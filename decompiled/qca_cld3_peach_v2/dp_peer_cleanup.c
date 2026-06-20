void *__fastcall dp_peer_cleanup(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x8
  int v13; // w9
  unsigned int v14; // w21
  _QWORD *v15; // x22
  __int64 v16; // x8
  __int64 v17; // x8
  void (__fastcall *v18)(__int64, __int64); // x8
  const char *v19; // x2
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x0
  void *result; // x0
  _DWORD *v30; // x8
  __int64 v31; // x0
  __int64 v32; // x1
  __int64 v33; // [xsp+0h] [xbp-10h] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 24);
  v13 = *(_DWORD *)(a2 + 408);
  v14 = *(_DWORD *)(a1 + 32);
  WORD2(v33) = 0;
  v15 = *(_QWORD **)(v12 + 8);
  LODWORD(v33) = 0;
  if ( v13 == 2 )
    goto LABEL_11;
  v16 = v15[2514];
  if ( !v16 )
  {
    v19 = "%s: monitor soc is NULL";
    goto LABEL_10;
  }
  v17 = *(_QWORD *)(v16 + 416);
  if ( !v17 || (v18 = *(void (__fastcall **)(__int64, __int64))(v17 + 296)) == nullptr )
  {
    v19 = "%s: callback not registered";
LABEL_10:
    qdf_trace_msg(0x92u, 8u, v19, a3, a4, a5, a6, a7, a8, a9, a10, "dp_monitor_peer_tx_cleanup", v33, v34);
    goto LABEL_11;
  }
  if ( *((_DWORD *)v18 - 1) != -1867512383 )
    __break(0x8228u);
  v18(a1, a2);
LABEL_11:
  if ( v14 != 4 )
    dp_peer_rx_cleanup(a1, a2);
  dp_peer_rx_tids_destroy(a2);
  if ( *(_DWORD *)(a2 + 408) == 1 )
  {
    v28 = *(_QWORD *)(a2 + 416);
    if ( v28 )
    {
      dp_peer_unref_delete(v28, 7u, v20, v21, v22, v23, v24, v25, v26, v27);
      *(_QWORD *)(a2 + 416) = 0;
    }
  }
  result = qdf_mem_copy(&v33, (const void *)(a1 + 96), 6u);
  v30 = *(_DWORD **)(v15[1] + 32LL);
  if ( v30 )
  {
    v31 = v15[2];
    v32 = **(unsigned __int8 **)(a1 + 24);
    if ( *(v30 - 1) != 147071213 )
      __break(0x8228u);
    result = (void *)((__int64 (__fastcall *)(__int64, __int64, __int64, __int64 *, _QWORD))v30)(
                       v31,
                       v32,
                       a2 + 44,
                       &v33,
                       v14);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
