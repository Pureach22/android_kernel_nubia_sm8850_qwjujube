__int64 __fastcall sde_dbg_reg_base_open(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  size_t v5; // x0
  __int64 v6; // x20
  size_t v7; // x0
  int v8; // w8
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v10; // [xsp+10h] [xbp-40h]
  __int64 v11; // [xsp+18h] [xbp-38h]
  __int64 v12; // [xsp+20h] [xbp-30h]
  __int64 v13; // [xsp+28h] [xbp-28h]
  __int64 v14; // [xsp+30h] [xbp-20h]
  __int64 v15; // [xsp+38h] [xbp-18h]
  __int64 v16; // [xsp+40h] [xbp-10h]
  __int64 v17; // [xsp+48h] [xbp-8h]

  result = 4294967274LL;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  *(_QWORD *)s = 0;
  v10 = 0;
  if ( !a1 || !a2 )
  {
LABEL_16:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  snprintf(s, 0x40u, "%s", (const char *)(*(_QWORD *)(a2 + 72) + 56LL));
  v5 = strnlen((const char *)(*(_QWORD *)(a2 + 72) + 56LL), 0x28u);
  if ( v5 >= 0x29 )
  {
    _fortify_panic(2, 40, v5 + 1);
    goto LABEL_20;
  }
  if ( v5 == 40 )
  {
LABEL_20:
    v5 = _fortify_panic(4, 40, 41);
    goto LABEL_21;
  }
  if ( v5 - 4 < 0x40 )
  {
    v6 = qword_2942A8;
    s[v5 - 4] = 0;
    if ( (__int64 *)v6 == &qword_2942A8 )
      goto LABEL_15;
    while ( 1 )
    {
      v7 = strnlen((const char *)(v6 + 32), 0x50u);
      if ( v7 >= 0x51 )
      {
        _fortify_panic(2, 80, v7 + 1);
LABEL_18:
        _fortify_panic(4, 80, 81);
      }
      if ( v7 )
      {
        if ( v7 == 80 )
          goto LABEL_18;
        if ( !strcmp((const char *)(v6 + 32), s) )
          break;
      }
      v6 = *(_QWORD *)v6;
      if ( (__int64 *)v6 == &qword_2942A8 )
        goto LABEL_15;
    }
    if ( !v6 )
    {
LABEL_15:
      printk(&unk_25428D, "sde_dbg_reg_base_open");
      result = 4294967274LL;
    }
    else
    {
      v8 = *(_DWORD *)(a2 + 12);
      result = 0;
      *(_QWORD *)(a2 + 32) = v6;
      *(_DWORD *)(a2 + 12) = v8 & 0xFFFFFFE3;
    }
    goto LABEL_16;
  }
LABEL_21:
  __break(0x5512u);
  return sde_dbg_reg_base_release(v5);
}
