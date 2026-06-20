__int64 __fastcall reg_set_ap_pwr_type(
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
  __int64 v9; // x19
  int v10; // w5
  __int64 v11; // x4

  v9 = a1 + 56728;
  if ( *(_BYTE *)(a1 + 56760) == 1 && *(_BYTE *)(a1 + 57610) )
  {
    v10 = 0;
  }
  else if ( (reg_does_country_supp_c2c(*(_QWORD *)v9) & 1) != 0
         && (reg_is_indoor_ap_detected(*(_QWORD *)v9) & 1) != 0
         && *(_BYTE *)(v9 + 885) )
  {
    v10 = 3;
  }
  else if ( *(_BYTE *)(v9 + 884) )
  {
    v10 = 2;
  }
  else
  {
    v10 = 4;
  }
  v11 = *(unsigned __int8 *)(v9 + 32);
  *(_DWORD *)(v9 + 1476) = v10;
  return qdf_trace_msg(
           0x51u,
           8u,
           "%s: indoor_chan_enabled %d ap_pwr_type %d",
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           "reg_set_ap_pwr_type",
           v11);
}
