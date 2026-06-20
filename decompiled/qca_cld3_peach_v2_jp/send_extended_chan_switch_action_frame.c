__int64 __fastcall send_extended_chan_switch_action_frame(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int8 *v4; // x25
  unsigned int v6; // w21
  unsigned int v7; // w22
  double v9; // d0
  unsigned int v10; // w0
  unsigned int v11; // w24
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  int v20; // w8
  unsigned int v21; // w24
  unsigned __int8 v22; // w27
  _WORD *v23; // x23
  unsigned int v24; // w0
  unsigned int v25; // w0
  unsigned int v26; // [xsp+Ch] [xbp-4h]

  v4 = (unsigned __int8 *)(a4 + 4096);
  v6 = a3;
  v7 = a2;
  v9 = lim_op_class_from_bandwidth(a1, a2, a3, *(unsigned __int8 *)(a4 + 7211));
  v11 = v10;
  result = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21560), (unsigned __int16)v7, v9, v12, v13, v14, v15, v16, v17, v18);
  v20 = *(_DWORD *)(a4 + 88);
  v26 = result;
  if ( v20 == 2 )
    return lim_send_extended_chan_switch_action_frame(a1, a4 + 24, 0, v11, (unsigned int)result, v4[3120], a4);
  if ( v20 == 1 )
  {
    if ( *(_BYTE *)(a1 + 14811) )
      v21 = 0;
    else
      v21 = v4[3128];
    v22 = 0;
    do
    {
      v23 = (_WORD *)(*(_QWORD *)(a4 + 368) + 952LL * v22);
      if ( v23 )
      {
        if ( (*v23 & 8) != 0 )
        {
          v24 = lim_calculate_peer_ch_width(a4, v23 + 169, v6);
          lim_op_class_from_bandwidth(a1, v7, v24, v4[3115]);
          result = lim_send_extended_chan_switch_action_frame(a1, v23 + 169, v21, v25, v26, v4[3120], a4);
        }
      }
      ++v22;
    }
    while ( *(unsigned __int8 *)(a1 + 12272) >= (unsigned int)v22 );
  }
  return result;
}
