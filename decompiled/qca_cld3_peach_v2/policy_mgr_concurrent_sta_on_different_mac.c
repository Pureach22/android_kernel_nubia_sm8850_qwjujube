__int64 __fastcall policy_mgr_concurrent_sta_on_different_mac(__int64 a1)
{
  char v2; // w20
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  __int64 v13; // x25
  __int64 v14; // x22
  unsigned int v15; // w23
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x23
  unsigned __int64 v25; // x8
  __int64 v26; // x22
  unsigned int v27; // w25
  unsigned int v28; // w26
  int v29; // w27
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w28
  __int64 v39; // x20
  __int64 v40; // x24
  __int64 v41; // x23
  unsigned __int64 v42; // x8
  unsigned int v43; // w25
  unsigned int v44; // w26
  int v45; // w27
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w28
  __int64 v55; // x22
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v66; // [xsp+8h] [xbp-58h]
  int v67; // [xsp+10h] [xbp-50h]
  unsigned int v68; // [xsp+20h] [xbp-40h] BYREF
  unsigned int v69; // [xsp+24h] [xbp-3Ch] BYREF
  int v70; // [xsp+28h] [xbp-38h] BYREF
  char v71; // [xsp+2Ch] [xbp-34h]
  int v72; // [xsp+30h] [xbp-30h] BYREF
  char v73; // [xsp+34h] [xbp-2Ch]
  int v74; // [xsp+38h] [xbp-28h] BYREF
  char v75; // [xsp+3Ch] [xbp-24h]
  _QWORD v76[2]; // [xsp+40h] [xbp-20h] BYREF
  int v77; // [xsp+50h] [xbp-10h]
  __int64 v78; // [xsp+58h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOBYTE(v69) = 0;
  LOBYTE(v68) = 0;
  v75 = 0;
  v74 = 0;
  v73 = 0;
  v72 = 0;
  v77 = 0;
  v76[0] = 0;
  v76[1] = 0;
  v71 = 0;
  v70 = 0;
  if ( (wlan_mlme_support_non_dbs_dual_sta_roaming() & 1) == 0 )
  {
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
    {
      v2 = 0;
      goto LABEL_40;
    }
    context = policy_mgr_get_context(a1);
    if ( !context )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "policy_mgr_concurrent_sta_on_different_mac");
      v2 = 0;
      goto LABEL_40;
    }
    v12 = context;
    qdf_mutex_acquire(context + 56);
    policy_mgr_get_ml_and_non_ml_mode_count(
      a1,
      &v69,
      (__int64)&v74,
      &v68,
      (__int64)&v72,
      (unsigned __int64)v76,
      (unsigned __int64)&v70,
      0);
    v13 = (unsigned __int8)v68;
    LODWORD(v14) = (unsigned __int8)v69;
    v2 = 0;
    if ( (_BYTE)v68 )
    {
      v15 = (unsigned __int8)v68 + (unsigned __int8)v69;
      if ( v15 >= 2 )
      {
        policy_mgr_get_disabled_ml_sta_idx(a1, &v69, &v74, v76, &v70, v15);
        v14 = (unsigned __int8)v69;
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: num disabled_links: %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "policy_mgr_concurrent_sta_on_different_mac",
          (unsigned __int8)(v13 - v15 + v69));
        if ( (unsigned int)v13 >= 2 )
        {
          v67 = v14;
          v24 = 1;
          while ( 1 )
          {
            if ( v24 == 5 )
              goto LABEL_41;
            v25 = *((unsigned __int8 *)&v72 + v24);
            if ( v25 > 4 || (unsigned __int8)v72 > 4uLL )
              goto LABEL_41;
            v26 = v13;
            v27 = *((_DWORD *)v76 + v25);
            v28 = *((_DWORD *)v76 + (unsigned __int8)v72);
            v29 = policy_mgr_2_freq_same_mac_in_dbs(a1, v27, v28);
            v38 = (v29 & 1) != 0 ? policy_mgr_2_freq_same_mac_in_sbs(a1, v27, v28) : 1;
            v39 = jiffies;
            if ( policy_mgr_2_freq_always_on_same_mac___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: freq1 %d freq2 %d: Same mac:: DBS:%d SBS:%d",
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                "policy_mgr_2_freq_always_on_same_mac",
                v27,
                v28,
                v29 & 1,
                v38 & 1);
              policy_mgr_2_freq_always_on_same_mac___last_ticks = v39;
            }
            if ( (v29 & v38 & 1) == 0 )
              break;
            ++v24;
            v13 = v26;
            if ( v26 == v24 )
            {
              LODWORD(v14) = v67;
              goto LABEL_36;
            }
          }
          v2 = 1;
          LODWORD(v13) = v26;
          goto LABEL_38;
        }
        if ( (_DWORD)v14 )
        {
          v40 = 0;
          v41 = v14 - 1;
          v66 = v13;
          v67 = v14;
          do
          {
            if ( v40 == 5 || (v42 = *((unsigned __int8 *)&v74 + v40), v42 > 4) || (unsigned __int8)v72 > 4uLL )
LABEL_41:
              __break(0x5512u);
            v43 = *((_DWORD *)v76 + v42);
            v44 = *((_DWORD *)v76 + (unsigned __int8)v72);
            v45 = policy_mgr_2_freq_same_mac_in_dbs(a1, v43, v44);
            if ( (v45 & 1) != 0 )
              v54 = policy_mgr_2_freq_same_mac_in_sbs(a1, v43, v44);
            else
              v54 = 1;
            v55 = jiffies;
            if ( policy_mgr_2_freq_always_on_same_mac___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: freq1 %d freq2 %d: Same mac:: DBS:%d SBS:%d",
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                "policy_mgr_2_freq_always_on_same_mac",
                v43,
                v44,
                v45 & 1,
                v54 & 1);
              policy_mgr_2_freq_always_on_same_mac___last_ticks = v55;
            }
            if ( (v45 & v54 & 1) == 0 )
              break;
          }
          while ( v41 != v40++ );
          LODWORD(v13) = v66;
          v2 = v45 & v54 ^ 1;
LABEL_38:
          LODWORD(v14) = v67;
          goto LABEL_39;
        }
LABEL_36:
        v2 = 0;
      }
    }
LABEL_39:
    qdf_mutex_release(v12 + 56);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Non-ML STA count %d, ML STA count %d, sta concurrency on different mac %d",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "policy_mgr_concurrent_sta_on_different_mac",
      (unsigned int)v13,
      (unsigned int)v14,
      v2 & 1);
    goto LABEL_40;
  }
  v2 = 1;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return v2 & 1;
}
