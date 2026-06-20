__int64 __fastcall icnss_wpss_early_notifier_nb(__int64 a1, __int64 a2)
{
  const char *v4; // x21
  unsigned __int64 v12; // x8
  unsigned __int64 v14; // x9

  if ( (a2 & 0xFFFFFFFC) != 0 )
    v4 = "UNKNOWN";
  else
    v4 = off_A88E0[a2 & 3];
  printk("%sicnss2: WPSS-EARLY-Notify: event %s(%lu)\n", byte_13289B, v4, a2);
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2: WPSS-EARLY-Notify: event %s(%lu)\n",
    (const char *)&unk_12DBF3,
    v4,
    a2);
  if ( a2 == 2 )
  {
    _X20 = (unsigned __int64 *)(a1 - 984);
    __asm { PRFM            #0x11, [X20] }
    do
      v12 = __ldxr(_X20);
    while ( __stxr(v12 | 0x2000, _X20) );
    icnss_ignore_fw_timeout(1);
    __asm { PRFM            #0x11, [X20] }
    do
      v14 = __ldxr(_X20);
    while ( __stxr(v14 & 0xFFFFFFFFF7FFFFFFLL, _X20) );
    complete(a1 + 2992);
  }
  return 0;
}
