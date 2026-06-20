__int64 __fastcall nan_handle_delete_all_pasn_peers(
        __int64 a1,
        unsigned int a2,
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
  __int64 comp_private_obj; // x0
  _QWORD *v21; // x21
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 (*v31)(void); // x8
  __int64 v32; // x19
  unsigned int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w20
  const char *v43; // x2
  void (__fastcall *v44)(_QWORD); // x8
  const char *v45; // x2
  __int64 v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x22
  unsigned int v57; // w0
  __int64 v58; // x0

  qdf_trace_msg(
    0x53u,
    8u,
    "%s: Received all peer delete response for vdev id %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "nan_handle_delete_all_pasn_peers",
    (unsigned __int8)a2);
  if ( !a1 )
  {
    v45 = "%s: psoc is NULL";
LABEL_11:
    qdf_trace_msg(0x53u, 2u, v45, v12, v13, v14, v15, v16, v17, v18, v19, "nan_handle_delete_all_pasn_peers");
    return 29;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
    v45 = "%s: psoc_nan_obj is NULL";
    goto LABEL_11;
  }
  v21 = (_QWORD *)comp_private_obj;
  v22 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 20);
  v31 = (__int64 (*)(void))v21[24];
  v32 = v22;
  if ( !v31 )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: pasn_peer_delete_all_complete_cb is NULL",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "nan_handle_delete_all_pasn_peers");
    v42 = 29;
    goto LABEL_19;
  }
  if ( *((_DWORD *)v31 - 1) != 1263140689 )
    __break(0x8228u);
  v33 = v31();
  if ( !v33 )
  {
    if ( v32 )
    {
      v47 = wlan_objmgr_vdev_get_comp_private_obj(v32, 0xFu);
      if ( v47 )
      {
        v56 = v47;
        v57 = nan_cleanup_pasn_peers(a1);
        if ( !v57 )
        {
          *(_WORD *)(v56 + 105) = 0;
          v44 = (void (__fastcall *)(_QWORD))v21[4];
          if ( v44 )
          {
            v58 = v21[40];
            if ( *((_DWORD *)v44 - 1) != 251140989 )
              __break(0x8228u);
            v44(v58);
          }
          v42 = 0;
          goto LABEL_19;
        }
        v42 = v57;
        v43 = "%s: nan clean up err";
        goto LABEL_8;
      }
    }
    else
    {
      qdf_trace_msg(0x53u, 2u, "%s: vdev is null", v34, v35, v36, v37, v38, v39, v40, v41, "nan_get_vdev_priv_obj");
    }
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: NAN vdev priv obj is null",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "nan_handle_delete_all_pasn_peers");
    v42 = 16;
    goto LABEL_19;
  }
  v42 = v33;
  v43 = "%s: delete all complete err";
LABEL_8:
  qdf_trace_msg(0x53u, 2u, v43, v34, v35, v36, v37, v38, v39, v40, v41, "nan_handle_delete_all_pasn_peers");
LABEL_19:
  wlan_objmgr_vdev_release_ref(v32, 0x14u, (unsigned int *)v44, v34, v35, v36, v37, v38, v39, v40, v41);
  return v42;
}
