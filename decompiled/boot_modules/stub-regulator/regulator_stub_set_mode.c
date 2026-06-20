__int64 __fastcall regulator_stub_set_mode(__int64 a1, int a2)
{
  __int64 drvdata; // x8

  drvdata = rdev_get_drvdata();
  if ( a2 == 2 || a2 == 4 )
  {
    *(_DWORD *)(drvdata + 328) = a2;
    return 0;
  }
  else
  {
    dev_err(a1 + 232, "%s: invalid mode requested %u\n", "regulator_stub_set_mode", a2);
    return 4294967274LL;
  }
}
