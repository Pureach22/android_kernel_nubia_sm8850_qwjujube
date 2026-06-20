__int64 __fastcall pmic_arb_offset_v2(__int64 *a1, int a2, int a3)
{
  __int64 v3; // x19
  unsigned __int64 v4; // t2
  __int64 result; // x0

  v3 = *a1;
  HIDWORD(v4) = a2;
  LODWORD(v4) = a3 << 16;
  result = pmic_arb_ppid_to_apid_v2((__int64)a1, v4 >> 24);
  if ( (result & 0x80000000) == 0 )
    return (*(unsigned __int8 *)(v3 + 49) << 12) + ((_DWORD)result << 15);
  return result;
}
