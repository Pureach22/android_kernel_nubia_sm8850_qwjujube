__int64 __fastcall mlo_mlme_peer_assoc(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x8

  result = wlan_objmgr_get_mlo_ctx();
  if ( result )
  {
    v3 = *(_QWORD *)(result + 352);
    if ( v3 )
    {
      v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 32);
      if ( v4 )
      {
        if ( *((_DWORD *)v4 - 1) != 1223560042 )
          __break(0x8228u);
        return v4(a1);
      }
    }
  }
  return result;
}
