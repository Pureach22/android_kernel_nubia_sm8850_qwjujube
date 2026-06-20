__int64 __fastcall hdd_power_debugstats_dealloc(__int64 a1)
{
  __int64 result; // x0

  result = _qdf_mem_free(*(_QWORD *)(a1 + 24));
  *(_QWORD *)(a1 + 24) = 0;
  return result;
}
