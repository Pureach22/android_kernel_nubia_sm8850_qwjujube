__int64 __fastcall dp_bbm_context_deinit(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x19

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( result )
  {
    v2 = *(_QWORD *)(result + 1160);
    if ( v2 )
    {
      *(_QWORD *)(result + 1160) = 0;
      qdf_mutex_destroy(v2 + 32);
      return _qdf_mem_free(v2);
    }
  }
  return result;
}
