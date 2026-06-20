__int64 __fastcall trace_raw_output_drv_tdls_recv_channel_switch(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x5

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    if ( *(_BYTE *)(v1 + 56) )
      v4 = "/p2p";
    else
      v4 = (const char *)&unk_B8EF0;
    trace_event_printf(
      a1,
      "%s vif:%s(%d%s) received tdls channel switch packet action:%d status:%d time:%d switch time:%d switch timeout:%d i"
      "nitiator: %d chan: chandef(%d.%03d MHz,width:%d,center: %d.%03d/%d MHz) sta:%pM\n",
      (const char *)(v1 + 8),
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 60)),
      *(_DWORD *)(v1 + 40),
      v4,
      *(unsigned __int8 *)(v1 + 64),
      *(_DWORD *)(v1 + 96),
      *(_DWORD *)(v1 + 104),
      *(unsigned __int16 *)(v1 + 108),
      *(unsigned __int16 *)(v1 + 110),
      *(unsigned __int8 *)(v1 + 100),
      *(_DWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 76),
      *(_DWORD *)(v1 + 80),
      *(_DWORD *)(v1 + 84),
      *(_DWORD *)(v1 + 88),
      *(_DWORD *)(v1 + 92),
      (const void *)(v1 + 65));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
