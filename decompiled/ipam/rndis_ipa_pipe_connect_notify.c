__int64 __fastcall rndis_ipa_pipe_connect_notify(
        unsigned int a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        int a5,
        unsigned int *a6)
{
  __int64 v12; // x20
  int state; // w26
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 result; // x0
  __int64 v17; // x9
  _DWORD *v18; // x20
  unsigned int v19; // w0
  __int64 v20; // x9
  __int64 v21; // x0
  int v22; // w28
  int v23; // w26
  int v24; // w8
  _DWORD *v25; // x25
  __int64 v26; // x8
  int v27; // w28
  int v28; // w8
  int v29; // w9
  int v30; // w10
  unsigned int v31; // w0
  __int64 v32; // x1
  __int64 v33; // x0
  int v34; // w6
  unsigned int v35; // w0
  long double v36; // q0
  __int64 v37; // x8
  __int64 v38; // x21
  long double v39; // q0
  __int64 v40; // x22
  const char *v41; // x0
  size_t v42; // x0
  unsigned __int64 v43; // x2
  unsigned int v44; // w0
  __int64 v45; // x20
  unsigned int v46; // w0
  __int64 v47; // x0
  __int64 v48; // x0
  unsigned int v49; // w19
  void *v50; // x0
  unsigned int v51; // w21
  __int64 v52; // x1
  long double v53; // q0
  __int64 v54; // x8
  const char *v55; // x4
  unsigned __int64 v62; // x9
  int v63; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v64[5]; // [xsp+8h] [xbp-28h] BYREF

  v64[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v63 = 0;
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_pipe_connect_notify", 799);
  if ( !a6 )
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_3E01BA, "rndis_ipa_pipe_connect_notify");
    if ( ipa_rndis_logbuf )
    {
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d null pointer #ptr\n", "rndis_ipa_pipe_connect_notify", 802);
      result = 4294967274LL;
      goto LABEL_113;
    }
    goto LABEL_77;
  }
  if ( ipa_rndis_logbuf )
  {
    ipc_log_string(
      ipa_rndis_logbuf,
      "RNDIS_IPA %s:%d usb_to_ipa_hdl=%d, ipa_to_usb_hdl=%d, private=0x%pK\n",
      "rndis_ipa_pipe_connect_notify",
      809,
      a1,
      a2,
      a6);
    if ( ipa_rndis_logbuf )
    {
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d max_xfer_sz_to_dev=%d, max_pkt_num_to_dev=%d\n",
        "rndis_ipa_pipe_connect_notify",
        813,
        a3,
        a4);
      if ( ipa_rndis_logbuf )
        ipc_log_string(
          ipa_rndis_logbuf,
          "RNDIS_IPA %s:%d max_xfer_sz_to_host=%d\n",
          "rndis_ipa_pipe_connect_notify",
          816,
          a5);
    }
  }
  v12 = raw_spin_lock_irqsave(a6 + 50);
  state = rndis_ipa_next_state(a6[18], 1);
  raw_spin_unlock_irqrestore(a6 + 50, v12);
  if ( state != 5 )
  {
    if ( a1 >= 0x86 )
    {
      if ( (unsigned int)__ratelimit(&rndis_ipa_pipe_connect_notify__rs, "rndis_ipa_pipe_connect_notify") )
      {
        _ReadStatusReg(SP_EL0);
        printk(&unk_3FD38E, "rndis_ipa_pipe_connect_notify");
        v14 = ipa_rndis_logbuf;
        if ( ipa_rndis_logbuf )
          goto LABEL_12;
      }
      else
      {
        v14 = ipa_rndis_logbuf;
        if ( ipa_rndis_logbuf )
        {
LABEL_12:
          ipc_log_string(
            v14,
            "RNDIS_IPA %s:%d usb_to_ipa_hdl(%d) - not valid ipa handle\n",
            "rndis_ipa_pipe_connect_notify",
            832,
            a1);
LABEL_17:
          result = 4294967274LL;
          goto LABEL_113;
        }
      }
LABEL_77:
      result = 4294967274LL;
      goto LABEL_113;
    }
    if ( a2 >= 0x86 )
    {
      if ( (unsigned int)__ratelimit(&rndis_ipa_pipe_connect_notify__rs_54, "rndis_ipa_pipe_connect_notify") )
      {
        _ReadStatusReg(SP_EL0);
        printk(&unk_3DA6F0, "rndis_ipa_pipe_connect_notify");
        v15 = ipa_rndis_logbuf;
        if ( !ipa_rndis_logbuf )
          goto LABEL_77;
      }
      else
      {
        v15 = ipa_rndis_logbuf;
        if ( !ipa_rndis_logbuf )
          goto LABEL_77;
      }
      ipc_log_string(
        v15,
        "RNDIS_IPA %s:%d ipa_to_usb_hdl(%d) - not valid ipa handle\n",
        "rndis_ipa_pipe_connect_notify",
        838,
        a2);
      goto LABEL_17;
    }
    v18 = a6 + 51;
    v17 = *(_QWORD *)a6;
    v64[2] = a6;
    v64[3] = 1;
    v64[0] = v17 + 296;
    v64[1] = rndis_ipa_pm_cb;
    v19 = ipa_pm_register((__int64)v64, a6 + 51);
    if ( v19 )
    {
      _ReadStatusReg(SP_EL0);
      v49 = v19;
      printk(&unk_3C2FAB, "rndis_ipa_register_pm_client");
      if ( ipa_rndis_logbuf )
        ipc_log_string(
          ipa_rndis_logbuf,
          "RNDIS_IPA %s:%d failed to create IPA PM client %d\n",
          "rndis_ipa_register_pm_client",
          2003,
          v49);
      printk(&unk_3C6299, "rndis_ipa_pipe_connect_notify");
      if ( ipa_rndis_logbuf )
        ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d fail on PM register\n", "rndis_ipa_pipe_connect_notify", 844);
      goto LABEL_112;
    }
    if ( ipa_rndis_logbuf )
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d PM client was registered\n",
        "rndis_ipa_pipe_connect_notify",
        847);
    a6[12] = a1;
    a6[13] = a2;
    if ( a4 < 2 )
    {
      v26 = *(_QWORD *)a6;
      *((_BYTE *)a6 + 26) = 0;
      v22 = *((unsigned __int8 *)a6 + 208);
      v23 = *(_DWORD *)(v26 + 56);
      if ( ipa_rndis_logbuf )
      {
        ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d deaggregation disabled\n", "rndis_ipa_ep_registers_cfg", 2148);
        v24 = 44;
        v25 = &usb_to_ipa_ep_cfg_deaggr_dis;
        if ( (v22 & 1) == 0 )
          goto LABEL_27;
LABEL_35:
        v29 = 18;
        v27 = 1;
        v28 = v24 | 0x12;
        qmap_template_hdr = qmap_template_hdr & 0xFFFFE0FFFFFFFFFFLL | 0x40000000000LL;
        v30 = 62;
LABEL_36:
        v25[3] = v28;
        dword_41964 = v30;
        dword_41970 = v29;
        v25[35] = a3;
        v31 = ipa3_cfg_ep(a1, (__int64)v25);
        if ( v31 )
        {
          v49 = v31;
          v50 = &unk_3AED05;
        }
        else
        {
          v33 = ipa_rndis_logbuf;
          if ( ipa_rndis_logbuf )
          {
            ipc_log_string(
              ipa_rndis_logbuf,
              "RNDIS_IPA %s:%d IPA<-USB end-point configured\n",
              "rndis_ipa_ep_registers_cfg",
              2173);
            v33 = ipa_rndis_logbuf;
          }
          if ( (unsigned int)(a5 - v23) >= 0x400 )
            v34 = 1000;
          else
            v34 = 0;
          dword_419C0 = (unsigned int)(a5 - v23) >> 10;
          dword_419C4 = v34;
          dword_419C8 = (unsigned int)(a5 - v23) < 0x400;
          if ( v33 )
            ipc_log_string(
              v33,
              "RNDIS_IPA %s:%d RNDIS aggregation param: en=%d byte_limit=%d time_limit=%d pkt_limit=%d\n",
              "rndis_ipa_ep_registers_cfg",
              2192,
              dword_419B8,
              (unsigned int)(a5 - v23) >> 10,
              v34,
              (unsigned int)(a5 - v23) < 0x400);
          v25[11] = 1;
          if ( (ipa3_is_ulso_supported() & 1) != 0 )
            byte_41A0C = 1;
          if ( v27 )
          {
            v25[11] = 0;
            *((_QWORD *)v25 + 2) = 0x3A00000001LL;
          }
          v35 = ipa3_cfg_ep(a2, (__int64)&ipa_to_usb_ep_cfg);
          if ( !v35 )
          {
            if ( ipa_rndis_logbuf )
            {
              v36 = ipc_log_string(
                      ipa_rndis_logbuf,
                      "RNDIS_IPA %s:%d IPA->USB end-point configured\n",
                      "rndis_ipa_ep_registers_cfg",
                      2213);
              if ( ipa_rndis_logbuf )
                v36 = ipc_log_string(
                        ipa_rndis_logbuf,
                        "RNDIS_IPA %s:%d end-points configured\n",
                        "rndis_ipa_pipe_connect_notify",
                        867);
            }
            v37 = *(_QWORD *)(*(_QWORD *)a6 + 24LL);
            *(_QWORD *)(v37 + 328) = jiffies;
            __dmb(0xBu);
            while ( 1 )
            {
              _X8 = (unsigned __int64 *)(v37 + 336);
              __asm { PRFM            #0x11, [X8] }
              do
                v62 = __ldxr(_X8);
              while ( __stxr(v62 | 1, _X8) );
              if ( ipa_rndis_logbuf )
                v36 = ipc_log_string(
                        ipa_rndis_logbuf,
                        "RNDIS_IPA %s:%d netif_stop_queue() was called\n",
                        "rndis_ipa_pipe_connect_notify",
                        870);
              netif_carrier_on(*(_QWORD *)a6, v36);
              if ( (*(_QWORD *)(*(_QWORD *)a6 + 168LL) & 4) != 0 )
                break;
              if ( ipa_rndis_logbuf )
                ipc_log_string(
                  ipa_rndis_logbuf,
                  "RNDIS_IPA %s:%d netif_carrier_on() was called\n",
                  "rndis_ipa_pipe_connect_notify",
                  878);
              v38 = _kmalloc_cache_noprof(ipc_log_string, 3520, 36);
              if ( !v38 )
              {
                v49 = -12;
                goto LABEL_111;
              }
              v40 = *(_QWORD *)a6;
              v41 = (const char *)(*(_QWORD *)a6 + 296LL);
              v63 = 2359315;
              v42 = strnlen(v41, 0x10u);
              if ( v42 < 0x10 || v42 == 32 )
              {
                if ( v42 == 32 )
                  v43 = 32;
                else
                  v43 = v42 + 1;
                if ( v43 < 0x21 )
                {
                  sized_strscpy(v38, v40 + 296);
                  *(_DWORD *)(v38 + 32) = *(_DWORD *)(*(_QWORD *)a6 + 224LL);
                  v44 = ipa_send_msg((unsigned __int8 *)&v63, (_WORD *)v38, rndis_ipa_msg_free_cb);
                  if ( !v44 )
                  {
                    v45 = raw_spin_lock_irqsave(a6 + 50);
                    v46 = rndis_ipa_next_state(a6[18], 1);
                    if ( v46 == 5 )
                    {
                      raw_spin_unlock_irqrestore(a6 + 50, v45);
                      if ( !(unsigned int)__ratelimit(
                                            &rndis_ipa_pipe_connect_notify__rs_72,
                                            "rndis_ipa_pipe_connect_notify") )
                      {
                        v47 = ipa_rndis_logbuf;
                        if ( !ipa_rndis_logbuf )
                          goto LABEL_95;
                        goto LABEL_68;
                      }
                      _ReadStatusReg(SP_EL0);
                      printk(&unk_3D4C8B, "rndis_ipa_pipe_connect_notify");
                      v47 = ipa_rndis_logbuf;
                      if ( ipa_rndis_logbuf )
                      {
LABEL_68:
                        ipc_log_string(
                          v47,
                          "RNDIS_IPA %s:%d use init()/disconnect() before connect()\n",
                          "rndis_ipa_pipe_connect_notify",
                          905);
                        goto LABEL_69;
                      }
LABEL_95:
                      result = 0xFFFFFFFFLL;
                    }
                    else
                    {
                      v51 = v46;
                      a6[18] = v46;
                      raw_spin_unlock_irqrestore(a6 + 50, v45);
                      if ( ipa_rndis_logbuf )
                      {
                        v54 = a6[18];
                        if ( (unsigned int)v54 > 4 )
                          v55 = "Not supported";
                        else
                          v55 = off_1F6620[v54];
                        v53 = ipc_log_string(
                                ipa_rndis_logbuf,
                                "RNDIS_IPA %s:%d Driver state: %s\n",
                                "rndis_ipa_pipe_connect_notify",
                                911,
                                v55);
                      }
                      if ( v51 == 4 )
                      {
                        rndis_ipa_enable_data_path(a6, v53);
                      }
                      else if ( ipa_rndis_logbuf )
                      {
                        ipc_log_string(
                          ipa_rndis_logbuf,
                          "RNDIS_IPA %s:%d queue shall be started after open()\n",
                          "rndis_ipa_pipe_connect_notify",
                          916);
                      }
                      printk(&unk_3F45AA, v52);
                      result = ipa_rndis_logbuf;
                      if ( ipa_rndis_logbuf )
                      {
                        ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_pipe_connect_notify", 920);
                        result = 0;
                      }
                    }
                    goto LABEL_113;
                  }
                  v49 = v44;
                  _ReadStatusReg(SP_EL0);
                  printk(&unk_400165, "rndis_ipa_pipe_connect_notify");
                  if ( ipa_rndis_logbuf )
                    ipc_log_string(
                      ipa_rndis_logbuf,
                      "RNDIS_IPA %s:%d fail to send ECM_CONNECT for rndis\n",
                      "rndis_ipa_pipe_connect_notify",
                      895);
                  kfree(v38);
LABEL_111:
                  ((void (__fastcall *)(_QWORD, long double))ipa_pm_deactivate_sync)((unsigned int)*v18, v39);
                  ((void (__fastcall *)(_QWORD))ipa_pm_deregister)((unsigned int)*v18);
                  *v18 = -1;
LABEL_112:
                  result = v49;
                  goto LABEL_113;
                }
              }
              else
              {
                _fortify_panic(2, 16, v42 + 1);
              }
              _fortify_panic(7, 32, v43);
            }
            if ( (unsigned int)__ratelimit(&rndis_ipa_pipe_connect_notify__rs_64, "rndis_ipa_pipe_connect_notify") )
            {
              _ReadStatusReg(SP_EL0);
              printk(&unk_3EB74F, "rndis_ipa_pipe_connect_notify");
              v48 = ipa_rndis_logbuf;
              if ( !ipa_rndis_logbuf )
                goto LABEL_73;
            }
            else
            {
              v48 = ipa_rndis_logbuf;
              if ( !ipa_rndis_logbuf )
              {
LABEL_73:
                v49 = -16;
                goto LABEL_111;
              }
            }
            v39 = ipc_log_string(v48, "RNDIS_IPA %s:%d netif_carrier_ok error\n", "rndis_ipa_pipe_connect_notify", 874);
            goto LABEL_73;
          }
          v49 = v35;
          v50 = &unk_3DA859;
        }
        printk(v50, v32);
        _ReadStatusReg(SP_EL0);
        printk(&unk_3B423A, "rndis_ipa_pipe_connect_notify");
        if ( ipa_rndis_logbuf )
          v39 = ipc_log_string(
                  ipa_rndis_logbuf,
                  "RNDIS_IPA %s:%d fail on ep cfg\n",
                  "rndis_ipa_pipe_connect_notify",
                  864);
        goto LABEL_111;
      }
      v25 = &usb_to_ipa_ep_cfg_deaggr_dis;
      v24 = 44;
    }
    else
    {
      v20 = *(_QWORD *)a6;
      v21 = ipa_rndis_logbuf;
      *((_BYTE *)a6 + 26) = 1;
      v22 = *((unsigned __int8 *)a6 + 208);
      v23 = *(_DWORD *)(v20 + 56);
      if ( v21 )
      {
        ipc_log_string(v21, "RNDIS_IPA %s:%d deaggregation enabled\n", "rndis_ipa_ep_registers_cfg", 2145);
        v24 = 0;
        v25 = &usb_to_ipa_ep_cfg_deaggr_en;
        if ( (v22 & 1) != 0 )
          goto LABEL_35;
LABEL_27:
        v27 = 0;
        v28 = v24 + 14;
        v29 = 14;
        v30 = 58;
        goto LABEL_36;
      }
      v24 = 0;
      v25 = &usb_to_ipa_ep_cfg_deaggr_en;
    }
    if ( !v22 )
      goto LABEL_27;
    goto LABEL_35;
  }
  _ReadStatusReg(SP_EL0);
  printk(&unk_3D4C8B, "rndis_ipa_pipe_connect_notify");
  if ( !ipa_rndis_logbuf )
    goto LABEL_95;
  ipc_log_string(
    ipa_rndis_logbuf,
    "RNDIS_IPA %s:%d use init()/disconnect() before connect()\n",
    "rndis_ipa_pipe_connect_notify",
    824);
LABEL_69:
  result = 0xFFFFFFFFLL;
LABEL_113:
  _ReadStatusReg(SP_EL0);
  return result;
}
