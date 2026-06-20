__int64 __fastcall ipa_mhi_suspend(char a1)
{
  __int64 ipc_logbuf; // x0
  long double v3; // q0
  __int64 ipc_logbuf_low; // x0
  unsigned int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x0
  long double v8; // q0
  __int64 v9; // x0
  unsigned int v10; // w0
  char v11; // w20
  long double v12; // q0
  __int64 v13; // x0
  long double v14; // q0
  __int64 v15; // x0
  __int64 v16; // x22
  __int64 v17; // x19
  int ch_ctx; // w0
  __int64 v19; // x0
  __int64 v20; // x0
  char v21; // w19
  unsigned int v22; // w0
  __int64 v23; // x0
  long double v24; // q0
  __int64 v25; // x0
  __int64 v26; // x0
  long double v27; // q0
  __int64 v28; // x0
  unsigned int v29; // w0
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned int v32; // w0
  unsigned int v33; // w0
  __int64 v34; // x0
  __int64 result; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  unsigned int v39; // w19
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  int v44; // w20
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  long double v51; // q0
  long double v52; // q0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  long double v58; // q0
  __int64 v59; // x0
  __int64 v60; // x0
  long double v61; // q0
  __int64 v62; // x0
  __int64 v63; // x0
  long double v64; // q0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  int v68; // w19
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  long double v73; // q0
  __int64 v74; // x0
  long double v75; // q0
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x0
  long double v79; // q0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0

  _ReadStatusReg(SP_EL0);
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_suspend", 1881);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v3 = ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_suspend", 1881);
  }
  if ( !(unsigned int)((__int64 (__fastcall *)(__int64, long double))ipa_mhi_set_state)(3, v3) )
  {
    v5 = ipa_mhi_suspend_channels(ipa_mhi_client_ctx + 440, 4);
    if ( v5 )
    {
      v39 = v5;
      printk(&unk_3AB47F, "ipa_mhi_suspend_dl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v40 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v40,
          "ipa_mhi_client %s:%d ipa_mhi_suspend_channels for dl failed %d\n",
          "ipa_mhi_suspend_dl",
          1828,
          v39);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v41 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v41,
          "ipa_mhi_client %s:%d ipa_mhi_suspend_channels for dl failed %d\n",
          "ipa_mhi_suspend_dl",
          1828,
          v39);
      }
      goto LABEL_102;
    }
    v6 = ipa_mhi_client_ctx;
    if ( *(_BYTE *)(ipa_mhi_client_ctx + 440) == 1 )
    {
      if ( (ipa3_has_open_aggr_frame(*(unsigned int *)(ipa_mhi_client_ctx + 444)) & 1) != 0 )
        goto LABEL_18;
      v6 = ipa_mhi_client_ctx;
    }
    if ( *(_BYTE *)(v6 + 640) == 1 )
    {
      if ( (ipa3_has_open_aggr_frame(*(unsigned int *)(v6 + 644)) & 1) != 0 )
        goto LABEL_18;
      v6 = ipa_mhi_client_ctx;
    }
    if ( *(_BYTE *)(v6 + 840) != 1 )
    {
LABEL_16:
      if ( *(_BYTE *)(v6 + 1040) != 1 || (ipa3_has_open_aggr_frame(*(unsigned int *)(v6 + 1044)) & 1) == 0 )
      {
LABEL_24:
        usleep_range_state(900, 1100, 2);
        v10 = ipa_mhi_suspend_channels(ipa_mhi_client_ctx + 40, 2);
        if ( v10 )
        {
          v39 = v10;
          printk(&unk_3DFA55, "ipa_mhi_suspend_ul");
          if ( ipa3_get_ipc_logbuf() )
          {
            v42 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v42,
              "ipa_mhi_client %s:%d ipa_mhi_suspend_ul_channels failed %d\n",
              "ipa_mhi_suspend_ul",
              1645,
              v39);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v43 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v43,
              "ipa_mhi_client %s:%d ipa_mhi_suspend_ul_channels failed %d\n",
              "ipa_mhi_suspend_ul",
              1645,
              v39);
          }
          v44 = 0;
        }
        else
        {
          v11 = ((__int64 (*)(void))ipa_mhi_wait_for_ul_empty_timeout)();
          if ( (v11 & 1) != 0 )
          {
            if ( (a1 & 1) != 0 )
            {
LABEL_44:
              v21 = 1;
              goto LABEL_62;
            }
            if ( ipa3_get_ipc_logbuf() )
            {
              v13 = ipa3_get_ipc_logbuf();
              ipc_log_string(v13, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_check_pending_packets_from_host", 1523);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v15 = ipa3_get_ipc_logbuf_low();
              v14 = ipc_log_string(v15, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_check_pending_packets_from_host", 1523);
            }
            v16 = ipa_mhi_client_ctx;
            v17 = ipa_mhi_client_ctx + 40;
            if ( *(_BYTE *)(ipa_mhi_client_ctx + 40) == 1 )
            {
              if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, long double))ipa3_mhi_query_ch_info)(
                                   *(unsigned int *)(ipa_mhi_client_ctx + 44),
                                   ipa_mhi_client_ctx + 56,
                                   v14) )
                goto LABEL_128;
              ch_ctx = ipa_mhi_read_ch_ctx(v17);
              if ( ch_ctx )
                goto LABEL_132;
              if ( *(_QWORD *)(v16 + 64) != *(_QWORD *)(v16 + 140) )
                goto LABEL_136;
              v16 = ipa_mhi_client_ctx;
            }
            v17 = v16 + 240;
            if ( *(_BYTE *)(v16 + 240) != 1 )
            {
LABEL_40:
              if ( ipa3_get_ipc_logbuf() )
              {
                v19 = ipa3_get_ipc_logbuf();
                ipc_log_string(v19, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_check_pending_packets_from_host", 1550);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v20 = ipa3_get_ipc_logbuf_low();
                v12 = ipc_log_string(
                        v20,
                        "ipa_mhi_client %s:%d EXIT\n",
                        "ipa_mhi_check_pending_packets_from_host",
                        1550);
              }
              goto LABEL_44;
            }
            if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD, __int64))ipa3_mhi_query_ch_info)(
                                  *(unsigned int *)(v16 + 244),
                                  v16 + 256) )
            {
              ch_ctx = ipa_mhi_read_ch_ctx(v16 + 240);
              if ( !ch_ctx )
              {
                if ( *(_QWORD *)(v16 + 264) == *(_QWORD *)(v16 + 340) )
                  goto LABEL_40;
LABEL_136:
                if ( ipa3_get_ipc_logbuf() )
                {
                  v81 = ipa3_get_ipc_logbuf();
                  ipc_log_string(
                    v81,
                    "ipa_mhi_client %s:%d There are pending packets from host\n",
                    "ipa_mhi_check_pending_packets_from_host",
                    1542);
                  if ( !ipa3_get_ipc_logbuf_low() )
                  {
LABEL_138:
                    if ( !ipa3_get_ipc_logbuf() )
                      goto LABEL_139;
                    goto LABEL_164;
                  }
                }
                else if ( !ipa3_get_ipc_logbuf_low() )
                {
                  goto LABEL_138;
                }
                v82 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(
                  v82,
                  "ipa_mhi_client %s:%d There are pending packets from host\n",
                  "ipa_mhi_check_pending_packets_from_host",
                  1542);
                if ( !ipa3_get_ipc_logbuf() )
                {
LABEL_139:
                  if ( !ipa3_get_ipc_logbuf_low() )
                  {
LABEL_141:
                    v44 = 0;
                    v39 = -11;
                    goto LABEL_142;
                  }
LABEL_140:
                  v71 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(
                    v71,
                    "ipa_mhi_client %s:%d device rp 0x%llx host 0x%llx\n",
                    "ipa_mhi_check_pending_packets_from_host",
                    1544,
                    *(_QWORD *)(v17 + 24),
                    *(_QWORD *)(v17 + 100));
                  goto LABEL_141;
                }
LABEL_164:
                v83 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v83,
                  "ipa_mhi_client %s:%d device rp 0x%llx host 0x%llx\n",
                  "ipa_mhi_check_pending_packets_from_host",
                  1544,
                  *(_QWORD *)(v17 + 24),
                  *(_QWORD *)(v17 + 100));
                if ( !ipa3_get_ipc_logbuf_low() )
                  goto LABEL_141;
                goto LABEL_140;
              }
