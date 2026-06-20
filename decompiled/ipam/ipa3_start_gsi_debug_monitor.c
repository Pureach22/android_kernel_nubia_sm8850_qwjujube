__int64 __fastcall ipa3_start_gsi_debug_monitor(unsigned int a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x21
  __int64 v6; // x21
  int v7; // t1
  __int64 result; // x0
  __int64 v9; // x9
  unsigned int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x11
  __int64 v16; // x12
  __int64 v17; // x0
  __int64 v18; // x9
  __int64 v19; // x9
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x11
  __int64 v23; // x0
  unsigned int v24; // w19
  __int64 v25; // x9
  __int64 v26; // x9

  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d entry\n", "ipa3_start_gsi_debug_monitor", 304);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d entry\n", "ipa3_start_gsi_debug_monitor", 304);
      v2 = ipa3_ctx;
    }
  }
  if ( *(_DWORD *)(v2 + 34308) > a1 )
  {
    if ( a1 >= 0x24 )
    {
      __break(0x5512u);
      return ipa3_get_gsi_chan_info();
    }
    v5 = v2 + 480LL * a1;
    v7 = *(_DWORD *)(v5 + 168);
    v6 = v5 + 168;
    if ( v7 )
    {
      result = ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
      v9 = ipa3_ctx;
      v10 = *(_DWORD *)(ipa3_ctx + 32240);
      if ( v10 < 0x11 || v10 <= 0x17 && ((1 << v10) & 0x940000) != 0 )
        return result;
      v13 = ipa3_ctx + 45316;
      if ( (int)result > 96 )
      {
        if ( (_DWORD)result != 97 )
        {
          if ( (_DWORD)result == 98 )
          {
            v26 = *(_QWORD *)(v6 + 8);
            *(_BYTE *)(ipa3_ctx + 45324) = 1;
            *(_BYTE *)(v13 + 9) = v26;
          }
          else
          {
            if ( (_DWORD)result != 99 )
            {
LABEL_30:
              if ( ipa3_ctx )
              {
                if ( *(_QWORD *)(ipa3_ctx + 34152) )
                {
                  v24 = result;
                  ipc_log_string(
                    *(_QWORD *)(ipa3_ctx + 34152),
                    "ipa %s:%d client_type %d not supported\n",
                    "ipa3_start_gsi_debug_monitor",
                    358,
                    result);
                  v9 = ipa3_ctx;
                  result = v24;
                }
                if ( *(_QWORD *)(v9 + 34160) )
                  return ipc_log_string(
                           *(_QWORD *)(v9 + 34160),
                           "ipa %s:%d client_type %d not supported\n",
                           "ipa3_start_gsi_debug_monitor",
                           358,
                           result);
              }
              return result;
            }
            v18 = *(_QWORD *)(v6 + 8);
            *(_BYTE *)(ipa3_ctx + 45326) = 0;
            *(_BYTE *)(v13 + 11) = v18;
          }
          return ipa3_uc_debug_stats_alloc(
                   *(_QWORD *)v13,
                   *(unsigned int *)(v13 + 8) | ((unsigned __int64)*(unsigned __int16 *)(v13 + 12) << 32));
        }
        v20 = *(_QWORD *)(v6 + 8);
        *(_BYTE *)(ipa3_ctx + 45322) = 0;
        v21 = *(unsigned __int16 *)(v13 + 12);
        v22 = *(unsigned int *)(v13 + 8);
        *(_BYTE *)(v13 + 7) = v20;
        v23 = *(_QWORD *)v13;
      }
      else
      {
        if ( (_DWORD)result == 18 )
        {
          v19 = *(_QWORD *)(v6 + 8);
          v15 = *(unsigned __int16 *)(ipa3_ctx + 45342);
          *(_BYTE *)(ipa3_ctx + 45334) = 1;
          v16 = *(unsigned int *)(v13 + 22);
          *(_BYTE *)(v13 + 19) = v19;
          v17 = *(_QWORD *)(v13 + 14);
          return ipa3_uc_debug_stats_alloc(v17, v16 | (v15 << 32));
        }
        if ( (_DWORD)result != 19 )
        {
          if ( (_DWORD)result == 96 )
          {
            v14 = *(_QWORD *)(v6 + 8);
            v15 = *(unsigned __int16 *)(ipa3_ctx + 45328);
            *(_BYTE *)(ipa3_ctx + 45320) = 1;
            v16 = *(unsigned int *)(v13 + 8);
            *(_BYTE *)(v13 + 5) = v14;
            v17 = *(_QWORD *)v13;
            return ipa3_uc_debug_stats_alloc(v17, v16 | (v15 << 32));
          }
          goto LABEL_30;
        }
        v25 = *(_QWORD *)(v6 + 8);
        *(_BYTE *)(ipa3_ctx + 45336) = 0;
        v21 = *(unsigned __int16 *)(v13 + 26);
        v22 = *(unsigned int *)(v13 + 22);
        *(_BYTE *)(v13 + 21) = v25;
        v23 = *(_QWORD *)(v13 + 14);
      }
      return ipa3_uc_debug_stats_alloc(v23, v22 | (v21 << 32));
    }
  }
  result = printk(&unk_3A948A, "ipa3_start_gsi_debug_monitor");
  v11 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v12 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d Bad parameters.\n", "ipa3_start_gsi_debug_monitor", 307);
      v11 = ipa3_ctx;
    }
    result = *(_QWORD *)(v11 + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d Bad parameters.\n", "ipa3_start_gsi_debug_monitor", 307);
  }
  return result;
}
