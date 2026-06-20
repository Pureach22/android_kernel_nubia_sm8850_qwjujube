__int64 __fastcall cam_cdm_write_indirect(__int64 a1, int a2, __int16 a3)
{
  int v3; // w9

  v3 = *(unsigned __int8 *)(a1 + 2);
  *(_DWORD *)a1 = (unsigned __int16)(a3 - 1) | (v3 << 16) | 0x5000000;
  *(_DWORD *)(a1 + 4) = a2;
  return a1 + 8;
}
