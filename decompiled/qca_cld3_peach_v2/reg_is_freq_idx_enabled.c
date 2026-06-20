__int64 __fastcall reg_is_freq_idx_enabled(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  char v22; // w8
  __int64 v23; // x0
  __int64 superchan_entry; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v34; // x8
  _QWORD v35[2]; // [xsp+0h] [xbp-10h] BYREF

  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  pdev_obj = reg_get_pdev_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !pdev_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev private obj is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "reg_is_freq_idx_enabled");
    v22 = 0;
    goto LABEL_11;
  }
  if ( a2 <= 0x29 )
  {
LABEL_3:
    v22 = reg_is_chan_disabled_and_not_nol(pdev_obj + 36LL * a2) ^ 1;
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return v22 & 1;
  }
  if ( !a3 )
  {
    if ( a2 <= 0x65 )
      goto LABEL_3;
LABEL_10:
    v22 = 0;
    goto LABEL_11;
  }
  if ( a2 > 0x65 )
    goto LABEL_10;
  v23 = *(_QWORD *)(pdev_obj + 56728);
  v35[0] = 0;
  superchan_entry = reg_get_superchan_entry(v23, a2, v35, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( (_DWORD)superchan_entry )
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: Failed to get super channel entry for freq_idx %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "reg_is_freq_idx_enabled_on_given_pwr_mode",
      a2);
    v22 = 0;
    goto LABEL_11;
  }
  if ( a3 == -1 )
    a3 = *(_DWORD *)((char *)&off_0 + v35[0] + 4);
  if ( a3 < 0xD )
  {
    v34 = v35[0] + 4LL * (int)a3;
    v22 = (*(_DWORD *)(v34 + 60) & 1) == 0 || *(_DWORD *)(v34 + 216) != 0;
    goto LABEL_11;
  }
  __break(0x5512u);
  return reg_find_chwidth_from_bw(superchan_entry);
}
