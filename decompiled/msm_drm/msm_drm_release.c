__int64 __fastcall msm_drm_release(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 56);
  *(_QWORD *)(a1 + 56) = 0;
  return kfree(v1);
}
