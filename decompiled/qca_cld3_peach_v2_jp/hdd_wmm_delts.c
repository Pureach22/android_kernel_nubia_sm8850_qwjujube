__int64 __fastcall hdd_wmm_delts(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x8
  __int64 v13; // x22
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w23
  unsigned int v24; // w24
  int v25; // w21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v43; // w21
  unsigned int v44; // w20
  __int64 v45; // x8
  __int64 v46; // x21
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  const char *v55; // x2
  unsigned int v56; // w1
  unsigned int v57; // w8
  __int64 v58; // x10
  __int64 v59; // x20
  const char *v60; // x2

  if ( a1 && (v12 = *(_QWORD *)(a1 + 24)) != 0 )
    v13 = *(_QWORD *)(v12 + 16);
  else
    v13 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: Entered with handle 0x%x", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_wmm_delts", a2);
  mutex_lock(a1 + 1832);
  v14 = a1 + 1816;
  do
  {
    v14 = *(_QWORD *)v14;
    if ( v14 == a1 + 1816 )
    {
      mutex_unlock(a1 + 1832);
      goto LABEL_14;
    }
  }
  while ( *(_DWORD *)(v14 + 16) != a2 );
  mutex_unlock(a1 + 1832);
  if ( !v14 )
  {
LABEL_14:
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: tid already freed for handle 0x%x",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_wmm_delts",
      a2);
    return 13;
  }
  v23 = *(_DWORD *)(v14 + 32);
  v24 = *(_DWORD *)(v14 + 20);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: found handle 0x%x, flow %d, AC %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "hdd_wmm_delts",
    a2,
    v24,
    v23);
  v25 = sme_qos_release_req(v13, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), v24);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: SME flow %d released, SME status %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "hdd_wmm_delts",
    v24,
    (unsigned int)v25);
  if ( v25 > 102 )
  {
    if ( v25 == 103 )
    {
      v43 = 14;
    }
    else
    {
      if ( v25 != 104 )
        goto LABEL_18;
      v43 = 16;
    }
    goto LABEL_26;
  }
  if ( v25 == 100 )
  {
    if ( v23 >= 4 )
      goto LABEL_40;
    *(_WORD *)(a1 + 280LL * v23 + 1885) = 0;
    v44 = *(_DWORD *)(v14 + 32);
    if ( v44 >= 5 )
      goto LABEL_40;
    v45 = *(_QWORD *)(v14 + 24);
    v46 = v45 + 280LL * v44;
    if ( *(_BYTE *)(v46 + 1887) == 1 )
    {
      if ( (unsigned int)sme_disable_uapsd_for_ac(v44, *(unsigned __int8 *)(*(_QWORD *)(v45 + 52824) + 8LL)) )
      {
        v55 = "%s: Failed to disable U-APSD for AC=%d";
        v56 = 2;
      }
      else
      {
        v55 = "%s: Disabled UAPSD in TL for AC=%d";
        v56 = 8;
        *(_BYTE *)(v46 + 1887) = 0;
      }
      qdf_trace_msg(0x33u, v56, v55, v47, v48, v49, v50, v51, v52, v53, v54, "hdd_wmm_disable_tl_uapsd", v44);
    }
    v57 = *(_DWORD *)(v14 + 32);
    if ( v57 >= 5 )
    {
LABEL_40:
      __break(0x5512u);
      JUMPOUT(0x36FCF4);
    }
    v58 = *(_QWORD *)(v14 + 24);
    v59 = v58 + 280LL * v57 + 1880;
    *(_QWORD *)(v58 + 280LL * v57 + 1980) = 0;
    if ( *(_BYTE *)(v14 + 76) != 1 )
      goto LABEL_39;
    *(_BYTE *)(v14 + 76) = 0;
    if ( (unsigned int)qdf_mc_timer_stop(v58 + 280LL * v57 + 1992) )
    {
      v60 = "%s: Failed to stop inactivity timer";
    }
    else
    {
      if ( !(unsigned int)qdf_mc_timer_destroy(v59 + 112) )
      {
LABEL_39:
        hdd_wmm_free_context(v14, v34, v35, v36, v37, v38, v39, v40, v41);
        return 13;
      }
      v60 = "%s: Failed to destroy inactivity timer:Timer started";
    }
    qdf_trace_msg(0x33u, 2u, v60, v34, v35, v36, v37, v38, v39, v40, v41, "hdd_wmm_disable_inactivity_timer");
    goto LABEL_39;
  }
  if ( v25 != 101 )
LABEL_18:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: unexpected SME Status=%d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "hdd_wmm_delts",
      (unsigned int)v25);
  v43 = 15;
LABEL_26:
  mutex_lock(a1 + 1832);
  if ( *(_DWORD *)(v14 + 72) == 1464683864 )
    *(_DWORD *)(v14 + 36) = v43;
  mutex_unlock(a1 + 1832);
  return v43;
}
