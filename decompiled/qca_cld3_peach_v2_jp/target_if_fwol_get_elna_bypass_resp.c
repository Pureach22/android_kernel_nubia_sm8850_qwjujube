__int64 __fastcall target_if_fwol_get_elna_bypass_resp(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 psoc_from_scn_hdl; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  __int64 v31; // x21
  __int64 v32; // x20
  __int64 psoc_obj; // x0
  __int64 v34; // x22
  const char *v35; // x2
  unsigned int v36; // w1
  __int64 result; // x0
  __int64 (__fastcall *v38)(__int64, __int64 *); // x8
  __int64 v39; // [xsp+0h] [xbp-10h] BYREF

  qdf_trace_msg(
    0x49u,
    8u,
    "%s: scn:%pK, data:%pK, datalen:%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "target_if_fwol_get_elna_bypass_resp",
    a1,
    a2,
    a3,
    0,
    *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808));
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: scn: 0x%pK, data: 0x%pK",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_fwol_get_elna_bypass_resp",
      a1,
      a2);
LABEL_15:
    result = 4294967274LL;
    goto LABEL_16;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v35 = "%s: null psoc";
    goto LABEL_13;
  }
  v30 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v30 || (v31 = *(_QWORD *)(v30 + 16)) == 0 )
  {
    v35 = "%s: Invalid wmi_handle";
    goto LABEL_13;
  }
  v32 = psoc_from_scn_hdl;
  psoc_obj = fwol_get_psoc_obj(psoc_from_scn_hdl);
  if ( !psoc_obj )
  {
    v35 = "%s: Failed to get FWOL Obj";
    goto LABEL_13;
  }
  if ( !*(_QWORD *)(psoc_obj + 1400) )
  {
    v35 = "%s: No get_elna_bypass_resp callback";
    v36 = 1;
    goto LABEL_14;
  }
  v34 = psoc_obj;
  if ( (unsigned int)wmi_extract_get_elna_bypass_resp(v31, a2, &v39) )
  {
    v35 = "%s: Failed to extract eLNA bypass";
LABEL_13:
    v36 = 2;
LABEL_14:
    qdf_trace_msg(0x49u, v36, v35, v22, v23, v24, v25, v26, v27, v28, v29, "target_if_fwol_get_elna_bypass_resp");
    goto LABEL_15;
  }
  v38 = *(__int64 (__fastcall **)(__int64, __int64 *))(v34 + 1400);
  if ( *((_DWORD *)v38 - 1) != -1200120311 )
    __break(0x8228u);
  result = v38(v32, &v39);
  if ( (_DWORD)result )
  {
    v35 = "%s: get_elna_bypass_resp failed.";
    goto LABEL_13;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
