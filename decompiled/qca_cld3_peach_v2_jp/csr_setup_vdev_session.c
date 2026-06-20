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
  _BYTE *v19; // x23
  __int64 v20; // x22
  _QWORD *v21; // x21
  __int64 v22; // x0
  unsigned int v23; // w20
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
  unsigned __int8 *v39; // x1
  const char *v40; // x2
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  _QWORD *vdev_by_id_from_pdev; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x19
  _BYTE *dynamic_oce_flags; // x0
  unsigned int *v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  int v69; // [xsp+10h] [xbp-10h] BYREF
  __int16 v70; // [xsp+14h] [xbp-Ch]
  unsigned __int8 v71; // [xsp+16h] [xbp-Ah]
  __int64 v72; // [xsp+18h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
    v20 = *(_QWORD *)(a1 + 504);
    v21 = context;
    v22 = context[2695];
    v23 = *(unsigned __int8 *)(v20 + 104);
    v24 = *(_DWORD *)(v20 + 74);
    v70 = *(_WORD *)(v20 + 78);
    v69 = v24;
    v71 = 6;
    wlan_objmgr_pdev_iterate_obj_list(
      v22,
      2,
      (void (__fastcall *)(__int64, __int64, __int64))csr_get_vdev_id_from_bssid,
      (__int64)&v69,
      0,
      0xBu);
    if ( v71 >= 6u )
      v33 = 0;
    else
      v33 = v71;
    if ( v71 <= 5u )
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
    if ( v23 > 5 || (v39 = (unsigned __int8 *)(v21[2153] + 96LL * v23)) == nullptr )
    {
      v40 = "%s: Session does not exist for interface %d";
      goto LABEL_16;
    }
    if ( v39[1] == 1 )
    {
      v40 = "%s: Cannot re-open active session with Id %d";
LABEL_16:
      qdf_trace_msg(0x34u, 2u, v40, v25, v26, v27, v28, v29, v30, v31, v32, "csr_setup_vdev_session", v23);
      goto LABEL_19;
    }
    *v39 = v23;
    v39[1] = 1;
    *(_DWORD *)(a1 + 60) = *(unsigned __int16 *)(v21[1] + 1268LL);
    *(_DWORD *)(a1 + 48) = v19[2674] & 3
                         | (4 * (v19[2616] & 3))
                         | (16 * (unsigned __int8)v19[2617])
                         | (32 * (unsigned __int8)v19[2618])
                         | ((unsigned __int8)v19[2619] << 6)
                         | ((unsigned __int8)v19[2620] << 7)
                         | ((unsigned __int8)v19[2621] << 8)
                         | ((unsigned __int8)v19[2622] << 11)
                         | ((unsigned __int8)v19[2623] << 12)
                         | ((v19[2624] & 7) << 13)
                         | ((v19[2625] & 7) << 16)
                         | ((unsigned __int8)v19[2626] << 19)
                         | ((unsigned __int8)v19[2668] << 20)
                         | ((unsigned __int8)v19[2627] << 21)
                         | ((unsigned __int8)v19[2628] << 22)
                         | ((unsigned __int8)v19[2630] << 28)
                         | ((unsigned __int8)v19[2631] << 29)
                         | ((v19[2673] & 7) << 23);
    csr_update_session_he_cap((__int64)v21, v39);
    csr_send_set_ie(
      *(unsigned __int8 *)(a1 + 163),
      *(_BYTE *)(a1 + 164),
      *(_BYTE *)(v20 + 104),
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48);
    if ( *(_BYTE *)(a1 + 163) == 2 )
    {
      vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(v21[2695], *(_BYTE *)(v20 + 104), 7u);
      if ( vdev_by_id_from_pdev )
      {
        v58 = (__int64)vdev_by_id_from_pdev;
        dynamic_oce_flags = (_BYTE *)mlme_get_dynamic_oce_flags(
                                       (__int64)vdev_by_id_from_pdev,
                                       v50,
                                       v51,
                                       v52,
                                       v53,
                                       v54,
                                       v55,
                                       v56,
                                       v57);
        if ( dynamic_oce_flags )
        {
          v60 = (unsigned int *)*(unsigned __int8 *)(v21[1] + 3456LL);
          *dynamic_oce_flags = (_BYTE)v60;
        }
        wlan_objmgr_vdev_release_ref(v58, 7u, v60, v61, v62, v63, v64, v65, v66, v67, v68);
      }
      wlan_mlme_update_oce_flags(v21[2695]);
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
