__int64 __fastcall dispatcher_dbr_psoc_disable(__int64 result)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  if ( !result )
    return qdf_trace_msg(56, 2, "%s: tx_ops is NULL", "dispatcher_dbr_psoc_disable");
  v1 = *(_QWORD *)(result + 2128);
  if ( !v1 )
    return qdf_trace_msg(56, 2, "%s: tx_ops is NULL", "dispatcher_dbr_psoc_disable");
  v2 = *(__int64 (**)(void))(v1 + 1784);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != -770124015 )
      __break(0x8228u);
    return v2();
  }
  return result;
}
