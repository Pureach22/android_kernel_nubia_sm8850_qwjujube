__int64 __fastcall check_ai_scaler_feature(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  if ( !a1 )
    return 4294967274LL;
  v1 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v1 >= 3 )
  {
    __break(0x5512u);
    MEMORY[0x25981E0]();
    JUMPOUT(0x1A8C8C);
  }
  v2 = *(__int64 (**)(void))(a1 + 8 * v1 + 1408);
  if ( !v2 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 732LL) & 1) == 0 )
    {
      _drm_dev_dbg(0, 0, 1, "AI Scaler not supported in dspp idx %d", *(_DWORD *)(a1 + 64));
      return 0;
    }
    return 4294967274LL;
  }
  if ( *((_DWORD *)v2 - 1) != 905945830 )
    __break(0x8228u);
  return v2();
}
