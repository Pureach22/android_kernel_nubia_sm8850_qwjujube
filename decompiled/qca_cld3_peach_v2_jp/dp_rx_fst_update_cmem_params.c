__int64 __fastcall dp_rx_fst_update_cmem_params(__int64 a1, unsigned __int16 a2, int a3)
{
  __int64 result; // x0
  __int64 v6; // x1
  __int64 v7; // x8

  result = dp_get_context();
  v7 = *(_QWORD *)(result + 1480);
  *(_WORD *)(v7 + 32) = a2;
  *(_DWORD *)(v7 + 40) = a2 - 1;
  *(_DWORD *)(v7 + 436) = a3;
  if ( *(_BYTE *)(result + 1496) == 1 && !*(_QWORD *)(result + 1488) )
    return qdf_event_set(v7 + 568, v6);
  return result;
}
