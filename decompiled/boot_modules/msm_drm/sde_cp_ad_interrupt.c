__int64 __fastcall sde_cp_ad_interrupt(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 *v3; // x20
  int v5; // w8
  _QWORD *v6; // x19
  char v7; // w23
  int v8; // w24
  unsigned int v9; // w21
  __int64 *v11; // x8
  __int64 v12; // x8
  unsigned int v13; // w0
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  int v18; // w7
  __int64 v19; // x20
  int v20; // w0
  _QWORD *v21; // x8
  __int64 v22; // x1
  _QWORD *v23; // x20
  __int64 v24; // x0
  __int64 v25; // x3
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  int v29; // w7
  int v30; // w9
  __int64 v31; // x20
  __int64 v32; // x8
  _QWORD v33[13]; // [xsp+8h] [xbp-78h] BYREF
  unsigned int v34; // [xsp+74h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+78h] [xbp-8h]

  v3 = (__int64 *)a1;
  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    _drm_err("invalid crtc %pK irq %pK\n", (const void *)a1, (const void *)a3);
LABEL_28:
    v9 = -22;
LABEL_32:
    _ReadStatusReg(SP_EL0);
    return v9;
  }
  v5 = *(_DWORD *)(a1 + 2192);
  v6 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)a1 + 56LL) + 8LL);
  if ( v5 )
  {
    if ( (unsigned int)(v5 - 9) < 0xFFFFFFF8 )
      goto LABEL_69;
    v7 = a2;
    v8 = *(_QWORD *)(a1 + 2216) != 0;
    if ( v5 != 1 )
    {
      if ( *(_QWORD *)(a1 + 2264) )
        ++v8;
      if ( v5 != 2 )
      {
        if ( *(_QWORD *)(a1 + 2312) )
          ++v8;
        if ( v5 != 3 )
        {
          if ( *(_QWORD *)(a1 + 2360) )
            ++v8;
          if ( v5 != 4 )
          {
            if ( *(_QWORD *)(a1 + 2408) )
              ++v8;
            if ( v5 != 5 )
            {
              if ( *(_QWORD *)(a1 + 2456) )
                ++v8;
              if ( v5 != 6 )
              {
                if ( *(_QWORD *)(a1 + 2504) )
                  ++v8;
                if ( v5 != 7 && *(_QWORD *)(a1 + 2552) )
                  ++v8;
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v7 = a2;
    v8 = 0;
  }
  memset(&v33[2], 0, 88);
  v33[0] = 0;
  v33[1] = 20;
  a1 = sde_cp_ad_validate_prop(v33, a1);
  if ( (_DWORD)a1 )
  {
    v9 = a1;
    _drm_err("Ad not supported ret %d\n", (unsigned int)a1);
    goto LABEL_32;
  }
  if ( !v8 )
    goto LABEL_55;
  v11 = v3 + 277;
  if ( *(_BYTE *)(v3[275] + 384) != 1
    || v8 == 1
    || (v11 = v3 + 283, *(_BYTE *)(v3[281] + 384) != 1)
    || v8 == 2
    || (v11 = v3 + 289, *(_BYTE *)(v3[287] + 384) != 1)
    || v8 == 3
    || (v11 = v3 + 295, *(_BYTE *)(v3[293] + 384) != 1)
    || v8 == 4
    || (v11 = v3 + 301, *(_BYTE *)(v3[299] + 384) != 1)
    || v8 == 5
    || (v11 = v3 + 307, *(_BYTE *)(v3[305] + 384) != 1)
    || v8 == 6
    || (v11 = v3 + 313, *(_BYTE *)(v3[311] + 384) != 1)
    || v8 == 7
    || (v11 = v3 + 319, *(_BYTE *)(v3[317] + 384) != 1)
    || v8 == 8 )
  {
    v12 = *v11;
    if ( v12 )
    {
      v9 = sde_core_irq_idx_lookup((__int64)v6, 26, *(unsigned int *)(v12 + 64));
      v34 = v9;
      if ( (v9 & 0x80000000) != 0 )
      {
        _drm_err("failed to get the irq idx ret %d\n", v9);
      }
      else if ( (v7 & 1) != 0 )
      {
        *(_QWORD *)(a3 + 16) = sde_cp_ad_interrupt_cb;
        *(_QWORD *)(a3 + 24) = v3;
        v13 = sde_core_irq_register_callback((__int64)v6, v9, (__int64 *)a3);
        if ( v13 )
        {
          v9 = v13;
          _drm_err("failed to register the callback ret %d\n", v13);
        }
        else
        {
          v24 = raw_spin_lock_irqsave(a3 + 68);
          v30 = *(_DWORD *)(a3 + 64);
          v31 = v24;
          if ( v30 != 3 && v30 )
          {
            v32 = a3;
            v9 = 0;
          }
          else
          {
            v9 = sde_core_irq_enable(v6, (__int64)&v34, 1u, v25, v26, v27, v28, v29);
            if ( v9 )
            {
              _drm_err("enable irq %d error %d\n", v34, v9);
              sde_core_irq_unregister_callback(v6, v34, (_QWORD *)a3);
              v32 = a3;
            }
            else
            {
              v32 = a3;
              *(_DWORD *)(a3 + 64) = 1;
            }
          }
          raw_spin_unlock_irqrestore(v32 + 68, v31);
        }
      }
      else
      {
        v19 = raw_spin_lock_irqsave(a3 + 68);
        if ( *(_DWORD *)(a3 + 64) == 1
          && (v20 = sde_core_irq_disable((__int64)v6, (__int64)&v34, 1u, v14, v15, v16, v17, v18)) != 0 )
        {
          _drm_err("disable irq %d error %d\n", v34, v20);
          v21 = (_QWORD *)a3;
        }
        else
        {
          v21 = (_QWORD *)a3;
          *(_DWORD *)(a3 + 64) = 0;
        }
        v22 = v19;
        v23 = v21;
        raw_spin_unlock_irqrestore((char *)v21 + 68, v22);
        sde_core_irq_unregister_callback(v6, v34, v23);
        v9 = 0;
      }
      goto LABEL_32;
    }
LABEL_55:
    _drm_err("invalid dspp\n");
    goto LABEL_28;
  }
LABEL_69:
  __break(0x5512u);
  return sde_cp_ad_validate_prop(a1, a2);
}
