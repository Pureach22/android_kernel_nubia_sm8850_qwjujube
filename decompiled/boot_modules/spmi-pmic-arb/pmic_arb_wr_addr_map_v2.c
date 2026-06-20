__int64 __fastcall pmic_arb_wr_addr_map_v2(__int64 *a1, int a2, int a3, _QWORD *a4)
{
  __int64 v4; // x20
  unsigned __int64 v6; // t2
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x8

  v4 = *a1;
  HIDWORD(v6) = a2;
  LODWORD(v6) = a3 << 16;
  result = pmic_arb_ppid_to_apid_v2((__int64)a1, v6 >> 24);
  if ( (result & 0x80000000) == 0 )
  {
    v8 = (*(unsigned __int8 *)(v4 + 49) << 12) + ((_DWORD)result << 15);
    v9 = *(_QWORD *)(v4 + 16) + v8;
    *a4 = v9;
    a4[1] = v9 + 4095;
    return 0;
  }
  return result;
}
