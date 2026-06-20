__int64 __fastcall dp_rx_tid_update_wifi3(
        __int64 a1,
        int a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  char v17; // w21
  __int64 v18; // x8
  int v19; // w9
  __int64 v20; // x22
  __int64 v21; // x8
  __int64 result; // x0
  __int64 v23; // x24
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // w9
  _DWORD *v42; // x8
  _QWORD v43[4]; // [xsp+0h] [xbp-30h] BYREF
  __int64 v44; // [xsp+20h] [xbp-10h]
  __int64 v45; // [xsp+28h] [xbp-8h]

  v17 = a2;
  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(_QWORD *)(a1 + 24);
  v19 = *(_DWORD *)(a1 + 408);
  memset(v43, 0, sizeof(v43));
  v20 = *(_QWORD *)(*(_QWORD *)(v18 + 24) + 8LL);
  v21 = *(_QWORD *)(a1 + 88);
  v44 = 0;
  if ( v19 == 1 && *(_QWORD *)(a1 + 416) )
  {
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: skip tid update for peer:%02x:%02x:%02x:**:**:%02x",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "dp_rx_tid_update_wifi3",
      *(unsigned __int8 *)(a1 + 44),
      *(unsigned __int8 *)(a1 + 45),
      *(unsigned __int8 *)(a1 + 46),
      *(unsigned __int8 *)(a1 + 49),
      v43[0],
      v43[1]);
    result = 16;
  }
  else
  {
    v23 = v21 + 144LL * a2;
    qdf_mem_set(v43, 0x28u, 0);
    LOBYTE(v43[0]) = 1;
    v32 = *(_QWORD *)(v23 + 56);
    HIDWORD(v43[0]) = v32;
    LOBYTE(v43[1]) = BYTE4(v32);
    if ( a4 > 0xFFF )
    {
      *(_QWORD *)((char *)&v43[1] + 4) |= 0x20400uLL;
      *(_QWORD *)((char *)&v43[2] + 4) = *(_QWORD *)((char *)&v43[2] + 4) & 0xFFFFFFFFFFFD8000LL | a3 & 0x7FFF;
      qdf_trace_msg(
        0x81u,
        8u,
        "%s: Setting SSN valid bit to %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "dp_set_ssn_valid_flag",
        0,
        v43[0],
        v43[1],
        v43[2],
        v43[3],
        v44,
        v45);
    }
    else
    {
      *(_QWORD *)((char *)&v43[1] + 4) |= 0x40400uLL;
      *(_QWORD *)((char *)&v43[2] + 4) = *(_QWORD *)((char *)&v43[2] + 4) & 0xFFFFFFFFC0038000LL
                                       | a3 & 0x7FFF
                                       | (a4 << 18);
    }
    if ( (unsigned int)dp_reo_send_cmd(
                         v20,
                         5u,
                         v24,
                         v25,
                         v26,
                         v27,
                         v28,
                         v29,
                         v30,
                         v31,
                         (__int64)v43,
                         (__int64)dp_rx_tid_update_cb,
                         v23) )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: failed to send reo cmd CMD_UPDATE_RX_REO_QUEUE",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "dp_rx_tid_update_wifi3");
      if ( v20 )
        ++*(_DWORD *)(v20 + 14092);
    }
    *(_WORD *)(v23 + 72) = a3;
    v41 = dp_get_peer_vdev_roaming_in_progress(a1, v33, v34, v35, v36, v37, v38, v39, v40) & 1;
    if ( v41 )
      result = 12;
    else
      result = 0;
    if ( !v41 && (a5 & 1) == 0 )
    {
      v42 = *(_DWORD **)(v20 + 1616);
      if ( *(v42 - 1) != -1687924027 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD))v42)(v20, a1, 1LL << v17, a3, 0);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
