__int64 __fastcall target_if_pdev_aoa_phasedaelta_event_handler(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 psoc_from_scn_hdl; // x0
  __int64 v13; // x19
  const char *v14; // x2
  __int64 result; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  const char *v18; // x2
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 pdev_by_id; // x0
  __int64 v28; // x20
  __int64 comp_private_obj; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x21
  int v39; // w8
  bool v40; // cf
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int *v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  _BYTE dest[272]; // [xsp+8h] [xbp-228h] BYREF
  _DWORD s[68]; // [xsp+118h] [xbp-118h] BYREF
  __int64 v77; // [xsp+228h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( !a1 || !a2 )
  {
    v14 = "%s: sc or data is null";
    goto LABEL_8;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v14 = "%s: psoc is null";
    goto LABEL_8;
  }
  v13 = psoc_from_scn_hdl;
  if ( (unsigned int)wlan_objmgr_psoc_try_get_ref(psoc_from_scn_hdl, 0x30u, v4, v5, v6, v7, v8, v9, v10, v11) )
  {
    v14 = "%s: unable to get psoc reference";
LABEL_8:
    qdf_trace_msg(0x6Au, 2u, v14, v4, v5, v6, v7, v8, v9, v10, v11, "target_if_pdev_aoa_phasedaelta_event_handler");
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  v16 = *(_QWORD *)(v13 + 2800);
  if ( !v16 || (v17 = *(_QWORD *)(v16 + 16)) == 0 )
  {
    v18 = "%s: wmi_handle is null";
    goto LABEL_16;
  }
  if ( (unsigned int)wmi_extract_cfr_pdev_phase_delta_event(v17) )
  {
    v18 = "%s: Failed to extract phase params";
LABEL_16:
    qdf_trace_msg(0x6Au, 2u, v18, v4, v5, v6, v7, v8, v9, v10, v11, "target_if_pdev_aoa_phasedaelta_event_handler");
    wlan_objmgr_psoc_release_ref(v13, 0x30u, v19, v20, v21, v22, v23, v24, v25, v26);
    goto LABEL_9;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(v13, s[0], 0x30u);
  if ( !pdev_by_id )
  {
    v18 = "%s: pdev is null";
    goto LABEL_16;
  }
  v28 = pdev_by_id;
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(pdev_by_id, 0x1Eu);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: pdev object for CFR is NULL",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "target_if_pdev_aoa_phasedaelta_event_handler");
    wlan_objmgr_psoc_release_ref(v13, 0x30u, v58, v59, v60, v61, v62, v63, v64, v65);
    wlan_objmgr_pdev_release_ref(v28, 0x30u, v66, v67, v68, v69, v70, v71, v72, v73, v74);
    goto LABEL_9;
  }
  v38 = comp_private_obj;
  if ( !*(_BYTE *)(comp_private_obj + 1442) )
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: AoA data event from unsupported target",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "target_if_pdev_aoa_phasedaelta_event_handler");
  v39 = s[2];
  v40 = s[2] >= 8u;
  *(_DWORD *)(v38 + 1936) = s[1];
  if ( v40 )
    v39 = 8;
  *(_DWORD *)(v38 + 1940) = v39;
  memcpy(dest, s, sizeof(dest));
  v41 = ((double (__fastcall *)(__int64, _BYTE *))populate_phase_delta)(v38, dest);
  wlan_objmgr_psoc_release_ref(v13, 0x30u, v41, v42, v43, v44, v45, v46, v47, v48);
  wlan_objmgr_pdev_release_ref(v28, 0x30u, v49, v50, v51, v52, v53, v54, v55, v56, v57);
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
