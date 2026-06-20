__int64 __fastcall sch_set_default_edca_params(
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
  __int64 v10; // x22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  _DWORD *v22; // x23
  int v23; // w2
  int v24; // w9
  int v25; // w10
  int v26; // w8
  int v27; // w9
  int v28; // w8
  int v29; // w10
  int v30; // w8
  int v31; // w9
  int v32; // w8
  int v33; // w10
  int v34; // w8
  int v35; // w9
  int v36; // w8
  int v37; // w10
  int v38; // w8
  int v39; // w9
  __int64 result; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  _BYTE v49[272]; // [xsp+0h] [xbp-130h] BYREF
  __int64 v50; // [xsp+110h] [xbp-20h] BYREF
  __int64 v51; // [xsp+118h] [xbp-18h]
  unsigned __int8 v52; // [xsp+120h] [xbp-10h]
  __int64 v53; // [xsp+128h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 8);
  if ( v10 )
  {
    memset(v49, 0, sizeof(v49));
    v21 = 0;
    v22 = &v49[32];
    while ( 1 )
    {
      v52 = 0;
      v23 = dp_getmodulation__he_bw_mod[4 * v21];
      v50 = 0;
      v51 = 0;
      if ( (unsigned int)wlan_mlme_get_edca_params(
                           (unsigned int *)(v10 + 16),
                           &v50,
                           v23,
                           v13,
                           v14,
                           v15,
                           v16,
                           v17,
                           v18,
                           v19,
                           v20) )
        break;
      v24 = BYTE1(v50);
      ++v21;
      v25 = BYTE2(v50);
      *(v22 - 8) = (unsigned __int8)v50;
      *(v22 - 7) = v24;
      v26 = BYTE3(v50);
      v27 = BYTE4(v50);
      *(v22 - 6) = v25;
      *(v22 - 5) = v26;
      v28 = BYTE5(v50);
      v29 = BYTE6(v50);
      *(v22 - 4) = v27;
      *(v22 - 3) = v28;
      v30 = HIBYTE(v50);
      v31 = (unsigned __int8)v51;
      *(v22 - 2) = v29;
      *(v22 - 1) = v30;
      v32 = BYTE1(v51);
      v33 = BYTE2(v51);
      *v22 = v31;
      v22[1] = v32;
      v34 = BYTE3(v51);
      v35 = BYTE4(v51);
      v22[2] = v33;
      v22[3] = v34;
      v36 = BYTE5(v51);
      v37 = BYTE6(v51);
      v22[4] = v35;
      v22[5] = v36;
      v38 = HIBYTE(v51);
      v39 = v52;
      v22[6] = v37;
      v22[7] = v38;
      v22[8] = v39;
      v22 += 17;
      if ( v21 == 4 )
      {
        result = set_sch_edca_params(a1, (__int64)v49, a2);
        goto LABEL_9;
      }
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Get failed for ac:[%d]",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "get_wmm_local_params",
      (unsigned int)v21);
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: NULL mlme cfg", a3, a4, a5, a6, a7, a8, a9, a10, "get_wmm_local_params");
  }
  result = qdf_trace_msg(
             0x35u,
             2u,
             "%s: get_wmm_local_params() failed",
             v41,
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             v48,
             "sch_set_default_edca_params");
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
