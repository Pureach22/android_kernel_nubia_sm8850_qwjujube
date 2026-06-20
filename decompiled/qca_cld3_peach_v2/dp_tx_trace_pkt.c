__int64 __fastcall dp_tx_trace_pkt(__int64 a1, __int64 a2, unsigned __int16 a3, unsigned int a4, unsigned int a5)
{
  __int64 result; // x0
  char v10; // w9

  if ( !*(_DWORD *)(a1 + 20124) || (result = hif_rtpm_get_state(), (int)result >= 2) )
  {
    v10 = *(_BYTE *)(a2 + 71) | 1;
    *(_WORD *)(a2 + 69) = *(_WORD *)(a2 + 69) & 0xF8FF | 0x100;
    *(_BYTE *)(a2 + 71) = v10;
    qdf_dp_trace_ptr(a2, 0x19u, 0xFFu, (const void *)(a2 + 224), 8u, a3, (unsigned __int8)a4, 0, a5);
    qdf_dp_trace_log_pkt(a4, a2, 0, 0xFFu, a5);
    return qdf_dp_trace_data_pkt(a2, 0xFFu, 0x12u, a3, 0);
  }
  return result;
}
