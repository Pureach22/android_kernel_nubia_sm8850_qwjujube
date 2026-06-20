__int64 __fastcall tdls_scan_complete_event_handler(__int64 result, __int64 a2, __int64 a3)
{
  _QWORD v3[7]; // [xsp+8h] [xbp-38h] BYREF

  v3[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result && a2 && a3 && *(_DWORD *)(a2 + 4) == 1 )
  {
    v3[1] = a3;
    v3[2] = tdls_process_cmd;
    v3[3] = tdls_post_msg_flush_cb;
    v3[4] = 0;
    v3[5] = 0;
    v3[0] = 10;
    result = scheduler_post_message_debug(0, 0, 72, (unsigned __int16 *)v3, 0x8ECu, (__int64)"tdls_post_scan_done_msg");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
