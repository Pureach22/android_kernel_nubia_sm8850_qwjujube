__int64 __fastcall btfm_slim_dai_shutdown(__int64 a1, unsigned int a2)
{
  __int64 v2; // x2
  __int64 v3; // x19
  _DWORD *v4; // x8
  __int64 v6; // x1
  int v7; // w9
  int v9; // w9
  _DWORD *v10; // x9
  _DWORD *v11; // x8
  int v12; // w10
  int v13; // t1
  __int64 v15; // x1
  __int64 v16; // x2

  v2 = a2;
  if ( a2 >= 4 )
    return printk(&unk_8B03, "btfm_slim_dai_shutdown", a2);
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  v4 = *(_DWORD **)((char *)*(&off_9350 + a2) + v3);
  if ( *v4 == 4 || *v4 == a2 )
  {
    v6 = *(_QWORD *)((char *)*(&off_9350 + a2) + v3);
  }
  else
  {
    v6 = (__int64)(v4 + 18);
    v7 = v4[18];
    if ( v7 != 4 && v7 != (_DWORD)v2 )
    {
      v6 = (__int64)(v4 + 36);
      v9 = v4[36];
      if ( v9 != 4 && v9 != (_DWORD)v2 )
      {
        v10 = v4 + 72;
        v13 = v4[54];
        v11 = v4 + 54;
        v12 = v13;
        if ( v13 == (_DWORD)v2 || v12 == 4 )
          v6 = (__int64)v11;
        else
          v6 = (__int64)v10;
      }
    }
  }
  if ( *(_WORD *)(v6 + 16) == 255 || *(_DWORD *)v6 == 4 )
    return printk(&unk_8859, "btfm_slim_dai_shutdown", v2);
  btfm_slim_disable_ch(*(_QWORD *)(*(_QWORD *)a1 + 152LL), v6, 0x1010000u >> (8 * v2), 0x1010102u >> (8 * v2));
  return btfm_slim_hw_deinit(v3, v15, v16);
}
