__int64 __fastcall ce_init(__int64 a1, unsigned int a2, _DWORD *a3)
{
  __int64 v3; // x26
  __int64 v5; // x28
  __int64 v8; // x19
  int v9; // w27
  __int64 v10; // x0
  unsigned int v11; // w0
  int v12; // w25
  unsigned int v13; // w0
  unsigned int v14; // w8
  __int64 v15; // x0
  __int64 v16; // x23
  __int64 v17; // x23
  __int64 v18; // x23
  int v19; // w22
  char *v20; // x8
  int v21; // w9
  _DWORD *v22; // x10
  unsigned __int64 v23; // x8
  unsigned int v24; // w24
  __int64 v25; // x0
  __int64 v26; // x23
  __int64 v27; // x0
  _DWORD *v28; // x8
  unsigned int v29; // w23
  __int64 v30; // x0
  __int64 v31; // x24
  _DWORD *v32; // x8
  unsigned int v33; // w8
  __int64 v34; // x0
  _DWORD *v35; // x8
  __int64 v37; // x8
  __int64 v38; // x10
  int v39; // w9
  __int64 v40; // x11
  __int64 v41; // x8
  __int64 v42; // x23
  unsigned int v43; // w25
  unsigned int v44; // w24
  __int64 v45; // x8
  int v46; // w0
  unsigned int v47; // w24
  _DWORD *v48; // x8
  int v49; // w13
  int v50; // w9
  __int64 v51; // x8
  int v52; // w25
  unsigned int v53; // w27
  unsigned int v54; // w23
  __int64 v55; // x8
  int v56; // w0
  char v57[8]; // [xsp+18h] [xbp-B8h] BYREF
  __int64 v58; // [xsp+20h] [xbp-B0h]
  __int64 v59; // [xsp+28h] [xbp-A8h]
  __int64 v60; // [xsp+30h] [xbp-A0h]
  __int64 v61; // [xsp+38h] [xbp-98h]
  __int64 v62; // [xsp+40h] [xbp-90h]
  __int16 v63; // [xsp+48h] [xbp-88h]
  char v64[8]; // [xsp+50h] [xbp-80h] BYREF
  __int64 v65; // [xsp+58h] [xbp-78h]
  __int64 v66; // [xsp+60h] [xbp-70h]
  __int64 v67; // [xsp+68h] [xbp-68h]
  __int64 v68; // [xsp+70h] [xbp-60h]
  __int64 v69; // [xsp+78h] [xbp-58h]
  __int16 v70; // [xsp+80h] [xbp-50h]
  char s[8]; // [xsp+88h] [xbp-48h] BYREF
  __int64 v72; // [xsp+90h] [xbp-40h]
  __int64 v73; // [xsp+98h] [xbp-38h]
  __int64 v74; // [xsp+A0h] [xbp-30h]
  __int64 v75; // [xsp+A8h] [xbp-28h]
  __int64 v76; // [xsp+B0h] [xbp-20h]
  __int16 v77; // [xsp+B8h] [xbp-18h]
  __int64 v78; // [xsp+C0h] [xbp-10h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 0xC )
    goto LABEL_89;
  v3 = a1 + 480;
  v5 = *(_QWORD *)(a1 + 480 + 8LL * a2);
  v8 = v5;
  v9 = *(_DWORD *)(*(_QWORD *)(a1 + 624) + 256LL)
     + (*(_DWORD *)(*(_QWORD *)(a1 + 624) + 260LL) - *(_DWORD *)(*(_QWORD *)(a1 + 624) + 256LL)) * a2;
  if ( !v5 )
  {
    v10 = _qdf_mem_malloc(320, "ce_init", 2909);
    v8 = v10;
    if ( !v10 )
      goto LABEL_68;
    *(_DWORD *)(v10 + 168) = 0;
    *(_QWORD *)(v10 + 176) = 0;
    *(_DWORD *)(v10 + 8) = a2;
    *(_DWORD *)(v10 + 16) = v9;
    *(_DWORD *)(v10 + 20) = 2;
    *(_DWORD *)(v10 + 12) = *a3;
  }
  *(_QWORD *)v8 = a1;
  *(_QWORD *)(v8 + 288) = ce_engine_service_reg;
  *(_DWORD *)(v8 + 160) = 0;
  if ( !a3 )
    goto LABEL_68;
  if ( !*(_DWORD *)(v8 + 132) )
    *(_DWORD *)(v8 + 132) = a3[3];
  ((void (__fastcall *)(__int64, _QWORD, _QWORD))ce_init_ce_desc_event_log)(a1, a2, (unsigned int)(a3[4] + a3[2]));
  if ( a3[2] && (v11 = roundup_pwr2(), !*(_QWORD *)(v8 + 136)) )
  {
    v24 = v11;
    v25 = ce_alloc_ring_state(v8, 0, v11);
    *(_QWORD *)(v8 + 136) = v25;
    if ( !v25 )
    {
      qdf_trace_msg(61, 2, "%s: src ring has no mem", "ce_init");
      if ( v5 )
      {
LABEL_67:
        v8 = 0;
        goto LABEL_68;
      }
      goto LABEL_79;
    }
    v26 = v25;
    v27 = _qdf_mem_malloc(8LL * v24 + 8, "ce_init", 2979);
    *(_QWORD *)(v26 + 56) = v27;
    if ( !v27 )
      goto LABEL_66;
    *(_QWORD *)(v26 + 64) = (v27 + 7) & 0xFFFFFFFFFFFFFFF8LL;
    v28 = *(_DWORD **)(*(_QWORD *)(a1 + 30696) + 8LL);
    if ( *(v28 - 1) != 1414724131 )
      __break(0x8228u);
    if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _DWORD *))v28)(a1, 0, a2, v26, a3) & 0x80000000) != 0 )
      goto LABEL_66;
    if ( *(_QWORD *)(v26 + 8) )
      qdf_trace_msg(
        61,
        2,
        "%s: ce %d, %s, initial sw_index = %d, initial write_index =%d",
        "ce_ring_test_initial_indexes",
        a2,
        "src_ring",
        *(_DWORD *)(v26 + 8),
        *(_DWORD *)(v26 + 12));
    if ( (*(_BYTE *)(v8 + 12) & 0x10) != 0 )
    {
      *(_QWORD *)(v8 + 256) = ce_poll_timeout;
      *(_QWORD *)(v8 + 264) = v8;
      init_timer_key(v8 + 216, _os_timer_shim, 0, 0, 0);
      if ( (*(_BYTE *)(v8 + 12) & 0x10) != 0 )
        *(_BYTE *)(v8 + 212) = 1;
      qdf_timer_mod(v8 + 216);
    }
    v12 = 1;
  }
  else
  {
    v12 = 0;
  }
  if ( !a3[4] )
    goto LABEL_13;
  v13 = roundup_pwr2();
  if ( *(_QWORD *)(v8 + 144) )
    goto LABEL_13;
  v29 = v13;
  v30 = ce_alloc_ring_state(v8, 1, v13);
  *(_QWORD *)(v8 + 144) = v30;
  if ( !v30 )
  {
    qdf_trace_msg(61, 2, "%s: dest ring has no mem", "ce_init");
LABEL_66:
    ce_fini(v8);
    goto LABEL_67;
  }
  v31 = v30;
  v32 = *(_DWORD **)(*(_QWORD *)(a1 + 30696) + 8LL);
  if ( *(v32 - 1) != 1414724131 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _DWORD *))v32)(a1, 1, a2, v30, a3) & 0x80000000) != 0 )
    goto LABEL_66;
  if ( *(_QWORD *)(v31 + 8) )
    qdf_trace_msg(
      61,
      2,
      "%s: ce %d, %s, initial sw_index = %d, initial write_index =%d",
      "ce_ring_test_initial_indexes",
      a2,
      "dest_ring",
      *(_DWORD *)(v31 + 8),
      *(_DWORD *)(v31 + 12));
  v33 = *(_DWORD *)(hif_get_target_info_handle(*(_QWORD *)v8) + 4);
  if ( v33 <= 0x2B && ((1LL << v33) & 0xFBFFFB00000LL) != 0 )
  {
    v34 = ce_alloc_ring_state(v8, 2, v29);
    *(_QWORD *)(v8 + 152) = v34;
    if ( v34 )
    {
      v35 = *(_DWORD **)(*(_QWORD *)(a1 + 30696) + 8LL);
      if ( *(v35 - 1) != 1414724131 )
        __break(0x8228u);
      if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _DWORD *))v35)(a1, 2, a2, v34, a3) & 0x80000000) != 0 )
        goto LABEL_66;
      goto LABEL_59;
    }
    _qdf_mem_free(*(_QWORD *)(v8 + 144));
    if ( v12 )
    {
      _qdf_mem_free(*(_QWORD *)(v8 + 136));
      *(_QWORD *)(v8 + 136) = 0;
    }
    if ( v5 )
      goto LABEL_67;
    *(_QWORD *)(v3 + 8LL * a2) = 0;
