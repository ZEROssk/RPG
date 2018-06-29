#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int St(int, char *);
int kaihuku(int, char *);
int kougekisyori(int, int);
int mahoukougeki(int, int);
int Player(int, char *);
int Cr(int);
int Ah(int, int);
int En(int, char *);

int main(void)
{
    char name[100];
    int EnemyHP = 100;
    int PlayerHP = 100;
    int ATK;
    int PHP;

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
        PlayerHP = Player(PlayerHP, name); // プレイヤーが受けるダメージの処理
        if (PlayerHP <= 0)
        {
            break;
        }
        printf("\n%sのターン\nEnemy HP = %d", name, EnemyHP);
        printf("\n攻撃の場合は１を押してください\n魔法攻撃の場合は2を押してください\n回復の場合は3を押してください\n = ");
        scanf("%d", &PHP);
        if (PHP == 3) {
            PlayerHP = kaihuku(PlayerHP, name); // プレイヤーの回復
            continue;
        }
        if (PHP == 2) {
            mahoukougeki(ATK, EnemyHP); // 魔法攻撃の処理
        } else {
            kougekisyori(ATK, EnemyHP); // 通常攻撃の処理部分
        }
        fflush(stdout);
    }
    if (PlayerHP <= 0) {
        printf(" %sは死んでしまった\n", name);
    } else {
        En(EnemyHP, name);
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
    printf("\n%sのターン\n攻撃力の設定 = ", name);
    return 0;
}

int kougekisyori(int ATK, int EnemyHP) //　攻撃処理
{
    printf("\n攻撃力の設定 = ");
    scanf("%d", &ATK);
    ATK = Cr(ATK);
    EnemyHP = Ah(ATK, EnemyHP);
    printf("相手に %d のダメージ\n", ATK);
    return 0;
}

int mahoukougeki(int ATK, int EnemyHP) // 魔法攻撃
{
    int mahou;
    srand(time(NULL));
    mahou = rand() % 10 + 9;
    printf("\n攻撃力の設定 = ");
    scanf("%d", &ATK);
    ATK = Cr(ATK) + mahou;
    EnemyHP = Ah(ATK, EnemyHP);
    printf("魔術による攻撃力アップ + %d\n", mahou);
    printf("相手に %d の魔法攻撃\n", ATK);
    return 0;
}

int kaihuku(int playerhp, char *name) // 回復
{
    int kaihukuti;
    srand(time(NULL));
    kaihukuti = rand() % 18 + 10;
    playerhp = playerhp + kaihukuti;
    printf("回復値 = %d\n", kaihukuti);
    printf("%s のHP = %d\n", name, playerhp);
    printf("回復しました\n");
    return playerhp;
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
    if (PlayerH <= 0)
    {
        PlayerH = 0;
    }
    printf(" %s のHP = %d\n", name, PlayerH);
    return PlayerH;
}

int En(int EH, char *name) // 最後の表示
{
    if (EH <= 0)
    {
        EH = 0;
    }
    printf("Enemy HP = %d\n", EH);
    printf("\n＿人人人人人人人人人＿\n＞ドラゴンを倒した！＜\n￣Y^Y^Y^Y^Y^Y^Y^Y^Y￣\n%sは1万Gを手に入れた\n", name);
    return 0;
}