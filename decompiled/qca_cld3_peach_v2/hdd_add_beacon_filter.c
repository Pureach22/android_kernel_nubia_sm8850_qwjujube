__int64 __fastcall hdd_add_beacon_filter(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 v3; // x0
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD v13[9]; // [xsp+8h] [xbp-48h] BYREF

  v2 = a2;
  v13[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 16);
  v13[6] = 0;
  v13[7] = 0;
  v13[0] = 0x2000400000001008LL;
  v13[1] = 0;
  v13[2] = 0;
  v13[3] = 553648329;
  v13[4] = 0x47000000000LL;
  v13[5] = 0x40000000000LL;
  result = sme_add_beacon_filter(v3, a2, v13);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev %d set bcn filter failed %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "hdd_add_beacon_filter",
      v2,
      (unsigned int)result);
    result = 4294967282LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
