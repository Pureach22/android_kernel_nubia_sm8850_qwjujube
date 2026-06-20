__int64 __fastcall wma_process_update_edca_param_req(
        __int64 *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  unsigned int v13; // w22
  _QWORD *v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x23
  int v41; // w25
  int v42; // w26
  int v43; // w27
  int v44; // w28
  int v45; // w24
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 result; // x0
  __int64 v55; // x8
  _DWORD *v56; // x8
  int v57; // [xsp+0h] [xbp-C0h]
  int v58; // [xsp+4h] [xbp-BCh]
  int v59; // [xsp+8h] [xbp-B8h]
  int v60; // [xsp+Ch] [xbp-B4h]
  int v61; // [xsp+10h] [xbp-B0h]
  int v62; // [xsp+14h] [xbp-ACh]
  int v63; // [xsp+18h] [xbp-A8h]
  int v64; // [xsp+1Ch] [xbp-A4h] BYREF
  __int64 v65; // [xsp+20h] [xbp-A0h] BYREF
  __int64 v66; // [xsp+28h] [xbp-98h]
  __int64 v67; // [xsp+30h] [xbp-90h]
  __int64 v68; // [xsp+38h] [xbp-88h] BYREF
  __int64 v69; // [xsp+40h] [xbp-80h]
  __int64 v70; // [xsp+48h] [xbp-78h]
  __int64 v71; // [xsp+50h] [xbp-70h] BYREF
  __int64 v72; // [xsp+58h] [xbp-68h]
  __int64 v73; // [xsp+60h] [xbp-60h]
  __int64 v74; // [xsp+68h] [xbp-58h] BYREF
  __int64 v75; // [xsp+70h] [xbp-50h]
  __int64 v76; // [xsp+78h] [xbp-48h]
  _DWORD v77[12]; // [xsp+80h] [xbp-40h] BYREF
  __int64 v78; // [xsp+B0h] [xbp-10h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  context = _cds_get_context(71, (__int64)"wma_process_update_edca_param_req", a3, a4, a5, a6, a7, a8, a9, a10);
  v13 = *a2;
  v14 = context;
  v64 = 0;
  if ( (wma_is_vdev_valid(v13, v15, v16, v17, v18, v19, v20, v21, v22) & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev id:%d is not active ",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wma_process_update_edca_param_req",
      v13);
    goto LABEL_13;
  }
  v31 = _qdf_mem_malloc(0x200u, "wma_process_update_edca_param_req", 2326);
  if ( !v31 )
    goto LABEL_13;
  v40 = v31;
  wma_update_edca_params_for_ac(a2 + 2, &v65, 0, a2[22], v31, 512, &v64);
  v62 = v66;
  v63 = HIDWORD(v65);
  v61 = HIDWORD(v66);
  wma_update_edca_params_for_ac(a2 + 7, &v68, 1, a2[22], v40, 512, &v64);
  v59 = v69;
  v60 = HIDWORD(v68);
  v58 = HIDWORD(v69);
  wma_update_edca_params_for_ac(a2 + 12, &v71, 2, a2[22], v40, 512, &v64);
  v41 = HIDWORD(v71);
  v42 = v72;
  v57 = HIDWORD(v72);
  wma_update_edca_params_for_ac(a2 + 17, &v74, 3, a2[22], v40, 512, &v64);
  v43 = HIDWORD(v74);
  v44 = v75;
  v45 = HIDWORD(v75);
  qdf_trace_msg(0x36u, 8u, "Vdev_id: %d WMM params: %s", v46, v47, v48, v49, v50, v51, v52, v53, v13, v40);
  _qdf_mem_free(v40);
  result = wmi_unified_process_update_edca_param(*a1);
  if ( (_DWORD)result == 2 )
    goto LABEL_14;
  if ( (_DWORD)result == 16 )
  {
LABEL_13:
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to set WMM Parameters",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "wma_process_update_edca_param_req");
    result = 16;
    goto LABEL_14;
  }
  if ( v14 && *v14 && (v55 = *(_QWORD *)(*v14 + 64LL)) != 0 )
  {
    v56 = *(_DWORD **)(v55 + 8);
    if ( v56 )
    {
      v77[6] = v41;
      v77[7] = v42;
      v77[0] = v63;
      v77[1] = v62;
      v77[10] = v44;
      v77[11] = v45;
      v77[2] = v61;
      v77[3] = v60;
      v77[4] = v59;
      v77[5] = v58;
      v77[8] = v57;
      v77[9] = v43;
      if ( *(v56 - 1) != 143699575 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, _QWORD, _DWORD *))v56)(v14, 0, v77);
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v32, v33, v34, v35, v36, v37, v38, v39, "cdp_set_wmm_param");
  }
  result = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
