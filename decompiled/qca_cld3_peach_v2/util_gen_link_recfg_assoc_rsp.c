__int64 __fastcall util_gen_link_recfg_assoc_rsp(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int16 a4,
        unsigned int a5,
        __int64 a6,
        char *a7,
        unsigned __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        __int64 *a17)
{
  __int64 v25; // x3
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x3
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w8
  __int64 v44; // x9
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  const char *v53; // x2
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w19
  unsigned __int16 v64; // w25
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  char *v73; // x0
  char *v74; // x24
  __int64 v75; // x25
  unsigned int v76; // w9
  __int64 v77; // x27
  __int64 v78; // x23
  unsigned __int16 v79; // w28
  unsigned __int64 v80; // x23
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned int v105; // w0
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  size_t n; // [xsp+8h] [xbp-28h] BYREF
  const void *v115; // [xsp+10h] [xbp-20h] BYREF
  __int64 v116; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v117[2]; // [xsp+20h] [xbp-10h] BYREF

  v117[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Link %d: dump org assoc rsp and action frame:",
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    a16,
    "util_gen_link_recfg_assoc_rsp",
    (unsigned __int8)a5);
  mgmt_txrx_frame_hex_dump(*(_QWORD *)(a1 + 8), *(_DWORD *)a1, 0, v25, v26, v27, v28, v29, v30, v31, v32, v33);
  mgmt_txrx_frame_hex_dump(a2, a3, 0, v34, v35, v36, v37, v38, v39, v40, v41, v42);
  v43 = *(_DWORD *)a1;
  v44 = *(_QWORD *)(a1 + 8);
  v117[0] = 0;
  v115 = nullptr;
  v116 = 0;
  n = 0;
  if ( (unsigned int)util_find_mlie(v44 + 6, v43 - 6, v117, &v116) )
  {
    v53 = "%s: ML IE not found";
LABEL_5:
    qdf_trace_msg(0x8Fu, 2u, v53, v45, v46, v47, v48, v49, v50, v51, v52, "util_link_recfg_replace_ml_ie");
LABEL_6:
    v62 = 4;
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_link_recfg_replace_ml_ie failed %d",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "util_gen_link_recfg_assoc_rsp",
      4);
    goto LABEL_7;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: ML IE org_assoc_rsp_ies",
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    "util_link_recfg_replace_ml_ie");
  ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(75, 8, v117[0], (unsigned int)v116);
  if ( (unsigned int)util_find_mlie(a2 + a4, (unsigned __int16)a3 - (unsigned __int64)a4, &v115, &n) )
  {
    v53 = "%s: ML IE not found in action_ies";
    goto LABEL_5;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: ML IE action_ies",
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    "util_link_recfg_replace_ml_ie");
  ((void (__fastcall *)(__int64, __int64, const void *, _QWORD))qdf_trace_hex_dump)(75, 8, v115, (unsigned int)n);
  v64 = n - v116 + *(_DWORD *)a1;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: mlieseqlen %d, action_mlieseqlen %d new_assc_rsp_buf_len %d",
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    "util_link_recfg_replace_ml_ie");
  v73 = (char *)_qdf_mem_malloc(v64, "util_link_recfg_replace_ml_ie", 3207);
  if ( !v73 )
    goto LABEL_6;
  v74 = v73;
  qdf_mem_copy(v73, *(const void **)(a1 + 8), LODWORD(v117[0]) - (unsigned int)*(_QWORD *)(a1 + 8));
  v75 = v117[0];
  v76 = *(_DWORD *)a1;
  v77 = v116;
  v78 = v117[0] - *(_QWORD *)(a1 + 8);
  v79 = v76 - v116 - v78;
  qdf_mem_copy(&v74[(unsigned __int16)v78], v115, (unsigned int)n);
  LOWORD(v78) = n + v78;
  qdf_mem_copy(&v74[(unsigned __int16)v78], (const void *)(v75 + v77), v79);
  v80 = (unsigned __int16)(v79 + v78);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: len %d",
    v81,
    v82,
    v83,
    v84,
    v85,
    v86,
    v87,
    v88,
    "util_link_recfg_replace_ml_ie",
    (unsigned int)v80);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: ML new_assoc_rsp",
    v89,
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    "util_link_recfg_replace_ml_ie");
  v97 = ((double (__fastcall *)(__int64, __int64, char *, _QWORD))qdf_trace_hex_dump)(75, 8, v74, (unsigned int)v80);
  v105 = util_gen_link_reqrsp_cmn(
           v74,
           v80,
           1u,
           a5,
           a6 & 0xFFFFFFFFFFFFLL,
           nullptr,
           a7,
           a8,
           v97,
           v98,
           v99,
           v100,
           v101,
           v102,
           v103,
           v104,
           a17);
  if ( v105 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: util_gen_link_reqrsp_cmn failed %d",
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      "util_gen_link_recfg_assoc_rsp",
      v105);
    _qdf_mem_free((__int64)v74);
    v62 = 4;
  }
  else
  {
    _qdf_mem_free((__int64)v74);
    v62 = 0;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v62;
}
