__int64 __fastcall cm_delete_crypto_keys_for_all_links(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0

  _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(result + 1360);
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 3880);
    if ( v2 )
    {
      if ( *(_DWORD *)(v2 + 24) | *(unsigned __int16 *)(v2 + 28) && *(_DWORD *)v2 | *(unsigned __int16 *)(v2 + 4) )
      {
        v3 = *(_QWORD *)(result + 216);
        v4 = result;
        if ( v3 )
          v5 = *(_QWORD *)(v3 + 80);
        else
          v5 = 0;
        wlan_crypto_free_key_by_link_id(v5, (unsigned __int8 *)v2, *(_BYTE *)(v2 + 6));
        v2 += 48;
        result = v4;
      }
      if ( *(_DWORD *)(v2 + 24) | *(unsigned __int16 *)(v2 + 28) && *(_DWORD *)v2 | *(unsigned __int16 *)(v2 + 4) )
      {
        v6 = *(_QWORD *)(result + 216);
        v7 = result;
        if ( v6 )
          v8 = *(_QWORD *)(v6 + 80);
        else
          v8 = 0;
        wlan_crypto_free_key_by_link_id(v8, (unsigned __int8 *)v2, *(_BYTE *)(v2 + 6));
        v2 += 48;
        result = v7;
      }
      if ( *(_DWORD *)(v2 + 24) | *(unsigned __int16 *)(v2 + 28) && *(_DWORD *)v2 | *(unsigned __int16 *)(v2 + 4) )
      {
        v9 = *(_QWORD *)(result + 216);
        if ( v9 )
          v10 = *(_QWORD *)(v9 + 80);
        else
          v10 = 0;
        result = wlan_crypto_free_key_by_link_id(v10, (unsigned __int8 *)v2, *(_BYTE *)(v2 + 6));
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
