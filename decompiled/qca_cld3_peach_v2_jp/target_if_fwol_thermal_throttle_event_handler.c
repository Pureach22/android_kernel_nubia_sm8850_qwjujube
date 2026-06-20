__int64 __fastcall target_if_fwol_thermal_throttle_event_handler(
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
  __int64 v31; // x22
  __int64 v32; // x20
  __int64 psoc_obj; // x0
  __int64 v34; // x21
  const char *v35; // x2
  unsigned int v36; // w1
  __int64 result; // x0
  unsigned int (__fastcall *v38)(__int64, __int64 *); // x8
  __int64 (__fastcall *v39)(__int64, __int64 *); // x8
  __int64 v40; // [xsp+0h] [xbp-80h] BYREF
  int v41; // [xsp+Ch] [xbp-74h]
  __int64 v42; // [xsp+70h] [xbp-10h]
  __int64 v43; // [xsp+78h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v42) = 0;
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
    "target_if_fwol_thermal_throttle_event_handler",
    a1,
    a2,
    a3,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    v42,
    v43);
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
      "target_if_fwol_thermal_throttle_event_handler",
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
LABEL_13:
    v36 = 2;
    goto LABEL_14;
  }
  v32 = psoc_from_scn_hdl;
  psoc_obj = fwol_get_psoc_obj(psoc_from_scn_hdl);
  if ( !psoc_obj )
  {
    v35 = "%s: Failed to get FWOL Obj";
    goto LABEL_13;
  }
  v34 = psoc_obj;
  if ( (unsigned int)wmi_extract_thermal_stats(v31) )
  {
    v35 = "%s: Failed to convert thermal target level";
LABEL_9:
    v36 = 8;
LABEL_14:
    qdf_trace_msg(
      0x49u,
      v36,
      v35,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "target_if_fwol_thermal_throttle_event_handler");
    goto LABEL_15;
  }
  v38 = *(unsigned int (__fastcall **)(__int64, __int64 *))(v34 + 1416);
  if ( !v38 || !v41 )
    goto LABEL_23;
  if ( *((_DWORD *)v38 - 1) != 76461256 )
    __break(0x8228u);
  if ( v38(v32, &v40) )
LABEL_23:
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: thermal stats level response failed.",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "target_if_fwol_thermal_throttle_event_handler");
  v39 = *(__int64 (__fastcall **)(__int64, __int64 *))(v34 + 1408);
  if ( !v39 )
  {
    v35 = "%s: No notify thermal_throttle callback";
    goto LABEL_9;
  }
  if ( HIDWORD(v40) == 4 )
  {
    v35 = "%s: Failed to convert thermal target lvl";
    goto LABEL_9;
  }
  if ( *((_DWORD *)v39 - 1) != 76461256 )
    __break(0x8228u);
  result = v39(v32, &v40);
  if ( (_DWORD)result )
  {
    v35 = "%s: notify thermal_throttle failed.";
    goto LABEL_9;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
