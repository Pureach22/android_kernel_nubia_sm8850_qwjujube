_QWORD *__fastcall epping_stop_adapter(
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
  _QWORD *result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x22
  int v21; // w23
  unsigned __int64 v22; // x24
  __int64 v23; // x25
  unsigned __int64 v30; // x8
  __int64 v31; // x0
  _QWORD *v32; // [xsp+8h] [xbp-8h]

  result = _cds_get_context(64, (__int64)"epping_stop_adapter", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !result )
    return (_QWORD *)qdf_trace_msg(
                       0x33u,
                       1u,
                       "%s: qdf_ctx is NULL\n",
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       "epping_stop_adapter");
  if ( *(_BYTE *)(a1 + 133) == 1 )
  {
    v32 = result;
    qdf_trace_msg(0x33u, 4u, "%s: Disabling queues", v11, v12, v13, v14, v15, v16, v17, v18, "epping_stop_adapter");
    StatusReg = _ReadStatusReg(SP_EL0);
    v20 = *(_QWORD *)(a1 + 16);
    *(_DWORD *)(StatusReg + 16) += 512;
    v21 = *(_DWORD *)(StatusReg + 40);
    raw_spin_lock(v20 + 1116);
    if ( *(_DWORD *)(v20 + 1096) )
    {
      v22 = 0;
      v23 = 336;
      do
      {
        _X21 = (unsigned __int64 *)(*(_QWORD *)(v20 + 24) + v23);
        raw_spin_lock(_X21 - 2);
        *((_DWORD *)_X21 - 3) = v21;
        *(_X21 - 1) = jiffies;
        __dmb(0xBu);
        __asm { PRFM            #0x11, [X21] }
        do
          v30 = __ldxr(_X21);
        while ( __stxr(v30 | 1, _X21) );
        *((_DWORD *)_X21 - 3) = -1;
        raw_spin_unlock(_X21 - 2);
        ++v22;
        v23 += 384;
      }
      while ( v22 < *(unsigned int *)(v20 + 1096) );
    }
    v31 = raw_spin_unlock(v20 + 1116);
    local_bh_enable_1(v31);
    netif_carrier_off(*(_QWORD *)(a1 + 16));
    *(_BYTE *)(a1 + 133) = 0;
    return (_QWORD *)pld_request_bus_bandwidth(v32[5], 2u);
  }
  return result;
}
