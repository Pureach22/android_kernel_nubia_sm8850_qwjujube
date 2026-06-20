__int64 __fastcall wlan_hdd_dealloc_ll_stats(__int64 result)
{
  _DWORD *v1; // x19
  int v2; // w20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  int v12; // w21
  __int64 *v13; // x22
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v1 = (_DWORD *)result;
    v14[0] = 0;
    while ( 1 )
    {
      raw_spin_lock(v1 + 8);
      v2 = qdf_list_remove_front(v1, v14);
      result = raw_spin_unlock(v1 + 8);
      if ( v2 )
        break;
      v11 = v14[0];
      if ( *(_DWORD *)(v14[0] + 16LL) == 1 )
      {
        v12 = *(_DWORD *)(v14[0] + 36LL);
        if ( v12 >= 1 )
        {
          v13 = (__int64 *)(*(_QWORD *)(v14[0] + 24LL) + 72LL);
          do
          {
            if ( *((_DWORD *)v13 - 1) )
              _qdf_mem_free(*v13);
            if ( *((_DWORD *)v13 - 6) )
              _qdf_mem_free(*(v13 - 2));
            --v12;
            v13 += 10;
          }
          while ( v12 );
        }
      }
      _qdf_mem_free(*(_QWORD *)(v11 + 24));
      _qdf_mem_free(v11);
    }
    if ( v1[4] )
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: list length not equal to zero",
                 v3,
                 v4,
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 "qdf_list_destroy");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
