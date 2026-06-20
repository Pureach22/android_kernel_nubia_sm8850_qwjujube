__int64 __fastcall dp_rx_buffers_is_skip_replenish(__int64 a1, __int64 a2, _QWORD *a3, __int64 **a4, _DWORD *a5)
{
  unsigned __int64 v5; // x20
  __int64 v6; // x22
  __int64 v7; // x24
  __int64 v12; // x0
  __int64 v13; // x1
  unsigned __int16 free_desc_list; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v30; // w9

  v5 = (unsigned int)*a5;
  v6 = *(int *)(a2 + 108);
  if ( (_DWORD)v6 )
  {
    v7 = *(int *)(a2 + 112);
    if ( (unsigned int)v7 > (unsigned int)v6 )
    {
      if ( !*a3 )
        return 1;
      v12 = dp_rx_add_desc_list_to_free_list(a1, a3, a4, (__int64)a4, a2);
      _X8 = (unsigned int *)(a2 + 112);
      __asm { PRFM            #0x11, [X8] }
      do
        v30 = __ldxr(_X8);
      while ( __stxr(v30 - v5, _X8) );
      if ( v7 - v6 >= v5 )
        return 1;
      *a4 = nullptr;
      *a3 = 0;
      free_desc_list = dp_rx_get_free_desc_list(
                         v12,
                         v13,
                         a2,
                         (unsigned __int16)v5 - ((unsigned __int16)v7 - (unsigned __int16)v6),
                         a3,
                         a4);
      *a5 = free_desc_list;
      if ( !free_desc_list )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Rx descriptors not available",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "dp_rx_buffers_is_skip_replenish");
        return 1;
      }
    }
  }
  return 0;
}
