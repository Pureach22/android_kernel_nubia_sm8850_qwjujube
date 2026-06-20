__int64 __fastcall target_if_mlo_link_recfg_indication_event_handler(__int64 a1, __int64 a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 psoc_from_scn_hdl; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  unsigned int v24; // w10
  __int64 v25; // x9
  unsigned int v26; // w10
  const char *v27; // x2
  unsigned int v28; // w1
  __int64 result; // x0
  __int64 v30; // x22
  __int64 v31; // x8
  __int64 v32; // x21
  unsigned int mlo_link_recfg_indication_evt; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w19
  _DWORD *v43; // x8
  _BYTE s[272]; // [xsp+8h] [xbp-118h] BYREF
  __int64 v45; // [xsp+118h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: scn: 0x%pK, data: 0x%pK",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "target_if_mlo_link_recfg_indication_event_handler",
      a1,
      a2);
LABEL_30:
    result = 4294967274LL;
    goto LABEL_31;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v27 = "%s: null psoc";
LABEL_10:
    v28 = 2;
LABEL_29:
    qdf_trace_msg(
      0x49u,
      v28,
      v27,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "target_if_mlo_link_recfg_indication_event_handler");
    goto LABEL_30;
  }
  v23 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v23 )
    goto LABEL_28;
  v24 = *(_DWORD *)(v23 + 504);
  v25 = v23 + 3120;
  if ( v24 <= 0xA )
  {
    if ( *(_DWORD *)v25 == v24 )
    {
      v26 = 0;
LABEL_25:
      v25 += 184LL * v26;
      goto LABEL_26;
    }
    if ( *(_DWORD *)(v23 + 3304) == v24 )
    {
      v26 = 1;
      goto LABEL_25;
    }
    if ( *(_DWORD *)(v23 + 3488) == v24 )
    {
      v26 = 2;
      goto LABEL_25;
    }
    if ( *(_DWORD *)(v23 + 3672) == v24 )
    {
      v26 = 3;
      goto LABEL_25;
    }
    if ( *(_DWORD *)(v23 + 3856) == v24 )
    {
      v26 = 4;
      goto LABEL_25;
    }
    if ( *(_DWORD *)(v23 + 4040) == v24 )
    {
      v26 = 5;
      goto LABEL_25;
    }
    if ( *(_DWORD *)(v23 + 4224) == v24 )
    {
      v26 = 6;
      goto LABEL_25;
    }
    if ( *(_DWORD *)(v23 + 4408) == v24 )
    {
      v26 = 7;
      goto LABEL_25;
    }
LABEL_28:
    v27 = "%s: unexpected fw link recnfig not supported";
    v28 = 8;
    goto LABEL_29;
  }
LABEL_26:
  if ( !v25 || (*(_WORD *)(v25 + 174) & 0x2000) == 0 )
    goto LABEL_28;
  v30 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v30 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: rx_ops is NULL", v15, v16, v17, v18, v19, v20, v21, v22, "target_if_mlo_get_rx_ops");
    goto LABEL_38;
  }
  if ( !*(_QWORD *)(v30 + 1288) )
  {
LABEL_38:
    v27 = "%s: callback not registered";
    goto LABEL_10;
  }
  v31 = *(_QWORD *)(v23 + 16);
  if ( !v31 )
  {
    v27 = "%s: wmi_handle is null";
    goto LABEL_10;
  }
  v32 = psoc_from_scn_hdl;
  mlo_link_recfg_indication_evt = wmi_extract_mlo_link_recfg_indication_evt(v31, a2, a3, s);
  if ( mlo_link_recfg_indication_evt )
  {
    v42 = mlo_link_recfg_indication_evt;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Unable to extract link recfg ind fixed param, ret = %d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "target_if_mlo_link_recfg_indication_event_handler",
      mlo_link_recfg_indication_evt);
    result = v42;
  }
  else
  {
    v43 = *(_DWORD **)(v30 + 1288);
    if ( *(v43 - 1) != 77447232 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _BYTE *))v43)(v32, s);
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
