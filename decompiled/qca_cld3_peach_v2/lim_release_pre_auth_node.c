__int64 __fastcall lim_release_pre_auth_node(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int64 v5; // x21
  __int64 result; // x0

  v2 = *(_DWORD *)(a2 + 16);
  *(_BYTE *)(a2 + 278) |= 4u;
  if ( v2 == 3 && *(_BYTE *)(a2 + 560) == 1 )
  {
    v5 = *(_QWORD *)(a2 + 568);
    lim_free_assoc_req_frm_buf(v5);
    _qdf_mem_free(v5);
    *(_QWORD *)(a2 + 568) = 0;
    *(_BYTE *)(a2 + 560) = 0;
  }
  qdf_trace(53, 0xEu, 255, 7);
  result = tx_timer_deactivate(a2 + 280);
  --*(_DWORD *)(a1 + 11404);
  return result;
}
