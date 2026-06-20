__int64 __fastcall btfm_swr_dai_get_channel_map(__int64 a1, _DWORD *a2, int *a3, _DWORD *a4, int *a5, unsigned int a6)
{
  __int64 v6; // x8
  __int64 result; // x0
  int v8; // w8
  int v9; // w8

  v6 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  *a5 = 0;
  *a3 = 0;
  *a4 = 0;
  *a2 = 0;
  if ( a6 > 4 )
  {
    printk(&unk_724B, "btfm_swr_dai_get_channel_map");
    return 4294967274LL;
  }
  else if ( ((1 << a6) & 0x13) != 0 )
  {
    result = 0;
    *a2 = *(unsigned __int8 *)(v6 + 30);
    if ( *(_BYTE *)(v6 + 30) == 2 )
      v8 = 3;
    else
      v8 = 1;
    *a3 = v8;
  }
  else
  {
    result = 0;
    *a4 = *(unsigned __int8 *)(v6 + 30);
    if ( *(_BYTE *)(v6 + 30) == 2 )
      v9 = 3;
    else
      v9 = 1;
    *a5 = v9;
  }
  return result;
}
