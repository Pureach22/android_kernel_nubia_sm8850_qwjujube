__int64 __fastcall gsi_opts_release(__int64 a1)
{
  __int64 v1; // x9
  __int64 v2; // x19

  v1 = *(_QWORD *)(a1 + 176);
  if ( v1 )
  {
    v2 = a1;
    ipc_log_string(*(_QWORD *)(v1 + 1344), "%s: releasing %s instance\n", "gsi_opts_release", *(const char **)v1);
    a1 = v2;
  }
  return usb_put_function_instance(a1);
}
