__int64 __fastcall wlan_logging_notifier_deinit(char a1)
{
  if ( (unsigned __int8)word_76E1D8 == 1 && (a1 & 1) == 0 )
    atomic_notifier_chain_unregister(&panic_notifier_list, &panic_nb);
  return 0;
}
