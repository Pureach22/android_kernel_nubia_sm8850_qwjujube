__int64 __fastcall sch_process_pre_beacon_ind(__int64 a1, __int64 a2, int a3)
{
  unsigned __int8 *v5; // x19
  __int64 session_by_bssid; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  const char *v15; // x2
  const char *v16; // x2
  unsigned int v17; // w1
  unsigned int v18; // w21
  __int64 v20; // x8
  char v21; // w11
  int v22; // w23
  __int64 v23; // x9
  int v24; // w5
  unsigned __int16 v25; // w10
  int v26; // w22
  __int64 v27; // x22
  unsigned __int64 v28; // x8
  int v29; // w9
  __int64 v30; // x12
  char v31; // w10
  int v32; // w8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int8 v41[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned __int8 **)(a2 + 8);
  v41[0] = 0;
  session_by_bssid = pe_find_session_by_bssid(a1, v5, v41);
  if ( !session_by_bssid )
  {
    v15 = "%s: session lookup fails";
    goto LABEL_7;
  }
  if ( *(_DWORD *)(session_by_bssid + 80) != 16 )
  {
    v16 = "%s: PreBeaconInd received in invalid state: %d";
    v17 = 8;
LABEL_10:
    qdf_trace_msg(0x35u, v17, v16, v7, v8, v9, v10, v11, v12, v13, v14, "sch_process_pre_beacon_ind");
    goto LABEL_11;
  }
  if ( *(_DWORD *)(session_by_bssid + 88) != 1 )
  {
    v16 = "%s: Error-PE has Receive PreBeconGenIndication when System is in %d role";
    v17 = 2;
    goto LABEL_10;
  }
  if ( *(_WORD *)(session_by_bssid + 248) )
  {
    v15 = "%s: can not send beacon for PEER session entry";
LABEL_7:
    qdf_trace_msg(0x35u, 2u, v15, v7, v8, v9, v10, v11, v12, v13, v14, "sch_process_pre_beacon_ind");
LABEL_11:
    v18 = 16;
    goto LABEL_12;
  }
  v20 = *(unsigned __int16 *)(session_by_bssid + 7360);
  v21 = *(_BYTE *)(session_by_bssid + 251);
  v22 = v20 + 10;
  v23 = *(_QWORD *)(session_by_bssid + 7344) + v20;
  *(_WORD *)v23 = 2053;
  *(_BYTE *)(v23 + 2) = -1;
  *(_BYTE *)(v23 + 3) = v21;
  *(_BYTE *)(v23 + 4) = -1;
  if ( (_WORD)v20 == 0xFFF6 )
  {
    v25 = 0;
    LOWORD(v26) = 4;
  }
  else
  {
    v24 = *(unsigned __int16 *)(session_by_bssid + 7362);
    if ( v24 + (unsigned int)(unsigned __int16)(v20 + 10) >= 0x201 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: beacon tmp fail size %d BeaconOffsetEnd %d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "write_beacon_to_memory");
      goto LABEL_11;
    }
    v27 = session_by_bssid;
    lim_reorder_vendor_ies(a1, *(_QWORD *)(session_by_bssid + 7352), v24);
    session_by_bssid = v27;
    if ( *(_WORD *)(v27 + 7362) )
    {
      v28 = 0;
      v29 = v22;
      do
      {
        v30 = (unsigned __int16)v29;
        v26 = v29 + 1;
        v31 = *(_BYTE *)(*(_QWORD *)(session_by_bssid + 7352) + v28++);
        v29 = v26;
        *(_BYTE *)(*(_QWORD *)(session_by_bssid + 7344) + v30) = v31;
        v25 = v26;
      }
      while ( v28 < *(unsigned __int16 *)(session_by_bssid + 7362) );
    }
    else
    {
      LOWORD(v26) = v22;
      v25 = v22;
    }
  }
  v32 = v25 - 4;
  if ( !(_WORD)v22 )
    v32 = 0;
  **(_DWORD **)(session_by_bssid + 7344) = v32;
  if ( !*(_BYTE *)(a1 + 12450) )
    goto LABEL_11;
  v18 = sch_send_beacon_req(a1, *(const void **)(session_by_bssid + 7344), v26, session_by_bssid, a3);
  if ( v18 )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: sch_send_beacon_req() returned an error %d, size %d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "write_beacon_to_memory",
      v18,
      (unsigned __int16)v26);
  *(_BYTE *)(a1 + 12450) = 0;
LABEL_12:
  _qdf_mem_free((__int64)v5);
  _ReadStatusReg(SP_EL0);
  return v18;
}
