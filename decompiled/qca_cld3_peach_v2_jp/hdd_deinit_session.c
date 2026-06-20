__int64 __fastcall hdd_deinit_session(
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
  __int64 v10; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w8
  int v20; // w8
  unsigned __int64 v28; // x10

  v10 = a1 + 41680;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_deinit_session");
  v19 = *(_DWORD *)(a1 + 40);
  if ( v19 <= 0x10 )
  {
    v20 = 1 << v19;
    if ( (v20 & 0x108C5) != 0 )
    {
      if ( (*(_QWORD *)(a1 + 1624) & 2) != 0 )
      {
        hdd_wmm_adapter_close(a1);
        _X8 = (unsigned __int64 *)(a1 + 1624);
        __asm { PRFM            #0x11, [X8] }
        do
          v28 = __ldxr(_X8);
        while ( __stxr(v28 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      }
    }
    else if ( (v20 & 0xA) != 0 && a1 && (*(_QWORD *)(a1 + 1640) & 1) != 0 && a1 != -52832 )
    {
      do
        hdd_deinit_ap_mode((_DWORD *)(a1 + 52832), v11, v12, v13, v14, v15, v16, v17, v18);
      while ( !(unsigned __int8)~(-910593773 * ((unsigned int)(a1 - *(_DWORD *)(a1 + 52832)) >> 4))
           && (*(_QWORD *)(a1 + 1640) & 1) != 0 );
    }
  }
  if ( *(_QWORD *)v10 )
  {
    _qdf_mem_free(*(_QWORD *)v10);
    *(_QWORD *)v10 = 0;
    *(_WORD *)(v10 + 8) = 0;
  }
  return qdf_trace_msg(0x33u, 8u, "%s: exit", v11, v12, v13, v14, v15, v16, v17, v18, "hdd_deinit_session");
}
