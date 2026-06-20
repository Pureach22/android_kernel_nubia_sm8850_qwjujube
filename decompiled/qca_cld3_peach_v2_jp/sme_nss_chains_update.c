__int64 __fastcall sme_nss_chains_update(__int64 a1, unsigned int *a2, unsigned int a3)
{
  unsigned __int8 v4; // w22
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  unsigned int *v25; // x8
  unsigned int v26; // w24
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 dynamic_vdev_config; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  _QWORD *v44; // x23
  _DWORD *ini_vdev_config; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x27
  char *v55; // x8
  char *v56; // x9
  char *v57; // x10
  char *v58; // x11
  char *v59; // x12
  const char *v60; // x2
  char v61; // w14
  unsigned int v62; // w7
  char v63; // w6
  unsigned int v64; // w24
  unsigned int v65; // w25
  unsigned int v66; // w28
  unsigned int v67; // w30
  unsigned int v68; // w5
  unsigned int v69; // w14
  unsigned int v70; // w7
  unsigned int v71; // w7
  __int64 v72; // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x8
  __int64 v98; // x9
  __int64 v99; // x8
  __int64 v100; // x10
  __int64 v101; // x11
  _QWORD *v103; // [xsp+0h] [xbp-10h]

  v4 = a3;
  v6 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)(a1 + 21552),
         a3,
         11);
  if ( v6 )
  {
    v15 = v6;
    if ( (unsigned __int8)wlan_policy_mgr_get_ll_lt_sap_vdev_id(*(_QWORD *)(a1 + 21552)) != 255 )
    {
      v24 = jiffies;
      v25 = (unsigned int *)(sme_nss_chains_update___last_ticks - jiffies);
      if ( sme_nss_chains_update___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x34u,
          4u,
          "%s: LL_LT_SAP vdev %d present, chainmask config not allowed",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "sme_nss_chains_update");
        sme_nss_chains_update___last_ticks = v24;
      }
      v26 = 16;
      goto LABEL_68;
    }
    if ( (unsigned int)wlan_is_tdls_session_present(v15) )
    {
      v26 = qdf_mutex_acquire(a1 + 12776);
      if ( !v26 )
      {
        dynamic_vdev_config = mlme_get_dynamic_vdev_config(v15, v16, v17, v18, v19, v20, v21, v22, v23);
        if ( dynamic_vdev_config )
        {
          v44 = (_QWORD *)dynamic_vdev_config;
          ini_vdev_config = (_DWORD *)mlme_get_ini_vdev_config(v15, v36, v37, v38, v39, v40, v41, v42, v43);
          if ( ini_vdev_config )
          {
            v54 = 0;
            v55 = (char *)(a2 + 2);
            v56 = (char *)(a2 + 6);
            v57 = (char *)(a2 + 4);
            v58 = (char *)(a2 + 11);
            v59 = (char *)a2 + 46;
            v103 = v44 + 3;
            v60 = "%s: Validation from ini config failed";
            v61 = 1;
            while ( 1 )
            {
              v62 = *(_DWORD *)&v55[4 * v54];
              v63 = v61;
              if ( v62 )
              {
                v64 = a2[v54];
                if ( v64 )
                  goto LABEL_16;
              }
              else
              {
                v62 = *((_DWORD *)v44 + v54 + 2);
                *(_DWORD *)&v55[4 * v54] = v62;
                v64 = a2[v54];
                if ( v64 )
                {
LABEL_16:
                  v65 = *(_DWORD *)&v56[4 * v54];
                  if ( v65 )
                    goto LABEL_17;
                  goto LABEL_44;
                }
              }
              v64 = *((_DWORD *)v44 + v54);
              a2[v54] = v64;
              v65 = *(_DWORD *)&v56[4 * v54];
              if ( v65 )
              {
LABEL_17:
                v66 = *(_DWORD *)&v57[4 * v54];
                if ( v66 )
                  goto LABEL_18;
                goto LABEL_45;
              }
LABEL_44:
              v65 = *((_DWORD *)v103 + v54);
              *(_DWORD *)&v56[4 * v54] = v65;
              v66 = *(_DWORD *)&v57[4 * v54];
              if ( v66 )
              {
LABEL_18:
                v67 = a2[10];
                if ( v67 )
                  goto LABEL_19;
                goto LABEL_46;
              }
LABEL_45:
              v66 = *((_DWORD *)v44 + v54 + 4);
              *(_DWORD *)&v57[4 * v54] = v66;
              v67 = a2[10];
              if ( v67 )
              {
LABEL_19:
                v68 = a2[8];
                if ( v68 )
                  goto LABEL_20;
                goto LABEL_50;
              }
LABEL_46:
              if ( a2[1] >= ini_vdev_config[10] )
                v67 = ini_vdev_config[10];
              else
                v67 = a2[1];
              a2[10] = v67;
              v68 = a2[8];
              if ( v68 )
              {
LABEL_20:
                v69 = a2[9];
                if ( v69 )
                  goto LABEL_21;
                goto LABEL_53;
              }
LABEL_50:
              v68 = ini_vdev_config[8];
              if ( *a2 < v68 )
                v68 = *a2;
              a2[8] = v68;
              v69 = a2[9];
              if ( v69 )
              {
LABEL_21:
                if ( (v58[v54] & 1) != 0 )
                  goto LABEL_22;
                goto LABEL_56;
              }
LABEL_53:
              v69 = *a2;
              if ( *a2 >= ini_vdev_config[9] )
                v69 = ini_vdev_config[9];
              a2[9] = v69;
              if ( (v58[v54] & 1) != 0 )
              {
LABEL_22:
                if ( (v59[v54] & 1) != 0 )
                  goto LABEL_24;
LABEL_23:
                v59[v54] = *((_BYTE *)v44 + v54 + 46);
                goto LABEL_24;
              }
LABEL_56:
              v58[v54] = *((_BYTE *)v44 + v54 + 44);
              if ( (v59[v54] & 1) == 0 )
                goto LABEL_23;
LABEL_24:
              if ( v62 > ini_vdev_config[v54 + 2]
                || v64 > ini_vdev_config[v54]
                || v65 > ini_vdev_config[v54 + 6]
                || v66 > ini_vdev_config[v54 + 4]
                || v67 > ini_vdev_config[10]
                || v68 > ini_vdev_config[8]
                || v69 > ini_vdev_config[9] )
              {
                goto LABEL_60;
              }
              if ( v64 > v62 )
              {
                v60 = "%s: User cfg validation failed";
                goto LABEL_60;
              }
              if ( v66 > v64 )
                a2[v54] = v66;
              if ( v65 > v62 )
                *(_DWORD *)&v55[4 * v54] = v65;
              v70 = a2[1];
              if ( v67 > v70 )
                a2[10] = v70;
              v71 = *a2;
              if ( v68 > *a2 )
                a2[8] = v71;
              if ( v69 > v71 )
                a2[9] = v71;
              v61 = 0;
              v54 = 1;
              if ( (v63 & 1) == 0 )
              {
                v26 = 0;
                goto LABEL_61;
              }
            }
          }
          v60 = "%s: nss chain ini config NULL";
LABEL_60:
          qdf_trace_msg(0x34u, 2u, v60, v46, v47, v48, v49, v50, v51, v52, v53, "sme_validate_nss_chains_config", v103);
          LODWORD(v54) = 0;
          v26 = 16;
LABEL_61:
          v72 = *(_QWORD *)(a1 + 8);
          *((_BYTE *)a2 + 50) = *(_BYTE *)(v72 + 3294);
          a2[13] = *(_DWORD *)(v72 + 3296);
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: dynamic_cfg",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "sme_nss_chains_update",
            v103);
          sme_dump_nss_cfg(v44);
          qdf_trace_msg(0x34u, 8u, "%s: user_cfg", v73, v74, v75, v76, v77, v78, v79, v80, "sme_nss_chains_update");
          sme_dump_nss_cfg(a2);
          if ( (_DWORD)v54 )
          {
            if ( (unsigned int)qdf_mem_cmp(v44, a2, 0x38u) )
            {
              qdf_trace_msg(
                0x34u,
                8u,
                "%s: User params verified, sending to fw vdev id %d",
                v81,
                v82,
                v83,
                v84,
                v85,
                v86,
                v87,
                v88,
                "sme_nss_chains_update",
                v4);
              v26 = wma_vdev_nss_chain_params_send(*(unsigned __int8 *)(v15 + 104), a2);
              if ( v26 )
              {
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: params sent failed to fw vdev id %d",
                  v89,
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  v96,
                  "sme_nss_chains_update",
                  v4);
              }
              else
              {
                v98 = *((_QWORD *)a2 + 1);
                v97 = *((_QWORD *)a2 + 2);
                *v44 = *(_QWORD *)a2;
                v44[1] = v98;
                v44[2] = v97;
                v99 = *((_QWORD *)a2 + 6);
                v100 = *((_QWORD *)a2 + 3);
                v101 = *((_QWORD *)a2 + 4);
                v44[5] = *((_QWORD *)a2 + 5);
                v44[6] = v99;
                v44[3] = v100;
                v44[4] = v101;
              }
            }
            else
            {
              qdf_trace_msg(
                0x34u,
                8u,
                "%s: current config same as user config",
                v81,
                v82,
                v83,
                v84,
                v85,
                v86,
                v87,
                v88,
                "sme_nss_chains_update");
              v26 = 0;
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: nss chain dynamic config NULL",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "sme_nss_chains_update");
          v26 = 16;
        }
        qdf_mutex_release(a1 + 12776);
      }
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: TDLS session exists",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sme_nss_chains_update");
      v26 = 16;
    }
LABEL_68:
    wlan_objmgr_vdev_release_ref(v15, 0xBu, v25, v16, v17, v18, v19, v20, v21, v22, v23);
    return v26;
  }
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: Got NULL vdev obj, returning",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "sme_nss_chains_update");
  return 16;
}
