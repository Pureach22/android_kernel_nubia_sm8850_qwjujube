__int64 __fastcall populate_dotf_tdls_vht_aid(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v17; // x0
  unsigned int v18; // w1
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int16 v52; // w8
  __int64 v53; // x4
  __int64 v54; // x5
  __int64 v55; // x6
  __int64 v56; // x7
  __int16 v57; // [xsp+Ch] [xbp-14h] BYREF
  int v58; // [xsp+10h] [xbp-10h] BYREF
  __int16 v59; // [xsp+14h] [xbp-Ch]
  __int64 v60; // [xsp+18h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)(a1 + 21560);
  v18 = *(_DWORD *)(a5 + 284);
  v58 = a3;
  v59 = WORD2(a3);
  result = wlan_reg_freq_to_chan(v17, v18, a6, a7, a8, a9, a10, a11, a12, a13);
  if ( (unsigned __int8)result <= 0xEu && (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2671LL) & 1) != 0
    || (result = wlan_reg_freq_to_chan(
                   *(_QWORD *)(a1 + 21560),
                   *(_DWORD *)(a5 + 284),
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27),
        (unsigned __int8)result >= 0xEu) )
  {
    if ( (unsigned int)(a2 - 8) < 6 || !a2 )
    {
      result = wma_get_fw_wlan_feat_caps(2);
      if ( (result & 1) != 0 )
      {
        v57 = 0;
        result = dph_lookup_hash_entry(
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   v43,
                   a1,
                   (unsigned __int8 *)&v58,
                   &v57,
                   a5 + 360);
        if ( result )
        {
          v52 = v57;
          *(_BYTE *)a4 = 1;
          *(_WORD *)(a4 + 2) = v52 | 0xC000;
        }
        else
        {
          v53 = (unsigned __int8)v58;
          v54 = BYTE1(v58);
          v55 = BYTE2(v58);
          v56 = HIBYTE(v59);
          *(_BYTE *)a4 = 0;
          result = qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: sta is NULL for %02x:%02x:%02x:**:**:%02x",
                     v44,
                     v45,
                     v46,
                     v47,
                     v48,
                     v49,
                     v50,
                     v51,
                     "populate_dotf_tdls_vht_aid",
                     v53,
                     v54,
                     v55,
                     v56);
        }
      }
    }
  }
  else
  {
    *(_BYTE *)a4 = 0;
    result = qdf_trace_msg(
               0x35u,
               3u,
               "%s: Vht not enable from ini for 2.4GHz",
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               "populate_dotf_tdls_vht_aid");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
