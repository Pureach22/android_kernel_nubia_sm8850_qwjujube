__int64 __fastcall lim_set_emlsr_caps(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 result; // x0
  char v6; // w0
  char v7; // w21
  char is_aux_emlsr_support; // w19
  __int64 v9; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v11; // x8
  unsigned int v12; // w9
  __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x8
  __int64 v16; // x9
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x22
  __int64 v34; // x22
  _BYTE v35[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 21624);
  v35[0] = 0;
  result = policy_mgr_is_hw_emlsr_capable(v4);
  if ( (result & 1) != 0 )
  {
    wlan_mlme_get_emlsr_mode_enabled(*(_QWORD *)(a1 + 21624), v35);
    v6 = ((__int64 (__fastcall *)(__int64))lim_is_emlsr_band_supported)(a2);
    v7 = v35[0] & v6;
    is_aux_emlsr_support = wlan_mlme_is_aux_emlsr_support(*(_QWORD *)(a1 + 21624));
    if ( (v7 & 1) != 0 || (is_aux_emlsr_support & 1) != 0 && v35[0] == 1 )
    {
      v9 = *(_QWORD *)(a2 + 16);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v9 + 1344);
      }
      else
      {
        v33 = v9;
        raw_spin_lock_bh(v9 + 1344);
        *(_QWORD *)(v33 + 1352) |= 1uLL;
      }
      v11 = *(_QWORD *)(a2 + 16);
      v12 = *(_DWORD *)(v11 + 48) | 0x400;
    }
    else
    {
      v13 = *(_QWORD *)(a2 + 16);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v14 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v14 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v14 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v13 + 1344);
      }
      else
      {
        v34 = v13;
        raw_spin_lock_bh(v13 + 1344);
        *(_QWORD *)(v34 + 1352) |= 1uLL;
      }
      v11 = *(_QWORD *)(a2 + 16);
      v12 = *(_DWORD *)(v11 + 48) & 0xFFFFFBFF;
    }
    *(_DWORD *)(v11 + 48) = v12;
    v15 = *(_QWORD *)(a2 + 16);
    v16 = *(_QWORD *)(v15 + 1352);
    if ( (v16 & 1) != 0 )
    {
      *(_QWORD *)(v15 + 1352) = v16 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v15 + 1344);
    }
    else
    {
      raw_spin_unlock(v15 + 1344);
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: eMLSR vdev cap: %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_set_emlsr_caps",
      v7 & 1);
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: eMLSR aux support: %d, eMLSR enabled: %d",
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               "lim_set_emlsr_caps",
               is_aux_emlsr_support & 1,
               v35[0]);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
