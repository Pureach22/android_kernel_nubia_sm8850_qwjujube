__int64 __fastcall cm_connect_fetch_candidates(__int64 a1, __int64 a2, unsigned int *a3, __int64 *a4, unsigned int *a5)
{
  unsigned int v10; // w24
  unsigned __int8 *rsnxe_data_from_ie_ptr; // x3
  char v12; // w0
  unsigned int v13; // w8
  char v14; // w26
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  __int64 v24; // x0
  __int64 v25; // x25
  unsigned int v26; // w8
  int v27; // w9
  __int16 v28; // w8
  int v29; // w8
  __int64 v30; // x26
  __int64 v31; // x0
  const void *v32; // x26
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 scan_result; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w27
  __int64 v51; // x26
  unsigned int *v52; // [xsp+0h] [xbp-20h] BYREF
  _WORD v53[2]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v54; // [xsp+18h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 *)(*(_QWORD *)a2 + 104LL);
  rsnxe_data_from_ie_ptr = wlan_get_rsnxe_data_from_ie_ptr(*((unsigned __int8 **)a3 + 21), a3[40]);
  v12 = wlan_cm_6ghz_allowed_for_akm(
          *(_QWORD *)(a1 + 80),
          a3[24],
          *((_WORD *)a3 + 64),
          (__int64)rsnxe_data_from_ie_ptr,
          *((unsigned __int8 *)a3 + 200),
          (a3[48] & 2) != 0);
  v13 = a3[17];
  v14 = v12;
  if ( !v13 || (v12 & 1) != 0 || (wlan_reg_is_6ghz_chan_freq(v13) & 1) == 0 )
  {
    v24 = _qdf_mem_malloc(0x2D0u, "cm_connect_fetch_candidates", 1584);
    if ( !v24 )
    {
      result = 2;
      goto LABEL_41;
    }
    v25 = v24;
    if ( a3[4] | *((unsigned __int16 *)a3 + 10) )
    {
      *(_BYTE *)(v24 + 16) = 1;
      v26 = a3[4];
      *(_WORD *)(v24 + 74) = *((_WORD *)a3 + 10);
      *(_DWORD *)(v24 + 70) = v26;
    }
    v27 = *(unsigned int *)((char *)a3 + 61);
    *(_WORD *)(v24 + 68) = *(_WORD *)((char *)a3 + 65);
    *(_DWORD *)(v24 + 64) = v27;
    *(_BYTE *)(v24 + 17) = 1;
    qdf_mem_copy((void *)(v24 + 100), a3 + 7, 0x21u);
    if ( a3[17] )
    {
      *(_WORD *)(v25 + 18) = 1;
      *(_DWORD *)(v25 + 268) = a3[17];
    }
    if ( (v14 & 1) == 0 )
      *(_WORD *)v25 |= 0x20u;
    if ( *((_BYTE *)a3 + 816) == 1 )
      *(_WORD *)v25 &= ~0x20u;
    if ( (a3[48] & 7) != 0 )
    {
      *(_WORD *)v25 |= 8u;
      goto LABEL_23;
    }
    *(_DWORD *)(v25 + 40) = a3[21];
    *(_DWORD *)(v25 + 48) = a3[23];
    *(_DWORD *)(v25 + 44) = a3[24];
    *(_DWORD *)(v25 + 52) = a3[22];
    *(_DWORD *)(v25 + 56) = a3[33];
    v28 = *((_WORD *)a3 + 64);
    if ( (v28 & 0x40) != 0 )
    {
      v29 = 2;
    }
    else
    {
      if ( (v28 & 0x80) == 0 )
      {
        *(_DWORD *)(v25 + 24) = 0;
        goto LABEL_23;
      }
      v29 = 1;
    }
    *(_DWORD *)(v25 + 24) = v29;
LABEL_23:
    v30 = *(_QWORD *)(a1 + 80);
    *(_DWORD *)(v25 + 20) = 1;
    *(_WORD *)v25 = *(_WORD *)v25 & 0xFFFE | wlan_mlme_adaptive_11r_enabled(v30) & 1;
    if ( !*(_DWORD *)(*(_QWORD *)a2 + 16LL) )
    {
      if ( (a3[204] & 1) == 0 )
        ((void (__fastcall *)(__int64, __int64))wlan_cm_dual_sta_roam_update_connect_channels)(v30, v25);
      *(_DWORD *)(v25 + 28) = a3[49];
      if ( *((_BYTE *)a3 + 216) == 1 )
      {
        if ( a3[120] )
        {
          v53[0] = 0;
          v31 = _qdf_mem_malloc(0x20u, "cm_create_fils_realm_hash", 779);
          if ( v31 )
          {
            v32 = (const void *)v31;
            v52 = a3 + 121;
            qdf_get_hash((__int64)"sha256", 1u, (__int64)&v52, a3 + 120);
            qdf_mem_copy(v53, v32, 2u);
            _qdf_mem_free((__int64)v32);
            *(_BYTE *)(v25 + 60) = 1;
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: vdev %d cm_id 0x%x: creating realm based on fils info",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "cm_update_fils_scan_filter",
              *((unsigned __int8 *)a3 + 8),
              *a3);
            qdf_mem_copy((void *)(v25 + 61), v53, 2u);
          }
        }
      }
      *(_BYTE *)(v25 + 712) = *(_BYTE *)(*(_QWORD *)a2 + 92LL);
    }
    scan_result = scm_get_scan_result(a1, v25);
    if ( scan_result )
    {
      v50 = *(_DWORD *)(scan_result + 16);
      v51 = scan_result;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d cm_id 0x%x: num_entries found %d",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "cm_connect_fetch_candidates",
        v10,
        *a3,
        v50);
      *a5 = v50;
      if ( v50 && !*(_DWORD *)(*(_QWORD *)a2 + 16LL) && (a3[204] & 1) == 0 )
        cm_calculate_scores(a2, a1, v25, v51, a3[1] == 0);
      _qdf_mem_free(v25);
      if ( *(_DWORD *)(v51 + 16) )
      {
        result = 0;
        *a4 = v51;
        goto LABEL_41;
      }
      scm_purge_scan_results(v51);
    }
    else
    {
      *a5 = 0;
      _qdf_mem_free(v25);
    }
    result = 13;
    goto LABEL_41;
  }
  qdf_trace_msg(
    0x68u,
    4u,
    "%s: vdev %d cm_id 0x%x: 6ghz freq (%d) given and 6Ghz not allowed for the security in connect req",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "cm_connect_fetch_candidates",
    v10,
    *a3,
    a3[17]);
  result = 4;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
