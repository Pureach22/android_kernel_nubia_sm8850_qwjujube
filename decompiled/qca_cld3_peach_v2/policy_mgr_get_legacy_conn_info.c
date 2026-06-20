__int64 __fastcall policy_mgr_get_legacy_conn_info(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned __int8 a5)
{
  __int64 context; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _QWORD *v18; // x25
  unsigned int v19; // w24
  unsigned __int64 v20; // x26
  unsigned int v21; // w20
  __int64 *v22; // x19
  unsigned int v23; // w28
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x27
  char is_mlo_vdev; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int *v43; // x8
  char v44; // w7
  __int64 v45; // x0
  _DWORD *v46; // x8
  int v47; // w8
  __int64 v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x25
  double v58; // d0
  char v59; // w0
  unsigned int *v60; // x8
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  const char *v68; // x6
  int v69; // w8
  __int64 v70; // x8
  __int64 v71; // x11
  __int64 v72; // x10
  unsigned __int64 v73; // x13
  unsigned int v74; // w14
  unsigned int v75; // w17
  unsigned int v76; // w15
  bool v77; // cf
  bool v78; // zf
  unsigned int v79; // w15
  unsigned int v80; // w17
  unsigned int v81; // w16
  unsigned int v82; // w17
  unsigned int v83; // w16
  unsigned int v84; // w16
  unsigned int v85; // w17
  char v86; // w15
  int v87; // w17
  int v88; // w0
  char v90; // [xsp+4h] [xbp-2Ch]
  _QWORD *v91; // [xsp+8h] [xbp-28h]
  unsigned int v93; // [xsp+1Ch] [xbp-14h] BYREF
  int v94; // [xsp+20h] [xbp-10h]
  _BYTE v95[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v96; // [xsp+28h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "policy_mgr_get_legacy_conn_info");
    v21 = 0;
    goto LABEL_79;
  }
  v18 = (_QWORD *)context;
  v19 = a5;
  qdf_mutex_acquire(context + 56);
  if ( !a5 )
  {
    v21 = 0;
    goto LABEL_78;
  }
  v20 = 0;
  v21 = 0;
  v22 = &pm_conc_connection_list;
  v95[0] = 0;
  v94 = 0;
  do
  {
    if ( *((_BYTE *)v22 + 28) == 1 )
    {
      v23 = *((unsigned __int8 *)v22 + 24);
      v24 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              *v18,
              *((unsigned __int8 *)v22 + 24),
              24);
      if ( v24 )
      {
        v33 = v24;
        is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v24, v25, v26, v27, v28, v29, v30, v31, v32);
        v43 = (unsigned int *)*(unsigned int *)v22;
        if ( (is_mlo_vdev & 1) != 0 && !(_DWORD)v43 || (unsigned int)v43 >= 4 )
        {
LABEL_33:
          wlan_objmgr_vdev_release_ref(v33, 0x18u, v43, v35, v36, v37, v38, v39, v40, v41, v42);
          goto LABEL_34;
        }
        if ( (_DWORD)v43 == 1 )
        {
          v93 = 4;
          v45 = policy_mgr_get_context(a1);
          if ( v45 )
          {
            v46 = *(_DWORD **)(v45 + 368);
            if ( v46 )
            {
              if ( *(v46 - 1) != -333933844 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, _QWORD, unsigned int *))v46)(a1, v23, &v93);
              if ( v93 <= 1 )
              {
                if ( v21 >= 5 )
                  goto LABEL_80;
                v44 = 3;
                goto LABEL_30;
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x4Fu,
              2u,
              "%s: Invalid Context",
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              "policy_mgr_is_acs_2ghz_only_sap");
          }
        }
        else if ( !(_DWORD)v43 )
        {
          if ( v21 >= 5 )
            goto LABEL_80;
          v44 = 4;
LABEL_30:
          *(_BYTE *)(a2 + v21) = v23;
          v68 = "Unknown";
          v69 = *((_DWORD *)v22 + 1);
          v95[v21 - 4] = v44;
          *(_DWORD *)(a3 + 4LL * v21) = v69;
          v70 = *(unsigned int *)v22;
          *(_DWORD *)(a4 + 4LL * v21) = v70;
          if ( (unsigned int)v70 <= 6 )
            v68 = off_AD9240[v70];
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: vdev %d freq %d mode %s pri %d",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "policy_mgr_get_legacy_conn_info",
            v23,
            *(unsigned int *)(a3 + 4LL * v21++),
            v68);
          goto LABEL_33;
        }
        v47 = *(_DWORD *)v22;
        if ( (*(_DWORD *)v22 & 0xFFFFFFFE) == 2 )
        {
          v91 = v18;
          v48 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v23, 24);
          if ( v48 )
          {
            v57 = v48;
            v58 = wlan_is_vdev_traffic_ll_ht();
            v90 = v59;
            wlan_objmgr_vdev_release_ref(v57, 0x18u, v60, v58, v61, v62, v63, v64, v65, v66, v67);
            if ( (v90 & 1) != 0 )
            {
              v18 = v91;
              if ( v21 >= 5 )
                goto LABEL_80;
              v44 = 2;
              goto LABEL_30;
            }
          }
          else
          {
            qdf_trace_msg(
              0x4Fu,
              2u,
              "%s: invalid vdev for id %d",
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              "policy_mgr_is_vdev_high_tput_or_low_latency",
              v23);
          }
          v47 = *(_DWORD *)v22;
          v18 = v91;
        }
        v44 = v47 == 1;
        if ( v21 > 4 )
