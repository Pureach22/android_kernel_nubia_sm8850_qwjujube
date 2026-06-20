__int64 __fastcall lim_create_timers(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x24
  unsigned __int64 v11; // x23
  unsigned __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x0
  __int64 v23; // x23
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  const char *v40; // x2
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v49; // x2
  __int64 result; // x0
  __int64 v51; // x20
  __int64 v52; // x0
  unsigned __int64 v53; // x20

  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Creating Timers used by LIM module in Role: %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "lim_create_timers",
    *(unsigned int *)(a1 + 4060));
  if ( *(_DWORD *)(a1 + 4060) == 1 )
    goto LABEL_2;
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(_QWORD, _QWORD), __int64, unsigned __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                       a1,
                       a1 + 1072,
                       "JOIN FAILURE TIMEOUT",
                       lim_timer_handler,
                       5074,
                       *(unsigned int *)(*(_QWORD *)(a1 + 8) + 3680LL) / 0xAuLL,
                       0,
                       0) )
  {
    v49 = "%s: could not create Join failure timer";
LABEL_38:
    qdf_trace_msg(0x35u, 2u, v49, v41, v42, v43, v44, v45, v46, v47, v48, "lim_create_non_ap_timers");
    LODWORD(v21) = 0;
    goto LABEL_39;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(_QWORD, _QWORD), __int64, unsigned __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                       a1,
                       a1 + 2136,
                       "Periodic Join Probe Request Timer",
                       lim_timer_handler,
                       5112,
                       *(unsigned int *)(*(_QWORD *)(a1 + 8) + 3684LL) / 0xAuLL,
                       0,
                       0) )
  {
    v49 = "%s: could not create Periodic Join Probe Request tmr";
    goto LABEL_38;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(_QWORD, _QWORD), __int64, __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                       a1,
                       a1 + 2928,
                       "Periodic AUTH Timer",
                       lim_timer_handler,
                       5117,
                       6,
                       0,
                       0) )
  {
    v49 = "%s: could not create Periodic AUTH Timer";
    goto LABEL_38;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(), _QWORD, unsigned __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                       a1,
                       a1 + 280,
                       "ASSOC FAILURE TIMEOUT",
                       lim_assoc_failure_timer_handler,
                       0,
                       *(unsigned int *)(*(_QWORD *)(a1 + 8) + 3704LL) / 0xAuLL,
                       0,
                       0) )
  {
    v49 = "%s: could not create Association failure timer";
    goto LABEL_38;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(), __int64, unsigned __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                       a1,
                       a1 + 1344,
                       "ADDTS RSP TIMEOUT",
                       lim_addts_response_timer_handler,
                       5084,
                       *(unsigned int *)(*(_QWORD *)(a1 + 8) + 3716LL) / 0xAuLL,
                       0,
                       0) )
  {
    v49 = "%s: could not create Addts response timer";
    goto LABEL_38;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(_QWORD, _QWORD), __int64, unsigned __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                       a1,
                       a1 + 808,
                       "AUTH FAILURE TIMEOUT",
                       lim_timer_handler,
                       5075,
                       *(unsigned int *)(*(_QWORD *)(a1 + 8) + 3692LL) / 0xAuLL,
                       0,
                       0) )
  {
    v49 = "%s: could not create Auth failure timer";
    goto LABEL_38;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(_QWORD, _QWORD), __int64, __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                       a1,
                       a1 + 3192,
                       "SAE AUTH Timer",
                       lim_timer_handler,
                       5118,
                       500,
                       0,
                       0) )
  {
    v49 = "%s: could not create SAE AUTH Timer";
    goto LABEL_38;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(_QWORD, _QWORD), __int64, __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                       a1,
                       a1 + 3720,
                       "Channel vacate timer",
                       lim_timer_handler,
                       5120,
                       500,
                       0,
                       0) )
  {
    v49 = "%s: could not create channel vacate timer";
    goto LABEL_38;
  }
