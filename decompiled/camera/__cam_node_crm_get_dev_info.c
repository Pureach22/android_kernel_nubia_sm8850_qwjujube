__int64 __fastcall _cam_node_crm_get_dev_info(unsigned int *a1)
{
  __int64 device_priv; // x0

  if ( !a1 )
    return 4294967274LL;
  device_priv = cam_get_device_priv(*a1);
  if ( device_priv )
    return cam_context_handle_crm_get_dev_info(device_priv, (__int64)a1);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    2,
    1,
    "__cam_node_crm_get_dev_info",
    586,
    "Can not get context  for handle %d",
    *a1);
  return 4294967274LL;
}
