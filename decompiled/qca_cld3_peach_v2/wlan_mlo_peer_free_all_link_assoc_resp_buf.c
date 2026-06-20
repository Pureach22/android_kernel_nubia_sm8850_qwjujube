__int64 __fastcall wlan_mlo_peer_free_all_link_assoc_resp_buf(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x0

  v1 = *(_QWORD *)(result + 784);
  if ( v1 )
  {
    qdf_mutex_acquire(v1 + 120);
    v2 = *(_QWORD *)(v1 + 40);
    if ( v2 )
    {
      _qdf_nbuf_free(v2);
      *(_QWORD *)(v1 + 40) = 0;
    }
    v3 = *(_QWORD *)(v1 + 80);
    if ( v3 )
    {
      _qdf_nbuf_free(v3);
      *(_QWORD *)(v1 + 80) = 0;
    }
    return qdf_mutex_release(v1 + 120);
  }
  return result;
}
