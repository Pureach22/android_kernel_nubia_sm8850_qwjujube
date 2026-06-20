__int64 __fastcall dp_rx_page_pool_resize(__int64 a1, unsigned int a2, unsigned __int64 a3)
{
  __int64 v4; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x26
  unsigned __int64 v16; // x8
  __int64 result; // x0
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x22
  unsigned __int64 v20; // x8
  _QWORD *v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const void *v30; // x1
  _QWORD *v31; // x21
  _QWORD *v32; // x0
  _QWORD *v33; // x1
  int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _QWORD **v43; // x24
  __int64 v44; // x8
  int v45; // w23
  int v46; // w25
  __int64 v47; // x27
  __int64 v48; // x8
  char v49; // w9
  bool v50; // zf
  unsigned int v51; // w28
  _QWORD *v52; // x25
  int v53; // w25
  __int64 v54; // x8
  __int64 v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x6
  char v65; // w8
  _QWORD **v66; // x8
  __int64 v67; // x8
  unsigned __int64 v68; // x20
  _BYTE *v69; // x21
  __int64 v70; // x0
  void (*v71)(void); // x8
  _QWORD *v72; // x0
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  _QWORD *v81; // x21
  _QWORD *v82; // x0
  _QWORD *v83; // x1
  _QWORD *v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  _QWORD *v93; // x21
  _QWORD *v94; // x0
  _QWORD *v95; // x1
  __int64 v96; // x8
  _QWORD *v97; // x21
  __int64 v98; // x0
  _QWORD *v99; // x23
  void (*v100)(void); // x8
  __int64 v101; // [xsp+8h] [xbp-68h]
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-60h]
  unsigned __int64 v103; // [xsp+18h] [xbp-58h]
  unsigned __int64 v104; // [xsp+20h] [xbp-50h]
  unsigned __int64 v105; // [xsp+28h] [xbp-48h]
  int v106; // [xsp+30h] [xbp-40h]
  _QWORD *v107; // [xsp+38h] [xbp-38h] BYREF
  _QWORD **v108; // [xsp+40h] [xbp-30h]
  __int64 v109; // [xsp+48h] [xbp-28h]
  __int64 v110; // [xsp+50h] [xbp-20h] BYREF
  char v111[4]; // [xsp+5Ch] [xbp-14h] BYREF
  __int64 v112[2]; // [xsp+60h] [xbp-10h] BYREF

  v112[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 5 )
    goto LABEL_102;
  v4 = *(_QWORD *)(a1 + 40);
  v108 = nullptr;
  v109 = 0;
  v107 = nullptr;
  if ( (wlan_cfg_get_dp_rx_buffer_recycle(v4) & 1) == 0 )
  {
    result = 16;
    goto LABEL_6;
  }
  v15 = a1 + 544LL * a2 + 20280;
  v16 = *(_QWORD *)(a1 + 544LL * a2 + 20552);
  if ( v16 == a3 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: No change in pool size, continue with existing pools",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_rx_page_pool_resize");
    result = 0;
    goto LABEL_6;
  }
  result = 16;
  if ( a3 && v16 )
  {
    *(_DWORD *)(a1 + 544LL * a2 + 20568) = 1;
    if ( v16 < a3 )
    {
      v18 = *(_QWORD *)(a1 + 544LL * a2 + 20560);
      v112[0] = 0;
      v111[0] = 0;
      v110 = 0;
      v105 = a3 % v18;
      if ( a3 % v18 )
        v19 = a3 / v18 + 1;
      else
        v19 = a3 / v18;
      if ( v19 >= 5 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Failed to allocate page pools, invalid pool count %zu",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "dp_rx_page_pool_upsize",
          v19);
        result = 16;
        goto LABEL_90;
      }
      v34 = wlan_cfg_rx_buffer_size(*(_QWORD *)(a1 + 40));
      if ( v19 < 2 )
      {
        v67 = 1;
        v45 = 1;
        goto LABEL_52;
      }
      v43 = (_QWORD **)(a1 + 544LL * a2 + 20696);
      v103 = v19;
      v104 = v19 - 1;
      v44 = 1;
      v45 = 1;
      v46 = 1;
      v101 = v34 + 447LL;
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v47 = v15 + 48 * v44;
        if ( *(_QWORD *)(v47 + 16) )
          goto LABEL_26;
        v50 = v104 == v44;
        v48 = *(_QWORD *)(a1 + 544LL * a2 + 20560);
        v49 = _ReadStatusReg(DAIF);
        v50 = !v50 || v105 == 0;
        v106 = v46;
        if ( v50 )
          v51 = v48;
        else
          v51 = v105;
        if ( v49 < 0 || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 544LL * a2 + 20536);
        }
        else
        {
          raw_spin_lock_bh(a1 + 544LL * a2 + 20536);
          *(_QWORD *)(a1 + 544LL * a2 + 20544) |= 1uLL;
        }
        v52 = *v43;
        if ( *v43 == v43 )
        {
LABEL_39:
          v53 = 0;
          v54 = *(_QWORD *)(a1 + 544LL * a2 + 20544);
          if ( (v54 & 1) == 0 )
            goto LABEL_40;
        }
        else
        {
          while ( 1 )
          {
            v66 = (_QWORD **)*v52;
            if ( v52[2] )
            {
              if ( v52[3] == v51 )
                break;
            }
            v52 = (_QWORD *)*v52;
            if ( v66 == v43 )
              goto LABEL_39;
          }
          qdf_list_remove_node(a1 + 544LL * a2 + 20696, v52);
          qdf_mem_copy((void *)v47, v52, 0x30u);
          _qdf_mem_free((__int64)v52);
          v53 = 1;
          v54 = *(_QWORD *)(a1 + 544LL * a2 + 20544);
          if ( (v54 & 1) == 0 )
          {
LABEL_40:
            raw_spin_unlock(a1 + 544LL * a2 + 20536);
            if ( !v53 )
              goto LABEL_41;
            goto LABEL_24;
          }
        }
        *(_QWORD *)(a1 + 544LL * a2 + 20544) = v54 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 544LL * a2 + 20536);
        if ( !v53 )
        {
LABEL_41:
          v55 = _dp_rx_page_pool_create(a1, v51, v101 & 0xFFFFFFFFFFFFFFC0LL, &v110, v112, v111);
          if ( !v55 )
            goto LABEL_54;
          v64 = v112[0];
          v65 = v111[0];
          *(_QWORD *)(v47 + 16) = v55;
          *(_QWORD *)(v47 + 24) = v51;
          *(_QWORD *)(v47 + 32) = v64;
          v46 = v106 + 1;
          *(_BYTE *)(v47 + 40) = v65;
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Page pool idx %d pool_size %d pp_size %zu",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "dp_rx_page_pool_upsize",
            (unsigned int)v45,
            v51);
          goto LABEL_25;
        }
