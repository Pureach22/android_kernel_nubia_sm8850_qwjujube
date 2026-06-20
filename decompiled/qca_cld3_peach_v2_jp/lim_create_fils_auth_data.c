__int64 __fastcall lim_create_fils_auth_data(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _WORD *a10,
        __int64 a11,
        _DWORD *a12,
        unsigned __int8 *a13)
{
  _QWORD *v16; // x0
  __int64 v17; // x24
  __int64 v18; // x0
  __int64 *v19; // x23
  __int64 v20; // x0
  __int64 *v21; // x20
  int v22; // w25
  __int64 v23; // x26
  int v24; // w21
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x22
  __int16 v35; // w8
  size_t v36; // x2
  _BYTE *v37; // x22
  void *v38; // x22
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w20
  __int64 result; // x0
  __int64 v58; // x1
  __int64 v59; // x2
  unsigned int v60; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v61[5]; // [xsp+8h] [xbp-28h] BYREF

  v61[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a13 && *(_DWORD *)(a11 + 88) == 1 )
  {
    v16 = lim_search_pre_auth_list(*(_QWORD *)(a11 + 8608), a13);
    if ( v16 )
    {
      v17 = v16[76];
      if ( !v17 )
        goto LABEL_20;
LABEL_7:
      v19 = (__int64 *)(v17 + 56);
      v18 = *(_QWORD *)(v17 + 56);
      if ( v18 )
      {
        _qdf_mem_free(v18);
        *v19 = 0;
      }
      v21 = (__int64 *)(v17 + 24);
      v20 = *(_QWORD *)(v17 + 24);
      if ( v20 )
      {
        _qdf_mem_free(v20);
        *v21 = 0;
      }
      if ( *a10 == 4 )
      {
        v22 = *(unsigned __int8 *)(v17 + 351);
        v23 = *(unsigned __int8 *)(v17 + 16);
        memset(v61, 0, 32);
        if ( (_DWORD)v23 && *(_BYTE *)(v17 + 48) )
        {
          v24 = v23 + 27;
          v25 = _qdf_mem_malloc(v23 + 27, "lim_create_fils_wrapper_data", 1181);
          *v21 = v25;
          if ( !v25 )
          {
LABEL_26:
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: failed to allocate wrapped data",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "lim_create_fils_auth_data");
            result = 16;
            goto LABEL_23;
          }
          *(_BYTE *)(v25 + 3) = v24;
          *(_WORD *)v25 = 5;
          v34 = v25 + 10;
          *(_BYTE *)(v25 + 2) = BYTE1(v24);
          *(_WORD *)(v25 + 4) = 8194;
          v35 = *(_WORD *)(v17 + 68);
          *(_BYTE *)(v25 + 7) = v35;
          *(_BYTE *)(v25 + 8) = 1;
          *(_BYTE *)(v25 + 6) = HIBYTE(v35);
          v36 = *(unsigned __int8 *)(v17 + 16);
          *(_BYTE *)(v25 + 9) = v36;
          qdf_mem_copy((void *)(v25 + 10), *(const void **)(v17 + 8), v36);
          v37 = (_BYTE *)(v34 + *(unsigned __int8 *)(v17 + 16));
          *v37 = 2;
          v38 = v37 + 1;
          v39 = _qdf_mem_malloc(*(unsigned __int8 *)(v17 + 48), "lim_create_fils_wrapper_data", 1231);
          *(_QWORD *)(v17 + 56) = v39;
          if ( !v39 )
          {
            _qdf_mem_free(*v21);
            goto LABEL_25;
          }
          if ( (unsigned int)wlan_crypto_create_fils_rik(
                               *(_QWORD *)(v17 + 40),
                               *(_BYTE *)(v17 + 48),
                               v39,
                               (_DWORD *)(v17 + 64),
                               v40,
                               v41,
                               v42,
                               v43,
                               v44,
                               v45,
                               v46,
                               v47) )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: RIK create fails",
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              "lim_create_fils_wrapper_data");
            _qdf_mem_free(*v21);
            _qdf_mem_free(*v19);
            *v21 = 0;
            v21 = (__int64 *)(v17 + 56);
LABEL_25:
            *v21 = 0;
            goto LABEL_26;
          }
          v58 = *(_QWORD *)(v17 + 56);
          v59 = *(unsigned int *)(v17 + 64);
          *(_DWORD *)(v17 + 32) = v24;
          v60 = v23 + 11;
          qdf_get_hmac_hash((__int64)"hmac(sha256)", v58, v59, 1u, v17 + 24, &v60);
          qdf_mem_copy(v38, v61, 0x10u);
          v56 = v22 + v24 + 33;
        }
        else
        {
          v56 = v22 + 30;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: FILS_PMKSA: NO keyname nai/RRK configured. Use PMKSA caching",
            a1,
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            "lim_create_fils_wrapper_data");
        }
      }
      else
      {
        v56 = 0;
      }
      result = 0;
      *a12 += v56;
      goto LABEL_23;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: No preauth node created for %02x:%02x:%02x:**:**:%02x",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "lim_get_fils_info",
      *a13,
      a13[1],
      a13[2],
      a13[5]);
  }
  else
  {
    v17 = *(_QWORD *)(a11 + 9976);
    if ( v17 )
      goto LABEL_7;
  }
LABEL_20:
  qdf_trace_msg(0x35u, 2u, "%s: Failed to get fils_info", a1, a2, a3, a4, a5, a6, a7, a8, "lim_create_fils_auth_data");
  result = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
