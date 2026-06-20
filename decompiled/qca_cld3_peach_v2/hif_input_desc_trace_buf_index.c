__int64 __fastcall hif_input_desc_trace_buf_index(__int64 a1, char *s, __int64 a3)
{
  __int64 v3; // x19
  _DWORD *v4; // x21
  _DWORD *v5; // x20

  if ( !a1 )
    return -22;
  v3 = a3;
  if ( !a3 )
  {
    qdf_trace_msg(56, 2, "%s: Invalid input buffer.", "hif_input_desc_trace_buf_index");
    return -22;
  }
  v4 = (_DWORD *)(a1 + 3612);
  v5 = (_DWORD *)(a1 + 3608);
  if ( sscanf(s, "%u %u", a1 + 3612, a1 + 3608) != 2 )
  {
    qdf_trace_msg(56, 2, "%s: Invalid input value.", "hif_input_desc_trace_buf_index");
    return -22;
  }
  if ( *v4 > 0xBu || *v5 >= 0x300u )
  {
    qdf_trace_msg(56, 2, "%s: Invalid values", "hif_input_desc_trace_buf_index");
    return -22;
  }
  return v3;
}
