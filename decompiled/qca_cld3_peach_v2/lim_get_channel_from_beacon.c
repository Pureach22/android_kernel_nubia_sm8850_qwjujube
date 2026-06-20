__int64 __fastcall lim_get_channel_from_beacon(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0

  if ( (a2[2703] & 0x20) != 0 )
  {
    LOBYTE(result) = wlan_reg_chan_band_to_freq(
                       *(_QWORD *)(a1 + 21632),
                       (unsigned __int8)a2[2712],
                       4u,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10);
  }
  else if ( a2[2465] || !a2[1260] )
  {
    LOBYTE(result) = a2[72];
  }
  else
  {
    LOBYTE(result) = wlan_reg_legacy_chan_to_freq(
                       *(_QWORD *)(a1 + 21632),
                       (unsigned __int8)a2[1261],
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10);
  }
  return (unsigned __int8)result;
}
