__int64 __fastcall wmi_unified_cmd_send_fl(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        const char *a5,
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
  int v20; // w26
  __int64 (*v21)(void); // x8
  unsigned __int16 v22; // w0
  __int64 result; // x0
  __int64 v24; // x8
  unsigned __int16 v25; // w27
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x0
  __int64 v35; // x24
  unsigned __int16 v36; // w8
  __int64 v37; // x1
  unsigned __int16 v38; // w24
  _DWORD *v39; // x8
  int v40; // w8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned __int64 StatusReg; // x8
  int v50; // w9
  unsigned int v51; // w9
  int v52; // w11
  unsigned int v53; // w11
  __int64 v54; // x9
  unsigned int v55; // w23
  __int64 v56; // x10
  unsigned __int64 v57; // x8
  unsigned __int64 v58; // x12
  unsigned int v59; // w22
  unsigned __int64 v60; // kr00_8
  unsigned __int64 v61; // x14
  __int64 v62; // x8
  __int64 v63; // x14
  unsigned __int64 v64; // x26
  unsigned __int64 v65; // x25
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 v98; // x0
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  unsigned int v115; // w19
  __int64 v116; // x4
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  const char *v125; // x6
  __int64 v126; // x9
  int v127; // w8
  __int64 v128; // x0
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 (__fastcall *v137)(_QWORD); // x8
  unsigned int *v138; // x10
  __int64 v139; // x8
  unsigned int v140; // w11
  __int64 v141; // x9
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  __int64 v150; // x4
  unsigned int v151; // w19
  unsigned int v158; // w9
  unsigned int v161; // w10
  unsigned int v164; // w11
  unsigned int v167; // w10
  unsigned int v168; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v169; // [xsp+8h] [xbp-8h]

  v169 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = *(_DWORD *)(a1 + 708);
  if ( v20 )
  {
    v21 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3504LL);
    if ( *((_DWORD *)v21 - 1) != -1007878647 )
      __break(0x8228u);
    v22 = v21();
  }
  else if ( *(_DWORD *)(a1 + 696) )
  {
    v22 = 0;
    if ( a4 != 69634 && a4 != 77829 )
    {
      qdf_trace_msg(0x31u, 2u, "Target is suspended (via %s:%u)", a7, a8, a9, a10, a11, a12, a13, a14, a5, a6);
      result = 8;
      goto LABEL_70;
    }
  }
  else
  {
    v22 = 0;
  }
  if ( *(_BYTE *)(a1 + 737) == 1 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s:%d, WMI stop in progress, wmi_handle:%pK",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a5,
      a6,
      a1);
    result = 4;
    goto LABEL_70;
  }
  if ( *(_DWORD *)(a1 + 716) )
  {
    qdf_trace_msg(0x31u, 2u, "wow enable ack already failed(via %s:%u)", a7, a8, a9, a10, a11, a12, a13, a14, a5, a6);
    result = 4;
    goto LABEL_70;
  }
  if ( !*(_DWORD *)(a1 + 724) )
  {
    v37 = *(_QWORD *)(a2 + 224);
    v38 = v22;
    v39 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 4000LL);
    if ( *(v39 - 1) != 409496415 )
      __break(0x8228u);
    v40 = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, _QWORD))v39)(0, v37, a3, a4);
    v22 = v38;
    if ( v40 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s:%d, Invalid WMI Param Buffer for Cmd:%d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        a5,
        a6,
        a4);
      result = 4;
      goto LABEL_70;
    }
  }
  v24 = *(_QWORD *)(a2 + 40);
  v25 = v22;
  if ( v24 )
    *(_QWORD *)(a2 + 40) = v24 - 4;
  if ( !skb_push(a2, 4) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s:%d, Failed to send cmd %x, no memory",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      a5,
      a6,
      a4);
    result = 2;
    goto LABEL_70;
  }
  qdf_mem_set(*(void **)(a2 + 224), 4u, 0);
  **(_DWORD **)(a2 + 224) = a4 & 0xFFFFFF | (*(unsigned __int8 *)(*(_QWORD *)(a2 + 224) + 3LL) << 24);
  _X8 = (unsigned int *)(a1 + 24);
  __asm { PRFM            #0x11, [X8] }
  do
    v158 = __ldxr(_X8);
  while ( __stxr(v158 + 1, _X8) );
  if ( *(_DWORD *)(a1 + 24) >= (int)*(unsigned __int16 *)(a1 + 768) )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 664);
    }
    else
    {
      raw_spin_lock_bh(a1 + 664);
      *(_QWORD *)(a1 + 672) |= 1uLL;
    }
    v50 = **(_DWORD **)(a1 + 424);
    if ( v50 )
      v51 = v50 - 1;
    else
      v51 = *(_DWORD *)(a1 + 432);
    v52 = **(_DWORD **)(a1 + 456);
    if ( v52 )
      v53 = v52 - 1;
    else
      v53 = *(_DWORD *)(a1 + 464);
    v54 = *(_QWORD *)(a1 + 408) + 32LL * (v51 % *(_DWORD *)(a1 + 432));
    v55 = *(_DWORD *)v54;
    v56 = *(_QWORD *)(a1 + 440) + 32LL * (v53 % *(_DWORD *)(a1 + 464));
    v57 = *(_QWORD *)(v54 + 24);
    v58 = *(_QWORD *)(v56 + 24);
    v59 = *(_DWORD *)v56;
    v60 = 10 * v57;
    _CF = 10 * v57 >= v57;
    v61 = v57 / 0xC0;
    v62 = *(_QWORD *)(a1 + 672);
    v63 = 10 * v61;
    if ( _CF )
      v64 = v60 / 0xC0;
    else
      v64 = v63;
    if ( 10 * v58 < v58 )
      v65 = 10 * (v58 / 0xC0);
    else
      v65 = 10 * v58 / 0xC0;
    if ( (v62 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 672) = v62 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 664);
    }
    else
    {
      raw_spin_unlock(a1 + 664);
    }
    qdf_trace_msg(
      0x31u,
      2u,
      "Last wmi command Time (s) = % 8lld.%06lld ",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v64 / 0xF4240,
      v64 % 0xF4240);
    qdf_trace_msg(0x31u, 2u, "Last wmi Cmd_Id = (0x%06x) ", v74, v75, v76, v77, v78, v79, v80, v81, v55);
    qdf_trace_msg(
      0x31u,
      2u,
      "Last wmi command tx completion Time (s) = % 8lld.%06lld",
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v65 / 0xF4240,
      v65 % 0xF4240);
    qdf_trace_msg(
      0x31u,
      2u,
      "Last wmi command tx completion Cmd_Id = (0x%06x) ",
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v59);
    v98 = *(_QWORD *)(a1 + 64);
    v168 = 0;
    htc_get_control_endpoint_tx_host_credits(v98, &v168);
    qdf_trace_msg(0x31u, 2u, "hostcredits = %d", v99, v100, v101, v102, v103, v104, v105, v106, v168);
    htc_dump_counter_info(*(_QWORD *)(a1 + 64));
    _X8 = (unsigned int *)(a1 + 24);
    __asm { PRFM            #0x11, [X8] }
    do
      v161 = __ldxr(_X8);
    while ( __stxr(v161 - 1, _X8) );
    qdf_trace_msg(
      0x31u,
      2u,
      "%s:%d, MAX %d WMI Pending cmds reached",
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      a5,
      a6,
      *(unsigned __int16 *)(a1 + 768));
    v115 = *(_DWORD *)(a1 + 28);
    v116 = (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD))htc_get_tx_queue_depth)(*(_QWORD *)(a1 + 64), v115);
    if ( *(_DWORD *)(a1 + 724) )
      v125 = "WMI_NON_TLV_TARGET";
    else
      v125 = "WMI_TLV_TARGET";
    qdf_trace_msg(
      0x31u,
      2u,
      "Endpoint ID = %d, Tx Queue Depth = %d, soc_id = %u, target type = %s",
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      v115,
      v116,
      *(unsigned int *)(*(_QWORD *)(a1 + 760) + 7792LL),
      v125);
    htc_ce_tasklet_debug_dump(*(__int64 **)(a1 + 64));
    _qdf_trigger_self_recovery();
    result = 8;
    goto LABEL_70;
  }
  v34 = _qdf_mem_malloc(0x70u, a5, a6);
  if ( !v34 )
  {
    _X8 = (unsigned int *)(a1 + 24);
    __asm { PRFM            #0x11, [X8] }
    do
      v167 = __ldxr(_X8);
    while ( __stxr(v167 - 1, _X8) );
    result = 2;
    goto LABEL_70;
  }
  v35 = v34;
  if ( !v20 )
  {
    if ( (int)a4 <= 77827 )
    {
      if ( a4 != 69633 )
      {
        v36 = 4098;
LABEL_57:
        if ( a4 == (v36 | 0x10000) )
          v25 = 16;
        goto LABEL_60;
      }
    }
    else if ( a4 != 77828 && a4 != 77834 )
    {
      v36 = 12293;
      goto LABEL_57;
    }
    v25 = 15;
  }
LABEL_60:
  *(_QWORD *)(v34 + 16) = 0;
  v126 = *(_QWORD *)(a2 + 224);
  *(_DWORD *)(v34 + 44) = a3 + 4;
  *(_QWORD *)(v34 + 32) = v126;
  v127 = *(_DWORD *)(a1 + 28);
  *(_WORD *)(v34 + 56) = v25;
  *(_DWORD *)(v34 + 72) = 0;
  *(_BYTE *)(v34 + 64) = 0;
  *(_DWORD *)(v34 + 48) = v127;
  *(_QWORD *)(v34 + 96) = a2;
  v128 = wmi_id_to_name(a4);
  qdf_trace_msg(0x31u, 8u, "Send cmd %s(0x%x) tag:%d", v129, v130, v131, v132, v133, v134, v135, v136, v128, a4, v25);
  if ( *(_BYTE *)(a1 + 680) == 1 )
  {
    qdf_spin_lock_bh_4(a1 + 664);
    v137 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 728) + 3528LL);
    if ( *((_DWORD *)v137 - 1) != -1896783675 )
      __break(0x8228u);
    if ( (v137(a4) & 1) == 0 )
    {
      v138 = *(unsigned int **)(a1 + 424);
      v139 = *(_QWORD *)(a2 + 224);
      v140 = *v138;
      v141 = *(unsigned int *)(*(_QWORD *)(a1 + 760) + 7848LL);
      if ( wmi_cmd_log_max_entry <= *v138 )
      {
        *v138 = 0;
        v140 = **(_DWORD **)(a1 + 424);
      }
      *(_DWORD *)(*(_QWORD *)(a1 + 408) + 32LL * v140) = a4;
      qdf_mem_copy(
        (void *)(*(_QWORD *)(a1 + 408) + 32LL * **(unsigned int **)(a1 + 424) + 4),
        (const void *)(v139 + v141),
        (unsigned int)wmi_record_max_length);
      __isb(0xFu);
      *(_QWORD *)(*(_QWORD *)(a1 + 408) + 32LL * (unsigned int)(**(_DWORD **)(a1 + 424))++ + 24) = _ReadStatusReg(CNTVCT_EL0);
      ++*(_DWORD *)(a1 + 416);
    }
    qdf_spin_unlock_bh_2(a1 + 664);
  }
  result = htc_send_pkt(*(_QWORD *)(a1 + 64), v35);
  if ( (_DWORD)result )
  {
    _X9 = (unsigned int *)(a1 + 24);
    __asm { PRFM            #0x11, [X9] }
    do
      v164 = __ldxr(_X9);
    while ( __stxr(v164 - 1, _X9) );
    v150 = a6;
    v151 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s:%d, htc_send_pkt failed, status:%d",
      v142,
      v143,
      v144,
      v145,
      v146,
      v147,
      v148,
      v149,
      a5,
      v150,
      (unsigned int)result);
    _qdf_mem_free(v35);
    result = v151;
  }
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
