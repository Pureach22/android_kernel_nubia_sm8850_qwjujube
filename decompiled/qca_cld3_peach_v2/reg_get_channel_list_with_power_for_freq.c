__int64 __fastcall reg_get_channel_list_with_power_for_freq(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_obj; // x0
  __int64 v14; // x9
  int v15; // w8
  __int64 v16; // x12
  const char *v17; // x2

  if ( !a2 || !a3 )
  {
    v17 = "%s: chan_list or num_ch is NULL";
LABEL_12:
    qdf_trace_msg(0x51u, 2u, v17, a4, a5, a6, a7, a8, a9, a10, a11, "reg_get_channel_list_with_power_for_freq");
    return 16;
  }
  pdev_obj = reg_get_pdev_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !pdev_obj )
  {
    v17 = "%s: reg pdev priv obj is NULL";
    goto LABEL_12;
  }
  v14 = 0;
  v15 = 0;
  do
  {
    if ( *(_DWORD *)(pdev_obj + v14 + 8) )
    {
      if ( (*(_BYTE *)(pdev_obj + v14 + 12) & 1) == 0 )
      {
        v16 = a2 + 12LL * v15++;
        *(_DWORD *)v16 = *(_DWORD *)(pdev_obj + v14);
        *(_BYTE *)(v16 + 4) = *(_BYTE *)(pdev_obj + v14 + 4);
        *(_DWORD *)(v16 + 8) = *(_DWORD *)(pdev_obj + v14 + 16);
      }
    }
    v14 += 36;
  }
  while ( v14 != 3672 );
  *a3 = v15;
  return 0;
}
