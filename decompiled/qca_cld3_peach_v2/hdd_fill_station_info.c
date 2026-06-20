__int64 __fastcall hdd_fill_station_info(__int64 a1, int *a2)
{
  __int64 v2; // x25
  __int64 sta_info_by_mac; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  char v24; // w8
  __int64 result; // x0
  __int64 v26; // x4
  __int64 v27; // x9
  unsigned int v28; // w5
  int v29; // w11
  unsigned __int8 v30; // w12
  unsigned int v31; // w13
  __int64 v32; // x8
  unsigned __int8 v33; // w14
  char v34; // w10
  unsigned int v35; // w22
  char *v36; // x8
  __int64 v37; // x10
  char *v38; // x8
  char *v39; // x8
  char *v40; // x10
  int v41; // w10
  _BOOL4 v42; // w12
  unsigned int v43; // w9
  const char *v44; // x2
  const char *v45; // x3
  unsigned int v46; // w1
  __int64 v47; // x8
  char *v48; // x10
  unsigned __int64 v49; // x11
  unsigned __int64 v50; // x8
  unsigned __int16 *v51; // x12
  unsigned __int16 *v52; // x10
  unsigned __int16 *v53; // x9
  unsigned int v54; // w10
  unsigned int v55; // w8
  __int64 v56; // x8
  char *v57; // x10
  unsigned __int64 v58; // x11
  unsigned __int16 *v59; // x12
  unsigned __int16 *v60; // x10
  char v61; // w8
  bool v62; // w9
  char v63; // w10
  void *v64; // x0
  __int64 v65; // x0
  int v66; // w9
  int v67; // w9
  __int64 v68; // x4
  __int64 v69; // x5
  __int64 v70; // x6
  __int64 v71; // x7
  int v72; // w9
  int v73; // w10
  int v74; // w14
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  _BYTE *v83; // x0
  _BYTE *v84; // x22
  void *v85; // x0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v95; // x8
  __int64 v96; // x8
  __int64 v97; // x27
  unsigned __int64 v98; // x28
  __int64 v99; // x9
  __int64 v100; // x8
  unsigned int v107; // w9
  __int64 v108; // [xsp+0h] [xbp-70h]
  __int64 v109; // [xsp+48h] [xbp-28h] BYREF
  __int64 v110; // [xsp+50h] [xbp-20h] BYREF
  __int64 v111; // [xsp+58h] [xbp-18h] BYREF
  _QWORD v112[2]; // [xsp+60h] [xbp-10h] BYREF

  v112[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v110 = 0;
  sta_info_by_mac = hdd_get_sta_info_by_mac(a1 + 38848, a2, 16, 1);
  v112[0] = sta_info_by_mac;
  if ( sta_info_by_mac )
  {
    v14 = sta_info_by_mac;
    qdf_mem_copy((void *)(sta_info_by_mac + 224), (char *)a2 + 181, 2u);
    *(_DWORD *)(v14 + 160) = a2[9];
    *(_DWORD *)(v14 + 28) = a2[2];
    v23 = (unsigned int)a2[12];
    if ( (unsigned int)v23 >= 0x10 )
    {
      if ( (v23 & 0xFFFFFFF8) == 0x10 )
        v24 = 5;
      else
        v24 = 7;
    }
    else
    {
      v24 = byte_B358D8[v23];
    }
    *(_BYTE *)(v14 + 164) = v24;
    v26 = *((unsigned __int8 *)a2 + 60);
    *(_BYTE *)(v14 + 50) = v26;
    *(_DWORD *)(v14 + 52) = a2[16];
    *(_BYTE *)(v14 + 136) = *((_BYTE *)a2 + 76);
    v27 = *((unsigned __int8 *)a2 + 77);
    *(_BYTE *)(v14 + 137) = v27;
    *(_BYTE *)(v14 + 144) = *((_BYTE *)a2 + 78);
    *(_BYTE *)(v14 + 145) = *((_BYTE *)a2 + 79);
    v28 = a2[20];
    *(_DWORD *)(v14 + 148) = v28;
    v29 = a2[21];
    *(_BYTE *)(v14 + 152) = v29;
    v30 = *((_BYTE *)a2 + 88);
    *(_BYTE *)(v14 + 153) = v30;
    v31 = *((unsigned __int8 *)a2 + 89);
    *(_BYTE *)(v14 + 154) = v31;
    if ( (unsigned __int8)(v30 - 13) >= 0xF2u )
      v30 = 12;
    v32 = *((unsigned __int8 *)a2 + 90);
    v33 = v30;
    *(_BYTE *)(v14 + 155) = v32;
    if ( v30 <= v31 )
      v33 = v31;
    if ( v31 != 255 )
      v30 = v33;
    *(_BYTE *)(v14 + 156) = *((_BYTE *)a2 + 91);
    v34 = *((_BYTE *)a2 + 92);
    *(_BYTE *)(v14 + 157) = v34;
    *(_BYTE *)(v14 + 158) = *((_BYTE *)a2 + 93);
    *(_QWORD *)(v14 + 112) = jiffies;
    v35 = 10;
    switch ( v30 )
    {
      case 2u:
        break;
      case 4u:
        v35 = 20;
        break;
      case 0xBu:
        v35 = 55;
        break;
      case 0xCu:
        v35 = 60;
        break;
      case 0x12u:
        v35 = 90;
        break;
      case 0x16u:
        v35 = 110;
        break;
      case 0x18u:
        v35 = 120;
        break;
      case 0x24u:
        v35 = 180;
        break;
      case 0x2Cu:
        v35 = 220;
        break;
      case 0x30u:
        v35 = 240;
        break;
      case 0x42u:
        v35 = 330;
        break;
      case 0x48u:
        v35 = 360;
        break;
      case 0x60u:
        v35 = 480;
        break;
      case 0x6Cu:
        v35 = 540;
        break;
      default:
        v35 = 0;
        break;
    }
    if ( (unsigned __int8)v29 != 3 )
    {
      if ( (unsigned __int8)v29 != 2 )
      {
        if ( (unsigned __int8)v29 != 1 )
          goto LABEL_98;
        if ( (unsigned int)v32 >= 8 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: ht_mcs_idx %d is incorrect",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "calculate_max_phy_rate",
            (unsigned int)v32);
          goto LABEL_98;
        }
        if ( (_DWORD)v26 == 1 )
        {
          v40 = (char *)&supported_mcs_rate_nss1;
        }
        else
        {
          if ( (_DWORD)v26 != 2 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: nss %d not supported",
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              "calculate_max_phy_rate");
            goto LABEL_98;
          }
          v40 = (char *)&supported_mcs_rate_nss2;
        }
        if ( v28 == 1 )
        {
          v56 = 10 * v32;
          v57 = &v40[v56];
          v58 = v56 + 8;
          v50 = v56 + 4;
          v59 = (unsigned __int16 *)(v57 + 8);
          v60 = (unsigned __int16 *)(v57 + 4);
          if ( (_DWORD)v27 )
          {
            v50 = v58;
            v53 = v59;
          }
          else
          {
            v53 = v60;
          }
        }
        else
        {
          if ( v28 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid mode %d ch_width %d",
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              "calculate_max_phy_rate",
              1);
            goto LABEL_98;
          }
          v47 = 10 * v32;
          v48 = &v40[v47];
          v49 = v47 + 6;
          v50 = v47 + 2;
          v51 = (unsigned __int16 *)(v48 + 2);
          v52 = (unsigned __int16 *)(v48 + 6);
          if ( (_DWORD)v27 )
          {
            v50 = v49;
            v53 = v52;
          }
          else
          {
            v53 = v51;
          }
        }
        if ( v50 > 0x4E )
        {
          __break(1u);
LABEL_146:
          _X8 = (unsigned int *)(v2 + 2064);
          __asm { PRFM            #0x11, [X8] }
          do
            v107 = __ldxr(_X8);
          while ( __stxr(v107 + 1, _X8) );
          goto LABEL_110;
        }
        v55 = *v53;
LABEL_96:
        if ( v35 <= v55 )
          v35 = v55;
LABEL_98:
        *(_DWORD *)(v14 + 68) = 100 * v35;
        *(_BYTE *)(v14 + 56) = *((_BYTE *)a2 + 94);
        *(_DWORD *)(v14 + 60) = a2[24];
        *(_BYTE *)(v14 + 64) = *((_BYTE *)a2 + 100);
        if ( *((_BYTE *)a2 + 164) )
        {
          *(_BYTE *)(v14 + 166) = 1;
          hdd_copy_vht_caps((_WORD *)(v14 + 193), (__int64)(a2 + 41));
          *(_BYTE *)(v14 + 226) |= 2 * *(_BYTE *)(v14 + 166);
        }
        if ( *((_BYTE *)a2 + 104) )
        {
          *(_BYTE *)(v14 + 165) = 1;
          hdd_copy_ht_caps((_WORD *)(v14 + 167), (__int64)(a2 + 26));
        }
        v61 = *(_BYTE *)(v14 + 226) | (4 * *((_BYTE *)a2 + 183));
        *(_BYTE *)(v14 + 226) = v61;
        v62 = *((_BYTE *)a2 + 183) != 1 || *((_BYTE *)a2 + 164) || *((_BYTE *)a2 + 104) != 0;
        v63 = *((_BYTE *)a2 + 180);
        *(_QWORD *)(v14 + 216) = 0;
        *(_BYTE *)(v14 + 226) = v62 | (16 * v63) | v61;
        if ( a2[6] )
        {
          _qdf_mem_free(*(_QWORD *)(v14 + 272));
          *(_DWORD *)(v14 + 264) = 0;
          v64 = (void *)_qdf_mem_malloc((unsigned int)a2[6], "hdd_fill_station_info", 1835);
          *(_QWORD *)(v14 + 272) = v64;
          if ( v64 )
          {
            qdf_mem_copy(v64, *((const void **)a2 + 2), (unsigned int)a2[6]);
            *(_DWORD *)(v14 + 264) = a2[6];
          }
        }
        qdf_mem_copy((void *)(v14 + 38), a2 + 46, 6u);
        v65 = hdd_get_sta_info_by_mac(a1 + 38888, a2, 16, 1);
        v111 = v65;
        if ( v65 )
        {
          v66 = *a2;
          *(_WORD *)(v65 + 36) = *((_WORD *)a2 + 2);
          *(_DWORD *)(v65 + 32) = v66;
          v67 = a2[46];
          *(_WORD *)(v65 + 42) = *((_WORD *)a2 + 94);
          *(_DWORD *)(v65 + 38) = v67;
          hdd_put_sta_info_ref(a1 + 38888, &v111, 1, 16);
LABEL_110:
          v68 = *(unsigned __int8 *)(v14 + 136);
          v69 = *(unsigned __int8 *)(v14 + 137);
          v70 = *(unsigned __int8 *)(v14 + 144);
          *(_BYTE *)(v14 + 508) = *((_BYTE *)a2 + 191);
          v71 = *(unsigned __int8 *)(v14 + 145);
          v72 = *(unsigned __int8 *)(v14 + 48);
          v73 = *(unsigned __int8 *)(v14 + 152);
          v74 = *(_DWORD *)(v14 + 68);
          *(_WORD *)(v14 + 510) = *((_WORD *)a2 + 96);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: cap %d %d %d %d %d %d %d %d %d %x %d",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "hdd_fill_station_info",
            v68,
            v69,
            v70,
            v71,
            v72,
            *(_DWORD *)(v14 + 148),
            v73,
            *((unsigned __int8 *)a2 + 32),
            *((unsigned __int8 *)a2 + 60),
            a2[16],
            v74);
          LODWORD(v108) = *(unsigned __int8 *)(v14 + 158);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: rate info %d %d %d %d %d",
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            "hdd_fill_station_info",
            *(unsigned __int8 *)(v14 + 153),
            *(unsigned __int8 *)(v14 + 154),
            *(unsigned __int8 *)(v14 + 155),
            *(unsigned __int8 *)(v14 + 157),
            v108);
LABEL_111:
          result = hdd_put_sta_info_ref(a1 + 38848, v112, 1, 16);
          goto LABEL_112;
        }
        v83 = (_BYTE *)_qdf_mem_malloc(0x200u, "hdd_fill_station_info", 1852);
        v111 = (__int64)v83;
        if ( !v83 )
          goto LABEL_111;
        v84 = v83;
        v2 = a1 + 36864;
        qdf_mem_copy(v83, (const void *)v14, 0x200u);
        v84[432] = 0;
        v85 = (void *)_qdf_mem_malloc((unsigned int)a2[6], "hdd_fill_station_info", 1859);
        *((_QWORD *)v84 + 34) = v85;
        if ( v85 )
        {
          qdf_mem_copy(v85, *((const void **)a2 + 2), (unsigned int)a2[6]);
          *((_DWORD *)v84 + 66) = a2[6];
        }
        *((_DWORD *)v84 + 70) = 0;
        if ( *(int *)(a1 + 38928) <= 34 )
        {
          hdd_sta_info_attach(a1 + 38888, v84);
          goto LABEL_146;
        }
        v109 = 0;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: reached max caching, removing oldest",
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          "hdd_fill_station_info");
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 38912);
        }
        else
        {
          raw_spin_lock_bh(a1 + 38912);
          *(_QWORD *)(a1 + 38920) |= 1uLL;
        }
        hdd_get_front_sta_info_no_lock(a1 + 38888, &v109);
        if ( v109 )
          hdd_take_sta_info_ref(a1 + 38888, v109, 0, 16);
        hdd_get_next_sta_info_no_lock(a1 + 38888);
        v95 = *(_QWORD *)(a1 + 38920);
        if ( (v95 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 38920) = v95 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 38912);
          v96 = v109;
          if ( v109 )
          {
LABEL_127:
            v97 = 0;
            v98 = _ReadStatusReg(SP_EL0);
            do
            {
              while ( 1 )
              {
                v99 = *(_QWORD *)(v96 + 120);
                if ( v99 && (!v97 || v99 - v97 < 0) )
                {
                  v97 = *(_QWORD *)(v96 + 120);
                  v110 = v96;
                }
                hdd_put_sta_info_ref(a1 + 38888, &v109, 1, 16);
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (*(_DWORD *)(v98 + 16) & 0xF0000) != 0
                  || (*(_DWORD *)(v98 + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(a1 + 38912);
                }
                else
                {
                  raw_spin_lock_bh(a1 + 38912);
                  *(_QWORD *)(a1 + 38920) |= 1uLL;
                }
                v109 = 0;
                hdd_get_next_sta_info_no_lock(a1 + 38888);
                v100 = *(_QWORD *)(a1 + 38920);
                if ( (v100 & 1) != 0 )
                  break;
                raw_spin_unlock(a1 + 38912);
                v96 = v109;
                if ( !v109 )
                  goto LABEL_143;
              }
              *(_QWORD *)(a1 + 38920) = v100 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a1 + 38912);
              v96 = v109;
            }
            while ( v109 );
          }
        }
        else
        {
          raw_spin_unlock(a1 + 38912);
          v96 = v109;
          if ( v109 )
            goto LABEL_127;
        }
