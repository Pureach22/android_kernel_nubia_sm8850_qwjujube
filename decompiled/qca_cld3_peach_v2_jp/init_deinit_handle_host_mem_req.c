__int64 __fastcall init_deinit_handle_host_mem_req(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x23
  __int64 v14; // x20
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w21
  __int64 v25; // x20
  unsigned int v26; // w24
  char v27; // w8
  unsigned int v28; // w25
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w28
  unsigned int v38; // w27
  unsigned int v39; // w20
  unsigned int v40; // w24
  unsigned int v41; // w25
  bool v42; // w23
  __int64 v43; // x8
  _DWORD *v44; // x8
  unsigned int v45; // w26
  __int64 v46; // x21
  unsigned int v47; // w27
  __int64 v48; // x23
  __int64 v49; // x22
  __int64 v50; // x0
  bool v51; // cc
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  char v84; // [xsp+4h] [xbp-5Ch]
  __int64 v85; // [xsp+8h] [xbp-58h]
  __int64 v86; // [xsp+10h] [xbp-50h]
  int v87; // [xsp+18h] [xbp-48h]
  unsigned int v88; // [xsp+1Ch] [xbp-44h]
  unsigned int v89; // [xsp+20h] [xbp-40h]
  unsigned int v90; // [xsp+24h] [xbp-3Ch]
  bool v91; // [xsp+30h] [xbp-30h]
  unsigned int v92; // [xsp+34h] [xbp-2Ch]
  __int64 v93; // [xsp+38h] [xbp-28h] BYREF
  __int64 v94; // [xsp+40h] [xbp-20h]
  unsigned int v95; // [xsp+48h] [xbp-18h]
  _QWORD v96[2]; // [xsp+50h] [xbp-10h] BYREF

  v96[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v95 = 0;
  v93 = 0;
  v94 = 0;
  if ( !a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: target_psoc_info is null",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "init_deinit_handle_host_mem_req");
    result = 4;
    goto LABEL_48;
  }
  v11 = *(_QWORD *)(a2 + 16);
  v14 = a3;
  result = wmi_extract_num_mem_reqs_from_service_ready(v11, a3);
  if ( !(_DWORD)result )
  {
LABEL_48:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v24 = result;
  if ( (unsigned int)result > 0x20 )
  {
    v25 = jiffies;
    if ( init_deinit_handle_host_mem_req___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: num_mem_reqs:%u is out of bounds",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "init_deinit_handle_host_mem_req",
        (unsigned int)result);
      init_deinit_handle_host_mem_req___last_ticks = v25;
    }
LABEL_46:
    result = 16;
    goto LABEL_48;
  }
  v26 = 0;
  v87 = result;
  v27 = 1;
  v85 = v11;
  v86 = v14;
LABEL_8:
  v28 = 0;
  v84 = v27;
  v88 = v26;
  while ( 1 )
  {
    result = wmi_extract_host_mem_req_from_service_ready(
               v11,
               v14,
               &v93,
               *(unsigned int *)(a2 + 72),
               *(unsigned int *)(a2 + 68),
               v26,
               v28);
    v37 = v95;
    if ( v95 )
      break;
    if ( (_DWORD)result )
      goto LABEL_48;
LABEL_42:
    if ( ++v28 == v24 )
    {
      v27 = 0;
      result = 0;
      v26 = 1;
      if ( (v84 & 1) == 0 )
        goto LABEL_48;
      goto LABEL_8;
    }
  }
  v38 = v93;
  v89 = v28;
  v90 = v95;
  v39 = v94;
  v40 = *(_DWORD *)(a2 + 3328);
  v92 = v93;
  v41 = (HIDWORD(v93) + 3) & 0xFFFFFFFC;
  if ( v41 )
    v42 = a1 == 0;
  else
    v42 = 1;
  v91 = v42;
  while ( 1 )
  {
    if ( v40 == 32 )
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: REACHED MAX CHUNK LIMIT for mem units %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "init_deinit_alloc_host_mem",
        v90);
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: unit len %d requested by FW, only allocated %d",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "init_deinit_alloc_host_mem",
        v41,
        v90 - v37);
      *(_DWORD *)(a2 + 3328) = 32;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: num_mem_chunk exceeds supp number",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "init_deinit_handle_host_mem_req");
      goto LABEL_46;
    }
    v43 = *(_QWORD *)(a2 + 4512);
    if ( v43 )
    {
      v44 = *(_DWORD **)(v43 + 80);
      if ( v44 )
      {
        if ( *(v44 - 1) != -690961110 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v44)(
                   a1,
                   a2,
                   v38,
                   v40,
                   v37,
                   v41,
                   v39);
        v45 = result;
        if ( !(_DWORD)result )
          goto LABEL_47;
        goto LABEL_39;
      }
    }
    if ( v42 )
      goto LABEL_47;
    v46 = *(_QWORD *)(a1 + 2120);
    if ( !v46 )
      goto LABEL_47;
    if ( (v39 & 8) == 0 || v92 > 9 || (v47 = v37, ((1 << v92) & 0x21C) == 0) )
    {
      v47 = v37;
      if ( v37 * v41 >= 0x40000 )
        v47 = v37 / (((v37 * v41) >> 18) + 1);
    }
    v96[0] = 0;
    if ( v40 >= 0x20 )
      break;
    v48 = a1;
    v49 = a2 + 3336 + 32LL * v40;
    *(_QWORD *)v49 = 0;
    if ( v47 )
    {
      while ( 1 )
      {
        v50 = _qdf_mem_alloc_consistent(
                v46,
                *(_QWORD *)(v46 + 40),
                v47 * v41,
                (__int64)v96,
                "init_deinit_alloc_host_mem_chunk",
                92);
        *(_QWORD *)v49 = v50;
        if ( v50 )
        {
          *(_QWORD *)(v49 + 8) = v96[0];
          *(_DWORD *)(v49 + 24) = v47 * v41;
          *(_DWORD *)(v49 + 28) = v92;
          v45 = v47;
          goto LABEL_38;
        }
        if ( (v39 & 8) != 0 )
          break;
        v45 = v47 >> 1;
        v51 = v47 > 1;
        v47 >>= 1;
        if ( !v51 )
          goto LABEL_38;
      }
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: mem chink alloc failed for %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "init_deinit_alloc_host_mem_chunk",
        v40);
    }
    v45 = 0;
LABEL_38:
    v38 = v92;
    result = qdf_trace_msg(
               0x49u,
               8u,
               "%s: req_id %d idx %d num_units %d unit_len %d",
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               "init_deinit_alloc_host_mem_chunk",
               v92,
               v40,
               v45,
               v41);
    a1 = v48;
    v42 = v91;
    if ( !v45 )
    {
LABEL_47:
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: FAILED TO ALLOC mem unit len %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "init_deinit_alloc_host_mem",
        v41);
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: units requested %d units allocated %d",
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        "init_deinit_alloc_host_mem",
        v90,
        v90 - v37);
      *(_DWORD *)(a2 + 3328) = v40;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: mem alloc failure",
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        "init_deinit_handle_host_mem_req");
      result = 2;
      goto LABEL_48;
    }
LABEL_39:
    v37 -= v45;
    ++v40;
    if ( !v37 )
    {
      *(_DWORD *)(a2 + 3328) = v40;
      v11 = v85;
      v14 = v86;
      v24 = v87;
      v26 = v88;
      v28 = v89;
      goto LABEL_42;
    }
  }
  __break(0x5512u);
  return init_deinit_derive_band_to_mac_param(result);
}
