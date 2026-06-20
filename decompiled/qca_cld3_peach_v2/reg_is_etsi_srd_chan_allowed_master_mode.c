__int64 __fastcall reg_is_etsi_srd_chan_allowed_master_mode(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 psoc_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x21
  char v20; // w19
  const char *v21; // x2
  __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  __int16 v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v21 = "%s: pdev is NULL";
LABEL_9:
    v20 = 1;
    qdf_trace_msg(0x51u, 1u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "reg_is_etsi_srd_chan_allowed_master_mode");
    goto LABEL_10;
  }
  psoc_obj = reg_get_psoc_obj(*(_QWORD *)(a1 + 80), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !psoc_obj )
  {
    v21 = "%s: psoc reg component is NULL";
    goto LABEL_9;
  }
  if ( *(_BYTE *)(psoc_obj + 93233) )
  {
    v24 = 0;
    v23 = 0;
    if ( !(unsigned int)reg_get_curr_regdomain(a1, (unsigned __int16 *)&v23, a2, a3, a4, a5, a6, a7, a8, a9) )
    {
      v20 = reg_etsi_regdmn(BYTE4(v23));
      goto LABEL_10;
    }
    v19 = jiffies;
    if ( reg_is_etsi_regdmn___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: Failed to get reg domain",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "reg_is_etsi_regdmn");
      v20 = 0;
      reg_is_etsi_regdmn___last_ticks = v19;
      goto LABEL_10;
    }
  }
  v20 = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v20 & 1;
}
