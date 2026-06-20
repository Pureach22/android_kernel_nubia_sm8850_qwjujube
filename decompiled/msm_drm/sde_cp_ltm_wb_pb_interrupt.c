__int64 __fastcall sde_cp_ltm_wb_pb_interrupt(_QWORD *a1, char a2, __int64 *a3)
{
  __int64 v4; // x9
  _QWORD *v5; // x19
  __int64 v6; // x2
  __int64 result; // x0
  unsigned int v8; // w19
  unsigned int v9; // w0
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  int v14; // w7
  unsigned int v15; // w0
  unsigned int v16; // w21
  unsigned int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    _drm_err("invalid params: crtc %pK irq %pK\n", a1);
LABEL_10:
    result = 4294967274LL;
    goto LABEL_11;
  }
  v4 = *(_QWORD *)(*a1 + 56LL);
  v5 = *(_QWORD **)(v4 + 8);
  if ( !v5 )
  {
    _drm_err("invalid params: kms %pK sde_crtc %pK\n", 0);
    goto LABEL_10;
  }
  v6 = a1[277];
  if ( v6 )
  {
    if ( (a2 & 1) != 0 )
    {
      result = sde_cp_ltm_register_irq(*(_QWORD **)(v4 + 8), (__int64)a1, v6, a3, 0x24u);
      if ( (_DWORD)result )
      {
        v8 = result;
        _drm_err("failed to register WB_PB irq\n");
        result = v8;
      }
    }
    else
    {
      v9 = sde_core_irq_idx_lookup(*(_QWORD *)(v4 + 8), 36, *(unsigned int *)(v6 + 64));
      v17 = v9;
      if ( (v9 & 0x80000000) != 0 )
      {
        v16 = v9;
        _drm_err("failed to get the irq idx %d\n", v9);
      }
      else
      {
        v15 = sde_core_irq_disable((__int64)v5, (__int64)&v17, 1u, v10, v11, v12, v13, v14);
        if ( !v15 )
        {
          sde_core_irq_unregister_callback(v5, v17, a3);
          result = 0;
          goto LABEL_11;
        }
        v16 = v15;
        _drm_err("disable irq %d error %d\n", v17, v15);
        sde_core_irq_unregister_callback(v5, v17, a3);
      }
      _drm_err("failed to unregister WB_PB irq\n");
      result = v16;
    }
  }
  else
  {
    _drm_err("invalid dspp\n");
    result = 4294967277LL;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
