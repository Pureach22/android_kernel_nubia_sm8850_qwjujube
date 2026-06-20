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
  __int64 v21; // x0
  _DWORD *v23; // x20
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v26; // x10
  unsigned __int64 v33; // x10

  v10 = a1 + 40960;
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
          v33 = __ldxr(_X8);
        while ( __stxr(v33 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      }
    }
    else if ( (v20 & 0xA) != 0 && a1 )
    {
      if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 && (v23 = (_DWORD *)(a1 + 52840), a1 != -52840)
        || (*(_QWORD *)(a1 + 1640) & 2) != 0 && (v23 = (_DWORD *)(a1 + 58928), a1 != -58928)
        || (*(_QWORD *)(a1 + 1640) & 4) != 0 && (v23 = (_DWORD *)(a1 + 65016), a1 != -65016) )
      {
        do
        {
          hdd_deinit_ap_mode(v23, v11, v12, v13, v14, v15, v16, v17, v18);
          if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v23 - *v23 - 52840) >> 3) + 1) > 2u )
            break;
          v24 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v23 - *v23 - 52840) >> 3) + 1);
          v23 = nullptr;
          v25 = a1 + 52840 + 6088LL * (unsigned int)v24;
          do
          {
            if ( v23 )
              break;
            v26 = *(_QWORD *)(a1 + 1640) >> v24++;
            v23 = (_DWORD *)((v26 << 63 >> 63) & v25);
            v25 += 6088;
          }
          while ( v24 != 3 );
        }
        while ( v23 );
      }
    }
  }
  v21 = *(_QWORD *)(v10 + 720);
  if ( v21 )
  {
    _qdf_mem_free(v21);
    *(_QWORD *)(v10 + 720) = 0;
    *(_WORD *)(v10 + 728) = 0;
  }
  return qdf_trace_msg(0x33u, 8u, "%s: exit", v11, v12, v13, v14, v15, v16, v17, v18, "hdd_deinit_session");
}
