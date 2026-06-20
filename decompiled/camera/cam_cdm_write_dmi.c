__int64 __fastcall cam_cdm_write_dmi(__int64 a1, __int64 a2, int a3, unsigned __int8 a4, int a5, unsigned __int16 a6)
{
  int v6; // w10

  v6 = *(unsigned __int8 *)(a1 + 2);
  *(_DWORD *)(a1 + 4) = a5;
  *(_DWORD *)(a1 + 8) = a3 & 0xFFFFFF | (a4 << 24);
  *(_DWORD *)a1 = a6 | (v6 << 16) | 0x1000000;
  return a1 + 12;
}
