__int64 __fastcall mlo_mlme_peer_reassoc(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v9; // x8
  __int64 (__fastcall *v10)(__int64, __int64, __int64, __int64); // x8

  result = wlan_objmgr_get_mlo_ctx();
  if ( result )
  {
    v9 = *(_QWORD *)(result + 352);
    if ( v9 )
    {
      v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v9 + 104);
      if ( v10 )
      {
        if ( *((_DWORD *)v10 - 1) != -1051888654 )
          __break(0x8228u);
        return v10(a1, a2, a3, a4);
      }
    }
  }
  return result;
}
