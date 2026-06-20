__int64 __fastcall hdd_get_tsf_time(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x8
  unsigned __int64 v14; // x22
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x10
  __int64 v18; // x10
  unsigned __int64 v19; // x9
  bool v20; // cf
  unsigned __int64 v21; // x9
  unsigned __int64 v22; // x9
  __int64 v23; // x9

  if ( !a1 || !a2 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid param passed", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_get_tsf_time");
    return 16;
  }
  if ( *(_DWORD *)a1 != 1885692259 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Magic cookie(%x) for adapter sanity verification is invalid",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hdd_get_tsf_time");
    return 16;
  }
  v13 = *(_QWORD *)(a1 + 24);
  if ( 10 * a2 < a2 )
    v14 = 10 * (a2 / 0xC0);
  else
    v14 = 10 * a2 / 0xC0;
  if ( v13 )
  {
    if ( *(int *)(v13 + 3236) < 1 )
    {
      LODWORD(v13) = 0;
    }
    else
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 39160);
      }
      else
      {
        raw_spin_lock_bh(a1 + 39160);
        *(_QWORD *)(a1 + 39168) |= 1uLL;
      }
      LODWORD(v13) = 1;
    }
  }
  v16 = *(_QWORD *)(a1 + 38952) / 0x3E8uLL;
  v17 = v16 - v14;
  if ( v16 >= v14 )
  {
    if ( a3 )
    {
      v22 = *(_QWORD *)(a1 + 39368);
      v20 = v22 >= v17;
      v21 = v22 - v17;
      if ( !v20 )
        v21 = 0;
      goto LABEL_23;
    }
  }
  else if ( a3 )
  {
    v18 = *(_QWORD *)(a1 + 39368);
    v19 = v14 - v16;
    v20 = __CFADD__(v19, v18);
    v21 = v18 + v19;
    if ( v20 )
      v21 = 0;
LABEL_23:
    *a3 = v21;
  }
  if ( (_DWORD)v13 )
  {
    v23 = *(_QWORD *)(a1 + 39168);
    if ( (v23 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 39168) = v23 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 39160);
    }
    else
    {
      raw_spin_unlock(a1 + 39160);
    }
  }
  return 0;
}
