__int64 __fastcall msm_pdev_shutdown(__int64 a1)
{
  __int64 v1; // x0
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 168);
  if ( !v1 )
    return _drm_err("invalid drm device node\n");
  v2 = *(_QWORD *)(v1 + 56);
  if ( !v2 )
    return _drm_err("invalid msm drm private node or drm dev not registered\n");
  v3 = v2 + 4096;
  if ( (*(_BYTE *)(v2 + 5680) & 1) == 0 )
    return _drm_err("invalid msm drm private node or drm dev not registered\n");
  result = msm_lastclose();
  *(_BYTE *)(v3 + 1600) = 1;
  return result;
}
