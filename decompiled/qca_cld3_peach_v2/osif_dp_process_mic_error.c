__int64 __fastcall osif_dp_process_mic_error(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v10; // x8
  __int64 v11; // x8
  __int64 v12; // x19
  __int64 result; // x0
  __int64 v15; // [xsp+0h] [xbp-10h] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  if ( a2 && (v10 = *(__int64 **)(a2 + 680)) != nullptr && (v11 = *v10) != 0 && (v12 = *(_QWORD *)(v11 + 32)) != 0 )
  {
    result = _osif_vdev_sync_op_start(*(_QWORD *)(v11 + 32), &v15, "osif_dp_process_mic_error");
    if ( !(_DWORD)result )
    {
      cfg80211_michael_mic_failure(
        v12,
        a1,
        *(unsigned __int8 *)(a1 + 6) ^ 1u,
        *(unsigned __int8 *)(a1 + 7),
        a1 + 8,
        3264);
      result = _osif_vdev_sync_op_stop(v15, "osif_dp_process_mic_error");
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: failed to get netdev",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "osif_dp_process_mic_error",
               v15,
               v16);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