LABEL_79:
    _qdf_mem_free(v8);
    goto LABEL_67;
  }
LABEL_59:
  if ( (*(_BYTE *)(v8 + 12) & 0x10) != 0 )
  {
    *(_QWORD *)(v8 + 256) = ce_poll_timeout;
    *(_QWORD *)(v8 + 264) = v8;
    init_timer_key(v8 + 216, _os_timer_shim, 0, 0, 0);
    if ( (*(_BYTE *)(v8 + 12) & 0x10) != 0 )
      *(_BYTE *)(v8 + 212) = 1;
    qdf_timer_mod(v8 + 216);
  }
LABEL_13:
  v14 = *(_DWORD *)(hif_get_target_info_handle(a1) + 4);
  if ( v14 > 0x2B || ((1LL << v14) & 0xFBFFFB00000LL) == 0 )
  {
    if ( (hif_target_sleep_state_adjust(a1, 0, 1) & 0x80000000) != 0 )
      goto LABEL_66;
    v37 = *(_QWORD *)(a1 + 624);
    v38 = *(_QWORD *)(a1 + 40);
    v39 = *(unsigned __int8 *)(a1 + 31089);
    *(_QWORD *)s = 0;
    v40 = (unsigned int)(*(_DWORD *)(v37 + 148) + v9);
    v41 = *(_QWORD *)(a1 + 30720);
    v42 = v38 + v40;
    if ( v39 != 1 )
      goto LABEL_80;
    v43 = v42 - v41;
    if ( (unsigned int)(v42 - v41) >> 19 )
    {
      pld_lock_reg_window(*(_QWORD *)(a1 + 30760), s);
      v44 = (v43 >> 19) & 0x3F | 0x40000000;
      writel_0(v44, *(_QWORD *)(a1 + 30720) + 12920LL);
      v45 = *(_QWORD *)(a1 + 30720);
      *(_DWORD *)(a1 + 31092) = (v43 >> 19) & 0x3F;
      v46 = readl_0(v45 + 12920);
      if ( v46 != v44 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v44,
          v46,
          12920);
      v47 = readl_0(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v43 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), s);
    }
    else
    {
LABEL_80:
      v47 = readl_0(v38 + v40);
    }
    v48 = *(_DWORD **)(a1 + 624);
    *(_QWORD *)s = 0;
    v49 = v48[43];
    v50 = v48[38] | v48[39] | v48[40] | v48[41] | v48[42];
    v51 = *(_QWORD *)(a1 + 30720);
    v52 = v50 | v49;
    if ( *(_BYTE *)(a1 + 31089) == 1 && (v53 = v42 - v51, (unsigned int)(v42 - v51) >> 19) )
    {
      pld_lock_reg_window(*(_QWORD *)(a1 + 30760), s);
      v54 = (v53 >> 19) & 0x3F | 0x40000000;
      writel_0(v54, *(_QWORD *)(a1 + 30720) + 12920LL);
      v55 = *(_QWORD *)(a1 + 30720);
      *(_DWORD *)(a1 + 31092) = (v53 >> 19) & 0x3F;
      v56 = readl_0(v55 + 12920);
      if ( v56 != v54 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v54,
          v56,
          12920);
      writel_0(v52 | v47, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v53 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), s);
    }
    else
    {
      writel_0(v52 | v47, v42);
    }
    if ( (hif_target_sleep_state_adjust(a1, 1, 0) & 0x80000000) != 0 )
      goto LABEL_66;
  }
  *(_QWORD *)(v8 + 56) = ce_oom_recovery;
  *(_QWORD *)(v8 + 64) = v8;
  *(_QWORD *)(v8 + 24) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v8 + 32) = v8 + 32;
  *(_QWORD *)(v8 + 40) = v8 + 32;
  *(_QWORD *)s = 0;
  *(_DWORD *)v64 = 0;
  v15 = *(_QWORD *)v8;
  *(_QWORD *)(v8 + 48) = _qdf_defer_func;
  hif_select_service_to_pipe_map(v15, s, (int *)v64);
  if ( *(_DWORD *)v64 >= 0xCu )
  {
    v21 = *(_DWORD *)(v8 + 8);
    v22 = (_DWORD *)(*(_QWORD *)s + 4LL);
    v23 = *(unsigned int *)v64 / 0xCuLL;
    do
    {
      if ( v22[1] == v21 && (unsigned int)(*(v22 - 1) - 768) <= 2 )
      {
        if ( *v22 == 1 )
          *(_BYTE *)(v8 + 273) = 1;
        else
          *(_BYTE *)(v8 + 272) = 1;
      }
      --v23;
      v22 += 3;
    }
    while ( v23 );
  }
  *(_QWORD *)(v3 + 8LL * a2) = v8;
  v77 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  *(_QWORD *)s = 0;
  v72 = 0;
  v70 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  *(_QWORD *)v64 = 0;
  v65 = 0;
  v63 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  *(_QWORD *)v57 = 0;
  v58 = 0;
  snprintf(s, 0x32u, "%s%d", "ce_", a2);
  ((void (__fastcall *)(char *, __int64, __int64))qdf_ssr_driver_dump_register_region)(s, v8, 320);
  v16 = *(_QWORD *)(v8 + 152);
  if ( v16 )
  {
    snprintf(v64, 0x32u, "%s%s", s, "_status_ring");
    ((void (__fastcall *)(char *, __int64, __int64))qdf_ssr_driver_dump_register_region)(v64, v16, 136);
    snprintf(v57, 0x32u, "%s%s", v64, "_ctx");
    ((void (__fastcall *)(char *, _QWORD, __int64))qdf_ssr_driver_dump_register_region)(v57, *(_QWORD *)(v16 + 80), 312);
  }
  v17 = *(_QWORD *)(v8 + 144);
  if ( v17 )
  {
    snprintf(v64, 0x32u, "%s%s", s, "_dest_ring");
    ((void (__fastcall *)(char *, __int64, __int64))qdf_ssr_driver_dump_register_region)(v64, v17, 136);
    snprintf(v57, 0x32u, "%s%s", v64, "_ctx");
    ((void (__fastcall *)(char *, _QWORD, __int64))qdf_ssr_driver_dump_register_region)(v57, *(_QWORD *)(v17 + 80), 312);
  }
  v18 = *(_QWORD *)(v8 + 136);
  if ( v18 )
  {
    snprintf(v64, 0x32u, "%s%s", s, "_src_ring");
    ((void (__fastcall *)(char *, __int64, __int64))qdf_ssr_driver_dump_register_region)(v64, v18, 136);
    snprintf(v57, 0x32u, "%s%s", v64, "_ctx");
    ((void (__fastcall *)(char *, _QWORD, __int64))qdf_ssr_driver_dump_register_region)(v57, *(_QWORD *)(v18 + 80), 312);
  }
  if ( ((1LL << a2) & 0x8E) == 0 )
  {
    *(_BYTE *)(a1 + a2 + 2812) = 0;
LABEL_34:
    *(_BYTE *)(a1 + a2 + 2824) = 0;
    goto LABEL_68;
  }
  v19 = a3[2];
  qdf_trace_msg(
    61,
    8,
    "%s: get ce debug buffer ce_id %u, only_ce2/ce3=0x%lx, idx=%u",
    "hif_ce_debug_history_buf_get",
    a2,
    142,
    *(unsigned __int8 *)(a1 + a2 + 2800));
  if ( *(unsigned __int8 *)(a1 + a2 + 2800) > 4uLL )
LABEL_89:
    __break(0x5512u);
  v20 = (char *)&hif_ce_desc_history_buff + 43008 * *(unsigned __int8 *)(a1 + a2 + 2800);
  hif_ce_desc_history[a2] = v20;
  *(_QWORD *)(a1 + 8LL * a2 + 3616) = v20;
  *(_BYTE *)(a1 + a2 + 2812) = 1;
  if ( !v19 )
    goto LABEL_34;
LABEL_68:
  _ReadStatusReg(SP_EL0);
  return v8;
}
