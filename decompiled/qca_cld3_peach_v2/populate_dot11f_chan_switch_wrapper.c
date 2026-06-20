__int64 __fastcall populate_dot11f_chan_switch_wrapper(
        __int64 result,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w8
  __int16 v12; // w9
  __int16 v14; // [xsp+6h] [xbp-Ah] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_BYTE *)a2 = 1;
  v11 = *(_DWORD *)(a3 + 7228);
  v12 = *(_WORD *)(a3 + 7226);
  *(_BYTE *)(a2 + 1) = 1;
  *(_WORD *)(a2 + 3) = v12;
  *(_BYTE *)(a2 + 2) = (v11 & 0xFFFFFFFE) == 2;
  if ( *(_BYTE *)(a3 + 7170) )
  {
    result = populate_dot11f_tx_power_env(
               result,
               a3,
               (_BYTE *)(a2 + 8),
               *(_DWORD *)(a3 + 7212),
               *(_DWORD *)(a3 + 7204),
               &v14,
               1,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11);
    *(_WORD *)(a2 + 6) = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
