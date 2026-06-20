_QWORD *__fastcall reset_160mhz_delivery_state_machine(
        _QWORD *result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  _QWORD *v11; // x19
  _DWORD *v12; // x9
  _QWORD *v13; // x21
  __int64 v14; // x20
  __int64 v15; // x0

  if ( a2 < 2 )
  {
    v11 = result + 148;
    if ( (unsigned int)(*((_DWORD *)result + a2 + 296) - 3) <= 1 )
    {
      v12 = (_DWORD *)result[161];
      v13 = result;
      v14 = a2;
      v15 = *result;
      if ( *(v12 - 1) != 1779743641 )
        __break(0x8229u);
      result = (_QWORD *)((__int64 (__fastcall *)(__int64, _QWORD))v12)(v15, a2);
      if ( (unsigned int)(*((_DWORD *)v11 + v14) - 3) <= 1 )
        *((_DWORD *)v13 + v14 + 344) = 0;
    }
  }
  else
  {
    v10 = jiffies;
    if ( reset_160mhz_delivery_state_machine___last_ticks - jiffies + 125 < 0 )
    {
      result = (_QWORD *)qdf_trace_msg(
                           0x56u,
                           2u,
                           "%s: Invalid Spectral mode %d",
                           a3,
                           a4,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           a10,
                           "reset_160mhz_delivery_state_machine",
                           a2);
      reset_160mhz_delivery_state_machine___last_ticks = v10;
    }
  }
  return result;
}
