__int64 __fastcall sde_encoder_resource_control(__int64 a1, int a2)
{
  __int64 v4; // x26
  int v5; // w22
  int v6; // w6
  unsigned int v7; // w21
  __int64 v8; // x0
  int v9; // w8
  int v10; // w6
  int v11; // w6
  __int64 v12; // x21
  __int64 v13; // x8
  __int64 v14; // x26
  __int64 v15; // x27
  __int64 v16; // x23
  __int64 v17; // x0
  int v18; // w0
  int v19; // w4
  char *v20; // x1
  int v21; // w2
  int v22; // w5
  int v23; // w7
  __int64 v24; // x26
  int v25; // w5
  int v26; // w6
  int v27; // w6
  int v28; // w0
  int v29; // w4
  char *v30; // x1
  int v31; // w6
  int v32; // w2
  int v33; // w5
  int v34; // w5
  __int64 v35; // x8
  int v36; // w21
  unsigned int v37; // w0
  __int64 v38; // x8
  unsigned int v39; // w8
  __int64 v40; // x0
  void (*v41)(void); // x9
  __int64 v42; // x0
  void (*v43)(void); // x9
  __int64 v44; // x0
  void (*v45)(void); // x9
  __int64 v46; // x0
  void (*v47)(void); // x8
  unsigned int v48; // w8
  __int64 v49; // x0
  void (*v50)(void); // x9
  __int64 v51; // x0
  void (*v52)(void); // x9
  __int64 v53; // x0
  void (*v54)(void); // x9
  __int64 v55; // x0
  void (*v56)(void); // x8
  __int64 v57; // x8
  int v58; // w6
  int v59; // w5
  unsigned int v60; // w0
  int v61; // w6
  int v62; // w8
  __int64 v63; // x0
  __int64 (*v64)(void); // x8
  int v65; // w0
  int v66; // w4
  char *v67; // x1
  int v68; // w2
  int v69; // w5
  int v70; // w0
  int v71; // w4
  int v72; // w2
  int v73; // w7
  __int64 v74; // x8
  __int64 v75; // x8
  unsigned int v76; // w0
  __int64 v77; // x8
  int v78; // w7
  __int64 v80; // x8
  __int64 v81; // x8
  __int64 v82; // x8
  int v83; // w6
  int v84; // w0
  int v85; // w4
  char *v86; // x1
  int v87; // w6
  int v88; // w2
  int v89; // w5
  unsigned int v90; // w8
  __int64 v91; // x8

  if ( !a1 || !*(_QWORD *)a1 || (v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 )
  {
    printk(&unk_2537AF, "sde_encoder_resource_control");
    return (unsigned int)-22;
  }
  v5 = *(_DWORD *)(a1 + 648);
  v6 = *(unsigned __int8 *)(a1 + 836);
  if ( (unsigned int)(a2 - 1) >= 5 && !*(_BYTE *)(a1 + 836) )
    return 0;
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "enc%d sw_event:%d, idle_pc:%d\n", *(_DWORD *)(a1 + 24), a2, v6);
    v6 = *(unsigned __int8 *)(a1 + 836);
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_resource_control",
    3324,
    4,
    *(_DWORD *)(a1 + 24),
    a2,
    v6,
    *(_DWORD *)(a1 + 888),
    17);
  if ( a2 <= 3 )
  {
    if ( a2 != 1 )
    {
      if ( a2 == 2 )
      {
        if ( (kthread_cancel_delayed_work_sync(a1 + 944) & 1) != 0 && (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "enc%d sw_event:%d, work cancelled\n", *(_DWORD *)(a1 + 24), 2);
        mutex_lock(a1 + 840);
        v11 = *(_DWORD *)(a1 + 888);
        if ( v5 == 1 && (*(_BYTE *)(a1 + 749) & 1) == 0 && v11 == 4 )
        {
          sde_encoder_irq_control((_DWORD *)a1, 1);
        }
        else if ( (v11 | 4) == 4 )
        {
          if ( (_drm_debug & 4) != 0 )
          {
            _drm_dev_dbg(0, 0, 0, "enc%d sw_event:%d, rc in %d state\n", *(_DWORD *)(a1 + 24), 2, v11);
            v11 = *(_DWORD *)(a1 + 888);
          }
          v18 = sde_dbg_base_evtlog;
          v19 = *(_DWORD *)(a1 + 24);
          v20 = "_sde_encoder_rc_pre_stop";
          v21 = 2983;
          v22 = 2;
          v23 = 21845;
          goto LABEL_145;
        }
        ((void (__fastcall *)(__int64, _QWORD))sde_encoder_update_rsc_client)(a1, 0);
        v36 = 1;
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_encoder_rc_pre_stop",
          2995,
          -1,
          *(_DWORD *)(a1 + 24),
          2,
          *(_DWORD *)(a1 + 888),
          1,
          85);
LABEL_60:
        *(_DWORD *)(a1 + 888) = v36;
LABEL_146:
        mutex_unlock(a1 + 840);
        v7 = 0;
        goto LABEL_179;
      }
      mutex_lock(a1 + 840);
      v27 = *(_DWORD *)(a1 + 888);
      if ( !v27 )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(0, 0, 0, "enc%d sw_event:%d, rc in OFF state\n", *(_DWORD *)(a1 + 24), 3);
          v61 = *(_DWORD *)(a1 + 888);
        }
        else
        {
          v61 = 0;
        }
        sde_evtlog_log(sde_dbg_base_evtlog, "_sde_encoder_rc_stop", 3015, -1, *(_DWORD *)(a1 + 24), 3, v61, 26214, 239);
        goto LABEL_177;
      }
      if ( v27 == 1 )
      {
        sde_encoder_resource_control_helper(a1, 0);
        v27 = *(_DWORD *)(a1 + 888);
      }
      else if ( (unsigned int)(v27 - 2) < 2 )
      {
        printk(&unk_249263, "_sde_encoder_rc_stop");
        v28 = sde_dbg_base_evtlog;
        v29 = *(_DWORD *)(a1 + 24);
        v30 = "_sde_encoder_rc_stop";
        v31 = *(_DWORD *)(a1 + 888);
        v32 = 3022;
        v33 = 3;
        goto LABEL_195;
      }
      sde_evtlog_log(sde_dbg_base_evtlog, "_sde_encoder_rc_stop", 3035, -1, *(_DWORD *)(a1 + 24), 3, v27, 0, 102);
      v7 = 0;
      *(_DWORD *)(a1 + 888) = 0;
