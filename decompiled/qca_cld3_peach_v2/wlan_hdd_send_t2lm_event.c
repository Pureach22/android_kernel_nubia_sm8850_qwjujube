__int64 __fastcall wlan_hdd_send_t2lm_event(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 link_info_from_objmgr; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x19
  unsigned int bss_peer_mld_mac; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w20
  const char *v41; // x2
  __int64 result; // x0
  const char *v43; // x2
  int v44; // w0
  __int64 v45; // x21
  __int64 v46; // x22
  int v47; // w0
  _WORD *v48; // x21
  int v49; // w8
  int v50; // w22
  __int64 v51; // x24
  __int64 v52; // x25
  int v53; // w8
  _WORD *v54; // x24
  int v55; // w22
  __int64 v56; // x24
  __int64 v57; // x25
  int v58; // w8
  _WORD *v59; // x24
  int v60; // w22
  __int64 v61; // x24
  __int64 v62; // x25
  int v63; // w8
  _WORD *v64; // x24
  _WORD v65[2]; // [xsp+4h] [xbp-1Ch] BYREF
  int v66; // [xsp+8h] [xbp-18h] BYREF
  __int16 v67; // [xsp+Ch] [xbp-14h]
  int v68; // [xsp+10h] [xbp-10h] BYREF
  __int16 v69; // [xsp+14h] [xbp-Ch]
  __int64 v70; // [xsp+18h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v67 = 0;
  v66 = 0;
  link_info_from_objmgr = wlan_hdd_get_link_info_from_objmgr(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( link_info_from_objmgr )
  {
    v21 = _cfg80211_alloc_event_skb(
            *(_QWORD *)(*(_QWORD *)(*(_QWORD *)link_info_from_objmgr + 24LL) + 24LL),
            *(_QWORD *)link_info_from_objmgr + 112LL,
            103,
            197,
            0,
            62,
            160,
            3264);
    if ( v21 )
    {
      v30 = v21;
      bss_peer_mld_mac = wlan_vdev_get_bss_peer_mld_mac(a1, &v66, v22, v23, v24, v25, v26, v27, v28, v29);
      if ( bss_peer_mld_mac )
      {
        v40 = bss_peer_mld_mac;
        v41 = "%s: Failed to get mld address";
LABEL_11:
        qdf_trace_msg(0x33u, 2u, v41, v32, v33, v34, v35, v36, v37, v38, v39, "wlan_hdd_send_t2lm_event");
        sk_skb_reason_drop(0, v30, 2);
        result = v40;
        goto LABEL_12;
      }
      v69 = v67;
      v68 = v66;
      if ( (unsigned int)nla_put(v30, 1, 6, &v68) )
      {
        v43 = "%s: Failed to put mac_addr";
        goto LABEL_9;
      }
      if ( *((_BYTE *)a2 + 4) != 1 )
      {
        v45 = *(_QWORD *)(v30 + 216);
        v46 = *(unsigned int *)(v30 + 208);
        v47 = nla_put(v30, 32770, 0, 0);
        v43 = "%s: nla_nest_start error";
        if ( (v47 & 0x80000000) == 0 )
        {
          v48 = (_WORD *)(v45 + v46);
          if ( v48 )
          {
            v49 = *a2;
            if ( *a2 )
            {
              if ( v49 == 1 )
              {
                v55 = 0;
                while ( 1 )
                {
                  v56 = *(_QWORD *)(v30 + 216);
                  v57 = *(unsigned int *)(v30 + 208);
                  v58 = nla_put(v30, (unsigned int)(v55 + 32769), 0, 0);
                  v44 = -22;
                  if ( v58 < 0 )
                    break;
                  v59 = (_WORD *)(v56 + v57);
                  if ( !v59 )
                    break;
                  v65[0] = *((_WORD *)a2 + 8);
                  v44 = nla_put(v30, 1, 2, v65);
                  if ( v44 )
                    break;
                  v65[0] = 0;
                  v44 = nla_put(v30, 2, 2, v65);
                  if ( v44 )
                    break;
                  ++v55;
                  *v59 = *(_WORD *)(v30 + 216) + *(_DWORD *)(v30 + 208) - (_WORD)v59;
                  if ( v55 == 8 )
                    goto LABEL_41;
                }
              }
              else if ( v49 == 2 )
              {
                v50 = 0;
                while ( 1 )
                {
                  v51 = *(_QWORD *)(v30 + 216);
                  v52 = *(unsigned int *)(v30 + 208);
                  v53 = nla_put(v30, (unsigned int)(v50 + 32769), 0, 0);
                  v44 = -22;
                  if ( v53 < 0 )
                    break;
                  v54 = (_WORD *)(v51 + v52);
                  if ( !v54 )
                    break;
                  v65[0] = *((_WORD *)a2 + 8);
                  v44 = nla_put(v30, 1, 2, v65);
                  if ( v44 )
                    break;
                  v65[0] = *((_WORD *)a2 + 8);
                  v44 = nla_put(v30, 2, 2, v65);
                  if ( v44 )
                    break;
                  ++v50;
                  *v54 = *(_WORD *)(v30 + 216) + *(_DWORD *)(v30 + 208) - (_WORD)v54;
                  if ( v50 == 8 )
                    goto LABEL_41;
                }
              }
              else
              {
                v44 = -22;
              }
            }
            else
            {
              v60 = 0;
              while ( 1 )
              {
                v61 = *(_QWORD *)(v30 + 216);
                v62 = *(unsigned int *)(v30 + 208);
                v63 = nla_put(v30, (unsigned int)(v60 + 32769), 0, 0);
                v44 = -22;
                if ( v63 < 0 )
                  break;
                v64 = (_WORD *)(v61 + v62);
                if ( !v64 )
                  break;
                v65[0] = *((_WORD *)a2 + 8);
                v44 = nla_put(v30, 2, 2, v65);
                if ( v44 )
                  break;
                v65[0] = 0;
                v44 = nla_put(v30, 1, 2, v65);
                if ( v44 )
                  break;
                ++v60;
                *v64 = *(_WORD *)(v30 + 216) + *(_DWORD *)(v30 + 208) - (_WORD)v64;
                if ( v60 == 8 )
                {
LABEL_41:
                  *v48 = *(_WORD *)(v30 + 216) + *(_DWORD *)(v30 + 208) - (_WORD)v48;
                  goto LABEL_15;
                }
              }
            }
            goto LABEL_10;
          }
        }
LABEL_9:
        qdf_trace_msg(0x33u, 2u, v43, v32, v33, v34, v35, v36, v37, v38, v39, "hdd_t2lm_pack_nl_response");
        v44 = 4;
LABEL_10:
        v40 = v44;
        v41 = "%s: Failed to pack nl response";
        goto LABEL_11;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: update mld addr for default mapping",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "hdd_t2lm_pack_nl_response");
LABEL_15:
      _cfg80211_send_event_skb(v30, 3264);
      result = 0;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: wlan_cfg80211_vendor_event_alloc failed",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wlan_hdd_send_t2lm_event");
      result = 4294967274LL;
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid VDEV", v13, v14, v15, v16, v17, v18, v19, v20, "wlan_hdd_send_t2lm_event");
    result = 16;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
