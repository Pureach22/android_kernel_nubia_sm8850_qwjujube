__int64 __fastcall lim_rem_denylist_entry_with_lowest_delta(_QWORD *a1)
{
  _QWORD *v2; // x21
  __int64 v3; // x20
  signed int v4; // w22
  unsigned int v5; // w21
  unsigned int v6; // w22
  unsigned int v7; // w23
  unsigned int v8; // w24
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  int v18; // [xsp+0h] [xbp-20h]
  _QWORD *v19; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = nullptr;
  v20[0] = nullptr;
  qdf_list_peek_front(a1, v20);
  v2 = v20[0];
  if ( v20[0] )
  {
    v3 = 0;
    do
    {
      if ( !v3
        || (v4 = *(_DWORD *)(v3 + 24) + *(_DWORD *)(v3 + 32) - ktime_get_with_offset(1) / 1000 / 0x3E8uLL,
            v4 > (int)(*((_DWORD *)v2 + 6) + *((_DWORD *)v2 + 8) - ktime_get_with_offset(1) / 1000 / 0x3E8uLL)) )
      {
        v3 = (__int64)v2;
      }
      qdf_list_peek_next(a1, v20[0], &v19);
      v2 = v19;
      v19 = nullptr;
      v20[0] = v2;
    }
    while ( v2 );
    v5 = *(unsigned __int8 *)(v3 + 16);
    v6 = *(unsigned __int8 *)(v3 + 17);
    v7 = *(unsigned __int8 *)(v3 + 18);
    v8 = *(unsigned __int8 *)(v3 + 21);
    v18 = *(_DWORD *)(v3 + 24) + *(_DWORD *)(v3 + 32) - ktime_get_with_offset(1) / 1000 / 0x3E8uLL;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: remove node %02x:%02x:%02x:**:**:%02x with lowest delta %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "lim_rem_denylist_entry_with_lowest_delta",
      v5,
      v6,
      v7,
      v8,
      v18);
    qdf_list_remove_node((__int64)a1, (_QWORD *)v3);
    _qdf_mem_free(v3);
    result = 0;
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
