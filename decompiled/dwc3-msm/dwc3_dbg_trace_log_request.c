__int64 __fastcall dwc3_dbg_trace_log_request(__int64 result, __int64 a2, const char *a3)
{
  int v3; // w9
  const char *v4; // x7
  const char *v5; // x10
  const char *v6; // x11

  if ( a2 )
  {
    v3 = *(_DWORD *)(a2 + 40);
    if ( (v3 & 0x40000) != 0 )
      v4 = "Z";
    else
      v4 = "z";
    v5 = (const char *)&unk_16C6B;
    v6 = "i";
    if ( (v3 & 0x80000) != 0 )
      v5 = "S";
    if ( (v3 & 0x20000) == 0 )
      v6 = "I";
    return ipc_log_string(
             result,
             "%s: %s: req %p length %u/%u %s%s%s ==> %d",
             a3,
             (const char *)(*(_QWORD *)(a2 + 120) + 184LL),
             (const void *)a2,
             *(_DWORD *)(a2 + 88),
             *(_DWORD *)(a2 + 8),
             v4,
             v5,
             v6,
             *(_DWORD *)(a2 + 84));
  }
  return result;
}
