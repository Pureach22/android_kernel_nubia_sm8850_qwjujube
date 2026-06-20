__int64 __fastcall get_default_sscan_bw(
        __int64 *a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *vdev; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x23
  unsigned int ch_width; // w20
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  const char *v35; // x2
  const char *v36; // x3
  __int64 v37; // x8
  __int64 v38; // x9
  __int64 v39; // x10
  unsigned int v40; // w11
  unsigned int *v41; // x9
  bool v42; // cc
  __int64 v43; // x8
  __int64 v44; // x9
  unsigned int v45; // w10
  unsigned int *v46; // x8

  vdev = target_if_spectral_get_vdev(a1, a2, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !vdev )
  {
    v35 = "%s: vdev is null";
    v36 = "get_default_sscan_bw";
LABEL_28:
    qdf_trace_msg(0x56u, 2u, v35, v15, v16, v17, v18, v19, v20, v21, v22, v36);
    return 8;
  }
  v23 = (__int64)vdev;
  ch_width = target_if_vdev_get_ch_width(vdev);
  result = wlan_objmgr_vdev_release_ref(v23, 0x1Bu, v25, v26, v27, v28, v29, v30, v31, v32, v33);
  if ( ch_width >= 8 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid vdev channel width %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "get_default_sscan_bw",
      ch_width);
    return 8;
  }
  if ( !a2 )
  {
    if ( ch_width == 7 )
      return 8;
    v43 = ch_width;
    result = 8;
    v44 = dword_A2CCAC[v43];
    v45 = *(_DWORD *)((char *)a1 + v43 * 4 + 1976);
    v46 = (unsigned int *)((char *)&supported_sscan_bw_list + 4 * v44);
    while ( ((v45 >> v44) & 1) == 0 )
    {
      v42 = (int)v44 <= 0;
      LODWORD(v44) = v44 - 1;
      --v46;
      if ( v42 )
        return result;
    }
    if ( (unsigned int)v44 <= 6 )
      return *v46;
    goto LABEL_38;
  }
  if ( !a1 )
  {
    v35 = "%s: Spectral object is null";
LABEL_27:
    v36 = "target_if_spectral_find_agile_width";
    goto LABEL_28;
  }
  if ( !*a1 )
  {
    v35 = "%s: pdev is null";
    goto LABEL_27;
  }
  v37 = *(_QWORD *)(*a1 + 80);
  if ( !v37 )
  {
    v35 = "%s: psoc is null";
    goto LABEL_27;
  }
  if ( ch_width != 7 )
  {
    v38 = ch_width;
    v39 = dword_A2CCAC[v38];
    v40 = *(_DWORD *)((char *)a1 + v38 * 4 + 2012);
    v41 = (unsigned int *)((char *)&supported_sscan_bw_list + 4 * v39);
    while ( ((v40 >> v39) & 1) == 0 )
    {
      v42 = (int)v39 <= 0;
      LODWORD(v39) = v39 - 1;
      --v41;
      if ( v42 )
        goto LABEL_14;
    }
    if ( (unsigned int)v39 <= 6 )
    {
      result = *v41;
      if ( (*(_BYTE *)(v37 + 22) & 0x10) == 0 )
        return result;
      goto LABEL_33;
    }
LABEL_38:
    __break(0x5512u);
    return target_if_vdev_get_ch_width(result);
  }
LABEL_14:
  result = 8;
  if ( (*(_BYTE *)(v37 + 22) & 0x10) == 0 )
    return result;
LABEL_33:
  if ( ch_width == 3 || ch_width == 4 )
  {
    if ( (a3 & 1) != 0 )
      return 4;
    else
      return 3;
  }
  return result;
}
