__int64 __fastcall dummy_source_disable(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x0

  v1 = *(_QWORD *)(*(_QWORD *)(result + 152) + 152LL);
  if ( (unsigned int)*(_QWORD *)(result + 968) == 1 )
  {
    v2 = result;
    coresight_csr_set_etr_atid(result, *(unsigned __int8 *)(v1 + 16), 0, 0);
    v3 = *(unsigned __int8 *)(v1 + 16);
    if ( *(_BYTE *)(v1 + 17) == 1 )
      result = coresight_trace_id_free_reserved_id(v3);
    else
      result = coresight_trace_id_put_system_id(v3);
    *(_QWORD *)(v2 + 968) = 0;
  }
  return result;
}
