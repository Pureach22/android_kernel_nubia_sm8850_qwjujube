__int64 __fastcall target_if_spectral_scan_timeout_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int *v9; // x8
  __int64 v10; // x21
  const char *v11; // x2
  unsigned int *v12; // x22
  unsigned __int64 StatusReg; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  int v23; // w8
  unsigned __int64 *v24; // x8
  __int64 v25; // x9
  int v26; // w8
  int v27; // w9
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _DWORD v37[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v38; // [xsp+18h] [xbp-8h]

  v9 = (unsigned int *)(a1 - 8);
  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37[0] = 0;
  if ( a1 == 8 )
  {
    v11 = "%s: spectral_timer pointer is null.";
    goto LABEL_14;
  }
  v10 = *v9;
  if ( (unsigned int)v10 < 2 )
  {
    v12 = &v9[-24 * v10];
    if ( v12 != dword_828 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v12 - 436);
      }
      else
      {
        raw_spin_lock_bh(v12 - 436);
        *((_QWORD *)v12 - 217) |= 1uLL;
      }
      v22 = (__int64)&v12[4 * v10 - 155];
      v23 = *(unsigned __int8 *)(v22 + 12);
      *(_BYTE *)v22 = 0;
      if ( v23 == 1 )
      {
        v24 = (unsigned __int64 *)(v12 - 434);
        v25 = *((_QWORD *)v12 - 217);
        if ( (v25 & 1) != 0 )
        {
LABEL_12:
          *v24 = v25 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v12 - 436);
          goto LABEL_19;
        }
      }
      else
      {
        v27 = *(_DWORD *)(v22 + 4);
        v26 = *(_DWORD *)(v22 + 8);
        LOBYTE(v37[0]) = 54;
        v37[1] = 1;
        v37[2] = v26 - v27;
        if ( (unsigned int)target_if_spectral_scan_complete_event(
                             (__int64 *)v12 - 261,
                             (__int64)v37,
                             v14,
                             v15,
                             v16,
                             v17,
                             v18,
                             v19,
                             v20,
                             v21) )
          qdf_trace_msg(
            0x56u,
            2u,
            "%s: Failed spectral scan completion event",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "target_if_spectral_scan_timeout_handler");
        v24 = (unsigned __int64 *)(v12 - 434);
        *(_BYTE *)(v22 + 12) = 1;
        v25 = *((_QWORD *)v12 - 217);
        if ( (v25 & 1) != 0 )
          goto LABEL_12;
      }
      raw_spin_unlock(v12 - 436);
      goto LABEL_19;
    }
    v11 = "%s: spectral pointer is null.";
LABEL_14:
    qdf_trace_msg(0x56u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_spectral_scan_timeout_handler");
    goto LABEL_19;
  }
  qdf_trace_msg(
    0x56u,
    2u,
    "%s: Invalid Spectral mode %u",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "target_if_spectral_scan_timeout_handler",
    (unsigned int)v10);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return 0;
}
