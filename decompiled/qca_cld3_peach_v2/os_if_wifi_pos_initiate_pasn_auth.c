__int64 __fastcall os_if_wifi_pos_initiate_pasn_auth(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD **v12; // x8
  unsigned int v13; // w20
  __int64 v17; // x6
  __int64 v18; // x9
  int *v19; // x10
  int v20; // w11
  int v21; // w12
  int v22; // w14
  bool v23; // zf
  unsigned int v24; // w11
  unsigned int v25; // w13
  unsigned int v26; // w12
  int v27; // w11
  __int64 v28; // x0
  _BOOL4 v29; // w22
  __int64 v30; // x19
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w20
  __int64 result; // x0
  __int64 v41; // x23
  __int64 v42; // x25
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x25
  unsigned int v52; // w23
  __int64 v53; // x5
  __int64 v54; // x6
  __int64 v55; // x7
  int v56; // w8
  unsigned __int8 *v57; // x12
  _DWORD *v58; // x27
  int v59; // w9
  int v60; // w10
  int v61; // w11
  int v62; // w12
  __int64 v63; // x24
  __int64 v64; // x28
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  _WORD *v73; // x24
  __int64 v74; // x26
  __int64 v75; // x2
  __int64 v76; // x2
  __int64 v77; // x2
  const char *v78; // x2
  __int64 v79; // [xsp+0h] [xbp-60h]
  __int64 v80; // [xsp+8h] [xbp-58h]
  __int64 v81; // [xsp+10h] [xbp-50h]
  __int64 v82; // [xsp+18h] [xbp-48h]
  __int64 v83; // [xsp+20h] [xbp-40h]
  _WORD *v84; // [xsp+28h] [xbp-38h]
  __int64 v85; // [xsp+30h] [xbp-30h]
  _DWORD v86[3]; // [xsp+3Ch] [xbp-24h] BYREF
  _QWORD v87[3]; // [xsp+48h] [xbp-18h] BYREF

  v87[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD ***)(a1 + 680);
  v87[0] = 0;
  v87[1] = 0;
  if ( v12 )
  {
    v13 = a3;
    v17 = ((28 * a3 + 7) & 0x3FFCu) + 24;
    if ( a3 )
    {
      v18 = a3;
      v19 = (int *)(a2 + 108);
      do
      {
        v20 = *(v19 - 22);
        v21 = *(v19 - 5);
        v22 = *v19;
        v19 += 95;
        v23 = v20 == 0;
        v24 = (v20 + 7) & 0xFFFFFFFC;
        if ( v23 )
          v24 = 0;
        v25 = (v21 + 7) & 0xFFFFFFFC;
        if ( !v21 )
          v25 = 0;
        v26 = (v22 + 7) & 0xFFFFFFFC;
        v27 = v17 + v24;
        if ( !v22 )
          v26 = 0;
        --v18;
        v17 = v27 + v25 + v26 + 12;
      }
      while ( v18 );
    }
    v28 = _cfg80211_alloc_event_skb(**v12, *v12, 103, 197, 0, 55, v17, 2080);
    if ( v28 )
    {
      v29 = (a4 & 1) == 0;
      v30 = v28;
      v86[0] = v29;
      if ( (unsigned int)nla_put(v28, 1, 4, v86) )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: NLA put failed",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "os_if_wifi_pos_initiate_pasn_auth");
        v39 = 0;
      }
      else
      {
        v41 = *(_QWORD *)(v30 + 216);
        v42 = *(unsigned int *)(v30 + 208);
        if ( (nla_put(v30, 32770, 0, 0) & 0x80000000) != 0 || !(v41 + v42) )
        {
          v78 = "%s: NLA nest failed";
        }
        else
        {
          v84 = (_WORD *)(v41 + v42);
          if ( !a3 )
          {
LABEL_49:
            *v84 = *(_WORD *)(v30 + 216) + *(_WORD *)(v30 + 208) - (_WORD)v84;
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: action:%d num_pasn_peers:%d",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "os_if_wifi_pos_initiate_pasn_auth",
              v29,
              v13);
            _cfg80211_send_event_skb(v30, 2080);
            result = 0;
            goto LABEL_48;
          }
          v51 = 0;
          v52 = 0;
          v85 = 380LL * a3;
          while ( 1 )
          {
            if ( a2 + v51 )
            {
              v53 = *(unsigned __int8 *)(a2 + v51);
              v54 = *(unsigned __int8 *)(a2 + v51 + 1);
              v55 = *(unsigned __int8 *)(a2 + v51 + 2);
              v56 = *(unsigned __int8 *)(a2 + v51 + 5);
            }
            else
            {
              v55 = 0;
              v53 = 0;
              v54 = 0;
              v56 = 0;
            }
            v57 = (unsigned __int8 *)(a2 + v51);
            v58 = (_DWORD *)(a2 + v51 + 12);
            if ( a2 + v51 == -12 )
            {
              v61 = 0;
              v59 = 0;
              v60 = 0;
              v62 = 0;
            }
            else
            {
              v59 = *(unsigned __int8 *)v58;
              v60 = v57[13];
              v61 = v57[14];
              v62 = v57[17];
            }
            LODWORD(v83) = v62;
            LODWORD(v82) = v61;
            LODWORD(v81) = v60;
            LODWORD(v80) = v59;
            LODWORD(v79) = v56;
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: PASN peer_mac[%d]: %02x:%02x:%02x:**:**:%02x src_mac: %02x:%02x:%02x:**:**:%02x",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "os_if_wifi_pos_initiate_pasn_auth",
              v52,
              v53,
              v54,
              v55,
              v79,
              v80,
              v81,
              v82,
              v83);
            v63 = *(_QWORD *)(v30 + 216);
            v64 = *(unsigned int *)(v30 + 208);
            if ( (nla_put(v30, v52 | 0x8000, 0, 0) & 0x80000000) != 0 || (v73 = (_WORD *)(v63 + v64)) == nullptr )
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: NLA nest failed for iter:%d",
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                "os_if_wifi_pos_initiate_pasn_auth",
                v52);
              goto LABEL_46;
            }
            if ( (unsigned int)nla_put(v30, 2, 6, a2 + v51)
              || *v58 | *(unsigned __int16 *)(a2 + v51 + 16) && (unsigned int)nla_put(v30, 1, 6, a2 + v51 + 12) )
            {
              v78 = "%s: NLA put failed";
              goto LABEL_45;
            }
            v86[0] = osif_crypto_to_nl_suites(*(_DWORD *)(a2 + v51 + 372));
            if ( (unsigned int)nla_put(v30, 5, 4, v86) )
            {
              v78 = "%s: NLA put failed for PASN_PEER_AKM";
              goto LABEL_45;
            }
            v86[0] = *(_DWORD *)(a2 + v51 + 376);
            if ( (unsigned int)nla_put(v30, 6, 4, v86) )
            {
              v78 = "%s: NLA put failed for PASN_PEER_CIPHER";
              goto LABEL_45;
            }
            v74 = a2 + v51;
            v75 = *(unsigned int *)(a2 + v51 + 20);
            if ( (_DWORD)v75 )
            {
              if ( (unsigned int)nla_put(v30, 7, v75, v74 + 24) )
                break;
            }
            if ( (unsigned int)qdf_mem_cmp((const void *)(v74 + 92), v87, 0x10u) )
            {
              v76 = *(unsigned int *)(v74 + 88);
              if ( (_DWORD)v76 && (unsigned int)nla_put(v30, 8, v76, v74 + 92) )
              {
                v78 = "%s: NLA put failed for PASN_PEER_PMKID";
                goto LABEL_45;
              }
            }
            else
            {
              *(_DWORD *)(v74 + 88) = 0;
            }
            v77 = *(unsigned int *)(a2 + v51 + 108);
            if ( (_DWORD)v77 && (unsigned int)nla_put(v30, 10, v77, a2 + v51 + 112) )
            {
              v78 = "%s: NLA put failed for PASN_PEER_COOKIE";
              goto LABEL_45;
            }
            v51 += 380;
            ++v52;
            *v73 = *(_WORD *)(v30 + 216) + *(_WORD *)(v30 + 208) - (_WORD)v73;
            if ( v85 == v51 )
              goto LABEL_49;
          }
          v78 = "%s: NLA put failed for PASN_PEER_PASSWORD";
        }
LABEL_45:
        qdf_trace_msg(0x48u, 2u, v78, v43, v44, v45, v46, v47, v48, v49, v50, "os_if_wifi_pos_initiate_pasn_auth");
LABEL_46:
        v39 = 16;
      }
      sk_skb_reason_drop(0, v30, 2);
      result = v39;
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: OSIF priv is NULL",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "os_if_wifi_pos_initiate_pasn_auth");
    result = 16;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