LABEL_178:
      mutex_unlock(a1 + 840);
      goto LABEL_179;
    }
    v24 = *(_QWORD *)(a1 + 80);
    mutex_lock(a1 + 840);
    v25 = *(_DWORD *)(a1 + 888);
    if ( !v25 || v25 == 4 )
    {
      if ( v5 == 1 && v25 == 4 && (*(_BYTE *)(a1 + 753) & 1) == 0 )
      {
        sde_encoder_irq_control((_DWORD *)a1, 1);
        sde_encoder_pm_qos_add_request(a1);
      }
      else
      {
        v37 = sde_encoder_resource_control_helper(a1, 1);
        if ( v37 )
        {
          v7 = v37;
          printk(&unk_249263, "_sde_encoder_rc_kickoff");
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_encoder_rc_kickoff",
            2949,
            -1,
            *(_DWORD *)(a1 + 24),
            1,
            *(_DWORD *)(a1 + 888),
            60333,
            239);
          v38 = *(_QWORD *)(a1 + 328);
          if ( v38 )
            goto LABEL_153;
          goto LABEL_157;
        }
        ((void (__fastcall *)(__int64, __int64))sde_encoder_update_rsc_client)(a1, 1);
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_encoder_rc_kickoff",
        2955,
        -1,
        *(_DWORD *)(a1 + 24),
        1,
        *(_DWORD *)(a1 + 888),
        2,
        51);
      v7 = 0;
      *(_DWORD *)(a1 + 888) = 2;
      v38 = *(_QWORD *)(a1 + 328);
      if ( v38 )
        goto LABEL_153;
    }
    else
    {
      if ( v25 == 2 )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(0, 0, 0, "enc%d sw_event:%d, rc in ON state\n", *(_DWORD *)(a1 + 24), 1);
          v26 = *(_DWORD *)(a1 + 888);
        }
        else
        {
          v26 = 2;
        }
        v70 = sde_dbg_base_evtlog;
        v71 = *(_DWORD *)(a1 + 24);
        v72 = 2925;
        v73 = 13107;
      }
      else
      {
        printk(&unk_249263, "_sde_encoder_rc_kickoff");
        v70 = sde_dbg_base_evtlog;
        v71 = *(_DWORD *)(a1 + 24);
        v26 = *(_DWORD *)(a1 + 888);
        v72 = 2932;
        v73 = 60333;
      }
      sde_evtlog_log(v70, "_sde_encoder_rc_kickoff", v72, -1, v71, 1, v26, v73, 239);
      v7 = 0;
      v38 = *(_QWORD *)(a1 + 328);
      if ( v38 )
      {
LABEL_153:
        if ( (*(_BYTE *)(a1 + 644) & 2) != 0 )
        {
          v74 = *(_QWORD *)(v38 + 8);
          if ( v74 )
          {
            v75 = *(_QWORD *)(v74 + 2512);
            if ( v75 )
            {
              if ( *(_QWORD *)(v75 + 1440) )
                goto LABEL_160;
            }
          }
        }
      }
    }
