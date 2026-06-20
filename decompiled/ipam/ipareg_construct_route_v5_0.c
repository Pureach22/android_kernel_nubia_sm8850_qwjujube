void __fastcall ipareg_construct_route_v5_0(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8

  v3 = ((*(_DWORD *)a2 & 1) << 28) | *a3;
  *a3 = v3;
  v4 = *(unsigned __int8 *)(a2 + 4) | v3;
  *a3 = v4;
  v5 = ((*(_DWORD *)(a2 + 8) & 1) << 26) | v4;
  *a3 = v5;
  v6 = ((*(_DWORD *)(a2 + 12) & 3) << 16) | v5;
  *a3 = v6;
  v7 = v6 | (*(unsigned __int8 *)(a2 + 16) << 8);
  *a3 = v7;
  *a3 = ((*(_DWORD *)(a2 + 20) & 1) << 27) | v7;
}
