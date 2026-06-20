__int64 __fastcall wlan_mlme_peer_free_aid(__int64 a1, char a2, __int16 a3)
{
  __int64 result; // x0
  __int64 v7; // x21

  result = wlan_objmgr_get_mlo_ctx();
  if ( result )
  {
    if ( (a2 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 8LL * (((a3 & 0x3FFFu) - 1) >> 6)) &= ~(1LL << ((unsigned __int8)a3 - 1));
    }
    else
    {
      v7 = result;
      qdf_mutex_acquire(result + 64);
      *(_QWORD *)(a1 + 8LL * (((a3 & 0x3FFFu) - 1) >> 6)) &= ~(1LL << ((unsigned __int8)a3 - 1));
      return qdf_mutex_release(v7 + 64);
    }
  }
  return result;
}
