__int64 __fastcall csr_get_beaconing_concurrent_channel(__int64 a1, char a2)
{
  __int64 v4; // x21
  char v5; // w1
  __int64 v6; // x21
  __int64 v7; // x21
  __int64 v8; // x21
  __int64 v9; // x21
  __int64 result; // x0
  __int64 v11; // x20

  if ( a1 )
  {
    if ( a2 )
    {
      v4 = *(_QWORD *)(a1 + 17296);
      if ( v4 )
      {
        if ( *(_BYTE *)(v4 + 1) == 1
          && (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 0) & 0xFFFFFFFD) == 1
          && *(_DWORD *)(v4 + 4) )
        {
          v5 = 0;
          return wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), v5);
        }
      }
    }
  }
  if ( a1 )
  {
    if ( a2 != 1 )
    {
      v6 = *(_QWORD *)(a1 + 17296);
      if ( v6 )
      {
        if ( *(_BYTE *)(v6 + 97) == 1
          && (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 1) & 0xFFFFFFFD) == 1
          && *(_DWORD *)(v6 + 100) )
        {
          v5 = 1;
          return wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), v5);
        }
      }
    }
  }
  if ( a1 )
  {
    if ( a2 != 2 )
    {
      v7 = *(_QWORD *)(a1 + 17296);
      if ( v7 )
      {
        if ( *(_BYTE *)(v7 + 193) == 1
          && (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 2) & 0xFFFFFFFD) == 1
          && *(_DWORD *)(v7 + 196) )
        {
          v5 = 2;
          return wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), v5);
        }
      }
    }
  }
  if ( a1 )
  {
    if ( a2 != 3 )
    {
      v8 = *(_QWORD *)(a1 + 17296);
      if ( v8 )
      {
        if ( *(_BYTE *)(v8 + 289) == 1
          && (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 3) & 0xFFFFFFFD) == 1
          && *(_DWORD *)(v8 + 292) )
        {
          v5 = 3;
          return wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), v5);
        }
      }
    }
  }
  if ( a1 )
  {
    if ( a2 != 4 )
    {
      v9 = *(_QWORD *)(a1 + 17296);
      if ( v9 )
      {
        if ( *(_BYTE *)(v9 + 385) == 1
          && (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 4) & 0xFFFFFFFD) == 1
          && *(_DWORD *)(v9 + 388) )
        {
          v5 = 4;
          return wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), v5);
        }
      }
    }
  }
  result = 0;
  if ( a1 && a2 != 5 )
  {
    v11 = *(_QWORD *)(a1 + 17296);
    if ( v11
      && *(_BYTE *)(v11 + 481) == 1
      && (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 5) & 0xFFFFFFFD) == 1
      && *(_DWORD *)(v11 + 484) )
    {
      v5 = 5;
      return wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), v5);
    }
    return 0;
  }
  return result;
}
