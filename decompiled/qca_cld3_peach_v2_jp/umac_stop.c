__int64 umac_stop()
{
  __int64 result; // x0
  __int64 v1; // x1
  __int64 v2; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v3; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v4)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v5)(); // [xsp+20h] [xbp-20h]
  __int64 v6; // [xsp+28h] [xbp-18h]
  __int64 v7; // [xsp+30h] [xbp-10h]
  __int64 v8; // [xsp+38h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v7 = 0;
  v4 = nullptr;
  v5 = nullptr;
  v2 = 0;
  v3 = nullptr;
  result = qdf_event_create(g_stop_evt);
  if ( !(_DWORD)result )
  {
    LODWORD(v2) = -87162876;
    v3 = g_stop_evt;
    v4 = umac_stop_complete_cb;
    v5 = umac_stop_flush_cb;
    scheduler_post_message_debug(0x37u, 0x37u, 55, (unsigned __int16 *)&v2, 0x6Eu, (__int64)"umac_stop");
    qdf_wait_single_event((__int64)g_stop_evt, 0x7530u);
    result = qdf_event_destroy((__int64)g_stop_evt, v1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
