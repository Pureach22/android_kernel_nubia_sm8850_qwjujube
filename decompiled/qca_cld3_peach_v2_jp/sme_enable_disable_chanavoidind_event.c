__int64 __fastcall sme_enable_disable_chanavoidind_event(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v10; // w8
  int v11; // w20
  __int64 result; // x0
  unsigned int v14; // w20
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1058LL);
  memset(v15, 0, 48);
  if ( (v10 & 1) != 0 )
  {
    v11 = a2;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: set_value: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_enable_disable_chanavoidind_event",
      a2);
    result = qdf_mutex_acquire(a1 + 12776);
    if ( !(_DWORD)result )
    {
      qdf_mem_set(v15, 0x30u, 0);
      LOWORD(v15[0]) = 4488;
      HIDWORD(v15[0]) = v11;
      v14 = scheduler_post_message_debug(
              0x34u,
              0x36u,
              54,
              (unsigned __int16 *)v15,
              0x355Au,
              (__int64)"sme_enable_disable_chanavoidind_event");
      qdf_mutex_release(a1 + 12776);
      result = v14;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: optimize_ca_event not enabled in ini",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_enable_disable_chanavoidind_event");
    result = 11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
