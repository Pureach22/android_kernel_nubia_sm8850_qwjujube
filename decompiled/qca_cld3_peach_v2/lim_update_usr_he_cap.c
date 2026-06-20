__int64 __fastcall lim_update_usr_he_cap(__int64 a1, __int64 a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  __int64 v21; // x9
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x9
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x8
  unsigned int v41; // w9
  int v42; // w9
  __int64 ext_hdl; // x0
  unsigned __int64 v44; // x10
  unsigned __int64 v45; // x10
  unsigned __int64 v46; // x10
  unsigned __int64 v47; // x10
  unsigned __int64 v48; // x10
  unsigned __int64 v49; // x10
  __int128 v50; // [xsp+0h] [xbp-40h] BYREF
  __int64 v51; // [xsp+10h] [xbp-30h]
  __int64 v52; // [xsp+18h] [xbp-28h]
  __int64 v53; // [xsp+20h] [xbp-20h]
  __int64 v54; // [xsp+28h] [xbp-18h]
  __int64 v55; // [xsp+30h] [xbp-10h]
  __int64 v56; // [xsp+38h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v51 = 0;
  v50 = 0u;
  qdf_mem_set(&v50, 0x38u, 0);
  v11 = wlan_strip_ie(
          *(unsigned __int8 **)(a2 + 7328),
          (unsigned __int16 *)(a2 + 7320),
          0xFFu,
          1,
          "#",
          1u,
          (char *)&v50,
          54,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10);
  if ( v11 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Failed to strip HE cap IE status: %d",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "lim_update_usr_he_cap",
               v11);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Before update: su_beamformer: %d, su_beamformee: %d, mu_beamformer: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "lim_update_usr_he_cap",
      HIWORD(*(_DWORD *)(a2 + 8689)) & 1,
      (*(_DWORD *)(a2 + 8689) >> 17) & 1,
      (*(_DWORD *)(a2 + 8689) >> 18) & 1);
    v21 = *(_QWORD *)(a2 + 8689);
    v22 = (*(_QWORD *)((char *)&v50 + 7) >> 31) & v21;
    v23 = ((*(_QWORD *)((char *)&v50 + 7) >> 31) | 0xFFFFFFFFFFFCFFFFLL) & v21;
    *(_QWORD *)(a2 + 8689) = v22 & 0x60000 | v23 & 0xFFFFFFFFFFF9FFFFLL;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: After update: su_beamformer: %d, su_beamformee: %d, mu_beamformer: %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "lim_update_usr_he_cap",
      WORD1(v23) & 1,
      (v22 >> 17) & 1,
      (v22 >> 18) & 1);
    v40 = *(_QWORD *)(a2 + 8689);
    if ( (v40 & 0x10000) == 0 )
    {
      v40 &= 0xFFFFFFFE07FAFFFFLL;
      v41 = *(_DWORD *)(a2 + 7268) & 0xFFF0F7FF;
      *(_QWORD *)(a2 + 8689) = v40;
      *(_DWORD *)(a2 + 7268) = v41;
    }
    if ( (v40 & 0x20000) == 0 )
    {
      v42 = *(_DWORD *)(a2 + 7268);
      *(_QWORD *)(a2 + 8689) = v40 & 0xFFFFFFFFF8C5FFFFLL;
      *(_DWORD *)(a2 + 7268) = v42 & 0xFFEF0FFF;
    }
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a2 + 16), v32, v33, v34, v35, v36, v37, v38, v39);
    if ( ext_hdl )
    {
      v44 = *(_QWORD *)(ext_hdl + 23905) & 0xFFFFFFFFFFFBFFFFLL | (((*(_QWORD *)(a2 + 8689) >> 18) & 1LL) << 18);
      *(_QWORD *)(ext_hdl + 23905) = v44;
      v45 = v44 & 0xFFFFFFFFFFFEFFFFLL | (((*(_QWORD *)(a2 + 8689) >> 16) & 1LL) << 16);
      *(_QWORD *)(ext_hdl + 23905) = v45;
      v46 = v45 & 0xFFFFFFFFFFFDFFFFLL | (((*(_QWORD *)(a2 + 8689) >> 17) & 1LL) << 17);
      *(_QWORD *)(ext_hdl + 23905) = v46;
      v47 = v46 & 0xFFFFFFFFFFC7FFFFLL | (((*(_QWORD *)(a2 + 8689) >> 19) & 7LL) << 19);
      *(_QWORD *)(ext_hdl + 23905) = v47;
      v48 = v47 & 0xFFFFFFFFF8FFFFFFLL | (((*(_QWORD *)(a2 + 8689) >> 24) & 7LL) << 24);
      *(_QWORD *)(ext_hdl + 23905) = v48;
      v49 = v48 & 0xFFFFFFFFC7FFFFFFLL | (((*(_QWORD *)(a2 + 8689) >> 27) & 7LL) << 27);
      *(_QWORD *)(ext_hdl + 23905) = v49;
      *(_QWORD *)(ext_hdl + 23905) = v49 & 0xFFFFFFFE3FFFFFFFLL | (((*(_QWORD *)(a2 + 8689) >> 30) & 7LL) << 30);
    }
    result = wma_set_he_txbf_params(
               *(unsigned __int8 *)(a2 + 10),
               (*(_QWORD *)(a2 + 8689) >> 16) & 1LL,
               (*(_QWORD *)(a2 + 8689) >> 17) & 1LL,
               (*(_QWORD *)(a2 + 8689) >> 18) & 1LL);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
