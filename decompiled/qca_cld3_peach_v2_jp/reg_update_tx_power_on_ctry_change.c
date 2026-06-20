__int64 __fastcall reg_update_tx_power_on_ctry_change(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  __int64 v21; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v23; // x8
  void (__fastcall *v24)(_QWORD); // x23

  psoc_obj = reg_get_psoc_obj(*(_QWORD *)(a1 + 80), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( psoc_obj )
  {
    v20 = psoc_obj;
    v21 = psoc_obj + 90112;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(psoc_obj + 93240);
      v23 = *(_QWORD *)(v21 + 3136);
      v24 = *(void (__fastcall **)(_QWORD))(v21 + 1552);
      if ( (v23 & 1) == 0 )
        goto LABEL_6;
    }
    else
    {
      raw_spin_lock_bh(psoc_obj + 93240);
      v23 = *(_QWORD *)(v21 + 3136) | 1LL;
      *(_QWORD *)(v21 + 3136) = v23;
      v24 = *(void (__fastcall **)(_QWORD))(v21 + 1552);
      if ( (v23 & 1) == 0 )
      {
LABEL_6:
        raw_spin_unlock(v20 + 93240);
        if ( v24 )
        {
LABEL_7:
          if ( *((_DWORD *)v24 - 1) != -1560483463 )
            __break(0x8237u);
          v24(a2);
        }
        return 0;
      }
    }
    *(_QWORD *)(v21 + 3136) = v23 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v20 + 93240);
    if ( v24 )
      goto LABEL_7;
    return 0;
  }
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: reg psoc private obj is NULL",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "reg_update_tx_power_on_ctry_change");
  return 16;
}
