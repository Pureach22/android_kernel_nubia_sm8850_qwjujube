__int64 __fastcall wlan_ipa_flush_pending_vdev_events(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x21
  __int64 v5; // x24

  qdf_mutex_acquire(a1 + 7224);
  v4 = *(_QWORD *)(a1 + 4016);
  if ( v4 != a1 + 4016 )
  {
    do
    {
      v5 = *(_QWORD *)v4;
      if ( *(unsigned __int8 *)(v4 + 33) == a2 )
      {
        qdf_list_remove_node(a1 + 4016, (_QWORD *)v4);
        _qdf_mem_free(v4);
      }
      v4 = v5;
    }
    while ( v5 != a1 + 4016 );
  }
  return qdf_mutex_release(a1 + 7224);
}
