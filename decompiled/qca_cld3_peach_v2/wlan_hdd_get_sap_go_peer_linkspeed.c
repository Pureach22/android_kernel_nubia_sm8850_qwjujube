__int64 __fastcall wlan_hdd_get_sap_go_peer_linkspeed(__int64 *a1, _DWORD *a2, __int64 a3, unsigned __int8 a4)
{
  __int64 v5; // x21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned __int64 StatusReg; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x1
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _QWORD *v41; // x8
  unsigned __int64 v42; // x25
  int v44; // w10
  int v45; // w8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x8
  __int64 result; // x0
  unsigned int linkspeed_for_peermac; // w20
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  _QWORD *v66; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v67; // [xsp+10h] [xbp-30h] BYREF
  int v68; // [xsp+18h] [xbp-28h] BYREF
  unsigned __int16 v69; // [xsp+1Ch] [xbp-24h]
  _QWORD v70[4]; // [xsp+20h] [xbp-20h] BYREF

  v70[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a1;
  v69 = 0;
  v68 = 0;
  memset(v70, 0, 19);
  v66 = nullptr;
  v67 = nullptr;
  if ( sscanf((const char *)(a3 + a4), "%17s", v70) == 1 )
  {
    BYTE1(v70[2]) = 0;
    if ( (mac_pton(v70, &v68) & 1) != 0 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v5 + 38872);
      }
      else
      {
        raw_spin_lock_bh(v5 + 38872);
        *(_QWORD *)(v5 + 38880) |= 1uLL;
      }
      hdd_get_front_sta_info_no_lock((_QWORD *)(v5 + 38848), &v67);
      v23 = v67;
      if ( v67 )
      {
        hdd_take_sta_info_ref(v5 + 38848, (__int64)v67, 0, 0x17u, v15, v16, v17, v18, v19, v20, v21, v22);
        v23 = v67;
      }
      hdd_get_next_sta_info_no_lock((_QWORD *)(v5 + 38848), v23, &v66);
      if ( v66 )
        hdd_take_sta_info_ref(v5 + 38848, (__int64)v66, 0, 0x17u, v24, v25, v26, v27, v28, v29, v30, v31);
      v32 = *(_QWORD *)(v5 + 38880);
      if ( (v32 & 1) != 0 )
      {
        *(_QWORD *)(v5 + 38880) = v32 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v5 + 38872);
        v41 = v67;
        if ( v67 )
          goto LABEL_13;
      }
      else
      {
        raw_spin_unlock(v5 + 38872);
        v41 = v67;
        if ( v67 )
        {
LABEL_13:
          v42 = _ReadStatusReg(SP_EL0);
          while ( 1 )
          {
            if ( *((_DWORD *)v41 + 8) != -1 || *((__int16 *)v41 + 18) != -1 )
            {
              v44 = *((_DWORD *)v41 + 8);
              v45 = *((unsigned __int16 *)v41 + 18);
              if ( v68 == v44 && v69 == v45 )
                break;
            }
            hdd_put_sta_info_ref(v5 + 38848, (__int64 *)&v67, 1, 0x17u, v33, v34, v35, v36, v37, v38, v39, v40);
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(v42 + 16) & 0xF0000) != 0
              || (*(_DWORD *)(v42 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v5 + 38872);
            }
            else
            {
              raw_spin_lock_bh(v5 + 38872);
              *(_QWORD *)(v5 + 38880) |= 1uLL;
            }
            v67 = v66;
            hdd_get_next_sta_info_no_lock((_QWORD *)(v5 + 38848), v66, &v66);
            if ( v66 )
              hdd_take_sta_info_ref(v5 + 38848, (__int64)v66, 0, 0x17u, v47, v48, v49, v50, v51, v52, v53, v54);
            v55 = *(_QWORD *)(v5 + 38880);
            if ( (v55 & 1) != 0 )
            {
              *(_QWORD *)(v5 + 38880) = v55 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v5 + 38872);
              v41 = v67;
              if ( !v67 )
                goto LABEL_41;
            }
            else
            {
              raw_spin_unlock(v5 + 38872);
              v41 = v67;
              if ( !v67 )
                goto LABEL_41;
            }
          }
          linkspeed_for_peermac = wlan_hdd_get_linkspeed_for_peermac(
                                    *(__int64 **)(v5 + 52832),
                                    &v68,
                                    a2,
                                    v33,
                                    v34,
                                    v35,
                                    v36,
                                    v37,
                                    v38,
                                    v39,
                                    v40);
          hdd_put_sta_info_ref(v5 + 38848, (__int64 *)&v67, 1, 0x17u, v58, v59, v60, v61, v62, v63, v64, v65);
          if ( v66 )
            hdd_put_sta_info_ref(v5 + 38848, (__int64 *)&v66, 1, 0x17u, v33, v34, v35, v36, v37, v38, v39, v40);
          if ( !linkspeed_for_peermac )
          {
            result = 0;
            *a2 /= 0x1F4u;
            goto LABEL_43;
          }
LABEL_42:
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Unable to retrieve SAP/GO linkspeed",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "wlan_hdd_get_sap_go_peer_linkspeed");
          result = linkspeed_for_peermac;
          goto LABEL_43;
        }
      }
LABEL_41:
      linkspeed_for_peermac = 1;
      goto LABEL_42;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: String to Hex conversion Failed",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_hdd_get_sap_go_peer_linkspeed");
    result = 4294967274LL;
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
