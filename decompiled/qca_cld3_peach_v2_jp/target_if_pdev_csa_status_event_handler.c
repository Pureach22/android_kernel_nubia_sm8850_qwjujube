__int64 __fastcall target_if_pdev_csa_status_event_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_from_scn_hdl; // x0
  __int64 v12; // x22
  __int64 v13; // x19
  __int64 v14; // x26
  __int64 v15; // x21
  const char *v16; // x2
  __int64 result; // x0
  void (__fastcall *v18)(__int64, __int64, __int64); // x8
  __int64 v19; // x1
  __int64 v20; // x2
  signed int v21; // w27
  unsigned int v22; // w25
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x24
  __int64 cmpt_obj; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x8
  unsigned int (*v43)(void); // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x8
  _DWORD *v53; // x8
  __int64 v54; // [xsp+8h] [xbp-38h] BYREF
  __int64 v55; // [xsp+10h] [xbp-30h]
  __int64 v56; // [xsp+18h] [xbp-28h]
  _QWORD v57[4]; // [xsp+20h] [xbp-20h] BYREF

  v57[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  v56 = 0;
  v54 = 0;
  if ( !a1 || !a2 )
  {
    v16 = "%s: Invalid input";
    goto LABEL_15;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v16 = "%s: PSOC is NULL";
    goto LABEL_15;
  }
  v12 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  v13 = psoc_from_scn_hdl;
  if ( !v12 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_13;
  }
  if ( !*(_QWORD *)(v12 + 1152) )
  {
LABEL_13:
    v16 = "%s: No Rx Ops";
    goto LABEL_15;
  }
  v14 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v14 || (v15 = *(_QWORD *)(v14 + 16)) == 0 )
  {
    v16 = "%s: wmi_handle is null";
    goto LABEL_15;
  }
  qdf_mem_set(&v54, 0x18u, 0);
  if ( (unsigned int)wmi_extract_pdev_csa_switch_count_status(v15, a2, &v54) )
  {
    v16 = "%s: Extracting CSA switch count status event failed";
LABEL_15:
    qdf_trace_msg(0x68u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_pdev_csa_status_event_handler");
    result = 4294967274LL;
    goto LABEL_16;
  }
  if ( HIDWORD(v54) == 1 )
  {
    v18 = *(void (__fastcall **)(__int64, __int64, __int64))(v12 + 1152);
    v19 = v56;
    v20 = (unsigned int)v55;
    if ( *((_DWORD *)v18 - 1) != -1488742217 )
      __break(0x8228u);
    v18(v13, v19, v20);
  }
  if ( (*(_BYTE *)(v13 + 23) & 2) != 0 && (_DWORD)v55 )
  {
    v21 = 0;
    do
    {
      v22 = *(unsigned __int8 *)(v56 + 4LL * v21);
      v23 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              v13,
              *(unsigned __int8 *)(v56 + 4LL * v21),
              49);
      if ( v23 )
      {
        v32 = v23;
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj();
        if ( cmpt_obj )
        {
          v42 = *(_QWORD *)(cmpt_obj + 512);
          if ( v42 )
          {
            v43 = *(unsigned int (**)(void))(v42 + 192);
            if ( v43 )
            {
              if ( *((_DWORD *)v43 - 1) != -1843776435 )
                __break(0x8228u);
              if ( v43() )
                qdf_trace_msg(
                  0x68u,
                  2u,
                  "%s: vdev csa complete failed",
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  "target_if_vdev_csa_complete");
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: VDEV_%d: PSOC_%d VDEV_MLME is NULL",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "target_if_vdev_csa_complete",
            v22,
            *(unsigned __int8 *)(v13 + 48));
        }
        wlan_objmgr_vdev_release_ref(v32, 49);
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: VDEV is NULL",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "target_if_vdev_csa_complete");
      }
      ++v21;
    }
    while ( v21 < (unsigned int)v55 );
  }
  v52 = *(_QWORD *)(v14 + 4512);
  if ( v52 && (v53 = *(_DWORD **)(v52 + 152)) != nullptr )
  {
    v57[0] = v54;
    v57[1] = v55;
    v57[2] = v56;
    if ( *(v53 - 1) != 925576303 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD *))v53)(v13, v57);
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
