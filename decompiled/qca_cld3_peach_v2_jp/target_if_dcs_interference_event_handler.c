__int64 __fastcall target_if_dcs_interference_event_handler(
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
  __int64 psoc_from_scn_hdl; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x22
  __int64 v21; // x8
  __int64 v22; // x21
  __int64 v23; // x20
  const char *v24; // x2
  __int64 result; // x0
  int v26; // w8
  __int64 (__fastcall *v27)(__int64, __int64 *); // x8
  unsigned int v28; // w0
  __int64 v29; // [xsp+0h] [xbp-70h] BYREF
  __int64 v30; // [xsp+8h] [xbp-68h]
  __int64 v31; // [xsp+10h] [xbp-60h]
  __int64 v32; // [xsp+18h] [xbp-58h]
  __int64 v33; // [xsp+20h] [xbp-50h]
  __int64 v34; // [xsp+28h] [xbp-48h]
  __int64 v35; // [xsp+30h] [xbp-40h]
  __int64 v36; // [xsp+38h] [xbp-38h]
  __int64 v37; // [xsp+40h] [xbp-30h] BYREF
  __int64 v38; // [xsp+48h] [xbp-28h]
  __int64 v39; // [xsp+50h] [xbp-20h] BYREF
  __int64 v40; // [xsp+58h] [xbp-18h]
  __int64 v41; // [xsp+60h] [xbp-10h]
  __int64 v42; // [xsp+68h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v41) = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: scn: 0x%pK, data: 0x%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_dcs_interference_event_handler",
      a1,
      a2,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42);
LABEL_16:
    result = 4294967274LL;
    goto LABEL_17;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v24 = "%s: null psoc";
    goto LABEL_15;
  }
  v20 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v20 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: rx_ops is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_dcs_get_rx_ops",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42);
    goto LABEL_13;
  }
  if ( !*(_QWORD *)(v20 + 208) )
  {
LABEL_13:
    v24 = "%s: callback not registered";
    goto LABEL_15;
  }
  v21 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v21 || (v22 = *(_QWORD *)(v21 + 16)) == 0 )
  {
    v24 = "%s: wmi_handle is null";
    goto LABEL_15;
  }
  v23 = psoc_from_scn_hdl;
  if ( (unsigned int)wmi_extract_dcs_interference_type(v22, a2, (char *)&v37 + 4) )
  {
    v24 = "%s: Unable to extract dcs interference type";
LABEL_15:
    qdf_trace_msg(
      0x49u,
      2u,
      v24,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_dcs_interference_event_handler",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37);
    goto LABEL_16;
  }
  v26 = HIDWORD(v37);
  if ( HIDWORD(v37) == 2 )
  {
    if ( (unsigned int)wmi_extract_dcs_im_tgt_stats(v22, a2, &v29) )
    {
      v24 = "%s: Unable to extract WLAN IM stats";
      goto LABEL_15;
    }
    v26 = HIDWORD(v37);
  }
  if ( v26 == 4 && (unsigned int)wmi_extract_dcs_awgn_info(v22, a2, &v39) )
  {
    v24 = "%s: Unable to extract AWGN info";
    goto LABEL_15;
  }
  v27 = *(__int64 (__fastcall **)(__int64, __int64 *))(v20 + 208);
  if ( *((_DWORD *)v27 - 1) != 78868077 )
    __break(0x8228u);
  v28 = v27(v23, &v29);
  result = qdf_status_to_os_return(v28);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
