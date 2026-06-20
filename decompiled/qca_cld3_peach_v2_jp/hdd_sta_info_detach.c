__int64 __fastcall hdd_sta_info_detach(
        __int64 result,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 v11; // x19
  unsigned __int64 StatusReg; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8

  if ( !result || !a2 )
    return qdf_trace_msg(0x33u, 2u, "%s: Parameter(s) null", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_sta_info_detach");
  v10 = *a2;
  if ( *a2 )
  {
    v11 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 24);
    }
    else
    {
      raw_spin_lock_bh(result + 24);
      *(_QWORD *)(v11 + 32) |= 1uLL;
    }
    if ( *(_BYTE *)(v10 + 432) == 1 )
    {
      *(_BYTE *)(v10 + 432) = 0;
      hdd_put_sta_info_ref(v11, a2, 0, 28);
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: Stainfo is already detached",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "hdd_sta_info_detach");
    }
    v22 = *(_QWORD *)(v11 + 32);
    if ( (v22 & 1) != 0 )
    {
      *(_QWORD *)(v11 + 32) = v22 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v11 + 24);
    }
    else
    {
      return raw_spin_unlock(v11 + 24);
    }
  }
  return result;
}
