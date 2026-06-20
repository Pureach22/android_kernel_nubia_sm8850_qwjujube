__int64 __fastcall aw882xx_spin_init(__int64 a1)
{
  __int64 **v1; // x21
  __int64 v3; // x8
  __int64 *v4; // x8
  __int64 v5; // x1
  void *v6; // x0
  char *v7; // x20
  unsigned int v8; // w20
  __int64 *v9; // x8
  __int64 v10; // x1
  int v12; // w8
  __int64 *v13; // x9
  __int64 v14; // x0
  unsigned int v15; // w0
  __int64 v16; // x1
  _DWORD *v17; // x11
  bool v18; // zf
  int v19; // w10
  _DWORD *v20; // x11
  int v21; // w10
  _DWORD *v22; // x11
  int v23; // w10
  _DWORD *v24; // x11
  __int64 v25; // x1
  char *s1; // [xsp+0h] [xbp-20h] BYREF
  char *s; // [xsp+8h] [xbp-18h] BYREF
  int v28; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+18h] [xbp-8h]

  v1 = (__int64 **)(a1 - 824);
  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 - 824);
  s1 = nullptr;
  if ( (of_property_read_string(*(_QWORD *)(v3 + 744), "spin-mode", &s1) & 0x80000000) != 0 )
  {
    v4 = *v1;
    g_spin_mode = 0;
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    v6 = &unk_28F5B;
LABEL_10:
    printk(v6, v5, "aw_parse_spin_dts");
    v8 = 0;
    goto LABEL_11;
  }
  v7 = s1;
  if ( !strcmp(s1, "dsp_spin") )
  {
    g_spin_mode = 1;
LABEL_7:
    v5 = (*v1)[14];
    if ( !v5 )
      v5 = **v1;
    v6 = &unk_268E9;
    goto LABEL_10;
  }
  if ( !strcmp(v7, "reg_spin") )
  {
    v12 = 2;
  }
  else
  {
    if ( strcmp(v7, "reg_mixer_spin") )
    {
      g_spin_mode = 0;
      goto LABEL_7;
    }
    v12 = 3;
  }
  v13 = *v1;
  g_spin_mode = v12;
  v14 = v13[93];
  s = nullptr;
  v28 = 0;
  v15 = of_property_read_string(v14, "spin-data", &s);
  if ( (v15 & 0x80000000) != 0 )
  {
    v8 = v15;
    v16 = (*v1)[14];
    if ( !v16 )
      v16 = **v1;
    printk(&unk_22B2D, v16, "aw_parse_spin_table_dt");
    goto LABEL_11;
  }
  if ( sscanf(s, "%c %c %c %c", &v28, (char *)&v28 + 1, (char *)&v28 + 2, (char *)&v28 + 3) != 4 )
    goto LABEL_52;
  if ( (unsigned __int8)v28 > 0x6Bu )
  {
    v17 = (_DWORD *)(a1 + 20);
    if ( (unsigned __int8)v28 == 108 )
      goto LABEL_31;
    v18 = (unsigned __int8)v28 == 114;
  }
  else
  {
    v17 = (_DWORD *)(a1 + 20);
    if ( (unsigned __int8)v28 == 76 )
      goto LABEL_31;
    v18 = (unsigned __int8)v28 == 82;
  }
  v17 = (_DWORD *)(a1 + 24);
  if ( !v18 )
    goto LABEL_52;
LABEL_31:
  v19 = BYTE1(v28);
  *(_WORD *)(a1 + 4) = *v17;
  if ( v19 <= 107 )
  {
    if ( v19 != 76 )
    {
      v20 = (_DWORD *)(a1 + 24);
      if ( v19 != 82 )
        goto LABEL_52;
      goto LABEL_38;
    }
    goto LABEL_37;
  }
  v20 = (_DWORD *)(a1 + 24);
  if ( v19 != 114 )
  {
    if ( v19 != 108 )
      goto LABEL_52;
LABEL_37:
    v20 = (_DWORD *)(a1 + 20);
  }
LABEL_38:
  v21 = BYTE2(v28);
  *(_WORD *)(a1 + 6) = *v20;
  if ( v21 <= 107 )
  {
    if ( v21 != 76 )
    {
      v22 = (_DWORD *)(a1 + 24);
      if ( v21 != 82 )
        goto LABEL_52;
LABEL_45:
      v23 = HIBYTE(v28);
      *(_WORD *)(a1 + 8) = *v22;
      if ( v23 > 107 )
      {
        v24 = (_DWORD *)(a1 + 24);
        if ( v23 != 114 )
        {
          v24 = (_DWORD *)(a1 + 20);
          if ( v23 != 108 )
            goto LABEL_52;
        }
      }
      else
      {
        v24 = (_DWORD *)(a1 + 20);
        if ( v23 != 76 )
        {
          v24 = (_DWORD *)(a1 + 24);
          if ( v23 != 82 )
            goto LABEL_52;
        }
      }
      *(_WORD *)(a1 + 10) = *v24;
      goto LABEL_7;
    }
LABEL_44:
    v22 = (_DWORD *)(a1 + 20);
    goto LABEL_45;
  }
  v22 = (_DWORD *)(a1 + 24);
  if ( v21 == 114 )
    goto LABEL_45;
  if ( v21 == 108 )
    goto LABEL_44;
LABEL_52:
  v25 = (*v1)[14];
  if ( !v25 )
    v25 = **v1;
  printk(&unk_22B6A, v25, "aw_parse_spin_table_dt");
  v8 = -22;
LABEL_11:
  v9 = *v1;
  *(_DWORD *)a1 = g_spin_mode != 0;
  v10 = v9[14];
  if ( !v10 )
    v10 = *v9;
  printk(&unk_28AA5, v10, "aw882xx_spin_init");
  _ReadStatusReg(SP_EL0);
  return v8;
}
