__int64 __fastcall lim_extract_msd_caps(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *peer_by_mac; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _BYTE *v16; // x8
  unsigned int v17; // w10
  int v18; // w9
  __int16 v19; // w10
  __int64 v21; // x19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int16 v30; // w10
  _WORD *v31; // x11
  __int16 v32; // w9
  __int16 v33; // w12
  _WORD *v34; // x10
  __int16 v35; // w10
  __int16 v36; // w11
  __int16 v37; // w11
  unsigned int v38; // w12
  __int16 v39; // w8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 21624), (_BYTE *)a3, 7u);
  if ( !peer_by_mac )
    return qdf_trace_msg(0x35u, 2u, "%s: peer is null", v8, v9, v10, v11, v12, v13, v14, v15, "lim_extract_msd_caps");
  v16 = (_BYTE *)peer_by_mac[98];
  if ( v16 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a2 + 16) + 60LL) & 2) != 0 )
    {
      v30 = *(unsigned __int8 *)(a3 + 389);
      v31 = v16 + 628;
      *(_BYTE *)(a3 + 398) = v16[624];
      v32 = (unsigned __int8)v16[628];
      v33 = v32 | (v30 << 8);
      v34 = (_WORD *)(a3 + 388);
      *(_WORD *)(a3 + 388) = v33;
    }
    else
    {
      v17 = *(unsigned __int16 *)(a4 + 5344);
      v18 = (v17 >> 6) & 1;
      *(_BYTE *)(a3 + 398) = (v17 & 0x40) != 0;
      if ( (v17 & 0x40) != 0 )
      {
        v35 = *(unsigned __int8 *)(a4 + 5356);
        v36 = v35 | (*(unsigned __int8 *)(a3 + 389) << 8);
        *(_WORD *)(a3 + 388) = v36;
        v37 = v36 & 0xF0FF;
        v38 = *(_WORD *)(a4 + 5356) & 0xF00;
        if ( v38 > 0xA00 )
          LOWORD(v38) = 0;
        *(_WORD *)(a3 + 388) = v38 | v37;
        v19 = *(_WORD *)(a4 + 5356) & 0xF000 | v35 | v38;
      }
      else
      {
        v19 = 171;
      }
      *(_WORD *)(a3 + 388) = v19;
      v31 = (_WORD *)(a3 + 388);
      v16[624] = v18;
      v32 = *(unsigned __int8 *)(a3 + 388);
      v33 = v32 | ((unsigned __int8)v16[629] << 8);
      v34 = v16 + 628;
      *((_WORD *)v16 + 314) = v33;
    }
    v39 = *v31 & 0xF00;
    *v34 = v33 & 0xF0FF | v39;
    *v34 = v32 | *v31 & 0xF000 | v39;
    wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 7u, v8, v9, v10, v11, v12, v13, v14, v15);
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: MSD caps: %d, Duration: %d, Threshold:%d, TXOP num: %d",
             v40,
             v41,
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             "lim_extract_msd_caps",
             *(unsigned __int8 *)(a3 + 398),
             (unsigned __int8)*(_WORD *)(a3 + 388),
             HIBYTE(*(unsigned __int16 *)(a3 + 388)) & 0xF,
             *(unsigned __int16 *)(a3 + 388) >> 12);
  }
  else
  {
    v21 = (__int64)peer_by_mac;
    qdf_trace_msg(0x35u, 2u, "%s: mlo peer ctx is null", v8, v9, v10, v11, v12, v13, v14, v15, "lim_extract_msd_caps");
    return wlan_objmgr_peer_release_ref(v21, 7u, v22, v23, v24, v25, v26, v27, v28, v29);
  }
}
