__int64 __fastcall target_if_dfs_cac_complete_event_handler(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x22
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0
  const char *v32; // x2
  __int64 v33; // x4
  __int64 v34; // x0
  __int64 v35; // x19
  unsigned int (*v36)(void); // x8
  unsigned int *v37; // x8
  const char *v38; // x2
  unsigned int v39; // w20

  _ReadStatusReg(SP_EL0);
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: scn: %pK, data: %pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_dfs_cac_complete_event_handler",
      a1,
      a2);
LABEL_17:
    result = 4294967274LL;
    goto LABEL_18;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v32 = "%s: null psoc";
LABEL_14:
    qdf_trace_msg(0x49u, 2u, v32, v11, v12, v13, v14, v15, v16, v17, v18, "target_if_dfs_cac_complete_event_handler");
    goto LABEL_17;
  }
  v19 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v19 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: rx_ops is NULL", v11, v12, v13, v14, v15, v16, v17, v18, "target_if_dfs_get_rx_ops");
    v33 = 0;
LABEL_16:
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid dfs_rx_ops: %pK",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "target_if_dfs_cac_complete_event_handler",
      v33);
    goto LABEL_17;
  }
  if ( !*(_QWORD *)(v19 + 832) )
  {
    v33 = v19 + 680;
    goto LABEL_16;
  }
  v20 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v20 || (v21 = *(_QWORD *)(v20 + 16)) == 0 )
  {
    v32 = "%s: Invalid WMI handle";
    goto LABEL_14;
  }
  v22 = psoc_from_scn_hdl;
  if ( !(unsigned int)wmi_extract_dfs_cac_complete_event(v21) )
  {
    v34 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v22, 0, 14);
    if ( v34 )
    {
      v35 = v34;
      if ( *(_QWORD *)(v34 + 216) )
      {
        v36 = *(unsigned int (**)(void))(v19 + 832);
        if ( *((_DWORD *)v36 - 1) != -1349071724 )
          __break(0x8228u);
        if ( !v36() )
        {
          v39 = 0;
          goto LABEL_29;
        }
        v38 = "%s: dfs_dfs_cac_complete_ind failed";
      }
      else
      {
        v38 = "%s: null pdev";
      }
      qdf_trace_msg(0x49u, 2u, v38, v11, v12, v13, v14, v15, v16, v17, v18, "target_if_dfs_cac_complete_event_handler");
      v39 = -22;
LABEL_29:
      wlan_objmgr_vdev_release_ref(v35, 0xEu, v37, v11, v12, v13, v14, v15, v16, v17, v18);
      result = v39;
      goto LABEL_18;
    }
    v32 = "%s: null vdev";
    goto LABEL_14;
  }
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: failed to extract cac complete event",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "target_if_dfs_cac_complete_event_handler");
  result = 4294967282LL;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
