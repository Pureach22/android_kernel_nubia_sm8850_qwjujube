__int64 __fastcall htc_control_tx_complete(__int64 a1, __int64 a2)
{
  __int64 v3; // x0

  if ( (dword_B0B4 & 8) != 0 )
    qdf_trace_msg(
      56,
      2,
      "%s: +-htc_control_tx_complete 0x%pK (l:%d)\n",
      "htc_control_tx_complete",
      (const void *)a2,
      *(_DWORD *)(a2 + 44));
  v3 = *(_QWORD *)(a2 + 96);
  if ( v3 )
    _qdf_nbuf_free(v3);
  return _qdf_mem_free(a2);
}