LABEL_157:
    if ( !v24 || (mdnie_art_in_progress(v24 + 7952) & 1) == 0 && *(_BYTE *)(v24 + 7948) != 1 )
    {
      sde_encoder_rc_restart_delayed(a1, 1);
      goto LABEL_178;
    }
LABEL_160:
    if ( (kthread_cancel_delayed_work_sync(a1 + 944) & 1) != 0 && (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "enc%d sw_event:%d, work cancelled\n", *(_DWORD *)(a1 + 24), 1);
    goto LABEL_178;
  }
  if ( a2 <= 5 )
  {
    v8 = a1 + 840;
    if ( a2 == 4 )
    {
      mutex_lock(v8);
      v9 = *(_DWORD *)(a1 + 888);
      if ( v9 == 2 )
      {
LABEL_126:
        sde_evtlog_log(sde_dbg_base_evtlog, "_sde_encoder_rc_pre_modeset", 3079, -1, *(_DWORD *)(a1 + 24), 4, 2, 3, 119);
        *(_DWORD *)(a1 + 888) = 3;
        sde_encoder_pm_qos_remove_request(a1);
LABEL_177:
        v7 = 0;
        goto LABEL_178;
      }
      if ( !v9 )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(0, 0, 0, "enc%d sw_event:%d, rc in OFF state\n", *(_DWORD *)(a1 + 24), 4);
          v10 = *(_DWORD *)(a1 + 888);
        }
        else
        {
          v10 = 0;
        }
        v65 = sde_dbg_base_evtlog;
        v66 = *(_DWORD *)(a1 + 24);
        v67 = "_sde_encoder_rc_pre_modeset";
        v68 = 3055;
        v69 = 4;
LABEL_149:
        sde_evtlog_log(v65, v67, v68, -1, v66, v69, v10, 30583, 239);
        goto LABEL_177;
      }
      v60 = sde_encoder_resource_control_helper(a1, 1);
      if ( !v60 )
      {
        ((void (__fastcall *)(__int64, __int64))sde_encoder_update_rsc_client)(a1, 1);
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_encoder_rc_pre_modeset",
          3074,
          -1,
          *(_DWORD *)(a1 + 24),
          4,
          *(_DWORD *)(a1 + 888),
          2,
          119);
        *(_DWORD *)(a1 + 888) = 2;
        goto LABEL_126;
      }
      v7 = v60;
      printk(&unk_249263, "_sde_encoder_rc_pre_modeset");
      v84 = sde_dbg_base_evtlog;
      v85 = *(_DWORD *)(a1 + 24);
      v86 = "_sde_encoder_rc_pre_modeset";
      v87 = *(_DWORD *)(a1 + 888);
      v88 = 3067;
      v89 = 4;
