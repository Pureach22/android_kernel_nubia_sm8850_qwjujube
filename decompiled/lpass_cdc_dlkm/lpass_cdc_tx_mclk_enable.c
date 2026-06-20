__int64 __fastcall lpass_cdc_tx_mclk_enable(__int64 a1, char a2)
{
  _QWORD *v2; // x21
  _DWORD *v5; // x8

  if ( !a1 )
    return 4294967274LL;
  v2 = *(_QWORD **)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v2 )
    return 4294967274LL;
  if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(*v2 + 744LL), "qcom,lpass-cdc") )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_tx_mclk_enable__rs, "lpass_cdc_tx_mclk_enable") )
      dev_err(*(_QWORD *)(a1 + 24), "%s: invalid codec\n", "lpass_cdc_tx_mclk_enable");
    return 4294967274LL;
  }
  v5 = (_DWORD *)v2[40];
  if ( !v5 )
    return 0;
  if ( *(v5 - 1) != -1230333146 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v5)(a1, a2 & 1);
}
