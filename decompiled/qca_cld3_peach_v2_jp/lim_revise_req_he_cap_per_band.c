__int64 __fastcall lim_revise_req_he_cap_per_band(
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
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x20
  __int64 v15; // x22
  unsigned int v16; // w21
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x11
  unsigned __int64 *v27; // x12
  unsigned int v28; // w8
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x11
  __int64 result; // x0
  _QWORD *v32; // x9
  unsigned __int64 *v33; // x8
  unsigned __int64 v34; // x10
  unsigned int v35; // w13
  unsigned __int64 *v36; // x12
  bool v37; // zf
  unsigned __int64 v38; // x13
  unsigned __int64 v39; // x10
  unsigned __int64 v40; // x10
  unsigned __int64 v41; // x10
  unsigned __int64 v42; // x10
  unsigned __int64 v43; // x10
  unsigned __int64 v44; // x10
  unsigned __int64 v45; // x10
  __int64 v46; // x9
  __int64 v47; // x10
  int v48; // w8
  __int64 v49; // x8
  __int64 v50; // x8
  _QWORD v51[7]; // [xsp+8h] [xbp-48h] BYREF
  int v52; // [xsp+40h] [xbp-10h]
  __int64 v53; // [xsp+48h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 152LL);
  if ( v10 && (v11 = *(_QWORD *)(v10 + 80)) != 0 )
  {
    v12 = a1 + 20480;
    v15 = *(_QWORD *)(a2 + 8608) + 20480LL;
    v16 = *(_DWORD *)(cfg_psoc_get_values(v11) + 7548);
    v17 = a1 + 23896;
    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284)) )
    {
      v26 = *(_QWORD *)(v12 + 3417);
      v27 = (unsigned __int64 *)(v12 + 3425);
      *(_WORD *)(v12 + 3438) = *(_WORD *)(v15 + 1258);
      *(_WORD *)(v12 + 3436) = *(_WORD *)(v15 + 1256);
      v28 = (*(_DWORD *)(v15 + 1237) >> 27) & 3;
      if ( v16 < v28 )
        v28 = v16 & 3;
      v29 = v26 & 0xFFFFEFFFE7FFFFFFLL;
      v30 = *v27;
      *(_QWORD *)(v12 + 3417) = v29 | (v28 << 27);
      *v27 = v30 & 0xFF99FFFE3FFFFFFFLL;
    }
    else
    {
      v32 = (_QWORD *)(v15 + 1305);
      *(_WORD *)(v12 + 3438) = *(_WORD *)(v15 + 1318);
      *(_WORD *)(v12 + 3436) = *(_WORD *)(v15 + 1316);
      v33 = (unsigned __int64 *)(v12 + 3425);
      v34 = *(_QWORD *)(v12 + 3425) & 0xFFFFFFFFC7FFFFFFLL | (((*(_QWORD *)(v15 + 1305) >> 27) & 7LL) << 27);
      *(_QWORD *)(v12 + 3425) = v34;
      v35 = (*(_DWORD *)(v15 + 1297) >> 27) & 3;
      v36 = (unsigned __int64 *)(v12 + 3417);
      if ( v16 < v35 )
        v35 = v16 & 3;
      v37 = (*v36 & 0x30000000000000LL) == 0;
      v38 = *v36 & 0xFFFFFFFFE7FFFFFFLL | (v35 << 27);
      *v36 = v38;
      if ( !v37 )
      {
        v39 = v34 & 0xFFFFFFFE3FFFFFFFLL | (((*v32 >> 30) & 7LL) << 30);
        *v33 = v39;
        v40 = v39 & 0xFFDFFFFFFFFFFFFFLL | (((*v32 >> 53) & 1LL) << 53);
        *v33 = v40;
        v41 = v40 & 0xFFBFFFFFFFFFFFFFLL | (((*v32 >> 54) & 1LL) << 54);
        *v33 = v41;
        v42 = v41 & 0xFFFBFFFFFFFFFFFFLL | (((*v32 >> 50) & 1LL) << 50);
        *v33 = v42;
        v34 = v42 & 0xFFFDFFFFFFFFFFFFLL | (((*v32 >> 49) & 1LL) << 49);
        *v33 = v34;
        *v36 = v38 & 0xFFFFEFFFFFFFFFFFLL | (((*(_QWORD *)(v15 + 1297) >> 44) & 1LL) << 44);
      }
      v43 = v34 & 0xFFFFFFFDFFFFFFFFLL | (((*v32 >> 33) & 1LL) << 33);
      *v33 = v43;
      v44 = v43 & 0xFFFFFFFBFFFFFFFFLL | (((*v32 >> 34) & 1LL) << 34);
      *v33 = v44;
      v45 = v44 & 0xFFFFFFF7FFFFFFFFLL | (((*v32 >> 35) & 1LL) << 35);
      *v33 = v45;
      *v33 = v45 & 0xFFFFFFEFFFFFFFFFLL | (((*v32 >> 36) & 1LL) << 36);
    }
    v46 = *(_QWORD *)(v17 + 40);
    v47 = *(_QWORD *)(v17 + 48);
    v51[4] = *(_QWORD *)(v17 + 32);
    v51[5] = v46;
    v48 = *(_DWORD *)(v17 + 56);
    v51[6] = v47;
    v52 = v48;
    v49 = *(_QWORD *)(v17 + 8);
    v51[0] = *(_QWORD *)v17;
    v51[1] = v49;
    v50 = *(_QWORD *)(v17 + 24);
    v51[2] = *(_QWORD *)(v17 + 16);
    v51[3] = v50;
    qdf_trace_msg(0x35u, 8u, "%s: he_config: 0x", v18, v19, v20, v21, v22, v23, v24, v25, "lim_print_he_config");
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))qdf_trace_hex_dump)(53, 8, v51, 60);
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Failed to get psoc",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_revise_req_he_cap_per_band");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
