__int64 ipa3_client_prod_post_shutdown_cleanup()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 result; // x0

  if ( ipa3_ctx )
  {
    v0 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v0 )
      ipc_log_string(v0, "ipa %s:%d ENTER\n", "ipa3_client_prod_post_shutdown_cleanup", 5614);
  }
  ipa3_inc_client_enable_clks_no_log();
  ipa3_set_reset_client_prod_pipe_delay(1, 18);
  v1 = ((__int64 (__fastcall *)(__int64, __int64))ipa3_start_stop_client_prod_gsi_chnl)(18, 1);
  result = _ipa3_dec_client_disable_clks(v1);
  if ( ipa3_ctx )
  {
    result = *(_QWORD *)(ipa3_ctx + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d Exit with success\n", "ipa3_client_prod_post_shutdown_cleanup", 5623);
  }
  return result;
}
