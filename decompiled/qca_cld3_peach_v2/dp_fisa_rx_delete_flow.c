__int64 __fastcall dp_fisa_rx_delete_flow(__int64 *a1, __int64 a2, unsigned int a3, unsigned __int8 a4)
{
  __int64 v8; // x9
  __int64 v9; // x24
  __int64 v10; // x20
  int v11; // w8
  __int64 v12; // x27
  __int64 *v13; // x25
  unsigned __int64 StatusReg; // x8
  __int16 v15; // w9
  __int64 v16; // x0
  int v17; // w8
  __int64 v18; // x8
  __int64 v19; // x24
  __int64 v20; // x9
  __int64 v21; // x9
  __int64 v22; // x28
  char v23; // w8
  int v24; // w8
  __int64 v25; // x9
  __int64 v26; // x10
  __int64 v27; // x8
  __int64 v28; // x9
  char v29; // w11
  __int64 v30; // x1
  __int64 v31; // x11
  __int64 v32; // x9
  __int64 v33; // x11
  __int64 v34; // x0
  void *v35; // x0
  __int64 v36; // x1
  int v37; // w8
  int v38; // w9
  int v39; // w10
  int v40; // w10
  unsigned __int64 v41; // t2
  char v42; // w9
  char v43; // w8
  __int64 result; // x0
  __int64 v45; // x10
  int v46; // w9
  __int64 v47; // x21
  unsigned int v48; // w20
  char v49; // w8
  int v50; // w9
  __int64 *v51; // x8
  __int64 v52; // x9
  unsigned int v53; // w25
  __int64 v54; // x26
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned __int64 v77; // x9
  __int64 v78; // [xsp+10h] [xbp-240h] BYREF
  __int64 v79; // [xsp+18h] [xbp-238h]
  __int64 v80; // [xsp+20h] [xbp-230h]
  __int64 v81; // [xsp+28h] [xbp-228h]
  __int64 v82; // [xsp+30h] [xbp-220h]
  __int64 v83; // [xsp+38h] [xbp-218h]
  _QWORD v84[32]; // [xsp+40h] [xbp-210h] BYREF
  unsigned __int64 v85; // [xsp+140h] [xbp-110h] BYREF
  __int64 v86; // [xsp+148h] [xbp-108h]
  __int128 v87; // [xsp+150h] [xbp-100h]
  _DWORD v88[6]; // [xsp+160h] [xbp-F0h] BYREF
  __int64 v89; // [xsp+178h] [xbp-D8h]
  __int64 v90; // [xsp+180h] [xbp-D0h]
  __int64 v91; // [xsp+188h] [xbp-C8h]
  __int64 v92; // [xsp+190h] [xbp-C0h]
  __int64 v93; // [xsp+198h] [xbp-B8h]
  __int64 v94; // [xsp+1A0h] [xbp-B0h]
  __int64 v95; // [xsp+1A8h] [xbp-A8h]
  __int64 v96; // [xsp+1B0h] [xbp-A0h]
  __int64 v97; // [xsp+1B8h] [xbp-98h]
  __int64 v98; // [xsp+1C0h] [xbp-90h]
  __int64 v99; // [xsp+1C8h] [xbp-88h]
  __int64 v100; // [xsp+1D0h] [xbp-80h]
  __int64 v101; // [xsp+1D8h] [xbp-78h]
  __int64 v102; // [xsp+1E0h] [xbp-70h]
  __int64 v103; // [xsp+1E8h] [xbp-68h]
  __int64 v104; // [xsp+1F0h] [xbp-60h]
  __int64 v105; // [xsp+1F8h] [xbp-58h]
  __int64 v106; // [xsp+200h] [xbp-50h]
  __int64 v107; // [xsp+208h] [xbp-48h]
  __int64 v108; // [xsp+210h] [xbp-40h]
  __int64 v109; // [xsp+218h] [xbp-38h]
  __int64 v110; // [xsp+220h] [xbp-30h]
  __int64 v111; // [xsp+228h] [xbp-28h]
  __int64 v112; // [xsp+230h] [xbp-20h]
  __int64 v113; // [xsp+238h] [xbp-18h]
  __int64 v114; // [xsp+240h] [xbp-10h]

  v114 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *a1;
  v9 = a1[1];
  v82 = 0;
  v83 = 0;
  v10 = v8 + 336LL * a3;
  v11 = *((unsigned __int8 *)a1 + 608);
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  v12 = *(unsigned __int8 *)(v10 + 144);
  if ( v11 == 1 )
  {
    if ( (unsigned int)v12 >= 9 )
      goto LABEL_35;
    v13 = &a1[2 * v12];
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v13 + 55);
    }
    else
    {
      raw_spin_lock_bh(v13 + 55);
      v13[56] |= 1uLL;
    }
  }
  v15 = *(_WORD *)(v10 + 194);
  v16 = *(_QWORD *)(v10 + 152);
  *(_WORD *)(v10 + 62) = *(_WORD *)(v10 + 56);
  *(_WORD *)(v10 + 64) = v15;
  dp_rx_fisa_flush_flow(v16, v10);
  v17 = *(unsigned __int8 *)(v10 + 323);
  *(_WORD *)(v10 + 60) = 0;
  if ( v17 == 2 )
  {
    v18 = *(_QWORD *)(v9 + 2936);
    if ( v18 )
    {
      v19 = *(unsigned __int8 *)(v10 + 324);
      v20 = *(_QWORD *)(v18 + 6424);
      v113 = 0;
      v112 = 0;
      v111 = 0;
      v21 = v20 + (v19 << 7);
      v110 = 0;
      v109 = 0;
      v22 = v21 + 8;
      v108 = 0;
      v107 = 0;
      v105 = 0;
      v106 = 0;
      v103 = 0;
      v104 = 0;
      v101 = 0;
      v102 = 0;
      v99 = 0;
      v100 = 0;
      v23 = *(_BYTE *)(v18 + 148);
      v97 = 0;
      v98 = 0;
      v95 = 0;
      v96 = 0;
      v93 = 0;
      v94 = 0;
      v91 = 0;
      v92 = 0;
      v89 = 0;
      v90 = 0;
      memset(v88, 0, sizeof(v88));
      v86 = 0;
      v87 = 0u;
      v85 = 0;
      if ( (v23 & 8) != 0 )
      {
        v53 = *(_DWORD *)(v21 + 100);
        v54 = *(_QWORD *)(v21 + 80);
        dp_print_tuple_to_str(v21 + 28, &v85);
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: STC: c_state: [%u], c_flags: [%lu], Remove RX flow [%u] reason:[%u], tuple: %s",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "wlan_dp_stc_rx_flow_retire_ind",
          v53,
          v54,
          (unsigned int)v19,
          a4,
          &v85);
        if ( !*(_DWORD *)(v22 + 92) )
          goto LABEL_12;
      }
      else if ( !*(_DWORD *)(v21 + 100) )
      {
        goto LABEL_12;
      }
      if ( (*(_QWORD *)(v22 + 72) & 2) != 0 )
      {
        _X8 = (unsigned __int64 *)(v22 + 80);
        __asm { PRFM            #0x11, [X8] }
        do
          v77 = __ldxr(_X8);
        while ( __stxr(v77 | 2, _X8) );
      }
    }
  }
