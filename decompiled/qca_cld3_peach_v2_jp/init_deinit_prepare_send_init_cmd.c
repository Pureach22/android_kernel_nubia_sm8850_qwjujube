__int64 __fastcall init_deinit_prepare_send_init_cmd(
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
  int v10; // w9
  __int64 v11; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  __int64 result; // x0
  int v24; // w8
  __int64 v25; // x8
  __int64 (__fastcall *v26)(__int64, __int64); // x9
  __int64 (__fastcall *v27)(__int64, __int64); // x8
  unsigned int v28; // w8
  char v29; // w10
  __int64 v30; // x4
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  char v47; // w8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x0
  __int64 v57; // x8
  void (*v58)(void); // x8
  _DWORD **v59; // x8
  _DWORD *v60; // x8
  __int64 v61; // [xsp+20h] [xbp-50h] BYREF
  __int64 v62; // [xsp+28h] [xbp-48h]
  __int64 v63; // [xsp+30h] [xbp-40h]
  __int64 v64; // [xsp+38h] [xbp-38h]
  __int64 v65; // [xsp+40h] [xbp-30h]
  __int64 v66; // [xsp+48h] [xbp-28h]
  __int64 v67; // [xsp+50h] [xbp-20h]
  __int64 v68; // [xsp+58h] [xbp-18h]
  __int64 v69; // [xsp+60h] [xbp-10h]
  __int64 v70; // [xsp+68h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  if ( !a2 )
  {
    v22 = "%s: target_psoc_info is null";
    goto LABEL_6;
  }
  v10 = *(_DWORD *)(a2 + 3328);
  v11 = *(_QWORD *)(a2 + 16);
  v61 = a2 + 64;
  LOBYTE(v62) = v10;
  v63 = a2 + 3336;
  if ( (unsigned int)((__int64 (*)(void))init_deinit_is_service_ext_msg)() )
  {
    if ( (unsigned int)tgt_if_regulatory_modify_freq_range(a1) )
    {
      v22 = "%s: Modify freq range is failed";
LABEL_6:
      result = qdf_trace_msg(0x49u, 2u, v22, a3, a4, a5, a6, a7, a8, a9, a10, "init_deinit_prepare_send_init_cmd");
      goto LABEL_7;
    }
  }
  else
  {
    v24 = *(_DWORD *)(a2 + 504);
    if ( !v24 )
      v24 = 11;
    LODWORD(v64) = v24;
    init_deinit_derive_band_to_mac_param(v14, v15, v16, v17, v18, v19, v20, v21, a1, a2, (__int64)&v61);
  }
  v25 = *(_QWORD *)(a2 + 4512);
  if ( !v25 )
    goto LABEL_21;
  v26 = *(__int64 (__fastcall **)(__int64, __int64))(v25 + 64);
  if ( v26 )
  {
    if ( *((_DWORD *)v26 - 1) != -2039706441 )
      __break(0x8229u);
    result = v26(a1, a2);
    if ( (_DWORD)result )
      goto LABEL_7;
    v25 = *(_QWORD *)(a2 + 4512);
    if ( !v25 )
    {
LABEL_21:
      v28 = *(_DWORD *)(a2 + 376);
      v29 = *(_BYTE *)(a2 + 994);
      if ( v28 >= *(_DWORD *)(a2 + 972) )
        v28 = *(_DWORD *)(a2 + 972);
      *(_DWORD *)(a2 + 376) = v28;
      if ( (v29 & 1) != 0 )
      {
        *(_BYTE *)(a2 + 398) = 1;
        target_if_twt_set_twt_ack_support(a1, 1);
      }
      target_if_twt_set_wake_dur_and_wake_intvl(
        a1,
        *(unsigned __int16 *)(a2 + 1060),
        *(unsigned __int16 *)(a2 + 1062),
        *(unsigned __int16 *)(a2 + 1064),
        *(unsigned __int16 *)(a2 + 1066));
      v30 = *(unsigned int *)(a2 + 748);
      *(_DWORD *)(a2 + 404) = *(_DWORD *)(a2 + 996);
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: FW version 0x%x ",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "init_deinit_prepare_send_init_cmd",
        v30);
      if ( (unsigned int)init_deinit_is_service_ext_msg(a1, a2) )
        qdf_trace_msg(
          0x49u,
          8u,
          "%s: 0x%x\n",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "init_deinit_prepare_send_init_cmd",
          *(unsigned int *)(a2 + 752));
      else
        qdf_trace_msg(
          0x49u,
          8u,
          "%s: fw_build_vers_ext:0x%x HDL version info:0x%0x, CRM sub ID:0x%x\n",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "init_deinit_prepare_send_init_cmd",
          *(unsigned int *)(a2 + 820),
          *(_DWORD *)(a2 + 820) & 0x3FF,
          *(_DWORD *)(a2 + 820) >> 25);
      wmi_service_enabled(v11, 190);
      if ( (wmi_service_enabled(v11, 286) & 1) != 0 )
        v47 = 2;
      else
        v47 = *(_BYTE *)(a2 + 1000);
      *(_BYTE *)(a2 + 433) = v47;
      if ( (wmi_service_enabled(v11, 157) & 1) == 0 )
        *(_DWORD *)(a2 + 448) = 0;
      if ( a1 && (v56 = *(_QWORD *)(a1 + 2808)) != 0 && *(_QWORD *)v56 )
      {
        v57 = *(_QWORD *)(*(_QWORD *)v56 + 8LL);
        if ( v57 )
        {
          v58 = *(void (**)(void))(v57 + 184);
          if ( v58 )
          {
            if ( *((_DWORD *)v58 - 1) != -503247959 )
              __break(0x8228u);
            v58();
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x89u,
          8u,
          "%s: Invalid Instance:",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "cdp_txrx_set_psoc_param");
      }
      v59 = *(_DWORD ***)(a2 + 4512);
      if ( v59 )
      {
        v60 = *v59;
        if ( v60 )
        {
          if ( *(v60 - 1) != 1314010449 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v60)(a1, a2, 0);
        }
      }
      *(_BYTE *)(a2 + 421) = 0;
      wmi_unified_init_cmd_send(v11, &v61);
      target_if_scan_set_max_active_scans(a1, 8);
      result = wmi_service_enabled(v11, 172);
      if ( (result & 1) != 0 )
        *(_DWORD *)(a1 + 20) |= 0x8000u;
      goto LABEL_7;
    }
  }
  v27 = *(__int64 (__fastcall **)(__int64, __int64))(v25 + 72);
  if ( !v27 )
    goto LABEL_21;
  if ( *((_DWORD *)v27 - 1) != -2039706441 )
    __break(0x8228u);
  result = v27(a1, a2);
  if ( !(_DWORD)result )
    goto LABEL_21;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
