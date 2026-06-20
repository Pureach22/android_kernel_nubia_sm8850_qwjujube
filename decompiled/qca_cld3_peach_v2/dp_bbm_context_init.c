__int64 __fastcall dp_bbm_context_init(__int64 a1)
{
  __int64 comp_private_obj; // x0
  __int64 v2; // x19
  _QWORD *v3; // x0
  __int64 v4; // x20
  __int64 result; // x0
  unsigned int v6; // w21

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
    return 4294967274LL;
  v2 = comp_private_obj;
  v3 = (_QWORD *)_qdf_mem_malloc(0x60u, "dp_bbm_context_init", 498);
  if ( !v3 )
    return 4294967284LL;
  v4 = (__int64)v3;
  *v3 = &bus_bw_table_default;
  result = qdf_mutex_create((__int64)(v3 + 4));
  if ( (_DWORD)result )
  {
    v6 = result;
    _qdf_mem_free(v4);
    return qdf_status_to_os_return(v6);
  }
  else
  {
    *(_QWORD *)(v2 + 1160) = v4;
  }
  return result;
}
