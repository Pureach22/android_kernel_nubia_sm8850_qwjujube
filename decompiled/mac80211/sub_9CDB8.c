__int64 sub_9CDB8()
{
  __int64 v0; // x14
  __int64 v1; // d20
  __int64 v2; // d21

  *(_QWORD *)(v0 + 104) = v1;
  *(_QWORD *)(v0 + 112) = v2;
  return _bpf_trace_local_chanctx();
}
