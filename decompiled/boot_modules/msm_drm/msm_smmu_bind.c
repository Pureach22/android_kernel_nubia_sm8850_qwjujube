__int64 __fastcall msm_smmu_bind(_QWORD *a1, const void *a2)
{
  __int64 v2; // x8

  if ( a1 && a2 )
  {
    v2 = a1[19];
    if ( v2 )
    {
      *(_QWORD *)(v2 + 8) = a2;
      return 0;
    }
    _drm_err("invalid client\n");
  }
  else
  {
    _drm_err("invalid param(s), dev %pK, master %pK\n", a1, a2);
  }
  return 4294967274LL;
}
