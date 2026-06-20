__int64 __fastcall populate_dot11f_ht_info(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _BYTE *v14; // x23
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w8
  unsigned int v24; // w8
  unsigned int v25; // w8
  unsigned int v26; // w8
  unsigned int v27; // w8
  unsigned int v28; // w8
  unsigned int v29; // w8
  unsigned int v30; // w8
  unsigned int cfg_str; // w20
  __int16 v32; // w9
  __int16 v33; // w9
  __int16 v34; // w9
  __int16 v35; // w9
  __int16 v36; // w9
  __int16 v37; // w9
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  size_t v47[2]; // [xsp+0h] [xbp-10h] BYREF

  v47[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v14 = (_BYTE *)(a3 + 4096);
    *(_BYTE *)(a2 + 1) = wlan_reg_freq_to_chan(
                           *(_QWORD *)(a1 + 21632),
                           *(_DWORD *)(a3 + 284),
                           a4,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           a10,
                           a11);
    v23 = *(_DWORD *)(a2 + 2) & 0xFFFFFFFC | *(_DWORD *)(a3 + 164) & 3;
    *(_DWORD *)(a2 + 2) = v23;
    v24 = v23 & 0xFFFFFFFB | (4 * (*(_BYTE *)(a3 + 161) & 1));
    *(_DWORD *)(a2 + 2) = v24;
    v25 = v24 & 0xFFFFFFF7 | (8 * (v14[3070] & 1));
    *(_DWORD *)(a2 + 2) = v25;
    v26 = v25 & 0xFFFFFFEF | (16 * ((*(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1293LL) >> 4) & 1));
    *(_DWORD *)(a2 + 2) = v26;
    v27 = v26 & 0xFFFFFF1F | (32 * (*(_BYTE *)(a1 + 12227) & 7));
    *(_DWORD *)(a2 + 2) = v27;
    if ( *(_DWORD *)(a3 + 88) == 1 )
    {
      v28 = v27 & 0xFFFFFCFF | ((*(_DWORD *)(a3 + 280) & 3) << 8);
      *(_DWORD *)(a2 + 2) = v28;
      v29 = v28 & 0xFFFFFBFF | ((v14[3069] & 1) << 10);
      *(_DWORD *)(a2 + 2) = v29;
      v30 = v29 & 0xF8FFEFFF | ((v14[3072] & 1) << 12);
    }
    else
    {
      v30 = v27 & 0xF8FFE8FF;
    }
    *(_DWORD *)(a2 + 2) = v30;
    v32 = *(_WORD *)(a2 + 6) & 0xFF80 | *(_BYTE *)(a1 + 12240) & 0x7F;
    *(_WORD *)(a2 + 6) = v32;
    v33 = v32 & 0xFF7F | ((*(_BYTE *)(a1 + 12239) & 1) << 7);
    *(_WORD *)(a2 + 6) = v33;
    v34 = v33 & 0xFEFF | ((*(_BYTE *)(a1 + 12238) & 1) << 8);
    *(_WORD *)(a2 + 6) = v34;
    v35 = v34 & 0xFDFF | ((v14[3071] & 1) << 9);
    *(_WORD *)(a2 + 6) = v35;
    v36 = v35 & 0xFBFF | ((*(_BYTE *)(a1 + 12236) & 1) << 10);
    *(_WORD *)(a2 + 6) = v36;
    v37 = v36 & 0x7FF | ((*(_BYTE *)(a1 + 12237) & 1) << 11);
    v47[0] = 16;
    *(_WORD *)(a2 + 6) = v37;
    cfg_str = wlan_mlme_get_cfg_str(
                (void *)(a2 + 8),
                *(_QWORD *)(a1 + 8) + 3096LL,
                v47,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22);
    if ( cfg_str )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to retrieve nItem from CFG status: %d",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "populate_dot11f_ht_info",
        cfg_str);
    else
      *(_BYTE *)a2 = 1;
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: Invalid session entry", a4, a5, a6, a7, a8, a9, a10, a11, "populate_dot11f_ht_info");
    cfg_str = 16;
  }
  _ReadStatusReg(SP_EL0);
  return cfg_str;
}
