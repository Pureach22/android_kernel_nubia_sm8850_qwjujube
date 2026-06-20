__int64 __fastcall policy_mgr_hw_mode_transition_cb(
        unsigned int a1,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7)
{
  __int64 context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x26
  unsigned int hw_mode_from_idx; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  const char *v34; // x2
  __int64 (__fastcall *v35)(_QWORD); // x8
  __int64 v36; // [xsp+48h] [xbp-18h] BYREF
  __int64 v37; // [xsp+50h] [xbp-10h]
  __int64 v38; // [xsp+58h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  context = policy_mgr_get_context(a7);
  if ( !context )
  {
    v34 = "%s: Invalid context";
LABEL_7:
    result = qdf_trace_msg(0x4Fu, 2u, v34, v15, v16, v17, v18, v19, v20, v21, v22, "policy_mgr_hw_mode_transition_cb");
    goto LABEL_8;
  }
  if ( !a4 )
  {
    v34 = "%s: vdev_mac_map is NULL";
    goto LABEL_7;
  }
  v23 = context;
  hw_mode_from_idx = policy_mgr_get_hw_mode_from_idx(a7, a2, &v36);
  if ( hw_mode_from_idx )
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Get HW mode for index %d reason: %d",
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               "policy_mgr_hw_mode_transition_cb",
               a2,
               hw_mode_from_idx);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: HW mode: old %d new %d, DBS %d Agile %d SBS %d, MAC0:: SS:Tx %d Rx %d, BW %d band %d, MAC1:: SS:Tx %d Rx %d, BW %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "policy_mgr_hw_mode_transition_cb",
      a1,
      a2,
      HIBYTE(v36),
      (unsigned __int8)v37,
      BYTE1(v37),
      (unsigned __int8)v36,
      BYTE1(v36),
      BYTE4(v36),
      BYTE6(v36),
      BYTE2(v36),
      BYTE3(v36),
      BYTE5(v36));
    policy_mgr_dump_freq_range_n_vdev_map(a3, a4, a5, a6);
    result = policy_mgr_update_hw_mode_conn_info(a7, a3, a4, v36, v37, a5, a6);
    v35 = *(__int64 (__fastcall **)(_QWORD))(v23 + 2192);
    if ( v35 )
    {
      if ( *((_DWORD *)v35 - 1) != 1874538549 )
        __break(0x8228u);
      result = v35(result);
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
