__int64 __fastcall ipa_mhi_debugfs_dump_host_ch_ctx_arr(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v7; // w0
  unsigned int v8; // w22
  int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w23
  unsigned int v13; // w0
  unsigned int v14; // w23
  int v15; // w9
  __int64 v16; // x0
  unsigned int v17; // w23
  int v18; // w8
  __int64 v19; // x0
  int v20; // t1
  int v21; // w0
  _BYTE *v22; // x8
  int v23; // w0
  int v24; // w0
  int v25; // w0

  if ( *(_DWORD *)ipa_mhi_client_ctx >= 2u )
  {
    if ( *(_DWORD *)ipa_mhi_client_ctx == 4 )
    {
      v10 = scnprintf(&dbg_buff_5, 512, "IPA MHI is suspended, cannot dump channel ctx array");
      if ( v10 <= 0x200 )
      {
        v8 = v10;
        v9 = scnprintf((char *)&dbg_buff_5 + v10, 512 - v10, " from host -PCIe can be in D3 state\n");
        goto LABEL_7;
      }
    }
    else
    {
      v13 = scnprintf(&dbg_buff_5, 512, "channel contex array - dump from host\n");
      if ( v13 <= 0x200 )
      {
        v14 = v13;
        v15 = scnprintf((char *)&dbg_buff_5 + v13, 512 - v13, "***** UL channels *******\n");
        v16 = ipa_mhi_client_ctx;
        v17 = v15 + v14;
        if ( *(_BYTE *)(ipa_mhi_client_ctx + 40) == 1 )
        {
          if ( v17 > 0x200 )
            goto LABEL_29;
          v18 = ipa_mhi_print_host_channel_ctx_info(ipa_mhi_client_ctx + 40, (char *)&dbg_buff_5 + v17, 512 - v17);
          v16 = ipa_mhi_client_ctx;
          v17 += v18;
        }
        v20 = *(unsigned __int8 *)(v16 + 240);
        v19 = v16 + 240;
        if ( v20 == 1 )
        {
          if ( v17 > 0x200 )
            goto LABEL_29;
          v17 += ipa_mhi_print_host_channel_ctx_info(v19, (char *)&dbg_buff_5 + v17, 512 - v17);
        }
        if ( v17 <= 0x200 )
        {
          v21 = scnprintf((char *)&dbg_buff_5 + v17, 512 - v17, "\n***** DL channels *******\n");
          v22 = (_BYTE *)ipa_mhi_client_ctx;
          v11 = v21 + v17;
          if ( *(_BYTE *)(ipa_mhi_client_ctx + 440) == 1 )
          {
            if ( v11 > 0x200 )
              goto LABEL_29;
            v23 = ipa_mhi_print_host_channel_ctx_info(ipa_mhi_client_ctx + 440, (char *)&dbg_buff_5 + v11, 512 - v11);
            v22 = (_BYTE *)ipa_mhi_client_ctx;
            v11 += v23;
          }
          if ( v22[640] == 1 )
          {
            if ( v11 > 0x200 )
              goto LABEL_29;
            v24 = ipa_mhi_print_host_channel_ctx_info(v22 + 640, (char *)&dbg_buff_5 + v11, 512 - v11);
            v22 = (_BYTE *)ipa_mhi_client_ctx;
            v11 += v24;
          }
          if ( v22[840] == 1 )
          {
            if ( v11 > 0x200 )
              goto LABEL_29;
            v25 = ipa_mhi_print_host_channel_ctx_info(v22 + 840, (char *)&dbg_buff_5 + v11, 512 - v11);
            v22 = (_BYTE *)ipa_mhi_client_ctx;
            v11 += v25;
          }
          if ( v22[1040] != 1 )
            return simple_read_from_buffer(a2, a3, a4, &dbg_buff_5, (int)v11);
          if ( v11 <= 0x200 )
          {
            v11 += ipa_mhi_print_host_channel_ctx_info(v22 + 1040, (char *)&dbg_buff_5 + v11, 512 - v11);
            return simple_read_from_buffer(a2, a3, a4, &dbg_buff_5, (int)v11);
          }
        }
      }
    }
  }
  else
  {
    v7 = scnprintf(&dbg_buff_5, 512, "Cannot dump host channel context ");
    if ( v7 <= 0x200 )
    {
      v8 = v7;
      v9 = scnprintf((char *)&dbg_buff_5 + v7, 512 - v7, "before IPA MHI was STARTED\n");
LABEL_7:
      v11 = v9 + v8;
      return simple_read_from_buffer(a2, a3, a4, &dbg_buff_5, (int)v11);
    }
  }
LABEL_29:
  __break(0x5512u);
  return ipa_mhi_start();
}
