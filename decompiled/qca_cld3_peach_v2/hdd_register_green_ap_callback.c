__int64 __fastcall hdd_register_green_ap_callback(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  qdf_mem_set(v11, 8u, 0);
  v11[0] = wlan_hdd_send_green_ap_ll_ps_event;
  result = green_ap_register_hdd_callback(a1, v11);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: HDD callback registration for Green AP failed",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "hdd_register_green_ap_callback");
  _ReadStatusReg(SP_EL0);
  return result;
}
