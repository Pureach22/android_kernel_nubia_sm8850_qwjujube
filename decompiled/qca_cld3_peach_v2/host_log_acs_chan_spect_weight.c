__int64 __fastcall host_log_acs_chan_spect_weight(
        __int16 a1,
        __int16 a2,
        int a3,
        unsigned __int16 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  _WORD v13[2]; // [xsp+Ch] [xbp-14h] BYREF
  int v14; // [xsp+10h] [xbp-10h]
  int v15; // [xsp+14h] [xbp-Ch]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = a1;
  v13[1] = a2;
  v14 = a3;
  v15 = a4;
  result = host_diag_event_report_payload(3149, 12, v13, a5, a6, a7, a8, a9, a10, a11, a12);
  _ReadStatusReg(SP_EL0);
  return result;
}
