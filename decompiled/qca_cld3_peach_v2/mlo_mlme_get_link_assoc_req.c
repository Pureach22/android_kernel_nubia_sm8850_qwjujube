__int64 __fastcall mlo_mlme_get_link_assoc_req(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  _DWORD *v6; // x8

  result = wlan_objmgr_get_mlo_ctx();
  if ( result )
  {
    v5 = *(_QWORD *)(result + 352);
    if ( v5 && (v6 = *(_DWORD **)(v5 + 64)) != nullptr )
    {
      if ( *(v6 - 1) != -1002027501 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, _QWORD))v6)(a1, a2);
    }
    else
    {
      return 0;
    }
  }
  return result;
}
