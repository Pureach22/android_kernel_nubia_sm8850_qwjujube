__int64 __fastcall epping_tx_send_int(__int64 a1, __int64 *a2)
{
  __int64 *v4; // x22
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x10
  __int64 v8; // x11
  __int64 v9; // x9
  __int64 v10; // x11
  __int64 v11; // x10
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 v21; // x5
  unsigned int v22; // w22
  __int64 result; // x0
  __int64 v24; // x21
  int v25; // w8
  int v26; // w9
  __int64 v27; // x22
  unsigned int v28; // w20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x8
  __int64 v46; // x9
  __int64 v47; // [xsp+0h] [xbp-50h] BYREF
  __int64 v48; // [xsp+8h] [xbp-48h]
  __int64 v49; // [xsp+10h] [xbp-40h]
  __int64 v50; // [xsp+18h] [xbp-38h]
  __int64 v51; // [xsp+20h] [xbp-30h]
  __int64 v52; // [xsp+28h] [xbp-28h]
  __int64 v53; // [xsp+30h] [xbp-20h]
  __int64 v54; // [xsp+38h] [xbp-18h]
  __int16 v55; // [xsp+40h] [xbp-10h]
  __int64 v56; // [xsp+48h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 **)(a1 + 224);
  v5 = *a2;
  v47 = *v4;
  v6 = v4[4];
  v7 = v4[1];
  v8 = v4[2];
  v50 = v4[3];
  v51 = v6;
  v48 = v7;
  v49 = v8;
  v10 = v4[6];
  v9 = v4[7];
  v11 = v4[5];
  v55 = *((_WORD *)v4 + 32);
  v53 = v10;
  v54 = v9;
  v52 = v11;
  v12 = epping_alloc_cookie(v5);
  if ( !v12 )
  {
    qdf_trace_msg(
      0x33u,
      1u,
      "%s: epping_alloc_cookie returns no resource\n",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "epping_tx_send_int",
      v47,
      v48,
      v49,
      v50,
      v51);
    result = 0xFFFFFFFFLL;
LABEL_17:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v21 = *((unsigned __int8 *)v4 + 11);
  if ( v21 < 4 )
  {
    v22 = *(_DWORD *)(*a2 + 4 * v21 + 64);
    if ( v22 < 4 )
    {
      v24 = v12;
      if ( (unsigned __int16)v52 == 5 || (unsigned __int16)v52 == 2 )
        ((void (__fastcall *)(__int64 *, _QWORD, _QWORD))epping_set_kperf_flag)(a2, v22, BYTE4(v53));
      *(_QWORD *)(v24 + 16) = v24;
      *(_QWORD *)(v24 + 32) = *(_QWORD *)(a1 + 224);
      if ( (*(_BYTE *)(a1 + 68) & 4) != 0 )
        v25 = *(unsigned __int16 *)(a1 + 66);
      else
        v25 = 0;
      v26 = *(_DWORD *)(a1 + 112);
      *(_WORD *)(v24 + 56) = 0;
      *(_DWORD *)(v24 + 72) = 0;
      *(_BYTE *)(v24 + 64) = 0;
      *(_DWORD *)(v24 + 44) = v26 + v25;
      *(_DWORD *)(v24 + 48) = v22;
      *(_QWORD *)(v24 + 96) = a1;
      v27 = *(int *)(a1 + 112);
      v28 = htc_send_pkt(*(_QWORD *)(*a2 + 56), v24);
      epping_log_packet(a2, (__int64)&v47, v29, v30, v31, v32, v33, v34, v35, v36);
      if ( v28 )
      {
        qdf_trace_msg(
          0x33u,
          1u,
          "%s: htc_send_pkt failed, status = %d\n",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "epping_tx_send_int",
          v28,
          v47,
          v48,
          v49,
          v50,
          v51);
        epping_free_cookie(*a2, v24);
        result = 0xFFFFFFFFLL;
      }
      else
      {
        result = 0;
        v45 = a2[24];
        v46 = a2[18] + 1;
        a2[20] += v27;
        a2[18] = v46;
        if ( v45 | v46 )
        {
          if ( !((v45 + v46) % 0xC350uLL) )
          {
            epping_log_stats(a2, (__int64)"epping_tx_send_int", v37, v38, v39, v40, v41, v42, v43, v44);
            result = 0;
          }
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        1u,
        "%s: invalid eid = %d, ac = %d\n",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "epping_tx_send_int",
        v22,
        v47,
        v48,
        v49,
        v50,
        v51);
      result = 0xFFFFFFFFLL;
    }
    goto LABEL_17;
  }
  __break(0x5512u);
  return qdf_spin_lock_bh_11();
}
