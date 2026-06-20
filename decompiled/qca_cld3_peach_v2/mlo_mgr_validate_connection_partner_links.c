unsigned __int8 *__fastcall mlo_mgr_validate_connection_partner_links(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int8 *result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  unsigned __int64 v30; // x24
  unsigned __int8 v31; // w22
  unsigned __int8 v32; // w23
  _DWORD *v33; // x25
  __int64 v34; // x26
  __int64 v35; // x20
  void *v36; // x0
  _DWORD *v37; // x8
  int v38; // w9
  __int64 v39; // x10
  bool v40; // zf
  __int64 v41; // x8
  bool v42; // zf
  bool v43; // zf
  bool v44; // zf
  __int64 v45; // x9
  __int64 v46; // x10
  __int64 v47; // x8
  unsigned __int64 v48; // x27
  unsigned __int8 v49; // w26
  unsigned __int8 *v50; // x24
  __int64 v51; // x4
  __int64 v52; // x5
  __int64 v53; // x6
  __int64 v54; // x7
  unsigned __int64 v55; // x4
  unsigned int v57; // w8
  unsigned __int64 v58; // x22
  unsigned __int8 *v59; // x23
  __int64 v60; // x27
  unsigned __int8 *v61; // x20
  unsigned __int8 *v63; // x21
  unsigned __int64 v64; // x24
  _DWORD *v65; // [xsp+0h] [xbp-60h]
  __int64 v66; // [xsp+10h] [xbp-50h]
  __int64 v67; // [xsp+18h] [xbp-48h] BYREF
  __int64 v68; // [xsp+20h] [xbp-40h]
  __int64 v69; // [xsp+28h] [xbp-38h]
  __int64 v70; // [xsp+30h] [xbp-30h]
  __int64 v71; // [xsp+38h] [xbp-28h]
  __int64 v72; // [xsp+40h] [xbp-20h]
  int v73; // [xsp+48h] [xbp-18h] BYREF
  __int16 v74; // [xsp+4Ch] [xbp-14h]
  __int64 v75; // [xsp+58h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v74 = 0;
  v73 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  result = (unsigned __int8 *)wlan_vdev_get_bss_peer_mac(a1, &v73, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Failed to get BSSID for VDEV %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlo_mgr_validate_connection_partner_links",
      *(unsigned __int8 *)(a1 + 168));
    goto LABEL_3;
  }
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = a2 + 8;
  v34 = *(_QWORD *)(*(_QWORD *)(a1 + 1360) + 3880LL);
  v66 = a1;
  v65 = a2 + 152;
  do
  {
    v37 = (_DWORD *)(v34 + v30 + 72);
    if ( *v37 | *(unsigned __int16 *)(v34 + v30 + 76) )
    {
      v38 = *a2;
      ++v31;
      if ( !*a2 )
        goto LABEL_7;
      v39 = v34 + v30;
      v40 = *v33 == *v37 && *((unsigned __int16 *)a2 + 6) == *(unsigned __int16 *)(v34 + v30 + 76);
      if ( v40 && a2[14] == *(unsigned __int8 *)(v39 + 54) )
      {
        v41 = 0;
        result = a2 + 8;
      }
      else
      {
        if ( v38 == 1 )
          goto LABEL_7;
        v42 = *((_DWORD *)a2 + 14) == *v37 && *((unsigned __int16 *)a2 + 30) == *(unsigned __int16 *)(v34 + v30 + 76);
        if ( v42 && a2[62] == *(unsigned __int8 *)(v39 + 54) )
        {
          result = a2 + 56;
          v41 = 1;
        }
        else
        {
          if ( v38 == 2 )
            goto LABEL_7;
          v43 = *((_DWORD *)a2 + 26) == *v37 && *((unsigned __int16 *)a2 + 54) == *(unsigned __int16 *)(v34 + v30 + 76);
          if ( v43 && a2[110] == *(unsigned __int8 *)(v39 + 54) )
          {
            result = a2 + 104;
            v41 = 2;
          }
          else
          {
            if ( v38 == 3 )
              goto LABEL_7;
            v44 = *v65 == *v37 && *((unsigned __int16 *)a2 + 78) == *(unsigned __int16 *)(v34 + v30 + 76);
            if ( !v44 || a2[158] != *(unsigned __int8 *)(v39 + 54) )
            {
              if ( v38 != 4 )
                goto LABEL_78;
LABEL_7:
              v35 = v34 + v30;
              v36 = *(void **)(v34 + v30 + 80);
              *(_WORD *)(v34 + v30 + 76) = 0;
              *v37 = 0;
              result = (unsigned __int8 *)qdf_mem_set(v36, 0x28u, 0);
              *(_BYTE *)(v35 + 54) = -1;
              *(_QWORD *)(v35 + 64) = 0;
              goto LABEL_8;
            }
            result = a2 + 152;
            v41 = 3;
          }
        }
      }
      ++v32;
      if ( v29 != v41 )
      {
        v45 = *((_QWORD *)result + 3);
        v69 = *((_QWORD *)result + 2);
        v70 = v45;
        v46 = *((_QWORD *)result + 5);
        v71 = *((_QWORD *)result + 4);
        v72 = v46;
        v47 = *((_QWORD *)result + 1);
        v67 = *(_QWORD *)result;
        v68 = v47;
        qdf_mem_copy(result, &v33[v30 / 4], 0x30u);
        result = (unsigned __int8 *)qdf_mem_copy(&v33[v30 / 4], &v67, 0x30u);
      }
    }
LABEL_8:
    v30 += 48LL;
    ++v29;
  }
  while ( v30 != 96 );
  if ( v31 == v32 && *a2 == v32 )
    goto LABEL_4;
  if ( !v31 )
  {
LABEL_3:
    qdf_mem_set(a2, 0xB0u, 0);
    result = (unsigned __int8 *)qdf_trace_msg(
                                  0x8Fu,
                                  8u,
                                  "%s: Clearing all partner links",
                                  v21,
                                  v22,
                                  v23,
                                  v24,
                                  v25,
                                  v26,
                                  v27,
                                  v28,
                                  "mlo_mgr_validate_connection_partner_links");
    goto LABEL_4;
  }
  if ( !*a2 )
    goto LABEL_4;
  v48 = 0;
  v49 = 0;
  v50 = a2 + 8;
  while ( 2 )
  {
    if ( v48 == 4 )
      goto LABEL_78;
    if ( v73 == *(_DWORD *)v50 && v74 == *((_WORD *)v50 + 2) )
    {
      if ( v50 )
      {
        v51 = *v50;
        v52 = v50[1];
        v53 = v50[2];
        v54 = v50[5];
      }
      else
      {
        v53 = 0;
        v51 = 0;
        v52 = 0;
        v54 = 0;
      }
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Remove partner link with same BSSID %02x:%02x:%02x:**:**:%02x",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "mlo_mgr_validate_connection_partner_links",
        v51,
        v52,
        v53,
        v54,
        v65);
      goto LABEL_52;
    }
    result = (unsigned __int8 *)mlo_mgr_get_ap_link_info(v66, v50);
    if ( !result || result[6] != v50[6] )
    {
LABEL_52:
      result = (unsigned __int8 *)qdf_mem_set(v50, 0x30u, 0);
      v50[6] = -1;
      goto LABEL_53;
    }
    ++v49;
