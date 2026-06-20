__int64 __fastcall populate_dot11f_bw_ind_element(__int64 a1, __int64 a2, __int64 a3)
{
  char v5; // w23
  int v6; // w21
  char v7; // w22
  unsigned int v8; // w0
  __int64 v9; // x20
  __int16 v10; // w8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( a2 && *(_WORD *)(a2 + 7216) )
  {
    v5 = 0;
    v6 = HIBYTE(*(unsigned __int16 *)(a2 + 7216));
    v7 = *(_WORD *)(a2 + 7216);
  }
  else
  {
    if ( (unsigned __int16)wlan_reg_get_bw_value(*(_DWORD *)(a2 + 7212)) <= 0xA0u )
    {
      *(_BYTE *)a3 = 0;
      return 0;
    }
    v7 = 0;
    LOBYTE(v6) = 0;
    v5 = 1;
  }
  *(_BYTE *)a3 = 1;
  v8 = *(_DWORD *)(a2 + 7212);
  v9 = a2 + 4096;
  v10 = *(_WORD *)(a3 + 1) & 0xF8FF | ((wlan_mlme_convert_phy_ch_width_to_eht_op_bw(v8) & 7) << 8);
  *(_WORD *)(a3 + 1) = v10;
  if ( (v5 & 1) == 0 )
  {
    *(_BYTE *)(a3 + 5) = v7;
    *(_WORD *)(a3 + 1) = v10 | 2;
    *(_BYTE *)(a3 + 6) = v6;
  }
  *(_BYTE *)(a3 + 3) = *(_BYTE *)(v9 + 3113);
  *(_BYTE *)(a3 + 4) = *(_BYTE *)(v9 + 3114);
  qdf_trace_msg(0x35u, 8u, "bw_ind:", v11, v12, v13, v14, v15, v16, v17, v18);
  ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(53, 8, a3, 7);
  return 0;
}
