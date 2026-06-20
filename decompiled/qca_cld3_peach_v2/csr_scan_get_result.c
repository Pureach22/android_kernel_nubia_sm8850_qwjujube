__int64 __fastcall csr_scan_get_result(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 pdev_by_id; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  _QWORD *scan_result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w24
  __int64 v26; // x20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x22
  _QWORD *i; // x1
  __int64 v46; // x0
  __int64 v47; // x27
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  _DWORD *v64; // x0
  __int64 v65; // x28
  unsigned int v66; // w8
  unsigned int v67; // w8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  size_t v76; // x2
  unsigned int v77; // w23
  unsigned int *v78; // x8
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x0
  __int64 v88; // x0
  __int64 v89; // x21
  __int64 v91; // [xsp+0h] [xbp-40h]
  __int64 v92; // [xsp+8h] [xbp-38h]
  __int64 v93; // [xsp+10h] [xbp-30h]
  _QWORD *v94; // [xsp+20h] [xbp-20h] BYREF
  _QWORD *v95; // [xsp+28h] [xbp-18h] BYREF
  __int64 v96[2]; // [xsp+30h] [xbp-10h] BYREF

  v96[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
    *a3 = 0;
  pdev_by_id = wlan_objmgr_get_pdev_by_id(*(_QWORD *)(a1 + 21624), 0, 7u);
  if ( pdev_by_id )
  {
    v15 = pdev_by_id;
    scan_result = scm_get_scan_result(pdev_by_id, a2, v7, v8, v9, v10, v11, v12, v13, v14);
    if ( !scan_result )
    {
      qdf_trace_msg(0x34u, 8u, "%s: scan list empty", v17, v18, v19, v20, v21, v22, v23, v24, "csr_scan_get_result");
      v77 = 29;
LABEL_76:
      wlan_objmgr_pdev_release_ref(v15, 7u, v78, v79, v80, v81, v82, v83, v84, v85, v86);
      goto LABEL_77;
    }
    v25 = *((_DWORD *)scan_result + 4);
    v26 = (__int64)scan_result;
    qdf_trace_msg(0x34u, 8u, "%s: num_entries %d", v17, v18, v19, v20, v21, v22, v23, v24, "csr_scan_get_result", v25);
    if ( *(_DWORD *)(v26 + 16) )
    {
      v35 = _qdf_mem_malloc(0x60u, "csr_scan_get_result", 916);
      if ( !v35 )
      {
        v77 = 2;
        goto LABEL_75;
      }
      v44 = v35;
      csr_ll_open(v35);
      *(_QWORD *)(v44 + 88) = 0;
      v95 = nullptr;
      v94 = nullptr;
      qdf_list_peek_front((_QWORD *)v26, &v95);
      for ( i = v95; i; v95 = i )
      {
        qdf_list_peek_next((_QWORD *)v26, i, &v94);
        v46 = *(_QWORD *)(a1 + 21632);
        v96[0] = 0;
        v47 = v95[3];
        if ( (wlan_reg_get_channel_state_for_pwrmode(
                v46,
                *(_DWORD *)(v47 + 1192),
                0,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55)
            & 0xFFFFFFFB) != 0 )
        {
          v64 = (_DWORD *)_qdf_mem_malloc(
                            (unsigned __int16)(*(_DWORD *)(v47 + 1888) + 68) + 200LL,
                            "csr_fill_bss_from_scan_entry",
                            826);
          if ( v64 )
          {
            v65 = (__int64)v64;
            if ( *(_DWORD *)(v47 + 1264) || *(_DWORD *)(v47 + 1268) || *(_DWORD *)(v47 + 1272) )
            {
              v66 = *(_DWORD *)(v47 + 1272);
              if ( v66 )
              {
                if ( (v66 & 0x400) != 0 )
                {
                  v66 = 14;
                }
                else if ( (v66 & 0x200) != 0 )
                {
                  v66 = 13;
                }
                else if ( (v66 & 0x8C) != 0 )
                {
                  v66 = 6;
                }
                else if ( (v66 & 2) != 0 )
                {
                  v66 = 5;
                }
                else if ( (v66 & 0x140) != 0 )
                {
                  v66 = 10;
                }
                else if ( (v66 & 0x2010) != 0 )
                {
                  v66 = 7;
                }
                else if ( (v66 & 0x800) != 0 )
                {
                  v66 = 11;
                }
                else if ( (v66 & 0x1000) != 0 )
                {
                  v66 = 12;
                }
                else if ( (v66 & 0x8001) != 0 )
                {
                  v66 = 3;
                }
                else
                {
                  v66 = (v66 >> 14) & 4;
                }
              }
              v64[4] = v66;
              v67 = *(_DWORD *)(v47 + 1276);
              if ( v67 )
              {
                if ( (v67 & 0x400) != 0 )
                {
                  v67 = 14;
                }
                else if ( (v67 & 0x200) != 0 )
                {
                  v67 = 13;
                }
                else if ( (v67 & 0x8C) != 0 )
                {
                  v67 = 6;
                }
                else if ( (v67 & 2) != 0 )
                {
                  v67 = 5;
                }
                else if ( (v67 & 0x140) != 0 )
                {
                  v67 = 10;
                }
                else if ( (v67 & 0x2010) != 0 )
                {
                  v67 = 7;
                }
                else if ( (v67 & 0x800) != 0 )
                {
                  v67 = 11;
                }
                else if ( (v67 & 0x1000) != 0 )
                {
                  v67 = 12;
                }
                else if ( (v67 & 0x8001) != 0 )
                {
                  v67 = 3;
                }
                else
                {
                  v67 = (v67 >> 14) & 4;
                }
              }
              v64[5] = v67;
              csr_fill_auth_type(v64 + 6, *(_DWORD *)(v47 + 1264), *(_DWORD *)(v47 + 1268), *(_DWORD *)(v47 + 1272));
              LODWORD(v93) = *(_DWORD *)(v65 + 20);
              LODWORD(v92) = *(_DWORD *)(v65 + 16);
              LODWORD(v91) = *(_DWORD *)(v65 + 24);
              qdf_trace_msg(
                0x34u,
                8u,
                "%s: Authmode %x, AKM %x, Cipher Uc %x Mc %x CSR: Auth %d, Cipher Uc %d Mc %d",
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                "csr_fill_neg_crypto_info",
                *(unsigned int *)(v47 + 1264),
                *(unsigned int *)(v47 + 1268),
                *(unsigned int *)(v47 + 1272),
                *(unsigned int *)(v47 + 1276),
                v91,
                v92,
                v93);
            }
            v76 = *(unsigned __int8 *)(v47 + 13);
            *(_BYTE *)(v65 + 40) = v76;
            qdf_mem_copy((void *)(v65 + 41), (const void *)(v47 + 14), v76);
            *(_QWORD *)(v65 + 80) = *(_QWORD *)(v47 + 104);
            wlan_fill_bss_desc_from_scan_entry(a1, v65 + 88, v47);
            if ( (unsigned int)wlan_get_parsed_bss_description_ies(a1, (unsigned __int16 *)(v65 + 88), v96) )
            {
              _qdf_mem_free(v65);
            }
            else
            {
              *(_QWORD *)(v65 + 32) = v96[0];
              csr_ll_insert_tail(v44);
            }
          }
        }
        else
        {
          LODWORD(v91) = *(_DWORD *)(v47 + 1192);
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: BSS %02x:%02x:%02x:**:**:%02x channel %d invalid, not populating this BSSID",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "csr_fill_bss_from_scan_entry",
            *(unsigned __int8 *)(v47 + 1),
            *(unsigned __int8 *)(v47 + 2),
            *(unsigned __int8 *)(v47 + 3),
            *(unsigned __int8 *)(v47 + 6),
            v91);
        }
        i = v94;
        v94 = nullptr;
      }
      v87 = v44;
      if ( !a3 )
      {
        while ( 1 )
        {
          v88 = csr_ll_remove_head(v87, 0);
          if ( !v88 )
            break;
          if ( *(_QWORD *)(v88 + 32) )
          {
            v89 = v88;
            _qdf_mem_free(*(_QWORD *)(v88 + 32));
            v88 = v89;
          }
          _qdf_mem_free(v88);
          v87 = v44;
        }
        csr_ll_close(v44);
        _qdf_mem_free(v44);
        v77 = 0;
        goto LABEL_75;
      }
      if ( (unsigned int)csr_ll_count(v44) )
      {
        v77 = 0;
        *a3 = v44;
LABEL_75:
        scm_purge_scan_results(v26, v36, v37, v38, v39, v40, v41, v42, v43);
        goto LABEL_76;
      }
      csr_ll_close(v44);
      _qdf_mem_free(v44);
    }
    else
    {
      qdf_trace_msg(0x34u, 8u, "%s: scan list empty", v27, v28, v29, v30, v31, v32, v33, v34, "csr_scan_get_result");
    }
    if ( v25 )
      v77 = 14;
    else
      v77 = 29;
    goto LABEL_75;
  }
  qdf_trace_msg(0x34u, 2u, "%s: pdev is NULL", v7, v8, v9, v10, v11, v12, v13, v14, "csr_scan_get_result");
  v77 = 4;
LABEL_77:
  _ReadStatusReg(SP_EL0);
  return v77;
}
