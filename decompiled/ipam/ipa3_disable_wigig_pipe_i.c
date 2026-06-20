__int64 __fastcall ipa3_disable_wigig_pipe_i(unsigned int a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  unsigned int ep_mapping; // w0
  unsigned int v6; // w19
  __int64 v7; // x8
  __int64 v8; // x24
  _DWORD *v9; // x24
  int v10; // t1
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w8
  int v14; // w25
  int ep_bit; // w20
  unsigned int ep_reg_idx; // w0
  int v17; // w0
  int v18; // w20
  unsigned int v19; // w0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w0
  __int64 result; // x0
  unsigned int v28; // w19
  unsigned int v29; // w8
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  int v47; // w20
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x8
  __int64 v55; // x0
  __int64 v56; // x0
  __int16 v57[2]; // [xsp+20h] [xbp-10h] BYREF
  _BYTE v58[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v59; // [xsp+28h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  v58[0] = 0;
  v57[0] = 0;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d \n", "ipa3_disable_wigig_pipe_i", 1797);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d \n", "ipa3_disable_wigig_pipe_i", 1797);
  }
  ep_mapping = ipa_get_ep_mapping(a1);
  if ( ep_mapping == -1 )
  {
    printk(&unk_3CD9BE, "ipa3_disable_wigig_pipe_i");
    v32 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v33 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v33 )
      {
        ipc_log_string(v33, "ipa %s:%d fail to get ep (%d) %d.\n", "ipa3_disable_wigig_pipe_i", 1802, a1, -1);
        v32 = ipa3_ctx;
      }
      v34 = *(_QWORD *)(v32 + 34160);
      if ( v34 )
        ipc_log_string(v34, "ipa %s:%d fail to get ep (%d) %d.\n", "ipa3_disable_wigig_pipe_i", 1802, a1, -1);
    }
    goto LABEL_73;
  }
  v6 = ep_mapping;
  if ( ep_mapping >= (unsigned int)ipa3_get_max_num_pipes() )
  {
    printk(&unk_3BEF0C, "ipa3_disable_wigig_pipe_i");
    v35 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v36 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v36 )
      {
        ipc_log_string(v36, "ipa %s:%d ep %d out of range.\n", "ipa3_disable_wigig_pipe_i", 1806, v6);
        v35 = ipa3_ctx;
      }
      v37 = *(_QWORD *)(v35 + 34160);
      if ( v37 )
        ipc_log_string(v37, "ipa %s:%d ep %d out of range.\n", "ipa3_disable_wigig_pipe_i", 1806, v6);
    }
    goto LABEL_73;
  }
  if ( v6 < 0x25 )
  {
    v7 = ipa3_ctx;
    v8 = ipa3_ctx + 480LL * v6;
    v10 = *(_DWORD *)(v8 + 168);
    v9 = (_DWORD *)(v8 + 168);
    if ( v10 )
    {
      if ( v9[113] == 3 )
      {
        if ( ipa3_ctx )
        {
          v11 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v11 )
          {
            ipc_log_string(v11, "ipa %s:%d pipe %d\n", "ipa3_disable_wigig_pipe_i", 1824, v6);
            v7 = ipa3_ctx;
          }
          v12 = *(_QWORD *)(v7 + 34160);
          if ( v12 )
            ipc_log_string(v12, "ipa %s:%d pipe %d\n", "ipa3_disable_wigig_pipe_i", 1824, v6);
        }
        v13 = v9[1];
        v14 = 0;
        if ( v13 <= 0x85 && (v13 & 1) == 0 )
        {
          ep_bit = ipahal_get_ep_bit(v6);
          ep_reg_idx = ipahal_get_ep_reg_idx(v6);
          v17 = ipa3_enable_force_clear((_QWORD *)v6, 0, ep_bit, ep_reg_idx);
          if ( v17 )
          {
            v47 = v17;
            printk(&unk_3C4C92, "ipa3_disable_wigig_pipe_i");
            v48 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v49 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v49 )
              {
                ipc_log_string(v49, "ipa %s:%d failed to force clear %d\n", "ipa3_disable_wigig_pipe_i", 1836, v47);
                v48 = ipa3_ctx;
              }
              v50 = *(_QWORD *)(v48 + 34160);
              if ( v50 )
                ipc_log_string(v50, "ipa %s:%d failed to force clear %d\n", "ipa3_disable_wigig_pipe_i", 1836, v47);
            }
            printk(&unk_3F8C0B, "ipa3_disable_wigig_pipe_i");
            v51 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v52 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v52 )
              {
                ipc_log_string(v52, "ipa %s:%d remove delay from SCND reg\n", "ipa3_disable_wigig_pipe_i", 1837);
                v51 = ipa3_ctx;
              }
              v53 = *(_QWORD *)(v51 + 34160);
              if ( v53 )
              {
                ipc_log_string(v53, "ipa %s:%d remove delay from SCND reg\n", "ipa3_disable_wigig_pipe_i", 1837);
                v51 = ipa3_ctx;
              }
            }
            if ( *(_BYTE *)(v51 + 50153) == 1 )
            {
              ipa3_remove_secondary_flow_ctrl((unsigned int)v9[2]);
            }
            else
            {
              v58[0] = 0;
              ((void (__fastcall *)(__int64, _QWORD, _BYTE *))ipahal_write_reg_n_fields)(50, v6, v58);
            }
            v14 = 0;
          }
          else
          {
            v14 = 1;
          }
        }
        v18 = 0;
        while ( 1 )
        {
          v19 = ipa_stop_gsi_channel(v6);
          if ( v19 != -12 )
            break;
          v20 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v21 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v21 )
            {
              ipc_log_string(
                v21,
                "ipa %s:%d GSI stop channel failed retry cnt = %d\n",
                "ipa3_disable_wigig_pipe_i",
                1860,
                v18);
              v20 = ipa3_ctx;
            }
            v22 = *(_QWORD *)(v20 + 34160);
            if ( v22 )
              ipc_log_string(
                v22,
                "ipa %s:%d GSI stop channel failed retry cnt = %d\n",
                "ipa3_disable_wigig_pipe_i",
                1860,
                v18);
          }
          if ( ++v18 == 10 )
          {
            v28 = -12;
LABEL_41:
            ((void (*)(void))ipa_assert)();
            result = v28;
            goto LABEL_74;
          }
        }
        if ( v19 != -11 && v19 )
        {
          v28 = v19;
          printk(&unk_3E17F2, "ipa3_disable_wigig_pipe_i");
          v54 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v55 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v55 )
            {
              ipc_log_string(v55, "ipa %s:%d failed to stop channel res = %d\n", "ipa3_disable_wigig_pipe_i", 1856, v28);
              v54 = ipa3_ctx;
            }
            v56 = *(_QWORD *)(v54 + 34160);
            if ( v56 )
              ipc_log_string(v56, "ipa %s:%d failed to stop channel res = %d\n", "ipa3_disable_wigig_pipe_i", 1856, v28);
          }
          goto LABEL_41;
        }
        v23 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v24 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v24 )
          {
            ipc_log_string(
              v24,
              "ipa %s:%d GSI channel %ld STOP\n",
              "ipa3_disable_wigig_pipe_i",
              1866,
              *((_QWORD *)v9 + 1));
            v23 = ipa3_ctx;
          }
          v25 = *(_QWORD *)(v23 + 34160);
          if ( v25 )
            ipc_log_string(
              v25,
              "ipa %s:%d GSI channel %ld STOP\n",
              "ipa3_disable_wigig_pipe_i",
              1866,
              *((_QWORD *)v9 + 1));
        }
        v26 = ipa3_reset_gsi_channel((_QWORD *)v6);
        if ( v26 )
        {
          v28 = v26;
          printk(&unk_3FDCAE, "ipa3_disable_wigig_pipe_i");
          v44 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v45 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v45 )
            {
              ipc_log_string(v45, "ipa %s:%d Failed to reset chan: %d.\n", "ipa3_disable_wigig_pipe_i", 1871, v28);
              v44 = ipa3_ctx;
            }
            v46 = *(_QWORD *)(v44 + 34160);
            if ( v46 )
              ipc_log_string(v46, "ipa %s:%d Failed to reset chan: %d.\n", "ipa3_disable_wigig_pipe_i", 1871, v28);
          }
          goto LABEL_41;
        }
        if ( v14 )
          ipa3_disable_force_clear(v6);
        result = ipa3_disable_data_path(v6);
        if ( (_DWORD)result )
        {
          __break(0x800u);
          goto LABEL_74;
        }
        v29 = v9[1];
        if ( v29 <= 0x85 && (v29 & 1) == 0 )
        {
          v57[0] = 256;
          ipa_cfg_ep_ctrl(v6, (unsigned __int8 *)v57);
        }
        v9[113] &= ~2u;
        ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v6);
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v6) <= 0x85 )
          ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(v6);
        ipa3_dec_client_disable_clks();
        v30 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v31 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v31 )
          {
            ipc_log_string(v31, "ipa %s:%d exit\n", "ipa3_disable_wigig_pipe_i", 1894);
            v30 = ipa3_ctx;
          }
          result = *(_QWORD *)(v30 + 34160);
          if ( !result )
            goto LABEL_74;
          ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_disable_wigig_pipe_i", 1894);
        }
        result = 0;
