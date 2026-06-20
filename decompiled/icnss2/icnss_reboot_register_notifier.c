__int64 __fastcall icnss_reboot_register_notifier(__int64 a1)
{
  __int64 result; // x0
  int v3; // w20
  unsigned __int64 v10; // x9

  *(_QWORD *)(a1 + 2872) = icnss_reboot_notifier;
  result = register_reboot_notifier(a1 + 2872);
  if ( (_DWORD)result )
  {
    v3 = result;
    printk("%sicnss2: Failed to register Reboot notifier, err = %d\n", byte_130B32, result);
    return ipc_log_string(
             icnss_ipc_log_context,
             "%sicnss2: Failed to register Reboot notifier, err = %d\n",
             (const char *)&unk_12DBF3,
             v3);
  }
  else
  {
    _X8 = (unsigned __int64 *)(a1 + 1832);
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stxr(v10 | 0x10000000, _X8) );
  }
  return result;
}
