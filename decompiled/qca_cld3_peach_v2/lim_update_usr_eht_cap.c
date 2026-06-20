__int64 __fastcall lim_update_usr_eht_cap(__int64 a1, __int64 a2)
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
  unsigned __int64 *v21; // x21
  _QWORD *v22; // x22
  unsigned __int64 v23; // x10
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x9
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned __int64 v42; // x8
  __int64 v43; // x10
  int v44; // w9
  int v45; // w13
  __int64 v46; // x11
  __int64 ext_hdl; // x0
  unsigned __int64 v48; // x11
  unsigned __int64 v49; // x11
  unsigned __int64 v50; // x10
  unsigned __int64 v51; // x10
  unsigned __int64 v52; // x10
  unsigned __int64 v53; // x10
  unsigned __int64 v54; // x10
  unsigned __int64 v55; // x10
  unsigned __int64 v56; // x10
  __int64 v57; // [xsp+0h] [xbp-70h]
  __int128 v58; // [xsp+10h] [xbp-60h] BYREF
  __int64 v59; // [xsp+20h] [xbp-50h]
  __int64 v60; // [xsp+28h] [xbp-48h]
  __int64 v61; // [xsp+30h] [xbp-40h]
  __int64 v62; // [xsp+38h] [xbp-38h]
  __int64 v63; // [xsp+40h] [xbp-30h]
  __int64 v64; // [xsp+48h] [xbp-28h]
  __int64 v65; // [xsp+50h] [xbp-20h]
  __int64 v66; // [xsp+58h] [xbp-18h]
  __int64 v67; // [xsp+60h] [xbp-10h]
  __int64 v68; // [xsp+68h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v59 = 0;
  v58 = 0u;
  qdf_mem_set(&v58, 0x58u, 0);
  v11 = wlan_strip_ie(
          *(unsigned __int8 **)(a2 + 7328),
          (unsigned __int16 *)(a2 + 7320),
          0xFFu,
          1,
          "l",
          1u,
          (char *)&v58,
          86,
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
               "%s: Failed to strip EHT cap IE status: %d",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "lim_update_usr_eht_cap",
               v11);
  }
  else
  {
    v21 = (unsigned __int64 *)(a2 + 10073);
    v22 = (_QWORD *)(a2 + 10081);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Before update: su_bformer: %d, su_bformee: %d, mu_bformer <= 80MHZ: %d 160MHZ: %d 320MHZ: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "lim_update_usr_eht_cap",
      (*(_DWORD *)(a2 + 10073) >> 21) & 1,
      (*(_DWORD *)(a2 + 10073) >> 22) & 1,
      HIWORD(*(_DWORD *)(a2 + 10081)) & 1,
      (*(_DWORD *)(a2 + 10081) >> 17) & 1,
      (*(_DWORD *)(a2 + 10081) >> 18) & 1);
    v23 = (*(_QWORD *)((char *)&v58 + 7) >> 28) & *(_QWORD *)(a2 + 10081);
    v24 = *v21 & 0xFFFFFFFFFF9FFFFFLL
        | *(_DWORD *)((_BYTE *)&v58 + 3) & (unsigned int)*v21 & 0x200000
        | *(_DWORD *)((_BYTE *)&v58 + 3) & (unsigned int)*v21 & 0x400000;
    v25 = ((*(_QWORD *)((char *)&v58 + 7) >> 28) | 0xFFFFFFFFFFFCFFFFLL) & *(_QWORD *)(a2 + 10081);
    *(_QWORD *)(a2 + 10073) = v24;
    *(_QWORD *)(a2 + 10081) = v23 & 0x60000 | v25 & 0xFFFFFFFFFFF9FFFFLL;
    LODWORD(v57) = (v23 >> 18) & 1;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: After update: su_bformer: %d, su_bformee: %d, mu_bformer <= 80MHZ: %d 160MHZ: %d 320MHZ: %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "lim_update_usr_eht_cap",
      ((unsigned int)v24 >> 21) & 1,
      ((unsigned int)v24 >> 22) & 1,
      WORD1(v25) & 1,
      (v23 >> 17) & 1,
      v57);
    v42 = *(_QWORD *)(a2 + 10073);
    if ( (v42 & 0x200000) == 0 )
    {
      v42 &= 0xFFFFFC01FFDFFFFFLL;
      v43 = *(_QWORD *)(a2 + 8689);
      *v22 &= 0xFFFFFFFFFFF8FFFFLL;
      v44 = *(_DWORD *)(a2 + 7268);
      *v21 = v42;
      *(_QWORD *)(a2 + 8689) = v43 & 0xFFFFFFFE07FBFFFFLL;
      *(_DWORD *)(a2 + 7268) = v44 & 0xFFF0F7FF;
    }
    if ( (v42 & 0x400000) == 0 )
    {
      v45 = *(_DWORD *)(a2 + 7268);
      v46 = *(_QWORD *)(a2 + 8689);
      *v21 = v42 & 0xFFFFFFFE00BFFFFFLL;
      *(_QWORD *)(a2 + 8689) = v46 & 0xFFFFFFFFF8C7FFFFLL;
      *(_DWORD *)(a2 + 7268) = v45 & 0xFFEF0FFF;
    }
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a2 + 16), v34, v35, v36, v37, v38, v39, v40, v41);
    if ( ext_hdl )
    {
      v48 = *(_QWORD *)(ext_hdl + 24457) & 0xFFFFFFFFFFFEFFFFLL | (((*v22 >> 16) & 1LL) << 16);
      *(_QWORD *)(ext_hdl + 24457) = v48;
      v49 = v48 & 0xFFFFFFFFFFFDFFFFLL | (((*v22 >> 17) & 1LL) << 17);
      *(_QWORD *)(ext_hdl + 24457) = v49;
      *(_QWORD *)(ext_hdl + 24457) = v49 & 0xFFFFFFFFFFFBFFFFLL | (((*v22 >> 18) & 1LL) << 18);
      v50 = *(_QWORD *)(ext_hdl + 24449) & 0xFFFFFFFFFFDFFFFFLL | (((*v21 >> 21) & 1) << 21);
      *(_QWORD *)(ext_hdl + 24449) = v50;
      v51 = v50 & 0xFFFFFFFFFFBFFFFFLL | (((*v21 >> 22) & 1) << 22);
      *(_QWORD *)(ext_hdl + 24449) = v51;
      v52 = v51 & 0xFFFFFFFFF8FFFFFFLL | (((*v21 >> 24) & 7) << 24);
      *(_QWORD *)(ext_hdl + 24449) = v52;
      v53 = v52 & 0xFFFFFFFFC7FFFFFFLL | (((*v21 >> 27) & 7) << 27);
      *(_QWORD *)(ext_hdl + 24449) = v53;
      v54 = v53 & 0xFFFFFFFE3FFFFFFFLL | (((*v21 >> 30) & 7) << 30);
      *(_QWORD *)(ext_hdl + 24449) = v54;
      v55 = v54 & 0xFFFFFFF1FFFFFFFFLL | (((*v21 >> 33) & 7) << 33);
      *(_QWORD *)(ext_hdl + 24449) = v55;
      v56 = v55 & 0xFFFFFF8FFFFFFFFFLL | (((*v21 >> 36) & 7) << 36);
      *(_QWORD *)(ext_hdl + 24449) = v56;
      *(_QWORD *)(ext_hdl + 24449) = v56 & 0xFFFFFC7FFFFFFFFFLL | (((*v21 >> 39) & 7) << 39);
    }
    result = wma_set_eht_txbf_params(
               *(unsigned __int8 *)(a2 + 10),
               (*v21 >> 21) & 1,
               (*v21 >> 22) & 1,
               (*v22 & 0x70000LL) != 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
