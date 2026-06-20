__int64 __fastcall wcd9378_mbhc_register_notifier(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x0

  v3 = a1 + 976;
  if ( (a3 & 1) != 0 )
    return blocking_notifier_chain_register(v3);
  else
    return blocking_notifier_chain_unregister(v3);
}
