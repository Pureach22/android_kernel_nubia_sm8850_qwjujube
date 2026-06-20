__int64 __fastcall msm_atomic_state_free(__int64 a1)
{
  kfree(*(_QWORD *)(a1 + 120));
  drm_atomic_state_default_release(a1);
  return kfree(a1);
}
