__int64 __fastcall sde_encoder_resource_control_helper(__int64 a1, __int64 a2)
{
  char v3; // w20
  __int64 v4; // x8
  char v5; // w21
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x0
  unsigned int disp_op; // w0
  int v10; // w7
  __int64 result; // x0
  void *v12; // x0
  void *v13; // x0
  void *v14; // x0
  const char *v15; // x1
  int v16; // w6
  int v17; // w26
  __int64 v18; // x21
  unsigned int v19; // w25
  __int64 v20; // x8
  int v21; // w27
  __int64 v22; // x22
  __int64 v23; // x20
  unsigned int v24; // w0
  __int64 v25; // x9
  unsigned int v26; // w0
  unsigned int v27; // w9
  unsigned int v28; // w8
  void (*v29)(void); // x10
  void (*v30)(void); // x10
  void (*v31)(void); // x10
  __int64 v32; // x0
  __int64 (*v33)(void); // x10
  void (*v34)(void); // x8
  _BOOL4 v35; // w20
  bool v36; // w25
  __int64 v37; // x2
  __int64 v38; // x3
  __int64 v39; // x4
  __int64 v40; // x5
  __int64 v41; // x6
  int v42; // w7
  __int64 v43; // x8
  int v44; // w6
  int v45; // w7
  int v46; // w7
  __int64 v47; // x8
  int v48; // w4
  unsigned int v49; // w9
  unsigned int v56; // w11
  unsigned int v57; // w20
  int v58; // w7
  unsigned int v59; // w20
  unsigned int v60; // w8
  void (*v61)(void); // x9
  void (*v62)(void); // x9
  void (*v63)(void); // x9
  __int64 (*v64)(void); // x9
  int v65; // w8
  int v66; // w6
  int v67; // w7
  char v68; // [xsp+0h] [xbp-10h]
  char v69; // [xsp+0h] [xbp-10h]

  if ( !a1 )
  {
    v14 = &unk_26FCAB;
    v15 = "sde_encoder_get_kms";
LABEL_79:
    printk(v14, v15);
    return 4294967274LL;
  }
  v3 = a2;
  if ( !*(_QWORD *)a1 )
  {
    v12 = &unk_26FCAB;
LABEL_14:
    printk(v12, "sde_encoder_get_kms");
    v5 = 1;
    v6 = *(_QWORD *)a1;
    if ( *(_QWORD *)a1 )
      goto LABEL_6;
LABEL_15:
    v13 = &unk_26FCAB;
LABEL_16:
    printk(v13, "sde_encoder_get_kms");
    disp_op = 0;
    if ( (v5 & 1) != 0 )
      return 4294967274LL;
    goto LABEL_17;
  }
  v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v4 || !*(_QWORD *)(v4 + 8) )
  {
    v12 = &unk_234896;
    goto LABEL_14;
  }
  v5 = 0;
  v6 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
    goto LABEL_15;
LABEL_6:
  v7 = *(_QWORD *)(v6 + 56);
  if ( !v7 || (v8 = *(_QWORD *)(v7 + 8)) == 0 )
  {
    v13 = &unk_234896;
    goto LABEL_16;
  }
  disp_op = sde_kms_get_disp_op(v8, a2);
  if ( (v5 & 1) != 0 )
    return 4294967274LL;
