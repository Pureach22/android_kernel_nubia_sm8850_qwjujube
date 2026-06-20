__int64 __fastcall wlan_hdd_get_ani_level_dealloc(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 8);
  if ( result )
    return _qdf_mem_free(result);
  return result;
}
