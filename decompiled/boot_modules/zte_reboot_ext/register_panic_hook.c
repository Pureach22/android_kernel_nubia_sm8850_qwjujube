__int64 __fastcall register_panic_hook(__int64 a1)
{
  int v2; // w0

  v2 = register_kretprobe(&panic_probe);
  if ( v2 )
    return dev_err(a1 + 16, "ztedbg failed to register p_hook: %d\n", v2);
  else
    return dev_info(a1 + 16, "ztedbg register p_hook\n");
}
