__int64 __fastcall gmu_core_find_vma_block(__int64 a1, unsigned int a2, int a3)
{
  unsigned int *v3; // x8
  unsigned int v4; // w9
  unsigned int v5; // w10
  unsigned int v6; // w10
  unsigned int v7; // w10
  unsigned int v8; // w10
  unsigned int v9; // w10
  unsigned int v10; // w10

  v3 = *(unsigned int **)(a1 + 8224);
  v4 = a3 + a2;
  if ( *v3 <= a2 && v4 <= v3[1] + *v3 )
    return 0;
  v5 = v3[6];
  if ( v5 <= a2 && v4 <= v3[7] + v5 )
    return 1;
  v6 = v3[12];
  if ( v6 <= a2 && v4 <= v3[13] + v6 )
    return 2;
  v7 = v3[18];
  if ( v7 <= a2 && v4 <= v3[19] + v7 )
    return 3;
  v8 = v3[24];
  if ( v8 <= a2 && v4 <= v3[25] + v8 )
    return 4;
  v9 = v3[30];
  if ( v9 <= a2 && v4 <= v3[31] + v9 )
    return 5;
  v10 = v3[36];
  if ( v10 <= a2 && v4 <= v3[37] + v10 )
    return 6;
  else
    return 4294967294LL;
}