LABEL_132:
              v68 = ch_ctx;
              printk(&unk_3BC800, "ipa_mhi_check_pending_packets_from_host");
              if ( ipa3_get_ipc_logbuf() )
              {
                v69 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v69,
                  "ipa_mhi_client %s:%d ipa_mhi_read_ch_ctx failed %d\n",
                  "ipa_mhi_check_pending_packets_from_host",
                  1537,
                  v68);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v70 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(
                  v70,
                  "ipa_mhi_client %s:%d ipa_mhi_read_ch_ctx failed %d\n",
                  "ipa_mhi_check_pending_packets_from_host",
                  1537,
                  v68);
              }
              goto LABEL_141;
            }
LABEL_128:
            printk(&unk_3A52AB, "ipa_mhi_check_pending_packets_from_host");
            if ( ipa3_get_ipc_logbuf() )
            {
              v66 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v66,
                "ipa_mhi_client %s:%d gsi_query_channel_info failed\n",
                "ipa_mhi_check_pending_packets_from_host",
                1532);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v67 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v67,
                "ipa_mhi_client %s:%d gsi_query_channel_info failed\n",
                "ipa_mhi_check_pending_packets_from_host",
                1532);
            }
            goto LABEL_141;
          }
          if ( (a1 & 1) == 0 )
          {
            if ( ipa3_get_ipc_logbuf() )
            {
              v55 = ipa3_get_ipc_logbuf();
              ipc_log_string(v55, "ipa_mhi_client %s:%d IPA not empty\n", "ipa_mhi_suspend_ul", 1677);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v56 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v56, "ipa_mhi_client %s:%d IPA not empty\n", "ipa_mhi_suspend_ul", 1677);
            }
            goto LABEL_141;
          }
          v22 = ((__int64 (__fastcall *)(_QWORD))ipa_mhi_enable_force_clear)(*(unsigned int *)(ipa_mhi_client_ctx + 1296));
          if ( !v22 )
          {
            if ( ipa3_get_ipc_logbuf() )
            {
              v23 = ipa3_get_ipc_logbuf();
              ipc_log_string(v23, "ipa_mhi_client %s:%d force clear datapath enabled\n", "ipa_mhi_suspend_ul", 1662);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v25 = ipa3_get_ipc_logbuf_low();
              v24 = ipc_log_string(
                      v25,
                      "ipa_mhi_client %s:%d force clear datapath enabled\n",
                      "ipa_mhi_suspend_ul",
                      1662);
            }
            v21 = ipa_mhi_wait_for_ul_empty_timeout(v24);
            if ( ipa3_get_ipc_logbuf() )
            {
              v26 = ipa3_get_ipc_logbuf();
              ipc_log_string(v26, "ipa_mhi_client %s:%d empty=%d\n", "ipa_mhi_suspend_ul", 1666, v21 & 1);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v28 = ipa3_get_ipc_logbuf_low();
              v27 = ipc_log_string(v28, "ipa_mhi_client %s:%d empty=%d\n", "ipa_mhi_suspend_ul", 1666, v21 & 1);
            }
            if ( (v21 & 1) == 0 )
            {
              printk(&unk_3A8401, "ipa_mhi_suspend_ul");
              if ( ipa3_get_ipc_logbuf() )
              {
                v60 = ipa3_get_ipc_logbuf();
                ipc_log_string(v60, "ipa_mhi_client %s:%d Failed to suspend UL channels\n", "ipa_mhi_suspend_ul", 1668);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v62 = ipa3_get_ipc_logbuf_low();
                v61 = ipc_log_string(
                        v62,
                        "ipa_mhi_client %s:%d Failed to suspend UL channels\n",
                        "ipa_mhi_suspend_ul",
                        1668);
              }
              if ( (*(_BYTE *)(ipa_mhi_client_ctx + 1305) & 1) != 0 )
              {
                v39 = -11;
LABEL_127:
                v44 = 1;
                goto LABEL_142;
              }
              ((void (__fastcall *)(long double))ipa_assert)(v61);
            }
            v29 = ipa_mhi_disable_force_clear(*(unsigned int *)(ipa_mhi_client_ctx + 1296), v27);
            if ( !v29 )
            {
              if ( ipa3_get_ipc_logbuf() )
              {
                v30 = ipa3_get_ipc_logbuf();
                ipc_log_string(v30, "ipa_mhi_client %s:%d force clear datapath disabled\n", "ipa_mhi_suspend_ul", 1691);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v31 = ipa3_get_ipc_logbuf_low();
                v12 = ipc_log_string(
                        v31,
                        "ipa_mhi_client %s:%d force clear datapath disabled\n",
                        "ipa_mhi_suspend_ul",
                        1691);
              }
              ++*(_DWORD *)(ipa_mhi_client_ctx + 1296);
LABEL_62:
              ipa_mhi_update_host_ch_state(1, v12);
              ipa3_inc_client_enable_clks();
              v32 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa_mhi_client_ctx + 1308));
              if ( v32 )
              {
                v39 = v32;
                printk(&unk_3BF479, "ipa_mhi_suspend");
                if ( ipa3_get_ipc_logbuf() )
                {
                  v45 = ipa3_get_ipc_logbuf();
                  ipc_log_string(
                    v45,
                    "ipa_mhi_client %s:%d fail to deactivate client %d\n",
                    "ipa_mhi_suspend",
                    1914,
                    v39);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v46 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(
                    v46,
                    "ipa_mhi_client %s:%d fail to deactivate client %d\n",
                    "ipa_mhi_suspend",
                    1914,
                    v39);
                }
              }
              else
              {
                v33 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa_mhi_client_ctx
                                                                                               + 1312));
                if ( v33 )
                {
                  v39 = v33;
                  printk(&unk_3BF479, "ipa_mhi_suspend");
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v47 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v47,
                      "ipa_mhi_client %s:%d fail to deactivate client %d\n",
                      "ipa_mhi_suspend",
                      1919,
                      v39);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v48 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v48,
                      "ipa_mhi_client %s:%d fail to deactivate client %d\n",
                      "ipa_mhi_suspend",
                      1919,
                      v39);
                  }
                }
                else
                {
                  usleep_range_state(900, 1100, 2);
                  if ( (v21 & 1) == 0 )
                    ipa3_set_tag_process_before_gating(0);
                  if ( !(unsigned int)((__int64 (__fastcall *)(__int64))ipa_mhi_set_state)(4) )
                  {
                    ipa3_dec_client_disable_clks();
                    if ( ipa3_get_ipc_logbuf() )
                    {
                      v34 = ipa3_get_ipc_logbuf();
                      ipc_log_string(v34, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_suspend", 1934);
                    }
                    result = ipa3_get_ipc_logbuf_low();
                    if ( result )
                    {
                      v36 = ipa3_get_ipc_logbuf_low();
                      ipc_log_string(v36, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_suspend", 1934);
                      result = 0;
                    }
                    goto LABEL_155;
                  }
                  printk(&unk_3F64F3, "ipa_mhi_suspend");
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v49 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v49,
                      "ipa_mhi_client %s:%d ipa_mhi_set_state failed %d\n",
                      "ipa_mhi_suspend",
                      1929,
                      -1);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v50 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v50,
                      "ipa_mhi_client %s:%d ipa_mhi_set_state failed %d\n",
                      "ipa_mhi_suspend",
                      1929,
                      -1);
                  }
                  ipa_pm_activate_sync(*(_DWORD *)(ipa_mhi_client_ctx + 1312));
                  v39 = -1;
                }
                ipa_pm_activate_sync(*(_DWORD *)(ipa_mhi_client_ctx + 1308));
              }
              ipa3_dec_client_disable_clks();
              ipa_mhi_resume_channels(1, ipa_mhi_client_ctx + 40, 2, v51);
              if ( (v11 & 1) != 0 )
              {
LABEL_154:
                ipa_mhi_resume_channels(1, ipa_mhi_client_ctx + 440, 4, v52);
                ((void (__fastcall *)(__int64))ipa_mhi_set_state)(2);
                result = v39;
                goto LABEL_155;
              }
