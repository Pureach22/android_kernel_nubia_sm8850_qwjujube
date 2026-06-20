__int64 __fastcall ipa3_stop_ul_chan_with_data_drain(
        _QWORD *a1,
        int a2,
        unsigned int a3,
        char a4,
        unsigned int a5,
        char a6)
{
  __int64 v6; // x13
  unsigned int v12; // w22
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x21
  __int64 v16; // x21
  int v17; // t1
  unsigned int v18; // w0
  int v19; // w27
  __int64 result; // x0
  unsigned int v21; // w0
  unsigned int v22; // w8
  int v23; // w0
  int v24; // w24
  unsigned int v25; // w0
  unsigned int v26; // w23
  unsigned int v27; // w0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x9
  unsigned int v32; // w19
  unsigned int v33; // w19
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  unsigned int v37; // w22
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  unsigned int v44; // w24
  __int64 v45; // x0
  __int64 v46; // x8
  __int64 v47; // x0
  unsigned int v48; // w20
  __int64 v49; // x0
  __int64 v50; // x0
  int v51; // w24
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x0
  char v55[4]; // [xsp+8h] [xbp-18h] BYREF
  __int16 v56; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v57[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v58[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v59; // [xsp+18h] [xbp-8h]

  v12 = (unsigned int)a1;
  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = ipa3_ctx;
  v58[0] = 0;
  v57[0] = 0;
  v56 = 0;
  if ( ipa3_ctx )
  {
    v14 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v14 )
    {
      ipc_log_string(v14, "ipa %s:%d entry\n", "ipa3_stop_ul_chan_with_data_drain", 1224);
      v13 = ipa3_ctx;
    }
    a1 = *(_QWORD **)(v13 + 34160);
    if ( a1 )
    {
      a1 = (_QWORD *)ipc_log_string(a1, "ipa %s:%d entry\n", "ipa3_stop_ul_chan_with_data_drain", 1224);
      v13 = ipa3_ctx;
    }
  }
  if ( *(_DWORD *)(v13 + 34308) > a5 )
  {
    if ( a5 >= 0x24 )
    {
      __break(0x5512u);
      *a1 = v6;
      JUMPOUT(0x92478);
    }
    v15 = v13 + 480LL * a5;
    v17 = *(_DWORD *)(v15 + 168);
    v16 = v15 + 168;
    if ( v17 )
    {
      v18 = ((__int64 (__fastcall *)(_QWORD, _BYTE *))ipa3_xdci_stop_gsi_ch_brute_force)(a5, v57);
      if ( v18 )
      {
        v37 = v18;
        printk(&unk_3F1CA1, "ipa3_stop_ul_chan_with_data_drain");
        v38 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v39 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v39 )
          {
            ipc_log_string(
              v39,
              "ipa %s:%d fail to stop UL channel - hdl=%d clnt=%d\n",
              "ipa3_stop_ul_chan_with_data_drain",
              1239,
              a5,
              *(_DWORD *)(v16 + 4));
            v38 = ipa3_ctx;
          }
          v40 = *(_QWORD *)(v38 + 34160);
          if ( v40 )
          {
            ipc_log_string(
              v40,
              "ipa %s:%d fail to stop UL channel - hdl=%d clnt=%d\n",
              "ipa3_stop_ul_chan_with_data_drain",
              1239,
              a5,
              *(unsigned int *)(v16 + 4));
LABEL_60:
            result = v37;
            goto LABEL_33;
          }
        }
      }
      else
      {
        if ( v57[0] != 1 )
          goto LABEL_32;
        v19 = 50;
        do
        {
          result = ipa3_is_xdci_channel_empty(v16, v58);
          if ( (_DWORD)result )
            goto LABEL_33;
          if ( (v58[0] & 1) != 0 )
            goto LABEL_16;
          _const_udelay(85900);
          --v19;
        }
        while ( v19 );
        if ( (v58[0] & 1) == 0 )
          goto LABEL_18;
LABEL_16:
        v21 = ((__int64 (__fastcall *)(_QWORD, _BYTE *))ipa3_xdci_stop_gsi_ch_brute_force)(a5, v57);
        if ( !v21 )
        {
          if ( v57[0] == 1 )
          {
LABEL_18:
            if ( (a4 & 1) != 0 )
            {
              v22 = *(_DWORD *)(v16 + 4);
              if ( v22 <= 0x85 && (v22 & 1) == 0 )
              {
                v23 = ipa3_enable_force_clear((_QWORD *)v12, 0, a2, a3);
                if ( v23 )
                {
                  v55[0] = 0;
                  v51 = v23;
                  printk(&unk_3C6907, "ipa3_stop_ul_chan_with_data_drain");
                  v52 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v53 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v53 )
                    {
                      ipc_log_string(
                        v53,
                        "ipa %s:%d failed to force clear %d, remove delay from SCND reg\n",
                        "ipa3_stop_ul_chan_with_data_drain",
                        1296,
                        v51);
                      v52 = ipa3_ctx;
                    }
                    v54 = *(_QWORD *)(v52 + 34160);
                    if ( v54 )
                    {
                      ipc_log_string(
                        v54,
                        "ipa %s:%d failed to force clear %d, remove delay from SCND reg\n",
                        "ipa3_stop_ul_chan_with_data_drain",
                        1296,
                        v51);
                      v52 = ipa3_ctx;
                    }
                  }
                  if ( *(_BYTE *)(v52 + 50153) == 1 )
                  {
                    ipa3_remove_secondary_flow_ctrl(*(unsigned int *)(v16 + 8));
                  }
                  else
                  {
                    v55[0] = 0;
                    ((void (__fastcall *)(__int64, _QWORD, char *))ipahal_write_reg_n_fields)(50, a5, v55);
                  }
                }
              }
            }
            v24 = 50;
            do
            {
              result = ipa3_is_xdci_channel_empty(v16, v58);
              if ( (_DWORD)result )
                goto LABEL_30;
              if ( (v58[0] & 1) != 0 )
                break;
              _const_udelay(85900);
              --v24;
            }
            while ( v24 );
            v25 = ((__int64 (__fastcall *)(_QWORD, _BYTE *))ipa3_xdci_stop_gsi_ch_brute_force)(a5, v57);
            if ( !v25 )
            {
              if ( v57[0] )
                result = 4294967282LL;
              else
                result = 0;
LABEL_30:
              if ( (a4 & 1) == 0 )
                goto LABEL_33;
LABEL_31:
              v26 = result;
              ipa3_disable_force_clear(v12);
              result = v26;
              goto LABEL_33;
            }
            v44 = v25;
            v45 = printk(&unk_3F1CA1, "ipa3_stop_ul_chan_with_data_drain");
            v46 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v47 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v47 )
              {
                ipc_log_string(
                  v47,
                  "ipa %s:%d fail to stop UL channel - hdl=%d clnt=%d\n",
                  "ipa3_stop_ul_chan_with_data_drain",
                  1323,
                  a5,
                  *(_DWORD *)(v16 + 4));
                v46 = ipa3_ctx;
              }
              v45 = *(_QWORD *)(v46 + 34160);
              if ( v45 )
                v45 = ipc_log_string(
                        v45,
                        "ipa %s:%d fail to stop UL channel - hdl=%d clnt=%d\n",
                        "ipa3_stop_ul_chan_with_data_drain",
                        1323,
                        a5,
                        *(_DWORD *)(v16 + 4));
            }
            ((void (__fastcall *)(__int64))ipa_assert)(v45);
            result = v44;
            if ( (a4 & 1) != 0 )
              goto LABEL_31;
LABEL_33:
            if ( (a6 & 1) != 0 && *(_BYTE *)(v16 + 468) == 1 && (v57[0] & 1) == 0 )
            {
              v56 = 0;
              v27 = ipa_cfg_ep_ctrl(a5, &v56);
              if ( v27 )
              {
                v48 = v27;
                printk(&unk_3E353B, "ipa3_stop_ul_chan_with_data_drain");
                v31 = ipa3_ctx;
                if ( !ipa3_ctx )
                {
                  result = v48;
                  goto LABEL_48;
                }
                v49 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v49 )
                {
                  ipc_log_string(
                    v49,
                    "ipa %s:%d client (ep: %d) failed to remove delay result=%d\n",
                    "ipa3_stop_ul_chan_with_data_drain",
                    1341,
                    a5,
                    v48);
                  v31 = ipa3_ctx;
                }
                v50 = *(_QWORD *)(v31 + 34160);
                if ( v50 )
                {
                  ipc_log_string(
                    v50,
                    "ipa %s:%d client (ep: %d) failed to remove delay result=%d\n",
                    "ipa3_stop_ul_chan_with_data_drain",
                    1341,
                    a5,
                    v48);
                  result = v48;
                  v31 = ipa3_ctx;
                  if ( !ipa3_ctx )
                    goto LABEL_48;
                }
                else
                {
                  result = v48;
                  if ( !v31 )
                    goto LABEL_48;
                }
LABEL_44:
                if ( *(_QWORD *)(v31 + 34152) )
                {
                  v32 = result;
                  ipc_log_string(
                    *(_QWORD *)(v31 + 34152),
                    "ipa %s:%d exit\n",
                    "ipa3_stop_ul_chan_with_data_drain",
                    1348);
                  v31 = ipa3_ctx;
                  result = v32;
                }
                if ( *(_QWORD *)(v31 + 34160) )
                {
                  v33 = result;
                  ipc_log_string(
                    *(_QWORD *)(v31 + 34160),
                    "ipa %s:%d exit\n",
                    "ipa3_stop_ul_chan_with_data_drain",
                    1348);
                  result = v33;
                }
                goto LABEL_48;
              }
              v28 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v29 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v29 )
                {
                  ipc_log_string(
                    v29,
                    "ipa %s:%d client (ep: %d) delay removed\n",
                    "ipa3_stop_ul_chan_with_data_drain",
                    1344,
                    a5);
                  v28 = ipa3_ctx;
                }
                v30 = *(_QWORD *)(v28 + 34160);
                if ( v30 )
                  ipc_log_string(
                    v30,
                    "ipa %s:%d client (ep: %d) delay removed\n",
                    "ipa3_stop_ul_chan_with_data_drain",
                    1344,
                    a5);
              }
              result = 0;
              *(_BYTE *)(v16 + 468) = 0;
            }
            v31 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_48;
            goto LABEL_44;
          }
