__int64 __fastcall remote_etm_remove(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w20

  v1 = *(_QWORD *)(a1 + 168);
  if ( (*(_BYTE *)(v1 + 84) & 1) == 0 && *(_DWORD *)(v1 + 80) )
  {
    v2 = 0;
    do
      coresight_trace_id_put_system_id(*(unsigned __int8 *)(*(_QWORD *)(v1 + 72) + (int)v2++));
    while ( v2 < *(_DWORD *)(v1 + 80) );
  }
  return coresight_unregister(*(_QWORD *)(v1 + 8));
}
