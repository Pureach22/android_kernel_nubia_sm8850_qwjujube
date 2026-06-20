__int64 __fastcall wlan_hdd_fill_summary_stats(_DWORD *a1, __int64 a2, unsigned int a3)
{
  unsigned __int8 v4; // w20
  int v5; // w8
  int v6; // w8
  int v7; // w9
  int v8; // w10
  int v9; // w8
  int v10; // w9
  int v11; // w10
  int v12; // w8
  int v13; // w9
  int v14; // w10
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x5
  unsigned int v25; // w21
  int v26; // w8
  __int64 v27; // x24
  __int64 v28; // x22
  __int64 v29; // [xsp+8h] [xbp-18h] BYREF
  int v30; // [xsp+10h] [xbp-10h]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v4 = a3;
  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1[14];
  *(_QWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 84) = v5;
  v6 = a1[10];
  v30 = 0;
  v29 = 0;
  *(_DWORD *)(a2 + 88) = v6;
  v7 = a1[6];
  *(_DWORD *)(a2 + 92) = v7;
  v8 = a1[16];
  *(_DWORD *)(a2 + 96) = v8;
  v9 = v6 + a1[11];
  *(_DWORD *)(a2 + 88) = v9;
  v10 = v7 + a1[7];
  *(_DWORD *)(a2 + 92) = v10;
  v11 = v8 + a1[17];
  *(_DWORD *)(a2 + 96) = v11;
  v12 = v9 + a1[12];
  *(_DWORD *)(a2 + 88) = v12;
  v13 = v10 + a1[8];
  *(_DWORD *)(a2 + 92) = v13;
  v14 = v11 + a1[18];
  *(_DWORD *)(a2 + 96) = v14;
  *(_DWORD *)(a2 + 88) = v12 + a1[13];
  *(_DWORD *)(a2 + 92) = v13 + a1[9];
  *(_DWORD *)(a2 + 96) = v14 + a1[19];
  result = cds_dp_get_vdev_stats(a3, &v29);
  if ( (result & 1) != 0 )
  {
    v24 = *(unsigned int *)(a2 + 92);
    v25 = *(_DWORD *)(a2 + 96);
    v26 = v30 + v25;
    *(_DWORD *)(a2 + 92) = HIDWORD(v29);
    *(_DWORD *)(a2 + 96) = v26;
    v27 = jiffies;
    if ( wlan_hdd_fill_summary_stats___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: vdev %d tx retries adjust from %d to %d",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "wlan_hdd_fill_summary_stats",
                 v4,
                 v24);
      wlan_hdd_fill_summary_stats___last_ticks = v27;
    }
    v28 = jiffies;
    if ( wlan_hdd_fill_summary_stats___last_ticks_238 - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: tx failed adjust from %d to %d",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "wlan_hdd_fill_summary_stats",
                 v25,
                 *(unsigned int *)(a2 + 96));
      wlan_hdd_fill_summary_stats___last_ticks_238 = v28;
    }
  }
  *(_QWORD *)a2 |= 0x1C00uLL;
  _ReadStatusReg(SP_EL0);
  return result;
}
