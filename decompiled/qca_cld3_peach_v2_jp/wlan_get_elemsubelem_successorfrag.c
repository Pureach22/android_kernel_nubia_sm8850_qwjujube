__int64 __fastcall wlan_get_elemsubelem_successorfrag(
        char a1,
        unsigned __int8 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        unsigned __int8 **a6,
        _QWORD *a7,
        _QWORD *a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  unsigned __int64 v17; // x12
  __int64 v18; // x20
  const char *v20; // x2
  __int64 v21; // x8
  unsigned __int8 *v22; // x10
  __int64 v23; // x20
  __int64 v24; // x20
  __int64 v25; // x13
  __int64 v26; // x20
  __int64 v27; // x20
  __int64 v28; // x20

  if ( (a1 & 1) == 0 )
    a2 = -14;
  if ( !a6 )
  {
    v20 = "Double ptr to successor frag is NULL";
LABEL_13:
    qdf_trace_msg(0x38u, 2u, v20, a9, a10, a11, a12, a13, a14, a15, a16);
    return 29;
  }
  if ( !a7 )
  {
    v20 = "Ptr to successor frag total len is NULL";
    goto LABEL_13;
  }
  if ( !a8 )
  {
    v20 = "Ptr to successor frag payload len is NULL";
    goto LABEL_13;
  }
  v17 = a4 + a5;
  if ( a4 + a5 < (unsigned __int64)(a3 + 2) )
  {
    v18 = jiffies;
    if ( wlan_get_elemsubelem_successorfrag___last_ticks_30 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "(Space %zu after curr elem unit offset %zu in elem unit buff) < (header size of elem unit %zu)",
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        a16,
        a5 - (a3 - a4),
        a3 - a4,
        2);
      wlan_get_elemsubelem_successorfrag___last_ticks_30 = v18;
      return 27;
    }
    return 27;
  }
  v21 = *(unsigned __int8 *)(a3 + 1);
  v22 = (unsigned __int8 *)(a3 + v21 + 2);
  if ( v17 < (unsigned __int64)v22 )
  {
    v23 = jiffies;
    if ( wlan_get_elemsubelem_successorfrag___last_ticks_31 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "(Space %zu after curr elem unit offset %zu in elem unit buff) < (indicated total len of elem unit %zu)",
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        a16,
        a5 - (a3 - a4),
        a3 - a4,
        v21 + 2);
      wlan_get_elemsubelem_successorfrag___last_ticks_31 = v23;
      return 27;
    }
    return 27;
  }
  if ( (unsigned __int8 *)v17 == v22 )
    goto LABEL_29;
  if ( v17 < (unsigned __int64)(v22 + 2) )
  {
    v24 = jiffies;
    if ( wlan_get_elemsubelem_successorfrag___last_ticks_32 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "(Space %zu after next elem unit offset %zu in elem unit buff) < (header size of elem unit %zu)",
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        a16,
        a5 - (_QWORD)&v22[-a4],
        &v22[-a4],
        2);
      wlan_get_elemsubelem_successorfrag___last_ticks_32 = v24;
      return 27;
    }
    return 27;
  }
  v25 = v22[1];
  if ( v17 < (unsigned __int64)&v22[v25 + 2] )
  {
    v26 = jiffies;
    if ( wlan_get_elemsubelem_successorfrag___last_ticks_34 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "(Space %zu after next elem unit offset %zu in elem unit buff) < (indicated total len of elem unit %zu)",
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        a16,
        a5 - (_QWORD)&v22[-a4],
        &v22[-a4],
        v25 + 2);
      wlan_get_elemsubelem_successorfrag___last_ticks_34 = v26;
      return 27;
    }
    return 27;
  }
  if ( *v22 != a2 )
  {
LABEL_29:
    *a6 = nullptr;
    return 0;
  }
  else if ( (_DWORD)v21 == 255 )
  {
    if ( v22[1] )
    {
      *a6 = v22;
      *a7 = v25 + 2;
      *a8 = v22[1];
      return 0;
    }
    else
    {
      v28 = jiffies;
      if ( wlan_get_elemsubelem_successorfrag___last_ticks_38 - jiffies + 125 >= 0 )
        return 27;
      qdf_trace_msg(0x38u, 2u, "Potential successor frag len is 0", a9, a10, a11, a12, a13, a14, a15, a16);
      wlan_get_elemsubelem_successorfrag___last_ticks_38 = v28;
      return 27;
    }
  }
  else
  {
    v27 = jiffies;
    if ( wlan_get_elemsubelem_successorfrag___last_ticks_36 - jiffies + 125 >= 0 )
      return 27;
    qdf_trace_msg(
      0x38u,
      2u,
      "Potential successor frag found though (len %u of payload of curr elem unit) != (max payload len %zu)",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      *(unsigned __int8 *)(a3 + 1),
      255);
    wlan_get_elemsubelem_successorfrag___last_ticks_36 = v27;
    return 27;
  }
}
