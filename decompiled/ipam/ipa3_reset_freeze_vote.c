__int64 ipa3_reset_freeze_vote()
{
  __int64 v0; // x8
  __int64 result; // x0

  v0 = ipa3_ctx;
  if ( *(_BYTE *)(ipa3_ctx + 43729) == 1 )
  {
    if ( *(_BYTE *)(ipa3_ctx + 43728) == 1 )
    {
      _ipa3_dec_client_disable_clks();
      v0 = ipa3_ctx;
    }
    result = qcom_smem_state_update_bits(*(_QWORD *)(v0 + 43736), 3, 0);
    *(_WORD *)(ipa3_ctx + 43728) = 0;
  }
  return result;
}
