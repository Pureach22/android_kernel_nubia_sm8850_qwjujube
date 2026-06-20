__int64 __fastcall mlo_peer_get_link_peer_assoc_req_buf(__int64 result, unsigned int a2)
{
  __int64 v2; // x21
  __int64 v4; // x20

  if ( result )
  {
    v2 = result;
    qdf_mutex_acquire(result + 120);
    v4 = *(_QWORD *)(v2 + 16);
    qdf_mutex_release(v2 + 120);
    if ( v4 )
      return mlo_mlme_get_link_assoc_req(v4, a2);
    else
      return 0;
  }
  return result;
}
