// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_5AFFA4(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19
  __int64 v19; // x20
  int v20; // w30
  __int64 result; // x0

  if ( v20 )
    return ucfg_dlm_wifi_off(a1);
  result = dp_srng_free(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( *(unsigned __int8 *)(v19 + 3737) > 1u )
  {
    result = dp_srng_free(v18, v18 + 160, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( *(unsigned __int8 *)(v19 + 3737) > 2u )
    {
      __break(0x5512u);
      JUMPOUT(0x50055C);
    }
  }
  return result;
}
