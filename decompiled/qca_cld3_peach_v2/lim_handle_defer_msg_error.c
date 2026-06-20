__int64 __fastcall lim_handle_defer_msg_error(__int64 a1, __int64 a2)
{
  int v4; // w8
  _QWORD *v5; // x19
  __int64 v6; // t1
  __int64 result; // x0

  if ( *(_WORD *)a2 == 5044 )
  {
    raw_spin_lock(a1 + 12816);
    v4 = *(_DWORD *)(a1 + 12796);
    if ( v4 )
      *(_DWORD *)(a1 + 12796) = v4 - 1;
    raw_spin_unlock(a1 + 12816);
    v6 = *(_QWORD *)(a2 + 8);
    v5 = (_QWORD *)(a2 + 8);
    result = cds_pkt_return_packet(v6);
  }
  else
  {
    v5 = (_QWORD *)(a2 + 8);
    result = *(_QWORD *)(a2 + 8);
    if ( !result )
      return result;
    result = _qdf_mem_free(result);
  }
  *v5 = 0;
  return result;
}
