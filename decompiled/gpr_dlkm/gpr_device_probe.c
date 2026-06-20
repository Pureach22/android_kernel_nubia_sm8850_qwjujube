__int64 __fastcall gpr_device_probe(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 136) - 24LL);
  if ( *((_DWORD *)v1 - 1) != -465457219 )
    __break(0x8228u);
  return v1();
}
