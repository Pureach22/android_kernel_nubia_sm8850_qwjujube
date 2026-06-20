__int64 __fastcall lim_process_update_add_ies(
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
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  unsigned int v22; // w21
  unsigned int v23; // w4
  __int64 v24; // x19
  __int64 v25; // x23
  __int64 v26; // x0
  const char *v27; // x2
  const char *v28; // x3
  unsigned int v29; // w1
  const void *v30; // x22
  void *v31; // x8
  __int64 v32; // x23
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  const void *v41; // x20
  void *v42; // x8
  __int64 v43; // x22
  __int64 v44; // x21
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x19
  unsigned __int16 v54; // w21
  __int64 v55; // x20
  char *v56; // x0
  const void *v57; // x1
  size_t v58; // x2
  __int64 v59; // x22
  char *v60; // x20
  char v61[4]; // [xsp+Ch] [xbp-134h] BYREF
  __int64 v62; // [xsp+10h] [xbp-130h] BYREF
  __int64 v63; // [xsp+18h] [xbp-128h]
  int v64; // [xsp+20h] [xbp-120h]
  _DWORD v65[2]; // [xsp+28h] [xbp-118h] BYREF
  _DWORD v66[5]; // [xsp+30h] [xbp-110h] BYREF
  _QWORD v67[5]; // [xsp+44h] [xbp-FCh] BYREF
  __int64 v68; // [xsp+6Ch] [xbp-D4h]
  __int64 v69; // [xsp+74h] [xbp-CCh] BYREF
  __int64 v70; // [xsp+7Ch] [xbp-C4h]
  _DWORD v71[6]; // [xsp+84h] [xbp-BCh] BYREF
  _QWORD v72[2]; // [xsp+9Ch] [xbp-A4h] BYREF
  __int64 v73; // [xsp+ACh] [xbp-94h]
  __int64 v74; // [xsp+B4h] [xbp-8Ch] BYREF
  __int64 v75; // [xsp+BCh] [xbp-84h]
  __int64 v76; // [xsp+C4h] [xbp-7Ch]
  _BYTE v77[40]; // [xsp+CCh] [xbp-74h] BYREF
  __int64 v78; // [xsp+F4h] [xbp-4Ch]
  __int64 v79; // [xsp+FCh] [xbp-44h] BYREF
  __int64 v80; // [xsp+104h] [xbp-3Ch]
  _DWORD v81[6]; // [xsp+10Ch] [xbp-34h] BYREF
  _QWORD v82[2]; // [xsp+124h] [xbp-1Ch] BYREF
  int v83; // [xsp+134h] [xbp-Ch]
  __int64 v84; // [xsp+138h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61[0] = 0;
  if ( !a2 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: msg_buf is NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_process_update_add_ies");
    goto LABEL_48;
  }
  if ( *(_DWORD *)(a2 + 32) == 5 )
  {
    result = sch_edca_profile_update_all();
    goto LABEL_48;
  }
  result = pe_find_session_by_bssid(a1, a2 + 8, v61);
  if ( !result )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Session not found for given bssid%02x:%02x:%02x:**:**:%02x",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_process_update_add_ies",
      *(unsigned __int8 *)(a2 + 8),
      *(unsigned __int8 *)(a2 + 9),
      *(unsigned __int8 *)(a2 + 10),
      *(unsigned __int8 *)(a2 + 13));