LABEL_80:
          __break(0x5512u);
        goto LABEL_30;
      }
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: invalid vdev for id %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "policy_mgr_get_legacy_conn_info",
        v23);
    }
LABEL_34:
    if ( v20 > 3 )
      break;
    ++v20;
    v22 = (__int64 *)((char *)v22 + 36);
  }
  while ( v21 < v19 );
  if ( v21 )
  {
    v71 = 0;
    v72 = a2 + 2;
    do
    {
      v73 = v71 + 1;
      v74 = (unsigned __int8)v71;
      if ( v71 + 1 < (unsigned __int64)v21 )
      {
        if ( (unsigned __int8)v71 > 4u || v73 > 4 )
          goto LABEL_80;
        v75 = (unsigned __int8)v95[v71 - 4];
        v76 = (unsigned __int8)v95[v71 - 3];
        v77 = v75 >= v76;
        v78 = v75 == v76;
        v79 = (unsigned __int8)(v71 + 1);
        if ( v77 )
        {
          v79 = (unsigned __int8)v71;
          if ( v78 )
          {
            if ( *(unsigned __int8 *)(a2 + v71) <= (unsigned int)*(unsigned __int8 *)(v72 + v71 - 1) )
              v79 = (unsigned __int8)v71;
            else
              v79 = (unsigned __int8)(v71 + 1);
          }
        }
        if ( v21 == (unsigned __int8)(v71 + 2) )
          goto LABEL_50;
        if ( v71 == 3 )
          goto LABEL_80;
        v80 = (unsigned __int8)v95[v79 - 4];
        v74 = (unsigned __int8)(v71 + 2);
        v81 = (unsigned __int8)v95[v71 - 2];
        if ( v80 >= v81 )
        {
          if ( v80 == v81 )
          {
            if ( *(unsigned __int8 *)(a2 + v79) <= (unsigned int)*(unsigned __int8 *)(v72 + v71) )
              v74 = v79;
          }
          else
          {
            v74 = v79;
          }
        }
        if ( v21 == (unsigned __int8)(v71 + 3) )
          goto LABEL_74;
        if ( v74 > 4 || v73 > 2 )
          goto LABEL_80;
        v82 = (unsigned __int8)v95[v74 - 4];
        v79 = (unsigned __int8)(v71 + 3);
        v83 = (unsigned __int8)v95[v71 - 1];
        if ( v82 >= v83 )
        {
          if ( v82 == v83 )
          {
            if ( *(unsigned __int8 *)(a2 + v74) <= (unsigned int)*(unsigned __int8 *)(v72 + v71 + 1) )
              v79 = v74;
          }
          else
          {
            v79 = v74;
          }
        }
        if ( v21 == (unsigned __int8)(v71 + 4) )
        {
LABEL_50:
          v74 = v79;
        }
        else
        {
          if ( v79 > 4 || v71 == 1 )
            goto LABEL_80;
          v84 = (unsigned __int8)v95[v79 - 4];
          v85 = (unsigned __int8)v95[v71];
          v74 = (unsigned __int8)(v71 + 4);
          if ( v84 >= v85 )
          {
            if ( v84 == v85 )
            {
              if ( *(unsigned __int8 *)(a2 + v79) <= (unsigned int)*(unsigned __int8 *)(v72 + v71 + 2) )
                v74 = v79;
            }
            else
            {
              v74 = v79;
            }
          }
          if ( v21 != ((unsigned __int8)v73 | 4) )
            goto LABEL_80;
        }
      }
LABEL_74:
      if ( v71 != v74 )
      {
        v86 = *(_BYTE *)(a2 + v71);
        v87 = *(_DWORD *)(a3 + 4 * v71);
        v88 = *(_DWORD *)(a4 + 4 * v71);
        *(_BYTE *)(a2 + v71) = *(_BYTE *)(a2 + v74);
        *(_DWORD *)(a3 + 4 * v71) = *(_DWORD *)(a3 + 4LL * v74);
        *(_DWORD *)(a4 + 4 * v71) = *(_DWORD *)(a4 + 4LL * v74);
        *(_BYTE *)(a2 + v74) = v86;
        *(_DWORD *)(a3 + 4LL * v74) = v87;
        *(_DWORD *)(a4 + 4LL * v74) = v88;
      }
      ++v71;
    }
    while ( v21 != v73 );
  }
LABEL_78:
  qdf_mutex_release((__int64)(v18 + 7));
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return v21;
}
