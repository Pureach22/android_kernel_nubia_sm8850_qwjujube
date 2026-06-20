__int64 ipa3_q6_pre_powerup_cleanup()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 result; // x0

  if ( ipa3_ctx )
  {
    v0 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v0 )
      ipc_log_string(v0, "ipa %s:%d ENTER\n", "ipa3_q6_pre_powerup_cleanup", 5588);
  }
  v1 = ipa3_inc_client_enable_clks_no_log();
  if ( *(_BYTE *)(ipa3_ctx + 32260) == 1 && (*(_BYTE *)(ipa3_ctx + 32268) & 1) == 0 )
  {
    v1 = ipa3_set_reset_client_prod_pipe_delay(1, 42);
    if ( *(_BYTE *)(ipa3_ctx + 32264) == 1 )
      v1 = ipa3_set_reset_client_prod_pipe_delay(1, 112);
  }
  result = _ipa3_dec_client_disable_clks(v1);
  if ( ipa3_ctx )
  {
    result = *(_QWORD *)(ipa3_ctx + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d Exit with success\n", "ipa3_q6_pre_powerup_cleanup", 5603);
  }
  return result;
}