LABEL_143:
        hdd_sta_info_detach(a1 + 38888, &v110);
        hdd_sta_info_attach(a1 + 38888, v84);
        goto LABEL_110;
      }
      if ( (_DWORD)v26 == 1 )
      {
        v36 = (char *)&supported_vht_mcs_rate_nss1;
        if ( *(_BYTE *)(v14 + 508) )
          goto LABEL_37;
LABEL_49:
        v41 = v34 & 3;
        switch ( v41 )
        {
          case 0:
            v37 = 7;
            goto LABEL_38;
          case 2:
            v37 = 8;
            if ( v28 )
              v37 = 9;
            goto LABEL_38;
          case 1:
            v37 = 8;
            goto LABEL_38;
        }
        v44 = "%s: vht mcs map %x not supported";
        v45 = "get_max_rate_vht";
LABEL_94:
        v46 = 2;
        v26 = 3;
        goto LABEL_95;
      }
      if ( (_DWORD)v26 == 2 )
      {
        v36 = (char *)&supported_vht_mcs_rate_nss2;
        if ( *(_BYTE *)(v14 + 508) )
        {
LABEL_37:
          v37 = 11;
LABEL_38:
          switch ( v28 )
          {
            case 2u:
              v38 = &v36[14 * v37 + 2 + 2 * v27];
              goto LABEL_80;
            case 1u:
              v38 = &v36[14 * v37 + 6 + 2 * v27];
              goto LABEL_80;
            case 0u:
              v38 = &v36[14 * v37 + 10 + 2 * v27];
LABEL_80:
              v55 = *(unsigned __int16 *)v38;
              goto LABEL_96;
          }
          v44 = "%s: ch_width %d not supported";
          v45 = "get_max_rate_vht";
          goto LABEL_88;
        }
        goto LABEL_49;
      }
      v44 = "%s: nss %d not supported";
      v45 = "get_max_rate_vht";
