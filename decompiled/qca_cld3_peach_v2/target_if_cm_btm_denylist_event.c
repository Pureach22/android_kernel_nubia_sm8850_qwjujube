__int64 __fastcall target_if_cm_btm_denylist_event(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 psoc_from_scn_hdl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x19
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  __int64 result; // x0
  __int64 ext_hdl; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int (__fastcall *v37)(__int64, __int64); // x8
  __int64 v38; // x1
  unsigned int v39; // w19
  __int64 v40; // x20
  __int64 v41; // [xsp+0h] [xbp-10h] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v26 = "%s: psoc is null";
    goto LABEL_8;
  }
  v14 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v14 || (v15 = *(_QWORD *)(v14 + 16)) == 0 )
  {
    v26 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v26, v6, v7, v8, v9, v10, v11, v12, v13, "target_if_cm_btm_denylist_event", v41, v42);
    goto LABEL_9;
  }
  v16 = psoc_from_scn_hdl;
  v17 = wmi_extract_btm_denylist_event(v15, a2, a3, &v41);
  if ( v17 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: parsing of event failed, %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "target_if_cm_btm_denylist_event",
      v17);
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  if ( v41 )
  {
    ext_hdl = wlan_psoc_mlme_get_ext_hdl(v16);
    if ( ext_hdl )
    {
      v37 = *(unsigned int (__fastcall **)(__int64, __int64))(ext_hdl + 7560);
      if ( v37 )
      {
        v38 = v41;
        if ( *((_DWORD *)v37 - 1) != 1818810740 )
          __break(0x8228u);
        if ( v37(v16, v38) )
          v39 = -22;
        else
          v39 = 0;
        goto LABEL_23;
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: psoc legacy private object is NULL",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "target_if_cm_get_roam_rx_ops");
    }
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: No valid roam rx ops",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "target_if_cm_btm_denylist_event",
      v41,
      v42);
    v39 = -22;
LABEL_23:
    _qdf_mem_free(v41);
    result = v39;
    goto LABEL_10;
  }
  v40 = jiffies;
  if ( target_if_cm_btm_denylist_event___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: No APs in denylist received",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "target_if_cm_btm_denylist_event");
    result = 0;
    target_if_cm_btm_denylist_event___last_ticks = v40;
  }
  else
  {
    result = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
