void __fastcall ipareg_construct_route(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8

  v3 = *a3 | *(_DWORD *)a2 & 1;
  *a3 = v3;
  v4 = (2 * (*(_DWORD *)(a2 + 4) & 0x1F)) | v3;
  *a3 = v4;
  v5 = ((*(_DWORD *)(a2 + 8) & 1) << 6) | v4;
  *a3 = v5;
  v6 = ((*(_DWORD *)(a2 + 12) & 0x3FF) << 7) | v5;
  *a3 = v6;
  v7 = ((*(_BYTE *)(a2 + 16) & 0x1F) << 17) | v6;
  *a3 = v7;
  *a3 = v7 | ((*(_DWORD *)(a2 + 20) & 1) << 24);
}
