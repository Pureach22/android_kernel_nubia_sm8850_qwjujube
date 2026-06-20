__int64 __fastcall wma_pasn_handle_peer_create_conf(
        __int64 a1,
        unsigned __int8 *a2,
        char a3,
        unsigned int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v18; // x0
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w23
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  __int64 rx_ops; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  _DWORD *v48; // x8
  __int64 v49; // x0
  const char *v50; // x4

  if ( a4 )
    wma_pasn_peer_remove(a6, a7, a8, a9, a10, a11, a12, a13, a1, a2, a5, 1);
  v18 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 24),
          a5,
          8);
  if ( !v18 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Vdev is NULL",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wma_pasn_handle_peer_create_conf");
    return 29;
  }
  v28 = *(_DWORD *)(v18 + 16);
  wlan_objmgr_vdev_release_ref(v18, 8u, v19, v20, v21, v22, v23, v24, v25, v26, v27);
  if ( a3 == 12 )
  {
    if ( v28 != 16 )
    {
      v37 = "%s: PASN opmode:%d is not NAN";
LABEL_12:
      qdf_trace_msg(0x36u, 8u, v37, v29, v30, v31, v32, v33, v34, v35, v36, "wma_pasn_handle_peer_create_conf", v28);
      return 0;
    }
    wlan_nan_handle_pasn_peer_create_rsp(*(_QWORD *)(a1 + 24), a5, a2, a4);
  }
  else if ( a3 == 10 )
  {
    if ( !v28 )
    {
      rx_ops = wifi_pos_get_rx_ops(*(_QWORD *)(a1 + 24));
      if ( rx_ops )
      {
        v48 = *(_DWORD **)(rx_ops + 16);
        if ( v48 )
        {
          v49 = *(_QWORD *)(a1 + 24);
          if ( *(v48 - 1) != -2039865116 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, unsigned __int8 *, _QWORD))v48)(v49, a5, a2, a4);
          return 0;
        }
        v50 = "rx_ops->ranging_peer_cb";
      }
      else
      {
        v50 = "rx_ops";
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: %s is null",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "wma_pasn_handle_peer_create_conf",
        v50);
      return 29;
    }
    v37 = "%s: PASN opmode:%d is not sta";
    goto LABEL_12;
  }
  return 0;
}
