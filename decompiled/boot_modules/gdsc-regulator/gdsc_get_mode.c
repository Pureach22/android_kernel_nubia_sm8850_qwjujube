__int64 __fastcall gdsc_get_mode(__int64 a1)
{
  __int64 drvdata; // x0
  __int64 v2; // x8
  int v3; // w8
  unsigned int v4; // w9

  drvdata = rdev_get_drvdata(a1);
  v2 = 479;
  if ( *(_BYTE *)(drvdata + 513) )
    v2 = 514;
  v3 = *(unsigned __int8 *)(drvdata + v2);
  if ( *(_BYTE *)(drvdata + 513) )
    v4 = 4;
  else
    v4 = 1;
  if ( v3 )
    return v4;
  else
    return 2;
}