LABEL_58:
      v46 = 8;
LABEL_95:
      qdf_trace_msg(0x33u, v46, v44, v15, v16, v17, v18, v19, v20, v21, v22, v45, v26);
      v55 = 0;
      goto LABEL_96;
    }
    if ( (_DWORD)v26 == 1 )
    {
      v39 = (char *)&supported_he_mcs_rate_nss1;
    }
    else
    {
      if ( (_DWORD)v26 != 2 )
      {
        v44 = "%s: nss %d not supported";
        v45 = "get_max_rate_he";
        goto LABEL_58;
      }
      v39 = (char *)&supported_he_mcs_rate_nss2;
    }
    v42 = v27 == 0;
    if ( *(_WORD *)(v14 + 510) )
    {
      v43 = 13;
    }
    else
    {
      if ( (v34 & 3) == 3 )
      {
        v44 = "%s: HE mcs map %x not supported";
        v45 = "get_max_rate_he";
        goto LABEL_94;
      }
      v43 = (v34 & 3) + 9;
    }
    v54 = 2 * v42;
    switch ( v28 )
    {
      case 2u:
        v38 = &v39[50 * v43 + 26 + 2 * v54];
        goto LABEL_80;
      case 1u:
        v38 = &v39[50 * v43 + 14 + 2 * v54];
        goto LABEL_80;
      case 0u:
        v38 = &v39[50 * v43 + 2 + 2 * v54];
        goto LABEL_80;
    }
    if ( v28 - 3 <= 1 )
    {
      v38 = &v39[50 * v43 + 38 + 2 * v54];
      goto LABEL_80;
    }
    v44 = "%s: ch_width %d not supported";
    v45 = "get_max_rate_he";
LABEL_88:
    v46 = 2;
    v26 = v28;
    goto LABEL_95;
  }
  result = qdf_trace_msg(0x33u, 2u, "%s: invalid stainfo", v6, v7, v8, v9, v10, v11, v12, v13, "hdd_fill_station_info");
LABEL_112:
  _ReadStatusReg(SP_EL0);
  return result;
}
