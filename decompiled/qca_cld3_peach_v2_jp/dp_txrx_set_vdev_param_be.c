__int64 __fastcall dp_txrx_set_vdev_param_be(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned int a11)
{
  if ( a11 > 0x18 )
    goto LABEL_7;
  if ( ((1 << a11) & 0x401040) != 0 )
  {
LABEL_6:
    dp_tx_update_bank_profile();
    return 0;
  }
  if ( ((1 << a11) & 0x1800000) == 0 )
  {
    if ( a11 == 9 )
    {
      if ( !*(_DWORD *)(a10 + 40) )
        goto LABEL_6;
      return 0;
    }
LABEL_7:
    qdf_trace_msg(0x45u, 3u, "%s: invalid param %d", a1, a2, a3, a4, a5, a6, a7, a8, "dp_txrx_set_vdev_param_be", a11);
  }
  return 0;
}
