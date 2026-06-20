__int64 __fastcall ucfg_dp_fim_update_metadata(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  __int64 v12; // x20
  __int64 v13; // x20

  if ( a2 )
  {
    v2 = result;
    result = wlan_objmgr_vdev_get_comp_private_obj(a2, 0x2Eu);
    if ( result )
    {
      v11 = *(_QWORD *)(result + 32);
      if ( v11 )
      {
        result = wlan_dp_sawfish_update_metadata(*(__int64 **)(result + 32), v2);
        if ( (_DWORD)result )
        {
          result = dp_fim_update_metadata(v11, v2);
          if ( !(_DWORD)result )
            return ucfg_dp_lapb_handle_app_ind();
        }
      }
      else
      {
        v13 = jiffies;
        if ( ucfg_dp_fim_update_metadata___last_ticks_1 - jiffies + 125 < 0 )
        {
          result = qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: DP interface not found",
                     v3,
                     v4,
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     "ucfg_dp_fim_update_metadata");
          ucfg_dp_fim_update_metadata___last_ticks_1 = v13;
        }
      }
    }
    else
    {
      v12 = jiffies;
      if ( ucfg_dp_fim_update_metadata___last_ticks - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x45u,
                   2u,
                   "%s: DP link not found",
                   v3,
                   v4,
                   v5,
                   v6,
                   v7,
                   v8,
                   v9,
                   v10,
                   "ucfg_dp_fim_update_metadata");
        ucfg_dp_fim_update_metadata___last_ticks = v12;
      }
    }
  }
  return result;
}
