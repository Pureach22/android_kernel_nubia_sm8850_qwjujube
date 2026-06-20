__int64 __fastcall _gpr_driver_register(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a1 + 32) = &gprbus;
  *(_QWORD *)(a1 + 40) = a2;
  return driver_register(a1 + 24);
}
