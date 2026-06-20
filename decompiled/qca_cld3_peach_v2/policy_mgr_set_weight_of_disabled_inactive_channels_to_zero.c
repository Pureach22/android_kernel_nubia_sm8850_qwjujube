__int64 __fastcall policy_mgr_set_weight_of_disabled_inactive_channels_to_zero(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        _BYTE *a4)
{
  __int64 comp_private_obj; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x21
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    v26 = "%s: Invalid Context";
    return qdf_trace_msg(
             0x4Fu,
             2u,
             v26,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             "policy_mgr_set_weight_of_disabled_inactive_channels_to_zero");
  }
  if ( !a3 )
  {
    v26 = "%s: invalid number of channel length";
    return qdf_trace_msg(
             0x4Fu,
             2u,
             v26,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             "policy_mgr_set_weight_of_disabled_inactive_channels_to_zero");
  }
  v16 = comp_private_obj;
  LODWORD(a3) = *(_DWORD *)a3;
  result = qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: Set weight of disabled, inactive channels to 0",
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             "policy_mgr_set_weight_of_disabled_inactive_channels_to_zero");
  if ( (_DWORD)a3 )
  {
    if ( (unsigned int)a3 >= 0x66 )
      a3 = 102;
    else
      a3 = (unsigned int)a3;
    do
    {
      if ( wlan_reg_is_6ghz_chan_freq(*a2)
        && (result = wlan_reg_is_6ghz_band_set(*(_QWORD *)(v16 + 8), v18, v19, v20, v21, v22, v23, v24, v25),
            (result & 1) == 0)
        || (result = wlan_reg_get_channel_state_for_pwrmode(
                       *(_QWORD *)(v16 + 8),
                       *a2,
                       0,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23,
                       v24,
                       v25),
            (result & 0xFFFFFFFB) == 0) )
      {
        *a4 = 0;
      }
      --a3;
      ++a4;
      ++a2;
    }
    while ( a3 );
  }
  return result;
}
