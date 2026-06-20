__int64 __fastcall a5xx_cp_callback(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x1
  unsigned __int64 v10; // x9
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_QWORD *)(result + 14240) & 0x2000) == 0 )
  {
    v1 = result;
    v2 = *(_QWORD *)(result + 40);
    v11 = 0;
    kgsl_sharedmem_readl(v2, &v11, 24);
    if ( a5xx_cp_callback_prev == v11 )
    {
      if ( ++a5xx_cp_callback_count == 2 )
      {
        _X8 = (unsigned __int64 *)(v1 + 14240);
        __asm { PRFM            #0x11, [X8] }
        do
          v10 = __ldxr(_X8);
        while ( __stxr(v10 | 0x2000, _X8) );
        v3 = *(_DWORD *)(v1 + 20888) & 0xFFEFFFFF;
        *(_DWORD *)(v1 + 20888) = v3;
        kgsl_regmap_write(v1 + 13200, v3);
        result = queue_work_on(32, qword_3A900, v1 + 20768);
        goto LABEL_7;
      }
    }
    else
    {
      a5xx_cp_callback_prev = v11;
      a5xx_cp_callback_count = 0;
    }
    a5xx_preemption_trigger(v1);
    result = kthread_queue_work(*(_QWORD *)(v1 + 24400), v1 + 24408);
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