LABEL_32:
          result = 0;
          goto LABEL_33;
        }
        v37 = v21;
        printk(&unk_3F1CA1, "ipa3_stop_ul_chan_with_data_drain");
        v41 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v42 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v42 )
          {
            ipc_log_string(
              v42,
              "ipa %s:%d fail to stop UL channel - hdl=%d clnt=%d\n",
              "ipa3_stop_ul_chan_with_data_drain",
              1277,
              a5,
              *(_DWORD *)(v16 + 4));
            v41 = ipa3_ctx;
          }
          v43 = *(_QWORD *)(v41 + 34160);
          if ( v43 )
          {
            ipc_log_string(
              v43,
              "ipa %s:%d fail to stop UL channel - hdl=%d clnt=%d\n",
              "ipa3_stop_ul_chan_with_data_drain",
              1277,
              a5,
              *(unsigned int *)(v16 + 4));
            goto LABEL_60;
          }
        }
      }
      result = v37;
      goto LABEL_33;
    }
  }
  printk(&unk_3F1C01, "ipa3_stop_ul_chan_with_data_drain");
  v34 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_54;
  v35 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v35 )
  {
    ipc_log_string(v35, "ipa %s:%d Bad parameter.\n", "ipa3_stop_ul_chan_with_data_drain", 1228);
    v34 = ipa3_ctx;
  }
  v36 = *(_QWORD *)(v34 + 34160);
  if ( v36 )
  {
    ipc_log_string(v36, "ipa %s:%d Bad parameter.\n", "ipa3_stop_ul_chan_with_data_drain", 1228);
    result = 4294967274LL;
  }
  else
  {
LABEL_54:
    result = 4294967274LL;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
