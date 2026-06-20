__int64 __fastcall mlo_dev_ctx_init(__int64 a1)
{
  __int64 mlo_ctx; // x22
  _QWORD *mld_ctx_by_mldaddr; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 v13; // x21
  _QWORD *v14; // x19
  unsigned int v15; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 *v25; // x22
  __int64 v26; // x4
  __int64 v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  __int16 v37; // w9
  int v38; // w8
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int16 v49; // w8
  __int16 v50; // w10
  __int64 v51; // x19
  int v52; // w9
  int v53; // w8
  __int64 v54; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  const char *v63; // x2
  __int64 v64; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x0
  unsigned int (**v82)(void); // x8
  unsigned int (*v83)(void); // x8
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  int v100; // w8
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  mld_ctx_by_mldaddr = wlan_mlo_get_mld_ctx_by_mldaddr((const void *)(a1 + 80));
  v12 = *(_QWORD *)(a1 + 216);
  if ( v12 )
  {
    v13 = *(_QWORD *)(v12 + 80);
    if ( v13 )
    {
      v14 = mld_ctx_by_mldaddr;
      if ( mld_ctx_by_mldaddr )
      {
        v15 = *(_DWORD *)(a1 + 16);
        qdf_mutex_acquire((__int64)(mld_ctx_by_mldaddr + 207));
        v25 = v14 + 3;
        v24 = v14[3];
        if ( !v24 || (v26 = *(unsigned int *)(v24 + 16), (_DWORD)v26 == v15) )
        {
          v27 = v14[4];
          if ( !v27 || (v26 = *(unsigned int *)(v27 + 16), (_DWORD)v26 == v15) )
          {
            qdf_mutex_release((__int64)(v14 + 207));
            qdf_mutex_acquire((__int64)(v14 + 207));
            v36 = *v25;
            if ( *v25 )
            {
              if ( v14[4] )
              {
LABEL_13:
                qdf_mutex_release((__int64)(v14 + 207));
                return 0;
              }
              v36 = 1;
            }
            v37 = *((_WORD *)v14 + 20);
            v25[v36] = a1;
            *((_WORD *)v14 + 20) = v37 + 1;
            v38 = *(_DWORD *)(a1 + 16);
            *(_QWORD *)(a1 + 1360) = v14;
            if ( v38 == 1 )
              wlan_mlo_vdev_alloc_aid_mgr(v14, a1, v28, v29, v30, v31, v32, v33, v34, v35);
            goto LABEL_13;
          }
        }
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Invalid opmode %d type found expected %d, investigate config",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "wlan_mlo_check_valid_config",
          v26,
          v15);
        qdf_mutex_release((__int64)(v14 + 207));
        return 16;
      }
      if ( *(_DWORD *)(mlo_ctx + 208) >= 3u )
      {
        qdf_trace_msg(0x8Fu, 2u, "%s: No more MLD allowed", v4, v5, v6, v7, v8, v9, v10, v11, "mlo_dev_ctx_init");
        return 1;
      }
      v40 = _qdf_mem_malloc(0xF40u, "mlo_dev_ctx_init", 1188);
      if ( v40 )
      {
        v49 = *(_WORD *)(a1 + 84);
        v50 = *(_WORD *)(v40 + 40);
        v51 = v40;
        v52 = *(_DWORD *)(a1 + 80);
        *(_QWORD *)(v40 + 24) = a1;
        *(_WORD *)(v40 + 21) = v49;
        *(_DWORD *)(v40 + 17) = v52;
        *(_WORD *)(v40 + 40) = v50 + 1;
        *(_QWORD *)(a1 + 1360) = v40;
        qdf_mutex_create(v40 + 1656);
        qdf_mutex_create(v51 + 1720);
        v53 = *(_DWORD *)(a1 + 16);
        if ( v53 != 1 )
        {
          if ( !v53 )
          {
            v54 = _qdf_mem_malloc(0x5F0u, "mlo_dev_ctx_init", 1202);
            *(_QWORD *)(v51 + 2224) = v54;
            if ( !v54 )
            {
              qdf_mutex_destroy(v51 + 1720);
              qdf_mutex_destroy(v51 + 1656);
              _qdf_mem_free(v51);
              return 2;
            }
            wlan_minidump_log(v55, v56, v57, v58, v59, v60, v61, v62, v54, 1520, v13);
            qdf_mutex_create(*(_QWORD *)(v51 + 2224) + 40LL);
            mlo_sta_reset_requested_emlsr_mode(v51);
          }
          goto LABEL_34;
        }
        v64 = _qdf_mem_malloc(0xD0u, "mlo_ap_ctx_init", 827);
        if ( v64 )
        {
          *(_QWORD *)(v51 + 2232) = v64;
          qdf_mutex_create(v64 + 16);
          if ( !(unsigned int)wlan_mlo_vdev_aid_mgr_init((__int64 *)v51) )
          {
            wlan_minidump_log(v73, v74, v75, v76, v77, v78, v79, v80, *(_QWORD *)(v51 + 2232), 208, v13);
LABEL_34:
            v81 = *(_QWORD *)(v13 + 2808);
            if ( v81 )
            {
              if ( *(_QWORD *)v81 )
              {
                v82 = *(unsigned int (***)(void))(*(_QWORD *)v81 + 176LL);
                if ( v82 )
                {
                  v83 = *v82;
                  if ( v83 )
                  {
                    if ( *((_DWORD *)v83 - 1) != -951226545 )
                      __break(0x8228u);
                    if ( !v83() )
                    {
                      wlan_minidump_log(v84, v85, v86, v87, v88, v89, v90, v91, v51, 3904, v13);
                      wlan_minidump_log(v101, v102, v103, v104, v105, v106, v107, v108, mlo_ctx, 1264, v13);
                      *(_WORD *)(v51 + 3896) = 2;
                      mlo_dev_mlpeer_list_init(v51);
                      qdf_mutex_acquire(mlo_ctx);
                      if ( *(_DWORD *)(mlo_ctx + 208) <= 2u )
                        qdf_list_insert_back((_QWORD *)(mlo_ctx + 192), (_QWORD *)v51);
                      qdf_mutex_release(mlo_ctx);
                      mlo_reset_cache_link_assoc_rsp(v51);
                      mlo_t2lm_ctx_init(v51, a1);
                      mlo_epcs_ctx_init(v51);
                      mlo_mgr_link_switch_init(v13, v51);
                      mlo_link_recfg_init(v13, v51);
                      return 0;
                    }
                  }
                }
              }
            }
            qdf_mutex_destroy(v51 + 1720);
            v100 = *(_DWORD *)(a1 + 16);
            if ( v100 == 1 )
            {
              wlan_minidump_remove(v92, v93, v94, v95, v96, v97, v98, v99, *(_QWORD *)(v51 + 2232), 208, v13);
              mlo_ap_ctx_deinit(v51);
            }
            else if ( !v100 )
            {
              wlan_minidump_remove(v92, v93, v94, v95, v96, v97, v98, v99, *(_QWORD *)(v51 + 2224), 1520, v13);
              _qdf_mem_free(*(_QWORD *)(v51 + 2224));
            }
            qdf_mutex_destroy(v51 + 1656);
            _qdf_mem_free(v51);
            v63 = "%s: Failed to create DP MLO Dev ctxt";
            goto LABEL_46;
          }
          wlan_mlo_vdev_aid_mgr_deinit(v51, v73, v74, v75, v76, v77, v78, v79, v80);
          qdf_mutex_destroy(*(_QWORD *)(v51 + 2232) + 16LL);
          _qdf_mem_free(*(_QWORD *)(v51 + 2232));
          *(_QWORD *)(v51 + 2232) = 0;
        }
        else
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: MLO AP ctx alloc failure",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "mlo_ap_ctx_init");
        }
        qdf_mutex_destroy(v51 + 1720);
        qdf_mutex_destroy(v51 + 1656);
        _qdf_mem_free(v51);
        v63 = "%s: Failed to allocate memory for ap ctx";
      }
      else
      {
        v63 = "%s: Failed to allocate memory for ML dev";
      }
LABEL_46:
      qdf_trace_msg(0x8Fu, 2u, v63, v41, v42, v43, v44, v45, v46, v47, v48, "mlo_dev_ctx_init");
      return 2;
    }
  }
  qdf_trace_msg(0x8Fu, 2u, "%s: Failed to get psoc", v4, v5, v6, v7, v8, v9, v10, v11, "mlo_dev_ctx_init");
  return 16;
}
