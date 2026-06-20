__int64 __fastcall wlan_mlo_link_peer_assoc_set(__int64 result, char a2)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8

  v2 = *(_QWORD *)(result + 784);
  if ( v2 )
  {
    v3 = result;
    qdf_mutex_acquire(v2 + 120);
    v5 = *(_QWORD *)(v2 + 16);
    if ( v5 && v5 == v3 )
    {
      v6 = 16;
    }
    else
    {
      v7 = *(_QWORD *)(v2 + 56);
      if ( !v7 || v7 != v3 )
        return qdf_mutex_release(v2 + 120);
      v6 = 56;
    }
    *(_BYTE *)(v2 + v6 + 32) = a2 & 1;
    return qdf_mutex_release(v2 + 120);
  }
  return result;
}
