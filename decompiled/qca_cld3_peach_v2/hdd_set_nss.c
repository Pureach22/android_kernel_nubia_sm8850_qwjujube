__int64 __fastcall hdd_set_nss(unsigned __int8 *a1, __int64 a2)
{
  unsigned int v2; // w19
  unsigned int updated; // w0
  __int64 result; // x0

  v2 = *(unsigned __int8 *)(a2 + 4);
  updated = hdd_update_nss(a1, *(unsigned __int8 *)(a2 + 4), *(unsigned __int8 *)(a2 + 4));
  result = qdf_status_to_os_return(updated);
  if ( !(_DWORD)result )
  {
    if ( *(_DWORD *)(*(_QWORD *)a1 + 40LL) == 1 )
      return wma_cli_set_command(a1[8], 34, v2, 1);
    else
      return 0;
  }
  return result;
}
