double __fastcall mlo_mgr_link_rejection_handler(__int64 a1, __int64 a2, unsigned int *a3, char a4, double result)
{
  __int64 v6; // x8
  __int64 v8; // x25
  __int64 v9; // x9
  int v11; // w11
  unsigned int v12; // w12
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _WORD *v21; // x1
  _WORD *v22; // x20
  int v23; // w9
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  __int64 v32; // x20
  int v33; // t1
  __int16 v34; // w10
  __int64 v35; // x1
  __int64 v36; // x0
  __int64 v37; // x1
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x8
  __int64 v46; // x26
  __int64 v47; // x28
  unsigned __int64 v48; // x23
  char v49; // w27
  unsigned __int8 *v50; // x24
  __int64 v52; // x21
  unsigned int v53; // w10
  __int64 v54; // x8
  unsigned __int8 *v55; // x22
  unsigned int v56; // w8
  int v57; // w9
  unsigned __int8 *v58; // x20
  __int64 v59; // x4
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x4
  __int64 v69; // x5
  __int64 v70; // [xsp+0h] [xbp-80h]
  _QWORD v71[11]; // [xsp+10h] [xbp-70h] BYREF
  __int64 v72; // [xsp+68h] [xbp-18h]
  __int64 v73; // [xsp+70h] [xbp-10h]
  __int64 v74; // [xsp+78h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_32;
  if ( !a2 )
    goto LABEL_32;
  v6 = *(_QWORD *)(a1 + 1360);
  if ( !v6 )
    goto LABEL_32;
  v8 = *(_QWORD *)(v6 + 2224);
  if ( !v8 )
    goto LABEL_32;
  v72 = 0;
  v73 = 0;
  memset(v71, 0, sizeof(v71));
  if ( a3 && (a4 & 1) != 0 )
  {
    v9 = *(_QWORD *)(v6 + 3880);
    *(_BYTE *)(v9 + 361) = *(_BYTE *)(a2 + 6);
    v11 = *(_DWORD *)(a2 + 24);
    *(_WORD *)(v9 + 366) = *(_WORD *)(a2 + 28);
    *(_DWORD *)(v9 + 362) = v11;
    *(_BYTE *)(v9 + 368) = *((_BYTE *)a3 + 6);
    LOWORD(v11) = *((_WORD *)a3 + 14);
    v12 = a3[6];
    *(_BYTE *)(v9 + 375) = 1;
    *(_WORD *)(v9 + 373) = v11;
    *(_DWORD *)(v9 + 369) = v12;
    *(_BYTE *)(v9 + 360) = *(_BYTE *)(a1 + 168);
    *(_DWORD *)(a1 + 64) |= 0x4000000u;
    wlan_vdev_mlme_send_set_mac_addr(
      *a3 | ((unsigned __int64)*((unsigned __int16 *)a3 + 2) << 32),
      *(unsigned int *)(v6 + 17) | ((unsigned __int64)*(unsigned __int16 *)(v6 + 21) << 32));
    v21 = a3;
    if ( *((unsigned __int8 *)a3 + 12) != 255 )
      goto LABEL_8;
    if ( *(unsigned __int8 *)(a2 + 12) == 255 )
      goto LABEL_8;
    v53 = *((unsigned __int8 *)a3 + 6);
    if ( v53 > 0xE )
      goto LABEL_8;
    v54 = *(_QWORD *)(a1 + 1360);
    if ( !v54 )
      goto LABEL_8;
    v55 = *(unsigned __int8 **)(v54 + 3880);
    v56 = *(unsigned __int8 *)(a2 + 6);
    v57 = v55[6];
    v58 = v55;
    if ( v57 != v53 )
    {
      if ( v55[54] == v53 )
      {
        v58 = v55 + 48;
      }
      else
      {
        if ( v55[102] != v53 )
          goto LABEL_8;
        v58 = v55 + 96;
      }
    }
    if ( v56 <= 0xE && v58 )
    {
      if ( v57 == v56 )
        goto LABEL_42;
      if ( v55[54] == v56 )
      {
        v55 += 48;
        goto LABEL_42;
      }
      if ( v55[102] == v56 )
      {
        v55 += 96;
LABEL_42:
        if ( v55 )
        {
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Accepted vdev id %d rejected vdev id %d ",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "mlo_mgr_update_link_vdev_id",
            v58[12],
            v55[12]);
          v68 = v58[12];
          v69 = v55[12];
          if ( (_DWORD)v68 == 255 && (_DWORD)v69 != 255 )
          {
            v58[12] = v69;
            v69 = 255;
            v55[12] = -1;
            v55[6] = -1;
            v68 = v58[12];
          }
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Updated accepted vdev id %d rejected vdev id %d ",
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            "mlo_mgr_update_link_vdev_id",
            v68,
            v69);
          v21 = a3;
        }
      }
    }