LABEL_17:
  v16 = *(_DWORD *)(a1 + 888);
  if ( (v3 & 1) != 0 )
  {
    if ( v16 == 4 )
      v17 = 3;
    else
      v17 = 1;
  }
  else
  {
    if ( (v16 | 4) == 4 )
    {
      if ( (_drm_debug & 4) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "unbalanced call - enable: %d, rc_state: %d", 0, v16);
        v16 = *(_DWORD *)(a1 + 888);
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_encoder_resource_control_helper",
        2318,
        -1,
        *(_DWORD *)(a1 + 24),
        0,
        v16,
        60333,
        239);
      return 0;
    }
    v17 = 2 * (v16 != 1);
  }
  v18 = *(_QWORD *)(a1 + 80);
  v19 = disp_op;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "enc%d enable:%d\n", *(_DWORD *)(a1 + 24), v3 & 1);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_encoder_resource_control_helper",
    2331,
    -1,
    *(_DWORD *)(a1 + 24),
    v3 & 1,
    -1059143953,
    v10,
    v68);
  v20 = *(_QWORD *)(a1 + 328);
  if ( !v20 )
  {
    v14 = &unk_24C8AC;
    v15 = "_sde_encoder_resource_control_helper";
    goto LABEL_79;
  }
  v21 = *(_DWORD *)(a1 + 648);
  v22 = *(_QWORD *)(v20 + 8);
  if ( (v3 & 1) != 0 )
  {
    v23 = *(_QWORD *)(*(_QWORD *)a1 + 8LL);
    v24 = _pm_runtime_resume(v23, 4);
    if ( (v24 & 0x80000000) == 0 )
    {
      v25 = *(_QWORD *)(a1 + 328);
      *(_BYTE *)(a1 + 1370) = 1;
      v26 = sde_connector_clk_ctrl(*(_QWORD *)(v25 + 8), 1, 0);
      if ( v26 )
      {
        v59 = v26;
        printk(&unk_22E1A3, "_sde_encoder_resource_control_helper");
        _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)a1 + 8LL), 4);
        return v59;
      }
      sde_encoder_irq_control((_DWORD *)a1, 1);
      if ( v17 != 3 || v21 != 1 || *(_BYTE *)(a1 + 753) != 1 )
        goto LABEL_64;
      v27 = *(_DWORD *)(a1 + 196);
      v28 = v19;
      if ( !v27 )
        goto LABEL_56;
      v29 = *(void (**)(void))(*(_QWORD *)(a1 + 200) + 352LL);
      if ( v29 )
      {
        if ( *((_DWORD *)v29 - 1) != -511414616 )
          __break(0x822Au);
        v29();
        v27 = *(_DWORD *)(a1 + 196);
        v28 = v19;
      }
      if ( v27 < 2 )
        goto LABEL_56;
      v30 = *(void (**)(void))(*(_QWORD *)(a1 + 208) + 352LL);
      if ( v30 )
      {
        if ( *((_DWORD *)v30 - 1) != -511414616 )
          __break(0x822Au);
        v30();
        v27 = *(_DWORD *)(a1 + 196);
        v28 = v19;
      }
      if ( v27 < 3 )
        goto LABEL_56;
      v31 = *(void (**)(void))(*(_QWORD *)(a1 + 216) + 352LL);
      if ( v31 )
      {
        if ( *((_DWORD *)v31 - 1) != -511414616 )
          __break(0x822Au);
        v31();
        v27 = *(_DWORD *)(a1 + 196);
        v28 = v19;
      }
      if ( v27 < 4 )
        goto LABEL_56;
      v32 = *(_QWORD *)(a1 + 224);
      v33 = *(__int64 (**)(void))(v32 + 352);
      if ( v33 )
      {
        if ( *((_DWORD *)v33 - 1) != -511414616 )
          __break(0x822Au);
        v32 = v33();
        v27 = *(_DWORD *)(a1 + 196);
        v28 = v19;
      }
      if ( v27 <= 4 )
      {
LABEL_56:
        v32 = *(_QWORD *)(*(_QWORD *)(a1 + 328) + 416LL);
        if ( !v32 )
        {
LABEL_62:
          if ( v22 )
            *(_DWORD *)(v22 + 4720) = 5;
LABEL_64:
          sde_encoder_pm_qos_add_request(a1);
          return 0;
        }
        if ( v28 <= 2 )
        {
          v34 = *(void (**)(void))(v32 + 8LL * v28 + 880);
          if ( v34 )
          {
            if ( *((_DWORD *)v34 - 1) != 836498625 )
              __break(0x8228u);
            v34();
          }
          goto LABEL_62;
        }
      }
