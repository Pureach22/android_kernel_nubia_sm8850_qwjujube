__int64 __fastcall lim_get_max_tx_power(
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
  char fcc_constraint; // w8
  __int64 result; // x0
  unsigned int v13; // w8
  unsigned int v14; // w10

  fcc_constraint = wlan_reg_get_fcc_constraint(
                     *(_QWORD *)(a1 + 21560),
                     *(_DWORD *)(a2 + 556),
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10);
  result = *(unsigned __int8 *)(a2 + 536);
  if ( (fcc_constraint & 1) == 0 )
  {
    v13 = *(unsigned __int8 *)(a2 + 552);
    if ( (unsigned int)result < v13 )
      v13 = *(unsigned __int8 *)(a2 + 536);
    if ( v13 >= 8 )
      v14 = 24;
    else
      v14 = 8;
    if ( (unsigned __int8)(v13 - 8) >= 0x11u )
      return v14;
    else
      return v13;
  }
  return result;
}
