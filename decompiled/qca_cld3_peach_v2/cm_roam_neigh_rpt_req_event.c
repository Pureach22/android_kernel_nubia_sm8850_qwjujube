__int64 __fastcall cm_roam_neigh_rpt_req_event(__int64 a1, __int64 a2)
{
  unsigned int v4; // w22
  __int64 v5; // x0
  __int64 v6; // x8
  unsigned int v7; // w10
  __int64 v8; // x0
  char v9; // w0
  unsigned int v10; // w8
  __int64 v11; // x0
  double tx_status; // d0
  char v13; // w0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 cmpt_obj; // x0
  size_t v22; // x2
  __int64 result; // x0
  _QWORD s[71]; // [xsp+8h] [xbp-238h] BYREF

  s[70] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x230u);
  qdf_mem_set(s, 0x230u, 0);
  v4 = *(_DWORD *)(a1 + 4);
  HIWORD(s[0]) = *(unsigned __int8 *)(a2 + 168);
  s[1] = qdf_get_time_of_the_day_us();
  v5 = ktime_get();
  BYTE2(s[4]) = 41;
  LOBYTE(s[4]) = 3;
  v6 = (unsigned __int128)(v5 * (__int128)0x20C49BA5E353F7CFLL) >> 64;
  v7 = HIDWORD(s[69]) & 0xFFFFFE00 | *(unsigned __int8 *)(a1 + 183);
  v8 = *(unsigned __int8 *)(a1 + 184);
  BYTE3(s[4]) = *(_BYTE *)(a1 + 179);
  s[2] = 1000LL * v4;
  s[3] = (v6 >> 7) + ((unsigned __int64)v6 >> 63);
  HIDWORD(s[69]) = v7 | 0x100;
  v9 = wlan_convert_host_to_diag_tx_fail_reason(v8);
  v10 = HIDWORD(s[69]) & 0xFFFF87FF | ((v9 & 0xF) << 11);
  v11 = *(unsigned __int8 *)(a1 + 184);
  HIDWORD(s[69]) = v10;
  tx_status = wlan_diag_get_tx_status(v11);
  HIDWORD(s[69]) = HIDWORD(s[69]) & 0xFFFFF9FF | ((v13 & 3) << 9);
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, tx_status, v14, v15, v16, v17, v18, v19, v20);
  if ( cmpt_obj )
  {
    v22 = *(unsigned __int8 *)(cmpt_obj + 178);
    if ( *(_BYTE *)(cmpt_obj + 178) )
    {
      BYTE6(s[4]) = *(_BYTE *)(cmpt_obj + 178);
      qdf_mem_copy((char *)&s[5] + 4, (const void *)(cmpt_obj + 145), v22);
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
