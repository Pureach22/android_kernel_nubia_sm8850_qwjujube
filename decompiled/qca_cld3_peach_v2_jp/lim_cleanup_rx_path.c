__int64 __fastcall lim_cleanup_rx_path(
        __int64 a1,
        __int16 *a2,
        __int64 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x24
  _BYTE *v17; // x23
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  __int16 v35; // w8
  __int64 v36; // x0
  char v37; // w8
  __int64 v38; // [xsp+8h] [xbp-38h] BYREF
  __int64 v39; // [xsp+10h] [xbp-30h]
  __int64 v40; // [xsp+18h] [xbp-28h]
  __int64 v41; // [xsp+20h] [xbp-20h]
  __int64 v42; // [xsp+28h] [xbp-18h]
  __int64 v43; // [xsp+30h] [xbp-10h]
  __int64 v44; // [xsp+38h] [xbp-8h]

  v16 = a1 + 0x2000;
  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = (_BYTE *)(a3 + 7286);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Cleanup Rx Path for AID: %d limSmeState: %d, mlmState: %d, delete_peer %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "lim_cleanup_rx_path",
    (unsigned __int16)a2[168],
    *(unsigned int *)(a3 + 80),
    *((unsigned int *)a2 + 2),
    a4 & 1);
  *v17 = 0;
  if ( *(_BYTE *)(v16 + 684) )
  {
    qdf_trace(53, 0xEu, *(_WORD *)(a3 + 8), 11);
    tx_timer_deactivate(a1 + 1344);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Reset gLimAddtsSent flag and send addts timeout to SME",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "lim_cleanup_rx_path");
    lim_process_sme_addts_rsp_timeout(a1, *(unsigned __int8 *)(v16 + 685));
  }
  if ( *((_DWORD *)a2 + 2) != 15
    || (lim_deactivate_and_change_per_sta_id_timer(a1, 8, (unsigned __int16)a2[168]), (a2[16] & 2) != 0) )
  {
    lim_admit_control_delete_sta(a1, a2[168], v18, v19, v20, v21, v22, v23, v24, v25);
    v35 = *a2;
    v42 = 0;
    v43 = 0;
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    *a2 = v35 & 0xFFFE;
    if ( a1 )
    {
      if ( a3 )
      {
        v36 = _qdf_mem_malloc(6u, "lim_send_sme_tsm_ie_ind", 4893);
        if ( v36 )
        {
          v37 = *(_BYTE *)(a3 + 10);
          *(_DWORD *)v36 = 0;
          LOWORD(v38) = 5202;
          *(_BYTE *)(v36 + 4) = v37;
          v39 = v36;
          HIDWORD(v38) = 0;
          sys_process_mmh_msg(a1, &v38);
        }
      }
    }
    if ( (a4 & 1) == 0 )
      goto LABEL_16;
    *((_DWORD *)a2 + 2) = 22;
    if ( *(_DWORD *)(a3 + 88) == 2 )
    {
      qdf_trace(53, 0, *(_WORD *)(a3 + 8), 22);
      *(_DWORD *)(a3 + 72) = 22;
      lim_deactivate_and_change_timer(a1, 2);
    }
    if ( (v17[1351] & 1) == 0 )
    {
      if ( *(_DWORD *)(a3 + 80) == 7 )
        result = lim_del_bss(a1, a2);
      else
        result = lim_del_sta(a1, a2, 1, a3);
    }
    else
    {
LABEL_16:
      result = 0;
    }
  }
  else
  {
    if ( *(_DWORD *)(a3 + 88) == 1 )
      lim_del_sta(a1, a2, 1, a3);
    else
      lim_delete_dph_hash_entry(a1, a2 + 169, (unsigned __int16)a2[168], a3);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
