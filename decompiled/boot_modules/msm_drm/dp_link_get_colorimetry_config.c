__int64 __fastcall dp_link_get_colorimetry_config(__int64 a1)
{
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    if ( (*(_DWORD *)(a1 + 208) & 0x42) == 2 )
      return 4 * (unsigned int)(*(_DWORD *)(a1 + 24) == 1);
    else
      return 0;
  }
  else
  {
    ipc_log_context = get_ipc_log_context((unsigned __int8)a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_link_get_colorimetry_config");
    return 4294967274LL;
  }
}
