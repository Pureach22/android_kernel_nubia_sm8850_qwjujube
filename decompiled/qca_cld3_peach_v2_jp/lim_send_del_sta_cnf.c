__int64 __fastcall lim_send_del_sta_cnf(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int16 a4,
        __int64 a5,
        unsigned int a6,
        __int64 a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 v20; // x4
  __int64 v21; // x6
  __int64 result; // x0
  unsigned int v23; // w8
  __int64 *v24; // x2
  __int64 v25; // x0
  __int64 v26; // x1
  char v27; // w9
  __int16 v28; // w8
  __int16 v29; // w8
  __int16 v30; // w9
  char v31; // w10
  char v32; // w9
  __int16 v33; // w2
  unsigned int v34; // w22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x2
  __int64 v44; // x3
  __int64 v45; // x0
  __int64 v46; // x1
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  _QWORD v55[2]; // [xsp+28h] [xbp-58h] BYREF
  __int64 v56; // [xsp+38h] [xbp-48h] BYREF
  __int64 v57; // [xsp+40h] [xbp-40h]
  int v58; // [xsp+48h] [xbp-38h]
  __int64 v59; // [xsp+50h] [xbp-30h] BYREF
  __int64 v60; // [xsp+58h] [xbp-28h]
  __int64 v61; // [xsp+60h] [xbp-20h]
  int v62; // [xsp+68h] [xbp-18h] BYREF
  __int16 v63; // [xsp+6Ch] [xbp-14h]
  int v64; // [xsp+70h] [xbp-10h] BYREF
  __int16 v65; // [xsp+74h] [xbp-Ch]
  __int64 v66; // [xsp+78h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v65 = WORD2(a2);
  v20 = *(unsigned __int16 *)(a7 + 8);
  v21 = *(unsigned __int16 *)(a5 + 26);
  v63 = WORD2(a3);
  v64 = a2;
  v62 = a3;
  v60 = 0;
  v61 = 0;
  v59 = 0;
  v58 = 0;
  v56 = 0;
  v57 = 0;
  memset(v55, 0, 14);
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: Sessionid: %d staDsAssocId: %d Trigger: %d status_code: %d sta_dsaddr: %02x:%02x:%02x:**:**:%02x",
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             a15,
             "lim_send_del_sta_cnf",
             v20,
             a4,
             v21,
             a6,
             (unsigned __int8)a2,
             BYTE1(a2),
             BYTE2(a2),
             BYTE5(a2));
  if ( *(_DWORD *)(a7 + 88) == 2 )
  {
    result = *(_QWORD *)(a7 + 128);
    if ( result )
    {
      result = _qdf_mem_free(result);
      *(_QWORD *)(a7 + 128) = 0;
    }
    *(_WORD *)(a7 + 180) = 0;
  }
  v23 = *(unsigned __int16 *)(a5 + 26);
  if ( v23 <= 4 )
  {
    if ( *(unsigned __int16 *)(a5 + 26) > 1u )
    {
      if ( v23 - 2 >= 2 )
      {
        if ( v23 != 4 )
          goto LABEL_22;
        goto LABEL_13;
      }
      goto LABEL_19;
    }
    if ( !*(_WORD *)(a5 + 26) )
    {
LABEL_19:
      qdf_mem_copy(&v59, &v64, 6u);
      v28 = *(_WORD *)(a5 + 26);
      goto LABEL_20;
    }
LABEL_18:
    qdf_mem_copy(v55, &v64, 6u);
    v29 = *(unsigned __int8 *)(a5 + 16);
    v30 = *(_WORD *)(a5 + 26);
    v24 = v55;
    v31 = *(_BYTE *)(a7 + 8);
    v25 = a1;
    v26 = 1031;
    WORD1(v55[1]) = a4;
    HIWORD(v55[0]) = v29;
    LOWORD(v55[1]) = v30;
    BYTE4(v55[1]) = v31;
    goto LABEL_21;
  }
  if ( *(unsigned __int16 *)(a5 + 26) > 6u )
  {
    if ( v23 == 7 )
    {
      v33 = *(_WORD *)(a7 + 8);
      v34 = *(unsigned __int8 *)(a7 + 10);
      *(_DWORD *)(a7 + 80) = 7;
      qdf_trace(53, 1u, v33, 7);
      if ( (unsigned int)(*(_DWORD *)(a5 + 20) - 511) <= 0x1A && ((1 << (*(_BYTE *)(a5 + 20) + 1)) & 0x6000001) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Lim Posting eWNI_SME_REASSOC_RSP to SMEresultCode: %d, status_code: %d,sessionId: %d",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "lim_send_del_sta_cnf");
        v43 = *(unsigned int *)(a5 + 20);
        v44 = *(unsigned __int16 *)(a5 + 28);
        v45 = a1;
        v46 = 1;
      }
      else
      {
        _qdf_mem_free(*(_QWORD *)(a7 + 112));
        *(_QWORD *)(a7 + 112) = 0;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Lim Posting eWNI_SME_JOIN_RSP to SME.resultCode: %d,status_code: %d,sessionId: %d",
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          "lim_send_del_sta_cnf",
          *(unsigned int *)(a5 + 20),
          *(unsigned __int16 *)(a5 + 28),
          *(unsigned __int16 *)(a7 + 8));
        v43 = *(unsigned int *)(a5 + 20);
        v44 = *(unsigned __int16 *)(a5 + 28);
        v45 = a1;
        v46 = 0;
      }
      result = lim_send_sme_join_reassoc_rsp(v45, v46, v43, v44, a7, v34);
      if ( *(_DWORD *)(a5 + 20) )
        goto LABEL_24;
    }
    else if ( v23 == 9 )
    {
      qdf_mem_copy(&v59, &v64, 6u);
      qdf_mem_copy((char *)&v59 + 6, &v62, 6u);
      v28 = 9;
LABEL_20:
      HIDWORD(v60) = a6;
      v32 = *(_BYTE *)(a7 + 8);
      v24 = &v59;
      v25 = a1;
      v26 = 1013;
      LOWORD(v61) = v28;
      BYTE4(v61) = v32;
      goto LABEL_21;
    }
  }
  else
  {
    if ( v23 == 5 )
      goto LABEL_18;
    if ( v23 == 6 )
    {
LABEL_13:
      v24 = &v56;
      v25 = a1;
      v26 = 1018;
      LODWORD(v57) = a6;
      LODWORD(v56) = v64;
      v27 = *(_BYTE *)(a7 + 8);
      WORD2(v56) = v65;
      WORD2(v57) = v23;
      LOBYTE(v58) = v27;
LABEL_21:
      result = lim_process_mlm_rsp_messages(v25, v26, v24);
    }
  }
LABEL_22:
  if ( a7 && *(_DWORD *)(a7 + 88) != 1 )
LABEL_24:
    result = pe_delete_session(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
