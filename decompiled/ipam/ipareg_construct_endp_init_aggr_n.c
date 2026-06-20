void __fastcall ipareg_construct_endp_init_aggr_n(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w9
  int v4; // w9
  unsigned int v5; // w10
  int v6; // w8
  int v7; // w8
  int v8; // w8
  unsigned int v9; // w9
  int v10; // w9
  int v11; // w8
  int v12; // w8

  v3 = *a3 | *(_DWORD *)a2 & 3;
  *a3 = v3;
  v4 = (4 * (*(_DWORD *)(a2 + 4) & 7)) | v3;
  *a3 = v4;
  v5 = *(_DWORD *)(a2 + 8);
  if ( v5 <= 0x1F )
    v6 = 32 * v5;
  else
    v6 = 992;
  v7 = v6 | v4;
  *a3 = v7;
  v8 = (16 * ((274877907 * (unsigned __int64)*(unsigned int *)(a2 + 12)) >> 32)) & 0x7C00 | v7;
  *a3 = v8;
  v9 = *(_DWORD *)(a2 + 16);
  if ( v9 <= 0x3F )
    v10 = v9 << 15;
  else
    v10 = 2064384;
  v11 = v8 | v10;
  *a3 = v11;
  v12 = v11 | (*(unsigned __int8 *)(a2 + 24) << 21);
  *a3 = v12;
  *a3 = ((*(_DWORD *)(a2 + 20) & 1) << 24) | v12;
}
