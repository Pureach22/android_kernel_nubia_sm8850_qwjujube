__int64 __fastcall wcd939x_swr_dmic_register_notifier(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x8
  __int64 v4; // x0

  if ( a1 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
    v4 = v3 + 3240;
    *(_BYTE *)(v3 + 3232) = a3 & 1;
    if ( (a3 & 1) != 0 )
      return blocking_notifier_chain_register(v4);
    else
      return blocking_notifier_chain_unregister(v4);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&wcd939x_swr_dmic_register_notifier__rs, "wcd939x_swr_dmic_register_notifier") )
      printk(&unk_19447, "wcd939x_swr_dmic_register_notifier");
    return 4294967274LL;
  }
}
