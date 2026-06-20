__int64 __fastcall wlan_mlo_peer_get_primary_peer_link_id_by_ml_peer(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x8
  __int64 v11; // x8
  unsigned int v12; // w20
  const char *v14; // x2

  if ( a1 )
  {
    qdf_mutex_acquire(a1 + 120);
    if ( *(_DWORD *)(a1 + 200) > 1u )
    {
      qdf_mutex_release(a1 + 120);
      v14 = "%s: ml_peer is not created and association is not done";
    }
    else
    {
      v10 = *(_QWORD *)(a1 + 16);
      if ( v10 && *(_BYTE *)(a1 + 31) == 1 || (v10 = *(_QWORD *)(a1 + 56)) != 0 && (*(_BYTE *)(a1 + 71) & 1) != 0 )
      {
        v11 = *(_QWORD *)(v10 + 96);
        if ( v11 )
        {
          v12 = *(unsigned __int8 *)(v11 + 93);
          qdf_mutex_release(a1 + 120);
          return v12;
        }
        qdf_mutex_release(a1 + 120);
        v14 = "%s: link vdev not found";
      }
      else
      {
        qdf_mutex_release(a1 + 120);
        v14 = "%s: None of the peer is designated as primary";
      }
    }
  }
  else
  {
    v14 = "%s: ml_peer is null";
  }
  qdf_trace_msg(0x8Fu, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mlo_peer_get_primary_peer_link_id_by_ml_peer");
  return 255;
}
