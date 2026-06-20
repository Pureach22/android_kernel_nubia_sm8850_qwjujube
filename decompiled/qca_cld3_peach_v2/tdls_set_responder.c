__int64 __fastcall tdls_set_responder(
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
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x2
  const char *v20; // x3
  unsigned int v21; // w20
  __int64 comp_private_obj; // x0
  __int64 v23; // x20
  __int64 peer; // x0
  __int64 v25; // x9
  __int64 v26; // x0
  unsigned int *v27; // x8

  if ( a1 )
  {
    v10 = *(_QWORD *)a1;
    if ( !v10 )
    {
      qdf_trace_msg(0, 2u, "%s: Invalid input params %pK", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_set_responder", a1);
      v21 = -22;
LABEL_19:
      _qdf_mem_free(a1);
      return v21;
    }
    if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(v10, 0x11u, a2, a3, a4, a5, a6, a7, a8, a9) )
    {
      v19 = "%s: vdev object is deleted";
      v20 = "tdls_set_responder";
LABEL_17:
      qdf_trace_msg(0, 2u, v19, v11, v12, v13, v14, v15, v16, v17, v18, v20);
      v21 = -22;
LABEL_18:
      wlan_objmgr_vdev_release_ref(*(_QWORD *)a1, 0x11u, v27, v11, v12, v13, v14, v15, v16, v17, v18);
      goto LABEL_19;
    }
    if ( *(_QWORD *)a1 )
    {
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(*(_QWORD *)a1, 0xAu);
      if ( comp_private_obj )
      {
        v23 = comp_private_obj;
        peer = tdls_get_peer(comp_private_obj, a1 + 8);
        if ( peer )
        {
          *(_BYTE *)(peer + 40) = *(_BYTE *)(a1 + 14);
          v25 = *(_QWORD *)(*(_QWORD *)v23 + 216LL);
          if ( v25 && (v26 = *(_QWORD *)(v25 + 80)) != 0 )
          {
            if ( !(unsigned int)policy_mgr_update_nss_req(v26, *(unsigned __int8 *)(*(_QWORD *)v23 + 168LL)) )
            {
              v21 = 0;
              goto LABEL_18;
            }
            v19 = "%s: Unable to process NSS request";
          }
          else
          {
            v19 = "%s: psoc not found";
          }
        }
        else
        {
          v19 = "%s: curr_peer is NULL";
        }
        goto LABEL_16;
      }
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: NULL vdev", v11, v12, v13, v14, v15, v16, v17, v18, "wlan_vdev_get_tdls_vdev_obj");
    }
    v19 = "%s: tdls vdev obj is NULL";
LABEL_16:
    v20 = "tdls_process_set_responder";
    goto LABEL_17;
  }
  qdf_trace_msg(0, 2u, "%s: Invalid input params", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_set_responder");
  return (unsigned int)-22;
}
