__int64 __fastcall wlan_hdd_free_oem_data(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    result = *(_QWORD *)(result + 24);
    if ( result )
    {
      result = _qdf_mem_free(result);
      *(_QWORD *)(v1 + 24) = 0;
    }
  }
  return result;
}
