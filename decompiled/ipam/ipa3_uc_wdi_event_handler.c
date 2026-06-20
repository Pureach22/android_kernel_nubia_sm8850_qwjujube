__int64 __fastcall ipa3_uc_wdi_event_handler(__int64 result)
{
  __int64 v1; // x8
  unsigned int v2; // w23
  __int64 v3; // x19
  __int64 v4; // x0
  unsigned int v5; // w21
  __int64 v6; // x0

  if ( *(_BYTE *)(result + 20) == 96 )
  {
    v1 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v2 = *(_DWORD *)(result + 24);
      v3 = result;
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      v5 = HIBYTE(v2);
      if ( v4 )
      {
        ipc_log_string(
          v4,
          "ipa %s:%d uC WDI evt errType=%u pipe=%d cherrType=%u\n",
          "ipa3_uc_wdi_event_handler",
          422,
          (unsigned __int8)v2,
          BYTE2(v2),
          v5);
        v1 = ipa3_ctx;
      }
      result = *(_QWORD *)(v1 + 34160);
      if ( result )
      {
        result = ipc_log_string(
                   result,
                   "ipa %s:%d uC WDI evt errType=%u pipe=%d cherrType=%u\n",
                   "ipa3_uc_wdi_event_handler",
                   422,
                   (unsigned __int8)v2,
                   BYTE2(v2),
                   v5);
        v1 = ipa3_ctx;
      }
      if ( v1 )
      {
        v6 = *(_QWORD *)(v1 + 34152);
        if ( v6 )
        {
          ipc_log_string(
            v6,
            "ipa %s:%d tx_ch_state=%u rx_ch_state=%u\n",
            "ipa3_uc_wdi_event_handler",
            428,
            *(unsigned __int8 *)(v3 + 72),
            *(unsigned __int8 *)(v3 + 73));
          v1 = ipa3_ctx;
        }
        result = *(_QWORD *)(v1 + 34160);
        if ( result )
          return ipc_log_string(
                   result,
                   "ipa %s:%d tx_ch_state=%u rx_ch_state=%u\n",
                   "ipa3_uc_wdi_event_handler",
                   428,
                   *(unsigned __int8 *)(v3 + 72),
                   *(unsigned __int8 *)(v3 + 73));
      }
    }
  }
  return result;
}
