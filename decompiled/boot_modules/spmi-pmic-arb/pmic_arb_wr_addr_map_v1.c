__int64 __fastcall pmic_arb_wr_addr_map_v1(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 *a4)
{
  unsigned __int64 v6; // x8

  v6 = *(_QWORD *)(*(_QWORD *)a1 + 16LL) + ((unsigned __int64)*(unsigned __int8 *)(*(_QWORD *)a1 + 48LL) << 7) + 2048;
  *a4 = v6;
  a4[1] = v6 + 127;
  return 0;
}
