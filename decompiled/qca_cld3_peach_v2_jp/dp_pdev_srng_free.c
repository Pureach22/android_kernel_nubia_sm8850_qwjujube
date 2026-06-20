__int64 __fastcall dp_pdev_srng_free(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  unsigned __int8 *v10; // x19
  int v11; // w21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v9 = *(_QWORD *)(result + 8);
  v10 = (unsigned __int8 *)result;
  if ( (*(_BYTE *)(v9 + 20040) & 2) == 0 )
  {
    if ( *(unsigned __int8 *)(result + 1) >= 2uLL )
    {
LABEL_10:
      __break(0x5512u);
      return dp_pdev_srng_deinit(result);
    }
    result = dp_srng_free(
               *(_QWORD *)(result + 8),
               v9 + 80LL * *(unsigned __int8 *)(result + 1) + 80,
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9);
  }
  if ( (*(_BYTE *)(v9 + 20064) & 1) == 0 && *(_BYTE *)(*(_QWORD *)(v9 + 40) + 804LL) )
  {
    v11 = 0;
    while ( 1 )
    {
      result = dp_get_lmac_id_for_pdev_id(v9, v11, *v10);
      if ( (unsigned int)result > 2 )
        break;
      result = dp_srng_free(v9, v9 + 320 + 80LL * (unsigned int)result, v12, v13, v14, v15, v16, v17, v18, v19);
      if ( ++v11 >= (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v9 + 40) + 804LL) )
        return result;
    }
    goto LABEL_10;
  }
  return result;
}
