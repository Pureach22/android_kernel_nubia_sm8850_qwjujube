__int64 __fastcall sde_encoder_phys_cmd_wait_for_commit_done(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x22
  unsigned int disp_op; // w20
  unsigned int v5; // w21
  unsigned int v6; // w0
  unsigned int *v7; // x8
  unsigned int v8; // w21
  __int64 v9; // x0
  unsigned int v10; // w1
  int v11; // w2
  __int64 v12; // x0
  __int64 v13; // x12
  __int64 v14; // x9
  __int64 v15; // x24
  __int64 v16; // x25
  __int64 v17; // x12
  __int64 v18; // x22
  int v19; // w4
  int v20; // w22
  __int64 v21; // x24
  int v22; // w4
  __int64 v23; // x8
  void (*v24)(void); // x8
  int v25; // w4
  int v26; // w8
  unsigned int v27; // w8
  int v28; // w9
  __int64 v29; // x0
  __int64 (*v30)(void); // x8
  char v31; // w20
  int v32; // w8
  int v33; // w22
  int v35; // w4
  __int64 v36; // x0
  __int64 v37; // x22
  __int64 v38; // x23
  unsigned int v39; // w0
  __int64 v40; // x24
  __int64 v41; // x9
  _DWORD *v42; // x8
  __int64 v43; // x0
  __int64 v44; // x9
  int v45; // w4
  int v46; // w4
  unsigned int v47; // w8
  unsigned int v54; // w10
  __int64 v55; // x0
  void (__fastcall *v56)(__int64, __int64, __int64); // x9
  __int64 v57; // x20
  __int64 v58; // x0
  int v59; // w4
  int v60; // w5
  int v61; // w6
  int v62; // w4
  __int64 v63; // x0
  __int64 (__fastcall *v64)(__int64, __int64); // x8
  unsigned int v65; // w0
  int v66; // w4
  char v67; // [xsp+0h] [xbp-70h]
  char v68; // [xsp+0h] [xbp-70h]
  _QWORD v69[4]; // [xsp+28h] [xbp-48h] BYREF
  _QWORD v70[2]; // [xsp+48h] [xbp-28h] BYREF
  __int64 v71; // [xsp+58h] [xbp-18h]
  int v72; // [xsp+60h] [xbp-10h]
  __int64 v73; // [xsp+68h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ktime_get(a1);
  if ( !a1 )
  {
    v5 = -22;
    goto LABEL_66;
  }
  v3 = v2;
  disp_op = sde_encoder_get_disp_op(*(_QWORD *)a1);
  if ( *(_QWORD *)a1 && *(_BYTE *)(*(_QWORD *)a1 + 4922LL) == 1 && *(_DWORD *)(a1 + 664) == 3 )
  {
    v5 = 0;
    goto LABEL_66;
  }
  if ( *(_DWORD *)(a1 + 664) == 3 )
  {
    v5 = 0;
    goto LABEL_59;
  }
  v5 = sde_encoder_phys_cmd_wait_for_wr_ptr(a1);
  if ( v5 != -110 )
  {
LABEL_46:
    if ( *(_BYTE *)(a1 + 2688) != 1 )
      goto LABEL_53;
    v26 = *(_DWORD *)(a1 + 664);
    v69[2] = 0;
    if ( v26 == 3 )
      goto LABEL_48;
    v27 = *(_DWORD *)(a1 + 2692);
    v28 = *(_DWORD *)(a1 + 992);
    if ( v27 <= 1 )
      v27 = 1;
    v69[0] = a1 + 2704;
    v69[1] = a1 + 2696;
    v69[3] = (int)(v27 * v28);
    v5 = sde_encoder_helper_wait_for_irq((__int64 **)a1, 9u, v69);
    if ( v5 )
    {
      sde_encoder_helper_report_irq_timeout((__int64 *)a1, 9);
      goto LABEL_53;
    }
    v36 = *(_QWORD *)a1;
    v37 = *(_QWORD *)(a1 + 496);
    v38 = *(_QWORD *)(a1 + 424);
    v72 = 0;
    v70[1] = 0;
    v71 = 0;
    v70[0] = 0;
    v39 = sde_encoder_get_disp_op(v36);
    if ( !v37 || !v38 )
    {
LABEL_53:
      v29 = *(_QWORD *)(a1 + 416);
      if ( !v29 )
        goto LABEL_59;
      if ( disp_op < 3 )
      {
        v30 = *(__int64 (**)(void))(v29 + 8LL * disp_op + 976);
        if ( v30 )
        {
          if ( *((_DWORD *)v30 - 1) != 1814623283 )
            __break(0x8228u);
          v31 = v30();
LABEL_60:
          v32 = *(_DWORD *)(a1 + 876);
          if ( v32 <= 1 && (!v32 || (v31 & 1) == 0) && (v5 || *(_DWORD *)(a1 + 2332) != 1) )
            goto LABEL_66;
          goto LABEL_63;
        }
LABEL_59:
        v31 = -114;
        goto LABEL_60;
      }
LABEL_132:
      __break(0x5512u);
      JUMPOUT(0x150B28);
    }
    v40 = v39;
    if ( *(_BYTE *)(a1 + 2288) == 1 )
    {
      if ( v39 >= 3 )
        goto LABEL_132;
      v41 = v38 + 8LL * v39;
      v42 = *(_DWORD **)(v41 + 560);
      if ( v42 && *(_QWORD *)(v41 + 632) )
      {
        v43 = v38;
        if ( *(v42 - 1) != 601581659 )
          __break(0x8228u);
LABEL_89:
        v5 = ((__int64 (__fastcall *)(__int64, _QWORD *))v42)(v43, v70);
        if ( !v5 )
        {
          if ( (_drm_debug & 4) != 0 )
          {
            if ( *(_QWORD *)a1 )
              v45 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
            else
              v45 = -1;
            _drm_dev_dbg(
              0,
              0,
              0,
              "enc%d intf%d pp:%d intf:%d rd_ptr %d wr_ptr %d\n",
              v45,
              *(_DWORD *)(a1 + 672) - 1,
              *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
              *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
              v71,
              HIDWORD(v71));
          }
          if ( *(_QWORD *)a1 )
            v62 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
          else
            v62 = -1;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_encoder_phys_cmd_poll_write_pointer_started",
            1009,
            4,
            v62,
            *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
            *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
            SHIDWORD(v71),
            239);
          if ( *(_BYTE *)(a1 + 2288) == 1 )
          {
            v63 = v38;
            v64 = *(__int64 (__fastcall **)(__int64, __int64))(v38 + 8 * v40 + 632);
            if ( *((_DWORD *)v64 - 1) != 185992269 )
              __break(0x8228u);
          }
          else
          {
            v63 = v37;
            v64 = *(__int64 (__fastcall **)(__int64, __int64))(v37 + 8 * v40 + 232);
            if ( *((_DWORD *)v64 - 1) != 1902169678 )
              __break(0x8228u);
          }
          v65 = v64(v63, 20000);
          v5 = v65;
          if ( v65 )
          {
            if ( *(_QWORD *)a1 )
              v66 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
            else
              v66 = -1;
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "_sde_encoder_phys_cmd_poll_write_pointer_started",
              1018,
              -1,
              v66,
              *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
              *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
              20000,
              v65);
            sde_dbg_dump(0, "_sde_encoder_phys_cmd_poll_write_pointer_started", 0xFFFFFF, "panic", 0);
          }
        }
        goto LABEL_53;
      }
    }
    else
    {
      if ( v39 > 2 )
        goto LABEL_132;
      v44 = v37 + 8LL * v39;
      v42 = *(_DWORD **)(v44 + 160);
      if ( v42 && *(_QWORD *)(v44 + 232) )
      {
        v43 = v37;
        if ( *(v42 - 1) != 684548186 )
          __break(0x8228u);
        goto LABEL_89;
      }
    }
