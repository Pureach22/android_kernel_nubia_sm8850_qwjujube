bool __fastcall dp_skip_ftm_mode_wbm_ring_init(__int64 a1)
{
  unsigned int (*v1)(void); // x8

  v1 = *(unsigned int (**)(void))(*(_QWORD *)(a1 + 8) + 200LL);
  if ( !v1 )
    return 0;
  if ( *((_DWORD *)v1 - 1) != 1696218653 )
    __break(0x8228u);
  return v1() == 5;
}
