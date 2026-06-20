__int64 __fastcall sub_5FEE50(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, unsigned __int64 *a6)
{
  int v6; // kr04_4

  v6 = __ldxp(a6) >> 32;
  LODWORD(a3) = v6;
  return hdd_apf_read_memory_callback(a1, a2, a3);
}
