__int64 tp_ghost_check()
{
  __int64 v0; // x21
  __int64 v1; // x1
  __int64 v2; // x2
  char *v3; // x19
  unsigned int v4; // w3
  unsigned __int8 v5; // w9
  int v6; // w13
  unsigned int v7; // w20
  __int64 v8; // x10
  unsigned int v9; // w11
  unsigned int v10; // w10
  int v11; // w4
  int v13; // w3
  int v14; // w0
  int v15; // w22
  int v16; // w0
  int v17; // w20
  __int64 v18; // x24
  int v19; // w26
  _DWORD *v20; // x27
  int v21; // w26

  v0 = tpd_cdev;
  v3 = (char *)vmalloc_noprof(2048);
  if ( !v3 )
  {
    printk(&unk_38791, v1, v2);
    return 0;
  }
  v4 = HIWORD(dword_30F04);
  v5 = HIWORD(dword_30F8C) != 0;
  if ( HIWORD(dword_30F04) )
    ++v5;
  if ( HIWORD(dword_31014) )
    ++v5;
  v6 = *(_DWORD *)(v0 + 1176);
  if ( HIWORD(dword_3109C) )
    ++v5;
  if ( HIWORD(dword_31124) )
    ++v5;
  if ( HIWORD(dword_311AC) )
    ++v5;
  if ( HIWORD(dword_31234) )
    ++v5;
  if ( HIWORD(dword_312BC) )
    ++v5;
  if ( HIWORD(dword_31344) )
    ++v5;
  if ( HIWORD(dword_313CC) )
    ++v5;
  if ( *(_DWORD *)(v0 + 1164) <= (int)v5 )
    v7 = v5;
  else
    v7 = *(_DWORD *)(v0 + 1164);
  v8 = 1171;
  if ( v7 > 2 )
    v8 = 1172;
  v9 = *(unsigned __int8 *)(v0 + v8);
  v10 = v9 * v5;
  if ( v6 )
  {
    v11 = (unsigned __int16)dword_30F04;
    if ( (unsigned __int16)dword_30F04 >= v9 )
    {
      v13 = 0;
      goto LABEL_90;
    }
    if ( HIWORD(dword_30F04) && v5 >= 6u && v10 < HIWORD(dword_30F04) )
      goto LABEL_98;
    if ( v6 == 1 )
      goto LABEL_38;
  }
  else
  {
    LOWORD(v4) = 0;
  }
  v11 = (unsigned __int16)dword_30F8C;
  if ( (unsigned __int16)dword_30F8C >= v9 )
  {
    v13 = 1;
    goto LABEL_90;
  }
  if ( HIWORD(dword_30F8C) )
  {
    LOWORD(v4) = HIWORD(dword_30F8C) + v4;
    if ( v5 >= 6u && v10 < (unsigned __int16)v4 )
    {
      v4 = (unsigned __int16)v4;
      goto LABEL_98;
    }
  }
  if ( v6 == 2 )
  {
LABEL_43:
    v11 = (unsigned __int16)dword_3109C;
    if ( (unsigned __int16)dword_3109C >= v9 )
    {
      v13 = 3;
      goto LABEL_90;
    }
    if ( HIWORD(dword_3109C) )
    {
      LOWORD(v4) = HIWORD(dword_3109C) + v4;
      if ( v5 >= 6u && v10 < (unsigned __int16)v4 )
      {
        v4 = (unsigned __int16)v4;
        goto LABEL_98;
      }
    }
    if ( v6 == 4 )
      goto LABEL_53;
    goto LABEL_48;
  }
LABEL_38:
  v11 = (unsigned __int16)dword_31014;
  if ( (unsigned __int16)dword_31014 >= v9 )
  {
    v13 = 2;
    goto LABEL_90;
  }
  if ( HIWORD(dword_31014) )
  {
    LOWORD(v4) = HIWORD(dword_31014) + v4;
    if ( v5 >= 6u && v10 < (unsigned __int16)v4 )
    {
      v4 = (unsigned __int16)v4;
      goto LABEL_98;
    }
  }
  if ( v6 != 3 )
    goto LABEL_43;
LABEL_48:
  v11 = (unsigned __int16)dword_31124;
  if ( (unsigned __int16)dword_31124 >= v9 )
  {
    v13 = 4;
    goto LABEL_90;
  }
  if ( HIWORD(dword_31124) )
  {
    LOWORD(v4) = HIWORD(dword_31124) + v4;
    if ( v5 >= 6u && v10 < (unsigned __int16)v4 )
    {
      v4 = (unsigned __int16)v4;
      goto LABEL_98;
    }
  }
  if ( v6 == 5 )
  {
LABEL_58:
    v11 = (unsigned __int16)dword_31234;
    if ( (unsigned __int16)dword_31234 >= v9 )
    {
      v13 = 6;
      goto LABEL_90;
    }
    if ( HIWORD(dword_31234) )
    {
      LOWORD(v4) = HIWORD(dword_31234) + v4;
      if ( v5 >= 6u && v10 < (unsigned __int16)v4 )
      {
        v4 = (unsigned __int16)v4;
        goto LABEL_98;
      }
    }
    if ( v6 == 7 )
      goto LABEL_68;
    goto LABEL_63;
  }
LABEL_53:
  v11 = (unsigned __int16)dword_311AC;
  if ( (unsigned __int16)dword_311AC >= v9 )
  {
    v13 = 5;
    goto LABEL_90;
  }
  if ( HIWORD(dword_311AC) )
  {
    LOWORD(v4) = HIWORD(dword_311AC) + v4;
    if ( v5 >= 6u && v10 < (unsigned __int16)v4 )
    {
      v4 = (unsigned __int16)v4;
      goto LABEL_98;
    }
  }
  if ( v6 != 6 )
    goto LABEL_58;
LABEL_63:
  v11 = (unsigned __int16)dword_312BC;
  if ( (unsigned __int16)dword_312BC >= v9 )
  {
    v13 = 7;
    goto LABEL_90;
  }
  if ( HIWORD(dword_312BC) )
  {
    LOWORD(v4) = HIWORD(dword_312BC) + v4;
    if ( v5 >= 6u && v10 < (unsigned __int16)v4 )
    {
      v4 = (unsigned __int16)v4;
      goto LABEL_98;
    }
  }
  if ( v6 == 8 )
  {
LABEL_73:
    v11 = (unsigned __int16)dword_313CC;
    if ( (unsigned __int16)dword_313CC < v9 )
    {
      if ( !HIWORD(dword_313CC) )
        goto LABEL_77;
      if ( v5 < 6u )
        goto LABEL_77;
      v4 = (unsigned __int16)(HIWORD(dword_313CC) + v4);
      if ( v10 >= v4 )
        goto LABEL_77;
      goto LABEL_98;
    }
    v13 = 9;
LABEL_90:
    v14 = snprintf(v3, 0x800u, "single ghost detect,touch id:%d, count:%d ", v13, v11);
    goto LABEL_99;
  }
LABEL_68:
  v11 = (unsigned __int16)dword_31344;
  if ( (unsigned __int16)dword_31344 >= v9 )
  {
    v13 = 8;
    goto LABEL_90;
  }
  if ( !HIWORD(dword_31344) || (LOWORD(v4) = HIWORD(dword_31344) + v4, v5 < 6u) || v10 >= (unsigned __int16)v4 )
  {
    if ( v6 == 9 )
    {
LABEL_77:
      vfree(v3);
      return 0;
    }
    goto LABEL_73;
  }
  v4 = (unsigned __int16)v4;
LABEL_98:
  v14 = snprintf(v3, 0x800u, "multi ghost detect,ghost_count:%d. ", v4);
LABEL_99:
  v15 = v14;
  v16 = snprintf(&v3[v14], 2048 - v14, "point_down_num: %d.", v7);
  v17 = 0;
  v18 = -1360;
  v19 = v16 + v15;
  do
  {
    v20 = (_DWORD *)((char *)&point_report_info + v18);
    if ( *(_WORD *)((char *)&point_report_info + v18 + 1454) )
    {
      v21 = snprintf(&v3[v19], 2048 - v19, " point[%d] down: %d, %d. ", v17, v20[346], v20[347]) + v19;
      v19 = snprintf(&v3[v21], 2048 - v21, " point[%d] up: %d, %d. ", v17, v20[349], v20[350]) + v21;
    }
    v18 += 136;
    ++v17;
  }
  while ( v18 );
  printk(&unk_36F34, "tp_ghost_check", v3);
  vfree(v3);
  return 1;
}
