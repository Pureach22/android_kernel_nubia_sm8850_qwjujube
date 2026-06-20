__int64 __fastcall wlan_mlme_peer_get_assoc_rsp_ies(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x9

  result = 4;
  if ( a1 )
  {
    if ( a2 )
    {
      if ( a3 )
      {
        *a2 = 0;
        *a3 = 0;
        result = wlan_objmgr_peer_get_comp_private_obj(a1, 0);
        if ( result )
        {
          v7 = result;
          if ( *(_DWORD *)(result + 56) )
          {
            v8 = *(_QWORD *)(result + 64);
            *a2 = v8;
            *a3 = *(unsigned int *)(v7 + 56);
            return 0;
          }
          else
          {
            return 0;
          }
        }
      }
    }
  }
  return result;
}
