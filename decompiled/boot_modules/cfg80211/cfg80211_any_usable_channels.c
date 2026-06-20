__int64 __fastcall cfg80211_any_usable_channels(__int64 a1, char a2, int a3)
{
  char v3; // w12
  bool v4; // cf
  unsigned __int64 v5; // x12
  unsigned __int64 v6; // x12
  unsigned int *v7; // x14
  __int64 v8; // x13
  int *v9; // x14
  int v10; // t1

  v3 = 0;
  while ( 1 )
  {
    v5 = a2 & 0x3F & (unsigned __int64)(-1LL << v3);
    if ( !v5 )
      return 0;
    v6 = __clz(__rbit64(v5));
    v7 = *(unsigned int **)(a1 + 328 + 8 * v6);
    if ( v7 )
    {
      v8 = v7[5];
      if ( (int)v8 >= 1 )
        break;
    }
LABEL_2:
    v4 = v6 >= 5;
    v3 = v6 + 1;
    if ( v4 )
      return 0;
  }
  v9 = (int *)(*(_QWORD *)v7 + 12LL);
  while ( 1 )
  {
    v10 = *v9;
    v9 += 16;
    if ( (v10 & (a3 | 1)) == 0 )
      return 1;
    if ( !--v8 )
      goto LABEL_2;
  }
}
