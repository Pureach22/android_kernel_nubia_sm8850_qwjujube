void __fastcall ipareg_construct_endp_init_deaggr_n(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8

  v3 = *a3 | *(_DWORD *)a2 & 0x3F;
  *a3 = v3;
  v4 = v3 | (*(unsigned __int8 *)(a2 + 5) << 7);
  *a3 = v4;
  v5 = ((*(_DWORD *)(a2 + 8) & 0x3F) << 8) | v4;
  *a3 = v5;
  *a3 = v5 | (*(_DWORD *)(a2 + 16) << 16);
}
