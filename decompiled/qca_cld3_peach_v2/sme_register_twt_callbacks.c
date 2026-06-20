__int64 __fastcall sme_register_twt_callbacks(_QWORD *a1, _QWORD *a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  result = qdf_mutex_acquire((__int64)(a1 + 1606));
  if ( !(_DWORD)result )
  {
    a1[1811] = *a2;
    a1[1813] = a2[2];
    a1[1814] = a2[3];
    a1[1815] = a2[4];
    a1[1817] = a2[5];
    a1[1812] = a2[1];
    a1[1818] = a2[6];
    a1[1816] = a2[7];
    a1[1819] = a2[8];
    qdf_mutex_release((__int64)(a1 + 1606));
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: TWT: callbacks registered",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "sme_register_twt_callbacks");
    return 0;
  }
  return result;
}