LABEL_148:
              if ( (unsigned int)ipa_mhi_disable_force_clear(*(unsigned int *)(ipa_mhi_client_ctx + 1296), v52) )
              {
                printk(&unk_3E23EA, "ipa_mhi_suspend");
                if ( ipa3_get_ipc_logbuf() )
                {
                  v78 = ipa3_get_ipc_logbuf();
                  ipc_log_string(v78, "ipa_mhi_client %s:%d failed to disable force clear\n", "ipa_mhi_suspend", 1949);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v80 = ipa3_get_ipc_logbuf_low();
                  v79 = ipc_log_string(
                          v80,
                          "ipa_mhi_client %s:%d failed to disable force clear\n",
                          "ipa_mhi_suspend",
                          1949);
                }
                ((void (__fastcall *)(long double))ipa_assert)(v79);
                if ( !ipa3_get_ipc_logbuf() )
                  goto LABEL_151;
              }
              else if ( !ipa3_get_ipc_logbuf() )
              {
LABEL_151:
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v77 = ipa3_get_ipc_logbuf_low();
                  v52 = ipc_log_string(
                          v77,
                          "ipa_mhi_client %s:%d force clear datapath disabled\n",
                          "ipa_mhi_suspend",
                          1952);
                }
                ++*(_DWORD *)(ipa_mhi_client_ctx + 1296);
                goto LABEL_154;
              }
              v76 = ipa3_get_ipc_logbuf();
              ipc_log_string(v76, "ipa_mhi_client %s:%d force clear datapath disabled\n", "ipa_mhi_suspend", 1952);
              goto LABEL_151;
            }
            v39 = v29;
            printk(&unk_3E23EA, "ipa_mhi_suspend_ul");
            if ( ipa3_get_ipc_logbuf() )
            {
              v63 = ipa3_get_ipc_logbuf();
              ipc_log_string(v63, "ipa_mhi_client %s:%d failed to disable force clear\n", "ipa_mhi_suspend_ul", 1687);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v65 = ipa3_get_ipc_logbuf_low();
              v64 = ipc_log_string(
                      v65,
                      "ipa_mhi_client %s:%d failed to disable force clear\n",
                      "ipa_mhi_suspend_ul",
                      1687);
            }
            ((void (__fastcall *)(long double))ipa_assert)(v64);
            goto LABEL_127;
          }
          v39 = v22;
          printk(&unk_3EACE0, "ipa_mhi_suspend_ul");
          if ( ipa3_get_ipc_logbuf() )
          {
            v57 = ipa3_get_ipc_logbuf();
            ipc_log_string(v57, "ipa_mhi_client %s:%d failed to enable force clear\n", "ipa_mhi_suspend_ul", 1657);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v59 = ipa3_get_ipc_logbuf_low();
            v58 = ipc_log_string(v59, "ipa_mhi_client %s:%d failed to enable force clear\n", "ipa_mhi_suspend_ul", 1657);
          }
          ((void (__fastcall *)(long double))ipa_assert)(v58);
          v44 = 0;
        }
