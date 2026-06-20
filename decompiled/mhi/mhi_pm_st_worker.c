__int64 __fastcall mhi_pm_st_worker(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x8
  _QWORD *v4; // x9
  _QWORD *v5; // x10
  __int64 result; // x0
  _QWORD *v7; // x24
  unsigned __int64 v8; // x23
  __int64 *v9; // x21
  __int64 v10; // x20
  __int64 *v11; // x26
  _QWORD *v12; // x25
  _QWORD *v13; // x8
  _QWORD *v14; // t2
  __int64 v15; // x8
  __int64 v16; // x9
  const char *v17; // x3
  __int64 v18; // x2
  int v19; // w8
  __int64 v20; // x8
  __int64 v21; // x20
  const char *v22; // x28
  const char *v23; // x4
  __int64 v24; // x0
  void (__fastcall *v25)(unsigned __int64, __int64, __int64); // x8
  int v26; // w20
  unsigned int v27; // w28
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x20
  __int64 v31; // x28
  __int64 v32; // x8
  int v33; // w0
  int v34; // w8
  bool v35; // zf
  char v36; // w9
  __int64 v37; // x20
  bool v38; // zf
  bool v39; // w8
  __int64 v40; // x8
  unsigned int exec_env; // w0
  void (__fastcall *v42)(unsigned __int64, __int64); // x8
  unsigned int v43; // w8
  __int64 v44; // x28
  unsigned int i; // w20
  __int64 v46; // x0
  __int64 v47; // x1
  __int64 v48; // x9
  __int64 v49; // x10
  __int64 *v50; // x12
  __int64 v51; // x8
  __int64 v52; // x9
  __int64 v53; // x8
  unsigned int v54; // w20
  __int64 v55; // x28
  __int64 v56; // x8
  __int64 v57; // x8
  __int64 v58; // x9
  __int64 v59; // x8
  _QWORD *v60; // x8
  __int64 v61; // x10
  __int64 v62; // x9
  __int64 v63; // x8
  unsigned int v64; // w9
  unsigned int v65; // w8
  _BYTE *v66; // x10
  _QWORD *v67; // x11
  __int64 v68; // x9
  __int64 v69; // x9
  unsigned int v70; // w28
  int v71; // w1
  __int64 v72; // x8
  __int64 v73; // x28
  const char *v74; // x0
  int v75; // w8
  const char *v76; // x4
  _DWORD *v77; // x8
  const char *v78; // x20
  const char *v79; // x0
  __int64 v80; // x20
  const char *v81; // x28
  const char *v82; // x4
  __int64 v83; // x0
  const char *v84; // x20
  const char *v85; // x0
  const char *v86; // x3
  const char *v87; // x20
  const char *v88; // x4
  const char *v89; // x3
  __int64 v90; // x20
  int v91; // w20
  __int64 v92; // [xsp+0h] [xbp-70h]
  __int64 v93; // [xsp+0h] [xbp-70h]
  __int64 v94; // [xsp+0h] [xbp-70h]
  __int64 v95; // [xsp+18h] [xbp-58h]
  __int64 v96; // [xsp+18h] [xbp-58h]
  __int64 v97; // [xsp+20h] [xbp-50h]
  _QWORD *v98; // [xsp+28h] [xbp-48h] BYREF
  _QWORD **v99; // [xsp+30h] [xbp-40h]
  _QWORD v100[5]; // [xsp+38h] [xbp-38h] BYREF
  int v101; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v102; // [xsp+68h] [xbp-8h]

  v1 = a1 - 24;
  v102 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v98 = &v98;
  v99 = &v98;
  raw_spin_lock_irq(a1 - 24);
  v3 = *(_QWORD *)(a1 - 40);
  if ( v3 != a1 - 40 )
  {
    v4 = v99;
    v5 = *(_QWORD **)(a1 - 32);
    *(_QWORD *)(v3 + 8) = v99;
    *v4 = v3;
    *v5 = &v98;
    v99 = (_QWORD **)v5;
    *(_QWORD *)(a1 - 40) = a1 - 40;
    *(_QWORD *)(a1 - 32) = a1 - 40;
  }
  result = raw_spin_unlock_irq(v1);
  v7 = v98;
  if ( v98 != &v98 )
  {
    v8 = a1 - 416;
    v9 = (__int64 *)(a1 - 400);
    v10 = a1 - 144;
    v11 = (__int64 *)(a1 - 384);
    _ReadStatusReg(SP_EL0);
    v97 = a1 - 144;
    do
    {
      v12 = v7;
      v14 = v7;
      v7 = (_QWORD *)*v7;
      v13 = (_QWORD *)v14[1];
      if ( (_QWORD *)*v13 == v12 && (_QWORD *)v7[1] == v12 )
      {
        v7[1] = v13;
        *v13 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v12);
      }
      *v12 = 0xDEAD000000000100LL;
      v12[1] = 0xDEAD000000000122LL;
      v15 = *(_QWORD *)(*v9 + 192);
      if ( v15 && !*(_DWORD *)(v15 + 24) )
      {
        v16 = *((unsigned int *)v12 + 4);
        v17 = "INVALID_STATE";
        if ( (unsigned int)v16 <= 7 )
          v17 = dev_state_tran_str[v16];
        ipc_log_string(*(_QWORD *)(v15 + 32), "[D][%s] Handling state transition: %s\n", "mhi_pm_st_worker", v17);
      }
      v18 = *((unsigned int *)v12 + 4);
      v19 = *((_DWORD *)v12 + 4);
      if ( v19 <= 3 )
      {
        if ( v19 > 1 )
        {
          if ( v19 == 2 )
          {
            raw_write_lock_irq(a1 - 96);
            *(_DWORD *)(a1 - 72) = 1;
            raw_write_unlock_irq(a1 - 96);
            mhi_process_sleeping_events(v8);
            mhi_create_devices(v8);
            if ( *(_BYTE *)(a1 + 198) == 1 )
              mhi_download_amss_image(v8);
          }
          else
          {
            v40 = *(_QWORD *)(*v9 + 192);
            LODWORD(v100[0]) = *(_DWORD *)(a1 - 72);
            if ( v40 && !*(_DWORD *)(v40 + 24) )
              ipc_log_string(
                *(_QWORD *)(v40 + 32),
                "[D][%s] Processing Mission Mode transition\n",
                "mhi_pm_mission_mode_transition");
            raw_write_lock_irq(a1 - 96);
            if ( (*(_WORD *)(a1 - 80) & 0xFDE) != 0
              && (exec_env = mhi_get_exec_env(v8), exec_env <= 7)
              && ((1 << exec_env) & 0x94) != 0 )
            {
              *(_DWORD *)(a1 - 72) = exec_env;
              raw_write_unlock_irq(a1 - 96);
              _wake_up(a1 + 40, 3, 0, 0);
              mhi_reset_reg_write_q(v8);
              device_for_each_child(*v9 + 40, v100, mhi_destroy_device);
              v42 = *(void (__fastcall **)(unsigned __int64, __int64))(a1 + 64);
              if ( *((_DWORD *)v42 - 1) != 1183736653 )
                __break(0x8228u);
              v42(v8, 5);
              if ( !(unsigned int)_mhi_device_get_sync(v8) )
              {
                raw_read_lock_bh(a1 - 96);
                if ( *(_DWORD *)(a1 - 80) <= 0x7Fu )
                {
                  v43 = *(_DWORD *)(a1 - 204);
                  if ( v43 )
                  {
                    v44 = *(_QWORD *)(a1 - 168);
                    for ( i = 0; i < v43; ++i )
                    {
                      if ( (*(_BYTE *)(v44 + 258) & 1) == 0
                        && (((*(_DWORD *)(a1 - 68) != 1) ^ *(unsigned __int8 *)(v44 + 256)) & 1) == 0 )
                      {
                        v49 = *(_QWORD *)(v44 + 96);
                        v48 = *(_QWORD *)(v44 + 104);
                        v50 = *(__int64 **)(v44 + 56);
                        v51 = *(_QWORD *)(v44 + 72) + v48 - v49;
                        v52 = v48 - v49 + *(_QWORD *)(v44 + 48);
                        *(_QWORD *)(v44 + 88) = v51;
                        *v50 = v52;
                        __dmb(0xAu);
                        raw_spin_lock_irq(v44 + 240);
                        mhi_ring_er_db((__int64 *)v44);
                        raw_spin_unlock_irq(v44 + 240);
                        v43 = *(_DWORD *)(a1 - 204);
                      }
                      v44 += 264;
                    }
                  }
                  raw_read_unlock_bh(a1 - 96);
                  mhi_process_sleeping_events(v8);
                  mhi_create_devices(v8);
                  mhi_misc_mission_mode(v8);
                  raw_read_lock_bh(a1 - 96);
                  v10 = a1 - 144;
                }
                v77 = *(_DWORD **)(a1 + 80);
                if ( *(v77 - 1) != 598874997 )
                  __break(0x8228u);
                ((void (__fastcall *)(unsigned __int64, _QWORD))v77)(v8, 0);
                raw_read_unlock_bh(a1 - 96);
              }
            }
            else
            {
              *(_DWORD *)(a1 - 80) = 4096;
              raw_write_unlock_irq(a1 - 96);
              _wake_up(a1 + 40, 3, 0, 0);
            }
          }
        }
        else if ( v19 )
        {
          if ( v19 == 1 )
            mhi_ready_state_transition(v8);
        }
        else
        {
          raw_write_lock_irq(a1 - 96);
          if ( (*(_WORD *)(a1 - 80) & 0xFDE) != 0 )
            *(_DWORD *)(a1 - 72) = mhi_get_exec_env(v8);
          raw_write_unlock_irq(a1 - 96);
          mhi_fw_load_handler(v8);
        }
        goto LABEL_6;
      }
      if ( v19 > 5 )
      {
        if ( v19 == 6 )
        {
          v46 = a1 - 416;
          v47 = 0;
          goto LABEL_83;
        }
        if ( v19 == 7 )
        {
          v46 = a1 - 416;
          v47 = 1;
LABEL_83:
          mhi_pm_disable_transition(v46, v47, v18);
        }
      }
      else
      {
        if ( v19 != 4 )
        {
          v95 = *v9;
          v20 = *(_QWORD *)(*v9 + 192);
          if ( v20 && !*(_DWORD *)(v20 + 24) )
          {
            v21 = *(_QWORD *)(v20 + 32);
            v22 = to_mhi_pm_state_str(*(_DWORD *)(a1 - 80));
            v23 = to_mhi_pm_state_str(0x200u);
            v24 = v21;
            v10 = a1 - 144;
            ipc_log_string(
              v24,
              "[D][%s] Transitioning from PM state: %s to: %s\n",
              "mhi_pm_sys_error_transition",
              v22,
              v23);
          }
          v25 = *(void (__fastcall **)(unsigned __int64, __int64, __int64))(a1 + 64);
          if ( *((_DWORD *)v25 - 1) != 1183736653 )
            __break(0x8228u);
          v25(v8, 6, v18);
          mutex_lock(v10);
          raw_write_lock_irq(a1 - 96);
          v26 = *(_DWORD *)(a1 - 80);
          v27 = mhi_tryset_pm_state(v8, 0x200u);
          raw_write_unlock_irq(a1 - 96);
          if ( v27 != 512 )
          {
            v92 = *(_QWORD *)(*v9 + 192);
            v78 = to_mhi_pm_state_str(v27);
            v79 = to_mhi_pm_state_str(0x200u);
            dev_err(
              v95 + 40,
              "[E][%s] Failed to transition from PM state: %s to: %s\n",
              "mhi_pm_sys_error_transition",
              v78,
              v79);
            v10 = a1 - 144;
            if ( v92 && *(_DWORD *)(v92 + 24) <= 2u )
            {
              v80 = *(_QWORD *)(v92 + 32);
              v81 = to_mhi_pm_state_str(v27);
              v82 = to_mhi_pm_state_str(0x200u);
              v83 = v80;
              v10 = a1 - 144;
              ipc_log_string(
                v83,
                "[E][%s] Failed to transition from PM state: %s to: %s\n",
                "mhi_pm_sys_error_transition",
                v81,
                v82);
            }
            goto LABEL_122;
          }
          *(_QWORD *)(a1 - 72) = 8;
          _wake_up(a1 + 40, 3, 0, 0);
          if ( (v26 & 0xFDE) != 0 )
          {
            v28 = *(unsigned int *)(a1 - 88);
            v101 = -1;
            v29 = _msecs_to_jiffies(v28);
            v30 = *v9;
            v31 = v29;
            v32 = *(_QWORD *)(*v9 + 192);
            if ( v32 && !*(_DWORD *)(v32 + 24) )
            {
              ipc_log_string(
                *(_QWORD *)(v32 + 32),
                "[D][%s] Triggering MHI Reset in device\n",
                "mhi_pm_sys_error_transition");
              v30 = *v9;
            }
            if ( (unsigned int)mhi_write_reg_field(v8, *v11, 0x38u) )
            {
              v94 = *(_QWORD *)(*v9 + 192);
              dev_err(v30 + 40, "[E][%s] Failed to set MHI state to: %s\n", "mhi_set_mhi_state", "RESET");
              if ( v94 )
              {
                if ( *(_DWORD *)(v94 + 24) <= 2u )
                  ipc_log_string(
                    *(_QWORD *)(v94 + 32),
                    "[E][%s] Failed to set MHI state to: %s\n",
                    "mhi_set_mhi_state",
                    "RESET");
              }
            }
            v33 = mhi_read_reg_field(v8, *v11, 56, 2, &v101);
            v34 = v101;
            if ( v33 )
              v35 = 1;
            else
              v35 = v101 == 0;
            v36 = v35;
            if ( ((unsigned __int8)v36 & (v31 == 0)) != 0 )
              v37 = 1;
            else
              v37 = v31;
            if ( (v36 & 1) == 0 && v37 )
            {
              memset(v100, 0, sizeof(v100));
              init_wait_entry(v100, 0);
              while ( 1 )
              {
                prepare_to_wait_event(a1 + 40, v100, 2);
                v38 = (unsigned int)mhi_read_reg_field(v8, *v11, 56, 2, &v101) || v101 == 0;
                v39 = v38;
                v37 = v39 && v31 == 0 ? 1LL : v31;
                if ( v39 || !v37 )
                  break;
                v31 = schedule_timeout(v37);
              }
              finish_wait(a1 + 40, v100);
              v34 = v101;
            }
            if ( !(_DWORD)v37 || v34 )
            {
              v90 = *(_QWORD *)(*v9 + 192);
              dev_err(v95 + 40, "[E][%s] Device failed to exit MHI Reset state\n", "mhi_pm_sys_error_transition");
              if ( v90 && *(_DWORD *)(v90 + 24) <= 2u )
                ipc_log_string(
                  *(_QWORD *)(v90 + 32),
                  "[E][%s] Device failed to exit MHI Reset state\n",
                  "mhi_pm_sys_error_transition");
              raw_write_lock_irq(a1 - 96);
              v91 = mhi_tryset_pm_state(v8, 0x400u);
              raw_write_unlock_irq(a1 - 96);
              if ( v91 != 1024 )
              {
                v10 = a1 - 144;
                goto LABEL_122;
              }
            }
            mhi_write_reg(v8);
          }
          v53 = *(_QWORD *)(*v9 + 192);
          if ( v53 && !*(_DWORD *)(v53 + 24) )
          {
            ipc_log_string(
              *(_QWORD *)(v53 + 32),
              "[D][%s] Waiting for all pending event ring processing to complete\n",
              "mhi_pm_sys_error_transition");
            if ( *(_DWORD *)(a1 - 204) )
              goto LABEL_93;
          }
          else if ( *(_DWORD *)(a1 - 204) )
          {
LABEL_93:
            v54 = 0;
            v55 = *(_QWORD *)(a1 - 168) + 168LL;
            do
            {
              if ( (*(_BYTE *)(v55 + 90) & 1) == 0 )
              {
                if ( *(_DWORD *)(v55 - 136) == 2 )
                  cancel_work_sync(v55 + 40);
                else
                  tasklet_kill(v55);
              }
              ++v54;
              v55 += 264;
            }
            while ( v54 < *(_DWORD *)(a1 - 204) );
          }
          v10 = a1 - 144;
          mutex_unlock(v97);
          mhi_misc_disable(v8);
          v56 = *(_QWORD *)(*v9 + 192);
          if ( v56 && !*(_DWORD *)(v56 + 24) )
            ipc_log_string(
              *(_QWORD *)(v56 + 32),
              "[D][%s] Waiting for all pending threads to complete\n",
              "mhi_pm_sys_error_transition");
          _wake_up(a1 + 40, 3, 0, 0);
          v57 = *v9;
          v58 = *(_QWORD *)(*v9 + 192);
          if ( v58 && !*(_DWORD *)(v58 + 24) )
          {
            ipc_log_string(
              *(_QWORD *)(v58 + 32),
              "[D][%s] Reset all active channels and remove MHI devices\n",
              "mhi_pm_sys_error_transition");
            v57 = *v9;
          }
          device_for_each_child(v57 + 40, 0, mhi_destroy_device);
          mutex_lock(v97);
          if ( *(_DWORD *)(a1 - 64) )
          {
            __break(0x800u);
            if ( !*(_DWORD *)(a1 - 60) )
              goto LABEL_108;
          }
          else if ( !*(_DWORD *)(a1 - 60) )
          {
LABEL_108:
            v59 = *(_QWORD *)(*v9 + 192);
            if ( v59 && !*(_DWORD *)(v59 + 24) )
              ipc_log_string(
                *(_QWORD *)(v59 + 32),
                "[D][%s] Resetting EV CTXT and CMD CTXT\n",
                "mhi_pm_sys_error_transition");
            v60 = *(_QWORD **)(a1 - 160);
            v61 = v60[4];
            v62 = *(_QWORD *)(*(_QWORD *)(a1 - 152) + 16LL);
            v60[5] = v61;
            v60[6] = v61;
            v63 = *(_QWORD *)(v62 + 12);
            *(_QWORD *)(v62 + 28) = v63;
            *(_QWORD *)(v62 + 36) = v63;
            v64 = *(_DWORD *)(a1 - 204);
            if ( v64 )
            {
              v65 = 0;
              v66 = (_BYTE *)(*(_QWORD *)(a1 - 168) + 258LL);
              v67 = (_QWORD *)(**(_QWORD **)(a1 - 152) + 28LL);
              do
              {
                if ( (*v66 & 1) == 0 )
                {
                  v68 = *(_QWORD *)(v66 - 186);
                  *(_QWORD *)(v66 - 178) = v68;
                  *(_QWORD *)(v66 - 170) = v68;
                  v69 = *(v67 - 2);
                  *v67 = v69;
                  v67[1] = v69;
                  v64 = *(_DWORD *)(a1 - 204);
                }
                ++v65;
                v66 += 264;
                v67 = (_QWORD *)((char *)v67 + 44);
              }
              while ( v65 < v64 );
            }
            if ( !(unsigned int)mhi_get_exec_env(v8)
              || (unsigned int)mhi_get_exec_env(v8) == 5
              || (unsigned int)mhi_get_exec_env(v8) == 6 )
            {
              raw_write_lock_irq(a1 - 96);
              v70 = mhi_tryset_pm_state(v8, 2u);
              raw_write_unlock_irq(a1 - 96);
              if ( v70 == 2 )
              {
                v71 = 0;
                goto LABEL_121;
              }
              v93 = *(_QWORD *)(*v9 + 192);
              v84 = to_mhi_pm_state_str(2u);
              v85 = to_mhi_pm_state_str(v70);
              v86 = v84;
              v10 = a1 - 144;
              dev_err(v95 + 40, "[E][%s] Error moving to state %s from %s\n", "mhi_pm_sys_error_transition", v86, v85);
              if ( v93 && *(_DWORD *)(v93 + 24) <= 2u )
              {
                v96 = *(_QWORD *)(v93 + 32);
                v87 = to_mhi_pm_state_str(2u);
                v88 = to_mhi_pm_state_str(v70);
                v89 = v87;
                v10 = a1 - 144;
                ipc_log_string(
                  v96,
                  "[E][%s] Error moving to state %s from %s\n",
                  "mhi_pm_sys_error_transition",
                  v89,
                  v88);
              }
            }
            else
            {
              v71 = 1;
LABEL_121:
              mhi_queue_state_transition(v8, v71);
            }
LABEL_122:
            v72 = *(_QWORD *)(*v9 + 192);
            if ( v72 && !*(_DWORD *)(v72 + 24) )
            {
              v73 = *(_QWORD *)(v72 + 32);
              v74 = to_mhi_pm_state_str(*(_DWORD *)(a1 - 80));
              v75 = *(_DWORD *)(a1 - 68);
              if ( v75 <= 3 )
              {
                if ( v75 > 1 )
                {
                  if ( v75 == 2 )
                    v76 = "M0";
                  else
                    v76 = "M1";
                }
                else
                {
                  v76 = "RESET";
                  if ( v75 )
                  {
                    if ( v75 != 1 )
                      goto LABEL_161;
                    v76 = "READY";
                  }
                }
              }
              else if ( v75 <= 5 )
              {
                if ( v75 == 4 )
                  v76 = "M2";
                else
                  v76 = "M3";
              }
              else
              {
                switch ( v75 )
                {
                  case 6:
                    v76 = "M3_FAST";
                    break;
                  case 7:
                    v76 = "BHI";
                    break;
                  case 255:
                    v76 = "SYS ERROR";
                    break;
                  default:
LABEL_161:
                    v76 = "Unknown state";
                    break;
                }
              }
              ipc_log_string(
                v73,
                "[D][%s] Exiting with PM state: %s, MHI state: %s\n",
                "mhi_pm_sys_error_transition",
                v74,
                v76);
            }
            mutex_unlock(v10);
            goto LABEL_6;
          }
          __break(0x800u);
          goto LABEL_108;
        }
        raw_write_lock_irq(a1 - 96);
        *(_DWORD *)(a1 - 72) = 7;
        raw_write_unlock_irq(a1 - 96);
        mhi_create_devices(v8);
      }
LABEL_6:
      result = kfree(v12);
    }
    while ( v7 != &v98 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
