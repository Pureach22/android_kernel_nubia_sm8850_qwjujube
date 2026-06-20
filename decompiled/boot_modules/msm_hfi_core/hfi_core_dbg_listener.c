__int64 __fastcall hfi_core_dbg_listener(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x0
  unsigned int v13; // w10
  unsigned __int64 v14; // x24
  __int64 v15; // x21
  __int64 *client_node; // x0
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x30
  void *v20; // x0
  __int64 v21; // x2
  __int64 v22; // x30
  void *v23; // x0
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 *v26; // x19
  __int64 v27; // x22
  _QWORD *v28; // x2
  __int64 v29; // x2
  __int64 v30; // x3
  __int64 v31; // x4
  int device_rx_buffer; // w5
  _QWORD *v33; // x27
  __int64 v34; // x19
  _QWORD **v35; // x25
  __int64 v36; // x9
  __int64 v37; // x24
  char v38; // w22
  unsigned int v39; // w23
  int appended; // w0
  char *v41; // x8
  int v42; // w9
  int v43; // w10
  int v44; // w11
  int v45; // w9
  _QWORD *v46; // x8
  unsigned int v47; // w28
  unsigned int v48; // w22
  __int64 v49; // x2
  unsigned int v50; // w8
  char *v51; // x8
  _QWORD *v52; // x8
  __int64 v53; // x0
  __int64 v54; // x30
  void *v55; // x0
  const char *v56; // x1
  __int64 v57; // x2
  int v58; // w22
  int v59; // w22
  __int64 v60; // x3
  __int64 v61; // x4
  int v62; // w19
  unsigned __int64 v63; // x4
  __int64 v64; // x5
  __int64 v65; // x30
  void *v66; // x0
  const char *v67; // x1
  __int64 v68; // x2
  __int64 v69; // x30
  void *v70; // x0
  __int64 v71; // x2
  __int64 v72; // x30
  void *v73; // x0
  __int64 v74; // x2
  __int64 v76; // [xsp+8h] [xbp-78h]
  __int64 v77; // [xsp+10h] [xbp-70h]
  unsigned __int64 v78; // [xsp+18h] [xbp-68h]
  __int64 v79; // [xsp+20h] [xbp-60h] BYREF
  __int64 v80; // [xsp+28h] [xbp-58h]
  __int64 v81; // [xsp+30h] [xbp-50h]
  unsigned int *v82; // [xsp+38h] [xbp-48h]
  __int64 v83; // [xsp+40h] [xbp-40h]
  _QWORD *v84; // [xsp+48h] [xbp-38h] BYREF
  __int64 v85; // [xsp+50h] [xbp-30h] BYREF
  __int128 v86; // [xsp+58h] [xbp-28h] BYREF
  _DWORD *v87; // [xsp+68h] [xbp-18h] BYREF
  __int64 v88; // [xsp+70h] [xbp-10h]
  __int64 v89; // [xsp+78h] [xbp-8h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
      goto LABEL_186;
  }
  else
  {
LABEL_185:
    printk(&unk_1E83A, "hfi_core_dbg_listener", 1357, a4);
    if ( !a1 )
      goto LABEL_186;
  }
  if ( *(_QWORD *)(a1 + 792) )
  {
    v76 = *(_QWORD *)(a1 + 792);
    _ReadStatusReg(SP_EL0);
    do
    {
      while ( 1 )
      {
LABEL_5:
        if ( !*(_DWORD *)(v76 + 80) )
        {
          v82 = nullptr;
          v83 = 0;
          v80 = 0;
          v81 = 0;
          v79 = 0;
          init_wait_entry(&v79, 0);
          while ( 1 )
          {
            v6 = prepare_to_wait_event(v76 + 88, &v79, 2);
            if ( *(_DWORD *)(v76 + 80) )
              break;
            schedule(v6);
          }
          finish_wait(v76 + 88, &v79);
        }
        _X9 = (unsigned int *)(v76 + 80);
        __asm { PRFM            #0x11, [X9] }
        do
          v13 = __ldxr(_X9);
        while ( __stlxr(0, _X9) );
        __dmb(0xBu);
        v14 = v13;
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          break;
        if ( v13 )
          goto LABEL_14;
      }
      printk(&unk_19FA5, "hfi_core_dbg_listener", 1369, v13);
    }
    while ( !(_DWORD)v14 );
LABEL_14:
    v15 = 1;
    v78 = v14;
    while ( 1 )
    {
      if ( ((v14 >> v15) & 1) == 0 )
        goto LABEL_16;
      if ( hfi_core_loop_back_mode_enable != 1 || v15 != 3 )
      {
        get_rx_buffers(a1, (unsigned int)v15);
        goto LABEL_16;
      }
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1E83A, "process_loop_back_dcp_client", 1258, a4);
      client_node = get_client_node(a1, 3, a3, a4, a5);
      if ( !client_node )
      {
        v19 = v77;
        v20 = &unk_1BE87;
        v21 = 1269;
LABEL_36:
        v25 = v19;
LABEL_44:
        printk(v20, "process_loop_back_dcp_client", v21, v25);
        goto LABEL_16;
      }
      if ( *((_BYTE *)client_node + 56) == 1 )
        break;
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        goto LABEL_37;
LABEL_28:
      *((_BYTE *)client_node + 56) = 1;
      if ( (unsigned int)trigger_ipc(3u, a1, 1, a4, a5) )
      {
        v22 = v77;
        v23 = &unk_1DD69;
        v24 = 1229;
        goto LABEL_43;
      }
LABEL_16:
      if ( ++v15 == 4 )
        goto LABEL_5;
    }
    if ( (*((_BYTE *)client_node + 57) & 1) != 0 )
    {
      v84 = (_QWORD *)_kmalloc_cache_noprof(devm_free_irq, 3520, 40);
      if ( !v84 )
      {
        v19 = v77;
        v20 = &unk_19B17;
        v21 = 1291;
        goto LABEL_36;
      }
      while ( 2 )
      {
        v28 = v84;
        v84[2] = 0;
        v28[3] = 0;
        v28[4] = 0;
        *v28 = 0;
        v28[1] = 0;
        device_rx_buffer = get_device_rx_buffer(a1, 3u, (__int64)v28, v17, v18);
        if ( device_rx_buffer )
        {
          if ( device_rx_buffer == -105 )
          {
            kfree(v84);
            if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
              printk(&unk_1C28B, "process_loop_back_dcp_client", 1327, a4);
          }
          else
          {
LABEL_166:
            printk(&unk_19C33, "process_loop_back_dcp_client", 1304, v77);
          }
          goto LABEL_16;
        }
        v33 = v84;
        if ( !*v84 || !v84[2] )
          goto LABEL_166;
        v88 = 0;
        v86 = 0u;
        v81 = 0;
        v82 = nullptr;
        v79 = 0;
        v80 = 0;
        v85 = 0;
        if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
        {
          if ( !v84 )
            goto LABEL_174;
LABEL_53:
          v34 = *(_QWORD *)(a1 + 792);
          v35 = (_QWORD **)(v34 + 120);
          if ( *(_QWORD *)(v34 + 120) != v34 + 120 )
          {
            v36 = v33[2];
            v87 = (_DWORD *)*v33;
            LODWORD(v88) = v36;
            if ( !(unsigned int)hfi_unpacker_get_header_info(&v87, &v86, v29, v30, v31) )
            {
              a4 = (unsigned int)v86;
              if ( !(_DWORD)v86 )
              {
                if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
                  printk(&unk_1C5C0, "process_loop_back_response", 992, *v33);
                goto LABEL_47;
              }
              v63 = (unsigned __int64)"Unknown";
              if ( (unsigned int)(DWORD1(v86) - 1) <= 4 )
                v63 = (unsigned __int64)off_205A8[DWORD1(v86) - 1];
              if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
              {
                printk(&unk_1DABF, "print_hfi_header_info", 412, (unsigned int)v86);
                if ( !(_DWORD)v86 )
                {
LABEL_152:
                  appended = 0;
LABEL_153:
                  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
                  {
                    v14 = v78;
                    if ( appended )
                      goto LABEL_172;
                  }
                  else
                  {
                    v62 = appended;
                    printk(&unk_1C28B, "process_loop_back_response", 1114, a4);
                    v14 = v78;
                    if ( v62 )
                      goto LABEL_172;
                  }
LABEL_47:
                  if ( !(unsigned int)put_device_rx_buffer(a1, 3, &v84, 1, v63, v64) )
                    continue;
                  v69 = v77;
                  v70 = &unk_1D7AC;
                  v71 = 1321;
LABEL_173:
                  printk(v70, "process_loop_back_dcp_client", v71, v69);
                  goto LABEL_16;
                }
              }
              v37 = 0;
              v38 = 0;
              v39 = 1;
              while ( 2 )
              {
                if ( (unsigned int)hfi_unpacker_get_packet_info(&v87, v39, (__int64)&v79, a4, v63) )
                {
                  printk(&unk_1BDAD, "process_loop_back_response", 1002, v77);
                  goto LABEL_171;
                }
                print_hfi_packet_info(&v79);
                v63 = (unsigned int)v79;
                if ( (int)v79 <= 33554434 )
                {
                  switch ( (_DWORD)v79 )
                  {
                    case 0xFF000007:
                      if ( v34 != -120 )
                      {
                        v52 = *v35;
                        if ( *v35 != v35 )
                        {
                          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
                          {
                            printk(&unk_19FC6, "hfi_core_lb_cmd_get_payload", 502, 4278190087LL);
                            v52 = *v35;
                          }
                          while ( v52 != v35 )
                          {
                            if ( v52 != &_ksymtab_hfi_core_cmds_rx_buf_get && *((_DWORD *)v52 - 6) == -16777209 )
                            {
                              if ( (v38 & 1) == 0 )
                              {
                                v37 = loopback_create_response_pkt(a1, &v86);
                                v85 = v37;
                                if ( !v37 )
                                {
                                  v65 = v77;
                                  v66 = &unk_1CBAA;
                                  v67 = "process_loop_back_response";
                                  v68 = 1051;
                                  goto LABEL_170;
                                }
                              }
                              appended = hfi_core_lb_append_packet(
                                           v37,
                                           a1,
                                           (unsigned int)v79,
                                           HIDWORD(v80),
                                           HIDWORD(v79));
                              if ( appended )
                              {
                                v59 = appended;
                                printk(&unk_1B5ED, "process_loop_back_response", 1062, v77);
                                appended = v59;
                              }
                              v38 = 1;
                              goto LABEL_62;
                            }
                            v52 = (_QWORD *)*v52;
                          }
                        }
                      }
                      goto LABEL_61;
                    case 0xFF000009:
                      if ( v82 )
                      {
                        if ( v82[2] )
                        {
                          byte_1FAF0 = 1;
                          qword_1FAF4 = *(_QWORD *)((char *)&v86 + 4);
                          dword_1FB10 = 0;
                          LODWORD(qword_1FB04) = HIDWORD(v79);
                          HIDWORD(qword_1FB04) = HIDWORD(v80);
                          byte_1FB0C = 1;
                          LODWORD(qword_1FAFC) = HIDWORD(v86);
                          HIDWORD(qword_1FAFC) = -16777206;
                          byte_1FB14 = hfi_core_lb_start_event_thread;
                          if ( hfi_core_lb_start_event_thread == 1 )
                            kthread_queue_delayed_work(v34 + 136, v34 + 192, 3);
                          appended = 0;
                          goto LABEL_145;
                        }
                        appended = 0;
                        byte_1FAF0 = 0;
                        dword_1FB10 = 0;
                        byte_1FB14 = 0;
                        qword_1FAF4 = 0;
                        qword_1FAFC = 0;
                        qword_1FB04 = 0;
LABEL_62:
                        if ( ++v39 > (unsigned int)v86 )
                        {
                          if ( !v37 )
                            goto LABEL_153;
                          if ( !(unsigned int)set_device_tx_buffer(a1, 3u, &v85, 1, v63) )
                          {
                            trigger_ipc(3u, a1, 1, v60, v61);
                            kfree(v85);
                            goto LABEL_152;
                          }
                          printk(&unk_18FE3, "process_loop_back_response", 1105, v77);
                          v14 = v78;
                          goto LABEL_172;
                        }
                        continue;
                      }
                      printk(&unk_1EEBF, "process_lb_panic_subscribe", 826, v77);
                      goto LABEL_61;
                    case 0x1000001:
                      if ( v34 != -120 )
                      {
                        v46 = *v35;
                        if ( *v35 != v35 )
                        {
                          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
                          {
                            printk(&unk_19FC6, "hfi_core_lb_cmd_get_payload", 502, 16777217);
                            v46 = *v35;
                          }
                          while ( v46 != v35 )
                          {
                            if ( v46 != &_ksymtab_hfi_core_cmds_rx_buf_get && *((_DWORD *)v46 - 6) == 16777217 )
                            {
                              if ( (v38 & 1) == 0 )
                              {
                                v37 = loopback_create_response_pkt(a1, &v86);
                                v85 = v37;
                                if ( !v37 )
                                {
                                  v65 = v77;
                                  v66 = &unk_1CBAA;
                                  v67 = "process_loop_back_response";
                                  v68 = 1016;
                                  goto LABEL_170;
                                }
                              }
                              v47 = HIDWORD(v79);
                              v48 = HIDWORD(v80);
                              if ( (unsigned int)hfi_core_lb_append_packet(
                                                   v37,
                                                   a1,
                                                   (unsigned int)v79,
                                                   HIDWORD(v80),
                                                   HIDWORD(v79)) )
                                printk(&unk_1AD0A, "process_lb_device_init_response", 938, v77);
                              if ( (unsigned int)hfi_core_lb_append_packet(v37, a1, 16777218, v48, v47) )
                                printk(&unk_1F7A2, "process_lb_device_init_response", 948, v77);
                              if ( (unsigned int)hfi_core_lb_append_packet(v37, a1, 16777219, v48, v47) )
                                printk(&unk_1F7A2, "process_lb_device_init_response", 948, v77);
                              if ( (unsigned int)hfi_core_lb_append_packet(v37, a1, 16777220, v48, v47) )
                                printk(&unk_1F7A2, "process_lb_device_init_response", 948, v77);
                              if ( (unsigned int)hfi_core_lb_append_packet(v37, a1, 16777221, v48, v47) )
                                printk(&unk_1F7A2, "process_lb_device_init_response", 948, v77);
                              if ( (unsigned int)hfi_core_lb_append_packet(v37, a1, 16777222, v48, v47) )
                                printk(&unk_1F7A2, "process_lb_device_init_response", 948, v77);
                              if ( (unsigned int)hfi_core_lb_append_packet(v37, a1, 16777223, v48, v47) )
                                printk(&unk_1F7A2, "process_lb_device_init_response", 948, v77);
                              if ( (unsigned int)hfi_core_lb_append_packet(v37, a1, 16777226, v48, v47) )
                                printk(&unk_1F7A2, "process_lb_device_init_response", 948, v77);
                              appended = hfi_core_lb_append_packet(v37, a1, 16777227, v48, v47);
                              if ( appended )
                              {
                                v58 = appended;
                                printk(&unk_1F7A2, "process_lb_device_init_response", 948, v77);
                                appended = v58;
                              }
                              v38 = 1;
                              goto LABEL_62;
                            }
                            v46 = (_QWORD *)*v46;
                          }
                        }
                      }
                      goto LABEL_61;
                  }
                }
                else
                {
                  if ( (int)v79 <= 33554436 )
                  {
                    if ( (_DWORD)v79 == 33554435 )
                    {
                      if ( byte_1FA50 == 1 )
                      {
                        byte_1FA6C = 1;
                        if ( byte_1FA74 == 1 && hfi_core_lb_start_event_thread == 1 )
                        {
                          kthread_queue_delayed_work(v34 + 136, v34 + 192, 3);
                          byte_1FA74 = 0;
                          hfi_core_lb_start_event_thread = 0;
                        }
                        ++dword_1FA70;
                      }
                      if ( byte_1FAF0 == 1 )
                      {
                        appended = 0;
                        ++dword_1FB10;
                        goto LABEL_62;
                      }
                    }
                    else
                    {
                      if ( !v82 )
                      {
                        v65 = v77;
                        v66 = &unk_19C88;
                        v67 = "process_lb_event_register";
                        v68 = 896;
                        goto LABEL_170;
                      }
                      v63 = *v82;
                      if ( (unsigned int)(v63 - 1) <= 5 )
                      {
                        if ( (unsigned int)(v63 - 1) <= 1 )
                        {
                          v41 = (char *)&g_debug_events + 40 * (unsigned int)v63;
                          *v41 = 1;
                          if ( ((40 * v63) | 4) > 0x118 )
                            goto LABEL_184;
                          *((_DWORD *)v41 + 1) = DWORD1(v86);
                          v42 = DWORD2(v86);
                          v43 = HIDWORD(v86);
                          v44 = HIDWORD(v80);
                          *((_DWORD *)v41 + 8) = 0;
                          *((_DWORD *)v41 + 2) = v42;
                          *((_DWORD *)v41 + 3) = v43;
                          *((_DWORD *)v41 + 5) = HIDWORD(v79);
                          *((_DWORD *)v41 + 6) = v44;
                          v45 = (unsigned __int8)hfi_core_lb_start_event_thread;
                          v41[36] = hfi_core_lb_start_event_thread;
                          if ( (_DWORD)v63 != 1 )
                          {
                            appended = 0;
                            *((_DWORD *)v41 + 4) = 67108866;
                            goto LABEL_62;
                          }
                          *((_DWORD *)v41 + 4) = 67108865;
                          v41[28] = 1;
                          if ( v45 )
                            kthread_queue_delayed_work(v34 + 136, v34 + 192, 3);
                          appended = 0;
                          byte_1FA4C = 0;
LABEL_145:
                          hfi_core_lb_start_event_thread = 0;
                          goto LABEL_62;
                        }
                        v54 = v77;
                        v55 = &unk_1EE74;
                        v56 = "process_lb_event_register";
                        v57 = 916;
LABEL_148:
                        printk(v55, v56, v57, v54);
                      }
                    }
LABEL_61:
                    appended = 0;
                    goto LABEL_62;
                  }
                  if ( (_DWORD)v79 == 33554437 )
                  {
                    if ( !v82 )
                    {
                      v65 = v77;
                      v66 = &unk_19C88;
                      v67 = "process_lb_event_deregister";
                      v68 = 855;
                      goto LABEL_170;
                    }
                    v50 = *v82;
                    if ( *v82 - 1 <= 5 )
                    {
                      if ( v50 > 6 )
                      {
LABEL_184:
                        __break(1u);
                        goto LABEL_185;
                      }
                      v51 = (char *)&g_debug_events + 40 * v50;
                      appended = 0;
                      *v51 = 0;
                      *((_DWORD *)v51 + 8) = 0;
                      v51[36] = 0;
                      *(_QWORD *)(v51 + 4) = 0;
                      *(_QWORD *)(v51 + 12) = 0;
                      *(_QWORD *)(v51 + 20) = 0;
                      goto LABEL_62;
                    }
                    goto LABEL_61;
                  }
                  if ( (_DWORD)v79 == 33554440 )
                  {
                    if ( (v38 & 1) != 0 )
                    {
                      v49 = 33554440;
                    }
                    else
                    {
                      v53 = loopback_create_response_pkt(a1, &v86);
                      v85 = v53;
                      if ( !v53 )
                      {
                        v65 = v77;
                        v66 = &unk_1CBAA;
                        v67 = "process_loop_back_response";
                        v68 = 1079;
LABEL_170:
                        printk(v66, v67, v68, v65);
LABEL_171:
                        v14 = v78;
                        goto LABEL_172;
                      }
                      v49 = (unsigned int)v79;
                      v37 = v53;
                    }
                    appended = hfi_core_lb_append_packet(v37, a1, v49, HIDWORD(v80), HIDWORD(v79));
                    v38 = 1;
                    goto LABEL_62;
                  }
                }
                break;
              }
              v54 = v77;
              v55 = &unk_1AA5B;
              v56 = "process_loop_back_response";
              v57 = 1090;
              goto LABEL_148;
            }
            printk(&unk_193A6, "process_loop_back_response", 986, v77);
LABEL_172:
            v69 = v77;
            v70 = &unk_1BA40;
            v71 = 1312;
            goto LABEL_173;
          }
          v72 = v77;
          v73 = &unk_1CB80;
          v74 = 975;
        }
        else
        {
          printk(&unk_1E83A, "process_loop_back_response", 966, v30);
          if ( v33 )
            goto LABEL_53;
LABEL_174:
          v72 = v77;
          v73 = &unk_1905C;
          v74 = 969;
        }
        break;
      }
      printk(v73, "process_loop_back_response", v74, v72);
      goto LABEL_172;
    }
    if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
    {
      if ( (*((_BYTE *)client_node + 57) & 1) != 0 )
        goto LABEL_33;
      goto LABEL_32;
    }
LABEL_37:
    v26 = client_node;
    printk(&unk_1E83A, "init_loop_back_client", 1222, a4);
    client_node = v26;
    if ( (v26[7] & 1) != 0 )
    {
      if ( (*((_BYTE *)v26 + 57) & 1) != 0 )
      {
LABEL_33:
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        {
          printk(&unk_1B329, "init_loop_back_client", 1246, 3);
          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
            printk(&unk_1C28B, "init_loop_back_client", 1247, a4);
        }
        goto LABEL_16;
      }
LABEL_32:
      *((_BYTE *)client_node + 57) = 1;
      if ( !(unsigned int)trigger_ipc(3u, a1, 1, a4, a5) )
        goto LABEL_33;
      v22 = v77;
      v23 = &unk_1A563;
      v24 = 1240;
LABEL_43:
      v27 = v22;
      printk(v23, "init_loop_back_client", v24, v22);
      v20 = &unk_19811;
      v21 = 1279;
      v25 = v27;
      goto LABEL_44;
    }
    goto LABEL_28;
  }
LABEL_186:
  printk(&unk_1905C, "hfi_core_dbg_listener", 1360, v77);
  _ReadStatusReg(SP_EL0);
  return 4294967274LL;
}
