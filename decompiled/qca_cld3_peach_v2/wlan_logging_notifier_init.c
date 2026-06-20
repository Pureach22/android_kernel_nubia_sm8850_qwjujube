__int64 __fastcall wlan_logging_notifier_init(char a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  result = 0;
  if ( (unsigned __int8)word_826C80 == 1 && (a1 & 1) == 0 )
  {
    result = atomic_notifier_chain_register(&panic_notifier_list, &panic_nb);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Failed to register panic notifier",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "wlan_logging_notifier_init");
      return 4294967274LL;
    }
  }
  return result;
}
