__int64 __fastcall sme_qos_buffer_existing_flows(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _BOOL4 v21; // w26
  int v22; // w27
  __int64 v23; // x21
  unsigned __int64 v24; // x11
  const char *v25; // x28
  __int64 v26; // x25
  unsigned __int64 v27; // x24
  int v28; // w8
  const char *v29; // x22
  __int64 v30; // x28
  int v31; // w27
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x9
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x4
  const char *v51; // x2
  unsigned __int64 v52; // x26
  int v53; // w24
  _BOOL4 v54; // w27
  __int64 v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  int v72; // w27
  unsigned __int64 v73; // x26
  __int64 v74; // x0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x9
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  _BOOL4 v92; // [xsp+8h] [xbp-78h]
  int v93; // [xsp+Ch] [xbp-74h]
  int v94; // [xsp+Ch] [xbp-74h]
  __int64 v95; // [xsp+18h] [xbp-68h]
  _BYTE v96[76]; // [xsp+20h] [xbp-60h] BYREF

  _ReadStatusReg(SP_EL0);
  memset(v96, 0, sizeof(v96));
  result = csr_ll_peek_head((__int64)&unk_856128, 0, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v21 = 0;
    v22 = 0;
    v23 = 0;
    v24 = 0;
    v25 = "sme_qos_buffer_existing_flows";
    while ( 1 )
    {
      do
      {
        if ( !result )
          goto LABEL_24;
        v26 = result;
        v27 = v24;
        result = csr_ll_next((__int64)&unk_856128, result, 0, v13, v14, v15, v16, v17, v18, v19, v20);
        v24 = v27;
      }
      while ( *(unsigned __int8 *)(v26 + 16) != a2 );
      v28 = *(_DWORD *)(v26 + 20);
      v95 = result;
      if ( v28 > 2 )
      {
        if ( v28 == 3 )
        {
          v29 = v25;
          v30 = a1;
          v92 = v21;
          v94 = v22;
          v72 = *(_DWORD *)(v26 + 24);
          *(_QWORD *)&v96[52] = *(_QWORD *)(v26 + 80);
          *(_QWORD *)&v96[60] = *(_QWORD *)(v26 + 88);
          *(_QWORD *)&v96[68] = *(_QWORD *)(v26 + 96);
          *(_QWORD *)&v96[44] = *(_QWORD *)(v26 + 72);
          *(_QWORD *)&v96[28] = *(_QWORD *)(v26 + 56);
          *(_QWORD *)&v96[36] = *(_QWORD *)(v26 + 64);
          *(_QWORD *)&v96[12] = *(_QWORD *)(v26 + 40);
          *(_QWORD *)&v96[20] = *(_QWORD *)(v26 + 48);
          *(_QWORD *)&v96[4] = *(_QWORD *)(v26 + 32);
          v73 = v27 & 0xFFFFFFFF00000000LL | *(unsigned int *)(v26 + 104);
          qdf_trace_msg(0x34u, 8u, "%s: Invoked", v13, v14, v15, v16, v17, v18, v19, v20, "sme_qos_buffer_cmd");
          v74 = _qdf_mem_malloc(0x90u, "sme_qos_buffer_cmd", 5884);
          if ( v74 )
          {
            *(_QWORD *)(v74 + 16) = 2;
            *(_QWORD *)(v74 + 24) = a1;
            v27 = v73;
            *(_QWORD *)(v74 + 120) = v73;
            *(_QWORD *)(v74 + 128) = v23;
            *(_DWORD *)(v74 + 33) = 0;
            *(_DWORD *)(v74 + 36) = 0;
            *(_DWORD *)(v74 + 40) = v72;
            v21 = v92;
            v22 = v94;
            *(_BYTE *)(v74 + 32) = a2;
            *(_QWORD *)(v74 + 92) = *(_QWORD *)&v96[48];
            *(_QWORD *)(v74 + 100) = *(_QWORD *)&v96[56];
            *(_QWORD *)(v74 + 108) = *(_QWORD *)&v96[64];
            *(_DWORD *)(v74 + 116) = *(_DWORD *)&v96[72];
            *(_DWORD *)(v74 + 136) = v94;
            *(_BYTE *)(v74 + 140) = v92;
            *(_QWORD *)(v74 + 60) = *(_QWORD *)&v96[16];
            *(_QWORD *)(v74 + 68) = *(_QWORD *)&v96[24];
            *(_QWORD *)(v74 + 76) = *(_QWORD *)&v96[32];
            *(_QWORD *)(v74 + 84) = *(_QWORD *)&v96[40];
            *(_OWORD *)(v74 + 44) = *(_OWORD *)v96;
            v83 = qword_856120 + 3040LL * a2;
            *(_WORD *)(v74 + 141) = 0;
            *(_BYTE *)(v74 + 143) = 0;
            csr_ll_insert_head(v83 + 2944, (__int64 *)v74, 1, v75, v76, v77, v78, v79, v80, v81, v82);
            v50 = *(unsigned int *)(v26 + 24);
            v51 = "%s: buffered a modify request for flow %d in handoff state";
            goto LABEL_16;
          }
          v27 = v73;
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: couldn't buffer the modify req for flow %d in handoff state",
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v29,
            *(unsigned int *)(v26 + 24));
          v21 = v92;
          v22 = v94;
          goto LABEL_21;
        }
        if ( v28 != 4 )
          goto LABEL_22;
      }
      else if ( v28 )
      {
        if ( v28 != 1 )
          goto LABEL_22;
        v29 = v25;
        v30 = a1;
        v93 = v22;
        v31 = *(_DWORD *)(v26 + 24);
        qdf_trace_msg(0x34u, 8u, "%s: Invoked", v13, v14, v15, v16, v17, v18, v19, v20, "sme_qos_buffer_cmd");
        v32 = _qdf_mem_malloc(0x90u, "sme_qos_buffer_cmd", 5884);
        if ( v32 )
        {
          *(_QWORD *)(v32 + 16) = 1;
          *(_QWORD *)(v32 + 24) = a1;
          *(_BYTE *)(v32 + 32) = a2;
          *(_DWORD *)(v32 + 33) = 0;
          *(_DWORD *)(v32 + 36) = 0;
          *(_DWORD *)(v32 + 40) = v31;
          v22 = v93;
          *(_QWORD *)(v32 + 120) = v27;
          *(_QWORD *)(v32 + 128) = v23;
          *(_BYTE *)(v32 + 140) = v21;
          *(_QWORD *)(v32 + 92) = *(_QWORD *)&v96[48];
          *(_QWORD *)(v32 + 100) = *(_QWORD *)&v96[56];
          *(_QWORD *)(v32 + 108) = *(_QWORD *)&v96[64];
          *(_DWORD *)(v32 + 116) = *(_DWORD *)&v96[72];
          *(_DWORD *)(v32 + 136) = v93;
          *(_QWORD *)(v32 + 60) = *(_QWORD *)&v96[16];
          *(_QWORD *)(v32 + 68) = *(_QWORD *)&v96[24];
          *(_QWORD *)(v32 + 76) = *(_QWORD *)&v96[32];
          *(_QWORD *)(v32 + 84) = *(_QWORD *)&v96[40];
          *(_OWORD *)(v32 + 44) = *(_OWORD *)v96;
          v41 = qword_856120 + 3040LL * a2;
          *(_WORD *)(v32 + 141) = 0;
          *(_BYTE *)(v32 + 143) = 0;
          csr_ll_insert_head(v41 + 2944, (__int64 *)v32, 1, v33, v34, v35, v36, v37, v38, v39, v40);
          v50 = *(unsigned int *)(v26 + 24);
          v51 = "%s: buffered a release request for flow %d in handoff state";
LABEL_16:
          v25 = v29;
          qdf_trace_msg(0x34u, 8u, v51, v42, v43, v44, v45, v46, v47, v48, v49, v29, v50);
          goto LABEL_22;
        }
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: couldn't buffer the release req for flow %d in handoff state",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v29,
          *(unsigned int *)(v26 + 24));
        v22 = v93;
LABEL_21:
        a1 = v30;
        v25 = v29;
        goto LABEL_22;
      }
      *(_DWORD *)&v96[72] = *(_DWORD *)(v26 + 104);
      *(_QWORD *)&v96[40] = *(_QWORD *)(v26 + 72);
      *(_QWORD *)&v96[48] = *(_QWORD *)(v26 + 80);
      v52 = *(_QWORD *)(v26 + 112);
      v23 = *(_QWORD *)(v26 + 120);
      *(_QWORD *)&v96[24] = *(_QWORD *)(v26 + 56);
      *(_QWORD *)&v96[32] = *(_QWORD *)(v26 + 64);
      *(_QWORD *)&v96[56] = *(_QWORD *)(v26 + 88);
      *(_QWORD *)&v96[64] = *(_QWORD *)(v26 + 96);
      v53 = *(_DWORD *)(v26 + 24);
      v54 = v28 != 0;
      *(_QWORD *)&v96[8] = *(_QWORD *)(v26 + 40);
      *(_QWORD *)&v96[16] = *(_QWORD *)(v26 + 48);
      *(_QWORD *)v96 = *(_QWORD *)(v26 + 32);
      qdf_trace_msg(0x34u, 8u, "%s: Invoked", v13, v14, v15, v16, v17, v18, v19, v20, "sme_qos_buffer_cmd");
      v55 = _qdf_mem_malloc(0x90u, "sme_qos_buffer_cmd", 5884);
      if ( v55 )
      {
        *(_QWORD *)(v55 + 16) = 0;
        *(_QWORD *)(v55 + 24) = a1;
        *(_DWORD *)(v55 + 33) = 0;
        *(_DWORD *)(v55 + 36) = 0;
        *(_DWORD *)(v55 + 40) = v53;
        *(_BYTE *)(v55 + 32) = a2;
        v27 = v52;
        *(_QWORD *)(v55 + 120) = v52;
        *(_QWORD *)(v55 + 128) = v23;
        *(_QWORD *)(v55 + 92) = *(_QWORD *)&v96[48];
        *(_QWORD *)(v55 + 100) = *(_QWORD *)&v96[56];
        *(_QWORD *)(v55 + 108) = *(_QWORD *)&v96[64];
        *(_DWORD *)(v55 + 116) = *(_DWORD *)&v96[72];
        *(_DWORD *)(v55 + 136) = 8;
        *(_BYTE *)(v55 + 140) = v54;
        *(_QWORD *)(v55 + 60) = *(_QWORD *)&v96[16];
        *(_QWORD *)(v55 + 68) = *(_QWORD *)&v96[24];
        *(_QWORD *)(v55 + 76) = *(_QWORD *)&v96[32];
        *(_QWORD *)(v55 + 84) = *(_QWORD *)&v96[40];
        *(_OWORD *)(v55 + 44) = *(_OWORD *)v96;
        *(_WORD *)(v55 + 141) = 0;
        *(_BYTE *)(v55 + 143) = 0;
        csr_ll_insert_head(qword_856120 + 3040LL * a2 + 2944, (__int64 *)v55, 1, v56, v57, v58, v59, v60, v61, v62, v63);
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: buffered a setup request for flow %d in handoff state",
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v25,
          *(unsigned int *)(v26 + 24));
      }
      else
      {
        v27 = v52;
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: couldn't buffer the setup request for flow %d in handoff state",
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v25,
          *(unsigned int *)(v26 + 24));
      }
      v21 = v54;
      v22 = 8;
LABEL_22:
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Deleting original entry at %pK with flowID %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v25,
        v26,
        *(unsigned int *)(v26 + 24));
      csr_ll_remove_entry((__int64)&unk_856128, (__int64 *)v26, 1, v84, v85, v86, v87, v88, v89, v90, v91);
      _qdf_mem_free(v26);
      result = v95;
      v24 = v27;
    }
  }
  result = qdf_trace_msg(
             0x34u,
             2u,
             "%s: Flow List empty, nothing to buffer",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "sme_qos_buffer_existing_flows");
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
