__int64 __fastcall wlan_mlme_get_mcc_duty_cycle_percentage(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 psoc_ext_obj_fl; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x4
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  const char *v24; // x2
  unsigned int v25; // w24
  unsigned int v26; // w25
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w8
  const char *v36; // x2
  unsigned int v37; // w20
  unsigned int v38; // w19
  unsigned int v39; // w21
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w22
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v65; // w21
  unsigned int v66; // w19
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 result; // x0
  const char *v76; // x2
  int v77; // [xsp+8h] [xbp-28h] BYREF
  char v78; // [xsp+Ch] [xbp-24h]
  _QWORD v79[2]; // [xsp+10h] [xbp-20h] BYREF
  int v80; // [xsp+20h] [xbp-10h]
  __int64 v81; // [xsp+28h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 80);
  if ( !v1 )
    goto LABEL_33;
  v3 = *(_QWORD *)(a1 + 80);
  v80 = 0;
  v79[0] = 0;
  v79[1] = 0;
  v77 = 0;
  v78 = 0;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v3);
  if ( !psoc_ext_obj_fl )
    goto LABEL_33;
  v13 = *(unsigned __int8 *)(psoc_ext_obj_fl + 1104);
  if ( *(unsigned __int8 *)(psoc_ext_obj_fl + 1105) == 255 || (_DWORD)v13 == 1 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Invalid primary vdev id or policy is unbaised :%d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_mlme_get_mcc_duty_cycle_percentage",
      v13);
LABEL_33:
    result = 4294967274LL;
    goto LABEL_34;
  }
  v14 = psoc_ext_obj_fl;
  if ( (unsigned int)policy_mgr_get_mode_specific_conn_info(v1, (unsigned __int64)v79, (unsigned __int64)&v77, 0) != 2 )
  {
    v76 = "%s: STA+STA concurrency is not present";
LABEL_32:
    qdf_trace_msg(0x68u, 8u, v76, v15, v16, v17, v18, v19, v20, v21, v22, "wlan_mlme_get_mcc_duty_cycle_percentage");
    goto LABEL_33;
  }
  v23 = *(unsigned __int8 *)(v14 + 1105);
  if ( (unsigned __int8)v77 == v23 )
    v24 = "%s: primary sta vdev:%d at index:%d, freq:%d";
  else
    v24 = "%s: secondary sta vdev:%d at index:%d, freq:%d";
  if ( (unsigned __int8)v77 == v23 )
    v25 = v79[0];
  else
    v25 = 0;
  if ( (unsigned __int8)v77 == v23 )
    v26 = 0;
  else
    v26 = v79[0];
  qdf_trace_msg(0x68u, 8u, v24, v15, v16, v17, v18, v19, v20, v21, v22, "wlan_mlme_get_mcc_duty_cycle_percentage");
  v35 = *(unsigned __int8 *)(v14 + 1105);
  if ( BYTE1(v77) == v35 )
    v36 = "%s: primary sta vdev:%d at index:%d, freq:%d";
  else
    v36 = "%s: secondary sta vdev:%d at index:%d, freq:%d";
  if ( BYTE1(v77) == v35 )
    v37 = HIDWORD(v79[0]);
  else
    v37 = v25;
  if ( BYTE1(v77) == v35 )
    v38 = v26;
  else
    v38 = HIDWORD(v79[0]);
  qdf_trace_msg(0x68u, 8u, v36, v27, v28, v29, v30, v31, v32, v33, v34, "wlan_mlme_get_mcc_duty_cycle_percentage");
  if ( !v37 || !v38 )
  {
    v76 = "%s: Invalid primary or secondary sta freq";
    goto LABEL_32;
  }
  v39 = (unsigned __int8)wlan_reg_freq_to_chan(a1, v37, v15, v16, v17, v18, v19, v20, v21, v22);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: First connection channel No.:%d and quota:%dms",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "wlan_mlme_get_mcc_duty_cycle_percentage",
    v39,
    70);
  v56 = (unsigned __int8)wlan_reg_freq_to_chan(a1, v38, v48, v49, v50, v51, v52, v53, v54, v55);
  if ( !v56 )
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Secondary adapter op channel is invalid",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "wlan_mlme_get_mcc_duty_cycle_percentage");
  v65 = (v56 | (v39 << 8)) & 0xFCFFFFFF | ((wlan_reg_freq_to_band(v37) & 3) << 24);
  v66 = v65 & 0xF3FFFFFF | ((wlan_reg_freq_to_band(v38) & 3) << 26) | 0x460000;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: quota value: 0x%x",
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    "wlan_mlme_get_mcc_duty_cycle_percentage",
    v66);
  result = v66;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
