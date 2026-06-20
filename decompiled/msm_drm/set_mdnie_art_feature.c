__int64 __fastcall set_mdnie_art_feature(__int64 a1)
{
  __int64 v1; // x8
  void (*v2)(void); // x8
  __int64 v4; // x0

  if ( !a1 )
    return 4294967274LL;
  v1 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v1 >= 3 )
  {
    __break(0x5512u);
    v4 = MEMORY[0x2597C78]();
    return check_aiqe_ssrc_data(v4);
  }
  v2 = *(void (**)(void))(a1 + 8 * v1 + 1192);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != -448913827 )
      __break(0x8228u);
    v2();
    return 0;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 616LL) & 1) != 0 )
    return 4294967274LL;
  _drm_dev_dbg(0, 0, 1, "MDNIE not supported in dspp idx %d", *(_DWORD *)(a1 + 64));
  return 0;
}
