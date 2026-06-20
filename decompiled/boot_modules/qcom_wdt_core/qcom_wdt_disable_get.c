__int64 __fastcall qcom_wdt_disable_get(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20

  v3 = *(_QWORD *)(a1 + 152);
  mutex_lock(v3 + 56);
  LODWORD(a3) = scnprintf(a3, 4096, "%d\n", *(unsigned __int8 *)(v3 + 208) ^ 1u);
  mutex_unlock(v3 + 56);
  return (int)a3;
}
