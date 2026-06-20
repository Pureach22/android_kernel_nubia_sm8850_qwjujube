__int64 __fastcall reg_is_etsi_srd_chan_for_freq(
        __int64 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v10; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  __int64 v22; // [xsp+8h] [xbp-18h] BYREF
  __int16 v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(channel_map + 168) > (unsigned int)a2 )
  {
LABEL_2:
    v10 = 0;
    goto LABEL_3;
  }
  v10 = 0;
  if ( (unsigned int)a2 - 5745 <= 0x78 && *(_DWORD *)(channel_map + 492) >= (unsigned int)a2 )
  {
    v23 = 0;
    v22 = 0;
    if ( !(unsigned int)reg_get_curr_regdomain(a1, (unsigned __int16 *)&v22, a3, a4, a5, a6, a7, a8, a9, a10) )
    {
      v10 = reg_etsi_regdmn(BYTE4(v22));
      goto LABEL_3;
    }
    v21 = jiffies;
    if ( reg_is_etsi_regdmn___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: Failed to get reg domain",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "reg_is_etsi_regdmn");
      v10 = 0;
      reg_is_etsi_regdmn___last_ticks = v21;
      goto LABEL_3;
    }
    goto LABEL_2;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return v10 & 1;
}
