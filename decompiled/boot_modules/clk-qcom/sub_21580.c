__int64 __fastcall sub_21580(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int128 *v4; // x9
  __int64 v5; // kr08_8

  v5 = __ldxp(v4) >> 64;
  return gdsc_register(a1, a2, a3, a4, v5);
}
