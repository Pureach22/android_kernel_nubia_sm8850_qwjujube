__int64 __fastcall trace_noc_remove(__int64 a1)
{
  return coresight_unregister(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 16LL));
}
