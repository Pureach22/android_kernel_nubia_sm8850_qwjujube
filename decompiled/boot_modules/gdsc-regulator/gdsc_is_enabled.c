__int64 __fastcall gdsc_is_enabled(__int64 a1)
{
  _BYTE *drvdata; // x0

  drvdata = (_BYTE *)rdev_get_drvdata(a1);
  if ( drvdata[513] == 1 )
    return (unsigned __int8)drvdata[478];
  if ( (drvdata[472] & 1) == 0 )
    return (unsigned __int8)(drvdata[474] ^ 1);
  if ( (drvdata[512] & 1) == 0 )
    return (unsigned __int8)drvdata[478];
  else
    return 0;
}
