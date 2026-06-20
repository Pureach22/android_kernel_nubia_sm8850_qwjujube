__int64 __fastcall qti_qpt_get_power(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19

  v1 = *(_QWORD *)(a1 + 120);
  mutex_lock(v1 + 104);
  v2 = *(_QWORD *)(v1 + 72);
  mutex_unlock(v1 + 104);
  return v2;
}