LABEL_47:
    result = _qdf_mem_free(*(_QWORD *)(a2 + 24));
    *(_QWORD *)(a2 + 24) = 0;
    goto LABEL_48;
  }
  v21 = *(unsigned int *)(a2 + 32);
  v22 = *(unsigned __int16 *)(a2 + 18);
  if ( *(_WORD *)(a2 + 18) )
  {
    if ( (int)v21 > 2 )
    {
      if ( (_DWORD)v21 == 3 )
      {
        v41 = *(const void **)(a2 + 24);
        if ( v41 )
        {
          v42 = *(void **)(result + 7312);
          if ( *(unsigned __int16 *)(result + 7304) >= v22
            || (*(_WORD *)(result + 7304) = v22,
                v43 = result,
                _qdf_mem_free((__int64)v42),
                v42 = (void *)_qdf_mem_malloc(*(unsigned __int16 *)(v43 + 7304), "lim_update_add_ie_buffer", 10722),
                result = v43,
                (*(_QWORD *)(v43 + 7312) = v42) != 0) )
          {
            *(_WORD *)(result + 7304) = v22;
            qdf_mem_copy(v42, v41, v22);
          }
          else
          {
            *(_WORD *)(v43 + 7304) = 0;
          }
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: src buffer is null",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "lim_update_add_ie_buffer");
        }
        goto LABEL_47;
      }
      if ( (_DWORD)v21 == 4 )
      {
        v25 = result;
        v26 = *(_QWORD *)(a2 + 24);
        v64 = 0;
        v62 = 0;
        v63 = 0;
        v82[1] = 0;
        v83 = 0;
        v82[0] = 0;
        memset(v81, 0, sizeof(v81));
        v80 = 0;
        v79 = 0;
        v78 = 0;
        memset(v77, 0, sizeof(v77));
        v76 = 0;
        v75 = 0;
        v74 = 0;
        v73 = 0;
        v72[1] = 0;
        v72[0] = 0;
        memset(v71, 0, sizeof(v71));
        v70 = 0;
        v69 = 0;
        v68 = 0;
        memset(v67, 0, sizeof(v67));
        if ( !(unsigned int)wlan_parse_wmm_params(v26, v22, &v62) )
        {
          v66[4] = HIWORD(v62);
          v65[0] = (WORD2(v62) >> 4) & 1;
          v65[1] = BYTE4(v62) & 0xF;
          v66[0] = (unsigned int)~(-1 << (BYTE5(v62) & 0xF)) >> 8;
          v66[1] = (unsigned __int8)~(-1 << (BYTE5(v62) & 0xF));
          v66[2] = (unsigned int)~(-1 << (WORD2(v62) >> 12)) >> 8;
          v66[3] = (unsigned __int8)~(-1 << (WORD2(v62) >> 12));
          qdf_mem_copy(v67, v66, 0x14u);
          qdf_mem_copy((char *)&v67[2] + 4, v66, 0x14u);
          v71[0] = WORD1(v63);
          LODWORD(v68) = ((unsigned __int16)v63 >> 4) & 1;
          HIDWORD(v68) = v63 & 0xF;
          LODWORD(v69) = (unsigned int)~(-1 << (BYTE1(v63) & 0xF)) >> 8;
          HIDWORD(v69) = (unsigned __int8)~(-1 << (BYTE1(v63) & 0xF));
          LODWORD(v70) = (unsigned int)~(-1 << ((unsigned __int16)v63 >> 12)) >> 8;
          HIDWORD(v70) = (unsigned __int8)~(-1 << ((unsigned __int16)v63 >> 12));
          qdf_mem_copy(&v71[1], &v69, 0x14u);
          qdf_mem_copy(v72, &v69, 0x14u);
          HIDWORD(v76) = HIWORD(v63);
          HIDWORD(v73) = (WORD2(v63) >> 4) & 1;
          LODWORD(v74) = BYTE4(v63) & 0xF;
          HIDWORD(v74) = (unsigned int)~(-1 << (BYTE5(v63) & 0xF)) >> 8;
          LODWORD(v75) = (unsigned __int8)~(-1 << (BYTE5(v63) & 0xF));
          HIDWORD(v75) = (unsigned int)~(-1 << (WORD2(v63) >> 12)) >> 8;
          LODWORD(v76) = (unsigned __int8)~(-1 << (WORD2(v63) >> 12));
          qdf_mem_copy(v77, (char *)&v74 + 4, 0x14u);
          qdf_mem_copy(&v77[20], (char *)&v74 + 4, 0x14u);
          v81[0] = HIWORD(v64);
          LODWORD(v78) = ((unsigned __int16)v64 >> 4) & 1;
          HIDWORD(v78) = v64 & 0xF;
          LODWORD(v79) = (unsigned int)~(-1 << (BYTE1(v64) & 0xF)) >> 8;
          HIDWORD(v79) = (unsigned __int8)~(-1 << (BYTE1(v64) & 0xF));
          LODWORD(v80) = (unsigned int)~(-1 << ((unsigned __int16)v64 >> 12)) >> 8;
          HIDWORD(v80) = (unsigned __int8)~(-1 << ((unsigned __int16)v64 >> 12));
          qdf_mem_copy(&v81[1], &v79, 0x14u);
          qdf_mem_copy(v82, &v79, 0x14u);
          *(_BYTE *)(v25 + 13280) = 1;
          sch_edca_profile_update(a1, v25, v65);
          goto LABEL_47;
        }
        v27 = "%s: Error parsing IE for WMM params %d";
        v28 = "lim_parse_and_update_wmm_params";
        v29 = 8;
        v21 = v22;
        goto LABEL_27;
      }
    }
    else
    {
      if ( (_DWORD)v21 == 1 )
      {
        v30 = *(const void **)(a2 + 24);
        if ( v30 )
        {
          v31 = *(void **)(result + 7328);
          if ( *(unsigned __int16 *)(result + 7320) >= v22
            || (*(_WORD *)(result + 7320) = v22,
                v32 = result,
                _qdf_mem_free((__int64)v31),
                v31 = (void *)_qdf_mem_malloc(*(unsigned __int16 *)(v32 + 7320), "lim_update_add_ie_buffer", 10722),
                result = v32,
                (*(_QWORD *)(v32 + 7328) = v31) != 0) )
          {
            *(_WORD *)(result + 7320) = v22;
            qdf_mem_copy(v31, v30, v22);
          }
          else
          {
            *(_WORD *)(v32 + 7320) = 0;
          }
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: src buffer is null",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "lim_update_add_ie_buffer");
        }
        if ( *(_BYTE *)(a2 + 17) == 1 )
          lim_handle_param_update(a1, *(_DWORD *)(a2 + 32), v33, v34, v35, v36, v37, v38, v39, v40);
        goto LABEL_47;
      }
      if ( (_DWORD)v21 == 2 )
      {
        if ( *(_BYTE *)(a2 + 16) == 1 )
        {
          v23 = *(unsigned __int16 *)(result + 7288);
          if ( (v22 ^ 0xFFFF) >= v23 )
          {
            v54 = v23 + v22;
            v55 = result;
            v56 = (char *)_qdf_mem_malloc(v54, "lim_process_update_add_ies", 10907);
            if ( v56 )
            {
              v57 = *(const void **)(v55 + 7296);
              v58 = *(unsigned __int16 *)(v55 + 7288);
              v59 = v55;
              v60 = v56;
              qdf_mem_copy(v56, v57, v58);
              qdf_mem_copy(
                &v60[*(unsigned __int16 *)(v59 + 7288)],
                *(const void **)(a2 + 24),
                *(unsigned __int16 *)(a2 + 18));
              _qdf_mem_free(*(_QWORD *)(v59 + 7296));
              *(_WORD *)(v59 + 7288) = v54;
              *(_QWORD *)(v59 + 7296) = v60;
            }
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: IE Length overflow, curr:%d, new:%d",
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              "lim_process_update_add_ies");
          }
        }
        else
        {
          lim_update_add_ie_buffer(result + 7296, result + 7288, *(_QWORD *)(a2 + 24));
        }
        goto LABEL_47;
      }
    }
    v27 = "%s: unhandled buffer type %d";
    v28 = "lim_process_update_add_ies";
    v29 = 2;