LABEL_2:
  v10 = 0;
  v11 = -1;
  v12 = *(unsigned int *)(*(_QWORD *)(a1 + 8) + 3516LL) / 0xAuLL;
  do
  {
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(), _QWORD, unsigned __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                         a1,
                         *(_QWORD *)(a1 + 1336) + v10,
                         "CNF_MISS_TIMEOUT",
                         lim_cnf_wait_tmer_handler,
                         (unsigned int)(v11 + 1),
                         v12,
                         0,
                         0) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Cannot create CNF wait timer",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "lim_create_timers");
      LODWORD(v21) = v11 + 1;
      goto LABEL_39;
    }
    ++v11;
    v10 += 264;
  }
  while ( v11 < *(unsigned __int16 *)(a1 + 3990) );
  v21 = *(unsigned int *)(*(_QWORD *)(a1 + 8) + 1896LL);
  *(_DWORD *)(a1 + 11408) = v21;
  v22 = _qdf_mem_malloc(8 * v21, "lim_create_timers", 207);
  *(_QWORD *)(a1 + 11416) = v22;
  if ( v22 )
  {
    if ( (_DWORD)v21 )
    {
      v23 = 0;
      while ( 1 )
      {
        *(_QWORD *)(*(_QWORD *)(a1 + 11416) + 8 * v23) = _qdf_mem_malloc(0x268u, "lim_create_timers", 214);
        if ( !*(_QWORD *)(*(_QWORD *)(a1 + 11416) + 8 * v23) )
          break;
        if ( (_DWORD)v21 == (_DWORD)++v23 )
          goto LABEL_10;
      }
      *(_DWORD *)(a1 + 11408) = 0;
      LODWORD(v21) = v23;
    }
    else
    {
LABEL_10:
      lim_init_pre_auth_timer_table(a1, (unsigned int *)(a1 + 11408));
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: alloc and init table for preAuth timers",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "lim_create_timers");
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(), __int64, unsigned __int64, unsigned __int64, _QWORD))tx_timer_create_intern)(
                           a1,
                           a1 + 1608,
                           "OLBC UPDATE CACHE TIMEOUT",
                           lim_update_olbc_cache_timer_handler,
                           5097,
                           *(unsigned int *)(*(_QWORD *)(a1 + 8) + 3712LL) / 0xAuLL,
                           *(unsigned int *)(*(_QWORD *)(a1 + 8) + 3712LL) / 0xAuLL,
                           0) )
      {
        v40 = "%s: Cannot create update OLBC cache tmr";
      }
      else if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(_QWORD, _QWORD), __int64, __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                                a1,
                                a1 + 2400,
                                "DISASSOC ACK TIMEOUT",
                                lim_timer_handler,
                                5110,
                                100,
                                0,
                                0) )
      {
        v40 = "%s: could not DISASSOC ACK TIMEOUT timer";
      }
      else if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(__int64, unsigned int, double, double, double, double, double, double, double, double), __int64, __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                                a1,
                                a1 + 2664,
                                "DISASSOC ACK TIMEOUT",
                                lim_process_deauth_ack_timeout,
                                255,
                                100,
                                0,
                                0) )
      {
        v40 = "%s: could not create DEAUTH ACK TIMEOUT timer";
      }
      else
      {
        result = ((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(_QWORD, _QWORD), __int64, __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                   a1,
                   a1 + 3456,
                   "STA STATS RSP timer",
                   lim_timer_handler,
                   5108,
                   1000,
                   0,
                   0);
        if ( !(_DWORD)result )
          return result;
        v40 = "%s: could not create STA STATS RSP Timer";
      }
      qdf_trace_msg(0x35u, 2u, v40, v32, v33, v34, v35, v36, v37, v38, v39, "lim_create_timers");
    }
  }
  else
  {
    LODWORD(v21) = v11 + 1;
  }
LABEL_39:
  tx_timer_delete(a1 + 3456);
  tx_timer_delete(a1 + 2664);
  tx_timer_delete(a1 + 2400);
  tx_timer_delete(a1 + 1608);
  if ( (int)v21 - 1 >= 0 )
  {
    v51 = 264LL * (unsigned int)(v21 - 1);
    do
    {
      tx_timer_delete(*(_QWORD *)(a1 + 1336) + v51);
      v51 -= 264;
    }
    while ( v51 != -264 );
  }
  tx_timer_delete(a1 + 808);
  tx_timer_delete(a1 + 1344);
  tx_timer_delete(a1 + 280);
  tx_timer_delete(a1 + 1072);
  tx_timer_delete(a1 + 2136);
  tx_timer_delete(a1 + 2928);
  tx_timer_delete(a1 + 3192);
  tx_timer_delete(a1 + 3720);
  v52 = *(_QWORD *)(a1 + 11416);
  if ( v52 )
  {
    if ( *(_DWORD *)(a1 + 11408) )
    {
      v53 = 0;
      do
        _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(a1 + 11416) + 8 * v53++));
      while ( v53 < *(unsigned int *)(a1 + 11408) );
      v52 = *(_QWORD *)(a1 + 11416);
    }
    _qdf_mem_free(v52);
    *(_QWORD *)(a1 + 11416) = 0;
  }
  return 21;
}
