__int64 __fastcall populate_dot11f_he_caps(__int64 a1, __int64 a2, int a3, unsigned int a4, unsigned int a5, _BYTE *a6)
{
  char v11; // w24
  bool v12; // zf
  __int64 v13; // x9
  bool is_24ghz_ch_freq; // w0
  __int64 v15; // x8
  unsigned __int64 v16; // x9
  __int16 v18; // w10
  __int16 v19; // w11
  __int16 v20; // w9
  __int16 v21; // w10
  __int16 v22; // w11

  *a6 = 1;
  if ( a2 )
  {
    v11 = 2 * *(_BYTE *)(a2 + 8635);
    qdf_mem_copy(a6, (const void *)(a2 + 8680), 0x3Cu);
    populate_dot11f_twt_he_cap(a1, a2, a6);
    if ( (*(_DWORD *)(a2 + 7036) | 2) == 2 )
    {
      v12 = (unsigned int)wlan_mlme_get_max_bw() > 2 && a5 == 2;
      if ( v12 )
        a5 = 3;
    }
  }
  else
  {
    qdf_mem_copy(a6, (const void *)(*(_QWORD *)(a1 + 8) + 1308LL), 0x3Cu);
    v11 = 4;
    if ( !a4 )
      goto LABEL_22;
  }
  if ( (a6[14] & 4) != 0 )
  {
    v12 = !wlan_reg_is_24ghz_ch_freq(a4);
    v13 = 1453;
    if ( !v12 )
      v13 = 1428;
    qdf_mem_copy(a6 + 33, (const void *)(*(_QWORD *)(a1 + 8) + v13), 0x19u);
    a6[32] = lim_truncate_ppet(a6 + 33);
  }
  else
  {
    a6[32] = 0;
  }
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(a4);
  v15 = *(_QWORD *)(a6 + 1);
  if ( is_24ghz_ch_freq )
  {
    v16 = 0xFE47FFFFFFFFFFFFLL;
LABEL_21:
    *(_QWORD *)(a6 + 1) = v15 & v16;
    goto LABEL_22;
  }
  *(_QWORD *)(a6 + 1) = v15 & 0xFEBBFFFFFFFFFFFFLL;
  if ( a5 < 3 )
  {
    v16 = 0xFE8BFFFFFFFFFFFFLL;
    goto LABEL_21;
  }
  if ( a5 == 3 )
  {
    v16 = 0xFE9BFFFFFFFFFFFFLL;
    goto LABEL_21;
  }
LABEL_22:
  v18 = *((_WORD *)a6 + 11) | (-1LL << v11);
  v19 = *((_WORD *)a6 + 12) | (-1LL << v11);
  *((_WORD *)a6 + 10) |= -1LL << v11;
  v20 = *((_WORD *)a6 + 13);
  *((_WORD *)a6 + 11) = v18;
  v21 = *((_WORD *)a6 + 14);
  *((_WORD *)a6 + 12) = v19;
  v22 = *((_WORD *)a6 + 15);
  *((_WORD *)a6 + 13) = v20 | (-1LL << v11);
  *((_WORD *)a6 + 14) = v21 | (-1LL << v11);
  *((_WORD *)a6 + 15) = v22 | (-1LL << v11);
  return 0;
}
