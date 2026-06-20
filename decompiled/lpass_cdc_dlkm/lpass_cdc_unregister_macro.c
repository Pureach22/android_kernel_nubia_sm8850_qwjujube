__int64 __fastcall lpass_cdc_unregister_macro(__int64 a1, unsigned __int16 a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x9

  if ( a1 )
  {
    result = of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 744LL), "qcom,lpass-cdc");
    if ( (_DWORD)result )
    {
      if ( a2 <= 4u )
      {
        v5 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
        if ( v5 )
        {
          v6 = v5 + 112LL * a2;
          *(_QWORD *)(v6 + 232) = 0;
          v7 = v6 + 232;
          *(_WORD *)(v7 + 16) = 0;
          *(_QWORD *)(v7 + 48) = 0;
          *(_QWORD *)(v7 + 24) = 0;
          *(_QWORD *)(v7 + 32) = 0;
          if ( a2 != 3 )
          {
            if ( a2 )
              goto LABEL_9;
            *(_QWORD *)(v7 + 56) = 0;
            *(_QWORD *)(v7 + 80) = 0;
            *(_QWORD *)(v7 + 88) = 0;
          }
          *(_QWORD *)(v7 + 72) = 0;
LABEL_9:
          if ( *(unsigned __int16 *)(v5 + 804) - 1 == (unsigned __int16)--*(_WORD *)(v5 + 802) )
            return snd_soc_unregister_component(*(_QWORD *)(a1 + 96));
          return result;
        }
      }
      result = __ratelimit(&lpass_cdc_unregister_macro__rs_28, "lpass_cdc_unregister_macro");
      if ( (_DWORD)result )
        return dev_err(a1, "%s: priv is null or invalid macro\n", "lpass_cdc_unregister_macro");
    }
    else
    {
      result = __ratelimit(&lpass_cdc_unregister_macro__rs_26, "lpass_cdc_unregister_macro");
      if ( (_DWORD)result )
        return dev_err(a1, "%s: macro:%d not in valid registered macro-list\n", "lpass_cdc_unregister_macro", a2);
    }
  }
  else
  {
    result = __ratelimit(&lpass_cdc_unregister_macro__rs, "lpass_cdc_unregister_macro");
    if ( (_DWORD)result )
      return printk(&unk_DCD3, "lpass_cdc_unregister_macro");
  }
  return result;
}
