__int64 __fastcall wma_set_bss_rate_flags(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v12; // w23
  __int64 cmpt_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int *v24; // x22
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  int v34; // w9
  bool v35; // zf
  unsigned int v36; // w8
  int v37; // w8
  const char *v38; // x2
  const char *v39; // x3
  int v40; // w8
  int v41; // w8
  int v42; // w8
  __int64 v43; // x21
  __int64 v44; // x0
  __int64 v45; // x20
  __int64 v46; // x0
  __int64 v47; // x0
  unsigned int *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  const char *v58; // x2
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7

  v12 = (unsigned __int8)a2;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(
               *(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * (unsigned __int8)a2),
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11);
  if ( !cmpt_obj )
  {
    v38 = "%s: Failed to get mlme obj for vdev_%d";
    v39 = "wma_set_bss_rate_flags";
    return qdf_trace_msg(0x36u, 2u, v38, v16, v17, v18, v19, v20, v21, v22, v23, v39, (unsigned __int8)a2);
  }
  v24 = (unsigned int *)(cmpt_obj + 304);
  *(_DWORD *)(cmpt_obj + 304) = 0;
  if ( (unsigned int)wma_set_bss_rate_flags_eht(cmpt_obj + 304, a3) )
  {
    if ( *(_BYTE *)(a3 + 857) != 1 )
    {
      if ( *(_BYTE *)(a3 + 850) )
      {
        v40 = *(_DWORD *)(a3 + 852);
        if ( v40 )
        {
          if ( v40 == 2 )
          {
            v41 = 224;
          }
          else if ( (unsigned int)(v40 - 3) >= 2 )
          {
            v41 = 96;
          }
          else
          {
            v41 = 4320;
          }
        }
        else
        {
          v41 = 32;
        }
      }
      else
      {
        if ( !*(_BYTE *)(a3 + 17) )
          goto LABEL_28;
        if ( *(_DWORD *)(a3 + 852) )
          v42 = 6;
        else
          v42 = 2;
        v41 = v42 | *v24;
      }
      *v24 = v41;
      goto LABEL_28;
    }
    v33 = *(_DWORD *)(a3 + 852);
    if ( v33 )
      v34 = 768;
    else
      v34 = 256;
    v35 = v33 == 2;
    v36 = v33 - 3;
    if ( v35 )
      v34 = 1792;
    if ( v36 >= 2 )
      v37 = v34;
    else
      v37 = 3840;
    *v24 |= v37;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: he_capable %d rate_flags 0x%x",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wma_set_bss_rate_flags_he",
      *(unsigned __int8 *)(a3 + 857));
  }
LABEL_28:
  if ( *(_BYTE *)(a3 + 59) || *(_BYTE *)(a3 + 58) )
    *v24 |= 8u;
  if ( !*(_BYTE *)(a3 + 17)
    && !*(_BYTE *)(a3 + 850)
    && (*(_BYTE *)(a3 + 857) & 1) == 0
    && (wma_get_bss_eht_capable(a3) & 1) == 0 )
  {
    *v24 = 1;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: capable: vht %u, ht %u, rate_flags %x, ch_width %d",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "wma_set_bss_rate_flags",
    *(unsigned __int8 *)(a3 + 850),
    *(unsigned __int8 *)(a3 + 17),
    *v24,
    *(unsigned int *)(a3 + 852));
  v43 = *(_QWORD *)(a1 + 520);
  v44 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 24),
          a2,
          8);
  if ( !v44 )
  {
    v38 = "%s: vdev not found for id: %d";
    v39 = "wma_cp_stats_set_rate_flag";
    return qdf_trace_msg(0x36u, 2u, v38, v16, v17, v18, v19, v20, v21, v22, v23, v39, (unsigned __int8)a2);
  }
  v45 = v44;
  v46 = *(_QWORD *)(v43 + 488LL * v12);
  if ( !v46 )
  {
    v58 = "%s: vdev is NULL";
LABEL_44:
    qdf_trace_msg(0x36u, 2u, v58, v16, v17, v18, v19, v20, v21, v22, v23, "wma_get_vdev_rate_flag");
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev not found for id: %d",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "wma_cp_stats_set_rate_flag",
      (unsigned __int8)a2);
    return wlan_objmgr_vdev_release_ref(v45, 8u, v48, v49, v50, v51, v52, v53, v54, v55, v56);
  }
  v47 = wlan_vdev_mlme_get_cmpt_obj(v46, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( !v47 )
  {
    v58 = "%s: ailed to get mlme_obj";
    goto LABEL_44;
  }
  ucfg_mc_cp_stats_set_rate_flags(v45, *(unsigned int *)(v47 + 304));
  return wlan_objmgr_vdev_release_ref(v45, 8u, v48, v49, v50, v51, v52, v53, v54, v55, v56);
}
