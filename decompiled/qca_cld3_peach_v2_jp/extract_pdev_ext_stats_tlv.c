__int64 __fastcall extract_pdev_ext_stats_tlv(__int64 a1, __int64 a2, unsigned int a3, _DWORD *a4)
{
  __int64 v4; // x8
  _DWORD *v6; // x20
  __int64 (*v7)(void); // x8
  int v8; // w8

  if ( !a2 )
    return 16;
  v4 = *(_QWORD *)(a2 + 128);
  if ( !v4 )
    return 16;
  v6 = (_DWORD *)(v4 + 20LL * a3);
  v7 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3712LL);
  if ( *((_DWORD *)v7 - 1) != -2112860426 )
    __break(0x8228u);
  v8 = v7();
  a4[29] = v8;
  a4[26] = v6[2];
  a4[27] = v6[3];
  a4[28] = v6[4];
  return 0;
}
