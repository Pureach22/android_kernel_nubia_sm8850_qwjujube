__int64 __fastcall tgt_vdev_mgr_reset_response_timer_info(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 v12; // x4

  result = mlme_psoc_get_priv(a1);
  if ( result )
  {
    *(_DWORD *)(result + 96) = 0;
    v11 = result;
    if ( (*(_BYTE *)(result + 112) & 1) != 0 )
    {
      *(_BYTE *)(result + 112) = 0;
      result = qdf_runtime_pm_allow_suspend((__int64 *)(result + 120));
    }
    *(_QWORD *)(v11 + 16) = 0;
    *(_DWORD *)(v11 + 208) = 0;
    if ( *(_BYTE *)(v11 + 224) == 1 )
    {
      *(_BYTE *)(v11 + 224) = 0;
      result = qdf_runtime_pm_allow_suspend((__int64 *)(v11 + 232));
    }
    *(_QWORD *)(v11 + 128) = 0;
    *(_DWORD *)(v11 + 320) = 0;
    if ( *(_BYTE *)(v11 + 336) == 1 )
    {
      *(_BYTE *)(v11 + 336) = 0;
      result = qdf_runtime_pm_allow_suspend((__int64 *)(v11 + 344));
    }
    *(_QWORD *)(v11 + 240) = 0;
    *(_DWORD *)(v11 + 432) = 0;
    if ( *(_BYTE *)(v11 + 448) == 1 )
    {
      *(_BYTE *)(v11 + 448) = 0;
      result = qdf_runtime_pm_allow_suspend((__int64 *)(v11 + 456));
    }
    *(_QWORD *)(v11 + 352) = 0;
    *(_DWORD *)(v11 + 544) = 0;
    if ( *(_BYTE *)(v11 + 560) == 1 )
    {
      *(_BYTE *)(v11 + 560) = 0;
      result = qdf_runtime_pm_allow_suspend((__int64 *)(v11 + 568));
    }
    *(_QWORD *)(v11 + 464) = 0;
    *(_DWORD *)(v11 + 656) = 0;
    if ( *(_BYTE *)(v11 + 672) == 1 )
    {
      *(_BYTE *)(v11 + 672) = 0;
      result = qdf_runtime_pm_allow_suspend((__int64 *)(v11 + 680));
    }
    *(_QWORD *)(v11 + 576) = 0;
  }
  else
  {
    if ( a1 )
      v12 = *(unsigned __int8 *)(a1 + 48);
    else
      v12 = 255;
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: PSOC_%d PSOC_MLME is NULL",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "tgt_vdev_mgr_reset_response_timer_info",
             v12);
  }
  return result;
}
