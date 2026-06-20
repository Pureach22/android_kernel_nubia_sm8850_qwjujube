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
  __int64 v19; // x4
  const char *v20; // x2
  unsigned int v21; // w20
  double v22; // d0
  unsigned int v23; // w0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v32; // x8
  unsigned int v33; // w20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  bool v42; // cf
  __int64 v43; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v44)(); // [xsp+10h] [xbp-30h]
  __int64 v45; // [xsp+18h] [xbp-28h]
  __int64 v46; // [xsp+20h] [xbp-20h]
  __int64 v47; // [xsp+28h] [xbp-18h]
  __int64 *v48; // [xsp+30h] [xbp-10h]
  __int64 v49; // [xsp+38h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v48 = nullptr;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = nullptr;
  if ( a1 )
  {
    v10 = *a1;
    if ( *a1 )
    {
      if ( (tdls_check_is_tdls_allowed(*a1) & 1) != 0 )
      {
        if ( (mlo_mgr_is_link_switch_in_progress(v10) & 1) == 0 )
        {
          v32 = *(_QWORD *)(v10 + 216);
          if ( v32 && *(_QWORD *)(v32 + 80) )
          {
            v43 = 14;
            v44 = tdls_add_peer_serialize_callback;
            LODWORD(v45) = 10;
            LODWORD(v46) = 4000;
            v47 = v10;
            v48 = a1;
            BYTE4(v45) = 2;
            v33 = wlan_serialization_request((unsigned int *)&v43, v11, v12, v13, v14, v15, v16, v17, v18);
            qdf_trace_msg(
              0,
              8u,
              "%s: req: 0x%pK wlan_serialization_request status:%d",
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              "tdls_process_add_peer",
              a1,
              v33);
            v42 = v33 >= 2;
            v21 = 0;
            if ( !v42 )
              goto LABEL_11;
          }
          else
          {
            qdf_trace_msg(0, 2u, "%s: can't get psoc", v11, v12, v13, v14, v15, v16, v17, v18, "tdls_process_add_peer");
          }
          goto LABEL_9;
        }
        v19 = *(unsigned __int8 *)(v10 + 168);
        v20 = "%s: Link Switch in progress, reject add sta for vdev: %d";
      }
      else
      {
        v19 = *(unsigned __int8 *)(v10 + 168);
        v20 = "%s: TDLS not allowed, reject add station for vdev: %d";
      }
      qdf_trace_msg(0, 2u, v20, v11, v12, v13, v14, v15, v16, v17, v18, "tdls_process_add_peer", v19);
LABEL_9:
      v22 = tdls_internal_add_peer_rsp(a1);
      v21 = v23;
      wlan_objmgr_vdev_release_ref(*a1, 0x11u, (unsigned int *)*a1, v22, v24, v25, v26, v27, v28, v29, v30);
      goto LABEL_10;
    }
  }
  qdf_trace_msg(0, 2u, "%s: req: %pK", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_add_peer", a1);
  v21 = 4;
LABEL_10:
  _qdf_mem_free((__int64)a1);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v21;
}
