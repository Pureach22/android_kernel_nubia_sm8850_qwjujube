__int64 __fastcall dp_service_srngs_wrapper(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 16) + 1872LL);
  if ( *((_DWORD *)v1 - 1) != -4250500 )
    __break(0x8228u);
  return v1();
}
