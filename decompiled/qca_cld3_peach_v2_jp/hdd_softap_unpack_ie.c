__int64 __fastcall hdd_softap_unpack_ie(
        __int64 a1,
        _DWORD *a2,
        _DWORD *a3,
        unsigned int *a4,
        _BYTE *a5,
        bool *a6,
        __int64 a7,
        unsigned __int8 *a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  __int64 result; // x0
  int v17; // w8
  unsigned int *v18; // x23
  _DWORD *v19; // x22
  _DWORD *v20; // x21
  _BYTE *v21; // x20
  bool *v22; // x19
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w0
  unsigned int v33; // w9
  unsigned int *v34; // x8
  unsigned int v35; // w0
  unsigned int v36; // w0
  unsigned int v37; // w0
  unsigned int v38; // w0
  unsigned int v39; // w0
  unsigned int v40; // w0
  unsigned int v41; // w0
  unsigned int v42; // w0
  unsigned int v43; // w0
  unsigned int v44; // w9
  unsigned int *v45; // x8
  unsigned int v46; // w0
  unsigned int v47; // w0
  unsigned int v48; // w0
  unsigned int v49; // w0
  unsigned int v50; // w0
  unsigned int v51; // w9
  unsigned int *v52; // x8
  unsigned int v53; // w0
  unsigned int v54; // w0
  unsigned int v55; // w0
  unsigned int v56; // w0
  int v57; // w0
  unsigned int v58; // w9
  int v59; // w8
  int v60; // w0
  int v61; // w8
  __int64 v62; // [xsp+0h] [xbp-140h] BYREF
  __int64 v63; // [xsp+8h] [xbp-138h] BYREF
  __int64 v64; // [xsp+10h] [xbp-130h] BYREF
  __int64 v65; // [xsp+18h] [xbp-128h] BYREF
  __int64 v66; // [xsp+20h] [xbp-120h]
  __int64 v67; // [xsp+28h] [xbp-118h] BYREF
  __int64 v68; // [xsp+30h] [xbp-110h]
  __int64 v69; // [xsp+38h] [xbp-108h]
  __int64 v70; // [xsp+40h] [xbp-100h]
  __int64 v71; // [xsp+48h] [xbp-F8h]
  __int64 v72; // [xsp+50h] [xbp-F0h]
  __int64 v73; // [xsp+58h] [xbp-E8h]
  __int64 v74; // [xsp+60h] [xbp-E0h]
  __int64 v75; // [xsp+68h] [xbp-D8h]
  __int64 v76; // [xsp+70h] [xbp-D0h] BYREF
  __int64 v77; // [xsp+78h] [xbp-C8h] BYREF
  __int64 v78; // [xsp+80h] [xbp-C0h]
  __int64 v79; // [xsp+88h] [xbp-B8h] BYREF
  __int64 v80; // [xsp+90h] [xbp-B0h] BYREF
  __int64 v81; // [xsp+98h] [xbp-A8h] BYREF
  __int64 v82; // [xsp+A0h] [xbp-A0h] BYREF
  __int64 v83; // [xsp+A8h] [xbp-98h] BYREF
  __int64 v84; // [xsp+B0h] [xbp-90h]
  __int64 v85; // [xsp+B8h] [xbp-88h]
  __int64 v86; // [xsp+C0h] [xbp-80h] BYREF
  __int64 v87; // [xsp+C8h] [xbp-78h] BYREF
  __int64 v88; // [xsp+D0h] [xbp-70h] BYREF
  __int64 v89; // [xsp+D8h] [xbp-68h] BYREF
  __int64 v90; // [xsp+E0h] [xbp-60h] BYREF
  __int64 v91; // [xsp+E8h] [xbp-58h]
  __int64 v92; // [xsp+F0h] [xbp-50h]
  __int64 v93; // [xsp+F8h] [xbp-48h]
  __int64 v94; // [xsp+100h] [xbp-40h]
  __int64 v95; // [xsp+108h] [xbp-38h]
  __int64 v96; // [xsp+110h] [xbp-30h]
  __int64 v97; // [xsp+118h] [xbp-28h]
  __int64 v98; // [xsp+120h] [xbp-20h]
  __int64 v99; // [xsp+128h] [xbp-18h]
  __int64 v100; // [xsp+130h] [xbp-10h]
  __int64 v101; // [xsp+138h] [xbp-8h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOWORD(v100) = 0;
  v98 = 0;
  v99 = 0;
  v96 = 0;
  v97 = 0;
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: NULL mac Handle",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "hdd_softap_unpack_ie",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101);
    result = 4294967274LL;
    goto LABEL_34;
  }
  if ( (unsigned __int16)a7 <= 0x8Au )
  {
    v17 = *a8;
    switch ( v17 )
    {
      case 221:
        if ( (unsigned __int16)(a7 - 49) < 0xFFD5u )
          goto LABEL_33;
        v18 = a4;
        v19 = a2;
        v20 = a3;
        v21 = a5;
        v22 = a6;
        v80 = 0;
        v81 = 0;
        v78 = 0;
        v79 = 0;
        v76 = 0;
        v77 = 0;
        v23 = ((__int64 (__fastcall *)(__int64, unsigned __int8 *, _QWORD, __int64 *, _QWORD, bool *, __int64, unsigned __int8 *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))dot11f_unpack_ie_wpa)(
                a1,
                a8 + 6,
                (unsigned int)(a7 - 6),
                &v76,
                0,
                a6,
                a7,
                a8,
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75);
        if ( v23 )
          goto LABEL_31;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: WPA unicast cipher suite count: %d akm count: %d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "hdd_softap_unpack_ie",
          WORD1(v77),
          WORD2(v79));
        if ( WORD2(v79) )
        {
          v50 = hdd_translate_wpa_to_csr_auth_type((int *)((char *)&v79 + 6));
          v51 = WORD2(v79);
          v52 = v18;
          v18[1] = v50;
          if ( v51 >= 2 )
          {
            v53 = hdd_translate_wpa_to_csr_auth_type((int *)((char *)&v80 + 2));
            v51 = WORD2(v79);
            v52 = v18;
            v18[2] = v53;
            if ( v51 >= 3 )
            {
              v54 = hdd_translate_wpa_to_csr_auth_type((int *)((char *)&v80 + 6));
              v51 = WORD2(v79);
              v52 = v18;
              v18[3] = v54;
              if ( v51 >= 4 )
              {
                v55 = hdd_translate_wpa_to_csr_auth_type((int *)((char *)&v81 + 2));
                v51 = WORD2(v79);
                v52 = v18;
                v18[4] = v55;
                if ( v51 >= 5 )
                {
                  v56 = hdd_translate_wpa_to_csr_auth_type((int *)((char *)&v81 + 6));
                  v51 = WORD2(v79);
                  v52 = v18;
                  v18[5] = v56;
                  if ( v51 > 5 )
                    goto LABEL_41;
                }
              }
            }
          }
        }
        else
        {
          v51 = 0;
          v52 = v18;
        }
        *v52 = v51;
        *v19 = hdd_translate_wpa_to_csr_encryption_type((_DWORD *)&v77 + 1);
        v60 = hdd_translate_wpa_to_csr_encryption_type((__int64 *)((char *)&v76 + 5));
        break;
      case 68:
        if ( (unsigned __int16)(a7 - 111) < 0xFF9Du )
          goto LABEL_33;
        v18 = a4;
        v19 = a2;
        v20 = a3;
        v21 = a5;
        v22 = a6;
        v66 = 0;
        v67 = 0;
        v64 = 0;
        v65 = 0;
        v62 = 0;
        v63 = 0;
        v23 = ((__int64 (__fastcall *)(__int64, unsigned __int8 *, _QWORD, __int64 *, _QWORD, bool *, __int64, unsigned __int8 *))dot11f_unpack_ie_wapi)(
                a1,
                a8 + 2,
                (unsigned int)(a7 - 2),
                &v62,
                0,
                a6,
                a7,
                a8);
        if ( v23 )
          goto LABEL_31;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: WAPI unicast cipher suite count: %d akm count: %d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "hdd_softap_unpack_ie",
          HIWORD(v64),
          WORD2(v62));
        if ( WORD2(v62) )
        {
          v43 = hdd_translate_wapi_to_csr_auth_type((__int64 *)((char *)&v62 + 6));
          v44 = WORD2(v62);
          v45 = v18;
          v18[1] = v43;
          if ( v44 >= 2 )
          {
            v46 = hdd_translate_wapi_to_csr_auth_type((__int64 *)((char *)&v63 + 2));
            v44 = WORD2(v62);
            v45 = v18;
            v18[2] = v46;
            if ( v44 >= 3 )
            {
              v47 = hdd_translate_wapi_to_csr_auth_type((__int64 *)((char *)&v63 + 6));
              v44 = WORD2(v62);
              v45 = v18;
              v18[3] = v47;
              if ( v44 >= 4 )
              {
                v48 = hdd_translate_wapi_to_csr_auth_type((__int64 *)((char *)&v64 + 2));
                v44 = WORD2(v62);
                v45 = v18;
                v18[4] = v48;
                if ( v44 >= 5 )
                {
                  v49 = hdd_translate_wapi_to_csr_auth_type((__int64 *)((char *)&v64 + 6));
                  v44 = WORD2(v62);
                  v45 = v18;
                  v18[5] = v49;
                  if ( v44 > 5 )
                    goto LABEL_41;
                }
              }
            }
          }
        }
        else
        {
          v44 = 0;
          v45 = v18;
        }
        *v45 = v44;
        *v19 = hdd_translate_wapi_to_csr_encryption_type((int *)&v65);
        v60 = hdd_translate_wapi_to_csr_encryption_type((int *)&v67);
        break;
      case 48:
        v18 = a4;
        v19 = a2;
        v20 = a3;
        v21 = a5;
        v22 = a6;
        LOWORD(v100) = 0;
        v98 = 0;
        v99 = 0;
        v96 = 0;
        v97 = 0;
        v94 = 0;
        v95 = 0;
        v92 = 0;
        v93 = 0;
        v90 = 0;
        v91 = 0;
        v88 = 0;
        v89 = 0;
        v86 = 0;
        v87 = 0;
        v84 = 0;
        v85 = 0;
        v82 = 0;
        v83 = 0;
        v23 = ((__int64 (__fastcall *)(__int64, unsigned __int8 *, _QWORD, __int64 *, _QWORD, bool *, __int64, unsigned __int8 *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))sme_unpack_rsn_ie)(
                a1,
                a8 + 2,
                (unsigned int)(a7 - 2),
                &v82,
                0,
                a6,
                a7,
                a8,
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                v81);
        if ( !v23 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: pairwise cipher count: %d akm count:%d",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "hdd_softap_unpack_ie",
            WORD1(v83),
            WORD2(v86));
          if ( !WORD2(v86) )
          {
LABEL_42:
            v33 = 0;
            v34 = v18;
LABEL_43:
            *v34 = v33;
            *v19 = hdd_translate_rsn_to_csr_encryption_type((_DWORD *)&v83 + 1);
            v57 = hdd_translate_rsn_to_csr_encryption_type((__int64 *)((char *)&v82 + 5));
            v58 = HIBYTE(v90);
            v59 = v57;
            result = 0;
            *v20 = v59;
            *v21 = v58 >> 7;
            *v22 = (v58 & 0x40) != 0;
            goto LABEL_34;
          }
          v32 = hdd_translate_rsn_to_csr_auth_type((int *)((char *)&v86 + 6));
          v33 = WORD2(v86);
          v34 = v18;
          v18[1] = v32;
          if ( v33 <= 1 )
            goto LABEL_43;
          v35 = hdd_translate_rsn_to_csr_auth_type((int *)((char *)&v87 + 2));
          v33 = WORD2(v86);
          v34 = v18;
          v18[2] = v35;
          if ( v33 < 3 )
            goto LABEL_43;
          v36 = hdd_translate_rsn_to_csr_auth_type((int *)((char *)&v87 + 6));
          v33 = WORD2(v86);
          v34 = v18;
          v18[3] = v36;
          if ( v33 < 4 )
            goto LABEL_43;
          v37 = hdd_translate_rsn_to_csr_auth_type((int *)((char *)&v88 + 2));
          v33 = WORD2(v86);
          v34 = v18;
          v18[4] = v37;
          if ( v33 < 5 )
            goto LABEL_43;
          v38 = hdd_translate_rsn_to_csr_auth_type((int *)((char *)&v88 + 6));
          v33 = WORD2(v86);
          v34 = v18;
          v18[5] = v38;
          if ( v33 < 6 )
            goto LABEL_43;
          v39 = hdd_translate_rsn_to_csr_auth_type((int *)((char *)&v89 + 2));
          v33 = WORD2(v86);
          v34 = v18;
          v18[6] = v39;
          if ( v33 < 7 )
            goto LABEL_43;
          v40 = hdd_translate_rsn_to_csr_auth_type((int *)((char *)&v89 + 6));
          v33 = WORD2(v86);
          v34 = v18;
          v18[7] = v40;
          if ( v33 < 8 )
            goto LABEL_43;
          v41 = hdd_translate_rsn_to_csr_auth_type((int *)((char *)&v90 + 2));
          v33 = WORD2(v86);
          v34 = v18;
          v18[8] = v41;
          if ( v33 < 9 )
            goto LABEL_43;
          v42 = hdd_translate_rsn_to_csr_auth_type((int *)((char *)&v90 + 6));
          v33 = WORD2(v86);
          v34 = v18;
          v18[9] = v42;
          if ( v33 <= 9 )
            goto LABEL_43;
LABEL_41:
          __break(0x5512u);
          goto LABEL_42;
        }
LABEL_31:
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: unpack failed, 0x%x",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "hdd_softap_unpack_ie",
          v23);
        result = 4294967274LL;
        goto LABEL_34;
      default:
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: gen_ie[0]: %d",
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          a15,
          a16,
          "hdd_softap_unpack_ie",
          *a8,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          v101);
LABEL_33:
        result = 16;
        goto LABEL_34;
    }
    v61 = v60;
    result = 0;
    *v20 = v61;
    *v21 = 0;
    *v22 = 0;
    goto LABEL_34;
  }
  result = 4294967274LL;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
