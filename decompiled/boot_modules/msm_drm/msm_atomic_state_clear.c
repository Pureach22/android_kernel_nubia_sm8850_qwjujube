__int64 __fastcall msm_atomic_state_clear(__int64 a1)
{
  __int64 result; // x0

  drm_atomic_state_default_clear();
  result = kfree(*(_QWORD *)(a1 + 120));
  *(_QWORD *)(a1 + 120) = 0;
  return result;
}
