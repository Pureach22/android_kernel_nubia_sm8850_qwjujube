__int64 __fastcall tpda_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 152);
  coresight_trace_id_put_system_id(*(unsigned __int8 *)(v1 + 28));
  return coresight_unregister(*(_QWORD *)(v1 + 16));
}
