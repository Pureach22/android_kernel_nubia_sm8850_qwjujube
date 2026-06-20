__int64 __fastcall qcom_secure_system_heap_drain(__int64 a1, unsigned __int64 a2)
{
  return _qcom_secure_system_heap_resize(a1, a2, 1);
}
