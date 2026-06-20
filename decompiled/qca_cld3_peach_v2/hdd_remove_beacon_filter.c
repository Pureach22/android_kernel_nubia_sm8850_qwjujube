__int64 __fastcall hdd_remove_beacon_filter(__int64 a1, unsigned __int8 a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = sme_remove_beacon_filter(*(_QWORD *)(a1 + 16));
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev %d remove bcn filter failed %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_remove_beacon_filter",
      a2,
      (unsigned int)result);
    return 4294967282LL;
  }
  return result;
}
