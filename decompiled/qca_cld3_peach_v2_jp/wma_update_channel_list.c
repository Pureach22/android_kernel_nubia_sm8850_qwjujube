__int64 __fastcall wma_update_channel_list(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v4; // w8
  unsigned int v5; // w22
  void *v6; // x0
  __int64 v7; // x20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int16 v16; // w8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x22
  unsigned __int64 v34; // x24
  _BYTE *v35; // x26
  unsigned int v36; // w8
  __int64 v37; // x23
  unsigned int v38; // w0
  __int64 v39; // x8
  __int16 v40; // w8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int v57; // w9
  unsigned int v58; // w19
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  _QWORD v68[3]; // [xsp+8h] [xbp-18h] BYREF

  v68[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a2;
  v68[0] = 0;
  v68[1] = 0;
  v5 = 36 * v4 + 12;
  v6 = (void *)_qdf_mem_malloc(36LL * v4 + 12, "wma_update_channel_list", 166);
  if ( v6 )
  {
    v7 = (__int64)v6;
    qdf_mem_set(v6, v5, 0);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: no of channels = %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wma_update_channel_list",
      *a2);
    v16 = *a2;
    *(_BYTE *)(v7 + 7) = 1;
    *(_WORD *)(v7 + 4) = v16;
    *(_BYTE *)(a1 + 3364) = *a2;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: ht %d, vht %d, vht_24 %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wma_update_channel_list",
      a2[1],
      a2[2],
      a2[3]);
    if ( *a2 )
    {
      v33 = 0;
      v34 = 0;
      v35 = a2 + 16;
      do
      {
        v36 = *((_DWORD *)v35 - 2);
        v37 = v7 + v33;
        *(_DWORD *)(v37 + 16) = v36;
        *(_QWORD *)(v37 + 28) = v36;
        if ( v33 == 3672 )
          __break(0x5512u);
        *(_DWORD *)(a1 + 3368 + 4 * v34) = *((_DWORD *)v35 - 2);
        if ( *(v35 - 3) == 1 )
          *(_WORD *)(v7 + v33 + 20) |= 0x14u;
        if ( *v35 == 1 )
          *(_WORD *)(v7 + v33 + 20) |= 0x400u;
        v38 = *(_DWORD *)(v37 + 16);
        v39 = v7 + v33;
        if ( v38 > 0xBB7 )
        {
          *(_DWORD *)(v39 + 24) = 0;
          if ( a2[2] && !wlan_reg_is_6ghz_chan_freq(v38) )
LABEL_16:
            *(_WORD *)(v7 + v33 + 20) |= 0x40u;
        }
        else
        {
          *(_DWORD *)(v39 + 24) = 1;
          if ( a2[2] && a2[3] )
            goto LABEL_16;
        }
        if ( a2[1] && !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v37 + 16)) )
          *(_WORD *)(v7 + v33 + 20) |= 0x20u;
        if ( a2[4] == 1 )
          *(_WORD *)(v7 + v33 + 20) |= 0x100u;
        if ( a2[5] == 1 )
          *(_WORD *)(v7 + v33 + 20) |= 0x800u;
        if ( (*(v35 - 2) & 1) != 0 )
        {
          v40 = 1;
        }
        else
        {
          if ( *(v35 - 1) != 1 )
            goto LABEL_29;
          v40 = 2;
        }
        *(_WORD *)(v7 + v33 + 20) |= v40;
LABEL_29:
        if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v37 + 16))
          && (wlan_reg_is_6ghz_psc_chan_freq(*(_DWORD *)(v37 + 16), v41, v42, v43, v44, v45, v46, v47, v48) & 1) != 0 )
        {
          *(_WORD *)(v7 + v33 + 20) |= 0x200u;
        }
        *(_BYTE *)(v7 + v33 + 38) = *(v35 - 4);
        qdf_mem_set(v68, 0x10u, 0);
        LODWORD(v68[0]) = 3;
        wlan_reg_set_channel_params_for_pwrmode(
          *(_QWORD *)(a1 + 32),
          *(_DWORD *)(v37 + 16),
          0,
          (__int64)v68,
          0,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56);
        v57 = 0;
        if ( (unsigned int)(LODWORD(v68[0]) - 1) <= 6 )
          v57 = dword_A183DC[LODWORD(v68[0]) - 1];
        *(_DWORD *)(v7 + v33 + 44) = v57;
        ++v34;
        v33 += 36;
        v35 += 12;
      }
      while ( v34 < *a2 );
    }
    *(_BYTE *)(v7 + 8) = wlan_reg_does_country_supp_c2c(*(_QWORD *)(a1 + 32), v25, v26, v27, v28, v29, v30, v31, v32)
                       & 1;
    v58 = wmi_unified_scan_chan_list_cmd_send(*(_QWORD *)a1);
    if ( v58 )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to send WMI_SCAN_CHAN_LIST_CMDID",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        "wma_update_channel_list");
    _qdf_mem_free(v7);
  }
  else
  {
    v58 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v58;
}
