__int64 __fastcall msm_gem_map_vma(__int64 a1)
{
  __int64 (*v1)(void); // x8

  if ( !a1 )
    return 4294967274LL;
  v1 = **(__int64 (***)(void))(a1 + 272);
  if ( !v1 )
    return 4294967274LL;
  if ( *((_DWORD *)v1 - 1) != -134049547 )
    __break(0x8228u);
  return v1();
}
