__int64 __fastcall aead_decrypt_assoc_rsp(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        int *a13)
{
  int v13; // w8
  const char *v14; // x2
  unsigned int v15; // w1
  unsigned __int8 *v16; // x9
  __int64 v17; // x25
  __int64 v18; // x27
  __int64 v19; // x10
  unsigned int v20; // w11
  unsigned __int64 v21; // x23
  unsigned __int8 *v22; // x28
  __int64 v23; // x21
  __int64 v24; // x24
  __int64 v25; // x20
  __int64 v26; // x22
  __int64 v27; // x26
  void *v28; // x0
  __int64 v29; // x25
  __int64 v30; // x27
  unsigned __int64 v31; // x23
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 result; // x0
  __int64 v43; // [xsp+20h] [xbp-A0h]
  __int64 v45; // [xsp+30h] [xbp-90h] BYREF
  __int64 v46; // [xsp+38h] [xbp-88h]
  __int64 v47; // [xsp+40h] [xbp-80h] BYREF
  __int64 v48; // [xsp+48h] [xbp-78h]
  __int64 v49; // [xsp+50h] [xbp-70h] BYREF
  __int64 v50; // [xsp+58h] [xbp-68h]
  __int64 v51; // [xsp+60h] [xbp-60h]
  __int64 v52; // [xsp+68h] [xbp-58h]
  __int64 v53; // [xsp+70h] [xbp-50h]
  __int64 v54; // [xsp+78h] [xbp-48h]
  __int64 v55; // [xsp+80h] [xbp-40h] BYREF
  __int64 v56; // [xsp+88h] [xbp-38h]
  __int64 v57; // [xsp+90h] [xbp-30h]
  __int64 v58; // [xsp+98h] [xbp-28h]
  __int64 v59; // [xsp+A0h] [xbp-20h]
  unsigned __int8 *v60; // [xsp+A8h] [xbp-18h]
  __int64 v61; // [xsp+B0h] [xbp-10h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *a13;
  if ( (unsigned int)*a13 > 5 )
  {
    v16 = (unsigned __int8 *)(a12 + 6);
    if ( a12 != -6 )
    {
      LODWORD(v17) = v13 - 6;
      if ( (unsigned int)(v13 - 6) >= 2 )
      {
        v18 = *(_QWORD *)(a10 + 9976);
        while ( 1 )
        {
          v19 = v16[1];
          v20 = v17 - 2;
          v17 = (unsigned int)(v17 - 2 - v19);
          if ( v20 < (unsigned int)v19 )
            goto LABEL_27;
          if ( v20 >= 3 && *v16 == 255 && v16[2] == 4 )
            break;
          v16 += v19 + 2;
          if ( (unsigned int)v17 <= 1 )
            goto LABEL_27;
        }
        v21 = *(unsigned __int8 *)(v18 + 889);
        v59 = 0;
        v60 = nullptr;
        v57 = 0;
        v58 = 0;
        v55 = 0;
        v56 = 0;
        v53 = 0;
        v54 = 0;
        v51 = 0;
        v52 = 0;
        v49 = 0;
        v50 = 0;
        v47 = 0;
        v48 = 0;
        v45 = 0;
        v46 = 0;
        if ( (unsigned int)(v21 - 32) <= 0x20 && ((1LL << ((unsigned __int8)v21 - 32)) & 0x100010001LL) != 0 )
        {
          v22 = &v16[(unsigned int)v19];
          v23 = a10 + 30;
          v24 = a10 + 24;
          v25 = v18 + 78;
          v26 = v18 + 758;
          if ( v22 == (unsigned __int8 *)-2LL
            || (unsigned int)v17 < 0x10
            || v18 == -758
            || v18 == -78
            || v13 == (_DWORD)v17 )
          {
            qdf_trace_msg(
              0x38u,
              2u,
              "%s: Error missing params mac:%pK bssid:%pK snonce:%pK anonce:%pK data_len:%zu ciphered_text_len:%zu plain_text:%pK",
              a1,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              "fils_aead_decrypt",
              v23,
              v24,
              v18 + 78,
              v18 + 758,
              (unsigned int)(v13 - v17),
              v17,
              v22 + 2);
          }
          else
          {
            v43 = (unsigned int)(v13 - v17);
            qdf_mem_copy(&v47, v22 + 2, 0x10u);
            qdf_mem_copy(&v45, v22 + 2, 0x10u);
            v27 = v17 - 16;
            BYTE4(v48) &= ~0x80u;
            LOBYTE(v48) = v48 & 0x7F;
            v28 = (void *)_qdf_mem_malloc(v17 - 16, "fils_aead_decrypt", 2787);
            if ( v28 )
            {
              v29 = (__int64)v28;
              v30 = v18 + 825;
              qdf_mem_copy(v28, v22 + 18, (unsigned int)v27);
              v31 = v21 >> 1;
              if ( !(unsigned int)qdf_aes_ctr(v30 + v31, v31, (__int64)&v47, v29, v27, (__int64)(v22 + 2), 0) )
              {
                v49 = 6;
                v50 = 6;
                v51 = 16;
                v52 = 16;
                v55 = v24;
                v56 = v23;
                v57 = v26;
                v58 = v25;
                v59 = a12;
                v60 = v22 + 2;
                v53 = v43;
                v54 = v27;
                if ( !(unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, __int64 *, __int64 *, __int64, __int64 *))qdf_aes_s2v)(
                                      v30,
                                      (unsigned int)v31,
                                      &v55,
                                      &v49,
                                      6,
                                      &v47) )
                {
                  if ( v47 == v45 && v48 == v46 )
                  {
                    _qdf_mem_free(v29);
                    result = 0;
                    *a13 -= 16;
                    goto LABEL_30;
                  }
                  qdf_trace_msg(
                    0x38u,
                    2u,
                    "%s: siv not same as frame siv",
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    v39,
                    "fils_aead_decrypt");
                }
              }
              _qdf_mem_free(v29);
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: Invalid key length: %u",
            a1,
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            "fils_aead_decrypt",
            (unsigned int)v21);
        }
        v14 = "%s: AEAD decryption fails";
        goto LABEL_28;
      }
    }
LABEL_27:
    v14 = "%s: FILS session IE not present";
LABEL_28:
    v15 = 2;
  }
  else
  {
    v14 = "%s: payload len is less than ASSOC RES offset";
    v15 = 8;
  }
  qdf_trace_msg(0x35u, v15, v14, a1, a2, a3, a4, a5, a6, a7, a8, "aead_decrypt_assoc_rsp");
  result = 16;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