LABEL_12:
  qdf_mem_set((void *)v10, 0x150u, 0);
  if ( !a2 )
  {
    result = hal_rx_flow_delete_cmem_fse(*(_QWORD *)(a1[1] + 256), *((unsigned int *)a1 + 109), a3);
    v50 = *((unsigned __int8 *)a1 + 608);
    ++*((_DWORD *)a1 + 17);
    if ( v50 != 1 )
      goto LABEL_30;
LABEL_27:
    if ( (unsigned int)v12 < 9 )
    {
      v51 = &a1[2 * v12];
      v52 = v51[56];
      if ( (v52 & 1) != 0 )
      {
        v51[56] = v52 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v51 + 55);
      }
      else
      {
        result = raw_spin_unlock(v51 + 55);
      }
      goto LABEL_30;
    }
LABEL_35:
    __break(0x5512u);
  }
  v24 = *(_DWORD *)(a2 + 76);
  v25 = *(_QWORD *)(a2 + 64);
  v26 = a1[1];
  *(_DWORD *)(v10 + 16) = a3;
  *(_DWORD *)(v10 + 8) = v24;
  LOBYTE(v24) = *(_BYTE *)(v25 + 59);
  *(_QWORD *)(v10 + 152) = v25;
  *(_BYTE *)(v10 + 160) = v24;
  v27 = *(_QWORD *)(*(_QWORD *)(v25 + 88) + 32LL);
  *(_QWORD *)(v10 + 200) = v26;
  *(_QWORD *)(v10 + 168) = v27;
  v28 = *a1 + 336LL * a3;
  LODWORD(v26) = *((_DWORD *)a1 + 108) + 1;
  *(_OWORD *)&v88[1] = 0u;
  v29 = *(_DWORD *)(a2 + 84);
  *((_DWORD *)a1 + 108) = v26;
  *(_DWORD *)(v28 + 240) = v26;
  v88[3] = v26;
  v30 = *((unsigned int *)a1 + 109);
  LODWORD(v28) = *(_DWORD *)(a2 + 20);
  LODWORD(v26) = *(_DWORD *)(a2 + 24);
  BYTE1(v88[2]) = v29;
  v31 = *(_QWORD *)(a2 + 28);
  v85 = __PAIR64__(v26, v28);
  v32 = *(_QWORD *)(a2 + 40);
  LODWORD(v26) = *(_DWORD *)(a2 + 36);
  v86 = v31;
  v33 = a1[1];
  *(_QWORD *)((char *)&v87 + 4) = v32;
  LODWORD(v27) = *(_DWORD *)(a2 + 48);
  LODWORD(v32) = *(_DWORD *)(a2 + 52);
  LODWORD(v87) = v26;
  LOWORD(v26) = *(_WORD *)(a2 + 56);
  v34 = *(_QWORD *)(v33 + 256);
  HIDWORD(v87) = v27;
  v88[0] = v32;
  LOWORD(v88[1]) = v26;
  *(_DWORD *)(v10 + 236) = hal_rx_flow_setup_cmem_fse(v34, v30, a3, &v85);
  *(_BYTE *)(v10 + 40) = 1;
  *(_BYTE *)(v10 + 144) = *(_BYTE *)(a2 + 90);
  *(_DWORD *)(v10 + 244) = *(_DWORD *)(a2 + 84);
  v35 = qdf_mem_copy((void *)(v10 + 88), (const void *)(a2 + 16), 0x2Cu);
  v37 = *(unsigned __int8 *)(v10 + 128);
  v38 = *(_DWORD *)(v10 + 120);
  v39 = *(_DWORD *)(v10 + 124);
  LODWORD(v80) = *(_DWORD *)(v10 + 104);
  LODWORD(v83) = 0;
  HIDWORD(v41) = v39;
  LODWORD(v41) = v39;
  v40 = v41 >> 16;
  LODWORD(v78) = v38;
  if ( v37 == 17 )
    v42 = 0;
  else
    v42 = -22;
  if ( v37 == 6 )
    v43 = 1;
  else
    v43 = v42;
  LODWORD(v82) = v40;
  BYTE4(v82) = v43;
  *(_QWORD *)(v10 + 136) = v78 ^ v79 ^ v80 ^ v81 ^ v82 ^ 0x574C414E5F44505FLL;
  *(_BYTE *)(v10 + 42) = *(_BYTE *)(a2 + 88);
  *(_BYTE *)(v10 + 41) = *(_BYTE *)(a2 + 89);
  *(_WORD *)(v10 + 36) = *(_WORD *)(a2 + 72);
  __isb(0xFu);
  *(_QWORD *)(v10 + 272) = _ReadStatusReg(CNTVCT_EL0);
  result = sched_clock(v35, v36);
  *(_QWORD *)(v10 + 248) = result;
  v45 = a1[1];
  v46 = *((_DWORD *)a1 + 17) + 1;
  ++*((_DWORD *)a1 + 16);
  *((_DWORD *)a1 + 17) = v46;
  v47 = *(_QWORD *)(v45 + 2936);
  if ( v47 )
  {
    v48 = *(_DWORD *)(v10 + 16);
    v113 = 0;
    v112 = 0;
    v111 = 0;
    v110 = 0;
    v109 = 0;
    v108 = 0;
    v107 = 0;
    v105 = 0;
    v106 = 0;
    v103 = 0;
    v104 = 0;
    v101 = 0;
    v102 = 0;
    v99 = 0;
    v100 = 0;
    v85 = 0;
    v49 = *(_BYTE *)(v47 + 148);
    v97 = 0;
    v98 = 0;
    v95 = 0;
    v96 = 0;
    v93 = 0;
    v94 = 0;
    v91 = 0;
    v92 = 0;
    v89 = 0;
    v90 = 0;
    memset(v88, 0, sizeof(v88));
    v86 = 0;
    v87 = 0u;
    memset(v84, 0, sizeof(v84));
    if ( (v49 & 8) != 0 )
    {
      dp_print_tuple_to_str(&v78, &v85);
      dp_print_rx_flow_info_to_str(v48, v84);
      result = qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: STC: Add RX flow [%u] %s [%s]",
                 v63,
                 v64,
                 v65,
                 v66,
                 v67,
                 v68,
                 v69,
                 v70,
                 "wlan_dp_indicate_flow_add",
                 v48,
                 &v85,
                 v84);
    }
    if ( *(_DWORD *)(v47 + 152) <= 1u )
    {
      result = qdf_periodic_work_start(v47 + 16, *(_DWORD *)(v47 + 144));
      *(_DWORD *)(v47 + 152) = 2;
    }
  }
  if ( *((_BYTE *)a1 + 608) == 1 )
    goto LABEL_27;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
