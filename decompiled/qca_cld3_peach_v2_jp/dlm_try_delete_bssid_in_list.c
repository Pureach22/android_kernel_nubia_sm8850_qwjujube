__int64 __fastcall dlm_try_delete_bssid_in_list(_QWORD *a1, int a2, __int64 *a3)
{
  _QWORD *v6; // x1
  unsigned __int64 v7; // x25
  __int64 v8; // x22
  unsigned __int64 delta_of_bssid; // x0
  __int64 v10; // x26
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w8
  unsigned int v20; // w9
  __int64 result; // x0
  _QWORD *v22; // [xsp+8h] [xbp-18h] BYREF
  __int64 v23[2]; // [xsp+10h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = nullptr;
  v23[0] = 0;
  qdf_list_peek_front(a1, v23);
  v6 = (_QWORD *)v23[0];
  if ( !v23[0] )
    goto LABEL_29;
  v7 = 0;
  v8 = 0;
  do
  {
    v10 = v8;
    qdf_list_peek_next(a1, v6, &v22);
    v8 = v23[0];
    v19 = *(unsigned __int8 *)(v23[0] + 104);
    if ( a2 > 2 )
    {
      if ( a2 == 3 )
      {
        v20 = v19 >> 1;
        if ( (v19 & 0x3D) != 0 )
          goto LABEL_3;
      }
      else if ( a2 == 4 )
      {
        v20 = v19 >> 4;
        if ( (v19 & 0x2F) != 0 )
          goto LABEL_3;
      }
      else
      {
        v20 = v19 >> 5;
        if ( (v19 & 0x1F) != 0 )
          goto LABEL_3;
      }
    }
    else if ( a2 )
    {
      if ( a2 == 1 )
      {
        LOBYTE(v20) = *(_BYTE *)(v23[0] + 104);
        if ( (v19 & 0x3E) != 0 )
          goto LABEL_3;
      }
      else
      {
        v20 = v19 >> 3;
        if ( (v19 & 0x37) != 0 )
          goto LABEL_3;
      }
    }
    else
    {
      v20 = v19 >> 2;
      if ( (v19 & 0x3B) != 0 )
        goto LABEL_3;
    }
    if ( (v20 & 1) == 0 )
    {
LABEL_3:
      v8 = v10;
      delta_of_bssid = v7;
      goto LABEL_4;
    }
    delta_of_bssid = dlm_get_delta_of_bssid(a2, v23[0], a3);
    if ( ((1 << a2) & 0x1D) != 0 )
    {
      if ( v7 - 1 < delta_of_bssid )
        goto LABEL_3;
    }
    else if ( delta_of_bssid <= v7 )
    {
      goto LABEL_3;
    }
LABEL_4:
    v6 = v22;
    v7 = delta_of_bssid;
    v22 = nullptr;
    v23[0] = (__int64)v6;
  }
  while ( v6 );
  if ( !v8 )
  {
LABEL_29:
    result = 16;
    goto LABEL_30;
  }
  qdf_trace_msg(
    0x6Du,
    8u,
    "%s: Removed %02x:%02x:%02x:**:**:%02x, type = %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "dlm_try_delete_bssid_in_list",
    *(unsigned __int8 *)(v8 + 16),
    *(unsigned __int8 *)(v8 + 17),
    *(unsigned __int8 *)(v8 + 18),
    *(unsigned __int8 *)(v8 + 21),
    a2);
  qdf_list_remove_node((__int64)a1, (_QWORD *)v8);
  _qdf_mem_free(v8);
  result = 0;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
