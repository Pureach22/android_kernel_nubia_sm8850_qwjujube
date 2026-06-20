__int64 __fastcall mlo_peer_get_link_peer_assoc_resp_buf(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x20
  int v3; // w21
  __int64 v5; // x8
  __int64 v6; // x0

  v2 = 0;
  if ( a1 )
  {
    v3 = a2;
    if ( a2 <= 2u )
    {
      qdf_mutex_acquire(a1 + 120);
      if ( *(_DWORD *)(a1 + 200) <= 1u )
      {
        if ( *(_QWORD *)(a1 + 16) && *(unsigned __int8 *)(a1 + 30) == v3 )
        {
          v5 = 16;
        }
        else
        {
          if ( !*(_QWORD *)(a1 + 56) || *(unsigned __int8 *)(a1 + 70) != v3 )
            goto LABEL_12;
          v5 = 56;
        }
        v6 = *(_QWORD *)(a1 + v5 + 24);
        if ( v6 )
        {
          v2 = _qdf_nbuf_clone(v6);
LABEL_13:
          qdf_mutex_release(a1 + 120);
          return v2;
        }
      }
LABEL_12:
      v2 = 0;
      goto LABEL_13;
    }
  }
  return v2;
}
