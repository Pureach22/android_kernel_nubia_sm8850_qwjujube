__int64 __fastcall hdd_softap_init_tx_rx_sta(__int64 *a1, unsigned __int8 *a2)
{
  __int64 v4; // x22
  __int64 v5; // x19
  __int64 sta_info_by_mac; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  __int64 v20; // x0
  __int64 v21; // x22
  unsigned int v22; // w21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v44; // x9
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w8
  __int64 v54; // x9
  __int64 v56; // [xsp+0h] [xbp-10h] BYREF
  __int64 v57; // [xsp+8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v5 = *a1 + 38848;
  sta_info_by_mac = hdd_get_sta_info_by_mac(v5, a2, 6, 1);
  v56 = sta_info_by_mac;
  if ( sta_info_by_mac )
  {
    v15 = sta_info_by_mac;
    if ( a2 )
    {
      v16 = *a2;
      v17 = a2[1];
      v18 = a2[2];
      v19 = a2[5];
    }
    else
    {
      v18 = 0;
      v16 = 0;
      v17 = 0;
      v19 = 0;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Reinit of in use station %02x:%02x:%02x:**:**:%02x",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "hdd_softap_init_tx_rx_sta",
      v16,
      v17,
      v18,
      v19,
      v56,
      v57);
    if ( v5 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v4 + 38872);
      }
      else
      {
        raw_spin_lock_bh(v4 + 38872);
        *(_QWORD *)(v4 + 38880) |= 1uLL;
      }
      if ( *(_BYTE *)(v15 + 432) == 1 )
      {
        v44 = *(_QWORD *)(v4 + 38880);
        if ( (v44 & 1) != 0 )
        {
          *(_QWORD *)(v4 + 38880) = v44 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v4 + 38872);
        }
        else
        {
          raw_spin_unlock(v4 + 38872);
        }
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: sta info is already attached",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "hdd_sta_info_re_attach");
      }
      else
      {
        *(_WORD *)(v15 + 24) = 0;
        *(_DWORD *)(v15 + 28) = 0;
        qdf_mem_set((void *)(v15 + 32), 6u, 0);
        *(_DWORD *)(v15 + 52) = 0;
        *(_BYTE *)(v15 + 56) = 0;
        *(_QWORD *)(v15 + 68) = 0;
        *(_QWORD *)(v15 + 80) = 0;
        *(_DWORD *)(v15 + 88) = 0;
        *(_QWORD *)(v15 + 500) = 0;
        *(_WORD *)(v15 + 144) = 0;
        *(_WORD *)(v15 + 157) = 0;
        *(_DWORD *)(v15 + 44) = 0;
        *(_DWORD *)(v15 + 47) = 0;
        *(_QWORD *)(v15 + 96) = 0;
        *(_QWORD *)(v15 + 104) = 0;
        *(_QWORD *)(v15 + 112) = 0;
        *(_QWORD *)(v15 + 120) = 0;
        *(_QWORD *)(v15 + 128) = 0;
        *(_WORD *)(v15 + 136) = 0;
        *(_QWORD *)(v15 + 148) = 0;
        *(_DWORD *)(v15 + 163) = 0;
        *(_DWORD *)(v15 + 160) = 0;
        qdf_mem_set((void *)(v15 + 167), 0x1Au, 0);
        qdf_mem_set((void *)(v15 + 193), 0xCu, 0);
        v53 = *(_DWORD *)(v15 + 264);
        *(_DWORD *)(v15 + 208) = 0;
        *(_BYTE *)(v15 + 212) = 0;
        *(_QWORD *)(v15 + 228) = 0;
        *(_QWORD *)(v15 + 216) = 0;
        *(_DWORD *)(v15 + 223) = 0;
        if ( v53 )
        {
          _qdf_mem_free(*(_QWORD *)(v15 + 272));
          *(_QWORD *)(v15 + 272) = 0;
          *(_DWORD *)(v15 + 264) = 0;
        }
        *(_QWORD *)(v15 + 424) = 0;
        hdd_take_sta_info_ref(v5, v15, 0, 28);
        qdf_mem_copy((void *)(v15 + 32), a2, 6u);
        *(_BYTE *)(v15 + 432) = 1;
        v54 = *(_QWORD *)(v4 + 38880);
        if ( (v54 & 1) != 0 )
        {
          *(_QWORD *)(v4 + 38880) = v54 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v4 + 38872);
        }
        else
        {
          raw_spin_unlock(v4 + 38872);
        }
      }
      v22 = 0;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Parameter(s) null",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "hdd_sta_info_re_attach");
      v22 = 4;
    }
    hdd_put_sta_info_ref(v5, &v56, 1, 6);
  }
  else
  {
    v20 = _qdf_mem_malloc(0x200u, "hdd_softap_init_tx_rx_sta", 441);
    if ( v20 )
    {
      v21 = v20;
      *(_BYTE *)(v20 + 49) = 0;
      *(_QWORD *)(v20 + 16) = a1;
      qdf_mem_copy((void *)(v20 + 32), a2, 6u);
      v22 = hdd_sta_info_attach(v5, v21);
      if ( v22 )
      {
        if ( a2 )
        {
          v31 = *a2;
          v32 = a2[1];
          v33 = a2[2];
          v34 = a2[5];
        }
        else
        {
          v33 = 0;
          v31 = 0;
          v32 = 0;
          v34 = 0;
        }
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to attach station: %02x:%02x:%02x:**:**:%02x",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "hdd_softap_init_tx_rx_sta",
          v31,
          v32,
          v33,
          v34,
          v56,
          v57);
        _qdf_mem_free(v21);
      }
    }
    else
    {
      v22 = 2;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v22;
}
