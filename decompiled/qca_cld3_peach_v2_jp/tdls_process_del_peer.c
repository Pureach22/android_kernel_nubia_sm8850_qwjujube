__int64 __fastcall tdls_process_del_peer(
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
  __int64 v10; // x20
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x21
  __int64 v22; // x0
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x5
  __int64 v33; // x22
  __int64 peer; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _DWORD *v43; // x8
  __int64 v44; // x2
  __int64 v45; // x1
  unsigned int v46; // w20
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  bool v55; // cf
  unsigned int v56; // w20
  double v57; // d0
  unsigned int v58; // w0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v67; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v68)(); // [xsp+10h] [xbp-30h]
  __int64 v69; // [xsp+18h] [xbp-28h]
  __int64 v70; // [xsp+20h] [xbp-20h]
  __int64 v71; // [xsp+28h] [xbp-18h]
  __int64 v72; // [xsp+30h] [xbp-10h]
  __int64 v73; // [xsp+38h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = nullptr;
  if ( !a1 || (v10 = *(_QWORD *)a1) == 0 )
  {
    qdf_trace_msg(0, 2u, "%s: req: %pK", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_del_peer", a1);
    v56 = 4;
LABEL_19:
    _qdf_mem_free(a1);
    goto LABEL_20;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(*(_QWORD *)a1, 0xAu);
  v20 = *(_QWORD *)(v10 + 152);
  v21 = comp_private_obj;
  if ( !v20 || (v22 = *(_QWORD *)(v20 + 80)) == 0 )
  {
    qdf_trace_msg(0, 2u, "%s: can't get psoc", v12, v13, v14, v15, v16, v17, v18, v19, "wlan_vdev_get_tdls_soc_obj");
    v32 = 0;
LABEL_17:
    qdf_trace_msg(
      0,
      2u,
      "%s: tdls vdev_obj: %pK soc_obj: %pK",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "tdls_process_del_peer",
      v21,
      v32);
LABEL_18:
    v57 = tdls_internal_del_peer_rsp(a1);
    v56 = v58;
    wlan_objmgr_vdev_release_ref(*(_QWORD *)a1, 0x11u, *(unsigned int **)a1, v57, v59, v60, v61, v62, v63, v64, v65);
    goto LABEL_19;
  }
  v23 = wlan_objmgr_psoc_get_comp_private_obj(v22, 0xAu);
  v32 = v23;
  if ( !v21 || !v23 )
    goto LABEL_17;
  v33 = v23;
  peer = tdls_find_peer(v21, a1 + 8);
  if ( !peer )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: %02x:%02x:%02x:**:**:%02x not found, ignore NL80211_TDLS_ENABLE_LINK",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "tdls_process_del_peer",
      *(unsigned __int8 *)(a1 + 8),
      *(unsigned __int8 *)(a1 + 9),
      *(unsigned __int8 *)(a1 + 10),
      *(unsigned __int8 *)(a1 + 13));
    goto LABEL_18;
  }
  if ( (*(_BYTE *)(peer + 30) & 1) == 0 )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: invalid peer:%02x:%02x:%02x:**:**:%02x link state %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "tdls_process_del_peer",
      *(unsigned __int8 *)(a1 + 8),
      *(unsigned __int8 *)(a1 + 9),
      *(unsigned __int8 *)(a1 + 10),
      *(unsigned __int8 *)(a1 + 13),
      *(_DWORD *)(peer + 36),
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73);
    goto LABEL_18;
  }
  v43 = *(_DWORD **)(v33 + 296);
  if ( v43 )
  {
    v44 = *(unsigned int *)(v33 + 344);
    v45 = *(unsigned __int8 *)(v10 + 104);
    if ( *(v43 - 1) != 792568820 )
      __break(0x8228u);
    v35 = ((double (__fastcall *)(__int64, __int64, __int64, _QWORD))v43)(v33, v45, v44, 0);
  }
  v67 = 15;
  v68 = tdls_del_peer_serialize_callback;
  LODWORD(v69) = 10;
  LODWORD(v70) = 9000;
  v71 = v10;
  v72 = a1;
  BYTE4(v69) = 2;
  v46 = wlan_serialization_request((unsigned int *)&v67, v35, v36, v37, v38, v39, v40, v41, v42);
  qdf_trace_msg(
    0,
    8u,
    "%s: req: 0x%pK wlan_serialization_request status:%d",
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    "tdls_process_del_peer",
    a1,
    v46);
  v55 = v46 >= 2;
  v56 = 0;
  if ( v55 )
    goto LABEL_18;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v56;
}
