__int64 __fastcall csr_get_concurrent_operation_freq(__int64 a1)
{
  __int64 result; // x0

  if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), 0) > 3
    || (result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21560), 0), !(_DWORD)result) )
  {
    if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), 1u) > 3
      || (result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21560), 1u), !(_DWORD)result) )
    {
      if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), 2u) > 3
        || (result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21560), 2u), !(_DWORD)result) )
      {
        if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), 3u) > 3
          || (result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21560), 3u), !(_DWORD)result) )
        {
          if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), 4u) > 3
            || (result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21560), 4u), !(_DWORD)result) )
          {
            if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), 5u) > 3 )
              return 0;
            result = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21560), 5u);
            if ( !(_DWORD)result )
              return 0;
          }
        }
      }
    }
  }
  return result;
}
