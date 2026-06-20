__int64 __fastcall osif_update_connect_results(__int64 a1, __int64 a2, unsigned __int8 *a3, __int64 a4)
{
  int v8; // w22
  unsigned int v9; // w8
  int v10; // w9
  unsigned int v11; // w8
  __int64 v12; // x9
  unsigned int v13; // w8
  __int64 v14; // x9
  __int64 v15; // x8
  __int16 v16; // w9
  __int64 v17; // x10
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 peer_by_mac; // x0
  __int64 v21; // x22
  __int64 ap_link_by_link_id; // x0
  int v23; // w8
  _OWORD *v24; // x9
  __int64 v25; // x22
  __int64 v26; // x23
  __int64 v27; // x24
  __int64 v28; // x0
  __int64 v29; // x25
  __int64 chan_bss_from_kernel; // x0
  int v31; // w8
  _OWORD *v32; // x9
  const char *v33; // x4
  __int64 v34; // x0
  unsigned int v35; // w0
  __int64 result; // x0
  int v37; // w5
  unsigned int v38; // w8
  unsigned __int64 v39; // x26
  unsigned __int8 *v40; // x23
  __int64 v41; // x27
  _OWORD *v42; // x25
  __int64 v43; // x9
  _QWORD *v44; // x25
  __int64 v45; // t1
  int v47; // w6
  int v48; // w7
  int v49; // w8
  int v50; // w9
  unsigned __int8 *v51; // x22
  unsigned __int64 v52; // x24
  int v53; // w8
  int v54; // w6
  int v55; // w7
  int v56; // w10
  int v57; // w11
  int v58; // w12
  int v59; // w13
  int v60; // w14
  __int64 v61; // x9
  int v62; // [xsp+48h] [xbp-278h]
  __int64 v63; // [xsp+58h] [xbp-268h]
  _OWORD s[37]; // [xsp+60h] [xbp-260h] BYREF
  __int64 v65; // [xsp+2B0h] [xbp-10h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  qdf_trace_msg(72, 8, "%s: enter(%s)", "osif_connect_done", (const char *)(a1 + 296));
  if ( *((_DWORD *)a3 + 13) )
  {
    if ( *((_DWORD *)a3 + 15) <= 1u )
      v8 = 1;
    else
      v8 = *((_DWORD *)a3 + 15);
  }
  else
  {
    v8 = 0;
  }
  qdf_mem_set((int)s, 0x250u, 0);
  LODWORD(s[0]) = v8;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a4) & 1) == 0 )
  {
    *((_QWORD *)&s[7] + 1) = a3 + 8;
    *(_QWORD *)&s[8] = a2;
  }
  v9 = *((_DWORD *)a3 + 14) - 6;
  if ( v9 > 4 )
    v10 = 0;
  else
    v10 = dword_ACFB80[v9];
  v11 = *((_DWORD *)a3 + 26);
  DWORD2(s[5]) = v10;
  if ( v11 > 4 )
  {
    v12 = *((_QWORD *)a3 + 14);
    if ( v12 )
    {
      *((_QWORD *)&s[0] + 1) = v12 + 4;
      *(_QWORD *)&s[1] = v11 - 4;
    }
  }
  v13 = *((_DWORD *)a3 + 30);
  if ( v13 > 6 )
  {
    v14 = *((_QWORD *)a3 + 16);
    if ( v14 )
    {
      *((_QWORD *)&s[1] + 1) = v14 + 6;
      *(_QWORD *)&s[2] = v13 - 6;
    }
  }
  v15 = *((_QWORD *)a3 + 17);
  v63 = a2;
  if ( v15 )
  {
    v16 = *(_WORD *)(v15 + 2442);
    BYTE8(s[3]) = 1;
    v17 = *(unsigned __int8 *)(v15 + 89);
    *((_QWORD *)&s[2] + 1) = v15 + 25;
    *(_QWORD *)&s[3] = v17;
    WORD5(s[3]) = v16 + 1;
    *(_QWORD *)&s[4] = *(_QWORD *)v15;
    *((_QWORD *)&s[4] + 1) = *(unsigned __int8 *)(v15 + 8);
    *(_QWORD *)&s[5] = v15 + 9;
    qdf_trace_msg(72, 8, "%s: erp_next_seq_num:%d", "osif_populate_fils_params", (unsigned __int16)(v16 + 1));
  }
  osif_cm_save_gtk(a4, a3);
  if ( !v8 && (wlan_vdev_mlme_is_mlo_vdev(a4) & 1) != 0 )
  {
    v18 = *(_QWORD *)(a4 + 216);
    if ( v18 && (v19 = *(_QWORD *)(v18 + 80)) != 0 && (peer_by_mac = wlan_objmgr_get_peer_by_mac(v19, a3 + 8, 6)) != 0 )
    {
      *(_QWORD *)&s[6] = peer_by_mac + 792;
      wlan_objmgr_peer_release_ref();
      v21 = *(unsigned __int8 *)(a4 + 93);
      ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(a4 + 1360), v21);
      if ( ap_link_by_link_id )
      {
        v23 = *((_DWORD *)a3 + 15);
        WORD4(s[6]) |= 1LL << v21;
        if ( (unsigned int)v21 >= 0xF )
LABEL_74:
          __break(0x5512u);
        v24 = &s[2 * v21 + 7];
        *(_QWORD *)v24 = ap_link_by_link_id;
        *((_QWORD *)v24 + 1) = a3 + 8;
        if ( a2 )
          *((_QWORD *)v24 + 2) = a2;
        *((_WORD *)v24 + 12) = v23;
        mlo_mgr_osif_update_connect_info(a4, (unsigned int)v21);
        v62 = v21;
        if ( a3[160] )
        {
          v25 = 0;
          v26 = 48LL * a3[160];
          do
          {
            if ( v25 == 192 )
              goto LABEL_74;
            v27 = a3[v25 + 174];
            v28 = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(a4 + 1360), v27);
            if ( v28 )
            {
              v29 = v28;
              chan_bss_from_kernel = osif_get_chan_bss_from_kernel(a4, &a3[v25 + 168], (__int64)a3);
              v31 = *(_DWORD *)(v29 + 44);
              WORD4(s[6]) |= 1LL << v27;
              if ( (unsigned int)v27 >= 0xF )
                goto LABEL_74;
              v32 = &s[2 * v27 + 7];
              *(_QWORD *)v32 = v29;
              *((_QWORD *)v32 + 1) = v29 + 24;
              if ( chan_bss_from_kernel )
                *((_QWORD *)v32 + 2) = chan_bss_from_kernel;
              *((_WORD *)v32 + 12) = v31;
              mlo_mgr_osif_update_connect_info(a4, (unsigned int)v27);
            }
            v25 += 48;
          }
          while ( v26 != v25 );
          v37 = a3[160];
          LODWORD(v21) = v62;
        }
        else
        {
          v37 = 0;
        }
        qdf_trace_msg(
          72,
          8,
          "%s: Vdev %d, Num partner links %d, valid links mask 0x%x Assoc link %u",
          "osif_fill_connect_resp_mlo_params",
          *a3,
          v37,
          WORD4(s[6]),
          v21);
        v38 = a3[160];
        if ( a3[160] )
        {
          v39 = 0;
          while ( 1 )
          {
            if ( v39 == 4 )
              goto LABEL_74;
            v40 = &a3[48 * v39 + 168];
            v41 = v40[6];
            if ( (unsigned int)v41 > 0xE )
              goto LABEL_74;
            v42 = &s[2 * v41 + 7];
            v45 = *((_QWORD *)v42 + 2);
            v44 = v42 + 1;
            v43 = v45;
            if ( v45 )
            {
              if ( (_DWORD)v41 != v62 && v43 == v63 )
              {
                if ( v40 )
                {
                  v47 = *v40;
                  v48 = v40[1];
                  v49 = v40[2];
                  v50 = v40[5];
                }
                else
                {
                  v49 = 0;
                  v47 = 0;
                  v48 = 0;
                  v50 = 0;
                }
                qdf_trace_msg(
                  72,
                  4,
                  "%s: link bss, link_id %d freq %d bssid %02x:%02x:%02x:**:**:%02x same as assoc bss, link %d freq %d bs"
                  "sid %02x:%02x:%02x:**:**:%02x",
                  "osif_debug_mlo_duplicate_bss",
                  v41,
                  *((unsigned __int16 *)v40 + 5),
                  v47,
                  v48,
                  v49,
                  v50,
                  v62,
                  *((_DWORD *)a3 + 12),
                  a3[8],
                  a3[9],
                  a3[10],
                  a3[13]);
                v38 = a3[160];
              }
              if ( v38 )
                break;
            }
LABEL_47:
            if ( ++v39 >= v38 )
              goto LABEL_38;
          }
          v51 = a3 + 168;
          v52 = 0;
          while ( 1 )
          {
            if ( v52 > v39 )
            {
              if ( v52 > 3 )
                goto LABEL_74;
              if ( *v44 )
              {
                v61 = v51[6];
                if ( (unsigned int)v61 > 0xE )
                  goto LABEL_74;
                if ( *(_QWORD *)&s[2 * v61 + 8] == *v44 )
                  break;
              }
            }
LABEL_65:
            ++v52;
            v51 += 48;
            if ( v52 >= v38 )
              goto LABEL_47;
          }
          if ( v40 )
          {
            v54 = *v40;
            v55 = v40[1];
            v53 = v40[2];
            v56 = v40[5];
            if ( !v51 )
              goto LABEL_73;
          }
          else
          {
            v53 = 0;
            v54 = 0;
            v55 = 0;
            v56 = 0;
            if ( !v51 )
            {
LABEL_73:
              v59 = 0;
              v57 = 0;
              v58 = 0;
              v60 = 0;
              goto LABEL_64;
            }
          }
          v57 = *v51;
          v58 = v51[1];
          v59 = v51[2];
          v60 = v51[5];
LABEL_64:
          qdf_trace_msg(
            72,
            4,
            "%s: link bss, link_id %d freq %d bssid %02x:%02x:%02x:**:**:%02x same as link bss, link %d freq %d bssid %02"
            "x:%02x:%02x:**:**:%02x",
            "osif_debug_mlo_duplicate_bss",
            v41,
            *((unsigned __int16 *)v40 + 5),
            v54,
            v55,
            v53,
            v56,
            v61,
            *((unsigned __int16 *)v51 + 5),
            v57,
            v58,
            v59,
            v60);
          v38 = a3[160];
          goto LABEL_65;
        }
      }
      else
      {
        qdf_trace_msg(
          72,
          2,
          "%s: Unable to find link_info for link_id: %d",
          "osif_fill_connect_resp_mlo_params",
          (unsigned int)v21);
      }
    }
    else
    {
      qdf_trace_msg(72, 2, "%s: Unable to fill peer mld address: %d", "osif_fill_connect_resp_mlo_params", 4);
    }
  }
LABEL_38:
  if ( (wlan_vdev_mlme_is_mlo_vdev(a4) & 1) != 0 )
    v33 = "ML ";
  else
    v33 = (const char *)&unk_98C763;
  v34 = qdf_trace_msg(72, 8, "%s: %svdev %d: status  %d", "osif_connect_done", v33, *a3, LODWORD(s[0]));
  v35 = qdf_mem_malloc_flags(v34);
  cfg80211_connect_done(a1, s, v35);
  result = osif_cm_set_hlp_data(a1, a4, a3);
  _ReadStatusReg(SP_EL0);
  return result;
}
