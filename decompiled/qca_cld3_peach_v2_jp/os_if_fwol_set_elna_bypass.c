__int64 __fastcall os_if_fwol_set_elna_bypass(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w4
  __int64 result; // x0
  unsigned int v12; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // [xsp+0h] [xbp-10h] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 *)(a2 + 4);
  LODWORD(v21) = *(unsigned __int8 *)(a1 + 104);
  HIDWORD(v21) = v10;
  if ( v10 < 3 )
  {
    v12 = ucfg_fwol_set_elna_bypass(a1, (__int64)&v21, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( v12 )
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Failed to set ELNA BYPASS, %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "os_if_fwol_set_elna_bypass",
        v12,
        v21,
        v22);
    result = qdf_status_to_os_return(v12);
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Invalid elna_bypass value %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "os_if_fwol_set_elna_bypass",
      v21,
      v22);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
