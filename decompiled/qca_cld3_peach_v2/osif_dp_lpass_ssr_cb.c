__int64 __fastcall osif_dp_lpass_ssr_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 - 8);
  if ( v6 )
    v6 = *(_QWORD *)(v6 + 2120);
  v7 = *(_QWORD *)(v6 + 40);
  v17[0] = 0;
  if ( (unsigned int)_osif_psoc_sync_op_start(v7, v17, "osif_dp_lpass_ssr_cb") )
  {
    result = 0;
  }
  else
  {
    if ( a2 == 2 )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: LPASS before shutdown event received - crashed:%u",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "osif_dp_lpass_ssr_cb",
        *(unsigned __int8 *)(a3 + 8));
      if ( *(_BYTE *)(a3 + 8) == 1 )
        ucfg_dp_direct_link_handle_lpass_ssr_notif(*(_QWORD *)(a1 - 8));
    }
    _osif_psoc_sync_op_stop(v17[0], "osif_dp_lpass_ssr_cb");
    result = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