LABEL_8:
    v22 = v21;
    qdf_mem_copy((void *)(a1 + 74), v21, 6u);
    v23 = *(_DWORD *)v22;
    *(_WORD *)(a1 + 90) = v22[2];
    *(_DWORD *)(a1 + 86) = v23;
    if ( (unsigned int)ucfg_dp_update_link_mac_addr(a1, v22, 1) )
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: DP link MAC update failed",
        result,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "mlo_mgr_link_rejection_handler");
LABEL_32:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v31 = *(_QWORD *)(a1 + 216);
  qdf_mem_set(v71, 0x68u, 0);
  v33 = *(_DWORD *)(a2 + 24);
  v32 = a2 + 24;
  v34 = *(_WORD *)(v32 + 4);
  v35 = *(unsigned __int8 *)(a1 + 168);
  LODWORD(v71[0]) = v33;
  v72 = 0x1200000002LL;
  WORD2(v71[0]) = v34;
  LODWORD(v73) = 1;
  ((void (__fastcall *)(__int64, __int64, _QWORD *))dlm_update_mlo_reject_ap_info)(v31, v35, v71);
  v36 = dlm_add_bssid_to_reject_list(v31, (__int64)v71);
  v45 = *(_QWORD *)(a1 + 1360);
  if ( !v45 )
    goto LABEL_32;
  v46 = *(_QWORD *)(v45 + 2224);
  if ( !v46 )
    goto LABEL_32;
  if ( !*(_BYTE *)(v46 + 1168) )
  {
    v49 = 0;
LABEL_31:
    v59 = (unsigned __int8)(*(_BYTE *)(v8 + 1168) - v49);
    *(_BYTE *)(v8 + 1168) -= v49;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Updated ml partner links %d",
      result,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "mlo_mgr_clear_rejected_partner_info",
      v59);
    goto LABEL_32;
  }
  v47 = 0;
  v48 = 0;
  v49 = 0;
  while ( v47 != 192 )
  {
    v50 = (unsigned __int8 *)(v46 + v47 + 1176);
    if ( v46 + v47 == -1176 )
    {
      v36 = qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: link_info null",
              result,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              "mlo_mgr_clear_rejected_partner_info");
    }
    else if ( *(_DWORD *)v32 == *(_DWORD *)v50
           && *(unsigned __int16 *)(v32 + 4) == *(unsigned __int16 *)(v46 + v47 + 1180) )
    {
      v52 = v46 + v47;
      LODWORD(v70) = *(unsigned __int8 *)(v46 + v47 + 1181);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Clear AP partner for link_id: %d, link_addr:%02x:%02x:%02x:**:**:%02x",
        result,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "mlo_mgr_clear_rejected_partner_info",
        *(unsigned __int8 *)(v46 + v47 + 1182),
        *v50,
        *(unsigned __int8 *)(v46 + v47 + 1177),
        *(unsigned __int8 *)(v46 + v47 + 1178),
        v70);
      v36 = (__int64)mlo_mgr_clear_ap_link_info(a1, v46 + v47 + 1176);
      ++v49;
      *(_WORD *)(v46 + v47 + 1180) = 0;
      *(_DWORD *)v50 = 0;
      *(_BYTE *)(v52 + 1182) = -1;
      *(_QWORD *)(v52 + 1192) = 0;
    }
    ++v48;
    v47 += 48;
    if ( v48 >= *(unsigned __int8 *)(v46 + 1168) )
      goto LABEL_31;
  }
  __break(0x5512u);
  return mlo_mgr_if_freq_n_inactive_links_freq_same(v36, v37);
}
