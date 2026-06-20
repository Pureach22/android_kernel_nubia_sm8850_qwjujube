__int64 __fastcall qcom_system_heap_free(__int64 a1)
{
  return deferred_free(a1 + 128, system_heap_deferred_free, (unsigned __int64)(*(_QWORD *)(a1 + 72) + 4095LL) >> 12);
}
