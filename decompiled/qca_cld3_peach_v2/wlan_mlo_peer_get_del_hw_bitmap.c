__int64 __fastcall wlan_mlo_peer_get_del_hw_bitmap(__int64 result, _DWORD *a2)
{
  __int64 v2; // x21
  __int64 v3; // x20

  _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(result + 784);
  if ( v2 )
  {
    v3 = result;
    qdf_mutex_acquire(v2 + 120);
    if ( *(_DWORD *)(v2 + 24) | *(unsigned __int16 *)(v2 + 28) )
    {
      if ( *(_QWORD *)(v2 + 16) == v3 )
      {
        if ( !*(_BYTE *)(v2 + 48) )
        {
LABEL_11:
          result = qdf_mutex_release(v2 + 120);
          goto LABEL_12;
        }
      }
      else if ( (*(_BYTE *)(v2 + 48) & 1) == 0 )
      {
        *a2 |= 1 << *(_BYTE *)(v2 + 32);
      }
    }
    if ( *(_DWORD *)(v2 + 64) | *(unsigned __int16 *)(v2 + 68)
      && *(_QWORD *)(v2 + 56) != v3
      && (*(_BYTE *)(v2 + 88) & 1) == 0 )
    {
      *a2 |= 1 << *(_BYTE *)(v2 + 72);
    }
    goto LABEL_11;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
