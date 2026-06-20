_QWORD *__fastcall cm_handle_roam_reason_invoke_roam_fail(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *result; // x0
  _QWORD *v15; // x21
  __int64 v16; // x0
  __int64 v17; // x22

  result = _cds_get_context(54, (__int64)"cm_handle_roam_reason_invoke_roam_fail", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( result )
  {
    v15 = result;
    ((void (__fastcall *)(_QWORD *, __int64))wma_handle_hw_mode_trans_ind)(result, a3);
    v16 = _qdf_mem_malloc(0x9C8u, "wma_handle_roam_reason_invoke_roam_fail", 2741);
    if ( v16 )
    {
      v17 = v16;
      lim_sae_auth_cleanup_retry(v15[2], a1);
      *(_BYTE *)(v17 + 13) = a1;
      cm_fw_roam_invoke_fail(v15[3], a1);
      wlan_cm_update_roam_states(v15[3], a1, a2, 1);
      _qdf_mem_free(v17);
    }
    return (_QWORD *)((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, _QWORD, _QWORD, _QWORD, _QWORD))cm_report_roam_rt_stats)(
                       v15[3],
                       a1,
                       1,
                       0,
                       a2,
                       0,
                       0);
  }
  return result;
}
