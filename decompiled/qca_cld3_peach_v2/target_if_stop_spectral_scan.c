__int64 __fastcall target_if_stop_spectral_scan(
        __int64 a1,
        unsigned int a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 (*v13)(void); // x8
  const char *v18; // x2
  __int64 v19; // x9
  __int64 v20; // x9
  __int64 (__fastcall *v21)(_QWORD); // x9
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x19
  unsigned __int64 StatusReg; // x8
  _DWORD *v33; // x8
  __int64 (__fastcall *v34)(_QWORD); // x8
  unsigned int v35; // w0
  __int64 v36; // x8
  unsigned int v37; // w20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  const char *v46; // x2
  unsigned __int64 v47; // x8
  _BYTE *v48; // x8
  __int64 v49; // x8
  unsigned __int64 v50; // x8
  __int64 v51; // x8
  __int64 v52; // x8

  if ( !a1 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: pdev object is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_stop_spectral_scan");
    return 4;
  }
  v11 = *(_QWORD *)(a1 + 80);
  if ( !v11 )
  {
    v18 = "%s: psoc is NULL";
LABEL_14:
    qdf_trace_msg(0x56u, 2u, v18, a4, a5, a6, a7, a8, a9, a10, a11, "target_if_spectral_is_feature_disabled_pdev");
LABEL_15:
    qdf_trace_msg(
      0x56u,
      4u,
      "%s: Spectral feature is disabled",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_stop_spectral_scan");
    return 39;
  }
  v12 = *(_QWORD *)(v11 + 2136);
  if ( !v12 )
  {
    v18 = "%s: rx_ops is null";
    goto LABEL_14;
  }
  v13 = *(__int64 (**)(void))(v12 + 304);
  if ( !v13 )
    goto LABEL_15;
  if ( *((_DWORD *)v13 - 1) != -1102235987 )
    __break(0x8228u);
  if ( (v13() & 1) != 0 )
    goto LABEL_15;
  if ( !a3 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Error code argument is null",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_stop_spectral_scan");
    return 29;
  }
  *a3 = 0;
  if ( a2 >= 2 )
  {
    *a3 = 2;
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid Spectral mode %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_stop_spectral_scan",
      a2);
    return 16;
  }
  v19 = *(_QWORD *)(a1 + 80);
  if ( !v19 )
  {
    v46 = "%s: psoc is null";
LABEL_39:
    qdf_trace_msg(0x56u, 2u, v46, a4, a5, a6, a7, a8, a9, a10, a11, "get_target_if_spectral_handle_from_pdev", a2);
LABEL_40:
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Spectral LMAC object is NUll ",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "target_if_stop_spectral_scan");
    return 16;
  }
  v20 = *(_QWORD *)(v19 + 2136);
  if ( !v20 )
  {
    v46 = "%s: rx_ops is null";
    goto LABEL_39;
  }
  v21 = *(__int64 (__fastcall **)(_QWORD))(v20 + 256);
  if ( *((_DWORD *)v21 - 1) != 1565325861 )
    __break(0x8229u);
  v22 = v21(a1);
  if ( !v22 )
    goto LABEL_40;
  v31 = v22;
  hrtimer_cancel(v22 + 96LL * a2 + 2096);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v31 + 344);
  }
  else
  {
    raw_spin_lock_bh(v31 + 344);
    *(_QWORD *)(v31 + 352) |= 1uLL;
  }
  v33 = *(_DWORD **)(v31 + 64);
  if ( *(v33 - 1) != 362784388 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v33)(v31, a2);
  if ( *(_DWORD *)(v31 + 580) )
  {
    *(_DWORD *)(v31 + 580) = 0;
    *(_QWORD *)(v31 + 840) = 0;
    *(_QWORD *)(v31 + 848) = 0;
  }
  v34 = *(__int64 (__fastcall **)(_QWORD))(v31 + 1312);
  *(_DWORD *)(v31 + 572) = 0;
  *(_DWORD *)(v31 + 860) = 0;
  if ( *((_DWORD *)v34 - 1) != -2099273483 )
    __break(0x8228u);
  v35 = v34(a1);
  if ( !v35 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v47 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v47 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v47 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v31 + 1880);
    }
    else
    {
      raw_spin_lock_bh(v31 + 1880);
      *(_QWORD *)(v31 + 1888) |= 1uLL;
    }
    v48 = (_BYTE *)(v31 + a2);
    v48[1685] = 0;
    v48[1781] = 0;
    v48[1877] = 0;
    v49 = *(_QWORD *)(v31 + 1888);
    if ( (v49 & 1) != 0 )
    {
      *(_QWORD *)(v31 + 1888) = v49 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v31 + 1880);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_49;
    }
    else
    {
      raw_spin_unlock(v31 + 1880);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_49;
    }
    v50 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v50 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v50 + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(v31 + 1960);
      v51 = *(_QWORD *)(v31 + 1968) | 1LL;
      *(_QWORD *)(v31 + 1968) = v51;
LABEL_50:
      *(_BYTE *)(v31 + 32LL * a2 + 1925) = 0;
      if ( (v51 & 1) != 0 )
      {
        *(_QWORD *)(v31 + 1968) = v51 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v31 + 1960);
        v52 = *(_QWORD *)(v31 + 352);
        if ( (v52 & 1) == 0 )
          goto LABEL_52;
      }
      else
      {
        raw_spin_unlock(v31 + 1960);
        v52 = *(_QWORD *)(v31 + 352);
        if ( (v52 & 1) == 0 )
        {
LABEL_52:
          raw_spin_unlock(v31 + 344);
          return 0;
        }
      }
      *(_QWORD *)(v31 + 352) = v52 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v31 + 344);
      return 0;
    }
LABEL_49:
    raw_spin_lock(v31 + 1960);
    v51 = *(_QWORD *)(v31 + 1968);
    goto LABEL_50;
  }
  v36 = *(_QWORD *)(v31 + 352);
  v37 = v35;
  if ( (v36 & 1) != 0 )
  {
    *(_QWORD *)(v31 + 352) = v36 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v31 + 344);
  }
  else
  {
    raw_spin_unlock(v31 + 344);
  }
  qdf_trace_msg(
    0x56u,
    2u,
    "%s: Failed to reset transport specific buffer.",
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    "target_if_stop_spectral_scan");
  return v37;
}
