__int64 __fastcall lim_send_chan_switch_action_frame(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x26
  unsigned __int8 *v6; // x25
  unsigned __int16 v7; // w22
  double v9; // d0
  unsigned int v10; // w0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  int v19; // w8
  unsigned int v20; // w22
  unsigned int v21; // w23
  unsigned int v22; // w24
  unsigned __int8 v23; // w28
  _WORD *v24; // x8
  unsigned int v25; // [xsp+Ch] [xbp-4h]

  v5 = *(_QWORD *)(a4 + 368);
  v6 = (unsigned __int8 *)(a4 + 7211);
  v7 = a2;
  v9 = lim_op_class_from_bandwidth(a1, a2, a3, *(unsigned __int8 *)(a4 + 7211));
  v25 = v10;
  result = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21560), v7, v9, v11, v12, v13, v14, v15, v16, v17);
  v19 = *(_DWORD *)(a4 + 88);
  v20 = result;
  if ( v19 == 2 )
    return lim_send_extended_chan_switch_action_frame(a1, a4 + 24, 0, v25, (unsigned int)result, v6[5], a4);
  if ( v19 == 1 )
  {
    if ( *(_BYTE *)(a1 + 14811) )
      v21 = 0;
    else
      v21 = v6[13];
    v22 = v6[5];
    v23 = 0;
    do
    {
      v24 = (_WORD *)(v5 + 952LL * v23);
      if ( v24 && (*v24 & 8) != 0 )
      {
        if ( v6[1464] )
          result = lim_send_channel_switch_mgmt_frame(a1, v24 + 169, v21, v20, v22, a4);
        else
          result = lim_send_extended_chan_switch_action_frame(a1, v24 + 169, v21, v25, v20, v22, a4);
      }
      ++v23;
    }
    while ( *(unsigned __int8 *)(a1 + 12272) >= (unsigned int)v23 );
  }
  return result;
}
