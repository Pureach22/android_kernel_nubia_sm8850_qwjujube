__int64 __fastcall tdls_process_add_peer(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  unsigned int v20; // w20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  bool v29; // cf
  unsigned int v30; // w20
  double v31; // d0
  unsigned int v32; // w0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v41; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v42)(); // [xsp+10h] [xbp-30h]
  __int64 v43; // [xsp+18h] [xbp-28h]
  __int64 v44; // [xsp+20h] [xbp-20h]
  __int64 v45; // [xsp+28h] [xbp-18h]
  __int64 *v46; // [xsp+30h] [xbp-10h]
  __int64 v47; // [xsp+38h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v46 = nullptr;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = nullptr;
  if ( a1 && (v10 = *a1) != 0 )
  {
    if ( (tdls_check_is_tdls_allowed(*a1) & 1) != 0 )
    {
      v19 = *(_QWORD *)(v10 + 152);
      if ( v19 && *(_QWORD *)(v19 + 80) )
      {
        v41 = 14;
        v42 = tdls_add_peer_serialize_callback;
        LODWORD(v43) = 10;
        LODWORD(v44) = 4000;
        v45 = v10;
        v46 = a1;
        BYTE4(v43) = 2;
        v20 = wlan_serialization_request((unsigned int *)&v41, v11, v12, v13, v14, v15, v16, v17, v18);
        qdf_trace_msg(
          0,
          8u,
          "%s: req: 0x%pK wlan_serialization_request status:%d",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "tdls_process_add_peer",
          a1,
          v20);
        v29 = v20 >= 2;
        v30 = 0;
        if ( !v29 )
          goto LABEL_13;
      }
      else
      {
        qdf_trace_msg(0, 2u, "%s: can't get psoc", v11, v12, v13, v14, v15, v16, v17, v18, "tdls_process_add_peer");
      }
    }
    else
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: TDLS not allowed, reject add station for vdev: %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "tdls_process_add_peer",
        *(unsigned __int8 *)(v10 + 104));
    }
    v31 = tdls_internal_add_peer_rsp(a1);
    v30 = v32;
    wlan_objmgr_vdev_release_ref(*a1, 0x11u, (unsigned int *)*a1, v31, v33, v34, v35, v36, v37, v38, v39);
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: req: %pK", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_add_peer", a1);
    v30 = 4;
  }
  _qdf_mem_free((__int64)a1);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v30;
}
