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
  char is_sap_override_dfs_required; // w8
  __int64 result; // x0
  _QWORD *link_info_by_vdev; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  __int64 v41; // x0
  void *v42; // x0
  void *v43; // x0
  int v44; // w8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x0
  _QWORD v54[2]; // [xsp+0h] [xbp-10h] BYREF

  v54[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v54[0] = 0;
  v10 = *(_QWORD *)(v9 + 24);
  if ( !v10 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: hdd context is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_sap_cfg_dfs_override");
    goto LABEL_19;
  }
  is_sap_override_dfs_required = policy_mgr_is_sap_override_dfs_required(
                                   *(_QWORD *)(v10 + 8),
                                   *((_DWORD *)a1 + 180),
                                   *((_DWORD *)a1 + 186),
                                   *((_DWORD *)a1 + 356),
                                   *((_DWORD *)a1 + 357),
                                   a2,
                                   a3,
                                   a4,
                                   a5,
                                   a6,
                                   a7,
                                   a8,
                                   a9,
                                   0,
                                   (unsigned int *)v54 + 1,
                                   (unsigned int *)v54);
  result = 0;
  if ( (is_sap_override_dfs_required & 1) == 0 )
    goto LABEL_20;
  if ( HIDWORD(v54[0]) > 0xFE || HIDWORD(v54[0]) == *((unsigned __int8 *)a1 + 8) )
    goto LABEL_19;
  link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev(v10);
  if ( !link_info_by_vdev )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid vdev",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_hdd_sap_cfg_dfs_override");
    result = 4294967274LL;
    goto LABEL_20;
  }
  v23 = link_info_by_vdev;
  if ( !*link_info_by_vdev )
  {
LABEL_19:
    result = 0;
    goto LABEL_20;
  }
  if ( *link_info_by_vdev == *a1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d and conc vdev %d belong to same adapter",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_hdd_sap_cfg_dfs_override",
      *((unsigned __int8 *)a1 + 8),
      HIDWORD(v54[0]));
    goto LABEL_19;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Only SCC AP-AP DFS Permitted (ch_freq=%d, con_ch_freq=%d)",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "wlan_hdd_sap_cfg_dfs_override",
    *((unsigned int *)a1 + 180),
    LODWORD(v54[0]));
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Overriding guest AP's channel",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "wlan_hdd_sap_cfg_dfs_override");
  result = LODWORD(v54[0]);
  *((_DWORD *)a1 + 180) = v54[0];
  if ( *((_BYTE *)v23 + 1416) == 1 )
  {
    if ( (_DWORD)result == *((_DWORD *)v23 + 495) || (_DWORD)result == *((_DWORD *)v23 + 496) )
    {
      v40 = a1[179];
      if ( v40 )
      {
        _qdf_mem_free(v40);
        a1[179] = 0;
      }
      v41 = a1[181];
      if ( v41 )
      {
        _qdf_mem_free(v41);
        a1[181] = 0;
      }
      qdf_mem_copy(a1 + 177, v23 + 177, 0x260u);
      v42 = (void *)_qdf_mem_malloc(4LL * *((unsigned __int8 *)v23 + 1440), "wlan_hdd_sap_cfg_dfs_override", 2336);
      a1[179] = (__int64)v42;
      if ( v42 )
      {
        qdf_mem_copy(v42, (const void *)v23[179], 4 * (unsigned int)*((unsigned __int8 *)v23 + 1440));
        v43 = (void *)_qdf_mem_malloc(4LL * *((unsigned __int8 *)v23 + 1456), "wlan_hdd_sap_cfg_dfs_override", 2348);
        a1[181] = (__int64)v43;
        if ( v43 )
        {
          qdf_mem_copy(v43, (const void *)v23[181], 4 * (unsigned int)*((unsigned __int8 *)v23 + 1456));
          result = LODWORD(v54[0]);
        }
        else
        {
          v53 = a1[179];
          *((_BYTE *)a1 + 1456) = 0;
          _qdf_mem_free(v53);
          a1[179] = 0;
          result = 4294967284LL;
        }
      }
      else
      {
        *((_BYTE *)a1 + 1440) = 0;
        result = 4294967284LL;
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Primary AP channel config error",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "wlan_hdd_sap_cfg_dfs_override");
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Operating ch: %d ACS ch freq: %d Sec Freq %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "wlan_hdd_sap_cfg_dfs_override",
        LODWORD(v54[0]),
        *((unsigned int *)v23 + 495),
        *((unsigned int *)v23 + 496));
      result = 4294967274LL;
    }
  }
  else
  {
    v44 = *((unsigned __int16 *)a1 + 729);
    *((_DWORD *)a1 + 495) = result;
    if ( v44 )
      *((_DWORD *)a1 + 496) = *((_DWORD *)v23 + 181);
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
