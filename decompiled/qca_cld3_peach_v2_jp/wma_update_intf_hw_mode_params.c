__int64 __fastcall wma_update_intf_hw_mode_params(
        unsigned int a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w9
  _QWORD v33[3]; // [xsp+8h] [xbp-18h] BYREF

  v33[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33[0] = 0;
  v33[1] = 0;
  result = (__int64)_cds_get_context(54, (__int64)"wma_update_intf_hw_mode_params", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( result )
  {
    v23 = result;
    if ( *(_QWORD *)(result + 520) )
    {
      if ( (unsigned int)policy_mgr_get_hw_mode_from_idx(*(_QWORD *)(result + 24), a3, (__int64)v33) )
      {
        result = qdf_trace_msg(
                   0x36u,
                   2u,
                   "%s: cfgd_hw_mode_index %d not found",
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   "wma_update_intf_hw_mode_params",
                   a3);
      }
      else
      {
        result = (__int64)wlan_mlme_set_vdev_mac_id(*(_QWORD *)(v23 + 32), a1, a2);
        if ( a2 )
          v32 = BYTE2(v33[0]);
        else
          v32 = LOBYTE(v33[0]);
        *(_DWORD *)(*(_QWORD *)(v23 + 520) + 488LL * a1 + 264) = v32;
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x36u,
                 2u,
                 "%s: Interface is NULL",
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 "wma_update_intf_hw_mode_params");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
