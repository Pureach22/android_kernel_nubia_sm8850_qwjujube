__int64 __fastcall csr_get_concurrent_operation_freq(__int64 a1)
{
  __int64 result; // x0

  if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 0) > 3
    || (result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), 0), !(_DWORD)result) )
  {
    if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 1) > 3
      || (result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), 1), !(_DWORD)result) )
    {
      if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 2) > 3
        || (result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), 2), !(_DWORD)result) )
      {
        if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 3) > 3
          || (result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), 3), !(_DWORD)result) )
        {
          if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 4) > 3
            || (result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), 4), !(_DWORD)result) )
          {
            if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), 5) > 3 )
              return 0;
            result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), 5);
            if ( !(_DWORD)result )
              return 0;
          }
        }
      }
    }
  }
  return result;
}