LABEL_48:
    v5 = 0;
    goto LABEL_53;
  }
  v6 = sde_encoder_get_disp_op(*(_QWORD *)a1);
  v7 = *(unsigned int **)a1;
  v8 = v6;
  v69[0] = 0;
  v9 = v7[986];
  v10 = v7[989];
  v11 = v7[990];
  v70[0] = 0;
  sde_encoder_helper_get_jitter_bounds_ns(v9, v10, v11, v69, v70);
  if ( !v69[0] || !v70[0] )
  {
    printk(&unk_215FB5, "_sde_encoder_phys_cmd_needs_vsync_change");
    goto LABEL_23;
  }
  v12 = raw_spin_lock_irqsave(*(_QWORD *)(a1 + 824));
  v13 = *(_QWORD *)(a1 + 2776);
  if ( v13 == a1 + 2768 )
  {
LABEL_22:
    raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 824), v12);
LABEL_23:
    v20 = 0;
    goto LABEL_24;
  }
  v14 = v3;
  v15 = 0;
  while ( 1 )
  {
    v16 = v15;
    v15 = v13;
    if ( v16 )
    {
      v17 = *(_QWORD *)(v13 + 16);
      if ( v17 > v14 )
      {
        v18 = *(_QWORD *)(v16 + 16) - v17;
        if ( v18 < v69[0] || v18 > v70[0] )
          break;
      }
    }
    v13 = *(_QWORD *)(v15 + 8);
    if ( v13 == a1 + 2768 )
      goto LABEL_22;
  }
  raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 824), v12);
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *(_QWORD *)a1 )
      v19 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v19 = -1;
    _drm_dev_dbg(
      0,
      0,
      0,
      "enc%d intf%d time_diff:%llu, prev:%llu, cur:%llu, jitter:%llu/%llu\n",
      v19,
      *(_DWORD *)(a1 + 672) - 1,
      v18,
      *(_QWORD *)(v16 + 16),
      *(_QWORD *)(v15 + 16),
      v69[0],
      v70[0]);
  }
  if ( *(_QWORD *)a1 )
    v59 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
  else
    v59 = -1;
  v60 = v69[0] % 0x3E8uLL;
  v69[0] /= 0x3E8uLL;
  v61 = v70[0] % 0x3E8uLL;
  v70[0] /= 0x3E8uLL;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_encoder_phys_cmd_needs_vsync_change",
    2046,
    -1,
    v59,
    v60,
    v61,
    v18 / 1000,
    173);
  v20 = 1;
