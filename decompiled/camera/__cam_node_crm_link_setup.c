__int64 __fastcall _cam_node_crm_link_setup(_DWORD *a1)
{
  __int64 device_priv; // x0

  if ( !a1 )
    return 4294967274LL;
  device_priv = cam_get_device_priv(a1[2]);
  if ( device_priv )
  {
    if ( *a1 )
      return cam_context_handle_crm_link(device_priv, (__int64)a1);
    else
      return cam_context_handle_crm_unlink(device_priv, (__int64)a1);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_crm_link_setup",
      604,
      "Can not get context for handle %d",
      a1[2]);
    return 4294967274LL;
  }
}
