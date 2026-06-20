__int64 __fastcall cm_roam_neigh_rpt_req_event(__int64 a1, __int64 a2)
{
  unsigned int v4; // w22
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x0
  __int64 v10; // x8
  unsigned int v11; // w10
  __int64 v12; // x0
  char v13; // w0
  unsigned int v14; // w8
  __int64 v15; // x0
  double tx_status; // d0
  char v17; // w0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 cmpt_obj; // x0
  size_t v26; // x2
  __int64 result; // x0
  _QWORD s[71]; // [xsp+8h] [xbp-238h] BYREF

  s[70] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x230u);
  qdf_mem_set(s, 0x230u, 0);
  v4 = *(_DWORD *)(a1 + 4);
  HIWORD(s[0]) = *(unsigned __int8 *)(a2 + 104);
  s[1] = qdf_get_time_of_the_day_us();
  v9 = ktime_get(s[1], v5, v6, v7, v8);
  BYTE2(s[4]) = 41;
  LOBYTE(s[4]) = 3;
  v10 = (unsigned __int128)(v9 * (__int128)0x20C49BA5E353F7CFLL) >> 64;
  v11 = HIDWORD(s[69]) & 0xFFFFFE00 | *(unsigned __int8 *)(a1 + 183);
  v12 = *(unsigned __int8 *)(a1 + 184);
  BYTE3(s[4]) = *(_BYTE *)(a1 + 179);
  s[2] = 1000LL * v4;
  s[3] = (v10 >> 7) + ((unsigned __int64)v10 >> 63);
  HIDWORD(s[69]) = v11 | 0x100;
  v13 = wlan_convert_host_to_diag_tx_fail_reason(v12);
  v14 = HIDWORD(s[69]) & 0xFFFF87FF | ((v13 & 0xF) << 11);
  v15 = *(unsigned __int8 *)(a1 + 184);
  HIDWORD(s[69]) = v14;
  tx_status = wlan_diag_get_tx_status(v15);
  HIDWORD(s[69]) = HIDWORD(s[69]) & 0xFFFFF9FF | ((v17 & 3) << 9);
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, tx_status, v18, v19, v20, v21, v22, v23, v24);
  if ( cmpt_obj )
  {
    v26 = *(unsigned __int8 *)(cmpt_obj + 162);
    if ( *(_BYTE *)(cmpt_obj + 162) )
    {
      BYTE6(s[4]) = *(_BYTE *)(cmpt_obj + 162);
      qdf_mem_copy((char *)&s[5] + 4, (const void *)(cmpt_obj + 129), v26);
    }
    else
    {
      BYTE6(s[4]) = 0;
    }
  }
  result = host_diag_event_report_payload(3383, 560, s);
  _ReadStatusReg(SP_EL0);
  return result;
}
