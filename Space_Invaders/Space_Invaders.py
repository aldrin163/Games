import pygame
from random import randint
from pygame import mixer
import time

pygame.init()

width, height = 800, 600
screen = pygame.display.set_mode((width, height))

background_img = pygame.image.load("background.png")
logo = pygame.image.load("logo.png")
player_img = pygame.image.load("player.png")
enemy_img = pygame.image.load("enemy.png")
bullet_img = pygame.image.load("bullet.png")

pygame.display.set_caption("Space Invaders")
pygame.display.set_icon(logo)

num_of_enemies = 7

playerX = width / 2 - 64
playerY = height - 100
playerX_change = 0

bullet_x = playerX
bullet_y = playerY
bulletY_change = 10
bullet_in_motion = False

score_value = 0
score_font = pygame.font.SysFont("comicsans", 32)
game_over_font = pygame.font.Font("freesansbold.ttf", 70)

mixer.music.load("background.wav")
mixer.music.play(-1)


class Enemy_class:
    def __init__(self):
        self.image = pygame.image.load('enemy.png')
        self.x = randint(0, width - 64)
        self.y = randint(50, height / 2 - 100)
        self.x_change = 4
        self.y_change = 40


enemy = []
for i in range(num_of_enemies):
    enemy.append(Enemy_class())


def show_player(x, y):
    screen.blit(player_img, (x, y))


def show_enemy(x, y):
    screen.blit(enemy_img, (x, y))


def fire(x, y):
    screen.blit(bullet_img, (x, y))


def game_over():
    game_over_text = game_over_font.render("GAME OVER", True, (255, 255, 255))
    screen.blit(game_over_text, (175, height / 2 - 60))


running = True
while running:
    screen.blit(background_img, (0, 0))

    # Key mappings
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                playerX_change -= 5
            elif event.key == pygame.K_RIGHT:
                playerX_change += 5
            elif event.key == pygame.K_SPACE and bullet_in_motion is False:
                bullet_in_motion = True
                bullet_x = playerX + 16
                fire(bullet_x, bullet_y)

        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_RIGHT or event.key == pygame.K_LEFT:
                playerX_change = 0

    # Player controls
    if playerX >= width - 64:
        playerX = width - 64
    elif playerX <= 0:
        playerX = 0

    playerX += playerX_change
    show_player(playerX, playerY)

    # Enemy controls
    for i in range(num_of_enemies):
        x = enemy[i].x
        y = enemy[i].y

        # Game over check
        if y >= playerY - 32 and x in range(int(playerX), int(playerX) + 64):
            game_over()
            for j in range(num_of_enemies):
                enemy[j].y = 2000
            playerY = 2000
            break

        if x >= width - 64 or x < 0:
            enemy[i].x_change *= -1
            enemy[i].y += enemy[i].y_change

        enemy[i].x += enemy[i].x_change
        show_enemy(enemy[i].x, enemy[i].y)

        # Bullet Collision check
        if bullet_in_motion:
            if bullet_x in range(x, x + 64) and bullet_y in range(y, y + 64):
                score_value += 5
                enemy[i].x = randint(0, width - 64)
                enemy[i].y = randint(50, height / 2 - 100)

    # Bullet controls
    if bullet_y <= 0:
        bullet_y = playerY
        bullet_in_motion = False

    if bullet_in_motion:
        bullet_y -= bulletY_change
        fire(bullet_x, bullet_y)

    score = score_font.render("Score: " + str(score_value), True, (255, 255, 255))
    screen.blit(score, (10, 10))
    pygame.display.update()
    time.sleep(0.01)
