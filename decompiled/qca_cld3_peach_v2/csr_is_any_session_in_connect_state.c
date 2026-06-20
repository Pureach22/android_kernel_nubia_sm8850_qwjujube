__int64 __fastcall csr_is_any_session_in_connect_state(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x8
  bool is_vdevid_connected; // w8
  __int64 result; // x0
  int opmode_from_vdev_id; // w8
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x8

  if ( !a1 )
    return 0;
  v1 = *(_QWORD *)(a1 + 17296);
  if ( !v1 )
    return 0;
  if ( *(_BYTE *)(v1 + 1) == 1
    && (cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), 0)
     || (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 0) & 0xFFFFFFFD) == 1) )
  {
    return 1;
  }
  v3 = *(_QWORD *)(a1 + 17296);
  if ( !v3 )
    return 0;
  if ( *(_BYTE *)(v3 + 97) != 1
    || (is_vdevid_connected = cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), 1u), result = 1, !is_vdevid_connected)
    && (opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 1),
        result = 1,
        (opmode_from_vdev_id & 0xFFFFFFFD) != 1) )
  {
    v7 = *(_QWORD *)(a1 + 17296);
    if ( v7 )
    {
      if ( *(_BYTE *)(v7 + 193) == 1
        && (cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), 2u)
         || (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 2) & 0xFFFFFFFD) == 1) )
      {
        return 1;
      }
      v8 = *(_QWORD *)(a1 + 17296);
      if ( v8 )
      {
        if ( *(_BYTE *)(v8 + 289) == 1
          && (cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), 3u)
           || (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 3) & 0xFFFFFFFD) == 1) )
        {
          return 1;
        }
        v9 = *(_QWORD *)(a1 + 17296);
        if ( v9 )
        {
          if ( *(_BYTE *)(v9 + 385) == 1
            && (cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), 4u)
             || (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 4) & 0xFFFFFFFD) == 1) )
          {
            return 1;
          }
          v10 = *(_QWORD *)(a1 + 17296);
          if ( v10 )
          {
            if ( *(_BYTE *)(v10 + 481) == 1
              && (cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), 5u)
               || (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 5) & 0xFFFFFFFD) == 1) )
            {
              return 1;
            }
          }
        }
      }
    }
    return 0;
  }
  return result;
}
