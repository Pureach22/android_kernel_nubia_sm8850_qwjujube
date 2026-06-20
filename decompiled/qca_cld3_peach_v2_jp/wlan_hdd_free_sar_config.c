__int64 __fastcall wlan_hdd_free_sar_config(__int64 result)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(result + 3848);
  if ( v1 )
  {
    *(_QWORD *)(result + 3848) = 0;
    _qdf_mem_free(*(_QWORD *)(v1 + 16));
    return _qdf_mem_free(v1);
  }
  return result;
}