LABEL_142:
        printk(&unk_3D4151, "ipa_mhi_suspend");
        if ( ipa3_get_ipc_logbuf() )
        {
          v72 = ipa3_get_ipc_logbuf();
          ipc_log_string(v72, "ipa_mhi_client %s:%d ipa_mhi_suspend_ul failed %d\n", "ipa_mhi_suspend", 1899, v39);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v74 = ipa3_get_ipc_logbuf_low();
          v75 = ipc_log_string(v74, "ipa_mhi_client %s:%d ipa_mhi_suspend_ul failed %d\n", "ipa_mhi_suspend", 1899, v39);
          ipa_mhi_resume_channels(1, ipa_mhi_client_ctx + 40, 2, v75);
          if ( (v44 & 1) == 0 )
            goto LABEL_154;
        }
        else
        {
          ipa_mhi_resume_channels(1, ipa_mhi_client_ctx + 40, 2, v73);
          if ( !v44 )
            goto LABEL_154;
        }
        goto LABEL_148;
      }
      goto LABEL_18;
    }
    if ( (ipa3_has_open_aggr_frame(*(unsigned int *)(v6 + 844)) & 1) == 0 )
    {
      v6 = ipa_mhi_client_ctx;
      goto LABEL_16;
    }
LABEL_18:
    if ( ipa3_get_ipc_logbuf() )
    {
      v7 = ipa3_get_ipc_logbuf();
      ipc_log_string(v7, "ipa_mhi_client %s:%d There is an open aggr frame\n", "ipa_mhi_suspend_dl", 1841);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      v8 = ipc_log_string(v9, "ipa_mhi_client %s:%d There is an open aggr frame\n", "ipa_mhi_suspend_dl", 1841);
    }
    if ( (a1 & 1) != 0 )
    {
      *(_BYTE *)(ipa_mhi_client_ctx + 24) = 1;
      goto LABEL_24;
    }
    ipa_mhi_resume_channels(1, ipa_mhi_client_ctx + 440, 4, v8);
    v39 = -11;
