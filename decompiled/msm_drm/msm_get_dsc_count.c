__int64 __fastcall msm_get_dsc_count(__int64 a1)
{
  __int64 v1; // x0
  __int64 (*v2)(void); // x8

  if ( !a1 )
  {
    _drm_err("invalid drm private struct\n");
    return 4294967274LL;
  }
  v1 = *(_QWORD *)(a1 + 8);
  if ( !v1 )
  {
    _drm_err("invalid msm kms struct\n");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)v1 || (v2 = *(__int64 (**)(void))(*(_QWORD *)v1 + 296LL)) == nullptr )
  {
    _drm_err("invalid function pointers\n");
    return 4294967274LL;
  }
  if ( *((_DWORD *)v2 - 1) != 917429457 )
    __break(0x8228u);
  return v2();
}
