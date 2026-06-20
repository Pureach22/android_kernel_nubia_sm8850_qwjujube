__int64 __fastcall wma_pre_vdev_start_setup(
        unsigned int a1,
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
  _QWORD *context; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 *v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  __int64 v31; // x24
  __int64 cmpt_obj; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x23
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w9
  unsigned __int8 *v51; // x23
  unsigned int peer; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w19
  __int64 v62; // x8
  _DWORD *v63; // x8
  int v64; // w8
  unsigned int v65; // w0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x4
  __int64 v75; // x5
  __int64 v76; // x6
  __int64 v77; // x7

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(71, (__int64)"wma_pre_vdev_start_setup", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = _cds_get_context(54, (__int64)"wma_pre_vdev_start_setup", v13, v14, v15, v16, v17, v18, v19, v20);
  result = 16;
  if ( !context || !v21 )
    goto LABEL_26;
  v31 = v21[65] + 488LL * (unsigned __int8)a1;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)v31, v22, v23, v24, v25, v26, v27, v28, v29);
  if ( !cmpt_obj )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev component object is NULL",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "wma_pre_vdev_start_setup");
LABEL_25:
    result = 16;
    goto LABEL_26;
  }
  v41 = cmpt_obj;
  wma_set_bss_rate_flags((__int64)v21, a1, a2, v33, v34, v35, v36, v37, v38, v39, v40);
  v50 = *(_DWORD *)(*(_QWORD *)v31 + 16LL);
  if ( v50 == 11 || v50 == 5 )
    v51 = (unsigned __int8 *)(v41 + 168);
  else
    v51 = (unsigned __int8 *)(*(_QWORD *)v31 + 74LL);
  peer = wma_create_peer((__int64)v21, v51, 0, 0, a1, 0, 0, v42, v43, v44, v45, v46, v47, v48, v49);
  if ( peer )
  {
    v61 = peer;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to create peer",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "wma_pre_vdev_start_setup");
    result = v61;
    goto LABEL_26;
  }
  if ( !*context || (v62 = *(_QWORD *)(*context + 72LL)) == 0 )
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v53, v54, v55, v56, v57, v58, v59, v60, "cdp_find_peer_exist");
LABEL_21:
    if ( v51 )
    {
      v74 = *v51;
      v75 = v51[1];
      v76 = v51[2];
      v77 = v51[5];
    }
    else
    {
      v76 = 0;
      v74 = 0;
      v75 = 0;
      v77 = 0;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to find peer %02x:%02x:%02x:**:**:%02x",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "wma_pre_vdev_start_setup",
      v74,
      v75,
      v76,
      v77);
    goto LABEL_25;
  }
  v63 = *(_DWORD **)(v62 + 16);
  if ( !v63 )
    goto LABEL_21;
  if ( *(v63 - 1) != 454466150 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(_QWORD *, _QWORD, unsigned __int8 *))v63)(context, 0, v51) & 1) == 0 )
    goto LABEL_21;
  v64 = *(unsigned __int8 *)(a2 + 18);
  *(_BYTE *)(v31 + 210) = v64;
  if ( v64 )
  {
    v65 = wmi_unified_pdev_param_send(*v21);
    if ( v65 )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to set QOS MFP/PMF (%d)",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "wma_set_mgmt_frame_protection",
        v65);
    else
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: QOS MFP/PMF set",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "wma_set_mgmt_frame_protection");
  }
  result = 0;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
