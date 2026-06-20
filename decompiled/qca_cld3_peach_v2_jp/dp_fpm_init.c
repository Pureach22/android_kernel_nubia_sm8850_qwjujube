__int64 __fastcall dp_fpm_init(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  v2 = _qdf_mem_malloc(0x68u, "dp_fpm_init", 261);
  if ( !v2 )
    return 2;
  *(_DWORD *)v2 = 0;
  *(_DWORD *)(v2 + 88) = 0;
  *(_QWORD *)(v2 + 96) = 0;
  *(_QWORD *)(v2 + 8) = 0;
  *(_QWORD *)(v2 + 16) = 0;
  *(_QWORD *)(v2 + 24) = 0;
  *(_QWORD *)(v2 + 32) = 0;
  *(_QWORD *)(v2 + 40) = 0;
  *(_QWORD *)(v2 + 48) = 0;
  *(_QWORD *)(v2 + 56) = 0;
  *(_QWORD *)(v2 + 64) = 0;
  *(_QWORD *)(v2 + 72) = 0;
  *(_QWORD *)(a1 + 3712) = v2;
  qdf_trace_msg(0x45u, 5u, "%s: init success", v3, v4, v5, v6, v7, v8, v9, v10, "dp_fpm_init");
  return 0;
}
