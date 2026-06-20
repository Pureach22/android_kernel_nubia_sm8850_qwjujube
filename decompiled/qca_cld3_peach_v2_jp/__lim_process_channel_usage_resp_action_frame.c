__int64 __fastcall _lim_process_channel_usage_resp_action_frame(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  _BYTE *v5; // x23
  __int64 v6; // x21
  unsigned __int8 *v7; // x24
  __int64 v8; // x19
  unsigned int v9; // w20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  int v23; // w24
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  __int64 v34; // [xsp+0h] [xbp-50h]
  __int64 v35; // [xsp+8h] [xbp-48h]

  if ( *(_DWORD *)(a3 + 7036) == 2 )
  {
    v34 = v3;
    v35 = v4;
    v5 = (_BYTE *)(a3 + 0x2000);
    if ( (*(_BYTE *)(a3 + 10080) & 2) != 0 )
    {
      v7 = *(unsigned __int8 **)(a2 + 16);
      v6 = *(_QWORD *)(a2 + 24);
      v8 = result;
      v9 = *(_DWORD *)(a2 + 40);
      result = qdf_mem_cmp(v7 + 10, (const void *)(a3 + 24), 6u);
      if ( (_DWORD)result )
      {
        if ( v7 == (unsigned __int8 *)-10LL )
        {
          v21 = 0;
          v19 = 0;
          v20 = 0;
          v22 = 0;
        }
        else
        {
          v19 = v7[10];
          v20 = v7[11];
          v21 = v7[12];
          v22 = v7[15];
        }
        return qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: Ignore resp frame not from GO%02x:%02x:%02x:**:**:%02x",
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 "__lim_process_channel_usage_resp_action_frame",
                 v19,
                 v20,
                 v21,
                 v22,
                 v3,
                 v35);
      }
      else if ( v9 >= 0x1D )
      {
        v23 = *(unsigned __int8 *)(v6 + 28);
        if ( v9 >= v23 + 32 )
        {
          qdf_mem_set((void *)(a3 + 10532), 0x104u, 0);
          v24 = dot11f_unpack_channel_usage_resp(v8, v6, (unsigned int)(v23 + 29), a3 + 10532, 0);
          if ( (v24 & 0x10000000) != 0 )
          {
            return qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: Error parsing channel usage resp action frame (0x%08x, %d bytes):",
                     v25,
                     v26,
                     v27,
                     v28,
                     v29,
                     v30,
                     v31,
                     v32,
                     "__lim_process_channel_usage_resp_action_frame",
                     v24,
                     v9,
                     v3,
                     v35);
          }
          else
          {
            if ( v24 )
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: There were warnings while unpacking channel usage resp action frame  (0x%08x, %d bytes):",
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                "__lim_process_channel_usage_resp_action_frame",
                v24,
                v9,
                v3,
                v35);
            if ( v5[2344] == v5[1908] && v5[2342] == v5[1906] )
            {
              v33 = (unsigned __int8)v5[2345];
              v5[1888] &= ~2u;
              if ( !v33 || (v33 & 1) != 0 )
              {
                tx_timer_deactivate(v8 + 3720);
                return lim_timer_handler(v8, 5120);
              }
              else
              {
                return lim_deactivate_and_change_timer(v8, 23);
              }
            }
            else
            {
              return qdf_trace_msg(
                       0x35u,
                       8u,
                       "%s: Ignore mismtach usage mode or dialogtoken",
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31,
                       v32,
                       "__lim_process_channel_usage_resp_action_frame",
                       v34,
                       v35);
            }
          }
        }
      }
    }
  }
  return result;
}
