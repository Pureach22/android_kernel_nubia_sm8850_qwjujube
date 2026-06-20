__int64 __fastcall regulator_stub_set_voltage(__int64 a1, int a2)
{
  __int64 drvdata; // x8

  drvdata = rdev_get_drvdata();
  *(_DWORD *)(drvdata + 320) = a2;
  return 0;
}
