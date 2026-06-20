__int64 __fastcall _lim_handle_beacon(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x1
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w8
  __int64 result; // x0
  __int64 v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a2 + 8);
  v16[0] = 0;
  lim_get_b_dfrom_rx_packet(a1, v5, v16);
  if ( a3 )
  {
    v14 = *(_DWORD *)(a3 + 80);
    if ( v14 == 16 || v14 == 10 )
      result = sch_beacon_process(a1, v16[0], a3);
    else
      result = lim_process_beacon_frame(a1, v16[0], a3, v6, v7, v8, v9, v10, v11, v12, v13);
  }
  else
  {
    result = sch_beacon_process(a1, v16[0], 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
