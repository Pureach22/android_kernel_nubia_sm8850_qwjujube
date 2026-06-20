__int64 __fastcall sde_cp_ltm_register_irq(_QWORD *a1, __int64 a2, __int64 a3, __int64 *a4, unsigned int a5)
{
  __int64 (__fastcall *v5)(); // x9
  __int64 v6; // x8
  unsigned int v10; // w19
  unsigned int v11; // w0
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x6
  int v16; // w7
  unsigned int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v5 = sde_cp_ltm_wb_pb_interrupt_cb;
  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a5 == 35 )
    v5 = (__int64 (__fastcall *)())&sde_cp_ltm_hist_interrupt_cb;
  v19 = v6;
  a4[2] = (__int64)v5;
  v10 = sde_core_irq_idx_lookup((__int64)a1, a5, *(unsigned int *)(a3 + 64));
  v18 = v10;
  if ( (v10 & 0x80000000) != 0 )
  {
    _drm_err("failed to get the irq idx %d\n", v10);
  }
  else
  {
    a4[3] = a2;
    v11 = sde_core_irq_register_callback((__int64)a1, v10, a4);
    if ( v11 )
    {
      v10 = v11;
      _drm_err("failed to register the callback ret %d\n", v11);
    }
    else
    {
      v10 = sde_core_irq_enable(a1, (__int64)&v18, 1u, v12, v13, v14, v15, v16);
      if ( v10 )
      {
        _drm_err("enable irq %d error %d\n", v18, v10);
        sde_core_irq_unregister_callback(a1, v18, a4);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v10;
}
