__int64 __fastcall mlo_mlme_handle_sta_csa_param(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 (__fastcall *v6)(__int64, __int64); // x8

  result = wlan_objmgr_get_mlo_ctx();
  if ( result )
  {
    v5 = *(_QWORD *)(result + 352);
    if ( v5 )
    {
      v6 = *(__int64 (__fastcall **)(__int64, __int64))(v5 + 88);
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != -419716457 )
          __break(0x8228u);
        return v6(a1, a2);
      }
    }
  }
  return result;
}
