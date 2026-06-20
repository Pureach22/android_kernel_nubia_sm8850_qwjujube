// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_3DD67C@<X0>(
        unsigned int a1@<W8>,
        double a2@<D0>,
        double a3@<D1>,
        double a4@<D2>,
        double a5@<D3>,
        double a6@<D4>,
        double a7@<D5>,
        double a8@<D6>,
        double a9@<D7>)
{
  _BYTE *v9; // x19
  __int64 v10; // x20
  __int64 v11; // x21
  unsigned __int8 *v12; // x22
  _BYTE *v13; // x25
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
  int v31; // w8
  size_t v32; // x2
  size_t v33; // x2
  unsigned __int64 v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w11
  unsigned int v44; // w9
  unsigned int v45; // w10
  unsigned int v46; // w0
  __int64 v47; // [xsp-100h] [xbp-100h]
  __int64 v48; // [xsp-F8h] [xbp-F8h]
  __int64 v49; // [xsp-F0h] [xbp-F0h]
  __int64 v50; // [xsp-E8h] [xbp-E8h]
  __int64 v51; // [xsp-E0h] [xbp-E0h]
  __int64 v52; // [xsp-D8h] [xbp-D8h]
  __int64 v53; // [xsp-D0h] [xbp-D0h]
  __int64 v54; // [xsp-C8h] [xbp-C8h]
  __int64 v55; // [xsp-C0h] [xbp-C0h]
  __int64 v56; // [xsp-B8h] [xbp-B8h]

  if ( !(_DWORD)v9 )
    return dot11f_unpack_ie_gtk();
  if ( a1 >= 5 )
  {
    qdf_mem_copy((void *)(v10 + 2280), v9 + 4464, 0x3Cu);
    if ( *((unsigned __int16 *)v9 + 2111) > 5u )
      goto LABEL_57;
  }
  *(_BYTE *)(v10 + 2293) = 1;
  if ( v13[120] )
  {
    *(_BYTE *)(v10 + 2294) = 1;
    qdf_mem_copy((void *)(v10 + 2280), v9 + 4217, 4u);
  }
  if ( v9[452] )
    qdf_mem_copy((void *)(v10 + 2742), v9 + 452, 6u);
  if ( v9[520] )
    qdf_mem_copy((void *)(v10 + 2296), v9 + 520, 0x10u);
  if ( v9[536] )
    qdf_mem_copy((void *)(v10 + 2312), v9 + 536, 6u);
  if ( v9[434] )
  {
    qdf_mem_copy((void *)(v10 + 2318), v9 + 434, 0x11u);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: timingMeas: %d, finetimingMeas Init: %d, Resp: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "sir_convert_assoc_resp_frame2_struct",
      (*(_DWORD *)(v10 + 2320) >> 23) & 1,
      (*(unsigned __int16 *)(v10 + 2328) >> 7) & 1,
      (*(unsigned __int16 *)(v10 + 2328) >> 6) & 1);
  }
  if ( v9[542] )
    qdf_mem_copy((void *)(v10 + 2335), v9 + 542, 2u);
  if ( v9[458] )
  {
    *(_BYTE *)(v10 + 2337) = 1;
    ((void (__fastcall *)(__int64, __int64, _BYTE *))convert_qos_mapset_frame)(v11, v10 + 2337, v9 + 458);
    if ( *(unsigned __int8 *)(v10 + 2338) >= 0x16u )
      *(_BYTE *)(v10 + 2338) = 21;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: num of dscp exceptions: %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "lim_log_qos_map_set");
    ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(53, 8, v10 + 2339, 42);
    ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(53, 8, v10 + 2381, 16);
  }
  v31 = (unsigned __int8)v13[400];
  *(_BYTE *)(v10 + 2416) = v31;
  if ( v31 )
    *(_BYTE *)(v10 + 2417) = v13[401];
  if ( v9[418] )
    qdf_mem_copy((void *)(v10 + 2444), v9 + 418, 0x10u);
  if ( v13[404] )
    qdf_mem_copy((void *)(v10 + 2420), v13 + 404, 0x10u);
  if ( v13[420] )
    qdf_mem_copy((void *)(v10 + 2436), v13 + 420, 6u);
  if ( v13[428] )
    qdf_mem_copy((void *)(v10 + 2464), v13 + 428, 0x2Cu);
  if ( v9[1340] )
    qdf_mem_copy((void *)(v10 + 2508), v9 + 1340, 0x3Cu);
  if ( v9[1400] )
    qdf_mem_copy((void *)(v10 + 2568), v9 + 1400, 0x12u);
  if ( v9[1418] )
    qdf_mem_copy((void *)(v10 + 2586), v9 + 1418, 0x15u);
  if ( v9[1456] )
    qdf_mem_copy((void *)(v10 + 2608), v9 + 1456, 4u);
  if ( v9[1442] )
  {
    *(_BYTE *)(v10 + 2716) = 1;
    ((void (__fastcall *)(__int64, __int64, _BYTE *))convert_mu_edca_param)(v11, v10 + 2717, v9 + 1442);
  }
  if ( v13[472] && v13[748] )
    qdf_mem_copy((void *)(v10 + 2460), v13 + 748, 3u);
  if ( v9[544] )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: fils session IE present",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "fils_convert_assoc_rsp_frame2_struct");
    *(_BYTE *)(v10 + 2748) = 1;
    qdf_mem_copy((void *)(v10 + 2749), v9 + 545, 8u);
  }
  if ( v9[811] )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: fils key conf IE present",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "fils_convert_assoc_rsp_frame2_struct");
    v32 = (unsigned __int8)v9[812];
    *(_BYTE *)(v10 + 2758) = v32;
    qdf_mem_copy((void *)(v10 + 2759), v9 + 813, v32);
  }
  if ( v9[2996] )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: fils kde IE present %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "fils_convert_assoc_rsp_frame2_struct",
      (unsigned __int8)v9[3005]);
    *(_BYTE *)(v10 + 3023) = v9[3005];
    qdf_mem_copy((void *)(v10 + 3015), v9 + 2997, 8u);
    qdf_mem_copy((void *)(v10 + 3024), v9 + 3006, *(unsigned __int8 *)(v10 + 3023));
  }
  if ( !v9[1068] )
    goto LABEL_54;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: FILS HLP container IE present",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "fils_convert_assoc_rsp_frame2_struct");
  *(_BYTE *)(v10 + 3279) = v9[1069];
  *(_BYTE *)(v10 + 3280) = v9[1070];
  *(_BYTE *)(v10 + 3281) = v9[1071];
  *(_BYTE *)(v10 + 3282) = v9[1072];
  *(_BYTE *)(v10 + 3283) = v9[1073];
  *(_BYTE *)(v10 + 3284) = v9[1074];
  *(_BYTE *)(v10 + 3285) = v9[1075];
  *(_BYTE *)(v10 + 3286) = v9[1076];
  *(_BYTE *)(v10 + 3287) = v9[1077];
  *(_BYTE *)(v10 + 3288) = v9[1078];
  *(_BYTE *)(v10 + 3289) = v9[1079];
  *(_BYTE *)(v10 + 3290) = v9[1080];
  v33 = (unsigned __int8)v9[1081];
  *(_WORD *)(v10 + 3292) = v33;
  qdf_mem_copy((void *)(v10 + 3294), v9 + 1082, v33);
  if ( !v9[2739] )
    goto LABEL_54;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: FILS fragment ie present",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "fils_convert_assoc_rsp_frame2_struct");
  v34 = *(unsigned __int16 *)(v10 + 3292);
  if ( v34 >= 0x801 )
  {
LABEL_57:
    __break(0x5512u);
    JUMPOUT(0x407210);
  }
  qdf_mem_copy((void *)(v10 + 3294 + v34), v9 + 2741, (unsigned __int8)v9[2740]);
  *(_WORD *)(v10 + 3292) += (unsigned __int8)v9[2740];
