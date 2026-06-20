void __fastcall csr_process_set_antenna_mode(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 v21; // x5
  __int64 v22; // x9
  __int64 v23; // x8
  __int64 v24; // x20
  const char *v25; // x2
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _DWORD *v35; // x20
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v45; // [xsp+10h] [xbp-30h]
  __int64 v46; // [xsp+18h] [xbp-28h]
  __int64 v47; // [xsp+20h] [xbp-20h]
  __int64 v48; // [xsp+28h] [xbp-18h]
  __int64 v49; // [xsp+30h] [xbp-10h]
  __int64 v50; // [xsp+38h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = nullptr;
  if ( a2 )
  {
    v12 = _qdf_mem_malloc(0x20u, "csr_process_set_antenna_mode", 7761);
    if ( !v12 )
      goto LABEL_7;
    *(_DWORD *)v12 = 2102395;
    v21 = a2[4];
    v22 = a2[5];
    v23 = a2[6];
    v24 = v12;
    *(_QWORD *)(v12 + 24) = v23;
    *(_QWORD *)(v12 + 8) = v21;
    *(_QWORD *)(v12 + 16) = v22;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Posting eWNI_SME_SET_ANTENNA_MODE_REQ to PE: %d %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "csr_process_set_antenna_mode",
      HIDWORD(v21));
    if ( !(unsigned int)umac_send_mb_message_to_mac(v24) )
      goto LABEL_9;
    v25 = "%s: Posting to PE failed";
  }
  else
  {
    v25 = "%s: Set antenna mode param is NULL";
  }
  qdf_trace_msg(0x34u, 2u, v25, a3, a4, a5, a6, a7, a8, a9, a10, "csr_process_set_antenna_mode");
LABEL_7:
  v26 = _qdf_mem_malloc(4u, "csr_process_set_antenna_mode", 7786);
  if ( v26 )
  {
    v35 = (_DWORD *)v26;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Sending set dual mac fail response to SME",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "csr_process_set_antenna_mode");
    *v35 = 2;
    LOWORD(v44) = 5244;
    v45 = v35;
    HIDWORD(v44) = 0;
    sys_process_mmh_msg(v36, v37, v38, v39, v40, v41, v42, v43, a1, (unsigned __int16 *)&v44);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
}
