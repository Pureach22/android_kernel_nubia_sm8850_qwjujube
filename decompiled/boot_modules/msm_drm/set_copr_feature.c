__int64 __fastcall set_copr_feature(__int64 a1)
{
  __int64 v1; // x8
  void (*v2)(void); // x8

  if ( !a1 )
    return 4294967274LL;
  v1 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v1 >= 3 )
  {
    __break(0x5512u);
    MEMORY[0x2597E6C]();
    JUMPOUT(0x1A8918);
  }
  v2 = *(void (**)(void))(a1 + 8 * v1 + 1288);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != -448913827 )
      __break(0x8228u);
    v2();
    return 0;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 619LL) & 1) != 0 )
    return 4294967274LL;
  _drm_dev_dbg(0, 0, 1, "COPR not supported in dspp idx %d", *(_DWORD *)(a1 + 64));
  return 0;
}
