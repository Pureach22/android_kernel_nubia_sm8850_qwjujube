__int64 __fastcall hif_get_direct_link_ce_dest_srng_buffers(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 30696) + 144LL);
  if ( !v1 )
    return 0;
  if ( *((_DWORD *)v1 - 1) != 367269747 )
    __break(0x8228u);
  return v1();
}
