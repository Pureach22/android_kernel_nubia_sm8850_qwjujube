void __fastcall lim_is_6g_vdev(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  unsigned __int16 operation_chan_freq; // w0
  __int64 v6; // x8

  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 16) == 1 && !(unsigned int)wlan_vdev_chan_config_valid(a2) )
    {
      operation_chan_freq = (unsigned __int16)wlan_get_operation_chan_freq((unsigned __int16 *)a2);
      if ( wlan_reg_is_6ghz_chan_freq(operation_chan_freq) )
      {
        if ( *a3 == 255 )
        {
          v6 = 0;
        }
        else if ( a3[1] == 255 )
        {
          v6 = 1;
        }
        else if ( a3[2] == 255 )
        {
          v6 = 2;
        }
        else if ( a3[3] == 255 )
        {
          v6 = 3;
        }
        else
        {
          if ( a3[4] != 255 )
            return;
          v6 = 4;
        }
        a3[v6] = *(_BYTE *)(a2 + 104);
      }
    }
  }
}
