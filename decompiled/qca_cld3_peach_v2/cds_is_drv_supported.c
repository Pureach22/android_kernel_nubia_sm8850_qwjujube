__int64 __fastcall cds_is_drv_supported(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x8
  __int64 result; // x0
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  if ( !gp_cds_context )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "__cds_get_context",
      "cds_is_drv_supported");
LABEL_6:
    result = 0;
    goto LABEL_7;
  }
  v8 = *(_QWORD *)(gp_cds_context + 56);
  if ( !v8 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %d context is Null (via %s)",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "__cds_get_context",
      64,
      "cds_is_drv_supported");
    goto LABEL_6;
  }
  pld_get_platform_cap(*(_QWORD *)(v8 + 40), &v10);
  result = ((unsigned __int8)v10 >> 2) & 1;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
