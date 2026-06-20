__int64 __fastcall wlan_tdls_check_and_teardown_links_sync(__int64 a1, __int64 a2)
{
  int v2; // w21
  char v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  __int64 v15; // x19
  __int64 comp_private_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x4
  const char *v36; // x2
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w0
  unsigned int v47; // w1

  v2 = *(_DWORD *)(a1 + 24);
  v5 = policy_mgr_mode_specific_connection_count(a1, 0, nullptr);
  if ( (v2 & 0x100) != 0 && *(_DWORD *)(a2 + 16) == 2 && v5 )
    return qdf_trace_msg(
             0,
             8u,
             "%s: Don't teardown tdls for existing STA vdev",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "wlan_tdls_check_and_teardown_links_sync");
  result = tdls_get_vdev(a1, 0x11u);
  if ( result )
  {
    v15 = result;
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(result, 0xAu);
    if ( !comp_private_obj )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: vdev priv is NULL",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_tdls_teardown_links_sync");
      return wlan_objmgr_vdev_release_ref(v15, 0x11u, v37, v38, v39, v40, v41, v42, v43, v44, v45);
    }
    v25 = comp_private_obj;
    qdf_event_reset(comp_private_obj + 1000);
    v26 = wlan_tdls_teardown_links(a1);
    if ( v26 )
    {
      v35 = v26;
      v36 = "%s: wlan_tdls_teardown_links failed err %d";
    }
    else
    {
      qdf_trace_msg(
        0,
        8u,
        "%s: vdev:%d Wait for tdls teardown completion. Timeout %u ms",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "wlan_tdls_teardown_links_sync",
        *(unsigned __int8 *)(v15 + 104),
        10000);
      v46 = qdf_wait_for_event_completion(v25 + 1000, 0x2710u);
      v35 = v46;
      if ( !v46 )
      {
        v36 = "%s: TDLS teardown completion status %d ";
        v47 = 8;
        goto LABEL_13;
      }
      v36 = "%s:  Teardown Completion timed out %d";
    }
    v46 = 0;
    v47 = 2;
LABEL_13:
    qdf_trace_msg(v46, v47, v36, v27, v28, v29, v30, v31, v32, v33, v34, "wlan_tdls_teardown_links_sync", v35);
    return wlan_objmgr_vdev_release_ref(v15, 0x11u, v37, v38, v39, v40, v41, v42, v43, v44, v45);
  }
  return result;
}
