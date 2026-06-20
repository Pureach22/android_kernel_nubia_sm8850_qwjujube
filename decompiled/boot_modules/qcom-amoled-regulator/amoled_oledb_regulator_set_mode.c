__int64 __fastcall amoled_oledb_regulator_set_mode(__int64 a1, int a2)
{
  __int64 drvdata; // x8

  drvdata = rdev_get_drvdata();
  *(_DWORD *)(drvdata + 352) = a2;
  return 0;
}
