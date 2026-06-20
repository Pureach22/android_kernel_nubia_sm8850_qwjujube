__int64 __fastcall wlan_tdls_notify_channel_switch_complete(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int *v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // [xsp+8h] [xbp-18h] BYREF
  __int64 v37[2]; // [xsp+10h] [xbp-10h] BYREF

  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37[0] = 0;
  result = tdls_get_vdev(a1, 0x11u);
  if ( result )
  {
    v2 = result;
    if ( (unsigned int)tdls_get_vdev_objects(result, v37, &v36) )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: Failed to get TDLS objects",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "wlan_tdls_notify_channel_switch_complete");
    }
    else
    {
      qdf_trace_msg(
        0,
        8u,
        "%s: vdev %d CSA complete",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "wlan_tdls_notify_channel_switch_complete",
        *(unsigned __int8 *)(v2 + 104));
      if ( (tdls_check_is_tdls_allowed(v2, v20, v21, v22, v23, v24, v25, v26, v27) & 1) != 0 )
      {
        tdls_process_enable_for_vdev(v2);
        tdls_set_tdls_offchannelmode(v2, 1u);
      }
      else
      {
        tdls_disable_offchan_and_teardown_links(v2);
        qdf_trace_msg(
          0,
          8u,
          "%s: vdev %d disable the tdls in FW after CSA",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "wlan_tdls_notify_channel_switch_complete",
          *(unsigned __int8 *)(v2 + 104));
      }
    }
    result = wlan_objmgr_vdev_release_ref(v2, 0x11u, v11, v12, v13, v14, v15, v16, v17, v18, v19);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
