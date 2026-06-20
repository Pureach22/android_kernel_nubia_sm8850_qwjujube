__int64 __fastcall hfi_msm_drv_init(__int64 a1)
{
  _QWORD *v2; // x8
  __int64 v3; // x9

  if ( !a1 )
    return 4294967274LL;
  v2 = (_QWORD *)_kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 56);
  *v2 = v3;
  *(_QWORD *)(v3 + 5920) = v2;
  return 0;
}
