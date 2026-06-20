__int64 __fastcall ucfg_tdls_add_peer(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int ref; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w19
  __int64 result; // x0
  __int64 v31; // x0
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w22
  _QWORD *v42; // x21
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v52; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v53)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v54)(); // [xsp+20h] [xbp-20h]
  __int64 v55; // [xsp+28h] [xbp-18h]
  __int64 v56; // [xsp+30h] [xbp-10h]
  __int64 v57; // [xsp+38h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  v56 = 0;
  v53 = nullptr;
  v54 = nullptr;
  v51 = 0;
  v52 = nullptr;
  if ( a1 && a2 )
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: vdevid: %d, peertype: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ucfg_tdls_add_peer",
      a2[3],
      a2[2]);
    ref = wlan_objmgr_vdev_try_get_ref(a1, 0x11u, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( !ref )
    {
      v31 = _qdf_mem_malloc(0x18u, "ucfg_tdls_add_peer", 738);
      v41 = 2;
      if ( v31 )
      {
        v42 = (_QWORD *)v31;
        qdf_mem_copy((void *)(v31 + 8), a2, 0x10u);
        *v42 = a1;
        v52 = v42;
        v53 = tdls_process_cmd;
        LOWORD(v51) = 2;
        v54 = ucfg_tdls_post_msg_flush_cb;
        result = scheduler_post_message_debug(
                   0x33u,
                   0,
                   72,
                   (unsigned __int16 *)&v51,
                   0x2F1u,
                   (__int64)"ucfg_tdls_add_peer");
        if ( !(_DWORD)result )
          goto LABEL_10;
        v41 = result;
        qdf_trace_msg(0, 2u, "%s: post add peer msg fail", v43, v44, v45, v46, v47, v48, v49, v50, "ucfg_tdls_add_peer");
        _qdf_mem_free((__int64)v42);
      }
      wlan_objmgr_vdev_release_ref(a1, 0x11u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
      result = v41;
      goto LABEL_10;
    }
    v29 = ref;
    qdf_trace_msg(0, 2u, "%s: can't get vdev", v21, v22, v23, v24, v25, v26, v27, v28, "ucfg_tdls_add_peer");
    result = v29;
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: vdev: %pK, req %pK", a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_tdls_add_peer", a1, a2);
    result = 29;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
