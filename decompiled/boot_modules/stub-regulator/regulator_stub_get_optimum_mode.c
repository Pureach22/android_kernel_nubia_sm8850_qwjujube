__int64 __fastcall regulator_stub_get_optimum_mode(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 drvdata; // x0

  drvdata = rdev_get_drvdata();
  if ( *(_DWORD *)(drvdata + 336) + a4 >= *(_DWORD *)(drvdata + 332) )
    return 2;
  else
    return 4;
}
