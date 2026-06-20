__int64 __fastcall qcom_vadc7_scale_hw_calib_die_temp(unsigned int *a1, __int64 a2, __int16 a3, int *a4)
{
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x9
  int v6; // w9
  __int64 v7; // x8
  __int64 v8; // x9
  int *v9; // x10
  _DWORD *v10; // x14
  int v11; // w10
  int v12; // w13
  int v13; // w11
  int v14; // w12
  int v16; // w13

  v4 = 1875000LL * (a3 & (unsigned int)~(a3 >> 31));
  v5 = *(unsigned int *)(a2 + 8);
  if ( v4 < v5 )
    goto LABEL_2;
  v7 = (__int64)(v4 / v5 * a1[1]) / *a1;
  if ( (int)v7 > 857299 )
  {
    v6 = 160000;
    goto LABEL_35;
  }
  if ( (int)v7 > 820099 )
  {
    v8 = 1;
  }
  else if ( (int)v7 > 782499 )
  {
    v8 = 2;
  }
  else if ( (int)v7 > 744599 )
  {
    v8 = 3;
  }
  else if ( (int)v7 > 706399 )
  {
    v8 = 4;
  }
  else if ( (int)v7 > 667899 )
  {
    v8 = 5;
  }
  else if ( (int)v7 > 629299 )
  {
    v8 = 6;
  }
  else if ( (int)v7 > 590499 )
  {
    v8 = 7;
  }
  else if ( (int)v7 > 551499 )
  {
    v8 = 8;
  }
  else if ( (int)v7 > 512399 )
  {
    v8 = 9;
  }
  else if ( (int)v7 > 473099 )
  {
    v8 = 10;
  }
  else
  {
    if ( (int)v7 < 433700 )
    {
LABEL_2:
      v6 = -60000;
      goto LABEL_35;
    }
    v8 = 11;
  }
  v9 = (int *)((char *)&adcmap7_die_temp + 8 * (unsigned int)(v8 - 1));
  v10 = (_DWORD *)((char *)&adcmap7_die_temp + 8 * v8);
  v12 = *v9;
  v11 = v9[1];
  v13 = v10[1];
  v14 = v7 - v12;
  v6 = v11;
  if ( (_DWORD)v7 != v12 && v13 != v11 )
  {
    v16 = *v10 - v12;
    if ( v16 )
    {
      v6 = v10[1];
      if ( *v10 != (_DWORD)v7 )
        v6 = (v13 - v11) * v14 / v16 + v11;
    }
    else
    {
      v6 = v10[1];
    }
  }
LABEL_35:
  *a4 = v6;
  return 0;
}
