__int64 __fastcall csr_setup_vdev_session(
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
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _BYTE *v19; // x24
  __int64 v20; // x23
  _QWORD *v21; // x22
  __int64 v22; // x0
  unsigned int v23; // w21
  int v24; // w9
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6
  __int64 v36; // x7
  int v37; // w8
  __int64 result; // x0
  __int64 v39; // x10
  unsigned __int8 *v40; // x20
  const char *v41; // x2
  __int64 v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x20
  __int64 ext_hdl; // x0
  unsigned int *v53; // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x24
  _QWORD *vdev_by_id_from_pdev; // x0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x19
  _BYTE *dynamic_oce_flags; // x0
  unsigned int *v74; // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  int v83; // [xsp+10h] [xbp-10h] BYREF
  __int16 v84; // [xsp+14h] [xbp-Ch]
  unsigned __int8 v85; // [xsp+16h] [xbp-Ah]
  __int64 v86; // [xsp+18h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(52, (__int64)"csr_setup_vdev_session", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = (_BYTE *)context[1];
    if ( !v19 )
    {
      qdf_trace_msg(0x34u, 2u, "%s: invalid mlme cfg", v11, v12, v13, v14, v15, v16, v17, v18, "csr_setup_vdev_session");
LABEL_19:
      result = 16;
      goto LABEL_20;
    }
    v20 = *(_QWORD *)(a1 + 520);
    v21 = context;
    v22 = context[2704];
    v23 = *(unsigned __int8 *)(v20 + 168);
    v24 = *(_DWORD *)(v20 + 74);
    v84 = *(_WORD *)(v20 + 78);
    v83 = v24;
    v85 = 6;
    wlan_objmgr_pdev_iterate_obj_list(
      v22,
      2,
      (void (__fastcall *)(__int64, __int64, __int64))csr_get_vdev_id_from_bssid,
      (__int64)&v83,
      0,
      0xBu);
    if ( v85 >= 6u )
      v33 = 0;
    else
      v33 = v85;
    if ( v85 <= 5u )
    {
      if ( v20 == -74 )
      {
        v36 = 0;
        v34 = 0;
        v35 = 0;
        v37 = 0;
      }
      else
      {
        v34 = *(unsigned __int8 *)(v20 + 74);
        v35 = *(unsigned __int8 *)(v20 + 75);
        v36 = *(unsigned __int8 *)(v20 + 76);
        v37 = *(unsigned __int8 *)(v20 + 79);
      }
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Session %d exists with mac address %02x:%02x:%02x:**:**:%02x",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "csr_setup_vdev_session",
        v33,
        v34,
        v35,
        v36,
        v37);
      goto LABEL_19;
    }
    if ( v23 > 5 || (v39 = v21[2162], (v40 = (unsigned __int8 *)(v39 + 96LL * v23)) == nullptr) )
    {
      v41 = "%s: Session does not exist for interface %d";
      goto LABEL_16;
    }
    if ( v40[1] == 1 )
    {
      v41 = "%s: Cannot re-open active session with Id %d";
LABEL_16:
      qdf_trace_msg(0x34u, 2u, v41, v25, v26, v27, v28, v29, v30, v31, v32, "csr_setup_vdev_session", v23);
      goto LABEL_19;
    }
    *v40 = v23;
    v40[1] = 1;
    *(_DWORD *)(a1 + 60) = *(unsigned __int16 *)(v21[1] + 1288LL);
    *(_DWORD *)(a1 + 48) = v19[2878] & 3
                         | (4 * (v19[2820] & 3))
                         | (16 * (unsigned __int8)v19[2821])
                         | (32 * (unsigned __int8)v19[2822])
                         | ((unsigned __int8)v19[2823] << 6)
                         | ((unsigned __int8)v19[2824] << 7)
                         | ((unsigned __int8)v19[2825] << 8)
                         | ((unsigned __int8)v19[2826] << 11)
                         | ((unsigned __int8)v19[2827] << 12)
                         | ((v19[2828] & 7) << 13)
                         | ((v19[2829] & 7) << 16)
                         | ((unsigned __int8)v19[2830] << 19)
                         | ((unsigned __int8)v19[2872] << 20)
                         | ((unsigned __int8)v19[2831] << 21)
                         | ((unsigned __int8)v19[2832] << 22)
                         | ((unsigned __int8)v19[2834] << 28)
                         | ((unsigned __int8)v19[2835] << 29)
                         | ((v19[2877] & 7) << 23);
    csr_update_session_he_cap((__int64)v21, (unsigned __int8 *)(v39 + 96LL * v23));
    v42 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v21[2703], *v40, 11);
    if ( v42 )
    {
      v51 = v42;
      ext_hdl = wlan_vdev_mlme_get_ext_hdl(v42, v43, v44, v45, v46, v47, v48, v49, v50);
      if ( ext_hdl )
      {
        v62 = ext_hdl;
        qdf_mem_copy((void *)(ext_hdl + 24448), (const void *)(v21[1] + 1500LL), 0x5Cu);
        v53 = (_DWORD *)(&off_0 + 1);
        *(_BYTE *)(v62 + 24448) = 1;
      }
      wlan_objmgr_vdev_release_ref(v51, 0xBu, v53, v54, v55, v56, v57, v58, v59, v60, v61);
    }
    csr_send_set_ie(
      *(unsigned __int8 *)(a1 + 179),
      *(_BYTE *)(a1 + 180),
      *(_BYTE *)(v20 + 168),
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50);
    if ( *(_BYTE *)(a1 + 179) == 2 )
    {
      vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(v21[2704], *(_BYTE *)(v20 + 168), 7u);
      if ( vdev_by_id_from_pdev )
      {
        v72 = (__int64)vdev_by_id_from_pdev;
        dynamic_oce_flags = (_BYTE *)mlme_get_dynamic_oce_flags(
                                       (__int64)vdev_by_id_from_pdev,
                                       v64,
                                       v65,
                                       v66,
                                       v67,
                                       v68,
                                       v69,
                                       v70,
                                       v71);
        if ( dynamic_oce_flags )
        {
          v74 = (unsigned int *)*(unsigned __int8 *)(v21[1] + 3668LL);
          *dynamic_oce_flags = (_BYTE)v74;
        }
        wlan_objmgr_vdev_release_ref(v72, 7u, v74, v75, v76, v77, v78, v79, v80, v81, v82);
      }
      wlan_mlme_update_oce_flags(v21[2704]);
    }
    result = 0;
  }
  else
  {
    result = 4;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
