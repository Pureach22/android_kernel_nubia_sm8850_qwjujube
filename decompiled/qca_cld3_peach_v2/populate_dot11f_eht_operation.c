__int64 __fastcall populate_dot11f_eht_operation(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 v6; // x22
  int v7; // w8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int updated; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int16 v26; // w8

  v6 = a2 + 4096;
  qdf_mem_copy(a3, (const void *)(a2 + 10164), 0xCu);
  v7 = *(_DWORD *)(a3 + 1);
  *a3 = 1;
  *(_DWORD *)(a3 + 1) = v7 | 1;
  wlan_mlme_get_ap_oper_ch_width(*(_QWORD *)(a2 + 16), v8, v9, v10, v11, v12, v13, v14, v15);
  updated = wlan_dnw_update_bandwidth(*(_QWORD *)(a2 + 16));
  if ( updated == 7 )
  {
    *(_WORD *)(a3 + 5) = *(_WORD *)(a3 + 5) & 0xF8FF | 0x400;
    a3[7] = *(_BYTE *)(v6 + 3078);
    a3[8] = *(_BYTE *)(v6 + 3090);
  }
  else if ( (unsigned int)(updated - 3) >= 2 )
  {
    if ( updated <= 1 )
    {
      if ( updated )
      {
        if ( updated != 1 )
          goto LABEL_4;
        v26 = *(_WORD *)(a3 + 5) & 0xF8FF | 0x100;
      }
      else
      {
        v26 = *(_WORD *)(a3 + 5) & 0xF8FF;
      }
      *(_WORD *)(a3 + 5) = v26;
      *(_WORD *)(a3 + 7) = *(unsigned __int8 *)(v6 + 3078);
      goto LABEL_4;
    }
    if ( updated != 2 )
      goto LABEL_4;
    *(_WORD *)(a3 + 5) = *(_WORD *)(a3 + 5) & 0xF8FF | 0x200;
    *(_WORD *)(a3 + 7) = *(unsigned __int8 *)(v6 + 3078);
  }
  else
  {
    *(_WORD *)(a3 + 5) = *(_WORD *)(a3 + 5) & 0xF8FF | 0x300;
    a3[7] = *(_BYTE *)(v6 + 3078);
    a3[8] = *(_BYTE *)(v6 + 3090);
    if ( updated != 3 )
      goto LABEL_4;
  }
  *(_DWORD *)(a3 + 1) = *(_DWORD *)(a3 + 1) & 0xFFFFFFFD | (2 * (*(_WORD *)(a2 + 7184) != 0));
  *(_WORD *)(a3 + 9) = *(_WORD *)(a2 + 7184);
LABEL_4:
  lim_log_eht_op(v17, v18, v19, v20, v21, v22, v23, v24, a1, a3);
  return 0;
}
