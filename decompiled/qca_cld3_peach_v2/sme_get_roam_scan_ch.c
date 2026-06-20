__int64 __fastcall sme_get_roam_scan_ch(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  unsigned int v6; // w20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v16, 0, 48);
  if ( (unsigned int)qdf_mutex_acquire(a1 + 12848) )
  {
    v6 = 16;
  }
  else
  {
    LOWORD(v16[0]) = 4542;
    HIDWORD(v16[0]) = a2;
    *(_QWORD *)(a1 + 14680) = a3;
    if ( (unsigned int)scheduler_post_message_debug(
                         0x34u,
                         0x36u,
                         54,
                         (unsigned __int16 *)v16,
                         0x6E6u,
                         (__int64)"sme_get_roam_scan_ch") )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Posting message %d failed",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "sme_get_roam_scan_ch",
        4542);
      v6 = 16;
      *(_QWORD *)(a1 + 14680) = 0;
    }
    else
    {
      v6 = 0;
    }
    qdf_mutex_release(a1 + 12848);
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
