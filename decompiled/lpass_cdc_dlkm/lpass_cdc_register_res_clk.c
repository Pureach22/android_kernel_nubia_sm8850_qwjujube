__int64 __fastcall lpass_cdc_register_res_clk(_QWORD *a1, __int64 a2)
{
  __int64 v4; // x8

  if ( a1 && a2 )
  {
    if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1[12] + 744LL), "qcom,lpass-cdc") )
    {
      v4 = *(_QWORD *)(a1[12] + 152LL);
      if ( v4 )
      {
        *(_QWORD *)(v4 + 1080) = a1;
        *(_QWORD *)(v4 + 1088) = a2;
        return 0;
      }
      if ( (unsigned int)__ratelimit(&lpass_cdc_register_res_clk__rs_12, "lpass_cdc_register_res_clk") )
        dev_err(a1, "%s: priv is null\n", "lpass_cdc_register_res_clk");
    }
    else if ( (unsigned int)__ratelimit(&lpass_cdc_register_res_clk__rs_10, "lpass_cdc_register_res_clk") )
    {
      dev_err(a1, "%s: child device :%pK not added yet\n", "lpass_cdc_register_res_clk", a1);
    }
  }
  else if ( (unsigned int)__ratelimit(&lpass_cdc_register_res_clk__rs, "lpass_cdc_register_res_clk") )
  {
    printk(&unk_DA5F, "lpass_cdc_register_res_clk");
  }
  return 4294967274LL;
}
