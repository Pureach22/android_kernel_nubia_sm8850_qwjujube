__int64 sub_8018()
{
  __int64 v0; // x22
  __int64 v1; // d13
  __int64 v2; // d30

  *(_QWORD *)(v0 - 216) = v2;
  *(_QWORD *)(v0 - 208) = v1;
  return _bpf_trace_cache_alloc_timestamp();
}
