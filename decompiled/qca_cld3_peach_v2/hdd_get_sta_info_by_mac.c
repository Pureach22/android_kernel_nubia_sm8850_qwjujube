__int64 *__fastcall hdd_get_sta_info_by_mac(
        __int64 **a1,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  char v12; // w21
  unsigned __int64 StatusReg; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 *i; // x8
  __int64 *v28; // x21
  __int64 *v29; // x8
  __int64 *v30; // x8
  __int64 *result; // x0
  unsigned int v38; // w10
  unsigned int v40; // w9

  _ReadStatusReg(SP_EL0);
  if ( a1 && a2 && *(_DWORD *)a2 | *((unsigned __int16 *)a2 + 2) )
  {
    v12 = a4;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: match_mac_type %d sta_info_dbgid %d %02x:%02x:%02x:**:**:%02x",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "hdd_get_sta_info_by_mac",
      a4,
      a3,
      *a2,
      a2[1],
      a2[2],
      a2[5]);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 3);
    }
    else
    {
      raw_spin_lock_bh(a1 + 3);
      a1[4] = (__int64 *)((unsigned __int64)a1[4] | 1);
    }
    for ( i = *a1; ; i = (__int64 *)*i )
    {
      if ( i == (__int64 *)a1 )
      {
        v30 = a1[4];
        if ( ((unsigned __int8)v30 & 1) != 0 )
        {
          a1[4] = (__int64 *)((unsigned __int64)v30 & 0xFFFFFFFFFFFFFFFELL);
          raw_spin_unlock_bh(a1 + 3);
        }
        else
        {
          raw_spin_unlock(a1 + 3);
        }
        goto LABEL_29;
      }
      if ( (v12 & 1) != 0
        && *((_DWORD *)i + 8) == *(_DWORD *)a2
        && *((unsigned __int16 *)i + 18) == *((unsigned __int16 *)a2 + 2) )
      {
        break;
      }
      if ( (v12 & 2) != 0
        && *(_DWORD *)((char *)i + 38) == *(_DWORD *)a2
        && *((unsigned __int16 *)i + 21) == *((unsigned __int16 *)a2 + 2) )
      {
        break;
      }
    }
    if ( i )
    {
      if ( a3 >= 0x23 )
      {
        v28 = i;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid sta_info debug id %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "hdd_take_sta_info_ref",
          a3);
        v29 = a1[4];
        if ( ((unsigned __int8)v29 & 1) != 0 )
          goto LABEL_41;
LABEL_34:
        raw_spin_unlock(a1 + 3);
        result = v28;
        goto LABEL_30;
      }
      _X9 = (unsigned int *)(i + 35);
      __asm { PRFM            #0x11, [X9] }
      do
        v38 = __ldxr(_X9);
      while ( __stxr(v38 + 1, _X9) );
      v28 = i;
      _X8 = (unsigned int *)i + a3 + 71;
      __asm { PRFM            #0x11, [X8] }
      do
        v40 = __ldxr(_X8);
      while ( __stxr(v40 + 1, _X8) );
      v29 = a1[4];
      if ( ((unsigned __int8)v29 & 1) == 0 )
        goto LABEL_34;
    }
    else
    {
      v28 = nullptr;
      qdf_trace_msg(0x33u, 2u, "%s: Parameter(s) null", v17, v18, v19, v20, v21, v22, v23, v24, "hdd_take_sta_info_ref");
      v29 = a1[4];
      if ( ((unsigned __int8)v29 & 1) == 0 )
        goto LABEL_34;
    }
LABEL_41:
    a1[4] = (__int64 *)((unsigned __int64)v29 & 0xFFFFFFFFFFFFFFFELL);
    raw_spin_unlock_bh(a1 + 3);
    result = v28;
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Parameter(s) null", a5, a6, a7, a8, a9, a10, a11, a12, "hdd_get_sta_info_by_mac");
LABEL_29:
    result = nullptr;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
