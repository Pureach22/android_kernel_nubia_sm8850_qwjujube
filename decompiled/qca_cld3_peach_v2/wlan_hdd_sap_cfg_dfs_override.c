__int64 __fastcall wlan_hdd_sap_cfg_dfs_override(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x20
  unsigned int v12; // w22
  int v13; // w23
  unsigned int v14; // w24
  unsigned int v15; // w25
  __int64 v16; // x21
  double v17; // d0
  char v18; // w0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _QWORD *link_info_by_vdev; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _QWORD *v35; // x20
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 result; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  void *v55; // x0
  void *v56; // x0
  int v57; // w8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x0
  _QWORD v67[2]; // [xsp+0h] [xbp-10h] BYREF

  v67[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v67[0] = 0;
  v10 = *(_QWORD *)(v9 + 24);
  if ( !v10 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: hdd context is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_sap_cfg_dfs_override");
LABEL_19:
    result = 0;
    goto LABEL_20;
  }
  v12 = *((_DWORD *)a1 + 180);
  v13 = *((_DWORD *)a1 + 188);
  v14 = *((_DWORD *)a1 + 358);
  v15 = *((_DWORD *)a1 + 359);
  v16 = *(_QWORD *)(v10 + 8);
  v17 = sap_phymode_is_eht(*((unsigned int *)a1 + 80));
  if ( (policy_mgr_is_sap_override_dfs_required(
          v16,
          v12,
          v13,
          v14,
          v15,
          v18 & 1,
          (unsigned int *)v67 + 1,
          (unsigned int *)v67,
          v17,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25)
      & 1) == 0
    || HIDWORD(v67[0]) > 0xFE
    || HIDWORD(v67[0]) == *((unsigned __int8 *)a1 + 8) )
  {
    goto LABEL_19;
  }
  link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev(v10);
  if ( !link_info_by_vdev )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid vdev",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "wlan_hdd_sap_cfg_dfs_override");
    result = 4294967274LL;
    goto LABEL_20;
  }
  v35 = link_info_by_vdev;
  if ( !*link_info_by_vdev )
    goto LABEL_19;
  if ( *link_info_by_vdev == *a1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d and conc vdev %d belong to same adapter",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "wlan_hdd_sap_cfg_dfs_override",
      *((unsigned __int8 *)a1 + 8),
      HIDWORD(v67[0]));
    goto LABEL_19;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Only SCC AP-AP DFS Permitted (ch_freq=%d, con_ch_freq=%d)",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "wlan_hdd_sap_cfg_dfs_override",
    *((unsigned int *)a1 + 180),
    LODWORD(v67[0]));
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Overriding guest AP's channel",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "wlan_hdd_sap_cfg_dfs_override");
  result = LODWORD(v67[0]);
  *((_DWORD *)a1 + 180) = v67[0];
  if ( *((_BYTE *)v35 + 1424) == 1 )
  {
    if ( (_DWORD)result == *((_DWORD *)v35 + 497) || (_DWORD)result == *((_DWORD *)v35 + 498) )
    {
      v53 = a1[180];
      if ( v53 )
      {
        _qdf_mem_free(v53);
        a1[180] = 0;
      }
      v54 = a1[182];
      if ( v54 )
      {
        _qdf_mem_free(v54);
        a1[182] = 0;
      }
      qdf_mem_copy(a1 + 178, v35 + 178, 0x268u);
      v55 = (void *)_qdf_mem_malloc(4LL * *((unsigned __int8 *)v35 + 1448), "wlan_hdd_sap_cfg_dfs_override", 2336);
      a1[180] = (__int64)v55;
      if ( v55 )
      {
        qdf_mem_copy(v55, (const void *)v35[180], 4 * (unsigned int)*((unsigned __int8 *)v35 + 1448));
        v56 = (void *)_qdf_mem_malloc(4LL * *((unsigned __int8 *)v35 + 1464), "wlan_hdd_sap_cfg_dfs_override", 2348);
        a1[182] = (__int64)v56;
        if ( v56 )
        {
          qdf_mem_copy(v56, (const void *)v35[182], 4 * (unsigned int)*((unsigned __int8 *)v35 + 1464));
          result = LODWORD(v67[0]);
        }
        else
        {
          v66 = a1[180];
          *((_BYTE *)a1 + 1464) = 0;
          _qdf_mem_free(v66);
          a1[180] = 0;
          result = 4294967284LL;
        }
      }
      else
      {
        *((_BYTE *)a1 + 1448) = 0;
        result = 4294967284LL;
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Primary AP channel config error",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "wlan_hdd_sap_cfg_dfs_override");
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Operating ch: %d ACS ch freq: %d Sec Freq %d",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "wlan_hdd_sap_cfg_dfs_override",
        LODWORD(v67[0]),
        *((unsigned int *)v35 + 497),
        *((unsigned int *)v35 + 498));
      result = 4294967274LL;
    }
  }
  else
  {
    v57 = *((unsigned __int16 *)a1 + 733);
    *((_DWORD *)a1 + 497) = result;
    if ( v57 )
      *((_DWORD *)a1 + 498) = *((_DWORD *)v35 + 181);
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
