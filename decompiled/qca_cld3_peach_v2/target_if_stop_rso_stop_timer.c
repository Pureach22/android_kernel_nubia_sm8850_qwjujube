__int64 __fastcall target_if_stop_rso_stop_timer(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v9; // w8
  __int64 v11; // x0
  __int64 v12; // x22
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w21
  __int64 v23; // x20
  __int64 v24; // x0
  __int64 (__fastcall *v25)(__int64, __int64); // x8
  __int64 v26; // x1
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int *v36; // x8
  __int64 v37; // x21
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w8
  __int64 result; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x8
  __int64 v58; // x5
  unsigned int v59; // w19
  __int64 v60; // x8
  __int64 v61; // x5
  __int64 v62; // x23
  __int64 v63; // x0
  _QWORD *v64; // x24
  __int64 v65; // x0
  unsigned int v66; // w21
  __int64 (__fastcall *v67)(__int64, __int64); // x8
  __int64 v68; // x1
  __int64 v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x0
  _QWORD *v79; // x23
  __int64 v80; // t1
  __int64 v81; // x0
  unsigned int v82; // w21
  __int64 (__fastcall *v83)(__int64, __int64); // x8
  __int64 v84; // x1

  v9 = *((_DWORD *)a1 + 4);
  a1[56] = 0;
  if ( v9 == 7 && *((_DWORD *)a1 + 6) == 11 )
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: HO_FAIL happened, wait for HO_FAIL event vdev_id: %u",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_stop_rso_stop_timer",
      *a1);
  v11 = *((_QWORD *)a1 + 1);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 2136)) == 0 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_19;
  }
  if ( !*(_QWORD *)(v12 + 1136) )
  {
LABEL_19:
    qdf_trace_msg(0x68u, 2u, "%s: No Rx Ops", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_find_active_rso_stop_rsp");
    goto LABEL_20;
  }
  v13 = ((__int64 (*)(void))wlan_objmgr_get_vdev_by_id_from_psoc)();
  if ( v13 )
  {
    v22 = *a1;
    v23 = v13;
    v24 = *((_QWORD *)a1 + 1);
    v25 = *(__int64 (__fastcall **)(__int64, __int64))(v12 + 1136);
    v26 = *a1;
    if ( *((_DWORD *)v25 - 1) != -672477040 )
      __break(0x8228u);
    v27 = v25(v24, v26);
    if ( v27 )
    {
      v36 = *(unsigned int **)(v27 + 64);
      if ( ((unsigned __int8)v36 & 0x20) != 0 )
      {
        v37 = v27;
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: MLO_ROAM: RSO bit set on vdev id %d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "target_if_is_vdev_rsp_valid",
          *(unsigned __int8 *)(v27 + 84));
LABEL_13:
        wlan_objmgr_vdev_release_ref(v23, 1u, v38, v39, v40, v41, v42, v43, v44, v45, v46);
        v47 = *((_DWORD *)a1 + 4);
        if ( v47 != 5 && (v47 != 7 || (*((_DWORD *)a1 + 6) & 0xFFFFFFFE) != 4) )
          return 0;
        result = target_if_vdev_mgr_rsp_timer_stop(*((_QWORD *)a1 + 1), v37, 5u);
        a1[56] = 1;
        if ( (_DWORD)result )
        {
          v57 = *((_QWORD *)a1 + 1);
          a1[56] = 0;
          v58 = *a1;
          v59 = result;
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: PSOC_%d VDEV_%d: VDEV MGR RSO Stop RSP Timer stop failed",
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            "target_if_stop_rso_stop_timer",
            *(unsigned __int8 *)(v57 + 48),
            v58);
          return v59;
        }
        return result;
      }
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: MLO_ROAM: vdev rsp not found for vdev:%d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "target_if_is_vdev_rsp_valid",
        v22);
    }
    v62 = *(_QWORD *)(v23 + 1360);
    if ( v62 )
    {
      v64 = (_QWORD *)(v62 + 24);
      v63 = *(_QWORD *)(v62 + 24);
      if ( v63 && !(unsigned int)wlan_objmgr_vdev_try_get_ref(v63, 0x5Au, v28, v29, v30, v31, v32, v33, v34, v35) )
      {
        v65 = *((_QWORD *)a1 + 1);
        v66 = *(unsigned __int8 *)(*v64 + 168LL);
        v67 = *(__int64 (__fastcall **)(__int64, __int64))(v12 + 1136);
        v68 = *(unsigned __int8 *)(*v64 + 168LL);
        if ( *((_DWORD *)v67 - 1) != -672477040 )
          __break(0x8228u);
        v69 = v67(v65, v68);
        if ( v69 )
        {
          if ( (*(_QWORD *)(v69 + 64) & 0x20) != 0 )
            goto LABEL_44;
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: MLO_ROAM: vdev rsp not found for vdev:%d",
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            "target_if_is_vdev_rsp_valid",
            v66);
        }
        mlo_release_vdev_ref(*v64);
      }
      v80 = *(_QWORD *)(v62 + 32);
      v79 = (_QWORD *)(v62 + 32);
      v78 = v80;
      if ( v80 && !(unsigned int)wlan_objmgr_vdev_try_get_ref(v78, 0x5Au, v28, v29, v30, v31, v32, v33, v34, v35) )
      {
        v81 = *((_QWORD *)a1 + 1);
        v82 = *(unsigned __int8 *)(*v79 + 168LL);
        v83 = *(__int64 (__fastcall **)(__int64, __int64))(v12 + 1136);
        v84 = *(unsigned __int8 *)(*v79 + 168LL);
        if ( *((_DWORD *)v83 - 1) != -672477040 )
          __break(0x8228u);
        v69 = v83(v81, v84);
        if ( v69 )
        {
          if ( (*(_QWORD *)(v69 + 64) & 0x20) != 0 )
          {
            v64 = v79;
LABEL_44:
            v37 = v69;
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: MLO_ROAM: RSO bit set on vdev id %d",
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              "target_if_is_vdev_rsp_valid",
              *(unsigned __int8 *)(v69 + 84));
            mlo_release_vdev_ref(*v64);
            goto LABEL_13;
          }
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: MLO_ROAM: vdev rsp not found for vdev:%d",
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            "target_if_is_vdev_rsp_valid",
            v82);
        }
        mlo_release_vdev_ref(*v79);
      }
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: RSO bit not set on any mlo vdev",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "target_if_find_active_rso_stop_rsp");
    }
    wlan_objmgr_vdev_release_ref(v23, 1u, v36, v28, v29, v30, v31, v32, v33, v34, v35);
  }
LABEL_20:
  v60 = *((_QWORD *)a1 + 1);
  if ( v60 )
    v61 = *(unsigned __int8 *)(v60 + 48);
  else
    v61 = 255;
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev response timer is null VDEV_%d PSOC_%d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "target_if_stop_rso_stop_timer",
    *a1,
    v61);
  return 4;
}
