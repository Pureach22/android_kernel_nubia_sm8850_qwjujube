__int64 __fastcall sme_set_thermal_level(__int64 a1, unsigned __int8 a2)
{
  unsigned int v4; // w20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v14, 0, 48);
  if ( (unsigned int)qdf_mutex_acquire(a1 + 12776) )
  {
    v4 = 16;
  }
  else
  {
    qdf_mem_set(v14, 0x30u, 0);
    LOWORD(v14[0]) = 4314;
    HIDWORD(v14[0]) = a2;
    if ( (unsigned int)scheduler_post_message_debug(
                         0x34u,
                         0x36u,
                         54,
                         (unsigned __int16 *)v14,
                         0x23F6u,
                         (__int64)"sme_set_thermal_level") )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post WMA_SET_THERMAL_LEVEL to WMA!",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "sme_set_thermal_level");
      v4 = 16;
    }
    else
    {
      v4 = 0;
    }
    qdf_mutex_release(a1 + 12776);
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
