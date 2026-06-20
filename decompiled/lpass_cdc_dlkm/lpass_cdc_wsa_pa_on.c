__int64 __fastcall lpass_cdc_wsa_pa_on(__int64 a1, char a2)
{
  __int64 v4; // x8
  __int64 v5; // x1
  __int64 result; // x0

  if ( a1 )
  {
    if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 744LL), "qcom,lpass-cdc") )
    {
      v4 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
      if ( v4 )
      {
        if ( (a2 & 1) != 0 )
          v5 = 6;
        else
          v5 = 5;
        return blocking_notifier_call_chain(v4 + 1008, v5, *(_QWORD *)(v4 + 1000));
      }
      else
      {
        result = __ratelimit(&lpass_cdc_wsa_pa_on__rs_33, "lpass_cdc_wsa_pa_on");
        if ( (_DWORD)result )
          return dev_err(a1, "%s: priv is null\n", "lpass_cdc_wsa_pa_on");
      }
    }
    else
    {
      result = __ratelimit(&lpass_cdc_wsa_pa_on__rs_32, "lpass_cdc_wsa_pa_on");
      if ( (_DWORD)result )
        return dev_err(a1, "%s: not a valid child dev\n", "lpass_cdc_wsa_pa_on");
    }
  }
  else
  {
    result = __ratelimit(&lpass_cdc_wsa_pa_on__rs, "lpass_cdc_wsa_pa_on");
    if ( (_DWORD)result )
      return printk(&unk_DCD3, "lpass_cdc_wsa_pa_on");
  }
  return result;
}
