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
  unsigned int v13; // w20
  _QWORD *v14; // x22
  __int64 v15; // x8
  __int64 v16; // x8
  void (__fastcall *v17)(__int64, __int64); // x8
  const char *v18; // x2
  void *result; // x0
  _DWORD *v20; // x8
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // [xsp+0h] [xbp-10h] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 24);
  v13 = *(_DWORD *)(a1 + 32);
  WORD2(v23) = 0;
  LODWORD(v23) = 0;
  v14 = *(_QWORD **)(v12 + 8);
  v15 = v14[2507];
  if ( !v15 )
  {
    v18 = "%s: monitor soc is NULL";
LABEL_10:
    qdf_trace_msg(0x92u, 8u, v18, a3, a4, a5, a6, a7, a8, a9, a10, "dp_monitor_peer_tx_cleanup", v23, v24);
    if ( v13 == 4 )
      goto LABEL_12;
    goto LABEL_11;
  }
  v16 = *(_QWORD *)(v15 + 416);
  if ( !v16 || (v17 = *(void (__fastcall **)(__int64, __int64))(v16 + 296)) == nullptr )
  {
    v18 = "%s: callback not registered";
    goto LABEL_10;
  }
  if ( *((_DWORD *)v17 - 1) != -1867512383 )
    __break(0x8228u);
  v17(a1, a2);
  if ( v13 != 4 )
LABEL_11:
    dp_peer_rx_cleanup(a1, a2);
LABEL_12:
  dp_peer_rx_tids_destroy(a2);
  result = qdf_mem_copy(&v23, (const void *)(a1 + 96), 6u);
  v20 = *(_DWORD **)(v14[1] + 32LL);
  if ( v20 )
  {
    v21 = v14[2];
    v22 = **(unsigned __int8 **)(a1 + 24);
    if ( *(v20 - 1) != 147071213 )
      __break(0x8228u);
    result = (void *)((__int64 (__fastcall *)(__int64, __int64, __int64, __int64 *, _QWORD))v20)(
                       v21,
                       v22,
                       a2 + 44,
                       &v23,
                       v13);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
