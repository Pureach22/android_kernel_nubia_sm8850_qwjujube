__int64 __fastcall spectral_phyerr_event_handler(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  __int64 v19; // [xsp+0h] [xbp-80h]
  __int64 v20; // [xsp+8h] [xbp-78h]
  __int64 v21; // [xsp+10h] [xbp-70h]
  __int64 v22; // [xsp+18h] [xbp-68h]
  __int64 v23; // [xsp+20h] [xbp-60h]
  __int64 v24; // [xsp+28h] [xbp-58h]
  __int64 v25; // [xsp+30h] [xbp-50h]
  __int64 v26; // [xsp+38h] [xbp-48h]
  __int64 v27; // [xsp+40h] [xbp-40h]
  __int64 v28; // [xsp+48h] [xbp-38h]
  __int64 v29; // [xsp+50h] [xbp-30h]
  __int64 v30; // [xsp+58h] [xbp-28h]
  __int64 v31; // [xsp+60h] [xbp-20h]
  __int64 v32; // [xsp+68h] [xbp-18h]
  __int64 v33; // [xsp+70h] [xbp-10h]
  __int64 v34; // [xsp+78h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v20) = 0;
  LOWORD(v24) = 0;
  v22 = 0;
  v23 = 0;
  v21 = 0;
  LOWORD(v20) = 0;
  v19 = 0;
  if ( a1 )
  {
    v9 = *a1;
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    v25 = 0;
    if ( (unsigned int)wmi_extract_comb_phyerr(v9) )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: extract comb phyerr failed",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "spectral_phyerr_event_handler",
        v19,
        v20);
      result = 16;
    }
    else
    {
      WORD2(v20) = 0;
      result = 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "__wma_validate_handle",
      "spectral_phyerr_event_handler",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
