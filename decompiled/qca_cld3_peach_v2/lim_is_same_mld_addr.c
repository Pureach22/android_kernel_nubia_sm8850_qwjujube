__int64 __fastcall lim_is_same_mld_addr(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  bool v22; // zf
  __int64 v23; // x21
  __int64 result; // x0
  int v25; // [xsp+0h] [xbp-30h]
  int v26; // [xsp+8h] [xbp-28h]
  int v27; // [xsp+10h] [xbp-20h]
  int v28; // [xsp+18h] [xbp-18h]
  int v29; // [xsp+20h] [xbp-10h] BYREF
  __int16 v30; // [xsp+24h] [xbp-Ch]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a2 + 16);
  v30 = 0;
  v29 = 0;
  if ( (mlo_is_mld_sta(v5) & 1) == 0 && *(_BYTE *)(a3 + 3437) != 1 )
    goto LABEL_12;
  if ( (mlo_is_mld_sta(*(_QWORD *)(a2 + 16)) & 1) != 0 && *(_BYTE *)(a3 + 3437) == 1 )
  {
    if ( (unsigned int)wlan_vdev_get_bss_peer_mld_mac(*(_QWORD *)(a2 + 16), &v29, v6, v7, v8, v9, v10, v11, v12, v13)
      || (v29 == *(_DWORD *)(a3 + 3441) ? (v22 = v30 == *(_WORD *)(a3 + 3445)) : (v22 = 0), !v22) )
    {
      v23 = jiffies;
      if ( lim_is_same_mld_addr___last_ticks - jiffies + 125 < 0 )
      {
        v26 = *(unsigned __int8 *)(a3 + 3442);
        v28 = *(unsigned __int8 *)(a3 + 3446);
        v27 = *(unsigned __int8 *)(a3 + 3443);
        v25 = *(unsigned __int8 *)(a3 + 3441);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: mld addr mismatch, bss peer %02x:%02x:%02x:**:**:%02x bcn %02x:%02x:%02x:**:**:%02x",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_is_same_mld_addr",
          (unsigned __int8)v29,
          BYTE1(v29),
          BYTE2(v29),
          HIBYTE(v30),
          v25,
          v26,
          v27,
          v28);
        result = 0;
        lim_is_same_mld_addr___last_ticks = v23;
        goto LABEL_13;
      }
      goto LABEL_11;
    }
LABEL_12:
    result = 1;
    goto LABEL_13;
  }
LABEL_11:
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
