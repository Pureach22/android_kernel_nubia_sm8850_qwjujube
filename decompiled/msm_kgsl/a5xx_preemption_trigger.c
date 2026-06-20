__int64 __fastcall a5xx_preemption_trigger(__int64 result)
{
  _QWORD *v1; // x19
  unsigned int *v2; // x23
  unsigned int v3; // w24
  __int64 v4; // x20
  __int64 v5; // x21
  int rptr; // w0
  int v7; // w25
  int v8; // w22
  __int64 v9; // x21
  __int64 v10; // x21
  __int64 v11; // x20
  int v12; // w0
  __int64 v13; // x1
  __int64 v14; // x22
  unsigned int v21; // w8
  unsigned int v22; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF

  v1 = (_QWORD *)result;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (unsigned int *)(result + 19632);
  v23[0] = 0;
  v22 = 0;
  _X10 = (unsigned int *)(result + 20488);
  __asm { PRFM            #0x11, [X10] }
  while ( 1 )
  {
    v21 = __ldxr(_X10);
    if ( v21 )
      break;
    if ( !__stlxr(1u, _X10) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( !v21 )
  {
    if ( *v2 )
    {
      v3 = 0;
      v4 = result + 14352;
      while ( 1 )
      {
        v5 = raw_spin_lock_irqsave(v4 + 1292);
        rptr = adreno_get_rptr(v4);
        v7 = *(_DWORD *)(v4 + 20);
        v8 = rptr;
        result = raw_spin_unlock_irqrestore(v4 + 1292, v5);
        if ( v8 != v7 )
          break;
        ++v3;
        v4 += 1320;
        if ( v3 >= *v2 )
          goto LABEL_15;
      }
      if ( v4 )
      {
        v9 = v1[2455];
        if ( v4 != v9 )
        {
          timer_delete(v1 + 2477);
          v10 = raw_spin_lock_irqsave(v4 + 1292);
          kgsl_sharedmem_readq(v1[6], v23, (32LL * *(int *)(v4 + 28)) | 0x10);
          kgsl_sharedmem_readl(v1[6], &v22, (32LL * *(int *)(v4 + 28)) | 0x18);
          kgsl_sharedmem_writel(*(_QWORD *)(v4 + 184), 20, *(unsigned int *)(v4 + 20));
          raw_spin_unlock_irqrestore(v4 + 1292, v10);
          if ( (v1[13] & 0x40) != 0 )
          {
            kgsl_sharedmem_writeq(v1[125], 8, v23[0]);
            kgsl_sharedmem_writel(v1[125], 20, v22);
          }
          kgsl_regmap_write(v1 + 1650, *(unsigned int *)(*(_QWORD *)(v4 + 184) + 24LL));
          kgsl_regmap_write(v1 + 1650, *(unsigned int *)(*(_QWORD *)(v4 + 184) + 28LL));
          v1[2456] = v4;
          mod_timer(v1 + 2563);
          __dmb(0xAu);
          v2[214] = 2;
          __dmb(0xAu);
          result = kgsl_regmap_write(v1 + 1650, 1);
          goto LABEL_16;
        }
        v11 = raw_spin_lock_irqsave(v9 + 1292);
        v12 = kgsl_regmap_read(v1 + 1650);
        v13 = *(unsigned int *)(v9 + 20);
        if ( v12 != (_DWORD)v13 )
        {
          kgsl_regmap_write(v1 + 1650, v13);
          v14 = jiffies;
          *(_QWORD *)(v9 + 1248) = _msecs_to_jiffies((unsigned int)adreno_drawobj_timeout) + v14;
        }
        raw_spin_unlock_irqrestore(v9 + 1292, v11);
        result = mod_timer(v1 + 2477);
      }
    }
LABEL_15:
    __dmb(0xAu);
    v2[214] = 0;
    __dmb(0xAu);
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
