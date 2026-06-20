__int64 __fastcall wlan_mlo_link_peer_attach(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 result; // x0
  unsigned int v13; // w9

  if ( !a1 )
    return 16;
  v3 = *(_QWORD *)(a2 + 96);
  if ( !v3 )
    return 16;
  result = mlo_peer_attach_link_peer(a1, a2, a3);
  if ( !(_DWORD)result )
  {
    qdf_mutex_acquire(a1 + 120);
    _X8 = (unsigned int *)(a1 + 188);
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 + 1, _X8) );
    *(_QWORD *)(a2 + 784) = a1;
    qdf_mutex_release(a1 + 120);
    if ( *(_DWORD *)(v3 + 16) != 1 || *(unsigned __int8 *)(a1 + 97) != *(unsigned __int8 *)(a1 + 96) )
      return 0;
    result = *(_QWORD *)(a1 + 16);
    if ( result )
    {
      mlo_mlme_peer_assoc_resp(result);
      return 0;
    }
  }
  return result;
}
