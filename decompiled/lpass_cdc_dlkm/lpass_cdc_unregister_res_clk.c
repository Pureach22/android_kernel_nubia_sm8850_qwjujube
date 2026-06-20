__int64 __fastcall lpass_cdc_unregister_res_clk(_QWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x8

  if ( a1 )
  {
    result = of_device_is_compatible(*(_QWORD *)(a1[12] + 744LL), "qcom,lpass-cdc");
    if ( (_DWORD)result )
    {
      v3 = *(_QWORD *)(a1[12] + 152LL);
      if ( v3 )
      {
        *(_QWORD *)(v3 + 1088) = 0;
        *(_QWORD *)(v3 + 1080) = 0;
      }
      else
      {
        result = __ratelimit(&lpass_cdc_unregister_res_clk__rs_16, "lpass_cdc_unregister_res_clk");
        if ( (_DWORD)result )
          return dev_err(a1, "%s: priv is null\n", "lpass_cdc_unregister_res_clk");
      }
    }
    else
    {
      result = __ratelimit(&lpass_cdc_unregister_res_clk__rs_14, "lpass_cdc_unregister_res_clk");
      if ( (_DWORD)result )
        return dev_err(a1, "%s: child device :%pK not added\n", "lpass_cdc_unregister_res_clk", a1);
    }
  }
  else
  {
    result = __ratelimit(&lpass_cdc_unregister_res_clk__rs, "lpass_cdc_unregister_res_clk");
    if ( (_DWORD)result )
      return printk(&unk_DB5A, "lpass_cdc_unregister_res_clk");
  }
  return result;
}
