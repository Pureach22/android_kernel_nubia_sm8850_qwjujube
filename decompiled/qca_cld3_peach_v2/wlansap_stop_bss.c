__int64 __fastcall wlansap_stop_bss(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  __int64 v10; // [xsp+0h] [xbp-20h] BYREF
  __int64 v11; // [xsp+8h] [xbp-18h]
  __int64 v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v12 = 0;
  if ( a1 )
  {
    v10 = 0;
    LODWORD(v11) = 11;
    result = sap_fsm(a1, (__int64)&v10, a2, a3, a4, a5, a6, a7, a8, a9);
  }
  else
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid SAP pointer", a2, a3, a4, a5, a6, a7, a8, a9, "wlansap_stop_bss");
    result = 5;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
