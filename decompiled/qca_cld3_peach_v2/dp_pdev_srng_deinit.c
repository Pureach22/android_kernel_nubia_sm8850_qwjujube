__int64 __fastcall dp_pdev_srng_deinit(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14)
{
  __int64 v14; // x20
  unsigned __int8 *v15; // x19
  unsigned __int64 v16; // x6
  __int64 v17; // x21
  __int64 v18; // x1
  __int64 *v19; // x21
  __int64 v20; // t1
  _DWORD *v21; // x8
  __int64 v22; // x0
  unsigned int v23; // w21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x22
  __int64 v33; // x3
  __int64 v34; // x4
  __int64 v35; // x5
  __int64 v36; // x6
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x1
  _DWORD *v46; // x8
  unsigned int v47; // w21
  int v48; // w26
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w26
  __int64 v58; // x27
  __int64 v59; // x3
  __int64 v60; // x4
  __int64 v61; // x5
  __int64 v62; // x6
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x1
  _DWORD *v72; // x8

  v14 = *(_QWORD *)(result + 8);
  v15 = (unsigned __int8 *)result;
  if ( (*(_BYTE *)(v14 + 20096) & 2) == 0 )
  {
    v16 = *(unsigned __int8 *)(result + 1);
    if ( v16 >= 2 )
      goto LABEL_42;
    v17 = v14 + 80LL * *(unsigned __int8 *)(result + 1);
    v20 = *(_QWORD *)(v17 + 80);
    v19 = (__int64 *)(v17 + 80);
    v18 = v20;
    if ( !v20 )
    {
      result = qdf_trace_msg(
                 0x7Cu,
                 2u,
                 "%s: %pK: Ring type: %d, num:%d not setup",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "dp_srng_deinit",
                 v14,
                 14);
      if ( (*(_BYTE *)(v14 + 20120) & 1) != 0 )
        return result;
      goto LABEL_10;
    }
    v21 = *(_DWORD **)(v14 + 1752);
    if ( v21 )
    {
      v22 = *(_QWORD *)(result + 8);
      if ( *(v21 - 1) != -1607343988 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64 *, __int64, _QWORD))v21)(v22, v19, 14, (unsigned int)v16);
      v18 = *v19;
    }
    result = hal_srng_cleanup(*(_QWORD *)(v14 + 1128), v18, 0, a12, a13, a14, v16);
    *v19 = 0;
  }
  if ( (*(_BYTE *)(v14 + 20120) & 1) != 0 )
    return result;
LABEL_10:
  result = *(_QWORD *)(v14 + 40);
  if ( !*(_BYTE *)(result + 804) )
    return result;
  v23 = *v15;
  result = wlan_cfg_per_pdev_lmac_ring(result);
  if ( (_DWORD)result )
  {
    if ( !v23 )
    {
      v23 = *(unsigned __int8 *)(*(_QWORD *)(v14 + 72) + 1LL);
      goto LABEL_14;
    }
LABEL_42:
    __break(0x5512u);
    return dp_rxdma_ring_cleanup(result, a2);
  }
LABEL_14:
  if ( v23 > 1 )
    goto LABEL_42;
  v32 = v14 + 320 + 80LL * v23;
  wlan_minidump_remove(
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    *(_QWORD *)(v32 + 8),
    *(unsigned int *)(v32 + 40),
    *(_QWORD *)(v14 + 16));
  v45 = *(_QWORD *)v32;
  if ( *(_QWORD *)v32 )
  {
    v46 = *(_DWORD **)(v14 + 1752);
    if ( v46 )
    {
      if ( *(v46 - 1) != -1607343988 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v46)(v14, v14 + 320 + 80LL * v23, 15, v23);
      v45 = *(_QWORD *)v32;
    }
    hal_srng_cleanup(*(_QWORD *)(v14 + 1128), v45, 0, v33, v34, v35, v36);
    *(_QWORD *)v32 = 0;
  }
  else
  {
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: Ring type: %d, num:%d not setup",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "dp_srng_deinit",
      v14,
      15,
      v23);
  }
  result = *(_QWORD *)(v14 + 40);
  if ( *(unsigned __int8 *)(result + 804) >= 2u )
  {
    v47 = 1;
    do
    {
      v48 = *v15;
      result = wlan_cfg_per_pdev_lmac_ring(result);
      if ( (_DWORD)result )
      {
        if ( v48 )
          goto LABEL_42;
        v57 = *(unsigned __int8 *)(*(_QWORD *)(v14 + 72) + 1LL);
        if ( v57 > 1 )
          goto LABEL_42;
      }
      else if ( v48 )
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Both mac_id and pdev_id cannot be non zero",
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          "dp_get_lmac_id_for_pdev_id");
        v57 = 0;
      }
      else
      {
        v57 = v47;
        if ( v47 > 1 )
          goto LABEL_42;
      }
      v58 = v14 + 320 + 80LL * v57;
      wlan_minidump_remove(
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        *(_QWORD *)(v58 + 8),
        *(unsigned int *)(v58 + 40),
        *(_QWORD *)(v14 + 16));
      v71 = *(_QWORD *)v58;
      if ( *(_QWORD *)v58 )
      {
        v72 = *(_DWORD **)(v14 + 1752);
        if ( v72 )
        {
          if ( *(v72 - 1) != -1607343988 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v72)(v14, v14 + 320 + 80LL * v57, 15, v57);
          v71 = *(_QWORD *)v58;
        }
        hal_srng_cleanup(*(_QWORD *)(v14 + 1128), v71, 0, v59, v60, v61, v62);
        *(_QWORD *)v58 = 0;
      }
      else
      {
        qdf_trace_msg(
          0x7Cu,
          2u,
          "%s: %pK: Ring type: %d, num:%d not setup",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "dp_srng_deinit",
          v14,
          15,
          v57);
      }
      result = *(_QWORD *)(v14 + 40);
      ++v47;
    }
    while ( v47 < *(unsigned __int8 *)(result + 804) );
  }
  return result;
}