LABEL_216:
      sde_evtlog_log(v84, v86, v88, -1, v85, v89, v87, 60333, 239);
      goto LABEL_178;
    }
    mutex_lock(v8);
    v34 = *(_DWORD *)(a1 + 888);
    if ( v34 == 3 )
    {
      if ( *(_DWORD *)(a1 + 648) == 2 && *(_BYTE *)(a1 + 700) == 1 )
      {
        v39 = *(_DWORD *)(a1 + 196);
        if ( v39 )
        {
          v40 = *(_QWORD *)(a1 + 200);
          if ( v40 )
          {
            v41 = *(void (**)(void))(v40 + 248);
            if ( v41 )
            {
              if ( *((_DWORD *)v41 - 1) != 1595431362 )
                __break(0x8229u);
              v41();
              v39 = *(_DWORD *)(a1 + 196);
            }
          }
          if ( v39 >= 2 )
          {
            v42 = *(_QWORD *)(a1 + 208);
            if ( v42 )
            {
              v43 = *(void (**)(void))(v42 + 248);
              if ( v43 )
              {
                if ( *((_DWORD *)v43 - 1) != 1595431362 )
                  __break(0x8229u);
                v43();
                v39 = *(_DWORD *)(a1 + 196);
              }
            }
            if ( v39 >= 3 )
            {
              v44 = *(_QWORD *)(a1 + 216);
              if ( v44 )
              {
                v45 = *(void (**)(void))(v44 + 248);
                if ( v45 )
                {
                  if ( *((_DWORD *)v45 - 1) != 1595431362 )
                    __break(0x8229u);
                  v45();
                  v39 = *(_DWORD *)(a1 + 196);
                }
              }
              if ( v39 >= 4 )
              {
                v46 = *(_QWORD *)(a1 + 224);
                if ( v46 )
                {
                  v47 = *(void (**)(void))(v46 + 248);
                  if ( v47 )
                  {
                    if ( *((_DWORD *)v47 - 1) != 1595431362 )
                      __break(0x8228u);
                    v47();
                  }
                }
              }
            }
          }
        }
        sde_encoder_update_vsync_source(a1, (unsigned __int8 *)(a1 + 640));
        v48 = *(_DWORD *)(a1 + 196);
        if ( v48 )
        {
          v49 = *(_QWORD *)(a1 + 200);
          if ( v49 )
          {
            v50 = *(void (**)(void))(v49 + 248);
            if ( v50 )
            {
              if ( *((_DWORD *)v50 - 1) != 1595431362 )
                __break(0x8229u);
              v50();
              v48 = *(_DWORD *)(a1 + 196);
            }
          }
          if ( v48 >= 2 )
          {
            v51 = *(_QWORD *)(a1 + 208);
            if ( v51 )
            {
              v52 = *(void (**)(void))(v51 + 248);
              if ( v52 )
              {
                if ( *((_DWORD *)v52 - 1) != 1595431362 )
                  __break(0x8229u);
                v52();
                v48 = *(_DWORD *)(a1 + 196);
              }
            }
            if ( v48 >= 3 )
            {
              v53 = *(_QWORD *)(a1 + 216);
              if ( v53 )
              {
                v54 = *(void (**)(void))(v53 + 248);
                if ( v54 )
                {
                  if ( *((_DWORD *)v54 - 1) != 1595431362 )
                    __break(0x8229u);
                  v54();
                  v48 = *(_DWORD *)(a1 + 196);
                }
              }
              if ( v48 >= 4 )
              {
                v55 = *(_QWORD *)(a1 + 224);
                if ( v55 )
                {
                  v56 = *(void (**)(void))(v55 + 248);
                  if ( v56 )
                  {
                    if ( *((_DWORD *)v56 - 1) != 1595431362 )
                      __break(0x8228u);
                    v56();
                  }
                }
              }
            }
          }
        }
      }
      ((void (__fastcall *)(__int64, __int64))sde_encoder_update_rsc_client)(a1, 1);
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_encoder_rc_post_modeset",
        3123,
        -1,
        *(_DWORD *)(a1 + 24),
        5,
        *(_DWORD *)(a1 + 888),
        2,
        136);
      *(_DWORD *)(a1 + 888) = 2;
      sde_encoder_pm_qos_add_request(a1);
      goto LABEL_177;
    }
    if ( !v34 )
    {
      if ( (_drm_debug & 4) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "enc%d sw_event:%d, rc in OFF state\n", *(_DWORD *)(a1 + 24), 5);
        v10 = *(_DWORD *)(a1 + 888);
      }
      else
      {
        v10 = 0;
      }
      v65 = sde_dbg_base_evtlog;
      v66 = *(_DWORD *)(a1 + 24);
      v67 = "_sde_encoder_rc_post_modeset";
      v68 = 3100;
      v69 = 5;
      goto LABEL_149;
    }
    printk(&unk_27006A, "_sde_encoder_rc_post_modeset");
    v28 = sde_dbg_base_evtlog;
    v29 = *(_DWORD *)(a1 + 24);
    v30 = "_sde_encoder_rc_post_modeset";
    v31 = *(_DWORD *)(a1 + 888);
    v32 = 3107;
    v33 = 5;
