unsigned __int16 *__fastcall wlan_get_operation_chan_freq(unsigned __int16 *result)
{
  if ( result )
  {
    result = (unsigned __int16 *)wlan_vdev_get_active_channel((__int64)result);
    if ( result )
      return (unsigned __int16 *)*result;
  }
  return result;
}
