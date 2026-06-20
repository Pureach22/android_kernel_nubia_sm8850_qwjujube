__int64 __fastcall tx_timer_deactivate(__int64 a1)
{
  __int64 v1; // x29
  __int64 v2; // x30
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // [xsp+8h] [xbp-18h]

  if ( *(_QWORD *)(a1 + 56) != 3735928559LL )
    return 21;
  v13 = v2;
  result = qdf_mc_timer_stop(a1 + 88);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x37u,
      5u,
      "Unable to stop timer %s; status =%d\n",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      a1,
      (unsigned int)result,
      v1,
      v13);
    return 0;
  }
  return result;
}
