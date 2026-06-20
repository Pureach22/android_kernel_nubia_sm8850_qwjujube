__int64 __fastcall ipa3_suspend_gsi_wdi_pipe(unsigned int a1)
{
  __int64 v2; // x0
  __int64 ep_mapping; // x0
  __int64 v4; // x13
  unsigned int v5; // w21
  __int64 v6; // x8
  __int64 v7; // x25
  unsigned int v8; // w8
  int v9; // w19
  int ep_bit; // w20
  unsigned int ep_reg_idx; // w22
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  int v15; // w0
  int v16; // w22
  __int64 v17; // x0
  unsigned int v18; // w20
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  unsigned int v34; // w9
  __int64 v35; // x11
  bool v36; // w9
  __int64 v37; // x10
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  int v44; // w20
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v54; // [xsp+20h] [xbp-50h] BYREF
  __int64 v55; // [xsp+28h] [xbp-48h]
  __int64 v56; // [xsp+30h] [xbp-40h]
  __int64 v57; // [xsp+38h] [xbp-38h] BYREF
  __int64 v58; // [xsp+40h] [xbp-30h]
  __int64 v59; // [xsp+48h] [xbp-28h]
  __int64 v60; // [xsp+50h] [xbp-20h]
  __int64 v61; // [xsp+58h] [xbp-18h]
  _BYTE v62[4]; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+68h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62[0] = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v2 = ((__int64 (*)(void))ipa3_get_client_mapping)();
  ep_mapping = ipa_get_ep_mapping(v2);
  if ( (ep_mapping & 0x80000000) != 0 )
  {
    printk(&unk_3CA4F4, "ipa3_suspend_gsi_wdi_pipe");
    v38 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_77;
    v39 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v39 )
    {
      ipc_log_string(v39, "ipa %s:%d IPA client mapping failed\n", "ipa3_suspend_gsi_wdi_pipe", 2852);
      v38 = ipa3_ctx;
    }
    v40 = *(_QWORD *)(v38 + 34160);
    if ( v40 )
    {
      ipc_log_string(v40, "ipa %s:%d IPA client mapping failed\n", "ipa3_suspend_gsi_wdi_pipe", 2852);
      v18 = -1;
    }
    else
    {
LABEL_77:
      v18 = -1;
    }
  }
  else
  {
    v5 = ep_mapping;
    if ( (unsigned int)ep_mapping >= 0x25 )
    {
      __break(0x5512u);
      *(_QWORD *)ep_mapping = v4;
      JUMPOUT(0x117F84);
    }
    v6 = ipa3_ctx;
    v7 = ipa3_ctx + 480LL * (unsigned int)ep_mapping;
    if ( *(_DWORD *)(v7 + 620) == 7 )
    {
      if ( *(_DWORD *)(v7 + 168) )
      {
        v8 = *(_DWORD *)(v7 + 172);
        v9 = 0;
        if ( v8 <= 0x85 && (v8 & 1) == 0 )
        {
          ep_bit = ipahal_get_ep_bit((unsigned int)ep_mapping);
          ep_reg_idx = ipahal_get_ep_reg_idx(v5);
          v12 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v13 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v13 )
            {
              ipc_log_string(v13, "ipa %s:%d suspended pipe %d\n", "ipa3_suspend_gsi_wdi_pipe", 2867, v5);
              v12 = ipa3_ctx;
            }
            v14 = *(_QWORD *)(v12 + 34160);
            if ( v14 )
              ipc_log_string(v14, "ipa %s:%d suspended pipe %d\n", "ipa3_suspend_gsi_wdi_pipe", 2867, v5);
          }
          v15 = ipa3_enable_force_clear((_QWORD *)a1, 0, ep_bit, ep_reg_idx);
          if ( v15 )
          {
            v44 = v15;
            printk(&unk_3C4C92, "ipa3_suspend_gsi_wdi_pipe");
            v45 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v46 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v46 )
              {
                ipc_log_string(v46, "ipa %s:%d failed to force clear %d\n", "ipa3_suspend_gsi_wdi_pipe", 2876, v44);
                v45 = ipa3_ctx;
              }
              v47 = *(_QWORD *)(v45 + 34160);
              if ( v47 )
                ipc_log_string(v47, "ipa %s:%d failed to force clear %d\n", "ipa3_suspend_gsi_wdi_pipe", 2876, v44);
            }
            printk(&unk_3F8C0B, "ipa3_suspend_gsi_wdi_pipe");
            v48 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v49 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v49 )
              {
                ipc_log_string(v49, "ipa %s:%d remove delay from SCND reg\n", "ipa3_suspend_gsi_wdi_pipe", 2877);
                v48 = ipa3_ctx;
              }
              v50 = *(_QWORD *)(v48 + 34160);
              if ( v50 )
              {
                ipc_log_string(v50, "ipa %s:%d remove delay from SCND reg\n", "ipa3_suspend_gsi_wdi_pipe", 2877);
                v48 = ipa3_ctx;
              }
            }
            if ( *(_BYTE *)(v48 + 50153) == 1 )
            {
              ipa3_remove_secondary_flow_ctrl(*(unsigned int *)(v7 + 176));
            }
            else
            {
              v62[0] = 0;
              ((void (__fastcall *)(__int64, _QWORD, _BYTE *))ipahal_write_reg_n_fields)(50, a1, v62);
            }
            v9 = 0;
          }
          else
          {
            v9 = 1;
          }
        }
        v16 = 0;
        while ( 1 )
        {
          v17 = ipa_stop_gsi_channel(v5);
          v18 = v17;
          if ( (_DWORD)v17 != -12 )
            break;
          v19 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v20 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v20 )
            {
              ipc_log_string(
                v20,
                "ipa %s:%d GSI stop channel failed retry cnt = %d\n",
                "ipa3_suspend_gsi_wdi_pipe",
                2899,
                v16);
              v19 = ipa3_ctx;
            }
            v17 = *(_QWORD *)(v19 + 34160);
            if ( v17 )
              v17 = ipc_log_string(
                      v17,
                      "ipa %s:%d GSI stop channel failed retry cnt = %d\n",
                      "ipa3_suspend_gsi_wdi_pipe",
                      2899,
                      v16);
          }
          if ( ++v16 == 10 )
            goto LABEL_96;
        }
        if ( (_DWORD)v17 != -11 && (_DWORD)v17 )
        {
          v17 = printk(&unk_3E17F2, "ipa3_suspend_gsi_wdi_pipe");
          v51 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v52 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v52 )
            {
              ipc_log_string(v52, "ipa %s:%d failed to stop channel res = %d\n", "ipa3_suspend_gsi_wdi_pipe", 2895, v18);
              v51 = ipa3_ctx;
            }
            v17 = *(_QWORD *)(v51 + 34160);
            if ( v17 )
              v17 = ipc_log_string(
                      v17,
                      "ipa %s:%d failed to stop channel res = %d\n",
                      "ipa3_suspend_gsi_wdi_pipe",
                      2895,
                      v18);
          }
