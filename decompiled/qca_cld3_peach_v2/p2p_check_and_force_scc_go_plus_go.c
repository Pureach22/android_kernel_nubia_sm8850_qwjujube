__int64 __fastcall p2p_check_and_force_scc_go_plus_go(__int64 a1, __int64 a2)
{
  int v4; // w21
  bool v5; // w0
  unsigned int v6; // w22
  unsigned int operation_chan_freq; // w21
  unsigned int v8; // w20
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int existing_con_info; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v43; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v44; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v45; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+18h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v43 = 7;
  v44 = 0;
  v4 = policy_mgr_mode_specific_connection_count(a1, 3, nullptr);
  v5 = policy_mgr_go_scc_enforced(a1);
  if ( v4 >= 2 && v5 )
  {
    v6 = *(unsigned __int8 *)(a2 + 168);
    operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)a2);
    v8 = *(_DWORD *)(*(_QWORD *)(a2 + 32) + 24LL);
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: Current vdev_id %d, chan_freq %d and ch_width %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "p2p_check_and_force_scc_go_plus_go",
      v6,
      operation_chan_freq,
      v8);
    existing_con_info = (unsigned __int8)policy_mgr_fetch_existing_con_info(
                                           a1,
                                           v6,
                                           operation_chan_freq,
                                           &v43,
                                           &v45,
                                           &v44);
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: Existing vdev_id %d, chan_freq %d and ch_width %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "p2p_check_and_force_scc_go_plus_go",
      existing_con_info,
      v45,
      v44);
    if ( existing_con_info == 255 )
    {
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: force scc not required",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "p2p_check_and_force_scc_go_plus_go");
    }
    else if ( v43 == 3 )
    {
      policy_mgr_process_forcescc_for_go(a1, existing_con_info, operation_chan_freq, v8, 3);
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: CSA for vdev_id %d",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "p2p_check_and_force_scc_go_plus_go",
        existing_con_info);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
