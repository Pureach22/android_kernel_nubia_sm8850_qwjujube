__int64 __fastcall tmc_free_etr_buf(__int64 a1)
{
  __int64 v1; // x8
  void (*v3)(void); // x8

  v1 = *(_QWORD *)(a1 + 48);
  if ( !v1 || (v3 = *(void (**)(void))(v1 + 24)) == nullptr )
  {
    __break(0x800u);
    v3 = *(void (**)(void))(*(_QWORD *)(a1 + 48) + 24LL);
  }
  if ( *((_DWORD *)v3 - 1) != 1050944703 )
    __break(0x8228u);
  v3();
  return kfree(a1);
}
