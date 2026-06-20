_QWORD *__fastcall wlan_serialization_find_cmd(
        __int64 a1,
        int a2,
        _DWORD *a3,
        int a4,
        __int64 a5,
        __int64 a6,
        int a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  int v15; // w28
  __int64 v17; // x25
  _QWORD *result; // x0
  _QWORD *v24; // x8
  const char *v25; // x2
  _QWORD *v26; // [xsp+0h] [xbp-10h] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(_DWORD *)(a1 + 16);
  v26 = nullptr;
  if ( !v15 )
    goto LABEL_31;
  if ( a7 )
    v17 = 0x1FFFFFFFFFFFFFFELL;
  else
    v17 = 0;
  if ( !a1 )
  {
    v25 = "%s: input parameters are invalid";
    goto LABEL_30;
  }
  while ( v26 )
  {
    if ( (unsigned int)qdf_list_peek_next((_QWORD *)a1, v26, &v26) )
      goto LABEL_29;
LABEL_15:
    if ( a2 > 1 )
    {
      if ( a2 == 2 )
      {
        result = v26;
        v24 = &v26[v17];
        if ( LODWORD(v26[v17 + 4]) == a4 )
          goto LABEL_8;
      }
      else if ( a2 == 3 )
      {
        if ( a3 )
        {
          result = v26;
          v24 = &v26[v17];
          if ( HIDWORD(v26[v17 + 4]) == a3[1] && *((_DWORD *)v24 + 8) == *a3 )
            goto LABEL_8;
        }
      }
    }
    else
    {
      if ( !a2 )
      {
        result = v26;
        v24 = &v26[v17];
LABEL_8:
        if ( v24[8] == a6 )
          goto LABEL_32;
        qdf_trace_msg(
          0x4Cu,
          8u,
          "%s: matching cmd not found for (vdev:%pK)",
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          a15,
          "wlan_serialization_match_cmd_vdev",
          a6);
        goto LABEL_10;
      }
      if ( a2 == 1 )
      {
        result = v26;
        if ( *(_QWORD *)(v26[8] + 216LL) == a5 )
          goto LABEL_32;
      }
    }
LABEL_10:
    if ( !--v15 )
      goto LABEL_31;
  }
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)a1, &v26) )
    goto LABEL_15;
LABEL_29:
  v25 = "%s: can't get next node from queue";
LABEL_30:
  qdf_trace_msg(0x4Cu, 2u, v25, a8, a9, a10, a11, a12, a13, a14, a15, "wlan_serialization_get_cmd_from_queue", v26, v27);
LABEL_31:
  result = nullptr;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
