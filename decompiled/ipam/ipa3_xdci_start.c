__int64 __fastcall ipa3_xdci_start(unsigned int a1, unsigned __int8 a2, char a3)
{
  __int64 v6; // x8
  unsigned int v7; // w20
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x25
  __int64 v11; // x25
  int v12; // t1
  const char *v13; // x8
  __int64 v14; // x0
  __int64 v15; // x9
  const char *v16; // x10
  int v17; // w0
  unsigned int v18; // w8
  unsigned int v19; // w0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  unsigned int v23; // w21
  int started; // w0
  unsigned int v25; // w8
  unsigned int v26; // w8
  int v27; // w0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  int v34; // w20
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  const char *v43; // x8
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  int v48; // w20
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  const char *v52; // x8
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  const char *v56; // [xsp+8h] [xbp-28h] BYREF
  char *v57; // [xsp+10h] [xbp-20h]
  __int64 v58; // [xsp+18h] [xbp-18h]
  unsigned int v59; // [xsp+20h] [xbp-10h] BYREF
  __int16 v60; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v61; // [xsp+28h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = ipa3_ctx;
  v60 = 0;
  v7 = *(_DWORD *)(ipa3_ctx + 34924);
  v59 = 0;
  if ( ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d entry\n", "ipa3_xdci_start", 908);
      v6 = ipa3_ctx;
    }
    v9 = *(_QWORD *)(v6 + 34160);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d entry\n", "ipa3_xdci_start", 908);
      v6 = ipa3_ctx;
    }
  }
  if ( *(_DWORD *)(v6 + 34308) <= a1 )
    goto LABEL_42;
  if ( a1 < 0x24 )
  {
    if ( (a2 & 0x80) == 0 )
    {
      v10 = v6 + 480LL * a1;
      v12 = *(_DWORD *)(v10 + 168);
      v11 = v10 + 168;
      if ( v12 )
      {
        v56 = nullptr;
        v57 = "ipa_client.c";
        v58 = 917;
        ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
          v13 = ipa_clients_strings[(unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1)];
        else
          v13 = "Invalid Client";
        v56 = v13;
        ipa3_inc_client_enable_clks();
        if ( (a3 & 1) == 0 )
          goto LABEL_15;
        v14 = *(_QWORD *)(v11 + 8);
        *(_DWORD *)(v11 + 88) = *(_DWORD *)(v11 + 88) & 0xF80FFFFF | (a2 << 20);
        v15 = *(_QWORD *)(v11 + 104);
        v16 = *(const char **)(v11 + 88);
        v57 = *(char **)(v11 + 96);
        v58 = v15;
        v56 = v16;
        v17 = gsi_write_channel_scratch(v14, &v56);
        if ( v17 )
        {
          v48 = v17;
          printk(&unk_3D5370, "ipa3_xdci_start");
          v49 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v50 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v50 )
            {
              ipc_log_string(v50, "ipa %s:%d Error writing channel scratch: %d\n", "ipa3_xdci_start", 924, v48);
              v49 = ipa3_ctx;
            }
            v51 = *(_QWORD *)(v49 + 34160);
            if ( v51 )
              ipc_log_string(v51, "ipa %s:%d Error writing channel scratch: %d\n", "ipa3_xdci_start", 924, v48);
          }
          v23 = -14;
        }
        else
        {
LABEL_15:
          v18 = *(_DWORD *)(v11 + 4);
          if ( v18 > 0x85 || (v18 & 1) != 0 || *(_BYTE *)(v11 + 404) != 1 )
          {
            v23 = -14;
            *(_BYTE *)(v11 + 468) = 0;
          }
          else
          {
            v60 = 256;
            *(_BYTE *)(v11 + 468) = 1;
            v19 = ipa_cfg_ep_ctrl(a1, &v60);
            if ( v19 )
            {
              v23 = v19;
              printk(&unk_3B7A7E, "ipa3_xdci_start");
              v53 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v54 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v54 )
                {
                  ipc_log_string(v54, "ipa %s:%d client (ep: %d) failed result=%d\n", "ipa3_xdci_start", 937, a1, v23);
                  v53 = ipa3_ctx;
                }
                v55 = *(_QWORD *)(v53 + 34160);
                if ( v55 )
                  ipc_log_string(v55, "ipa %s:%d client (ep: %d) failed result=%d\n", "ipa3_xdci_start", 937, a1, v23);
              }
            }
            else
            {
              v20 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_41;
              v21 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v21 )
              {
                ipc_log_string(v21, "ipa %s:%d client (ep: %d) success\n", "ipa3_xdci_start", 939, a1);
                v20 = ipa3_ctx;
              }
              v22 = *(_QWORD *)(v20 + 34160);
              if ( v22 )
              {
                ipc_log_string(v22, "ipa %s:%d client (ep: %d) success\n", "ipa3_xdci_start", 939, a1);
                v23 = 0;
              }
              else
              {
LABEL_41:
                v23 = 0;
              }
            }
          }
          started = gsi_start_channel(*(_QWORD *)(v11 + 8));
          if ( !started )
          {
            v25 = *(_DWORD *)(v11 + 4);
            if ( v25 - 87 <= 6 && ((1 << (v25 - 87)) & 0x55) != 0 || v25 <= 0x13 && ((1 << v25) & 0x82800) != 0 )
            {
              if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, _QWORD))ipa3_uc_client_add_holb_monitor)(
                                   *(unsigned __int16 *)(v11 + 8),
                                   3,
                                   v7,
                                   0) )
              {
                printk(&unk_3C68A9, "ipa3_xdci_start");
                v38 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v39 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v39 )
                  {
                    ipc_log_string(
                      v39,
                      "ipa %s:%d Add HOLB monitor failed for gsi ch %lu\n",
                      "ipa3_xdci_start",
                      956,
                      *(_QWORD *)(v11 + 8));
                    v38 = ipa3_ctx;
                  }
                  v40 = *(_QWORD *)(v38 + 34160);
                  if ( v40 )
                    ipc_log_string(
                      v40,
                      "ipa %s:%d Add HOLB monitor failed for gsi ch %lu\n",
                      "ipa3_xdci_start",
                      956,
                      *(_QWORD *)(v11 + 8));
                }
              }
            }
            v26 = *(_DWORD *)(v11 + 4);
            if ( v26 <= 0x85 && (v26 & 1) == 0 && *(_BYTE *)(v11 + 404) == 1 && *(_BYTE *)(ipa3_ctx + 32268) == 1 )
            {
              v27 = gsi_enable_flow_control_ee(*(unsigned int *)(v11 + 8), 0, &v59);
              v28 = ipa3_ctx;
              if ( v27 )
              {
                if ( ipa3_ctx )
                {
                  v29 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v29 )
                  {
                    ipc_log_string(
                      v29,
                      "ipa %s:%d failed to flow control gsi ch %lu code %d\n",
                      "ipa3_xdci_start",
                      969,
                      *(_QWORD *)(v11 + 8),
                      v59);
                    v28 = ipa3_ctx;
                  }
                  v30 = *(_QWORD *)(v28 + 34160);
                  if ( v30 )
                    ipc_log_string(
                      v30,
                      "ipa %s:%d failed to flow control gsi ch %lu code %d\n",
                      "ipa3_xdci_start",
                      969,
                      *(_QWORD *)(v11 + 8),
                      v59);
                }
              }
              else if ( ipa3_ctx )
              {
                v41 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v41 )
                {
                  ipc_log_string(
                    v41,
                    "ipa %s:%d flow control success gsi ch %lu with code %d\n",
                    "ipa3_xdci_start",
                    966,
                    *(_QWORD *)(v11 + 8),
                    v59);
                  v28 = ipa3_ctx;
                }
                v42 = *(_QWORD *)(v28 + 34160);
                if ( v42 )
                  ipc_log_string(
                    v42,
                    "ipa %s:%d flow control success gsi ch %lu with code %d\n",
                    "ipa3_xdci_start",
                    966,
                    *(_QWORD *)(v11 + 8),
                    v59);
              }
            }
            ipa3_start_gsi_debug_monitor(a1);
            if ( (*(_BYTE *)(v11 + 405) & 1) == 0 )
            {
              v57 = "ipa_client.c";
              v58 = 974;
              ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
              if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
                v43 = ipa_clients_strings[(unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1)];
              else
                v43 = "Invalid Client";
              v56 = v43;
              ipa3_dec_client_disable_clks();
            }
            v44 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v45 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v45 )
              {
                ipc_log_string(v45, "ipa %s:%d exit\n", "ipa3_xdci_start", 976);
                v44 = ipa3_ctx;
              }
              v46 = *(_QWORD *)(v44 + 34160);
              if ( v46 )
                ipc_log_string(v46, "ipa %s:%d exit\n", "ipa3_xdci_start", 976);
            }
            v23 = 0;
            goto LABEL_74;
          }
          v34 = started;
          printk(&unk_3DAEA8, "ipa3_xdci_start");
          v35 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v36 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v36 )
            {
              ipc_log_string(v36, "ipa %s:%d Error starting channel: %d\n", "ipa3_xdci_start", 946, v34);
              v35 = ipa3_ctx;
            }
            v37 = *(_QWORD *)(v35 + 34160);
            if ( v37 )
              ipc_log_string(v37, "ipa %s:%d Error starting channel: %d\n", "ipa3_xdci_start", 946, v34);
          }
        }
        v57 = "ipa_client.c";
        v58 = 980;
        ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
          v52 = ipa_clients_strings[(unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1)];
        else
          v52 = "Invalid Client";
        v56 = v52;
        ipa3_dec_client_disable_clks();
LABEL_74:
        _ReadStatusReg(SP_EL0);
        return v23;
      }
    }
LABEL_42:
    printk(&unk_3A948A, "ipa3_xdci_start");
    v31 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_47;
    v32 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v32 )
    {
      ipc_log_string(v32, "ipa %s:%d Bad parameters.\n", "ipa3_xdci_start", 912);
      v31 = ipa3_ctx;
    }
    v33 = *(_QWORD *)(v31 + 34160);
    if ( v33 )
    {
      ipc_log_string(v33, "ipa %s:%d Bad parameters.\n", "ipa3_xdci_start", 912);
      v23 = -22;
    }
    else
    {
LABEL_47:
      v23 = -22;
    }
    goto LABEL_74;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))ipa3_start_gsi_debug_monitor)();
}
