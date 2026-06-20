__int64 __fastcall policy_mgr_nss_update_cb(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned __int8 a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7)
{
  __int64 comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x27
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  const char *v33; // x2
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w1
  unsigned int v43; // w3

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    v33 = "%s: Invalid Context";
    return qdf_trace_msg(0x4Fu, 2u, v33, v15, v16, v17, v18, v19, v20, v21, v22, "policy_mgr_nss_update_cb");
  }
  v23 = comp_private_obj;
  if ( a2 )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: nss update failed(%d) for vdev %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "policy_mgr_nss_update_cb",
      a2,
      (unsigned __int8)a3);
  if ( (unsigned int)policy_mgr_get_connection_for_vdev_id(a1, (unsigned __int8)a3) == 5 )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: connection not found for vdev %d",
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             "policy_mgr_nss_update_cb",
             (unsigned __int8)a3);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: nss update successful for vdev:%d ori %d reason %d",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "policy_mgr_nss_update_cb",
    (unsigned __int8)a3,
    a6,
    a5);
  if ( a4 )
  {
    if ( a5 == 6 )
    {
      v42 = (unsigned __int8)a3;
      v43 = 6;
    }
    else
    {
      v42 = a6;
      v43 = a5;
    }
    return policy_mgr_next_actions(a1, v42, a4, v43, a7);
  }
  if ( a5 - 13 <= 1 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Continue connect/reassoc on vdev %d request_id %x reason %d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "policy_mgr_nss_update_cb",
      (unsigned __int8)a3,
      a7,
      a5);
    wlan_connect_hw_mode_change_resp(*(_QWORD *)(v23 + 8), a3, a7, 0);
  }
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: No action needed right now",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "policy_mgr_nss_update_cb");
  result = policy_mgr_set_opportunistic_update(a1);
  if ( (_DWORD)result )
  {
    v33 = "%s: ERROR: set opportunistic_update event failed";
    return qdf_trace_msg(0x4Fu, 2u, v33, v15, v16, v17, v18, v19, v20, v21, v22, "policy_mgr_nss_update_cb");
  }
  return result;
}
