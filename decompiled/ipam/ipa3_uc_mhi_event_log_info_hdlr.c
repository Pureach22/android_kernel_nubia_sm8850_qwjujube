__int64 __fastcall ipa3_uc_mhi_event_log_info_hdlr(_DWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  unsigned int v5; // w8
  unsigned int v6; // w19
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  int v10; // w21
  unsigned __int64 v11; // x22
  __int64 v12; // x2
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0

  if ( (*a1 & 2) != 0 )
  {
    v5 = a1[4];
    v6 = HIWORD(v5);
    if ( HIWORD(v5) == 176 )
    {
      *(_DWORD *)(ipa3_uc_mhi_ctx + 24) = a1[2] + (unsigned __int16)v5;
      printk(&unk_3BE822, "ipa3_uc_mhi_event_log_info_hdlr");
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v8 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v8 )
        {
          ipc_log_string(
            v8,
            "ipa %s:%d MHI stats ofst=0x%x\n",
            "ipa3_uc_mhi_event_log_info_hdlr",
            549,
            *(_DWORD *)(ipa3_uc_mhi_ctx + 24));
          v7 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v7 + 34160);
        if ( v9 )
        {
          ipc_log_string(
            v9,
            "ipa %s:%d MHI stats ofst=0x%x\n",
            "ipa3_uc_mhi_event_log_info_hdlr",
            549,
            *(_DWORD *)(ipa3_uc_mhi_ctx + 24));
          v7 = ipa3_ctx;
        }
      }
      v10 = *(_DWORD *)(*(_QWORD *)(v7 + 34176) + 36LL);
      v11 = *(unsigned int *)(ipa3_uc_mhi_ctx + 24) + 176LL;
      if ( v11 >= (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(64, 0, 0)
                + v10
                + *(unsigned __int16 *)(ipa3_ctx + 29520) )
      {
        result = printk(&unk_3D37D9, "ipa3_uc_mhi_event_log_info_hdlr");
        v17 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v18 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v18 )
          {
            ipc_log_string(
              v18,
              "ipa %s:%d uc_mhi_stats 0x%x outside SRAM\n",
              "ipa3_uc_mhi_event_log_info_hdlr",
              556,
              *(_DWORD *)(ipa3_uc_mhi_ctx + 24));
            v17 = ipa3_ctx;
          }
          result = *(_QWORD *)(v17 + 34160);
          if ( result )
            return ipc_log_string(
                     result,
                     "ipa %s:%d uc_mhi_stats 0x%x outside SRAM\n",
                     "ipa3_uc_mhi_event_log_info_hdlr",
                     556,
                     *(_DWORD *)(ipa3_uc_mhi_ctx + 24));
        }
      }
      else
      {
        if ( arm64_use_ng_mappings )
          v12 = 0x68000000000F13LL;
        else
          v12 = 0x68000000000713LL;
        result = ioremap_prot(
                   (unsigned int)(*(_DWORD *)(ipa3_uc_mhi_ctx + 24) + *(_DWORD *)(ipa3_ctx + 28640)),
                   176,
                   v12);
        *(_QWORD *)(ipa3_uc_mhi_ctx + 32) = result;
        if ( !result )
        {
          result = printk(&unk_3FE9D2, "ipa3_uc_mhi_event_log_info_hdlr");
          v13 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v14 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v14 )
            {
              ipc_log_string(v14, "ipa %s:%d fail to ioremap uc mhi stats\n", "ipa3_uc_mhi_event_log_info_hdlr", 565);
              v13 = ipa3_ctx;
            }
            result = *(_QWORD *)(v13 + 34160);
            if ( result )
              return ipc_log_string(
                       result,
                       "ipa %s:%d fail to ioremap uc mhi stats\n",
                       "ipa3_uc_mhi_event_log_info_hdlr",
                       565);
          }
        }
      }
    }
    else
    {
      result = printk(&unk_3B0353, "ipa3_uc_mhi_event_log_info_hdlr");
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v16 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v16 )
        {
          ipc_log_string(
            v16,
            "ipa %s:%d mhi stats sz invalid exp=%zu is=%u\n",
            "ipa3_uc_mhi_event_log_info_hdlr",
            542,
            0xB0u,
            v6);
          v15 = ipa3_ctx;
        }
        result = *(_QWORD *)(v15 + 34160);
        if ( result )
          return ipc_log_string(
                   result,
                   "ipa %s:%d mhi stats sz invalid exp=%zu is=%u\n",
                   "ipa3_uc_mhi_event_log_info_hdlr",
                   542,
                   0xB0u,
                   v6);
      }
    }
  }
  else
  {
    result = printk(&unk_3A7691, "ipa3_uc_mhi_event_log_info_hdlr");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d MHI feature missing 0x%x\n", "ipa3_uc_mhi_event_log_info_hdlr", 533, *a1);
        v3 = ipa3_ctx;
      }
      result = *(_QWORD *)(v3 + 34160);
      if ( result )
        return ipc_log_string(
                 result,
                 "ipa %s:%d MHI feature missing 0x%x\n",
                 "ipa3_uc_mhi_event_log_info_hdlr",
                 533,
                 *a1);
    }
  }
  return result;
}
