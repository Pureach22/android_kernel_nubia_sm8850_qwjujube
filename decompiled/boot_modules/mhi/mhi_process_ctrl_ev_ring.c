__int64 __fastcall mhi_process_ctrl_ev_ring(__int64 a1, __int64 *a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w21
  __int64 v4; // x12
  __int64 v7; // x24
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x9
  unsigned __int64 *v10; // x24
  unsigned __int64 v11; // t1
  unsigned __int64 v12; // x10
  __int64 v13; // x9
  __int64 *v14; // x26
  int v15; // w27
  __int64 v16; // x10
  int v17; // w27
  __int64 v18; // x8
  void (__fastcall *v19)(__int64, __int64); // x8
  _QWORD *v20; // x25
  unsigned __int64 v21; // x9
  __int64 v22; // x28
  unsigned __int64 v23; // x10
  unsigned __int64 v24; // x8
  unsigned int *v25; // x2
  unsigned int *v26; // x27
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x25
  __int64 v30; // x8
  unsigned int v31; // w27
  unsigned __int64 v32; // x25
  __int64 v33; // x8
  const char *v34; // x3
  unsigned int v35; // w8
  __int64 v36; // x22
  unsigned __int64 v37; // x27
  __int64 v38; // x22
  unsigned __int64 v39; // x8
  __int64 v40; // x1
  const char *v41; // x3
  __int64 v42; // x8
  int v43; // w26
  void (__fastcall *v44)(__int64, __int64); // x8
  __int64 v45; // x10
  unsigned __int64 v46; // x8
  _QWORD *v47; // x9
  __int64 v48; // x11
  unsigned __int64 v49; // x8
  unsigned __int64 v50; // x9
  __int64 v51; // x22
  __int64 v52; // x22
  __int64 v53; // x22
  unsigned __int64 v54; // x26
  const char *v55; // x3
  __int64 v56; // x25
  __int64 v57; // x27
  const char *v58; // x0
  void (__fastcall *v59)(__int64, __int64 *, __int64, __int64); // x9
  __int64 v60; // x0
  __int64 v61; // x2
  __int64 v62; // x3
  __int64 v64; // x19
  __int64 v65; // x19
  __int64 v66; // [xsp+8h] [xbp-8h]

  v2 = *(_DWORD *)(a1 + 336);
  v3 = -5;
  if ( v2 == 1 || v2 > 0x7F )
    return v3;
  v4 = *(_QWORD *)(a1 + 16);
  v7 = **(_QWORD **)(a1 + 264) + 44LL * *((unsigned int *)a2 + 4);
  v8 = a2[6];
  v11 = *(_QWORD *)(v7 + 28);
  v10 = (unsigned __int64 *)(v7 + 28);
  v9 = v11;
  v12 = v11 - v8;
  if ( v11 < v8 || (v9 & 0xF) != 0 || a2[13] + v8 <= v9 )
  {
    v64 = *(_QWORD *)(v4 + 192);
    dev_err(v4 + 40, "[E][%s] Event ring rp points outside of the event ring\n", "mhi_process_ctrl_ev_ring");
    if ( v64 && *(_DWORD *)(v64 + 24) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v64 + 32),
        "[E][%s] Event ring rp points outside of the event ring\n",
        "mhi_process_ctrl_ev_ring");
  }
  else
  {
    v13 = a2[9];
    v14 = (__int64 *)a2[10];
    if ( (__int64 *)(v13 + v12) != v14 )
    {
      v3 = 0;
      _ReadStatusReg(SP_EL0);
      v66 = v4;
      while ( 1 )
      {
        v15 = *((_DWORD *)v14 + 3);
        v16 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        if ( v16 && !*(_DWORD *)(v16 + 24) )
          ipc_log_string(
            *(_QWORD *)(v16 + 32),
            "[D][%s] RP:0x%llx Processing Event:0x%llx 0x%08x 0x%08x\n",
            "mhi_process_ctrl_ev_ring",
            (char *)v14 + v8 - v13,
            *v14,
            *((_DWORD *)v14 + 2),
            v15);
        v17 = BYTE2(v15);
        if ( v17 <= 33 )
        {
          if ( v17 == 32 )
          {
            v29 = *((unsigned int *)v14 + 2);
            v30 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
            v31 = BYTE3(v29);
            if ( v30 && !*(_DWORD *)(v30 + 24) )
            {
              v41 = "Unknown state";
              if ( (unsigned __int8)(HIBYTE(*((_DWORD *)v14 + 2)) + 1) <= 8u )
                v41 = off_20628[(unsigned __int8)(HIBYTE(*((_DWORD *)v14 + 2)) + 1)];
              ipc_log_string(
                *(_QWORD *)(v30 + 32),
                "[D][%s] State change event to state: %s\n",
                "mhi_process_ctrl_ev_ring",
                v41);
              if ( BYTE3(v29) <= 4u )
              {
LABEL_36:
                if ( v31 == 2 )
                {
                  mhi_pm_m0_transition(a1);
                  goto LABEL_78;
                }
                if ( v31 == 3 )
                {
                  mhi_pm_m1_transition(a1);
                  goto LABEL_78;
                }
LABEL_96:
                v54 = v29 >> 24;
                v55 = "Unknown state";
                if ( v31 <= 7 )
                  v55 = off_20670[v54];
                v56 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
                dev_err(v66 + 40, "[E][%s] Invalid state: %s\n", "mhi_process_ctrl_ev_ring", v55);
                if ( v56 && *(_DWORD *)(v56 + 24) <= 2u )
                {
                  v57 = *(_QWORD *)(v56 + 32);
                  v58 = mhi_state_str(v54);
                  ipc_log_string(v57, "[E][%s] Invalid state: %s\n", "mhi_process_ctrl_ev_ring", v58);
                }
                goto LABEL_78;
              }
            }
            else if ( BYTE3(v29) <= 4u )
            {
              goto LABEL_36;
            }
            if ( v31 == 5 )
            {
              mhi_pm_m3_transition(a1);
              goto LABEL_78;
            }
            if ( v31 != 255 )
              goto LABEL_96;
            v42 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
            if ( v42 && !*(_DWORD *)(v42 + 24) )
              ipc_log_string(*(_QWORD *)(v42 + 32), "[D][%s] System error detected\n", "mhi_process_ctrl_ev_ring");
            raw_write_lock_irq(a1 + 320);
            v43 = mhi_tryset_pm_state(a1, 256);
            raw_write_unlock_irq(a1 + 320);
            if ( v43 == 256 )
              mhi_pm_sys_err_handler(a1);
          }
          else
          {
            if ( v17 != 33 )
              goto LABEL_90;
            v20 = *(_QWORD **)(a1 + 256);
            v21 = *v14;
            v22 = *(_QWORD *)(a1 + 16);
            v23 = v20[1];
            v24 = *v14 - v23;
            if ( *v14 < v23 || (v21 & 0xF) != 0 || v20[8] + v23 <= v21 )
            {
              v51 = *(_QWORD *)(v22 + 192);
              dev_err(v22 + 40, "[E][%s] Event element points outside of the cmd ring\n", "mhi_process_cmd_completion");
              if ( v51 && *(_DWORD *)(v51 + 24) <= 2u )
                ipc_log_string(
                  *(_QWORD *)(v51 + 32),
                  "[E][%s] Event element points outside of the cmd ring\n",
                  "mhi_process_cmd_completion");
            }
            else
            {
              v25 = (unsigned int *)v20[5];
              v26 = (unsigned int *)(v20[4] + v24);
              if ( v26 != v25 )
              {
                _warn_printk("Out of order cmd completion: 0x%pK. Expected: 0x%pK\n", (const void *)(v20[4] + v24), v25);
                __break(0x800u);
              }
              v27 = v26[3];
              if ( (v27 & 0xFF0000) == 0x490000 )
              {
                mhi_misc_cmd_completion(a1, 73, *((unsigned __int8 *)v14 + 11));
              }
              else
              {
                v37 = v27 >> 24;
                if ( (unsigned int)(v27 >> 24) < *(_DWORD *)(a1 + 208)
                  && (v38 = *(_QWORD *)(a1 + 176) + 400LL * (unsigned int)v37, *(_BYTE *)(v38 + 393) == 1) )
                {
                  raw_write_lock_bh(v38 + 368);
                  *(_DWORD *)(v38 + 264) = *((unsigned __int8 *)v14 + 11);
                  complete(v38 + 336);
                  raw_write_unlock_bh(v38 + 368);
                }
                else
                {
                  v53 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
                  dev_err(
                    v22 + 40,
                    "[E][%s] Completion packet for invalid channel ID: %d\n",
                    "mhi_process_cmd_completion",
                    v37);
                  if ( v53 && *(_DWORD *)(v53 + 24) <= 2u )
                    ipc_log_string(
                      *(_QWORD *)(v53 + 32),
                      "[E][%s] Completion packet for invalid channel ID: %d\n",
                      "mhi_process_cmd_completion",
                      v37);
                }
              }
              v39 = v20[5] + v20[7];
              if ( v39 >= v20[4] + v20[8] )
                v39 = v20[4];
              v20[5] = v39;
              __dmb(0xAu);
            }
          }
        }
        else
        {
          switch ( v17 )
          {
            case '"':
              v28 = (unsigned __int64)*((unsigned int *)v14 + 3) >> 24;
              if ( (unsigned int)v28 < *(_DWORD *)(a1 + 208)
                || (__break(0x800u), (unsigned int)v28 < *(_DWORD *)(a1 + 208)) )
              {
                if ( *(_BYTE *)(*(_QWORD *)(a1 + 176) + 400LL * (unsigned int)v28 + 393) == 1 )
                  parse_xfer_event(a1, v14);
              }
              break;
            case '@':
              v32 = *((unsigned int *)v14 + 2);
              v33 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
              if ( v33 && !*(_DWORD *)(v33 + 24) )
              {
                v34 = "INVALID_EE";
                if ( (unsigned int)v32 >> 25 <= 4 )
                  v34 = mhi_ee_str[v32 >> 24];
                ipc_log_string(
                  *(_QWORD *)(v33 + 32),
                  "[D][%s] Received EE event: %s\n",
                  "mhi_process_ctrl_ev_ring",
                  v34);
              }
              v35 = BYTE3(v32);
              if ( BYTE3(v32) <= 2u )
              {
                if ( v35 == 1 )
                {
                  v40 = 2;
                  goto LABEL_77;
                }
                if ( v35 == 2 )
                {
LABEL_59:
                  v40 = 3;
LABEL_77:
                  mhi_queue_state_transition(a1, v40);
                  break;
                }
                goto LABEL_48;
              }
              if ( v35 != 3 )
              {
                if ( v35 == 7 )
                {
                  v40 = 4;
                  goto LABEL_77;
                }
                if ( v35 == 4 )
                  goto LABEL_59;
LABEL_48:
                v36 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
                dev_err(v66 + 40, "[E][%s] Unhandled EE event: 0x%x\n", "mhi_process_ctrl_ev_ring", 64);
                if ( v36 && *(_DWORD *)(v36 + 24) <= 2u )
                  ipc_log_string(
                    *(_QWORD *)(v36 + 32),
                    "[E][%s] Unhandled EE event: 0x%x\n",
                    "mhi_process_ctrl_ev_ring",
                    64);
                break;
              }
              v44 = *(void (__fastcall **)(__int64, __int64))(a1 + 480);
              if ( *((_DWORD *)v44 - 1) != 1183736653 )
                __break(0x8228u);
              v44(a1, 4);
              raw_write_lock_irq(a1 + 320);
              *(_DWORD *)(a1 + 344) = 3;
              raw_write_unlock_irq(a1 + 320);
              _wake_up(a1 + 456, 3, 0, 0);
              break;
            case 'P':
              raw_write_lock_irq(a1 + 320);
              *(_DWORD *)(a1 + 400) = *((unsigned __int8 *)v14 + 15);
              *(_DWORD *)(a1 + 404) = *((unsigned __int8 *)v14 + 8);
              raw_write_unlock_irq(a1 + 320);
              v18 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
              if ( v18 && !*(_DWORD *)(v18 + 24) )
                ipc_log_string(*(_QWORD *)(v18 + 32), "[D][%s] Received BW_REQ event\n", "mhi_process_ctrl_ev_ring");
              v19 = *(void (__fastcall **)(__int64, __int64))(a1 + 480);
              if ( *((_DWORD *)v19 - 1) != 1183736653 )
                __break(0x8228u);
              v19(a1, 8);
              break;
            default:
LABEL_90:
              v52 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
              dev_err(v66 + 40, "[E][%s] Unhandled event type: %d\n", "mhi_process_ctrl_ev_ring", v17);
              if ( v52 && *(_DWORD *)(v52 + 24) <= 2u )
                ipc_log_string(
                  *(_QWORD *)(v52 + 32),
                  "[E][%s] Unhandled event type: %d\n",
                  "mhi_process_ctrl_ev_ring",
                  (unsigned int)v17);
              break;
          }
        }
LABEL_78:
        v45 = a2[9];
        v46 = a2[11] + a2[12];
        v48 = a2[6];
        v47 = (_QWORD *)a2[7];
        if ( v46 >= v45 + a2[13] )
          v46 = a2[9];
        a2[11] = v46;
        *v47 = v48 - v45 + v46;
        v49 = a2[10] + a2[12];
        if ( v49 >= a2[9] + a2[13] )
          v49 = a2[9];
        a2[10] = v49;
        __dmb(0xAu);
        v50 = *v10;
        v8 = a2[6];
        if ( *v10 < v8 || (v50 & 0xF) != 0 || a2[13] + v8 <= v50 )
        {
          v65 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
          dev_err(v66 + 40, "[E][%s] Event ring rp points outside of the event ring\n", "mhi_process_ctrl_ev_ring");
          if ( v65 && *(_DWORD *)(v65 + 24) <= 2u )
            ipc_log_string(
              *(_QWORD *)(v65 + 32),
              "[E][%s] Event ring rp points outside of the event ring\n",
              "mhi_process_ctrl_ev_ring");
          return (unsigned int)-5;
        }
        v13 = a2[9];
        v14 = (__int64 *)a2[10];
        ++v3;
        if ( (__int64 *)(v13 + *v10 - v8) == v14 )
          goto LABEL_104;
      }
    }
    v3 = 0;
LABEL_104:
    raw_read_lock_bh(a1 + 320);
    if ( (*(_DWORD *)(a1 + 340) & *(_DWORD *)(a1 + 336)) != 0 && v3 )
    {
      v59 = (void (__fastcall *)(__int64, __int64 *, __int64, __int64))a2[20];
      v60 = *a2;
      v61 = a2[16];
      v62 = *(_QWORD *)a2[7];
      if ( *((_DWORD *)v59 - 1) != -396405511 )
        __break(0x8229u);
      v59(v60, a2 + 17, v61, v62);
    }
    raw_read_unlock_bh(a1 + 320);
  }
  return v3;
}
