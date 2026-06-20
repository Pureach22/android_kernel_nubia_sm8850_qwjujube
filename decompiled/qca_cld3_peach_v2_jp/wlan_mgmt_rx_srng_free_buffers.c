__int64 __fastcall wlan_mgmt_rx_srng_free_buffers(__int64 result)
{
  __int64 v1; // x19
  __int64 i; // x20
  __int64 v3; // x8

  v1 = result;
  for ( i = 0; i != 3072; i += 24 )
  {
    v3 = *(_QWORD *)(v1 + 80);
    if ( *(_BYTE *)(v3 + i + 17) == 1 )
    {
      _qdf_nbuf_unmap_single(*(_QWORD *)(v1 + 16), *(_QWORD *)(v3 + i), 2);
      result = *(_QWORD *)(*(_QWORD *)(v1 + 80) + i);
      if ( result )
        result = _qdf_nbuf_free(result);
    }
  }
  return result;
}
