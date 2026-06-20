__int64 __fastcall gsi_dump_stats(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  int v4; // w0
  unsigned int v5; // w8
  int v6; // w21
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v4 = kstrtoint_from_user(a2, a3, 0, &v8);
  if ( !v4 )
  {
    v5 = v8;
    if ( v8 == -1 )
    {
      v8 = 0;
      v6 = *(_DWORD *)(gsi_ctx + 28608);
      if ( v6 < 1 )
        goto LABEL_13;
      v5 = 0;
LABEL_11:
      while ( v5 <= 0x24 )
      {
        gsi_dump_ch_stats(gsi_ctx + 448LL * v5 + 184);
        v5 = ++v8;
        if ( (int)v8 >= v6 )
          goto LABEL_13;
      }
    }
    else
    {
      if ( (v8 & 0x80000000) != 0 || v8 >= *(_DWORD *)(gsi_ctx + 28608) )
      {
LABEL_14:
        printk(&unk_2CE33, "gsi_dump_stats", 272);
        v3 = -22;
        goto LABEL_13;
      }
      if ( v8 < 0x24 )
      {
        if ( *(_BYTE *)(gsi_ctx + 448LL * v8 + 480) == 1 )
        {
          v6 = v8 + 1;
          goto LABEL_11;
        }
        goto LABEL_14;
      }
    }
    __break(0x5512u);
  }
  v3 = v4;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v3;
}
