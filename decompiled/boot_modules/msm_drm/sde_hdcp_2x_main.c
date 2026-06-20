__int64 __fastcall sde_hdcp_2x_main(int *a1)
{
  __int64 v1; // x27
  __int64 should_stop; // x0
  int *v4; // x20
  char *v5; // x22
  _QWORD *v6; // x21
  char *v7; // x23
  __int64 *v8; // x28
  __int64 v9; // x0
  int v10; // w7
  unsigned int v11; // w8
  int v12; // w9
  int v13; // w8
  _QWORD *v14; // x24
  int *v15; // x25
  __int64 v16; // x20
  __int64 *v17; // x27
  char *v18; // x28
  char *v19; // x23
  char v20; // w26
  _QWORD *v21; // x22
  _QWORD *v22; // x8
  __int64 v23; // x9
  int v24; // w8
  __int64 v25; // x0
  int v26; // w5
  int v27; // w8
  char *v28; // x24
  char *v29; // x23
  _BYTE *v30; // x22
  int v31; // w9
  __int64 v32; // x9
  __int64 v33; // x8
  unsigned int v34; // w10
  int v35; // w7
  __int64 v36; // x0
  int v37; // w5
  char *v38; // x1
  int v39; // w2
  __int64 v40; // x8
  __int64 v41; // x0
  int v42; // w5
  int v43; // w6
  _BYTE *v44; // x8
  int v45; // w9
  __int64 v46; // x8
  __int64 v47; // x8
  __int64 v48; // x0
  int v49; // w0
  int v50; // w9
  int v51; // w8
  __int64 v52; // x9
  unsigned int v53; // w8
  int v54; // w10
  _BYTE *v55; // x8
  __int64 v56; // x9
  unsigned int v57; // w10
  __int64 v58; // x8
  __int64 v59; // x9
  int v60; // w8
  __int64 v61; // x9
  int v62; // w10
  bool v63; // zf
  char v64; // w9
  __int64 v65; // x9
  unsigned int v66; // w10
  int v67; // w8
  __int64 v68; // x9
  char v70; // [xsp+0h] [xbp-70h]
  struct sched_param param; // [xsp+4h] [xbp-6Ch] BYREF
  _QWORD v72[2]; // [xsp+8h] [xbp-68h] BYREF
  __int64 v73; // [xsp+18h] [xbp-58h]
  __int64 v74; // [xsp+20h] [xbp-50h]
  __int64 v75; // [xsp+28h] [xbp-48h]
  __int64 v76; // [xsp+30h] [xbp-40h]
  __int64 v77; // [xsp+38h] [xbp-38h] BYREF
  __int64 v78; // [xsp+40h] [xbp-30h]
  __int64 v79; // [xsp+48h] [xbp-28h]
  unsigned __int64 v80; // [xsp+50h] [xbp-20h]
  __int64 v81; // [xsp+58h] [xbp-18h]
  __int64 v82; // [xsp+60h] [xbp-10h]
  __int64 v83; // [xsp+68h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  param.__sched_priority = 16;
  should_stop = sched_setscheduler(_ReadStatusReg(SP_EL0), 1, &param);
  if ( (_DWORD)should_stop )
    should_stop = printk(&unk_25CECB, "sde_hdcp_2x_main");
  v4 = a1 + 6;
  v5 = "sde_hdcp_2x_start_auth";
  v6 = a1 + 48;
  v7 = "sde_hdcp_2x_msg_sent";
  v8 = &qword_294000;
  while ( 1 )
  {
    if ( *a1 == a1[1] )
    {
      should_stop = kthread_should_stop(should_stop);
      if ( (should_stop & 1) == 0 )
      {
        should_stop = kthread_should_park();
        if ( (should_stop & 1) == 0 )
        {
          v80 = 0;
          v81 = 0;
          v78 = 0;
          v79 = 0;
          v77 = 0;
          init_wait_entry(&v77, 0);
          while ( 1 )
          {
            v9 = prepare_to_wait_event(a1 + 14, &v77, 1026);
            if ( *a1 != a1[1] || (kthread_should_stop(v9) & 1) != 0 || (kthread_should_park() & 1) != 0 )
              break;
            schedule();
          }
          should_stop = finish_wait(a1 + 14, &v77);
        }
      }
    }
    should_stop = kthread_should_stop(should_stop);
    if ( (should_stop & 1) != 0 )
      break;
    v12 = *a1;
    v11 = a1[1];
    if ( *a1 == v11 )
    {
      should_stop = kthread_should_park();
      if ( (should_stop & 1) == 0 )
      {
        v12 = *a1;
        v11 = a1[1];
        goto LABEL_18;
      }
      should_stop = kthread_parkme();
    }
    else
    {
LABEL_18:
      if ( v12 != v11 )
      {
        v13 = v4[a1[2] & v11];
        __dmb(0xAu);
        ++a1[1];
        switch ( v13 )
        {
          case 1:
            if ( a1 && !*((_QWORD *)a1 + 19) )
            {
              should_stop = hdcp2_init((unsigned int)a1[45]);
              *((_QWORD *)a1 + 19) = should_stop;
              if ( !should_stop )
                should_stop = printk(&unk_247E6D, "sde_hdcp_2x_enable");
            }
            a1[33] = 0;
            continue;
          case 2:
            should_stop = *((_QWORD *)a1 + 19);
            if ( should_stop )
            {
              should_stop = hdcp2_deinit();
              *((_QWORD *)a1 + 19) = 0;
            }
            continue;
          case 3:
            should_stop = hdcp2_app_comm(*((_QWORD *)a1 + 19), 0, a1 + 20);
            if ( (_DWORD)should_stop )
              goto LABEL_20;
            continue;
          case 4:
            sde_evtlog_log(v8[191], v5, 565, 8, 4369, *((unsigned __int8 *)a1 + 139), -1059143953, v10, v70);
            if ( (unsigned int)hdcp2_app_comm(*((_QWORD *)a1 + 19), 1, a1 + 20) )
              goto LABEL_20;
            v32 = *((_QWORD *)a1 + 18);
            v33 = *((_QWORD *)a1 + 13);
            v81 = 0;
            v82 = 0;
            v77 = 0;
            v78 = v32;
            LODWORD(v32) = a1[28];
            LODWORD(v77) = 1;
            v34 = a1[20];
            v79 = v33 + 1;
            v80 = __PAIR64__(v34, v32);
            sde_hdcp_2x_wakeup_client(a1, &v77);
            v36 = v8[191];
            v37 = *((unsigned __int8 *)a1 + 139);
            v38 = v5;
            v39 = 577;
            goto LABEL_139;
          case 5:
          case 7:
          case 10:
          case 13:
            goto LABEL_20;
          case 6:
            v40 = *((_QWORD *)a1 + 18);
            v41 = v8[191];
            v42 = *((unsigned __int8 *)a1 + 139);
            v75 = 0;
            v76 = 0;
            v73 = 0;
            v74 = 0;
            v72[0] = 0;
            v72[1] = v40;
            sde_evtlog_log(v41, v7, 489, 8, 4369, v42, -1059143953, v10, v70);
            if ( a1[44] )
              goto LABEL_112;
            sde_evtlog_log(v8[191], v7, 496, 8, **((unsigned __int8 **)a1 + 13), -1059143953, v43, v35, v70);
            v44 = *((_BYTE **)a1 + 13);
            v45 = (unsigned __int8)*v44;
            if ( v45 == 11 )
            {
              if ( *((_BYTE *)a1 + 168) != 1 || a1[44] )
              {
                *v44 = 18;
                *(_BYTE *)(*((_QWORD *)a1 + 13) + 1LL) = *((_BYTE *)a1 + 184) == 2;
                a1[20] = 100;
                v58 = *((_QWORD *)a1 + 18);
                a1[28] = 1;
                v78 = v58;
                v77 = 1;
                v59 = *((_QWORD *)a1 + 13);
                v81 = 0;
                v82 = 0;
                v79 = v59 + 1;
                v80 = 0x6400000001LL;
                sde_hdcp_2x_wakeup_client(a1, &v77);
                goto LABEL_111;
              }
LABEL_108:
              v60 = a1[30];
              v61 = *((_QWORD *)a1 + 11);
              v62 = 5;
              goto LABEL_110;
            }
            if ( v45 != 15 )
            {
              if ( v45 == 18 )
              {
                if ( !(unsigned int)hdcp2_app_comm(*((_QWORD *)a1 + 19), 5, a1 + 20) )
                {
                  v63 = *((_BYTE *)a1 + 138) == 1;
                  *((_BYTE *)a1 + 139) = 1;
                  if ( v63 )
                    hdcp2_force_encryption(*((_QWORD *)a1 + 19), 1);
                  LODWORD(v72[0]) = 3;
                  sde_hdcp_2x_wakeup_client(a1, v72);
                }
                goto LABEL_108;
              }
              v60 = a1[20];
              v61 = *((_QWORD *)a1 + 11);
              v62 = 2;
LABEL_110:
              HIDWORD(v74) = v60;
              LODWORD(v72[0]) = v62;
              v73 = v61 + 1;
              goto LABEL_111;
            }
            if ( *((_BYTE *)a1 + 169) != 1 )
              goto LABEL_108;
            if ( a1[44] || *((_BYTE *)a1 + 168) != 1 || (unsigned int)hdcp2_app_comm(*((_QWORD *)a1 + 19), 6, a1 + 20) )
              goto LABEL_104;
            if ( *((_QWORD *)a1 + 13) && *((_QWORD *)a1 + 11) )
            {
              if ( !a1[44] )
              {
                a1[43] = 15;
                sde_hdcp_2x_send_message(a1);
              }
LABEL_104:
              *((_BYTE *)a1 + 169) = 0;
              goto LABEL_111;
            }
            printk(&unk_25CF86, "sde_hdcp_2x_query_stream");
            *((_BYTE *)a1 + 169) = 0;
LABEL_111:
            sde_hdcp_2x_wakeup_client(a1, v72);
LABEL_112:
            v36 = v8[191];
            v37 = *((unsigned __int8 *)a1 + 139);
            v38 = v7;
            v39 = 550;
LABEL_139:
            should_stop = sde_evtlog_log(v36, v38, v39, 8, 8738, v37, -1059143953, v35, v70);
            break;
          case 9:
            v25 = v8[191];
            v26 = *((unsigned __int8 *)a1 + 139);
            v81 = 0;
            v82 = 0;
            v79 = 0;
            v80 = 0;
            v77 = 0;
            v78 = 0;
            should_stop = sde_evtlog_log(v25, "sde_hdcp_2x_msg_recvd", 612, 8, 4369, v26, -1059143953, v10, v70);
            if ( a1[44] )
              continue;
            v27 = a1[32];
            v78 = *((_QWORD *)a1 + 18);
            if ( !v27 )
            {
              printk(&unk_23A7C3, "sde_hdcp_2x_msg_recvd");
              goto LABEL_137;
            }
            v28 = v7;
            v29 = v5;
            v30 = *((_BYTE **)a1 + 11);
            if ( (unsigned int)a1[45] >> 1 == 16385 )
            {
              *v30 = a1[43];
              v31 = 1;
            }
            else
            {
              v31 = 0;
            }
            v48 = *((_QWORD *)a1 + 19);
            a1[24] = v31 + v27;
            v49 = hdcp2_app_comm(v48, 3, a1 + 20);
            v50 = (unsigned __int8)*v30;
            if ( v49 )
            {
              v5 = v29;
              printk(&unk_244B4E, "sde_hdcp_2x_msg_recvd");
              v7 = v28;
            }
            else
            {
              if ( v50 == 7 && *((_BYTE *)a1 + 136) == 1 )
              {
                v51 = a1[20];
                v52 = *((_QWORD *)a1 + 11);
                LODWORD(v77) = 2;
                v5 = v29;
                v7 = v28;
                goto LABEL_123;
              }
              v53 = a1[28];
              if ( v53 )
              {
                v54 = **((unsigned __int8 **)a1 + 13);
                if ( v50 != 17 )
                  goto LABEL_124;
              }
              else
              {
                v54 = 0;
                if ( v50 != 17 )
                  goto LABEL_124;
              }
              if ( v54 == 16 )
              {
LABEL_124:
                *((_BYTE *)a1 + 140) = 0;
                v63 = *v30 == 10 && v54 == 9;
                v64 = v63;
                *((_BYTE *)a1 + 140) = v64;
                if ( v54 == 4 )
                {
                  v5 = v29;
                  *((_BYTE *)a1 + 136) = 1;
                }
                else
                {
                  v5 = v29;
                  *((_BYTE *)a1 + 136) = 0;
                  if ( v54 == 11 )
                  {
                    *((_BYTE *)a1 + 168) = *((_BYTE *)a1 + 84);
                    *((_BYTE *)a1 + 169) = 1;
                  }
                }
                v7 = v28;
                if ( !a1[44] )
                {
                  v65 = *((_QWORD *)a1 + 13);
                  LODWORD(v77) = 1;
                  v66 = a1[20];
                  v79 = v65 + 1;
                  v80 = __PAIR64__(v66, v53);
                }
                goto LABEL_137;
              }
              v5 = v29;
              v7 = v28;
              if ( (*((_BYTE *)a1 + 141) & 1) != 0 || (*((_BYTE *)a1 + 139) & 1) != 0 )
                goto LABEL_122;
              if ( !(unsigned int)hdcp2_app_comm(*((_QWORD *)a1 + 19), 5, a1 + 20) )
              {
                v63 = *((_BYTE *)a1 + 138) == 1;
                *((_BYTE *)a1 + 139) = 1;
                if ( v63 )
                  hdcp2_force_encryption(*((_QWORD *)a1 + 19), 1);
                LODWORD(v77) = 3;
                sde_hdcp_2x_wakeup_client(a1, &v77);
LABEL_122:
                v51 = a1[30];
                v52 = *((_QWORD *)a1 + 11);
                LODWORD(v77) = 5;
LABEL_123:
                HIDWORD(v80) = v51;
                v79 = v52 + 1;
LABEL_137:
                sde_hdcp_2x_wakeup_client(a1, &v77);
                goto LABEL_138;
              }
              printk(&unk_22CD81, "sde_hdcp_2x_msg_recvd");
              v67 = a1[30];
              v68 = *((_QWORD *)a1 + 11);
              LODWORD(v77) = 5;
              HIDWORD(v80) = v67;
              v79 = v68 + 1;
            }
            sde_hdcp_2x_wakeup_client(a1, &v77);
            if ( !a1[44] )
              sde_hdcp_2x_clean(a1);
LABEL_138:
            v36 = v8[191];
            v37 = *((unsigned __int8 *)a1 + 139);
            v38 = "sde_hdcp_2x_msg_recvd";
            v39 = 717;
            goto LABEL_139;
          case 11:
            if ( a1[44] )
              continue;
            should_stop = hdcp2_app_comm(*((_QWORD *)a1 + 19), 4, a1 + 20);
            if ( (_DWORD)should_stop )
            {
              if ( !a1[44] )
LABEL_20:
                should_stop = sde_hdcp_2x_clean(a1);
            }
            else
            {
              v55 = *((_BYTE **)a1 + 13);
              if ( *v55 == 9 && !a1[44] )
              {
                v56 = *((_QWORD *)a1 + 18);
                v47 = (__int64)(v55 + 1);
                v80 = 0;
                v81 = 0;
                v77 = 0;
                v78 = v56;
                LODWORD(v56) = a1[28];
                LODWORD(v77) = 1;
                v57 = a1[20];
                v82 = 0;
                v80 = __PAIR64__(v57, v56);
                goto LABEL_95;
              }
            }
            continue;
          case 12:
            if ( !a1[44] && *((_BYTE *)a1 + 168) == 1 )
              goto LABEL_44;
            continue;
          case 14:
            v24 = a1[44];
            if ( (a1[42] & 1) == 0 )
            {
              if ( !v24 )
              {
                **((_BYTE **)a1 + 13) = 18;
                *(_BYTE *)(*((_QWORD *)a1 + 13) + 1LL) = *((_BYTE *)a1 + 184) == 2;
                a1[28] = 1;
                a1[20] = 100;
                if ( !a1[44] )
                {
                  v46 = *((_QWORD *)a1 + 18);
                  v81 = 0;
                  v82 = 0;
                  v78 = v46;
                  v77 = 1;
                  v47 = *((_QWORD *)a1 + 13) + 1LL;
                  v80 = 0x6400000001LL;
LABEL_95:
                  v79 = v47;
                  should_stop = sde_hdcp_2x_wakeup_client(a1, &v77);
                }
              }
              continue;
            }
            if ( v24 )
              continue;
LABEL_44:
            if ( (*((_BYTE *)a1 + 139) & 1) != 0 || **((_BYTE **)a1 + 13) == 15 )
              goto LABEL_46;
            continue;
          case 15:
          case 16:
            v14 = (_QWORD *)*v6;
            if ( (_QWORD *)*v6 == v6 )
              continue;
            v15 = v4;
            v16 = v1;
            v17 = v8;
            v18 = v7;
            v19 = v5;
            v20 = 0;
            do
            {
              v21 = (_QWORD *)*v14;
              if ( (v14[3] & 1) != 0 )
              {
                if ( !*((_DWORD *)v14 + 5) )
                {
                  should_stop = hdcp2_open_stream(
                                  *((_QWORD *)a1 + 19),
                                  *((unsigned __int8 *)v14 + 17),
                                  *((unsigned __int8 *)v14 + 16),
                                  (char *)v14 + 20);
                  if ( (_DWORD)should_stop )
                    should_stop = printk(&unk_233B4B, "sde_hdcp_2x_manage_stream");
                  else
                    v20 = 1;
                }
              }
              else
              {
                hdcp2_close_stream(*((_QWORD *)a1 + 19), *((unsigned int *)v14 + 5));
                --*((_BYTE *)a1 + 208);
                v22 = (_QWORD *)v14[1];
                if ( (_QWORD *)*v22 == v14 && (v23 = *v14, *(_QWORD **)(*v14 + 8LL) == v14) )
                {
                  *(_QWORD *)(v23 + 8) = v22;
                  *v22 = v23;
                }
                else
                {
                  _list_del_entry_valid_or_report(v14);
                }
                *v14 = 0xDEAD000000000100LL;
                v14[1] = 0xDEAD000000000122LL;
                should_stop = kfree(v14);
                v20 = 1;
              }
              v14 = v21;
            }
            while ( v21 != v6 );
            v5 = v19;
            v7 = v18;
            v8 = v17;
            v1 = v16;
            v4 = v15;
            if ( (v20 & 1) == 0 )
              continue;
            if ( *((_BYTE *)a1 + 139) == 1 )
            {
              if ( !a1[44] && *((_BYTE *)a1 + 168) == 1 )
              {
LABEL_46:
                should_stop = hdcp2_app_comm(*((_QWORD *)a1 + 19), 6, a1 + 20);
                if ( !(_DWORD)should_stop )
                {
                  if ( *((_QWORD *)a1 + 13) && *((_QWORD *)a1 + 11) )
                  {
                    if ( !a1[44] )
                    {
                      a1[43] = 15;
                      should_stop = sde_hdcp_2x_send_message(a1);
                    }
                  }
                  else
                  {
                    should_stop = printk(&unk_25CF86, "sde_hdcp_2x_query_stream");
                  }
                }
              }
            }
            else if ( (a1[43] & 0xFFFFFFFE) == 0x10 )
            {
              *((_BYTE *)a1 + 141) = 1;
            }
            continue;
          default:
            continue;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
