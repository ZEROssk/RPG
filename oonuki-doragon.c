#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int St(int, char *);

int Player(int, char *);

int Cr(int);

int Ah(int, int);

int Sn(int);

int En(char *);

int main(void)
{
    char name[100];
    int EnemyHP = 100;
    int PlayerHP = 100;
    int ATK;

    printf("\nプレイヤー名を入力 = ");
    scanf("%s", name);
    St(PlayerHP, name);
    fflush(stdout);
    scanf("%d", &ATK);
    ATK = Cr(ATK);
    EnemyHP = Ah(ATK, EnemyHP);
    printf("ドラゴンに %d のダメージ\n", ATK);

    while (EnemyHP > 0)
    {
        Sn(EnemyHP);
        PlayerHP = Player(PlayerHP, name);
        if (PlayerHP <= 0)
        {
            break;
        }
        printf("\n%sの攻撃\nEnemy HP = %d\n攻撃力の設定 = ", name, EnemyHP);
        scanf("%d", &ATK);
        ATK = Cr(ATK);
        EnemyHP = Ah(ATK, EnemyHP);
        printf("相手に %d のダメージ\n", ATK);
        fflush(stdout);
    }
    if (PlayerHP <= 0) {
        printf(" %sは死んでしまった\n", name);
    } else {
        En(name);
    }
    return 0;
}

int St(int PlayerHP, char *name) // 最初の表示
{
    printf("\n┏━━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━┓\n");
    printf("┃ ドラゴンが現れた┃┃ Player1 HP %d┃\n", PlayerHP);
    printf("┃ HP100           ┃┗━━━━━━━━━━━━━━━┛\n");
    printf("┃ 討伐する▼       ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━┛\n");
    printf("\n%sの攻撃\n攻撃力の設定 = ", name);
    return 0;
}

int Cr(int atk) // クリティカル値
{
    int c;
    srand(time(NULL));
    c = rand() % 6;
    atk = atk + c;
    printf("クリティカル値 %d\n", c);
    return atk;
}

int Ah(int x, int h) // ダメージ計算
{
    int y;
    y = h - x;
    return y;
}

int Player(int PlayerH, char *name) // プレイヤーに与えられるダメージ
{
    int kougeki;
    srand(time(NULL));
    kougeki = rand() % 20 + 15;
    printf("\n>相手の攻撃\n %s に %d のダメージ\n", name, kougeki);
    PlayerH = PlayerH - kougeki;
    if(PlayerH <= 0){
        PlayerH = 0;
    }
    printf(" %s のHP = %d\n", name, PlayerH);
    return PlayerH;
}

int Sn(int HP) // while文の中身 エネミー
{
    printf("Enemy HP = %d\n", HP);
    return 0;
}

int En(char *name) // 最後の表示
{
    int HP;
    printf("Enemy HP = 0\n");
    printf("\n＿人人人人人人人人人＿\n＞ドラゴンを倒した！＜\n￣Y^Y^Y^Y^Y^Y^Y^Y^Y￣\n%sは1万Gを手に入れた\n", name);
    return 0;
}