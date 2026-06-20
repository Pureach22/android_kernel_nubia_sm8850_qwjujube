__int64 __fastcall dwc3_dbg_trace_ep_cmd(__int64 a1, __int64 a2, int a3, _DWORD *a4, int a5)
{
  const char *v6; // x3
  const char *v7; // x10

  if ( (unsigned __int8)(a3 - 1) > 8u )
    v6 = "UNKNOWN command";
  else
    v6 = off_156C0[(unsigned __int8)(a3 - 1)];
  if ( a5 > 0 )
  {
    if ( a5 == 1 )
    {
      v7 = "No Resource";
      return ipc_log_string(
               a1,
               "dbg_send_ep_cmd: %s: cmd '%s' [%x] params %08x %08x %08x --> status: %s",
               (const char *)(a2 + 184),
               v6,
               a3,
               a4[2],
               a4[1],
               *a4,
               v7);
    }
    if ( a5 == 2 )
    {
      v7 = "Bus Expiry";
      return ipc_log_string(
               a1,
               "dbg_send_ep_cmd: %s: cmd '%s' [%x] params %08x %08x %08x --> status: %s",
               (const char *)(a2 + 184),
               v6,
               a3,
               a4[2],
               a4[1],
               *a4,
               v7);
    }
LABEL_11:
    v7 = "UNKNOWN";
    return ipc_log_string(
             a1,
             "dbg_send_ep_cmd: %s: cmd '%s' [%x] params %08x %08x %08x --> status: %s",
             (const char *)(a2 + 184),
             v6,
             a3,
             a4[2],
             a4[1],
             *a4,
             v7);
  }
  if ( a5 == -110 )
  {
    v7 = "Timed Out";
    return ipc_log_string(
             a1,
             "dbg_send_ep_cmd: %s: cmd '%s' [%x] params %08x %08x %08x --> status: %s",
             (const char *)(a2 + 184),
             v6,
             a3,
             a4[2],
             a4[1],
             *a4,
             v7);
  }
  if ( a5 )
    goto LABEL_11;
  v7 = "Successful";
  return ipc_log_string(
           a1,
           "dbg_send_ep_cmd: %s: cmd '%s' [%x] params %08x %08x %08x --> status: %s",
           (const char *)(a2 + 184),
           v6,
           a3,
           a4[2],
           a4[1],
           *a4,
           v7);
}
