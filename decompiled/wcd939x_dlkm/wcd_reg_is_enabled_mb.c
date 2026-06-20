__int64 __fastcall wcd_reg_is_enabled_mb(__int64 a1)
{
  __int64 drvdata; // x19
  _QWORD *v3; // x0
  __int64 v5; // x8

  drvdata = rdev_get_drvdata(a1);
  v3 = (_QWORD *)rdev_get_drvdata(a1);
  if ( v3[1] == a1 )
  {
    v5 = 0;
  }
  else if ( v3[2] == a1 )
  {
    v5 = 1;
  }
  else if ( v3[3] == a1 )
  {
    v5 = 2;
  }
  else
  {
    if ( v3[4] != a1 )
      return 0;
    v5 = 3;
  }
  return *(unsigned __int8 *)(drvdata + v5 + 40);
}
