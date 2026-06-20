__int64 __fastcall spr_config_show(__int64 a1, __int64 a2, const char *a3)
{
  size_t v3; // x26
  __int64 v4; // x20
  unsigned int v6; // w22
  size_t v7; // x23
  size_t v8; // x0
  size_t v9; // x2
  __int64 v10; // x19
  __int64 v11; // x23
  __int64 v12; // x24
  __int64 *v13; // x8
  __int64 v14; // x25
  int v15; // w28
  size_t v16; // x2
  __int64 v17; // x20
  unsigned int v18; // w20
  __int64 v19; // x25
  int v20; // w28
  size_t v21; // x2
  __int64 v22; // x27
  __int64 result; // x0
  size_t v24; // x2
  __int64 v25; // [xsp+8h] [xbp-58h]
  char string[8]; // [xsp+18h] [xbp-48h] BYREF
  __int64 v28; // [xsp+20h] [xbp-40h]
  __int64 v29; // [xsp+28h] [xbp-38h]
  __int64 v30; // [xsp+30h] [xbp-30h]
  __int64 v31; // [xsp+38h] [xbp-28h]
  __int64 v32; // [xsp+40h] [xbp-20h]
  __int64 v33; // [xsp+48h] [xbp-18h]
  __int64 v34; // [xsp+50h] [xbp-10h]
  __int64 v35; // [xsp+58h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  *a3 = 0;
  if ( !v4 )
  {
    result = -14;
    goto LABEL_48;
  }
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  *(_QWORD *)string = 0;
  v28 = 0;
  mutex_lock(v4);
  v6 = scnprintf(string, 64, "spr data list below:\n");
  v7 = strnlen(a3, 0x1000u);
  if ( v7 == -1 )
  {
    v24 = 0;
    goto LABEL_52;
  }
  v8 = strnlen(string, 0x40u);
  if ( v8 >= 0x41 )
  {
LABEL_49:
    _fortify_panic(2, 64, v8 + 1);
LABEL_50:
    _fortify_panic(4, 64, 65);
LABEL_51:
    v24 = v3 + 1;
LABEL_52:
    _fortify_panic(2, -1, v24);
  }
  if ( v8 == 64 )
    goto LABEL_50;
  if ( v7 <= 0xFFF )
  {
    if ( v8 + v7 >= 0x1000 )
      v9 = 4095 - v7;
    else
      v9 = v8;
    if ( v8 + v7 >= 0x1000 )
      v10 = 4095;
    else
      v10 = v8 + v7;
    memcpy((void *)&a3[v7], string, v9);
    a3[v10] = 0;
  }
  v11 = 0;
  v12 = v4 + 64;
  v25 = v4;
  while ( v6 <= 0x1000 )
  {
    v13 = *(__int64 **)(v12 + 8 * v11);
    if ( v13 )
    {
      v14 = *v13;
      v15 = scnprintf(string, 64, "spr data for CPU[%d] below:\n", v11);
      v3 = strnlen(a3, 0x1000u);
      if ( v3 == -1 )
        goto LABEL_51;
      v8 = strnlen(string, 0x40u);
      if ( v8 >= 0x41 )
        goto LABEL_49;
      if ( v8 == 64 )
        goto LABEL_50;
      if ( v3 <= 0xFFF )
      {
        if ( v8 + v3 >= 0x1000 )
          v16 = 4095 - v3;
        else
          v16 = v8;
        if ( v8 + v3 >= 0x1000 )
          v17 = 4095;
        else
          v17 = v8 + v3;
        memcpy((void *)&a3[v3], string, v16);
        a3[v17] = 0;
      }
      v6 += v15;
      if ( *(_DWORD *)(*(_QWORD *)(v12 + 8 * v11) + 12LL) )
      {
        v18 = 0;
        v19 = v14 + 20;
        while ( v6 <= 0x1000 )
        {
          v20 = scnprintf(string, 64, "%d\n", *(_DWORD *)(v19 + 4LL * (int)v18));
          v3 = strnlen(a3, 0x1000u);
          if ( v3 == -1 )
            goto LABEL_51;
          v8 = strnlen(string, 0x40u);
          if ( v8 >= 0x41 )
            goto LABEL_49;
          if ( v8 == 64 )
            goto LABEL_50;
          if ( v3 <= 0xFFF )
          {
            if ( v8 + v3 >= 0x1000 )
              v21 = 4095 - v3;
            else
              v21 = v8;
            if ( v8 + v3 >= 0x1000 )
              v22 = 4095;
            else
              v22 = v8 + v3;
            memcpy((void *)&a3[v3], string, v21);
            a3[v22] = 0;
          }
          ++v18;
          v6 += v20;
          if ( v18 >= *(_DWORD *)(*(_QWORD *)(v12 + 8 * v11) + 12LL) )
            goto LABEL_15;
        }
        dev_err(a1, "Couldn't write complete config\n");
      }
    }
    else
    {
      dev_err(a1, "SPR data pinter for CPU%d is empty\n", v11);
    }
LABEL_15:
    if ( ++v11 == 8 )
      goto LABEL_47;
  }
  dev_err(a1, "Couldn't write complete config\n");
LABEL_47:
  mutex_unlock(v25);
  result = (int)v6;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
