void __fastcall csr_process_nss_update_req(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x4
  __int64 v13; // x8
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x21
  unsigned int v42; // w9
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // [xsp+8h] [xbp-38h] BYREF
  __int64 v52; // [xsp+10h] [xbp-30h]
  __int64 v53; // [xsp+18h] [xbp-28h]
  __int64 v54; // [xsp+20h] [xbp-20h]
  __int64 v55; // [xsp+28h] [xbp-18h]
  __int64 v56; // [xsp+30h] [xbp-10h]
  __int64 v57; // [xsp+38h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a2[6];
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  if ( a1
    && (unsigned int)v12 <= 5
    && (v13 = *(_QWORD *)(a1 + 17296)) != 0
    && (*(_BYTE *)(v13 + 96LL * (unsigned int)v12 + 1) & 1) != 0 )
  {
    v14 = _qdf_mem_malloc(0xCu, "csr_process_nss_update_req", 7825);
    if ( v14 )
    {
      *(_DWORD *)v14 = 791660;
      v23 = v14;
      *(_BYTE *)(v14 + 4) = a2[8];
      *(_BYTE *)(v14 + 5) = a2[9];
      *(_DWORD *)(v14 + 8) = a2[10];
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Posting eWNI_SME_NSS_UPDATE_REQ to PE",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "csr_process_nss_update_req");
      if ( !(unsigned int)umac_send_mb_message_to_mac(v23) )
        goto LABEL_11;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Posting to PE failed",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "csr_process_nss_update_req");
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid session id %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "csr_process_nss_update_req",
      v12);
  }
  v32 = _qdf_mem_malloc(0xCu, "csr_process_nss_update_req", 7847);
  if ( v32 )
  {
    v41 = v32;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Sending nss update fail response to SME",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "csr_process_nss_update_req");
    *(_DWORD *)(v41 + 8) = 16;
    v42 = a2[10];
    *(_DWORD *)(v41 + 4) = 1;
    *(_BYTE *)v41 = v42;
    LOWORD(v51) = 5229;
    v52 = v41;
    HIDWORD(v51) = 0;
    sys_process_mmh_msg(v43, v44, v45, v46, v47, v48, v49, v50, a1, (unsigned __int16 *)&v51);
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
}
