__int64 __fastcall lim_dump_session_info(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w13
  __int64 v11; // x9
  __int64 v12; // x21
  __int64 v14; // x22
  unsigned int v15; // w19
  unsigned int v16; // w20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char force_20mhz_in_24ghz; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // [xsp+0h] [xbp-80h]

  if ( result )
  {
    if ( a2 )
    {
      v10 = *(_DWORD *)(a2 + 7268);
      v11 = *(_QWORD *)(result + 8);
      v12 = a2 + 7023;
      v14 = result;
      qdf_trace_msg(
        0x35u,
        8u,
        "vdev_id %d freq %d ch_bw %d freq0 %d freq1 %d, smps %d mode %d action %d, nss_1x1 %d vdev_nss %d nss %d, cbMode "
        "%d, dot11Mode %d, subfer %d subfee %d csn %d, is_cisco %d, WPS %d OSEN %d FILS %d AKM %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        *(unsigned __int8 *)(a2 + 10),
        *(unsigned int *)(a2 + 284),
        *(unsigned int *)(a2 + 7176),
        *(unsigned __int8 *)(a2 + 7174),
        *(unsigned __int8 *)(a2 + 7184),
        *(unsigned __int8 *)(v11 + 1280),
        *(unsigned __int8 *)(v11 + 1281),
        *(unsigned __int8 *)(a2 + 7191),
        *(unsigned __int8 *)(a2 + 8653),
        *(unsigned __int8 *)(a2 + 8652),
        *(unsigned __int8 *)(a2 + 8635),
        *(unsigned __int8 *)(a2 + 160),
        *(unsigned __int8 *)(a2 + 154),
        (v10 >> 11) & 1,
        (v10 >> 12) & 1,
        (unsigned __int16)v10 >> 13,
        *(unsigned __int8 *)(a2 + 7286),
        *(unsigned __int8 *)(a2 + 7023),
        *(unsigned __int8 *)(a2 + 7364),
        **(unsigned __int8 **)(a2 + 9976),
        *(_DWORD *)(a2 + 156));
      v15 = *(char *)(v12 + 9);
      v16 = (*(unsigned __int8 *)(v12 + 1) >> 4) & 1;
      force_20mhz_in_24ghz = wlan_cm_get_force_20mhz_in_24ghz(
                               *(_QWORD *)(a2 + 16),
                               v17,
                               v18,
                               v19,
                               v20,
                               v21,
                               v22,
                               v23,
                               v24);
      LODWORD(v34) = *(unsigned __int8 *)(*(_QWORD *)(v14 + 8) + 5436LL);
      return qdf_trace_msg(
               0x35u,
               8u,
               " MaxTxPwr %d RMF %d force_20_24 %d UAPSD flag 0x%2x auth type %d privacy %d",
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               v15,
               v16,
               force_20mhz_in_24ghz & 1,
               *(unsigned __int8 *)(v12 + 250),
               *(unsigned __int8 *)(*(_QWORD *)(v14 + 8) + 5439LL),
               v34);
    }
  }
  return result;
}
