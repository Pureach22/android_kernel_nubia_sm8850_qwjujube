__int64 __fastcall wlan_get_elemsubelem_fragseq_info(
        char a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        _BYTE *a13,
        _QWORD *a14,
        _QWORD *a15)
{
  __int64 v15; // x20
  __int64 result; // x0
  const char *v17; // x2
  __int64 v18; // x19
  __int64 v19; // x21

  _ReadStatusReg(SP_EL0);
  if ( !a11 )
  {
    v17 = "Elem unit buff is NULL";
LABEL_14:
    qdf_trace_msg(0x38u, 2u, v17, a2, a3, a4, a5, a6, a7, a8, a9, 0, 0);
    result = 29;
    goto LABEL_15;
  }
  if ( !a12 )
  {
    qdf_trace_msg(0x38u, 2u, "Max size of elem unit buff is 0", a2, a3, a4, a5, a6, a7, a8, a9);
    result = 4;
    goto LABEL_15;
  }
  if ( !a13 )
  {
    v17 = "Ptr to status of frag seq presence is NULL";
    goto LABEL_14;
  }
  if ( !a14 )
  {
    v17 = "Ptr to total len of frag seq is NULL";
    goto LABEL_14;
  }
  if ( !a15 )
  {
    v17 = "Ptr to payload len of frag seq is NULL";
    goto LABEL_14;
  }
  if ( a11 + a12 < (unsigned __int64)(a11 + 2) )
  {
    v15 = jiffies;
    if ( wlan_get_elemsubelem_fragseq_info___last_ticks_22 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "(Space %zu after curr elem unit offset %zu in elem unit buff) < (header size of elem unit %zu)",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a12,
        0,
        2);
      wlan_get_elemsubelem_fragseq_info___last_ticks_22 = v15;
      result = 27;
      goto LABEL_15;
    }
LABEL_18:
    result = 27;
    goto LABEL_15;
  }
  v18 = *(unsigned __int8 *)(a11 + 1) + 2LL;
  if ( a11 + a12 < (unsigned __int64)(a11 + v18) )
  {
    v19 = jiffies;
    if ( wlan_get_elemsubelem_fragseq_info___last_ticks_24 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "(Space %zu after curr elem unit offset %zu in elem unit buff) < (indicated total len of elem unit %zu)",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a12,
        0,
        v18);
      wlan_get_elemsubelem_fragseq_info___last_ticks_24 = v19;
      result = 27;
      goto LABEL_15;
    }
    goto LABEL_18;
  }
  result = wlan_get_elemsubelem_successorfrag(a1 & 1);
  if ( !(_DWORD)result )
  {
    result = 0;
    *a13 = 0;
    *a14 = 0;
    *a15 = 0;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