LABEL_195:
    sde_evtlog_log(v28, v30, v32, -1, v29, v33, v31, 60333, 239);
    v7 = -22;
    goto LABEL_178;
  }
  if ( a2 != 6 )
  {
    v35 = *(_QWORD *)(a1 + 1360);
    if ( !v35 )
    {
      v7 = -22;
      if ( (_drm_debug & 4) == 0 )
        goto LABEL_179;
      v59 = 1;
      goto LABEL_167;
    }
    v7 = *(_DWORD *)(v35 + 160);
    if ( v7 > 0xF )
    {
      if ( (_drm_debug & 4) == 0 )
      {
        v7 = -22;
LABEL_179:
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_resource_control",
          3359,
          4,
          *(_DWORD *)(a1 + 24),
          a2,
          *(unsigned __int8 *)(a1 + 836),
          *(_DWORD *)(a1 + 888),
          34);
        return v7;
      }
      v59 = 0;
LABEL_167:
      _drm_dev_dbg(0, 0, 0, "enc%d invalid crtc:%d or crtc index:%d , sw_event:%u\n", *(_DWORD *)(a1 + 24), v59, v7, 7);
      v7 = -22;
      goto LABEL_179;
    }
    mutex_lock(a1 + 840);
    v62 = *(_DWORD *)(a1 + 888);
    if ( v62 == 4 )
    {
      v76 = sde_encoder_resource_control_helper(a1, 1);
      if ( v76 )
      {
        v7 = v76;
        printk(&unk_249263, "_sde_encoder_rc_early_wakeup");
        v84 = sde_dbg_base_evtlog;
        v85 = *(_DWORD *)(a1 + 24);
        v86 = "_sde_encoder_rc_early_wakeup";
        v87 = *(_DWORD *)(a1 + 888);
        v88 = 3262;
        v89 = 7;
        goto LABEL_216;
      }
      ((void (__fastcall *)(__int64, __int64))sde_encoder_update_rsc_client)(a1, 1);
      kthread_mod_delayed_work(v4 + 80LL * v7 + 1152, a1 + 944, 48);
      *(_DWORD *)(a1 + 888) = 2;
      LOBYTE(v77) = -64;
    }
    else
    {
      if ( v62 != 2 )
        goto LABEL_175;
      v63 = *(_QWORD *)(a1 + 328);
      if ( v63 )
      {
        v64 = *(__int64 (**)(void))(v63 + 264);
        if ( v64 )
        {
          if ( *((_DWORD *)v64 - 1) != -1375811177 )
            __break(0x8228u);
          if ( (v64() & 1) != 0 )
          {
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(
                0,
                0,
                0,
                "enc%d not handling early wakeup since auto refresh is enabled\n",
                *(_DWORD *)(a1 + 24));
            goto LABEL_177;
          }
        }
      }
      v77 = *(_QWORD *)(a1 + 1360);
      if ( !v77 )
        goto LABEL_176;
      if ( !*(_DWORD *)(v77 + 4712) )
      {
        kthread_mod_delayed_work(v4 + 80LL * v7 + 1152, a1 + 944, 15);
        LOBYTE(v77) = 58;
      }
      else
      {
LABEL_175:
        LOBYTE(v77) = 0;
      }
    }
LABEL_176:
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_encoder_rc_early_wakeup",
      3285,
      -1,
      *(_DWORD *)(a1 + 24),
      7,
      *(_DWORD *)(a1 + 888),
      2,
      v77);
    goto LABEL_177;
  }
  v12 = *(_QWORD *)(a1 + 80);
  v13 = *(_QWORD *)(a1 + 328);
  if ( !v12 || !v13 || (v14 = *(_QWORD *)(*(_QWORD *)a1 + 56LL), (v15 = *(_QWORD *)(v14 + 8)) == 0) )
  {
    printk(&unk_238436, "_sde_encoder_rc_idle");
    v7 = -22;
    goto LABEL_179;
  }
  v16 = *(_QWORD *)(v13 + 8);
  v17 = mutex_lock(a1 + 840);
  if ( *(_BYTE *)(v16 + 4516) == 1 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "enc%d skip idle. Panel in dead state\n", *(_DWORD *)(a1 + 24));
    v18 = sde_dbg_base_evtlog;
    v19 = *(_DWORD *)(a1 + 24);
    v11 = *(_DWORD *)(a1 + 888);
    v20 = "_sde_encoder_rc_idle";
    v21 = 3159;
    v22 = 6;
    v23 = 60333;