LABEL_27:
    qdf_trace_msg(0x35u, v29, v27, v13, v14, v15, v16, v17, v18, v19, v20, v28, v21);
    goto LABEL_47;
  }
  if ( (int)v21 > 2 )
  {
    if ( (_DWORD)v21 == 3 )
    {
      v53 = result;
      result = _qdf_mem_free(*(_QWORD *)(result + 7312));
      *(_QWORD *)(v53 + 7312) = 0;
      *(_WORD *)(v53 + 7304) = 0;
    }
    else if ( (_DWORD)v21 == 4 )
    {
      *(_BYTE *)(result + 13280) = 0;
      result = sch_edca_profile_update(a1, result, 0);
    }
  }
  else if ( (_DWORD)v21 == 1 )
  {
    v44 = result;
    result = _qdf_mem_free(*(_QWORD *)(result + 7328));
    *(_QWORD *)(v44 + 7328) = 0;
    *(_WORD *)(v44 + 7320) = 0;
    if ( *(_BYTE *)(a2 + 17) == 1 )
      result = lim_handle_param_update(a1, *(_DWORD *)(a2 + 32), v45, v46, v47, v48, v49, v50, v51, v52);
  }
  else if ( (_DWORD)v21 == 2 )
  {
    v24 = result;
    result = _qdf_mem_free(*(_QWORD *)(result + 7296));
    *(_QWORD *)(v24 + 7296) = 0;
    *(_WORD *)(v24 + 7288) = 0;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