LABEL_128:
      __break(0x5512u);
      return sde_encoder_pm_qos_remove_request(v32);
    }
    v49 = *(_DWORD *)(v23 + 480);
    do
    {
      if ( !v49 )
        break;
      _X13 = (unsigned int *)(v23 + 480);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v56 = __ldxr(_X13);
        if ( v56 != v49 )
          break;
        if ( !__stlxr(v49 - 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v56 == v49;
      v49 = v56;
    }
    while ( !_ZF );
    v57 = v24;
    printk(&unk_24C43E, "_sde_encoder_resource_control_helper");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_encoder_resource_control_helper",
      2348,
      -1,
      v57,
      60333,
      -1059143953,
      v58,
      v69);
    return v57;
  }
  else
  {
    sde_encoder_pm_qos_remove_request(a1);
    v35 = v17 == 2;
    v36 = v21 != 1 || v17 != 2;
    if ( !v36 && *(_BYTE *)(a1 + 753) == 1 )
    {
      if ( v22 )
        *(_DWORD *)(v22 + 4720) = 3;
      sde_crtc_copr_status_event_notify(v18);
      v43 = *(_QWORD *)(a1 + 328);
      if ( v43 && *(_BYTE *)(a1 + 748) == 1 )
      {
        hrtimer_cancel(v43 + 2544);
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_cancel_vrr_timers",
          2258,
          -1,
          *(_DWORD *)(a1 + 24),
          -1059143953,
          v44,
          v45,
          v69);
      }
      sde_encoder_handle_video_psr_self_refresh(a1, 1, v37, v38, v39, v40, v41, v42);
      if ( *(_BYTE *)(a1 + 749) == 1 )
      {
        v47 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
        v48 = *(_DWORD *)(a1 + 4916);
        if ( *(_QWORD *)(*(_QWORD *)(v47 + 8) + 2128LL) )
        {
          sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_vhm_wakelock", 2277, -1, v48, 0, -1059143953, v46, v69);
        }
        else if ( v48 == 1 )
        {
          sde_power_wakelock_ctrl(v47 + 16, 0);
          *(_DWORD *)(a1 + 4916) = 0;
        }
      }
      v60 = *(_DWORD *)(a1 + 196);
      if ( v60 )
      {
        v61 = *(void (**)(void))(*(_QWORD *)(a1 + 200) + 344LL);
        if ( v61 )
        {
          if ( *((_DWORD *)v61 - 1) != -511414616 )
            __break(0x8229u);
          v61();
          v60 = *(_DWORD *)(a1 + 196);
        }
        if ( v60 >= 2 )
        {
          v62 = *(void (**)(void))(*(_QWORD *)(a1 + 208) + 344LL);
          if ( v62 )
          {
            if ( *((_DWORD *)v62 - 1) != -511414616 )
              __break(0x8229u);
            v62();
            v60 = *(_DWORD *)(a1 + 196);
          }
          if ( v60 >= 3 )
          {
            v63 = *(void (**)(void))(*(_QWORD *)(a1 + 216) + 344LL);
            if ( v63 )
            {
              if ( *((_DWORD *)v63 - 1) != -511414616 )
                __break(0x8229u);
              v63();
              v60 = *(_DWORD *)(a1 + 196);
            }
            if ( v60 >= 4 )
            {
              v32 = *(_QWORD *)(a1 + 224);
              v64 = *(__int64 (**)(void))(v32 + 344);
              if ( v64 )
              {
                if ( *((_DWORD *)v64 - 1) != -511414616 )
                  __break(0x8229u);
                v32 = v64();
                v60 = *(_DWORD *)(a1 + 196);
              }
              if ( v60 > 4 )
                goto LABEL_128;
            }
          }
        }
      }
      if ( v22 )
        *(_DWORD *)(v22 + 4720) = 4;
    }
    sde_encoder_irq_control((_DWORD *)a1, 0);
    v65 = *(unsigned __int8 *)(a1 + 753);
    if ( v65 == 1 )
    {
      sde_encoder_cesta_update(a1, 4u);
      LOBYTE(v65) = *(_BYTE *)(a1 + 753);
    }
    if ( (v65 & 1) == 0 )
      v35 = *(_DWORD *)(a1 + 888) == 2;
    sde_connector_clk_ctrl(*(_QWORD *)(*(_QWORD *)(a1 + 328) + 8LL), 0, v35);
    _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)a1 + 8LL), 4);
    result = 0;
    if ( !v36 )
    {
      if ( *(_BYTE *)(a1 + 753) == 1 && *(_DWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 8LL) + 500LL) != 2 )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "idle entry failed, power vote still held\n");
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_encoder_resource_control_helper",
          2433,
          -1,
          43690,
          -1059143953,
          v66,
          v67,
          v69);
      }
      return 0;
    }
  }
  return result;
}
