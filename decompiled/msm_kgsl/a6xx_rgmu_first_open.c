__int64 __fastcall a6xx_rgmu_first_open(unsigned __int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x20
  int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x8
  _QWORD *v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  unsigned __int64 profile_buffer; // x0
  unsigned int v12; // w19
  unsigned int v15; // w9
  unsigned __int64 v22; // x9
  unsigned __int64 v25; // x9
  _QWORD v26[2]; // [xsp+0h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_QWORD *)(a1 - 16) & 1) != 0 )
  {
    result = a6xx_boot_0((_QWORD *)a1);
    if ( (_DWORD)result )
      goto LABEL_14;
    goto LABEL_17;
  }
  result = ((__int64 (__fastcall *)(unsigned __int64))a6xx_ringbuffer_init)(a1);
  if ( !(_DWORD)result )
  {
    result = a6xx_microcode_read((_QWORD *)a1);
    if ( !(_DWORD)result )
    {
      result = a6xx_init(a1);
      if ( !(_DWORD)result )
      {
        v3 = *(_QWORD *)(a1 - 72);
        v26[0] = 0;
        if ( !v3 )
        {
          v4 = *(_QWORD *)(a1 + 14264);
          v5 = request_firmware(v26, *(_QWORD *)(v4 + 112), *(_QWORD *)(a1 - 88) + 16LL);
          v6 = *(_QWORD *)(a1 - 88);
          if ( v5 < 0 )
          {
            v12 = v5;
            dev_err(v6 + 16, "request_firmware (%s) failed: %d\n", *(const char **)(v4 + 112), v5);
            result = v12;
            goto LABEL_14;
          }
          v7 = devm_kmemdup(v6 + 16, *(_QWORD *)(v26[0] + 8LL), *(_QWORD *)v26[0], 3264);
          v8 = (_QWORD *)v26[0];
          *(_QWORD *)(a1 - 72) = v7;
          if ( v7 )
            *(_DWORD *)(a1 - 64) = *v8 >> 2;
          release_firmware(v8);
          if ( !*(_QWORD *)(a1 - 72) )
          {
            result = 4294967284LL;
            goto LABEL_14;
          }
        }
        kgsl_pwrctrl_request_state(a1, 2);
        result = a6xx_rgmu_boot(a1);
        if ( !(_DWORD)result )
        {
          result = a6xx_gpu_boot_0(a1);
          if ( !(_DWORD)result )
          {
            adreno_get_bus_counters(a1, v9, v10);
            profile_buffer = adreno_create_profile_buffer(a1);
            _X8 = (unsigned __int64 *)(a1 - 16);
            __asm { PRFM            #0x11, [X8] }
            do
              v22 = __ldxr(_X8);
            while ( __stxr(v22 | 1, _X8) );
            _X8 = (unsigned __int64 *)(a1 - 16);
            __asm { PRFM            #0x11, [X8] }
            do
              v25 = __ldxr(_X8);
            while ( __stxr(v25 | 2, _X8) );
            *(_BYTE *)(a1 + 12960) = 1;
            *(_QWORD *)(a1 + 10904) = ktime_get(profile_buffer);
            kgsl_pwrctrl_set_state(a1, 2);
LABEL_17:
            _X8 = (unsigned int *)(a1 + 11128);
            __asm { PRFM            #0x11, [X8] }
            do
              v15 = __ldxr(_X8);
            while ( __stxr(v15 + 1, _X8) );
            adreno_active_count_put(a1);
            result = 0;
          }
        }
      }
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
