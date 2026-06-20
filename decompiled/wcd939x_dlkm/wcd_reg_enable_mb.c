__int64 __fastcall wcd_reg_enable_mb(__int64 a1)
{
  __int64 *v2; // x19
  _QWORD *drvdata; // x0
  __int64 result; // x0
  unsigned int v5; // w1
  __int64 v6; // x20

  v2 = (__int64 *)((__int64 (*)(void))rdev_get_drvdata)();
  drvdata = (_QWORD *)rdev_get_drvdata(a1);
  if ( drvdata[1] == a1 )
  {
    v5 = 1;
    v6 = 0;
  }
  else if ( drvdata[2] == a1 )
  {
    v5 = 2;
    v6 = 1;
  }
  else if ( drvdata[3] == a1 )
  {
    v5 = 3;
    v6 = 2;
  }
  else
  {
    if ( drvdata[4] != a1 )
      return 4294967277LL;
    v5 = 4;
    v6 = 3;
  }
  result = wcd939x_micb_external_event(*v2, v5, 1);
  if ( !(_DWORD)result )
    *((_BYTE *)v2 + v6 + 40) = 1;
  return result;
}