LABEL_24:
        v46 = v106 + 1;
LABEL_25:
        v19 = v103;
LABEL_26:
        v44 = ++v45;
        if ( v19 <= v45 )
        {
          v67 = (unsigned __int16)v46;
LABEL_52:
          if ( v19 != v67 )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: Failed to upscale RX buffers using page pool",
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              "dp_rx_page_pool_upsize");
LABEL_54:
            if ( v45 >= 2 )
            {
              v68 = (unsigned int)v45;
              v69 = (_BYTE *)(544LL * a2 + 48LL * (unsigned int)v45 + a1 + 20272);
              while ( v68 <= 5 )
              {
                v70 = *((_QWORD *)v69 - 3);
                if ( v70 )
                {
                  if ( *v69 && (v71 = *(void (**)(void))(*(_QWORD *)(a1 + 8) + 272LL)) != nullptr )
                  {
                    if ( *((_DWORD *)v71 - 1) != 820154707 )
                      __break(0x8228u);
                    v71();
                    *v69 = 0;
                  }
                  else
                  {
                    _qdf_page_pool_destroy(v70);
                  }
                  *((_QWORD *)v69 - 3) = 0;
                }
                --v68;
                v69 -= 48;
                if ( v68 + 1 <= 2 )
                  goto LABEL_66;
              }
LABEL_102:
              __break(0x5512u);
            }
LABEL_66:
            result = 16;
LABEL_90:
            *(_DWORD *)(v15 + 288) = 0;
            goto LABEL_6;
          }
