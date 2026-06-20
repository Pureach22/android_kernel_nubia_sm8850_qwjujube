_BYTE *__fastcall dp_catalog_hpd_set_edp_mode(_BYTE *result, char a2)
{
  __int64 ipc_log_context; // x0

  if ( result )
  {
    *result = a2 & 1;
  }
  else
  {
    ipc_log_context = get_ipc_log_context((unsigned __int8)result);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return (_BYTE *)printk(&unk_275B6D, "dp_catalog_hpd_set_edp_mode");
  }
  return result;
}
