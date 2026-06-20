__int64 __fastcall lpass_cdc_register_notifier(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x0

  if ( a1 && a2 )
  {
    v3 = a1 + 1008;
    if ( (a3 & 1) != 0 )
      return blocking_notifier_chain_register(v3);
    else
      return blocking_notifier_chain_unregister(v3);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_register_notifier__rs, "lpass_cdc_register_notifier") )
      printk(&unk_D24E, "lpass_cdc_register_notifier");
    return 4294967274LL;
  }
}
