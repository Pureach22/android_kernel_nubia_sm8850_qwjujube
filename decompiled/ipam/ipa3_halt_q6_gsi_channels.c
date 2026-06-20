__int64 __fastcall ipa3_halt_q6_gsi_channels(__int64 result)
{
  unsigned int v1; // w19
  int v2; // w24
  int v3; // w8
  bool v4; // zf
  bool v5; // zf
  bool v6; // zf
  bool v7; // zf
  bool v8; // zf
  bool v9; // zf
  _BOOL4 v10; // w8
  __int64 v11; // x0
  __int64 v12; // x25
  unsigned int v13; // w27
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v1 = 0;
  v2 = result ^ 1;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  do
  {
    if ( v1 == 85 )
      goto LABEL_65;
    if ( v1 == 115 )
      goto LABEL_65;
    v3 = v1 & 0xFD;
    if ( v3 == 77 || v1 == 75 || v1 == 61 || v3 == 57 || v1 == 53 || (v1 & 0xFB) == 0x33 )
      goto LABEL_65;
    v4 = v1 == 52 || (v1 & 0xFB) == 50;
    v5 = v4 || v3 == 56;
    v6 = v5 || v1 == 122;
    v7 = v6 || v1 == 74;
    v8 = v7 || v1 == 114;
    v9 = v8 || v1 == 84;
    v10 = !v9;
    if ( ((v10 | v2) & 1) == 0 )
    {
LABEL_65:
      result = ipa_get_ep_mapping(v1);
      if ( (_DWORD)result != -1 )
      {
        v11 = ((__int64 (__fastcall *)(_QWORD))ipa_get_gsi_ep_info)(v1);
        if ( !v11 )
        {
          printk(&unk_3D1F32, "ipa3_halt_q6_gsi_channels");
          v22 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v23 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v23 )
            {
              ipc_log_string(v23, "ipa %s:%d failed to get GSI config\n", "ipa3_halt_q6_gsi_channels", 4829);
              v22 = ipa3_ctx;
            }
            v24 = *(_QWORD *)(v22 + 34160);
            if ( v24 )
              ipc_log_string(v24, "ipa %s:%d failed to get GSI config\n", "ipa3_halt_q6_gsi_channels", 4829);
          }
          printk(&unk_3AED39, v21);
          __break(0x800u);
        }
        v12 = v11;
        result = gsi_halt_channel_ee(*(unsigned int *)(v11 + 4), *(unsigned int *)(v11 + 16), &v25);
        if ( (_DWORD)result == -12 )
        {
          v13 = 0;
          do
          {
            v14 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v15 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v15 )
              {
                ipc_log_string(
                  v15,
                  "ipa %s:%d ch %d ee %d with code %d\n is busy try again",
                  "ipa3_halt_q6_gsi_channels",
                  4843,
                  *(_DWORD *)(v12 + 4),
                  *(_DWORD *)(v12 + 16),
                  v25);
                v14 = ipa3_ctx;
              }
              v16 = *(_QWORD *)(v14 + 34160);
              if ( v16 )
                ipc_log_string(
                  v16,
                  "ipa %s:%d ch %d ee %d with code %d\n is busy try again",
                  "ipa3_halt_q6_gsi_channels",
                  4843,
                  *(_DWORD *)(v12 + 4),
                  *(_DWORD *)(v12 + 16),
                  v25);
            }
            usleep_range_state(5000, 10000, 2);
            result = gsi_halt_channel_ee(*(unsigned int *)(v12 + 4), *(unsigned int *)(v12 + 16), &v25);
            if ( v13 > 8 )
              break;
            ++v13;
          }
          while ( (_DWORD)result == -12 );
        }
        if ( (_DWORD)result )
        {
          result = printk(&unk_3AC00C, "ipa3_halt_q6_gsi_channels");
          v19 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v20 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v20 )
            {
              ipc_log_string(
                v20,
                "ipa %s:%d failed to halt ch %d ee %d code %d\n",
                "ipa3_halt_q6_gsi_channels",
                4859,
                *(_DWORD *)(v12 + 4),
                *(_DWORD *)(v12 + 16),
                v25);
              v19 = ipa3_ctx;
            }
            result = *(_QWORD *)(v19 + 34160);
            if ( result )
              result = ipc_log_string(
                         result,
                         "ipa %s:%d failed to halt ch %d ee %d code %d\n",
                         "ipa3_halt_q6_gsi_channels",
                         4859,
                         *(unsigned int *)(v12 + 4),
                         *(unsigned int *)(v12 + 16),
                         v25);
          }
        }
        else
        {
          v17 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v18 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v18 )
            {
              ipc_log_string(
                v18,
                "ipa %s:%d halted gsi ch %d ee %d with code %d\n",
                "ipa3_halt_q6_gsi_channels",
                4854,
                *(_DWORD *)(v12 + 4),
                *(_DWORD *)(v12 + 16),
                v25);
              v17 = ipa3_ctx;
            }
            result = *(_QWORD *)(v17 + 34160);
            if ( result )
              result = ipc_log_string(
                         result,
                         "ipa %s:%d halted gsi ch %d ee %d with code %d\n",
                         "ipa3_halt_q6_gsi_channels",
                         4854,
                         *(unsigned int *)(v12 + 4),
                         *(unsigned int *)(v12 + 16),
                         v25);
          }
        }
      }
    }
    ++v1;
  }
  while ( v1 != 134 );
  _ReadStatusReg(SP_EL0);
  return result;
}
