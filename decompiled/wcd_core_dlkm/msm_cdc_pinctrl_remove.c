__int64 __fastcall msm_cdc_pinctrl_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  if ( v1 )
  {
    if ( (*(_DWORD *)(v1 + 32) & 0x80000000) == 0 )
      gpio_free();
    if ( *(_QWORD *)v1 )
      devm_pinctrl_put(*(_QWORD *)v1);
  }
  return devm_kfree(a1 + 16, v1);
}