LABEL_74:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      printk(&unk_3D6A26, "ipa3_disable_wigig_pipe_i");
      v41 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v42 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v42 )
        {
          ipc_log_string(v42, "ipa %s:%d WIGIG channel bad state 0x%X\n", "ipa3_disable_wigig_pipe_i", 1820, v9[113]);
          v41 = ipa3_ctx;
        }
        v43 = *(_QWORD *)(v41 + 34160);
        if ( v43 )
          ipc_log_string(
            v43,
            "ipa %s:%d WIGIG channel bad state 0x%X\n",
            "ipa3_disable_wigig_pipe_i",
            1820,
            (unsigned int)v9[113]);
      }
    }
    else
    {
      printk(&unk_3DC47E, "ipa3_disable_wigig_pipe_i");
      v38 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v39 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v39 )
        {
          ipc_log_string(v39, "ipa %s:%d Invalid EP\n", "ipa3_disable_wigig_pipe_i", 1813);
          v38 = ipa3_ctx;
        }
        v40 = *(_QWORD *)(v38 + 34160);
        if ( v40 )
          ipc_log_string(v40, "ipa %s:%d Invalid EP\n", "ipa3_disable_wigig_pipe_i", 1813);
      }
    }
LABEL_73:
    result = 4294967282LL;
    goto LABEL_74;
  }
  __break(0x5512u);
  return ipa_wigig_send_wlan_msg();
}
