_DWORD *__fastcall sde_ltm_get_phase_info(_DWORD *result, __int64 a2)
{
  bool v2; // cf
  int v3; // w10
  unsigned int v4; // w12
  unsigned int v5; // w8
  unsigned int v6; // w8

  v2 = result[11] >= result[10];
  *(_BYTE *)(a2 + 32) = result[11] < result[10];
  v3 = result[7];
  if ( v2 )
    v4 = 50331648;
  else
    v4 = 117440512;
  if ( v2 )
    v5 = 117440512;
  else
    v5 = 50331648;
  *(_QWORD *)(a2 + 4) = 0x80000000800000LL;
  *(_QWORD *)(a2 + 12) = 0x80000000800000LL;
  *(_BYTE *)(a2 + 33) = v3 != 1;
  *(_DWORD *)(a2 + 20) = 0x800000;
  v6 = v5 / (result[11] - 1);
  *(_DWORD *)(a2 + 24) = v6;
  *(_DWORD *)(a2 + 28) = v4 / (result[10] - 1);
  if ( v3 != 1 )
  {
    *(_DWORD *)(a2 + 8) = (result[11] >> 1) * v6 + 0x800000;
    *(_DWORD *)(a2 + 16) = (result[11] >> 1) * v6 + 0x800000;
  }
  return result;
}
