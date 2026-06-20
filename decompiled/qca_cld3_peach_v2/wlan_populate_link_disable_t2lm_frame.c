__int64 __fastcall wlan_populate_link_disable_t2lm_frame(__int64 a1, __int64 a2)
{
  __int64 bsspeer; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  __int64 v23; // x8
  unsigned __int8 *v24; // x23
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int16 v33; // w8
  unsigned __int8 v34; // w8
  unsigned __int8 v35; // w8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 ap_link; // x22
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w26
  const char *v54; // x2
  int v56; // w8
  unsigned int v57; // w27
  __int64 v58; // x0
  unsigned int v59; // w20
  __int64 v60; // [xsp+8h] [xbp-C8h]
  _DWORD dest[43]; // [xsp+14h] [xbp-BCh] BYREF
  __int64 v62; // [xsp+C0h] [xbp-10h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x5Au);
  if ( !bsspeer )
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: peer is null",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_populate_link_disable_t2lm_frame");
    goto LABEL_6;
  }
  if ( !*(_QWORD *)(a1 + 1360) )
  {
LABEL_6:
    result = 29;
    goto LABEL_59;
  }
  v13 = bsspeer;
  if ( (mlo_is_link_recfg_in_progress(a1) & 1) != 0 )
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: Link Recfg in progress, ignore load balancing req",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_populate_link_disable_t2lm_frame");
    result = 8;
  }
  else
  {
    v23 = *(_QWORD *)(v13 + 784);
    v24 = (unsigned __int8 *)(v23 + 208);
    v60 = v23;
    memcpy(dest, (const void *)(v23 + 376), sizeof(dest));
    dest[0] = 1;
    if ( v24 )
    {
      v33 = *v24;
      if ( ((v33 + 1) & 0x100) != 0 )
        v34 = 1;
      else
        v34 = v33 + 1;
      *v24 = v34;
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: gen dialog token %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "t2lm_gen_dialog_token",
        v34);
      v35 = *v24;
    }
    else
    {
      v35 = 0;
    }
    LOBYTE(dest[1]) = v35;
    qdf_mem_set(&dest[2], 0x9Cu, 0);
    dest[2] = 4;
    dest[15] = 4;
    LOBYTE(dest[29]) = 0;
    dest[28] = 2;
    *(_WORD *)((char *)&dest[29] + 1) = 0;
    BYTE1(dest[40]) = 1;
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: dir %d",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "wlan_populate_link_disable_t2lm_frame",
      2);
    ap_link = mlo_mgr_get_ap_link(a1);
    v53 = 0;
    do
    {
      if ( ap_link )
      {
        v56 = *(_DWORD *)(a2 + 8);
        v57 = *(unsigned __int8 *)(ap_link + 6);
        if ( v56 )
        {
          switch ( *(_BYTE *)(ap_link + 6) )
          {
            case 0:
              if ( (v56 & 1) == 0 )
                goto LABEL_53;
              break;
            case 1:
              if ( (v56 & 2) == 0 )
                goto LABEL_53;
              break;
            case 2:
              if ( (v56 & 4) == 0 )
                goto LABEL_53;
              break;
            case 3:
              if ( (v56 & 8) == 0 )
                goto LABEL_53;
              break;
            case 4:
              if ( (v56 & 0x10) == 0 )
                goto LABEL_53;
              break;
            case 5:
              if ( (v56 & 0x20) == 0 )
                goto LABEL_53;
              break;
            case 6:
              if ( (v56 & 0x40) == 0 )
                goto LABEL_53;
              break;
            case 7:
              if ( (v56 & 0x80) == 0 )
                goto LABEL_53;
              break;
            case 8:
              if ( (v56 & 0x100) == 0 )
                goto LABEL_53;
              break;
            case 9:
              if ( (v56 & 0x200) == 0 )
                goto LABEL_53;
              break;
            case 0xA:
              if ( (v56 & 0x400) == 0 )
                goto LABEL_53;
              break;
            case 0xB:
              if ( (v56 & 0x800) == 0 )
                goto LABEL_53;
              break;
            case 0xC:
              if ( (v56 & 0x1000) == 0 )
                goto LABEL_53;
              break;
            case 0xD:
              if ( (v56 & 0x2000) == 0 )
                goto LABEL_53;
              break;
            case 0xE:
              if ( (v56 & 0x4000) == 0 )
                goto LABEL_53;
              break;
            case 0xF:
              if ( (v56 & 0x8000) == 0 )
                goto LABEL_53;
              break;
            default:
              goto LABEL_23;
          }
          v54 = "%s: Disabled link id %d";
          LOWORD(dest[32]) &= ~(unsigned __int16)(1LL << v57);
          HIWORD(dest[32]) &= ~(unsigned __int16)(1LL << v57);
          LOWORD(dest[33]) &= ~(unsigned __int16)(1LL << v57);
          HIWORD(dest[33]) &= ~(unsigned __int16)(1LL << v57);
          LOWORD(dest[34]) &= ~(unsigned __int16)(1LL << v57);
          HIWORD(dest[34]) &= ~(unsigned __int16)(1LL << v57);
          LOWORD(dest[35]) &= ~(unsigned __int16)(1LL << v57);
          HIWORD(dest[35]) &= ~(unsigned __int16)(1LL << v57);
        }
        else
        {
          qdf_trace_msg(
            0x99u,
            2u,
            "%s: Link id bitmap is 0",
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "wlan_is_ml_link_disabled");
          if ( v57 <= 0xF )
          {
LABEL_53:
            LOWORD(dest[32]) |= 1LL << v57;
            HIWORD(dest[32]) |= 1LL << v57;
            LOWORD(dest[33]) |= 1LL << v57;
            HIWORD(dest[33]) |= 1LL << v57;
            LOWORD(dest[34]) |= 1LL << v57;
            HIWORD(dest[34]) |= 1LL << v57;
            LOWORD(dest[35]) |= 1LL << v57;
            HIWORD(dest[35]) |= 1LL << v57;
          }
          else
          {
LABEL_23:
            qdf_trace_msg(
              0x99u,
              2u,
              "%s: Max 16 t2lm links are supported",
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              "wlan_t2lm_set_link_mapping_of_tids");
          }
          v54 = "%s: Enabled link id %d";
        }
        qdf_trace_msg(
          0x99u,
          8u,
          v54,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "wlan_populate_link_disable_t2lm_frame",
          v57);
        ap_link += 48;
      }
    }
    while ( v53++ < 2 );
    *(_BYTE *)(v60 + 548) = 1;
    v58 = *(_QWORD *)(v13 + 784);
    if ( v58 )
      v59 = ttlm_sm_deliver_event(v58, 7u, 0xACu, (__int64)dest);
    else
      v59 = 16;
    wlan_objmgr_peer_release_ref(v13, 0x5Au, v45, v46, v47, v48, v49, v50, v51, v52);
    result = v59;
  }
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return result;
}
