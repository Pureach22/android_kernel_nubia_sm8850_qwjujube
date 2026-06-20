__int64 __fastcall reg_is_6g_psd_power(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 pdev_obj; // x0
  __int64 v10; // x8
  const char *v11; // x2
  char v12; // w8

  if ( a1 )
  {
    pdev_obj = reg_get_pdev_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( pdev_obj )
    {
      v10 = 0;
      while ( (*(_BYTE *)(pdev_obj + v10 + 1524) & 1) != 0 )
      {
        v10 += 36;
        if ( v10 == 2160 )
          goto LABEL_10;
      }
      v12 = *(_BYTE *)(pdev_obj + v10 + 1539);
      return v12 & 1;
    }
    v11 = "%s: pdev priv obj is NULL";
  }
  else
  {
    v11 = "%s: pdev is NULL";
  }
  qdf_trace_msg(0x51u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "reg_is_6g_psd_power");
LABEL_10:
  v12 = 0;
  return v12 & 1;
}
