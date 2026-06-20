__int64 __fastcall init_deinit_aux_dev_cap_free(__int64 a1)
{
  __int64 v2; // x0

  v2 = *(_QWORD *)(a1 + 4496);
  if ( v2 )
  {
    _qdf_mem_free(v2);
    *(_QWORD *)(a1 + 4496) = 0;
  }
  return 0;
}
