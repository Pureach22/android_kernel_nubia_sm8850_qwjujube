__int64 __fastcall lim_update_eht_caps_mcs(
        __int64 a1,
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
  __int64 v10; // x20
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x8
  __int64 v22; // x5
  __int64 v23; // x4
  __int64 v24; // x9
  unsigned __int64 *v25; // x14
  unsigned __int64 v26; // x15
  __int64 v27; // x12
  unsigned __int64 *v28; // x13
  unsigned __int64 v29; // x17
  unsigned __int64 v30; // x15
  __int64 v31; // x14
  unsigned __int64 v32; // x14
  __int64 v33; // x17
  unsigned __int64 v34; // x14
  unsigned __int64 v35; // x15
  char v36; // w8

  v10 = *(_QWORD *)(a1 + 8);
  result = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a2 + 16), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v21 = (_DWORD *)(v10 + 1509);
    if ( *(_BYTE *)(a2 + 8635) == 1 )
    {
      v22 = 1;
      v23 = 1;
    }
    else
    {
      v22 = *v21 >> 28;
      v23 = *(_DWORD *)(v10 + 1513) & 0xF;
    }
    if ( (unsigned int)(v23 - 3) < 0xFFFFFFFE || (unsigned int)(v22 - 3) <= 0xFFFFFFFD )
    {
      return qdf_trace_msg(
               0x35u,
               2u,
               "%s: invalid Nss values tx_nss: %u rx_nss: %u",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "lim_update_eht_caps_mcs");
    }
    else
    {
      v24 = result + 20480;
      v25 = (unsigned __int64 *)(result + 24457);
      v26 = *(_QWORD *)(result + 24457) & 0xFFFFF0000FFFFFFFLL
          | ((unsigned __int8)(v22 & 0xF) << 28)
          | ((unsigned __int64)(v23 & 0xF) << 32) & 0xFFFFF00FFFFFFFFFLL
          | ((unsigned __int64)(v22 & 0xF) << 36) & 0xFFFFF0FFFFFFFFFFLL
          | ((unsigned __int64)(v23 & 0xF) << 40);
      *(_QWORD *)(result + 24457) = v26;
      v27 = *(_QWORD *)v21;
      if ( (*(_QWORD *)v21 & 0xF00000000000LL) != 0 )
      {
        v26 = v26 & 0xFFF00FFFFFFFFFFFLL
            | ((unsigned __int64)(unsigned int)v22 << 44)
            | ((unsigned __int64)(unsigned int)v23 << 48);
        *v25 = v26;
        v27 = *(_QWORD *)v21;
      }
      if ( (v27 & 0xF0000000000000LL) != 0 )
        v26 = v26 & 0xF00FFFFFFFFFFFFFLL
            | ((unsigned __int64)(unsigned int)v22 << 52)
            | ((unsigned __int64)(unsigned int)v23 << 56);
      v28 = (unsigned __int64 *)(result + 24465);
      v29 = ((unsigned __int64)(unsigned int)v22 << 60) | v26 & 0xFFFFFFFFFFFFFFFLL;
      v30 = *(_QWORD *)(result + 24465) & 0xFFFFFFFFFFFFFFF0LL | (unsigned int)v23;
      *v25 = v29;
      *(_QWORD *)(result + 24465) = v30;
      v31 = *(_QWORD *)(v10 + 1517);
      if ( (v31 & 0xF0) != 0 )
      {
        v30 = v30 & 0xFFFFFFFFFFFFF003LL | (16LL * (unsigned int)v22) | ((unsigned __int64)(unsigned int)v23 << 8);
        *v28 = v30;
        v31 = *(_QWORD *)(v10 + 1517);
      }
      if ( (v31 & 0xF000) != 0 )
        v30 = v30 & 0xFFFFFFFFFFF00FFFLL
            | ((unsigned __int64)(unsigned int)v22 << 12)
            | ((unsigned __int64)(unsigned int)v23 << 16);
      v32 = v30 & 0xFFFFFFFFF00FFFFFLL
          | ((unsigned __int64)(unsigned int)v22 << 20)
          | ((unsigned __int64)(unsigned int)v23 << 24);
      *v28 = v32;
      v33 = *(_QWORD *)(v10 + 1517);
      if ( (v33 & 0xF0000000) != 0 )
      {
        v32 = ((unsigned __int64)(unsigned int)v22 << 28)
            | (v23 << 32)
            | v30 & 0xFFFFFFF0000FFFFFLL
            | ((unsigned __int64)(unsigned int)v22 << 20) & 0xFFFFFFF0033FFFFFLL
            | ((unsigned __int64)(unsigned int)v23 << 24) & 0xFFFFFFF0033FFFFFLL;
        *v28 = v32;
        v33 = *(_QWORD *)(v10 + 1517);
      }
      result = v32 & 0xFFF0000FFFFFFFFFLL;
      if ( (v33 & 0xF000000000LL) != 0 )
        v32 = (v22 << 36) | (v23 << 40) | v32 & 0xFFF0000FFFFFFFFFLL;
      v34 = v32 & 0xFFF00FFFFFFFFFFFLL
          | ((unsigned __int64)(unsigned int)v22 << 44)
          | ((unsigned __int64)(unsigned int)v23 << 48);
      *v28 = v34;
      v35 = *(_QWORD *)(v10 + 1517);
      if ( (v35 & 0xF0000000000000LL) != 0 )
      {
        v34 = v34 & 0xF0033FFFFFFFFFFFLL
            | ((unsigned __int64)(unsigned int)v22 << 52)
            | ((unsigned __int64)(unsigned int)v23 << 56);
        *v28 = v34;
        v35 = *(_QWORD *)(v10 + 1517);
      }
      if ( v35 >> 60 )
      {
        v36 = *(_BYTE *)(v24 + 3993) & 0xF0;
        *v28 = v34 & 0xFFFFFFFFFFFFFFFLL | ((unsigned __int64)(unsigned int)v22 << 60);
        *(_BYTE *)(v24 + 3993) = v36 | v23;
      }
    }
  }
  return result;
}