LABEL_54:
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: ht %d vht %d vendor vht: cap %d op %d, he %d he 6ghband %d eht %d eht320 %d, max idle: present %d val %d, he mu "
    "edca %d wmm %d qos %d mlo %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "sir_convert_assoc_resp_frame2_struct",
    (unsigned __int8)v9[300],
    (unsigned __int8)v9[520],
    (unsigned __int8)v13[404],
    (unsigned __int8)v13[420],
    (unsigned __int8)v9[1340],
    (unsigned __int8)v9[1456],
    (unsigned __int8)v9[3264],
    (*(_DWORD *)(v10 + 2613) >> 17) & 1,
    (unsigned __int8)v9[452],
    *(unsigned __int16 *)(v10 + 2744),
    (unsigned __int8)v9[1442],
    *v12,
    (unsigned __int8)v9[458],
    (unsigned __int8)v9[3368]);
  if ( *v12 )
  {
    v43 = *((unsigned __int16 *)v9 + 2101);
    v44 = *((unsigned __int16 *)v9 + 2097);
    v45 = *((unsigned __int16 *)v9 + 2099);
    v46 = *((unsigned __int16 *)v9 + 2103);
    LODWORD(v56) = (v43 >> 5) & 3;
    LODWORD(v55) = (v43 >> 4) & 1;
    LODWORD(v54) = v43 & 0xF;
    LODWORD(v53) = *((unsigned __int16 *)v9 + 2100);
    LODWORD(v52) = v45 >> 12;
    LODWORD(v51) = (v45 >> 8) & 0xF;
    LODWORD(v50) = (v45 >> 5) & 3;
    LODWORD(v49) = (v45 >> 4) & 1;
    LODWORD(v48) = v45 & 0xF;
    LODWORD(v47) = *((unsigned __int16 *)v9 + 2098);
    qdf_trace_msg(
      0x35u,
      8u,
      "WMM: BE: aifsn %d, acm %d, aci %d, cwmin %d, cwmax %d, txop %d, BK: aifsn %d, acm %d, aci %d, cwmin %d, cwmax %d, "
      "txop %d, VI: aifsn %d, acm %d, aci %d, cwmin %d, cwmax %d, txop %d, VO: aifsn %d, acm %d, aci %d, cwmin %d, cwmax %d, txop %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v44 & 0xF,
      (v44 >> 4) & 1,
      (v44 >> 5) & 3,
      (v44 >> 8) & 0xF,
      v44 >> 12,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      (v43 >> 8) & 0xF,
      v43 >> 12,
      *((unsigned __int16 *)v9 + 2102),
      v46 & 0xF,
      (v46 >> 4) & 1,
      (v46 >> 5) & 3,
      (v46 >> 8) & 0xF,
      v46 >> 12,
      *((unsigned __int16 *)v9 + 2104));
  }
  _qdf_mem_free((__int64)v9);
  _ReadStatusReg(SP_EL0);
  return 0;
}
