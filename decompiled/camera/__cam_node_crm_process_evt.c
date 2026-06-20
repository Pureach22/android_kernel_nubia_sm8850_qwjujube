__int64 __fastcall _cam_node_crm_process_evt(__int64 a1)
{
  __int64 device_priv; // x0

  if ( a1 )
  {
    device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
    if ( device_priv )
      return cam_context_handle_crm_process_evt(device_priv, a1);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_crm_process_evt",
      687,
      "Can not get context for handle %d",
      *(_DWORD *)(a1 + 4));
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_crm_process_evt",
      680,
      "Invalid process event request payload");
  }
  return 4294967274LL;
}
