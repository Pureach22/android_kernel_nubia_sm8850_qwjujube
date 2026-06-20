__int64 __fastcall gsi_rst_stats(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  int v4; // w0
  unsigned int v5; // w9
  int v6; // w11
  __int64 v7; // x10
  unsigned int v8; // w9
  _QWORD *v9; // x11
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v4 = kstrtoint_from_user(a2, a3, 0, &v11);
  if ( !v4 )
  {
    v5 = v11;
    if ( v11 == -1 )
    {
      v6 = *(_DWORD *)(gsi_ctx + 28608);
      if ( v6 < 1 )
        goto LABEL_14;
      v5 = 0;
    }
    else
    {
      if ( (v11 & 0x80000000) != 0 || v11 >= *(_DWORD *)(gsi_ctx + 28608) )
        goto LABEL_15;
      if ( v11 >= 0x24 )
        goto LABEL_17;
      if ( *(_BYTE *)(gsi_ctx + 448LL * v11 + 480) != 1 )
      {
LABEL_15:
        printk(&unk_2C863, "gsi_rst_stats", 508);
        v3 = -22;
        goto LABEL_14;
      }
      v6 = v11 + 1;
    }
    v7 = 448LL * v5 - 16128;
    v8 = v6 - v5;
    while ( v7 )
    {
      --v8;
      v9 = (_QWORD *)(gsi_ctx + v7);
      v7 += 448;
      v9[2093] = 0;
      v9[2092] = 0;
      v9[2091] = 0;
      v9[2090] = 0;
      v9[2089] = 0;
      v9[2088] = 0;
      v9[2087] = 0;
      v9[2086] = 0;
      v9[2085] = 0;
      v9[2084] = 0;
      v9[2083] = 0;
      v9[2082] = 0;
      v9[2081] = 0;
      v9[2080] = 0;
      if ( !v8 )
        goto LABEL_14;
    }
    v11 = 36;
LABEL_17:
    __break(0x5512u);
  }
  v3 = v4;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v3;
}
