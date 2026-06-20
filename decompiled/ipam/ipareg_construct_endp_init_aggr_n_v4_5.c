void __fastcall ipareg_construct_endp_init_aggr_n_v4_5(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w9
  int v4; // w9
  unsigned int v5; // w10
  int v6; // w8
  int v7; // w8
  int v8; // w8
  int v9; // w8
  int v10; // w8
  int v11; // w8
  int v12; // w8

  v3 = *a3 | *(_DWORD *)a2 & 3;
  *a3 = v3;
  v4 = (4 * (*(_DWORD *)(a2 + 4) & 7)) | v3;
  *a3 = v4;
  v5 = *(_DWORD *)(a2 + 8);
  if ( v5 <= 0x3F )
    v6 = 32 * v5;
  else
    v6 = 2016;
  v7 = v6 | v4;
  *a3 = v7;
  v8 = ((*(_BYTE *)(a2 + 26) & 0x1F) << 12) | v7;
  *a3 = v8;
  v9 = v8 | ((*(_DWORD *)(a2 + 16) & 0x3F) << 17);
  *a3 = v9;
  v10 = v9 | (*(unsigned __int8 *)(a2 + 24) << 23);
  *a3 = v10;
  v11 = ((*(_DWORD *)(a2 + 20) & 1) << 26) | v10;
  *a3 = v11;
  v12 = ((*(_BYTE *)(a2 + 25) & 1) << 27) | v11;
  *a3 = v12;
  if ( *(_DWORD *)ipahal_ctx >= 0x18u )
    *a3 = v12 | (*(unsigned __int8 *)(a2 + 27) << 28);
}