LABEL_145:
    sde_evtlog_log(v18, v20, v21, -1, v19, v22, v11, v23, 239);
    goto LABEL_146;
  }
  v11 = *(_DWORD *)(a1 + 888);
  if ( v11 != 2 )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "enc%d sw_event:%d, rc:%d !ON state\n", *(_DWORD *)(a1 + 24), 6, v11);
      v11 = *(_DWORD *)(a1 + 888);
    }
    v18 = sde_dbg_base_evtlog;
    v19 = *(_DWORD *)(a1 + 24);
    v20 = "_sde_encoder_rc_idle";
    v21 = 3164;
    v22 = 6;
    v23 = 60333;
    goto LABEL_145;
  }
  v57 = *(_QWORD *)(a1 + 1360);
  if ( !v57 || *(_DWORD *)(v57 + 4712) || *(_BYTE *)(v12 + 6040) == 1 )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "enc%d skip idle entry", *(_DWORD *)(a1 + 24));
      v58 = *(_DWORD *)(a1 + 888);
      v57 = *(_QWORD *)(a1 + 1360);
    }
    else
    {
      v58 = 2;
    }
    if ( v57 )
      v78 = *(_DWORD *)(v57 + 4712);
    else
      v78 = -22;
    sde_evtlog_log(sde_dbg_base_evtlog, "_sde_encoder_rc_idle", 3170, -1, *(_DWORD *)(a1 + 24), 6, v58, v78, 173);
    v80 = *(_QWORD *)(a1 + 328);
    if ( v80
      && (*(_BYTE *)(a1 + 644) & 2) != 0
      && (v81 = *(_QWORD *)(v80 + 8)) != 0
      && (v82 = *(_QWORD *)(v81 + 2512)) != 0
      && *(_QWORD *)(v82 + 1440)
      || (mdnie_art_in_progress(v12 + 7952) & 1) != 0
      || *(_BYTE *)(v12 + 7948) == 1 )
    {
      if ( (kthread_cancel_delayed_work_sync(a1 + 944) & 1) != 0 && (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "enc%d sw_event:%d, work cancelled\n", *(_DWORD *)(a1 + 24), 6);
    }
    else
    {
      sde_encoder_rc_restart_delayed(a1, 6);
    }
    goto LABEL_146;
  }
  if ( *(_BYTE *)(a1 + 748) == 1 && (!*(_DWORD *)(v16 + 4692) || *(_BYTE *)(v16 + 4572) == 1) )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "enc%d Skip idle entry: apply_vrr set false\n", *(_DWORD *)(a1 + 24));
      v83 = *(_DWORD *)(a1 + 888);
    }
    else
    {
      v83 = 2;
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_encoder_rc_idle",
      3177,
      -1,
      *(_DWORD *)(a1 + 24),
      6,
      v83,
      *(unsigned __int8 *)(v16 + 4572),
      173);
    goto LABEL_146;
  }
  v90 = *(_DWORD *)(v12 + 160);
  if ( v5 == 1 && (*(_BYTE *)(a1 + 753) & 1) == 0 )
  {
    sde_encoder_irq_control((_DWORD *)a1, 0);
    sde_encoder_pm_qos_remove_request(a1);
LABEL_220:
    v36 = 4;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_encoder_rc_idle",
      3202,
      -1,
      *(_DWORD *)(a1 + 24),
      6,
      *(_DWORD *)(a1 + 888),
      4,
      153);
    goto LABEL_60;
  }
  if ( v90 < 0x10 )
  {
    v91 = v14 + 80LL * v90;
    if ( *(_QWORD *)(v91 + 2416) )
      kthread_flush_worker(v91 + 2432);
    if ( (*(_BYTE *)(a1 + 753) & 1) == 0 )
      sde_encoder_cesta_update(a1, 4u);
    ((void (__fastcall *)(__int64, _QWORD))sde_encoder_update_rsc_client)(a1, 0);
    sde_encoder_resource_control_helper(a1, 0);
    if ( !*(_DWORD *)(v15 + 2088) )
    {
      *(_QWORD *)(v12 + 7472) = 0;
      *(_QWORD *)(v12 + 7464) = 0;
      *(_QWORD *)(v12 + 7456) = 0;
      *(_QWORD *)(v12 + 7448) = 0;
      *(_QWORD *)(v12 + 7440) = 0;
      *(_QWORD *)(v12 + 7432) = 0;
      *(_QWORD *)(v12 + 7424) = 0;
      *(_QWORD *)(v12 + 7416) = 0;
      *(_QWORD *)(v12 + 7408) = 0;
      *(_QWORD *)(v12 + 7400) = 0;
      *(_QWORD *)(v12 + 7392) = 0;
    }
    goto LABEL_220;
  }
  __break(0x5512u);
  return sde_encoder_check_prog_fetch_region(v17);
}
