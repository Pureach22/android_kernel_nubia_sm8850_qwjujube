__int64 __fastcall hdd_update_wiphy_he_cap(__int64 *a1)
{
  __int64 v2; // x8
  __int64 v3; // x22
  __int64 v4; // x23
  __int64 v5; // x25
  unsigned __int8 vht_ch_width; // w20
  __int64 v7; // x21
  __int64 v8; // x24
  __int64 v9; // x0
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _WORD *v19; // x8
  char v20; // w8
  _WORD *v21; // x8
  char v22; // w9
  char v23; // w8
  __int64 v24; // x21
  __int64 v25; // x20
  unsigned __int8 v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  char *v35; // x8
  char v36; // w10
  char v37; // w8
  __int64 v38; // x0
  char v39; // w21
  char v40; // w22
  char v41; // w23
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  _WORD *v50; // x8
  int v51; // [xsp+4h] [xbp-5Ch] BYREF
  _BYTE v52[4]; // [xsp+8h] [xbp-58h] BYREF
  _BYTE v53[4]; // [xsp+Ch] [xbp-54h] BYREF
  _BYTE v54[4]; // [xsp+10h] [xbp-50h] BYREF
  _BYTE v55[4]; // [xsp+14h] [xbp-4Ch] BYREF
  _QWORD v56[2]; // [xsp+18h] [xbp-48h] BYREF
  __int64 v57; // [xsp+28h] [xbp-38h]
  __int64 v58; // [xsp+30h] [xbp-30h]
  __int64 v59; // [xsp+38h] [xbp-28h]
  __int64 v60; // [xsp+40h] [xbp-20h]
  __int64 v61; // [xsp+48h] [xbp-18h]
  int v62; // [xsp+50h] [xbp-10h]
  __int64 v63; // [xsp+58h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[3];
  v62 = 0;
  v3 = a1[17];
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56[1] = 0;
  v57 = 0;
  v56[0] = 0;
  v5 = *(_QWORD *)(v2 + 328);
  v4 = *(_QWORD *)(v2 + 336);
  vht_ch_width = sme_get_vht_ch_width();
  v8 = a1[16];
  v7 = a1[17];
  v9 = *a1;
  v51 = 0;
  result = mlme_cfg_get_he_caps(v9, (__int64)v56);
  if ( !(_DWORD)result )
  {
    if ( v5 )
    {
      *(_WORD *)a1[16] = 12;
      *(_BYTE *)(a1[16] + 2) = LOBYTE(v56[0]) != 0;
      *(_WORD *)(v5 + 92) = 1;
      v19 = (_WORD *)a1[16];
      if ( v19 )
      {
        v19[11] = HIWORD(v57);
        v19[13] = WORD1(v58);
        v19[15] = HIWORD(v58);
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Unable to update wiphy he_mcs",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "hdd_update_wiphy_he_mcs");
      }
      *(_QWORD *)(v5 + 96) = a1[16];
      ucfg_mlme_get_channel_bonding_24ghz(*a1, &v51);
      if ( v51 )
        *(_BYTE *)(v8 + 9) |= 2u;
      v20 = BYTE1(v56[0]);
      if ( (v56[0] & 0x200LL) != 0 )
        *(_BYTE *)(v8 + 3) |= 2u;
      if ( (v20 & 4) != 0 )
        *(_BYTE *)(v8 + 3) |= 4u;
    }
    if ( v4 )
    {
      *(_WORD *)a1[17] = 12;
      *(_BYTE *)(a1[17] + 2) = LOBYTE(v56[0]) != 0;
      *(_WORD *)(v4 + 92) = 1;
      v21 = (_WORD *)a1[17];
      if ( v21 )
      {
        v21[11] = HIWORD(v57);
        v21[13] = WORD1(v58);
        v21[15] = HIWORD(v58);
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Unable to update wiphy he_mcs",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "hdd_update_wiphy_he_mcs");
      }
      *(_QWORD *)(v4 + 96) = a1[17];
      if ( vht_ch_width )
      {
        v22 = *(_BYTE *)(v3 + 9);
        *(_BYTE *)(v3 + 9) = v22 | 4;
        if ( vht_ch_width != 1 )
        {
          *(_BYTE *)(v3 + 9) = v22 | 0xC;
          if ( vht_ch_width >= 3u )
            *(_BYTE *)(v3 + 9) = v22 | 0x1C;
        }
      }
      v23 = BYTE1(v56[0]);
      if ( (v56[0] & 0x200LL) != 0 )
        *(_BYTE *)(v7 + 3) |= 2u;
      if ( (v23 & 4) != 0 )
        *(_BYTE *)(v7 + 3) |= 4u;
    }
    v24 = a1[18];
    v25 = *(_QWORD *)(a1[3] + 352);
    v26 = sme_get_vht_ch_width();
    if ( !v25 || (v35 = (char *)(v24 + 9), v24 == -9) )
    {
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: 6ghz not supported in wiphy",
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 "hdd_update_wiphy_he_caps_6ghz");
    }
    else
    {
      *(_WORD *)a1[18] = 12;
      *(_BYTE *)(a1[18] + 2) = 1;
      *(_WORD *)(v25 + 92) = 1;
      if ( v26 )
      {
        v36 = *v35;
        *v35 |= 4u;
        if ( v26 != 1 )
        {
          *v35 = v36 | 0xC;
          if ( v26 >= 3u )
            *v35 = v36 | 0x1C;
        }
      }
      v37 = BYTE1(v56[0]);
      if ( (v56[0] & 0x200LL) != 0 )
      {
        *(_BYTE *)(v24 + 3) |= 2u;
        v37 = BYTE1(v56[0]);
      }
      if ( (v37 & 4) != 0 )
        *(_BYTE *)(v24 + 3) |= 4u;
      v38 = *a1;
      v55[0] = 0;
      v54[0] = 0;
      v53[0] = 0;
      v52[0] = 0;
      wlan_mlme_get_ht_mpdu_density(v38, v55);
      v39 = v55[0];
      wlan_mlme_cfg_get_vht_ampdu_len_exp(*a1, v54);
      v40 = v54[0];
      wlan_mlme_cfg_get_vht_max_mpdu_len(*a1, v53);
      v41 = v53[0];
      result = wlan_mlme_cfg_get_ht_smps(*a1, v52);
      *(_WORD *)(a1[18] + 57) = v39 & 7 | (8 * (v40 & 7)) & 0x3F | ((v41 & 3) << 6) | ((v52[0] & 3) << 9) | 0x3000;
      v50 = (_WORD *)a1[18];
      if ( v50 )
      {
        v50[11] = HIWORD(v57);
        v50[13] = WORD1(v58);
        v50[15] = HIWORD(v58);
      }
      else
      {
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: Unable to update wiphy he_mcs",
                   v42,
                   v43,
                   v44,
                   v45,
                   v46,
                   v47,
                   v48,
                   v49,
                   "hdd_update_wiphy_he_mcs");
      }
      *(_QWORD *)(v25 + 96) = a1[18];
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
