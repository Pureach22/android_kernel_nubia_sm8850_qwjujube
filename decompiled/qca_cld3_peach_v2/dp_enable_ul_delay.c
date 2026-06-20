__int64 __fastcall dp_enable_ul_delay(
        __int64 a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x21
  char v15; // w23
  int v17; // w8

  if ( a2 >= 3 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: Invalid client id: %u", a4, a5, a6, a7, a8, a9, a10, a11, "dp_enable_ul_delay", a2);
    return 4;
  }
  v14 = a1 + 40960;
  v15 = a3 & 1;
  raw_spin_lock(a1 + 43536);
  *(_BYTE *)(v14 + 2604 + a2) = v15;
  if ( (a3 & 1) != 0 )
  {
    v17 = 1;
  }
  else
  {
    if ( (*(_BYTE *)(v14 + 2604) & 1) != 0 || (*(_BYTE *)(v14 + 2605) & 1) != 0 || (*(_BYTE *)(v14 + 2606) & 1) != 0 )
      goto LABEL_9;
    v17 = 0;
  }
  *(_DWORD *)(v14 + 2592) = v17;
LABEL_9:
  raw_spin_unlock(a1 + 43536);
  return 0;
}
