__int64 __fastcall stm_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 152);
  if ( (*(_BYTE *)(v1 + 176) & 1) == 0 )
    coresight_trace_id_put_system_id(*(unsigned __int8 *)(v1 + 144));
  coresight_unregister(*(_QWORD *)(v1 + 24));
  return stm_unregister_device(v1 + 64);
}
