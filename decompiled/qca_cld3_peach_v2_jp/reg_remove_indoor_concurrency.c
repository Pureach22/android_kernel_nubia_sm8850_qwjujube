__int64 __fastcall reg_remove_indoor_concurrency(
        __int64 a1,
        unsigned __int8 a2,
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
  unsigned __int8 *pdev_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w10
  unsigned __int8 *v23; // x21
  __int64 v24; // x5
  __int64 result; // x0

  pdev_obj = (unsigned __int8 *)reg_get_pdev_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !pdev_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: pdev reg component is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "reg_remove_indoor_concurrency");
    return 16;
  }
  v22 = *((_DWORD *)pdev_obj + 14741);
  v23 = pdev_obj + 58960;
  if ( v22 != a3 )
  {
    if ( a2 == 255 )
    {
      if ( *((_DWORD *)pdev_obj + 14745) == a3 )
      {
        v23 = pdev_obj + 58976;
LABEL_15:
        v24 = 1;
        goto LABEL_16;
      }
      if ( *((_DWORD *)pdev_obj + 14749) == a3 )
      {
        v23 = pdev_obj + 58992;
        v24 = 2;
        goto LABEL_16;
      }
      return 16;
    }
    if ( *v23 == a2 )
    {
      v24 = 0;
    }
    else
    {
      v22 = *((_DWORD *)pdev_obj + 14745);
      v23 = pdev_obj + 58976;
      if ( v22 == a3 )
        goto LABEL_15;
      if ( *v23 == a2 )
      {
        v24 = 1;
      }
      else
      {
        v22 = *((_DWORD *)pdev_obj + 14749);
        v23 = pdev_obj + 58992;
        if ( v22 == a3 )
        {
          v24 = 2;
          goto LABEL_16;
        }
        if ( *v23 != a2 )
          return 16;
        v24 = 2;
      }
    }
    a3 = v22;
    goto LABEL_16;
  }
  v24 = 0;
LABEL_16:
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: Removed freq %d from idx %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "reg_remove_indoor_concurrency",
    a3,
    v24);
  result = 0;
  *((_DWORD *)v23 + 1) = 0;
  *v23 = -1;
  *((_QWORD *)v23 + 1) = 0;
  return result;
}
