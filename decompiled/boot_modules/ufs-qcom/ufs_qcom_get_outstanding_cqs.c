__int64 __fastcall ufs_qcom_get_outstanding_cqs(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 5056);
  if ( !v2 )
    return 4294967274LL;
  *a2 = (unsigned int)readl((unsigned int *)(v2 + 8));
  return 0;
}
