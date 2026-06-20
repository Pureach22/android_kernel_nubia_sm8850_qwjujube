__int64 __fastcall policy_mgr_pdev_set_hw_mode_cb(
        unsigned int a1,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        unsigned __int8 a5,
        unsigned int a6,
        unsigned int a7,
        __int64 a8,
        unsigned int a9)
{
  __int64 comp_private_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 *v26; // x27
  const char *v27; // x2
  unsigned int v28; // w1
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int hw_mode_from_idx; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 updated; // x0
  void (__fastcall *v48)(_QWORD); // x9
  __int64 *v49; // x8
  void (__fastcall *v50)(_QWORD); // x9
  __int64 v51; // x0
  unsigned __int64 v52; // [xsp+38h] [xbp-18h] BYREF
  __int64 v53; // [xsp+40h] [xbp-10h]
  __int64 v54; // [xsp+48h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a8, 6u);
  if ( !comp_private_obj )
  {
    v27 = "%s: Invalid Context";
LABEL_11:
    v28 = 2;
LABEL_13:
    qdf_trace_msg(0x4Fu, v28, v27, v18, v19, v20, v21, v22, v23, v24, v25, "policy_mgr_pdev_set_hw_mode_cb");
    goto LABEL_14;
  }
  v26 = (__int64 *)comp_private_obj;
  policy_mgr_set_hw_mode_change_in_progress(a8, 0);
  if ( a1 != 7 && a1 || (policy_mgr_set_connection_update(a8), a1) )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Set HW mode failed with status %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "policy_mgr_pdev_set_hw_mode_cb",
      a1);
LABEL_6:
    if ( a5 && (a1 == 7 || !a1) )
    {
      policy_mgr_next_actions(a8, a7, a5, a6, a9);
      goto LABEL_14;
    }
    v27 = "%s: No action needed right now";
    v28 = 8;
    goto LABEL_13;
  }
  if ( !a4 && a6 != 11 )
  {
    v27 = "%s: vdev_mac_map is NULL";
    goto LABEL_11;
  }
  v52 = 0;
  v53 = 0;
  hw_mode_from_idx = policy_mgr_get_hw_mode_from_idx(a8, a2, (__int64)&v52);
  if ( !hw_mode_from_idx )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: HW mode idx %d, DBS %d Agile %d SBS %d, MAC0:: SS:Tx %d Rx %d, BW %d band %d. MAC1:: SS:Tx %d Rx %d, BW %d",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "policy_mgr_pdev_set_hw_mode_cb",
      a2,
      HIBYTE(v52),
      (unsigned __int8)v53,
      BYTE1(v53),
      (unsigned __int8)v52,
      BYTE1(v52),
      BYTE4(v52),
      BYTE6(v52),
      BYTE2(v52),
      BYTE3(v52),
      BYTE5(v52));
    policy_mgr_dump_freq_range_n_vdev_map(a3, a4, 0, 0);
    updated = policy_mgr_update_hw_mode_conn_info(a8, a3, a4, v52, v53, 0, 0);
    v48 = (void (__fastcall *)(_QWORD))v26[274];
    v49 = v26;
    if ( v48 )
    {
      if ( *((_DWORD *)v48 - 1) != 1874538549 )
        __break(0x8229u);
      v48(updated);
      v49 = v26;
    }
    v50 = (void (__fastcall *)(_QWORD))v49[59];
    if ( v50 )
    {
      v51 = *v49;
      if ( *((_DWORD *)v50 - 1) != 1588979751 )
        __break(0x8229u);
      v50(v51);
    }
    goto LABEL_6;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Get HW mode for index %d reason: %d",
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    "policy_mgr_pdev_set_hw_mode_cb",
    a2,
    hw_mode_from_idx);
LABEL_14:
  result = policy_mgr_set_opportunistic_update(a8);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: ERROR: set opportunistic_update event failed",
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               "policy_mgr_pdev_set_hw_mode_cb");
  _ReadStatusReg(SP_EL0);
  return result;
}
