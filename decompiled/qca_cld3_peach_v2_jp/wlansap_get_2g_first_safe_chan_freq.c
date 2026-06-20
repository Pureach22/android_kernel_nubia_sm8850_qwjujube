__int64 __fastcall wlansap_get_2g_first_safe_chan_freq(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  void *v4; // x0
  __int64 v5; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w22
  __int64 v16; // x8
  __int64 v17; // x23
  _DWORD *v18; // x24
  unsigned __int64 v19; // x25
  unsigned int channel_state_for_pwrmode; // w0
  bool v21; // zf
  __int64 v22; // x9
  unsigned __int64 v23; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 152LL);
  v3 = *(_QWORD *)(v2 + 80);
  v4 = (void *)_qdf_mem_malloc(0xE58u, "wlansap_get_2g_first_safe_chan_freq", 4187);
  if ( v4 )
  {
    v5 = (__int64)v4;
    if ( (unsigned int)wlan_reg_get_current_chan_list(v2, v4) )
    {
LABEL_3:
      v14 = 2437;
    }
    else
    {
      v16 = *(_QWORD *)(a1 + 1536);
      v17 = 0;
      v18 = *(_DWORD **)(v16 + 32);
      v19 = *(unsigned __int8 *)(v16 + 40);
      while ( 1 )
      {
        v14 = *(_DWORD *)(v5 + 36 * v17);
        channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                      v2,
                                      v14,
                                      0,
                                      v6,
                                      v7,
                                      v8,
                                      v9,
                                      v10,
                                      v11,
                                      v12,
                                      v13);
        v21 = channel_state_for_pwrmode > 4 || ((1 << channel_state_for_pwrmode) & 0x13) == 0;
        if ( v21
          && wlan_reg_is_24ghz_ch_freq(v14)
          && (((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_is_safe_channel)(v3, v14) & 1) != 0
          && (_DWORD)v19 )
        {
          if ( *v18 == v14 )
            break;
          v22 = 1;
          do
          {
            v23 = v22;
            if ( v19 == v22 )
              break;
            v21 = v18[v22++] == v14;
          }
          while ( !v21 );
          if ( v23 < v19 )
            break;
        }
        if ( ++v17 == 102 )
          goto LABEL_3;
      }
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: found a 2g channel: %d",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlansap_get_2g_first_safe_chan_freq",
        v14);
    }
    _qdf_mem_free(v5);
  }
  else
  {
    return 2437;
  }
  return v14;
}
