__int64 __fastcall set_dspp_hist_irq_feature(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  _QWORD *v4; // x19
  __int64 v5; // x9
  __int64 v7; // x20
  __int64 *v8; // x24
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x6
  int v13; // w7
  __int64 v14; // x21
  __int64 result; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = 4294967274LL;
LABEL_39:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 32) + 384LL) & 1) != 0 )
  {
LABEL_38:
    result = 0;
    goto LABEL_39;
  }
  v18 = 0;
  if ( !a3 )
  {
    _drm_err("invalid crtc %pK\n", nullptr);
    goto LABEL_38;
  }
  v3 = *(_DWORD *)(a3 + 2192);
  if ( !v3 )
  {
LABEL_31:
    _drm_err("invalid dspp\n");
    goto LABEL_38;
  }
  v4 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)a3 + 56LL) + 8LL);
  v5 = a3 + 2216;
  if ( v3 == 1
    || (*(_BYTE *)(*(_QWORD *)(a3 + 2200) + 384LL) & 1) == 0
    || (v5 = a3 + 2264, v3 == 2)
    || (*(_BYTE *)(*(_QWORD *)(a3 + 2248) + 384LL) & 1) == 0
    || (v5 = a3 + 2312, v3 == 3)
    || (*(_BYTE *)(*(_QWORD *)(a3 + 2296) + 384LL) & 1) == 0
    || (v5 = a3 + 2360, v3 == 4)
    || (*(_BYTE *)(*(_QWORD *)(a3 + 2344) + 384LL) & 1) == 0
    || (v5 = a3 + 2408, v3 == 5)
    || (*(_BYTE *)(*(_QWORD *)(a3 + 2392) + 384LL) & 1) == 0
    || (v5 = a3 + 2456, v3 == 6)
    || (*(_BYTE *)(*(_QWORD *)(a3 + 2440) + 384LL) & 1) == 0
    || (v5 = a3 + 2504, v3 == 7)
    || (*(_BYTE *)(*(_QWORD *)(a3 + 2488) + 384LL) & 1) == 0
    || (v5 = a3 + 2552, v3 == 8)
    || (*(_BYTE *)(*(_QWORD *)(a3 + 2536) + 384LL) & 1) == 0 )
  {
    if ( *(_QWORD *)v5 )
    {
      v18 = sde_core_irq_idx_lookup((__int64)v4, 13, *(unsigned int *)(*(_QWORD *)v5 + 64LL));
      if ( v18 < 0 )
      {
        _drm_err("failed to get irq idx\n");
      }
      else
      {
        v7 = raw_spin_lock_irqsave(a3 + 6032);
        v8 = (__int64 *)(a3 + 4600);
        do
        {
          v8 = (__int64 *)*v8;
          if ( v8 == (__int64 *)(a3 + 4600) )
            goto LABEL_33;
        }
        while ( *((_DWORD *)v8 - 4) != 0x80000000 );
        if ( v8 == &_ksymtab_dss_reg_dump )
        {
LABEL_33:
          v16 = a3 + 6032;
          goto LABEL_37;
        }
        v14 = raw_spin_lock_irqsave((char *)v8 + 20);
        if ( *((_DWORD *)v8 + 4) == 3 )
        {
          if ( (unsigned int)sde_core_irq_enable(v4, (__int64)&v18, 1u, v9, v10, v11, v12, v13) )
            _drm_err("failed to enable irq %d\n", v18);
          else
            *((_DWORD *)v8 + 4) = 1;
        }
        raw_spin_unlock_irqrestore((char *)v8 + 20, v14);
        v16 = a3 + 6032;
LABEL_37:
        raw_spin_unlock_irqrestore(v16, v7);
      }
      goto LABEL_38;
    }
    goto LABEL_31;
  }
  __break(0x5512u);
  v17 = MEMORY[0x25250A4]();
  return set_dspp_ad_mode_feature(v17);
}
