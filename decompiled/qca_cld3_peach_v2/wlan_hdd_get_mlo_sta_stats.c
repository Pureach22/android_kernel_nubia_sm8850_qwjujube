__int64 __fastcall wlan_hdd_get_mlo_sta_stats(__int64 a1, const void *a2, __int64 a3)
{
  __int64 v6; // x21
  __int64 v7; // x24
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  _QWORD v33[33]; // [xsp+0h] [xbp-170h] BYREF
  __int64 v34; // [xsp+108h] [xbp-68h] BYREF
  _QWORD v35[4]; // [xsp+110h] [xbp-60h] BYREF
  __int64 v36; // [xsp+130h] [xbp-40h]
  __int64 v37; // [xsp+138h] [xbp-38h]
  __int64 v38; // [xsp+140h] [xbp-30h]
  __int64 v39; // [xsp+148h] [xbp-28h]
  __int64 v40; // [xsp+150h] [xbp-20h]
  __int64 v41; // [xsp+158h] [xbp-18h]
  __int64 v42; // [xsp+160h] [xbp-10h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  memset(v35, 0, sizeof(v35));
  v34 = 128;
  memset(v33, 0, sizeof(v33));
  BYTE5(v33[5]) = 0x80;
  if ( a1 )
  {
    v6 = a1 + 52840;
    if ( v6 )
    {
      v7 = 0;
      do
      {
        if ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v7 >> 3)) > 2 )
          break;
        if ( *(_DWORD *)(v6 + 976) != 255 )
        {
          qdf_mem_set(v33, 0x108u, 0);
          BYTE5(v33[5]) = 0x80;
          wlan_hdd_get_sta_stats(v6, a2, (__int64)v33);
          if ( (*(_BYTE *)(v6 + 2697) & 1) == 0 )
            qdf_trace_msg(
              0x33u,
              8u,
              "vdev_id[%d] is inactive",
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              *(unsigned __int8 *)(v6 + 8));
          if ( SBYTE5(v33[5]) > (char)v34 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "Updating rates for link_id %d",
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              *(unsigned int *)(v6 + 976));
            LOBYTE(v34) = BYTE5(v33[5]);
            *(_WORD *)((char *)&v34 + 1) = HIWORD(v33[5]);
            *(_DWORD *)((char *)&v34 + 3) = HIDWORD(v33[6]);
            qdf_mem_copy(v35, &v33[7], 0xEu);
            qdf_mem_copy((char *)&v35[1] + 6, (char *)&v33[8] + 6, 0xEu);
            v41 = v33[0];
          }
          v36 += v33[3];
          v37 += v33[4];
          LODWORD(v38) = v38 + HIDWORD(v33[10]);
          HIDWORD(v38) += LODWORD(v33[11]);
          LODWORD(v39) = v39 + HIDWORD(v33[11]);
          HIDWORD(v39) += LODWORD(v33[12]);
          LODWORD(v40) = v40 + HIDWORD(v33[26]);
          HIDWORD(v40) += LODWORD(v33[27]);
        }
        v6 += 6088;
        v7 += 6088;
      }
      while ( v6 );
    }
  }
  wlan_hdd_copy_hdd_stats_to_sinfo(a3, (__int64)&v34);
  qdf_trace_msg(0x33u, 8u, "Sending aggregated mlo station stats", v16, v17, v18, v19, v20, v21, v22, v23);
  result = qdf_trace_msg(0x33u, 8u, "%s: exit", v24, v25, v26, v27, v28, v29, v30, v31, "wlan_hdd_get_mlo_sta_stats");
  _ReadStatusReg(SP_EL0);
  return result;
}
