__int64 __fastcall sub_144F44(
        double a1,
        double a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        _DWORD *a9)
{
  __int64 v9; // d30
  __int64 v10; // d31

  *a9 = HIDWORD(v9);
  a9[1] = HIDWORD(v10);
  a9[2] = HIDWORD(a1);
  a9[3] = HIDWORD(a2);
  return sde_reglog_init();
}
