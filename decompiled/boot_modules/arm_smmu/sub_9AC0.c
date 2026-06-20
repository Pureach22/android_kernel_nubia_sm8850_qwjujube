__int64 sub_9AC0()
{
  __int64 v0; // x17
  __int64 v1; // d25
  __int64 v2; // d30

  *(_QWORD *)(v0 - 64) = v1;
  *(_QWORD *)(v0 - 56) = v2;
  return _traceiter_tlbsync_timeout();
}
