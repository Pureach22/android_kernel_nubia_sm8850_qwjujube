__int64 __fastcall hdd_update_chan_info(
        __int64 a1,
        _DWORD *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v14; // w9
  int v15; // w10
  int v16; // w8
  int v17; // w9

  if ( a3[1] >= 2u )
    qdf_trace_msg(0x33u, 2u, "%s: cmd flag is invalid: %d", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_update_chan_info");
  mutex_lock(a1 + 1744);
  if ( !a3[1] )
    qdf_mem_set(a2, 0x64u, 0);
  v14 = a2[3];
  v15 = a2[4];
  *a2 = *a3;
  a2[2] = a3[2];
  a2[6] = a3[6];
  a2[1] = a3[1];
  v16 = a3[3] - v14;
  v17 = a2[5];
  a2[3] = v16;
  a2[4] = a3[4] - v15;
  a2[5] = a3[5] - v17;
  return mutex_unlock(a1 + 1744);
}
