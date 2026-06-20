__int64 __fastcall msm_gem_address_space_unregister_cb(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 272);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(__int64 (**)(void))(v1 + 48);
  if ( !v2 )
    return 4294967274LL;
  if ( *((_DWORD *)v2 - 1) != 1017392984 )
    __break(0x8228u);
  return v2();
}
