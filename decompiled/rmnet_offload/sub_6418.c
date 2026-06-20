__int64 sub_6418()
{
  __int64 v0; // x20
  __int64 v1; // x24
  __int64 v2; // x30

  *(_QWORD *)(v0 - 168) = v2;
  *(_QWORD *)(v0 - 160) = v1;
  return rmnet_offload_engine_flush_by_hash();
}
