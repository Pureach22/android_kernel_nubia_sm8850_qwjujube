__int64 __fastcall sme_set_eht_testbed_def(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 v11; // x23
  __int64 v12; // x21
  __int64 v14; // x9
  __int64 v15; // x8
  char v16; // w10
  unsigned __int64 v17; // x9
  __int64 v18; // x0

  if ( a2 > 5u )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: No session for id %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "sme_set_eht_testbed_def");
  v10 = *(_QWORD *)(a1 + 17296) + 96LL * a2;
  if ( !v10 )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: No session for id %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "sme_set_eht_testbed_def");
  v11 = *(_QWORD *)(a1 + 8);
  v12 = a1 + 21785;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: set EHT caps testbed defaults",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "sme_set_eht_testbed_def");
  v14 = *(_QWORD *)(v11 + 1509);
  v15 = *(_QWORD *)(v11 + 1501) & 0xE000000081FFC8LL;
  *(_QWORD *)(v11 + 1517) = 0x1100001100001LL;
  v16 = *(_BYTE *)(v11 + 1525);
  *(_QWORD *)(v11 + 1501) = v15 | 0x3400000;
  *(_QWORD *)(v11 + 1509) = v14 & 0xFC0E000 | 0x1000011110000003LL;
  *(_BYTE *)(v11 + 1525) = v16 & 0xF0;
  csr_update_session_eht_cap(a1, v10);
  qdf_mem_copy((void *)(a1 + 22064), (const void *)(v11 + 1500), 0x5Cu);
  v17 = *(_QWORD *)(v12 + 296) & 0xFFFFFFFFFFFFFFF0LL;
  *(_QWORD *)(v12 + 288) &= 0xFFFFFFFFFFFFFFFuLL;
  *(_QWORD *)(v12 + 296) = v17;
  qdf_mem_copy((void *)(a1 + 22156), (const void *)(v11 + 1500), 0x5Cu);
  v18 = *(_QWORD *)(a1 + 21624);
  *(_BYTE *)v12 = 1;
  *(_DWORD *)(a1 + 17192) = 0;
  wlan_mlme_set_sta_mlo_conn_max_num(v18, 1u);
  return ucfg_mlme_set_bss_color_collision_det_sta(*(_QWORD *)(a1 + 21624), 0);
}
