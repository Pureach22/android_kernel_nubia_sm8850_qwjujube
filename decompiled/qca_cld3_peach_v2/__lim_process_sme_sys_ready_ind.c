bool __fastcall _lim_process_sme_sys_ready_ind(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v11; // w8
  int v13; // w19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD v23[7]; // [xsp+8h] [xbp-38h] BYREF

  v23[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_DWORD *)a1;
  memset(&v23[2], 0, 32);
  v23[0] = 4197;
  v23[1] = a2;
  if ( v11 != 1 )
  {
    a2[2] = pe_roam_synch_callback;
    a2[5] = pe_disconnect_callback;
    a2[6] = pe_set_ie_for_roam_invoke;
    pe_register_mgmt_rx_frm_callback(a1, a3, a4, a5, a6, a7, a8, a9, a10);
    pe_register_callbacks_with_wma(a1, a2);
    *(_QWORD *)(a1 + 12416) = a2[4];
    *(_QWORD *)(a1 + 12424) = a2[3];
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: sending WMA_SYS_READY_IND msg to HAL",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "__lim_process_sme_sys_ready_ind");
  mac_trace_msg_tx(a1, 255, 4197);
  v13 = wma_post_ctrl_msg(a1, v23);
  if ( v13 )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: wma_post_ctrl_msg failed",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "__lim_process_sme_sys_ready_ind");
  _ReadStatusReg(SP_EL0);
  return v13 != 0;
}
