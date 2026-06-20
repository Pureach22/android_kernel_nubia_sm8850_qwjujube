__int64 __fastcall ipa3_uc_ntn_event_log_info_handler(_DWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  unsigned int v5; // w8
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  int v9; // w21
  unsigned __int64 v10; // x22
  __int64 v11; // x2
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0

  if ( (*a1 & 0x20) != 0 )
  {
    v5 = a1[8];
    if ( HIWORD(v5) == 224 )
    {
      *(_DWORD *)(ipa3_ctx + 43184) = a1[2] + (unsigned __int16)v5;
      printk(&unk_3BBB1B, "ipa3_uc_ntn_event_log_info_handler");
      v6 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v7 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v7 )
        {
          ipc_log_string(
            v7,
            "ipa %s:%d NTN stats ofst=0x%x\n",
            "ipa3_uc_ntn_event_log_info_handler",
            34,
            *(_DWORD *)(ipa3_ctx + 43184));
          v6 = ipa3_ctx;
        }
        v8 = *(_QWORD *)(v6 + 34160);
        if ( v8 )
        {
          ipc_log_string(
            v8,
            "ipa %s:%d NTN stats ofst=0x%x\n",
            "ipa3_uc_ntn_event_log_info_handler",
            34,
            *(_DWORD *)(v6 + 43184));
          v6 = ipa3_ctx;
        }
      }
      v9 = *(_DWORD *)(*(_QWORD *)(v6 + 34176) + 36LL);
      v10 = *(unsigned int *)(v6 + 43184) + 224LL;
      if ( v10 >= (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(64, 0, 0)
                + v9
                + *(unsigned __int16 *)(ipa3_ctx + 29520) )
      {
        result = printk(&unk_3A43C4, "ipa3_uc_ntn_event_log_info_handler");
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v17 )
          {
            ipc_log_string(
              v17,
              "ipa %s:%d uc_ntn_stats 0x%x outside SRAM\n",
              "ipa3_uc_ntn_event_log_info_handler",
              41,
              *(_DWORD *)(ipa3_ctx + 43184));
            v16 = ipa3_ctx;
          }
          result = *(_QWORD *)(v16 + 34160);
          if ( result )
            return ipc_log_string(
                     result,
                     "ipa %s:%d uc_ntn_stats 0x%x outside SRAM\n",
                     "ipa3_uc_ntn_event_log_info_handler",
                     41,
                     *(_DWORD *)(v16 + 43184));
        }
      }
      else
      {
        if ( arm64_use_ng_mappings )
          v11 = 0x68000000000F13LL;
        else
          v11 = 0x68000000000713LL;
        result = ioremap_prot((unsigned int)(*(_DWORD *)(ipa3_ctx + 43184) + *(_DWORD *)(ipa3_ctx + 28640)), 224, v11);
        *(_QWORD *)(ipa3_ctx + 43192) = result;
        if ( !result )
        {
          result = printk(&unk_3ECC8D, "ipa3_uc_ntn_event_log_info_handler");
          v12 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v13 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v13 )
            {
              ipc_log_string(v13, "ipa %s:%d fail to ioremap uc ntn stats\n", "ipa3_uc_ntn_event_log_info_handler", 50);
              v12 = ipa3_ctx;
            }
            result = *(_QWORD *)(v12 + 34160);
            if ( result )
              return ipc_log_string(
                       result,
                       "ipa %s:%d fail to ioremap uc ntn stats\n",
                       "ipa3_uc_ntn_event_log_info_handler",
                       50);
          }
        }
      }
    }
    else
    {
      result = printk(&unk_3D3835, "ipa3_uc_ntn_event_log_info_handler");
      v14 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v15 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v15 )
        {
          ipc_log_string(
            v15,
            "ipa %s:%d NTN stats sz invalid exp=%zu is=%u\n",
            "ipa3_uc_ntn_event_log_info_handler",
            27,
            0xE0u,
            *((unsigned __int16 *)a1 + 17));
          v14 = ipa3_ctx;
        }
        result = *(_QWORD *)(v14 + 34160);
        if ( result )
          return ipc_log_string(
                   result,
                   "ipa %s:%d NTN stats sz invalid exp=%zu is=%u\n",
                   "ipa3_uc_ntn_event_log_info_handler",
                   27,
                   0xE0u,
                   *((unsigned __int16 *)a1 + 17));
      }
    }
  }
  else
  {
    result = printk(&unk_3AD686, "ipa3_uc_ntn_event_log_info_handler");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d NTN protocol missing 0x%x\n", "ipa3_uc_ntn_event_log_info_handler", 19, *a1);
        v3 = ipa3_ctx;
      }
      result = *(_QWORD *)(v3 + 34160);
      if ( result )
        return ipc_log_string(
                 result,
                 "ipa %s:%d NTN protocol missing 0x%x\n",
                 "ipa3_uc_ntn_event_log_info_handler",
                 19,
                 *a1);
    }
  }
  return result;
}
