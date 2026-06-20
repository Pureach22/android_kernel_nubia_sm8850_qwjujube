__int64 __fastcall lim_process_set_vdev_ies_per_band(
        __int64 a1,
        __int64 a2,
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
  const char *v13; // x2

  if ( a2 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: rcvd set vdev ie per band req vdev_id = %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_process_set_vdev_ies_per_band",
      *(unsigned int *)(a2 + 4));
    result = lim_send_ies_per_band(a1, *(unsigned int *)(a2 + 4), *(unsigned __int16 *)(a2 + 8));
    if ( !(_DWORD)result )
      return result;
    v13 = "%s: Unable to send HT/VHT Cap to FW";
  }
  else
  {
    v13 = "%s: NULL p_msg";
  }
  return qdf_trace_msg(0x35u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_set_vdev_ies_per_band");
}