LABEL_96:
          ((void (__fastcall *)(__int64))ipa_assert)(v17);
          goto LABEL_97;
        }
        v21 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v22 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v22 )
          {
            ipc_log_string(
              v22,
              "ipa %s:%d GSI channel %ld STOP\n",
              "ipa3_suspend_gsi_wdi_pipe",
              2905,
              *(_QWORD *)(v7 + 176));
            v21 = ipa3_ctx;
          }
          v23 = *(_QWORD *)(v21 + 34160);
          if ( v23 )
            ipc_log_string(
              v23,
              "ipa %s:%d GSI channel %ld STOP\n",
              "ipa3_suspend_gsi_wdi_pipe",
              2905,
              *(_QWORD *)(v7 + 176));
        }
        gsi_query_channel_info(*(_QWORD *)(v7 + 176), &v57);
        gsi_read_channel_scratch(*(_QWORD *)(v7 + 176), &v54);
        v6 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v24 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v24 )
          {
            ipc_log_string(
              v24,
              "ipa %s:%d ch=%lu channel base = 0x%llx , event base 0x%llx\n",
              "ipa3_suspend_gsi_wdi_pipe",
              2912,
              *(_QWORD *)(v7 + 176),
              *(_QWORD *)(v7 + 224),
              *(_QWORD *)(v7 + 200));
            v6 = ipa3_ctx;
          }
          v25 = *(_QWORD *)(v6 + 34160);
          if ( v25 )
          {
            ipc_log_string(
              v25,
              "ipa %s:%d ch=%lu channel base = 0x%llx , event base 0x%llx\n",
              "ipa3_suspend_gsi_wdi_pipe",
              2912,
              *(_QWORD *)(v7 + 176),
              *(_QWORD *)(v7 + 224),
              *(_QWORD *)(v7 + 200));
            v6 = ipa3_ctx;
          }
          if ( v6 )
          {
            v26 = *(_QWORD *)(v6 + 34152);
            if ( v26 )
            {
              ipc_log_string(
                v26,
                "ipa %s:%d RP=0x%llx WP=0x%llx ev_valid=%d ERP=0x%llx",
                "ipa3_suspend_gsi_wdi_pipe",
                2915,
                v58,
                v57,
                (unsigned __int8)v59,
                v61);
              v6 = ipa3_ctx;
            }
            v27 = *(_QWORD *)(v6 + 34160);
            if ( v27 )
            {
              ipc_log_string(
                v27,
                "ipa %s:%d RP=0x%llx WP=0x%llx ev_valid=%d ERP=0x%llx",
                "ipa3_suspend_gsi_wdi_pipe",
                2915,
                v58,
                v57,
                (unsigned __int8)v59,
                v61);
              v6 = ipa3_ctx;
            }
            if ( v6 )
            {
              v28 = *(_QWORD *)(v6 + 34152);
              if ( v28 )
              {
                ipc_log_string(v28, "ipa %s:%d EWP=0x%llx\n", "ipa3_suspend_gsi_wdi_pipe", 2916, v60);
                v6 = ipa3_ctx;
              }
              v29 = *(_QWORD *)(v6 + 34160);
              if ( v29 )
              {
                ipc_log_string(v29, "ipa %s:%d EWP=0x%llx\n", "ipa3_suspend_gsi_wdi_pipe", 2916, v60);
                v6 = ipa3_ctx;
              }
              if ( v6 )
              {
                v30 = *(_QWORD *)(v6 + 34152);
                if ( v30 )
                {
                  ipc_log_string(
                    v30,
                    "ipa %s:%d Scratch 0 = %x Scratch 1 = %x Scratch 2 = %x",
                    "ipa3_suspend_gsi_wdi_pipe",
                    2919,
                    v54,
                    HIDWORD(v54),
                    v55);
                  v6 = ipa3_ctx;
                }
                v31 = *(_QWORD *)(v6 + 34160);
                if ( v31 )
                {
                  ipc_log_string(
                    v31,
                    "ipa %s:%d Scratch 0 = %x Scratch 1 = %x Scratch 2 = %x",
                    "ipa3_suspend_gsi_wdi_pipe",
                    2919,
                    v54,
                    HIDWORD(v54),
                    v55);
                  v6 = ipa3_ctx;
                }
                if ( v6 )
                {
                  v32 = *(_QWORD *)(v6 + 34152);
                  if ( v32 )
                  {
                    ipc_log_string(v32, "ipa %s:%d Scratch 3 = %x\n", "ipa3_suspend_gsi_wdi_pipe", 2920, HIDWORD(v55));
                    v6 = ipa3_ctx;
                  }
                  v33 = *(_QWORD *)(v6 + 34160);
                  if ( v33 )
                  {
                    ipc_log_string(v33, "ipa %s:%d Scratch 3 = %x\n", "ipa3_suspend_gsi_wdi_pipe", 2920, HIDWORD(v55));
                    v6 = ipa3_ctx;
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v9 = 0;
        v18 = 0;
      }
      v34 = *(_DWORD *)(v6 + 32240);
      if ( v34 < 0x11 || v34 <= 0x17 && ((1 << v34) & 0x940000) != 0 )
      {
        if ( !v9 )
        {
LABEL_60:
          ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
          if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
            ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
          ipa3_dec_client_disable_clks();
          *(_DWORD *)(v7 + 620) &= ~4u;
          goto LABEL_97;
        }
      }
      else
      {
        v35 = 45281;
        v36 = *(_DWORD *)(v7 + 172) < 0x86u && (*(_DWORD *)(v7 + 172) & 1) == 0;
        v37 = 45280;
        if ( v36 )
        {
          v35 = 45279;
          v37 = 45278;
        }
        *(_BYTE *)(v6 + v35) = -1;
        *(_BYTE *)(v6 + v37) = v36;
        ipa3_uc_debug_stats_alloc(
          *(_QWORD *)(ipa3_ctx + 45274),
          *(unsigned int *)(ipa3_ctx + 45282) | ((unsigned __int64)*(unsigned __int16 *)(ipa3_ctx + 45286) << 32));
        if ( !v9 )
          goto LABEL_60;
      }
      ipa3_disable_force_clear(a1);
      goto LABEL_60;
    }
    printk(&unk_3C4C2C, "ipa3_suspend_gsi_wdi_pipe");
    v41 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_78;
    v42 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v42 )
    {
      ipc_log_string(
        v42,
        "ipa %s:%d WDI channel bad state %d\n",
        "ipa3_suspend_gsi_wdi_pipe",
        2859,
        *(_DWORD *)(v7 + 620));
      v41 = ipa3_ctx;
    }
    v43 = *(_QWORD *)(v41 + 34160);
    if ( v43 )
    {
      ipc_log_string(
        v43,
        "ipa %s:%d WDI channel bad state %d\n",
        "ipa3_suspend_gsi_wdi_pipe",
        2859,
        *(_DWORD *)(v7 + 620));
      v18 = -14;
    }
    else
    {
LABEL_78:
      v18 = -14;
    }
  }
LABEL_97:
  _ReadStatusReg(SP_EL0);
  return v18;
}
