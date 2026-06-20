__int64 __fastcall target_if_update_chan_info_in_spectral_session(
        __int64 *a1,
        _DWORD *a2,
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
  __int64 v12; // x21
  unsigned __int64 StatusReg; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x9
  __int64 *v26; // x20
  int v27; // w8
  __int64 v28; // x9
  char v29; // w10
  __int64 v30; // x9
  __int64 v31; // x21
  __int64 v32; // x21
  __int64 v33; // x20

  if ( a3 >= 2 )
  {
    v12 = jiffies;
    if ( target_if_update_chan_info_in_spectral_session___last_ticks_197 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Invalid Spectral scan mode :%u",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "target_if_update_chan_info_in_spectral_session",
        a3);
      target_if_update_chan_info_in_spectral_session___last_ticks_197 = v12;
    }
    return 16;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 245);
  }
  else
  {
    raw_spin_lock_bh(a1 + 245);
    a1[246] |= 1uLL;
  }
  v25 = *a1;
  v26 = &a1[4 * a3];
  *((_DWORD *)v26 + 474) = *a2;
  *((_DWORD *)v26 + 475) = a2[1];
  *((_DWORD *)v26 + 476) = a2[2];
  *((_DWORD *)v26 + 477) = a2[3];
  *((_DWORD *)v26 + 478) = a2[5];
  *((_DWORD *)v26 + 479) = a2[6];
  v27 = a2[7];
  *((_DWORD *)v26 + 480) = v27;
  if ( v25 )
  {
    v28 = *(_QWORD *)(v25 + 80);
    if ( v28 )
    {
      v29 = 1;
      if ( v27 == 4 )
      {
        if ( (*(_BYTE *)(v28 + 22) & 0x10) != 0 )
          v29 = 3;
        else
          v29 = 2;
      }
      v30 = a1[246];
      *((_BYTE *)v26 + 1924) = v29;
      *((_BYTE *)v26 + 1925) = 1;
      if ( (v30 & 1) != 0 )
      {
        a1[246] = v30 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 245);
      }
      else
      {
        raw_spin_unlock(a1 + 245);
      }
      return 0;
    }
    v32 = jiffies;
    if ( target_if_spectral_get_num_spans___last_ticks_201 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: psoc is null",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "target_if_spectral_get_num_spans");
      target_if_spectral_get_num_spans___last_ticks_201 = v32;
    }
  }
  else
  {
    v31 = jiffies;
    if ( target_if_spectral_get_num_spans___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: pdev is null",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "target_if_spectral_get_num_spans");
      target_if_spectral_get_num_spans___last_ticks = v31;
    }
  }
  *((_BYTE *)v26 + 1924) = -1;
  v33 = jiffies;
  if ( target_if_update_chan_info_in_spectral_session___last_ticks_199 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid number of spans: %u",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "target_if_update_chan_info_in_spectral_session",
      0xFFFFFFFFLL);
    target_if_update_chan_info_in_spectral_session___last_ticks_199 = v33;
  }
  return 4;
}
