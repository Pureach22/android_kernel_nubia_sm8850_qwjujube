__int64 __fastcall ucfg_dp_rx_handle_concurrency(__int64 a1, char a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w8
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // [xsp+0h] [xbp-10h] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( result )
  {
    v13 = *(_DWORD *)(result + 92);
    v14 = result;
    if ( (a2 & 1) != 0 )
    {
      if ( v13 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Enable TCP delack as LRO disabled in concurrency",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "ucfg_dp_rx_handle_concurrency",
          0x100000000LL,
          v24);
        LODWORD(v23) = *(_DWORD *)(v14 + 1048);
        result = wlan_dp_update_tcp_rx_param((__int64 *)v14, (__int64)&v23, v15, v16, v17, v18, v19, v20, v21, v22);
        *(_BYTE *)(v14 + 848) = 1;
      }
      *(_DWORD *)(v14 + 1128) = 1;
    }
    else
    {
      if ( v13 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Disable TCP delack as LRO is enabled",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "ucfg_dp_rx_handle_concurrency");
        *(_BYTE *)(v14 + 848) = 0;
        result = dp_reset_tcp_delack(a1);
      }
      *(_DWORD *)(v14 + 1128) = 0;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: DP context not found",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "ucfg_dp_rx_handle_concurrency");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
