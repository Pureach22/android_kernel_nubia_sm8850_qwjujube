__int64 __fastcall policy_mgr_is_vdev_active_ll_sap(__int64 result, __int64 a2, _BYTE *a3)
{
  __int64 v3; // x21
  unsigned int v4; // w20

  if ( a3 )
  {
    if ( *(_DWORD *)(a2 + 16) == 1 )
    {
      v3 = result;
      v4 = *(unsigned __int8 *)(a2 + 168);
      result = wlan_vdev_is_up();
      if ( !(_DWORD)result )
      {
        result = *(_QWORD *)(v3 + 80);
        if ( result )
        {
          result = policy_mgr_is_vdev_ll_lt_sap(result, v4);
          if ( (result & 1) != 0 )
            *a3 = v4;
        }
      }
    }
  }
  return result;
}