LABEL_89:
          result = 0;
          *(_QWORD *)(v15 + 272) = a3;
          goto LABEL_90;
        }
      }
    }
    v107 = &v107;
    v108 = &v107;
    v109 = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v20 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v20 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v20 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 544LL * a2 + 20536);
      if ( !*(_QWORD *)(a1 + 544LL * a2 + 20344) )
        goto LABEL_70;
    }
    else
    {
      raw_spin_lock_bh(a1 + 544LL * a2 + 20536);
      *(_QWORD *)(a1 + 544LL * a2 + 20544) |= 1uLL;
      if ( !*(_QWORD *)(a1 + 544LL * a2 + 20344) )
      {
LABEL_70:
        if ( !*(_QWORD *)(v15 + 112) )
          goto LABEL_77;
        if ( (_qdf_page_pool_full_bh() & 1) == 0 )
        {
          v72 = (_QWORD *)_qdf_mem_malloc(0x30u, "dp_rx_page_pool_resize", 1196);
          if ( v72 )
          {
            v81 = v72;
            qdf_mem_copy(v72, (const void *)(v15 + 96), 0x30u);
            qdf_mem_set((void *)(v15 + 96), 0x30u, 0);
            v82 = (_QWORD *)(v15 + 416);
            v83 = v81;
LABEL_76:
            qdf_list_insert_back(v82, v83);
LABEL_77:
            if ( !*(_QWORD *)(v15 + 160) )
            {
LABEL_84:
              if ( !qdf_list_empty((_QWORD *)(v15 + 416)) )
                _qdf_delayed_work_start(v15 + 296, 0x2710u);
              v96 = *(_QWORD *)(v15 + 264);
              *(_BYTE *)(v15 + 248) = 0;
              if ( (v96 & 1) != 0 )
              {
                *(_QWORD *)(v15 + 264) = v96 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v15 + 256);
              }
              else
              {
                raw_spin_unlock(v15 + 256);
              }
              v97 = v107;
              if ( v107 != &v107 )
              {
                do
                {
                  v98 = v97[2];
                  v99 = (_QWORD *)*v97;
                  if ( v98
                    && *((_BYTE *)v97 + 40)
                    && (v100 = *(void (**)(void))(*(_QWORD *)(a1 + 8) + 272LL)) != nullptr )
                  {
                    if ( *((_DWORD *)v100 - 1) != 820154707 )
                      __break(0x8228u);
                    v100();
                    *((_BYTE *)v97 + 40) = 0;
                  }
                  else
                  {
                    _qdf_page_pool_destroy(v98);
                  }
                  qdf_list_remove_node((__int64)&v107, v97);
                  qdf_mem_set((void *)(v15 + 144), 0x30u, 0);
                  v97 = v99;
                }
                while ( v99 != &v107 );
              }
              goto LABEL_89;
            }
            if ( (_qdf_page_pool_full_bh() & 1) == 0 )
            {
              v84 = (_QWORD *)_qdf_mem_malloc(0x30u, "dp_rx_page_pool_resize", 1196);
              if ( v84 )
              {
                v93 = v84;
                qdf_mem_copy(v84, (const void *)(v15 + 144), 0x30u);
                qdf_mem_set((void *)(v15 + 144), 0x30u, 0);
                v94 = (_QWORD *)(v15 + 416);
                v95 = v93;
LABEL_83:
                qdf_list_insert_back(v94, v95);
                goto LABEL_84;
              }
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: Failed to alloc inactive pp node for %pK",
                v85,
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                "dp_rx_page_pool_resize",
                v15 + 144);
            }
            v94 = &v107;
            v95 = (_QWORD *)(v15 + 144);
            goto LABEL_83;
          }
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Failed to alloc inactive pp node for %pK",
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            "dp_rx_page_pool_resize",
            v15 + 96);
        }
        v82 = &v107;
        v83 = (_QWORD *)(v15 + 96);
        goto LABEL_76;
      }
    }
    if ( (_qdf_page_pool_full_bh() & 1) == 0 )
    {
      v21 = (_QWORD *)_qdf_mem_malloc(0x30u, "dp_rx_page_pool_resize", 1196);
      if ( v21 )
      {
        v30 = (const void *)(a1 + 544LL * a2 + 20328);
        v31 = v21;
        qdf_mem_copy(v21, v30, 0x30u);
        qdf_mem_set((void *)(v15 + 48), 0x30u, 0);
        v32 = (_QWORD *)(v15 + 416);
        v33 = v31;
LABEL_69:
        qdf_list_insert_back(v32, v33);
        goto LABEL_70;
      }
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Failed to alloc inactive pp node for %pK",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "dp_rx_page_pool_resize",
        a1 + 544LL * a2 + 20328);
    }
    v32 = &v107;
    v33 = (_QWORD *)(a1 + 544LL * a2 + 20328);
    goto LABEL_69;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