LABEL_102:
    printk(&unk_3F9900, "ipa_mhi_suspend");
    if ( ipa3_get_ipc_logbuf() )
    {
      v53 = ipa3_get_ipc_logbuf();
      ipc_log_string(v53, "ipa_mhi_client %s:%d ipa_mhi_suspend_dl failed %d\n", "ipa_mhi_suspend", 1891, v39);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v54 = ipa3_get_ipc_logbuf_low();
      v52 = ipc_log_string(v54, "ipa_mhi_client %s:%d ipa_mhi_suspend_dl failed %d\n", "ipa_mhi_suspend", 1891, v39);
    }
    goto LABEL_154;
  }
  printk(&unk_3F64F3, "ipa_mhi_suspend");
  if ( ipa3_get_ipc_logbuf() )
  {
    v37 = ipa3_get_ipc_logbuf();
    ipc_log_string(v37, "ipa_mhi_client %s:%d ipa_mhi_set_state failed %d\n", "ipa_mhi_suspend", 1885, -1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v38 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v38, "ipa_mhi_client %s:%d ipa_mhi_set_state failed %d\n", "ipa_mhi_suspend", 1885, -1);
  }
  result = 0xFFFFFFFFLL;
LABEL_155:
  _ReadStatusReg(SP_EL0);
  return result;
}
