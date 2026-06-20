__int64 __fastcall wcd_reg_disable_mb(__int64 a1)
{
  __int64 *drvdata; // x19
  _QWORD *v3; // x0
  unsigned int v4; // w1
  __int64 v5; // x20

  drvdata = (__int64 *)rdev_get_drvdata(a1);
  v3 = (_QWORD *)rdev_get_drvdata(a1);
  if ( v3[1] == a1 )
  {
    v4 = 1;
LABEL_9:
    v5 = v4 - 1;
    goto LABEL_10;
  }
  if ( v3[2] == a1 )
  {
    v4 = 2;
    goto LABEL_9;
  }
  if ( v3[3] == a1 )
  {
    v4 = 3;
    goto LABEL_9;
  }
  if ( v3[4] == a1 )
  {
    v4 = 4;
    v5 = 3;
LABEL_10:
    wcd939x_micb_external_event(*drvdata, v4, 0);
    *((_BYTE *)drvdata + v5 + 40) = 0;
  }
  return 0;
}
