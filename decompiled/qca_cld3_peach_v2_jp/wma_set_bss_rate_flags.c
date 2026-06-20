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
  unsigned int v12; // w22
  __int64 cmpt_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  unsigned int v25; // w9
  int v26; // w10
  int v27; // w8
  int v28; // w5
  __int64 v29; // x23
  const char *v30; // x2
  const char *v31; // x3
  int v32; // w8
  int v33; // w8
  __int64 v34; // x5
  __int64 v35; // x21
  __int64 v36; // x0
  __int64 v37; // x20
  __int64 v38; // x0
  __int64 v39; // x0
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v50; // x2
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7

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
    v30 = "%s: Failed to get mlme obj for vdev_%d";
    v31 = "wma_set_bss_rate_flags";
    return qdf_trace_msg(0x36u, 2u, v30, v16, v17, v18, v19, v20, v21, v22, v23, v31, (unsigned __int8)a2);
  }
  *(_DWORD *)(cmpt_obj + 288) = 0;
  if ( *(_BYTE *)(a3 + 301) != 1 )
  {
    if ( *(_BYTE *)(a3 + 294) )
    {
      v32 = *(_DWORD *)(a3 + 296);
      if ( v32 )
      {
        if ( v32 == 2 )
        {
          v33 = 224;
        }
        else if ( (unsigned int)(v32 - 3) >= 2 )
        {
          v33 = 96;
        }
        else
        {
          v33 = 4320;
        }
      }
      else
      {
        v33 = 32;
      }
    }
    else
    {
      if ( !*(_BYTE *)(a3 + 17) )
        goto LABEL_27;
      if ( *(_DWORD *)(a3 + 296) )
        v33 = 6;
      else
        v33 = 2;
    }
    *(_DWORD *)(cmpt_obj + 288) = v33;
    goto LABEL_27;
  }
  v24 = *(_DWORD *)(a3 + 296);
  v25 = v24 - 3;
  if ( v24 )
    v26 = 768;
  else
    v26 = 256;
  if ( v24 == 2 )
    v27 = 1792;
  else
    v27 = v26;
  if ( v25 >= 2 )
    v28 = v27;
  else
    v28 = 3840;
  v29 = cmpt_obj;
  *(_DWORD *)(cmpt_obj + 288) = v28;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: he_capable %d rate_flags 0x%x",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wma_set_bss_rate_flags_he",
    *(unsigned __int8 *)(a3 + 301));
  cmpt_obj = v29;
LABEL_27:
  if ( *(_BYTE *)(a3 + 55) || *(_BYTE *)(a3 + 54) )
    *(_DWORD *)(cmpt_obj + 288) |= 8u;
  v34 = *(unsigned __int8 *)(a3 + 17);
  if ( !*(_BYTE *)(a3 + 17) )
  {
    if ( *(_BYTE *)(a3 + 294) || (*(_BYTE *)(a3 + 301) & 1) != 0 )
    {
      v34 = 0;
    }
    else
    {
      *(_DWORD *)(cmpt_obj + 288) = 1;
      v34 = *(unsigned __int8 *)(a3 + 17);
    }
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: capable: vht %u, ht %u, rate_flags %x, ch_width %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wma_set_bss_rate_flags",
    *(unsigned __int8 *)(a3 + 294),
    v34,
    *(unsigned int *)(cmpt_obj + 288),
    *(unsigned int *)(a3 + 296));
  v35 = *(_QWORD *)(a1 + 520);
  v36 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 24),
          a2,
          8);
  if ( !v36 )
  {
    v30 = "%s: vdev not found for id: %d";
    v31 = "wma_cp_stats_set_rate_flag";
    return qdf_trace_msg(0x36u, 2u, v30, v16, v17, v18, v19, v20, v21, v22, v23, v31, (unsigned __int8)a2);
  }
  v37 = v36;
  v38 = *(_QWORD *)(v35 + 488LL * v12);
  if ( !v38 )
  {
    v50 = "%s: vdev is NULL";
LABEL_42:
    qdf_trace_msg(0x36u, 2u, v50, v16, v17, v18, v19, v20, v21, v22, v23, "wma_get_vdev_rate_flag");
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev not found for id: %d",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "wma_cp_stats_set_rate_flag",
      (unsigned __int8)a2);
    return wlan_objmgr_vdev_release_ref(v37, 8u, v40, v41, v42, v43, v44, v45, v46, v47, v48);
  }
  v39 = wlan_vdev_mlme_get_cmpt_obj(v38, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( !v39 )
  {
    v50 = "%s: ailed to get mlme_obj";
    goto LABEL_42;
  }
  ucfg_mc_cp_stats_set_rate_flags(v37, *(unsigned int *)(v39 + 288));
  return wlan_objmgr_vdev_release_ref(v37, 8u, v40, v41, v42, v43, v44, v45, v46, v47, v48);
}
