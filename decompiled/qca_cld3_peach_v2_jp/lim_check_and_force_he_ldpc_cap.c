__int64 __fastcall lim_check_and_force_he_ldpc_cap(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  unsigned int v3; // w9

  v2 = *(_QWORD *)(a2 + 1);
  if ( (v2 & 0x4000000000000000LL) == 0 )
  {
    if ( *(_DWORD *)(result + 7176)
      || (v3 = *(unsigned __int16 *)(a2 + 20), ((v3 >> (2 * *(_BYTE *)(result + 8635) - 2)) & 3) == 2)
      || ((*(unsigned __int16 *)(a2 + 22) >> (2 * *(_BYTE *)(result + 8635) - 2)) & 3) == 2
      || *(_BYTE *)(result + 8676) == 1 && v3 >> 8 <= 0xFE && *(_BYTE *)a2 )
    {
      *(_QWORD *)(a2 + 1) = v2 | 0x4000000000000000LL;
    }
  }
  return result;
}
