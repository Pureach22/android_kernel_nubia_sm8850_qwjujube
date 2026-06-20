__int64 __fastcall init_deinit_spectral_scaling_params_free(__int64 a1)
{
  __int64 v2; // x0

  v2 = *(_QWORD *)(a1 + 3320);
  if ( !v2 )
    return 16;
  _qdf_mem_free(v2);
  *(_QWORD *)(a1 + 3320) = 0;
  return 0;
}
