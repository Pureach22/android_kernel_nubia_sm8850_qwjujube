__int64 __fastcall tdls_free_peer_list(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x22
  __int64 v10; // x23
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // [xsp+0h] [xbp-10h] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  if ( a1 )
  {
    v9 = 0;
    v10 = a1 + 8;
    do
    {
      while ( 1 )
      {
        result = qdf_list_remove_front((_DWORD *)(v10 + 24 * v9), &v20);
        if ( (_DWORD)result )
          break;
        _qdf_mem_free(v20);
      }
      if ( *(_DWORD *)(v10 + 24 * v9 + 16) )
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: list length not equal to zero",
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   "qdf_list_destroy");
      ++v9;
    }
    while ( v9 != 16 );
  }
  else
  {
    result = qdf_trace_msg(
               0,
               2u,
               "%s: NULL tdls vdev object",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "tdls_free_peer_list",
               v20,
               v21);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
