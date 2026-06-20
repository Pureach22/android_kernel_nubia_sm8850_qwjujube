__int64 __fastcall lim_send_stop_bss_failure_resp(__int64 a1, __int64 a2)
{
  int v2; // w3
  __int16 v3; // w2

  v2 = *(_DWORD *)(a2 + 84);
  v3 = *(_WORD *)(a2 + 8);
  *(_DWORD *)(a2 + 80) = v2;
  qdf_trace(53, 1u, v3, v2);
  return lim_send_stop_bss_response(a1, *(unsigned __int8 *)(a2 + 10), 533);
}
