__int64 __fastcall dp_hdcp2p2_main(int *a1)
{
  __int64 should_park; // x0
  char *v3; // x27
  int *v4; // x24
  __int64 *v5; // x28
  __int64 v6; // x0
  int v7; // w6
  int v8; // w7
  unsigned int v9; // w8
  int v10; // w9
  int v11; // w8
  __int64 v12; // x0
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x1
  __int64 v15; // x8
  __int64 (__fastcall **v16)(_QWORD); // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 *v19; // x24
  char *v20; // x20
  __int64 v21; // x0
  __int64 v22; // x25
  int v23; // w28
  unsigned int v24; // w23
  __int64 v25; // x0
  int v26; // w21
  __int64 v27; // x0
  int v28; // w27
  int v29; // w8
  int v30; // w7
  char v31; // w8
  __int64 (__fastcall **v32)(_QWORD); // x9
  __int64 (__fastcall *v33)(_QWORD); // x9
  __int64 v34; // x0
  unsigned int *v35; // x23
  __int64 v36; // x22
  int v37; // w25
  int v38; // w0
  unsigned int v39; // t1
  __int64 v40; // x8
  int *v41; // x9
  int v42; // w10
  int v43; // w8
  int v44; // w9
  __int64 (__fastcall *v45)(_QWORD); // x8
  __int64 v46; // x0
  const char *v47; // x3
  __int64 v48; // x0
  __int64 v49; // x0
  void *v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 ipc_log_context; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  const char *v61; // x3
  char v63; // [xsp+0h] [xbp-60h]
  char v64; // [xsp+0h] [xbp-60h]
  unsigned __int64 StatusReg; // [xsp+18h] [xbp-48h]
  struct sched_param param; // [xsp+24h] [xbp-3Ch] BYREF
  int v67[2]; // [xsp+28h] [xbp-38h] BYREF
  __int64 v68; // [xsp+30h] [xbp-30h]
  __int64 v69; // [xsp+38h] [xbp-28h]
  __int64 v70; // [xsp+40h] [xbp-20h]
  __int64 v71; // [xsp+48h] [xbp-18h]
  __int64 v72; // [xsp+50h] [xbp-10h]
  __int64 v73; // [xsp+58h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  param.__sched_priority = 16;
  StatusReg = _ReadStatusReg(SP_EL0);
  should_park = sched_setscheduler(StatusReg, 1, &param);
  if ( (_DWORD)should_park )
    should_park = printk(&unk_21814B, (unsigned int)should_park);
  v3 = "dp_hdcp2p2_send_msg";
  v4 = a1 + 6;
  v5 = &qword_294000;
  while ( 1 )
  {
    if ( *a1 == a1[1] )
    {
      should_park = ((__int64 (*)(void))kthread_should_stop)();
      if ( (should_park & 1) == 0 )
      {
        should_park = kthread_should_park();
        if ( (should_park & 1) == 0 )
        {
          v70 = 0;
          v71 = 0;
          v68 = 0;
          v69 = 0;
          *(_QWORD *)v67 = 0;
          init_wait_entry(v67, 0);
          while ( 1 )
          {
            v6 = prepare_to_wait_event(a1 + 14, v67, 1026);
            if ( *a1 != a1[1] || (kthread_should_stop(v6) & 1) != 0 || (kthread_should_park() & 1) != 0 )
              break;
            schedule();
          }
          should_park = finish_wait(a1 + 14, v67);
        }
      }
    }
    should_park = kthread_should_stop(should_park);
    if ( (should_park & 1) != 0 )
      break;
    v10 = *a1;
    v9 = a1[1];
    if ( *a1 == v9 )
    {
      should_park = kthread_should_park();
      if ( (should_park & 1) == 0 )
      {
        v10 = *a1;
        v9 = a1[1];
        goto LABEL_18;
      }
      should_park = kthread_parkme();
    }
    else
    {
LABEL_18:
      if ( v10 != v9 )
      {
        v11 = v4[a1[2] & v9];
        __dmb(0xAu);
        ++a1[1];
        if ( v11 <= 3 )
        {
          switch ( v11 )
          {
            case 1:
              v17 = v5[191];
              v71 = 0;
              v72 = 0;
              v69 = 0;
              v70 = 0;
              *(_QWORD *)v67 = 0;
              v68 = 0;
              v18 = sde_evtlog_log(v17, v3, 496, 8, 4369, -1059143953, v7, v8, v63);
              if ( a1 )
              {
                v68 = *((_QWORD *)a1 + 43);
                if ( !a1[20] )
                {
                  ipc_log_context = get_ipc_log_context(v18);
                  ipc_log_string(ipc_log_context, "[e][%-4d]hdcp is off\n", *(_DWORD *)(StatusReg + 1800));
                  printk(&unk_26B1C7, v3);
                  v31 = 1;
                  v32 = *((__int64 (__fastcall ***)(_QWORD))a1 + 44);
                  if ( !v32 )
                    goto LABEL_52;
                  goto LABEL_46;
                }
                v19 = v5;
                v20 = v3;
                v21 = mutex_lock(a1 + 72);
                v22 = *((_QWORD *)a1 + 46);
                v23 = a1[94];
                v24 = a1[106];
                v25 = get_ipc_log_context(v21);
                ipc_log_string(v25, "[d][%-4d]offset(0x%x), size(%d)\n", *(_DWORD *)(StatusReg + 1800), v24, v23);
                if ( (_drm_debug & 4) != 0 )
                  _drm_dev_dbg(
                    0,
                    0,
                    0,
                    "[msm-dp-debug][%-4d]offset(0x%x), size(%d)\n",
                    *(_DWORD *)(StatusReg + 1800),
                    v24,
                    v23);
                while ( 1 )
                {
                  v26 = v23 >= 16 ? 16 : v23;
                  v27 = drm_dp_dpcd_write(*((_QWORD *)a1 + 21), v24, v22, v26);
                  v28 = v27;
                  if ( v26 != (_DWORD)v27 )
                    break;
                  v23 -= v26;
                  v22 += v26;
                  v24 += v26;
                  if ( v23 <= 0 )
                  {
                    v29 = a1[101];
                    v67[0] = 6;
                    HIDWORD(v69) = v29;
                    mutex_unlock(a1 + 72);
                    v5 = v19;
                    v4 = a1 + 6;
                    v3 = v20;
                    goto LABEL_45;
                  }
                }
                v54 = get_ipc_log_context(v27);
                ipc_log_string(
                  v54,
                  "[e][%-4d]fail: offset(0x%x), size(0x%x), rc(0x%x)\n",
                  *(_DWORD *)(StatusReg + 1800),
                  v24,
                  v26,
                  v28);
                printk(&unk_237139, "dp_hdcp2p2_aux_write_message");
                v5 = v19;
                v55 = sde_evtlog_log(v19[191], "dp_hdcp2p2_aux_write_message", 444, 8, 4369, v24, v26, v28, 239);
                v56 = get_ipc_log_context(v55);
                ipc_log_string(v56, "[e][%-4d]Error sending msg to sink %d\n", *(_DWORD *)(StatusReg + 1800), -22);
                v3 = v20;
                printk(&unk_214811, v20);
                mutex_unlock(a1 + 72);
                v4 = a1 + 6;
              }
              else
              {
                v51 = get_ipc_log_context(v18);
                ipc_log_string(v51, "[e][%-4d]invalid input\n", *(_DWORD *)(StatusReg + 1800));
                printk(&unk_275B6D, v3);
              }
              v67[0] = 7;
              msleep(1000);
              if ( !a1 )
                goto LABEL_52;
LABEL_45:
              v31 = 0;
              v32 = *((__int64 (__fastcall ***)(_QWORD))a1 + 44);
              if ( !v32 )
                goto LABEL_52;
LABEL_46:
              v33 = *v32;
              if ( !v33 )
                v31 = 1;
              if ( (v31 & 1) == 0 )
              {
                if ( *((_DWORD *)v33 - 1) != -417196079 )
                  __break(0x8229u);
                v34 = v33(v67);
                if ( (_DWORD)v34 )
                {
                  v60 = get_ipc_log_context(v34);
                  v61 = "UNKNOWN";
                  if ( (unsigned int)(v67[0] - 3) <= 0xD )
                    v61 = off_27FCA0[v67[0] - 3];
                  ipc_log_string(v60, "[e][%-4d]error sending %s to lib\n", *(_DWORD *)(StatusReg + 1800), v61);
                  printk(&unk_24E728, "dp_hdcp2p2_wakeup_lib");
                }
              }
LABEL_52:
              should_park = sde_evtlog_log(v5[191], v3, 539, 8, 8738, v67[0], -1059143953, v30, v64);
              break;
            case 2:
              if ( *((_BYTE *)a1 + 481) )
              {
                *((_BYTE *)a1 + 483) = 1;
              }
              else if ( a1[20] )
              {
                v48 = (unsigned int)a1[101];
                if ( (_DWORD)v48 )
                  msleep(v48);
                should_park = dp_hdcp2p2_get_msg_from_sink(a1);
              }
              else
              {
                v59 = get_ipc_log_context(should_park);
                ipc_log_string(v59, "[e][%-4d]hdcp is off\n", *(_DWORD *)(StatusReg + 1800));
                should_park = printk(&unk_26B1C7, "dp_hdcp2p2_recv_msg");
              }
              break;
            case 3:
              goto LABEL_26;
          }
        }
        else if ( v11 > 5 )
        {
          if ( v11 == 6 )
          {
            v71 = 0;
            v72 = 0;
            v69 = 0;
            v70 = 0;
            *(_QWORD *)v67 = 0;
            v68 = 0;
            if ( a1 )
            {
              if ( a1[20] == 3 || !a1[20] )
              {
                v49 = get_ipc_log_context(should_park);
                ipc_log_string(v49, "[e][%-4d]invalid hdcp state\n", *(_DWORD *)(StatusReg + 1800));
                v50 = &unk_275BDA;
                goto LABEL_90;
              }
              v43 = *((unsigned __int8 *)a1 + 480);
              v44 = *((unsigned __int8 *)a1 + 482);
              v68 = *((_QWORD *)a1 + 43);
              if ( (v44 & v43) != 0 )
              {
                if ( (v43 & 8) != 0 )
                {
                  v57 = get_ipc_log_context(should_park);
                  ipc_log_string(v57, "[w][%-4d]reauth_req set by sink\n", *(_DWORD *)(StatusReg + 1800));
                  should_park = printk(&unk_210BFB, "dp_hdcp2p2_link_check");
                  if ( (a1[120] & 0x10) != 0 )
                  {
LABEL_97:
                    v58 = get_ipc_log_context(should_park);
                    ipc_log_string(v58, "[w][%-4d]link failure reported by sink\n", *(_DWORD *)(StatusReg + 1800));
                    should_park = printk(&unk_21484B, "dp_hdcp2p2_link_check");
                  }
                }
                else if ( (v43 & 0x10) != 0 )
                {
                  goto LABEL_97;
                }
                *((_WORD *)a1 + 240) = 0;
                v67[0] = 13;
                a1[20] = 3;
                v16 = *((__int64 (__fastcall ***)(_QWORD))a1 + 44);
                if ( v16 )
                {
LABEL_71:
                  v45 = *v16;
                  if ( v45 )
                  {
                    if ( *((_DWORD *)v45 - 1) != -417196079 )
                      __break(0x8228u);
                    should_park = v45(v67);
                    if ( (_DWORD)should_park )
                    {
                      v46 = get_ipc_log_context(should_park);
                      v47 = "UNKNOWN";
                      if ( (unsigned int)(v67[0] - 3) <= 0xD )
                        v47 = off_27FCA0[v67[0] - 3];
                      ipc_log_string(v46, "[e][%-4d]error sending %s to lib\n", *(_DWORD *)(StatusReg + 1800), v47);
                      should_park = printk(&unk_24E728, "dp_hdcp2p2_wakeup_lib");
                    }
                  }
                }
              }
              else if ( *((_BYTE *)a1 + 483) == 1 && (*((_BYTE *)a1 + 481) & (unsigned __int8)v43) != 0 )
              {
                *((_WORD *)a1 + 240) = 0;
                should_park = dp_hdcp2p2_get_msg_from_sink(a1);
                *((_BYTE *)a1 + 483) = 0;
              }
            }
            else
            {
              v52 = get_ipc_log_context(should_park);
              ipc_log_string(v52, "[e][%-4d]invalid input\n", *(_DWORD *)(StatusReg + 1800));
              v50 = &unk_275B6D;
LABEL_90:
              should_park = printk(v50, "dp_hdcp2p2_link_check");
            }
          }
          else if ( v11 == 7 )
          {
            v15 = *((_QWORD *)a1 + 43);
            v71 = 0;
            v72 = 0;
            v69 = 0;
            v70 = 0;
            v67[1] = 0;
            v68 = v15;
            v67[0] = 4;
            if ( a1 )
            {
              if ( a1[20] == 1 )
              {
                v16 = *((__int64 (__fastcall ***)(_QWORD))a1 + 44);
                if ( v16 )
                  goto LABEL_71;
              }
            }
          }
        }
        else if ( v11 == 4 )
        {
          v35 = *((unsigned int **)a1 + 12);
          v36 = *(_QWORD *)(*((_QWORD *)a1 + 15) + 8LL);
          if ( !a1[21] && v35 )
          {
            do
            {
              v40 = *v35;
              if ( !(_DWORD)v40 )
                break;
              v41 = *((int **)v35 + 1);
              if ( v41 )
              {
                v37 = 0;
                do
                {
                  v42 = *v41;
                  if ( !*v41 )
                    break;
                  v41 += 6;
                  v37 |= v42;
                }
                while ( v41 );
              }
              else
              {
                v37 = 0;
              }
              v38 = readl_relaxed(v36 + v40);
              v39 = *v35;
              v35 += 4;
              writel_relaxed(v38 & (unsigned int)~v37, v36 + v39);
            }
            while ( v35 );
          }
LABEL_26:
          v12 = *((_QWORD *)a1 + 24);
          v13 = *((__int64 (__fastcall **)(__int64, __int64))a1 + 25);
          v14 = (unsigned int)a1[20];
          if ( *((_DWORD *)v13 - 1) != -815732472 )
            __break(0x8228u);
          should_park = v13(v12, v14);
        }
        else
        {
          *((_BYTE *)a1 + 483) = 1;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
