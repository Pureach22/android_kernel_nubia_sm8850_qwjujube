void __fastcall ipareg_construct_tx_cfg_v4_5(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8

  v3 = (4 * (*(_DWORD *)(a2 + 4) & 0xF)) | *a3;
  *a3 = v3;
  v4 = ((*(_DWORD *)(a2 + 8) & 0xF) << 13) | v3;
  *a3 = v4;
  v5 = ((*(_DWORD *)(a2 + 12) & 0xF) << 6) | v4;
  *a3 = v5;
  v6 = ((*(_DWORD *)(a2 + 16) & 1) << 10) | v5;
  *a3 = v6;
  v7 = ((*(_DWORD *)(a2 + 20) & 1) << 11) | v6;
  *a3 = v7;
  v8 = ((*(_DWORD *)(a2 + 24) & 1) << 12) | v7;
  *a3 = v8;
  *a3 = v8 | (*(unsigned __int8 *)(a2 + 28) << 17);
}
