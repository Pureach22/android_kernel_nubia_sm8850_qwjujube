__int64 __fastcall hdd_reset_limit_off_chan(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v10; // x19
  __int64 result; // x0
  __int64 v12; // x20
  __int64 v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int8 v30[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 **)(a1 + 24);
  v30[0] = 0;
  result = _wlan_hdd_validate_context((__int64)v10, (__int64)"hdd_reset_limit_off_chan", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (result & 0x80000000) == 0 )
  {
    v12 = a1 + 49152;
    ucfg_policy_mgr_get_sys_pref(*v10, v30);
    policy_mgr_set_cur_conc_system_pref(*v10, v30[0]);
    v13 = *(_QWORD *)(v12 + 3680);
    *(_BYTE *)(v12 + 2944) = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: reset ac_bitmap for session %hu active_ac %0x",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "hdd_reset_limit_off_chan",
      *(unsigned __int8 *)(v13 + 8),
      0);
    result = sme_send_limit_off_channel_params(v10[2], *(unsigned __int8 *)(*(_QWORD *)(v12 + 3680) + 8LL), 0, 0, 0, 0);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to reset limit off chan params",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_reset_limit_off_chan");
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
