__int64 __fastcall dp_rx_tid_update_wifi3(__int64 a1, int a2, unsigned int a3, unsigned int a4, char a5)
{
  char v7; // w21
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x23
  __int64 v13; // x24
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w9
  __int64 result; // x0
  _DWORD *v33; // x8
  _QWORD v34[6]; // [xsp+0h] [xbp-30h] BYREF

  v7 = a2;
  v34[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 24);
  v11 = *(_QWORD *)(a1 + 88);
  memset(v34, 0, 40);
  v12 = *(_QWORD *)(*(_QWORD *)(v10 + 24) + 8LL);
  v13 = v11 + 144LL * a2;
  qdf_mem_set(v34, 0x28u, 0);
  LOBYTE(v34[0]) = 1;
  v22 = *(_QWORD *)(v13 + 56);
  HIDWORD(v34[0]) = v22;
  LOBYTE(v34[1]) = BYTE4(v22);
  if ( a4 > 0xFFF )
  {
    *(_QWORD *)((char *)&v34[1] + 4) |= 0x20400uLL;
    *(_QWORD *)((char *)&v34[2] + 4) = *(_QWORD *)((char *)&v34[2] + 4) & 0xFFFFFFFFFFFD8000LL | a3 & 0x7FFF;
    qdf_trace_msg(
      0x81u,
      8u,
      "%s: Setting SSN valid bit to %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "dp_set_ssn_valid_flag",
      0,
      v34[0],
      v34[1],
      v34[2],
      v34[3]);
  }
  else
  {
    *(_QWORD *)((char *)&v34[1] + 4) |= 0x40400uLL;
    *(_QWORD *)((char *)&v34[2] + 4) = *(_QWORD *)((char *)&v34[2] + 4) & 0xFFFFFFFFC0038000LL
                                     | a3 & 0x7FFF
                                     | (a4 << 18);
  }
  if ( (unsigned int)dp_reo_send_cmd(
                       v12,
                       5u,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       (__int64)v34,
                       (__int64)dp_rx_tid_update_cb,
                       v13) )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: failed to send reo cmd CMD_UPDATE_RX_REO_QUEUE",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "dp_rx_tid_update_wifi3");
    if ( v12 )
      ++*(_DWORD *)(v12 + 14036);
  }
  *(_WORD *)(v13 + 72) = a3;
  v31 = dp_get_peer_vdev_roaming_in_progress(a1, v23, v24, v25, v26, v27, v28, v29, v30) & 1;
  if ( v31 )
    result = 12;
  else
    result = 0;
  if ( !v31 && (a5 & 1) == 0 )
  {
    v33 = *(_DWORD **)(v12 + 1568);
    if ( *(v33 - 1) != -1687924027 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD))v33)(v12, a1, 1LL << v7, a3, 0);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