LABEL_24:
  v21 = *(_QWORD *)a1;
  if ( *(_QWORD *)a1 )
    v22 = *(_DWORD *)(v21 + 24);
  else
    v22 = -1;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_encoder_phys_cmd_handle_wr_ptr_timeout",
    2186,
    -1,
    v22,
    v20,
    4369,
    -1059143953,
    v67);
  v23 = *(_QWORD *)(a1 + 8);
  if ( v23 && *(_BYTE *)(v23 + 4516) != 1 )
  {
    if ( !v20 )
      goto LABEL_83;
    if ( (_drm_debug & 4) != 0 )
    {
      if ( *(_QWORD *)a1 )
        v25 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      else
        v25 = -1;
      _drm_dev_dbg(0, 0, 0, "enc%d intf%d wr_ptr_irq wait failed, retry with WD TE\n", v25, *(_DWORD *)(a1 + 672) - 1);
    }
    sde_encoder_helper_switch_vsync(*(_QWORD *)a1, 1);
    v5 = sde_encoder_phys_cmd_wait_for_wr_ptr(a1);
    sde_encoder_helper_switch_vsync(*(_QWORD *)a1, 0);
    if ( v5 == -110 )
      goto LABEL_83;
LABEL_45:
    *(_BYTE *)(a1 + 2760) = v5 == 0;
    goto LABEL_46;
  }
  if ( v8 >= 3 )
    goto LABEL_132;
  v24 = *(void (**)(void))(*(_QWORD *)(a1 + 424) + 8LL * v8 + 800);
  if ( v24 && (*(_BYTE *)(v21 + 700) & 1) == 0 )
  {
    if ( *((_DWORD *)v24 - 1) != -1839426449 )
      __break(0x8228u);
    v24();
  }
  v5 = sde_encoder_phys_cmd_wait_for_wr_ptr(a1);
  if ( v5 != -110 )
    goto LABEL_45;
LABEL_83:
  printk(&unk_2125A9, "_sde_encoder_phys_cmd_handle_wr_ptr_timeout");
  if ( *(_QWORD *)a1 )
    v46 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
  else
    v46 = -1;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_encoder_phys_cmd_handle_wr_ptr_timeout",
    2215,
    -1,
    v46,
    v20,
    60333,
    -1059143953,
    v68);
  if ( *(_DWORD *)(a1 + 664) != 3 )
  {
    v47 = *(_DWORD *)(a1 + 880);
    while ( v47 )
    {
      _X12 = (unsigned int *)(a1 + 880);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v54 = __ldxr(_X12);
        if ( v54 != v47 )
          break;
        if ( !__stlxr(v47 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v54 == v47;
      v47 = v54;
      if ( _ZF )
      {
        v55 = raw_spin_lock_irqsave(*(_QWORD *)(a1 + 824));
        v56 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 392);
        v57 = v55;
        v58 = *(_QWORD *)a1;
        if ( *((_DWORD *)v56 - 1) != -570463643 )
          __break(0x8229u);
        v56(v58, a1, 16);
        raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 824), v57);
        break;
      }
    }
  }
  *(_BYTE *)(a1 + 2760) = 0;
  v5 = -110;
  *(_DWORD *)(a1 + 832) = 5;
LABEL_63:
  v33 = *(_DWORD *)(a1 + 876);
  if ( v33 >= 1 )
  {
    do
    {
      --v33;
      v5 |= sde_encoder_wait_for_event(*(_QWORD *)a1, 1u);
    }
    while ( v33 );
  }
  if ( v5 )
  {
    if ( *(_QWORD *)a1 )
      v35 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v35 = -1;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_phys_cmd_wait_for_commit_done",
      2301,
      -1,
      v35,
      *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
      *(_DWORD *)(a1 + 2332),
      *(_DWORD *)(a1 + 876),
      *(_DWORD *)(a1 + 832));
    printk(&unk_220DEC, "sde_encoder_phys_cmd_wait_for_commit_done");
  }
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return v5;
}
