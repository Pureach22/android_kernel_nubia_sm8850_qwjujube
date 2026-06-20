__int64 __fastcall populate_dot11f_he_operation(__int64 a1, __int64 a2, _BYTE *a3)
{
  _BYTE *v6; // x22
  int updated; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w8
  unsigned int v17; // w8
  char v18; // w8
  char v19; // w9
  int v20; // w23
  char v21; // w0
  char v22; // w8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  char v31; // w8
  unsigned int v33; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v6 = (_BYTE *)(a2 + 7174);
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  qdf_mem_copy(a3, (const void *)(a2 + 8740), 0x12u);
  updated = wlan_dnw_update_bandwidth(*(_QWORD *)(a2 + 16));
  v16 = *(_DWORD *)(a3 + 1);
  *a3 = 1;
  v17 = v16 & 0xFFFBFFFF;
  *(_DWORD *)(a3 + 1) = v17;
  if ( (v6[1590] & 1) == 0 )
  {
    v20 = updated;
    if ( !policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a2 + 10))
      || !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 284)) )
    {
      goto LABEL_13;
    }
    v17 = *(_DWORD *)(a3 + 1);
    updated = v20;
  }
  *(_DWORD *)(a3 + 1) = v17 | 0x200000;
  if ( *(_DWORD *)(a2 + 92) != 1 )
  {
    v18 = a3[13];
    a3[13] = v18 & 0xFC | updated & 3;
    a3[14] = *v6;
    if ( (unsigned int)(updated - 3) > 1 )
    {
      a3[15] = 0;
    }
    else
    {
      v19 = v6[10];
      a3[13] = v18 | 3;
      a3[15] = v19;
    }
  }
  v21 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21560), *(_DWORD *)(a2 + 284), v8, v9, v10, v11, v12, v13, v14, v15);
  v22 = a3[13];
  a3[12] = v21;
  a3[16] = 0;
  a3[13] = v22 & 0xFB;
  wlan_reg_get_cur_6g_ap_pwr_type(*(_QWORD *)(a1 + 21560), &v33, v23, v24, v25, v26, v27, v28, v29, v30);
  if ( v33 == 3 )
    v31 = 16;
  else
    v31 = 8 * (v33 & 0xF);
  a3[13] = v31 | a3[13] & 0x87;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return 0;
}