LABEL_53:
    v55 = *a2;
    ++v48;
    v50 += 48;
    if ( v48 < v55 )
      continue;
    break;
  }
  if ( (_DWORD)v55 != v49 )
  {
    result = (unsigned __int8 *)qdf_trace_msg(
                                  0x8Fu,
                                  8u,
                                  "%s: Partner links %d, valid links %d required %d",
                                  v13,
                                  v14,
                                  v15,
                                  v16,
                                  v17,
                                  v18,
                                  v19,
                                  v20,
                                  "mlo_mgr_validate_connection_partner_links",
                                  v55,
                                  v49,
                                  v31);
    v57 = *a2;
    if ( *a2 )
    {
      v58 = 0;
      v59 = a2 + 56;
      v60 = 1;
      while ( 1 )
      {
        if ( v58 == 4 )
          goto LABEL_78;
        v61 = (unsigned __int8 *)&v33[12 * v58++];
        if ( v61[6] == 255 && v58 < v57 )
          break;
LABEL_66:
        ++v60;
        v59 += 48;
        if ( v58 >= v57 )
          goto LABEL_77;
      }
      v63 = v59;
      v64 = v60;
      while ( v64 != 4 )
      {
        if ( v63[6] != 255 )
        {
          qdf_mem_copy(v61, v63, 0x30u);
          result = (unsigned __int8 *)qdf_mem_set(v63, 0x30u, 0);
          v63[6] = -1;
          v57 = *a2;
        }
        ++v64;
        v63 += 48;
        if ( v64 >= v57 )
          goto LABEL_66;
      }
LABEL_78:
      __break(0x5512u);
    }
LABEL_77:
    *a2 = v49;
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
