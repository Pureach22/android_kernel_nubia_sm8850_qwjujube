__int64 __fastcall mlo_process_ml_priorityaccess_ie(
        __int64 a1,
        unsigned __int64 a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  const char *v21; // x2
  unsigned int v22; // w1
  unsigned __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int8 *v24[2]; // [xsp+10h] [xbp-10h] BYREF

  v24[1] = *(unsigned __int8 **)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24[0] = nullptr;
  if ( !a1 )
  {
    v21 = "%s: NULL ml_ie";
    goto LABEL_9;
  }
  if ( !a3 )
  {
    v21 = "%s: NULL priority_access_info";
    goto LABEL_9;
  }
  if ( (unsigned int)util_find_mlie_by_variant(a1, a2, v24, &v23, 4) || !v24[0] )
  {
    v21 = "%s: ML IE for reconfig variant not found";
    v22 = 8;
    goto LABEL_11;
  }
  qdf_trace_msg(
    0xA0u,
    8u,
    "%s: PAV ML IE with length %zu is present",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "mlo_process_ml_priorityaccess_ie",
    v23);
  result = util_get_pav_mlie_link_info(v24[0], v23, a3, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( (_DWORD)result )
  {
    v21 = "%s: Unable to get sta link info from ML PAV IE";
LABEL_9:
    v22 = 2;
LABEL_11:
    qdf_trace_msg(0x8Fu, v22, v21, a4, a5, a6, a7, a8, a9, a10, a11, "mlo_process_ml_priorityaccess_ie");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
