__int64 __fastcall dp_srng_init_idx(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v17; // x8
  __int64 v18; // x23
  __int64 result; // x0
  __int64 v23; // x6
  int v24; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 (__fastcall *v42)(_QWORD); // x8
  unsigned int (__fastcall *v43)(_QWORD); // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  _DWORD *v52; // x8
  __int16 pointer_timer_threshold_rx; // w0
  __int64 v54; // x8
  __int64 v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // [xsp+8h] [xbp-68h]
  _QWORD v65[2]; // [xsp+10h] [xbp-60h] BYREF
  __int64 v66; // [xsp+20h] [xbp-50h]
  __int64 v67; // [xsp+28h] [xbp-48h]
  __int64 v68; // [xsp+30h] [xbp-40h]
  __int64 v69; // [xsp+38h] [xbp-38h]
  __int64 v70; // [xsp+40h] [xbp-30h]
  __int64 v71; // [xsp+48h] [xbp-28h]
  __int64 v72; // [xsp+50h] [xbp-20h]
  __int64 v73; // [xsp+58h] [xbp-18h]
  __int64 v74; // [xsp+60h] [xbp-10h]
  __int64 v75; // [xsp+68h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)a2;
  v18 = *(_QWORD *)(a1 + 1128);
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65[1] = 0;
  v66 = 0;
  v65[0] = 0;
  if ( v17 )
  {
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: Ring type: %d, num:%d is already initialized",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "dp_srng_init_idx",
      a1,
      a3,
      a4);
    result = 0;
    goto LABEL_32;
  }
  qdf_mem_set(v65, 0x58u, 0);
  v23 = *(_QWORD *)(a2 + 16);
  v24 = *(_DWORD *)(a2 + 52);
  v65[0] = *(_QWORD *)(a2 + 32);
  LODWORD(v66) = v24;
  v33 = qdf_trace_msg(
          0x45u,
          5u,
          "%s: Ring type: %d, num:%d vaddr %pK paddr %pK entries %u",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "dp_srng_init_idx",
          a3,
          a4,
          v24,
          v64,
          v65[0],
          v23,
          v66,
          v67,
          v68,
          v69);
  if ( *(_BYTE *)(a1 + 17840) == 1 )
  {
    v42 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 200LL);
    if ( !v42 )
      goto LABEL_17;
    if ( *((_DWORD *)v42 - 1) != 1696218653 )
      __break(0x8228u);
    v33 = v42(v33);
    if ( (_DWORD)v33 == 4 )
    {
      if ( a3 && a3 != 15 )
      {
LABEL_18:
        dp_srng_msi_setup((_QWORD *)a1, a2, (__int64)v65, a3, a4);
        if ( is_dp_verbose_debug_enabled == 1 )
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: Using MSI for ring_type: %d, ring_num %d",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "dp_srng_init_idx",
            a3,
            a4);
        goto LABEL_25;
      }
    }
    else
    {
LABEL_17:
      if ( a3 != 17 )
        goto LABEL_18;
      if ( *(_BYTE *)(*(_QWORD *)(a1 + 40) + 817LL) == 1 )
      {
        v43 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 200LL);
        if ( v43 )
        {
          if ( *((_DWORD *)v43 - 1) != 1696218653 )
            __break(0x8228u);
          if ( !v43(v33) && (*(_BYTE *)(a1 + 20272) & 0x10) == 0 )
            goto LABEL_18;
        }
      }
    }
  }
  LODWORD(v68) = 0;
  v67 = 0;
  if ( is_dp_verbose_debug_enabled == 1 )
  {
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: Skipping MSI for ring_type: %d, ring_num %d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "dp_srng_init_idx",
      a3,
      a4);
    v52 = *(_DWORD **)(a1 + 1744);
    if ( !v52 )
      goto LABEL_25;
  }
  else
  {
    v52 = *(_DWORD **)(a1 + 1744);
    if ( !v52 )
      goto LABEL_25;
  }
  if ( *(v52 - 1) != -1171869274 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD))v52)(a1, a2, 0, a3, a4) )
    goto LABEL_31;
LABEL_25:
  dp_srng_configure_interrupt_thresholds(a1, v65, a3, a4);
  if ( !a3 )
  {
    pointer_timer_threshold_rx = wlan_cfg_get_pointer_timer_threshold_rx(*(_QWORD *)(a1 + 40));
    v54 = *(_QWORD *)(a1 + 40);
    WORD2(v74) = pointer_timer_threshold_rx;
    BYTE6(v74) = wlan_cfg_get_pointer_num_threshold_rx(v54);
  }
  if ( *(_BYTE *)(a2 + 44) )
    LODWORD(v70) = v70 | 0x40000;
  v55 = hal_srng_setup_idx(v18, a3, a4, a5, v65, 0, a6);
  result = 0;
  *(_QWORD *)a2 = v55;
  if ( !v55 )
  {
    dp_srng_free(a1, a2, v56, v57, v58, v59, v60, v61, v62, v63);
LABEL_31:
    result = 16;
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
