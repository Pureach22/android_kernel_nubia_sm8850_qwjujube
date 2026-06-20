unsigned __int16 *__fastcall reg_get_bonded_chan_entry(
        unsigned int a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x9
  __int64 v12; // x4
  unsigned int v13; // w8
  __int64 v14; // x9
  unsigned int v15; // w10
  unsigned __int16 *result; // x0

  if ( a2 - 1 > 3 )
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: Could not find bonded_chan_array for chwidth %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "reg_get_bonded_chan_entry",
      a2);
    return nullptr;
  }
  v11 = (__int64)*(&off_9E6378 + a2 - 1);
  v12 = a1;
  v13 = *(unsigned __int16 *)(v11 + 16);
  if ( !*(_WORD *)(v11 + 16) )
  {
LABEL_9:
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: Could not find a bonded pair for freq %d and width %d cen320_freq %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "reg_get_bonded_chan_entry",
      v12,
      a2,
      a3);
    return nullptr;
  }
  v14 = *(_QWORD *)(v11 + 8);
  v15 = 0;
  while ( 1 )
  {
    result = (unsigned __int16 *)(v14 + 4LL * v15);
    if ( *result <= (unsigned int)v12 && result[1] >= (unsigned int)v12 )
      return result;
    if ( ++v15 >= v13 )
      goto LABEL_9;
  }
}
