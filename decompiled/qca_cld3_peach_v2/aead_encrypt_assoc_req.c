__int64 __fastcall aead_encrypt_assoc_req(
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
        int *a12)
{
  unsigned __int8 *v12; // x9
  int v13; // w8
  __int64 v14; // x19
  __int64 v15; // x25
  __int64 v16; // x10
  unsigned int v17; // w11
  unsigned __int64 v18; // x21
  unsigned __int8 *v19; // x9
  __int64 v20; // x27
  __int64 v21; // x26
  __int64 v22; // x24
  __int64 v23; // x23
  void *v24; // x20
  void *v26; // x0
  __int64 v27; // x22
  __int64 v28; // x25
  unsigned __int64 v29; // x21
  const char *v30; // x2
  __int64 result; // x0
  int v32; // w19
  unsigned __int8 *v34; // [xsp+20h] [xbp-90h]
  __int64 v35; // [xsp+28h] [xbp-88h]
  _QWORD v36[6]; // [xsp+30h] [xbp-80h] BYREF
  _QWORD v37[6]; // [xsp+60h] [xbp-50h] BYREF
  __int64 v38; // [xsp+90h] [xbp-20h] BYREF
  __int64 v39; // [xsp+98h] [xbp-18h]
  __int64 v40; // [xsp+A0h] [xbp-10h]

  v12 = (unsigned __int8 *)(a11 + 28);
  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a11 == -28 || (v13 = *a12, LODWORD(v14) = *a12 - 4, (unsigned int)v14 < 2) )
  {
LABEL_19:
    v30 = "%s: Could not find FILS session IE";
LABEL_20:
    qdf_trace_msg(0x35u, 2u, v30, a1, a2, a3, a4, a5, a6, a7, a8, "aead_encrypt_assoc_req");
    result = 16;
  }
  else
  {
    v15 = *(_QWORD *)(a10 + 9976);
    while ( 1 )
    {
      v16 = v12[1];
      v17 = v14 - 2;
      v14 = (unsigned int)(v14 - 2 - v16);
      if ( v17 < (unsigned int)v16 )
        goto LABEL_19;
      if ( v17 >= 3 && *v12 == 255 && v12[2] == 4 )
        break;
      v12 += v16 + 2;
      if ( (unsigned int)v14 <= 1 )
        goto LABEL_19;
    }
    v18 = *(unsigned __int8 *)(v15 + 889);
    v38 = 0;
    v39 = 0;
    if ( (unsigned int)(v18 - 32) > 0x20 || ((1LL << ((unsigned __int8)v18 - 32)) & 0x100010001LL) == 0 )
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
        "fils_aead_encrypt",
        (unsigned int)v18);
      goto LABEL_24;
    }
    v19 = &v12[(unsigned int)v16];
    v20 = a10 + 30;
    v21 = a10 + 24;
    v22 = v15 + 78;
    v23 = v15 + 758;
    v24 = v19 + 2;
    if ( v19 == (unsigned __int8 *)-2LL || v17 == (_DWORD)v16 || v15 == -758 || v15 == -78 || v13 == (_DWORD)v14 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Error missing params mac:%pK bssid:%pK snonce:%pK anonce:%pK data_len:%zu plain_text_len:%zu out:%pK",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "fils_aead_encrypt",
        v20,
        v21,
        v15 + 78,
        v15 + 758,
        (unsigned int)(v13 - v14),
        v17 - (unsigned int)v16,
        v19 + 2);
      goto LABEL_24;
    }
    v34 = v19;
    v35 = (unsigned int)(v13 - v14);
    v26 = (void *)_qdf_mem_malloc(v17 - (unsigned int)v16, "fils_aead_encrypt", 2564);
    if ( !v26 )
    {
LABEL_24:
      v30 = "%s: AEAD Encryption fails!";
      goto LABEL_20;
    }
    v27 = (__int64)v26;
    v28 = v15 + 825;
    qdf_mem_copy(v26, v24, (unsigned int)v14);
    v29 = v18 >> 1;
    v36[0] = 6;
    v36[1] = 6;
    v36[2] = 16;
    v36[3] = 16;
    v37[0] = v20;
    v37[1] = v21;
    v37[2] = v22;
    v37[3] = v23;
    v37[4] = a11 + 24;
    v37[5] = v27;
    v36[4] = v35;
    v36[5] = v14;
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD *, _QWORD *, __int64, __int64 *))qdf_aes_s2v)(
                         v28,
                         (unsigned int)v29,
                         v37,
                         v36,
                         6,
                         &v38) )
    {
      _qdf_mem_free(v27);
      goto LABEL_24;
    }
    qdf_mem_copy(v24, &v38, 0x10u);
    BYTE4(v39) &= ~0x80u;
    LOBYTE(v39) = v39 & 0x7F;
    v32 = qdf_aes_ctr(v28 + v29, v29, (__int64)&v38, v27, v14, (__int64)(v34 + 18), 1);
    _qdf_mem_free(v27);
    if ( v32 )
      goto LABEL_24;
    result = 0;
    *a12 += 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
