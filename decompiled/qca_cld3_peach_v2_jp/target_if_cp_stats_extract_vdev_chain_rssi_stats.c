__int64 __fastcall target_if_cp_stats_extract_vdev_chain_rssi_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  char v17; // w0
  char v18; // w22
  __int64 v19; // x28
  unsigned __int64 v20; // x23
  const char *v21; // x24
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w27
  unsigned int v31; // w26
  unsigned int v32; // w26
  unsigned int v33; // w27
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 result; // x0
  __int64 v43; // [xsp+8h] [xbp-58h] BYREF
  __int64 v44; // [xsp+10h] [xbp-50h]
  __int64 v45; // [xsp+18h] [xbp-48h]
  __int64 v46; // [xsp+20h] [xbp-40h]
  __int64 v47; // [xsp+28h] [xbp-38h]
  __int64 v48; // [xsp+30h] [xbp-30h]
  __int64 v49; // [xsp+38h] [xbp-28h]
  __int64 v50; // [xsp+40h] [xbp-20h]
  __int64 v51; // [xsp+48h] [xbp-18h]
  int v52; // [xsp+50h] [xbp-10h]
  __int64 v53; // [xsp+58h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a2 + 40);
  *(_DWORD *)(a3 + 120) = v4;
  if ( (_DWORD)v4 )
  {
    v52 = 0;
    v50 = 0;
    v51 = 0;
    v48 = 0;
    v49 = 0;
    v46 = 0;
    v47 = 0;
    v44 = 0;
    v45 = 0;
    v43 = 0;
    v8 = _qdf_mem_malloc(3 * v4, "target_if_cp_stats_extract_vdev_chain_rssi_stats", 870);
    *(_QWORD *)(a3 + 128) = v8;
    if ( !v8 )
    {
      result = 2;
      goto LABEL_13;
    }
    v17 = wmi_service_enabled(a1, 0xACu, v9, v10, v11, v12, v13, v14, v15, v16);
    if ( *(_DWORD *)(a3 + 120) )
    {
      v18 = v17;
      v19 = 0;
      v20 = 0;
      if ( (v17 & 1) != 0 )
        v21 = "RSSI";
      else
        v21 = "SNR";
      do
      {
        if ( !(unsigned int)wmi_extract_per_chain_rssi_stats(a1, a4, (unsigned int)v20, &v43) )
        {
          *(_BYTE *)(*(_QWORD *)(a3 + 128) + v19) = v43;
          v30 = HIDWORD(v43);
          v31 = HIDWORD(v47);
          qdf_trace_msg(
            0x62u,
            8u,
            "vdev %d Chain %d %s bcn: %d data: %d",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            (unsigned int)v43,
            0,
            v21,
            HIDWORD(v43),
            HIDWORD(v47));
          wlan_util_stats_get_rssi(v18 & 1, v30, v31, (char *)(*(_QWORD *)(a3 + 128) + v19 + 1));
          v32 = v48;
          v33 = v44;
          qdf_trace_msg(
            0x62u,
            8u,
            "vdev %d Chain %d %s bcn: %d data: %d",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            (unsigned int)v43,
            1,
            v21,
            (unsigned int)v44,
            (unsigned int)v48);
          wlan_util_stats_get_rssi(v18 & 1, v33, v32, (char *)(*(_QWORD *)(a3 + 128) + v19 + 2));
        }
        ++v20;
        v19 += 3;
      }
      while ( v20 < *(unsigned int *)(a3 + 120) );
    }
  }
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
