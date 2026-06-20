__int64 __fastcall a6xx_counter_inline_enable(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v7; // x20
  __int64 v9; // x22
  _QWORD *v10; // x21
  unsigned int v11; // w23
  unsigned int v12; // w23
  unsigned int v13; // w8
  _QWORD *v14; // x8
  int v15; // w0
  unsigned int v16; // w20
  _DWORD v17[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 11120) != 2 )
  {
    v5 = *(_QWORD *)a2 + 48LL * a3;
    if ( (*(_BYTE *)(a2 + 24) & 2) != 0 )
    {
      result = a6xx_perfcounter_update(a1, (unsigned int *)(*(_QWORD *)a2 + 48LL * a3), 1);
      if ( (_DWORD)result )
        goto LABEL_16;
    }
    else
    {
      kgsl_regmap_write(a1 + 13200, a4);
    }
    result = 0;
    *(_QWORD *)(v5 + 32) = 0;
    goto LABEL_16;
  }
  if ( *(_BYTE *)(a1 + 24024) == 1 )
  {
    result = a6xx_hwsched_counter_inline_enable(a1, (__int64 *)a2, a3, a4);
  }
  else
  {
    v7 = *(_QWORD *)a2 + 48LL * a3;
    v9 = a1 + 14352;
    v10 = (_QWORD *)a1;
    if ( (*(_BYTE *)(a2 + 24) & 2) != 0 )
    {
      v11 = a4;
      a6xx_perfcounter_update(a1, (unsigned int *)(*(_QWORD *)a2 + 48LL * a3), 0);
      a1 = (__int64)v10;
      a4 = v11;
    }
    v12 = a4;
    v17[0] = 1881571328;
    v13 = *(_DWORD *)(v7 + 24);
    v17[1] = (((0x9669u >> (((v13 >> 4)
                           ^ BYTE1(v13)
                           ^ (v13 >> 12)
                           ^ BYTE2(v13)
                           ^ (v13 >> 20)
                           ^ HIBYTE(v13)
                           ^ (v13 >> 28)
                           ^ v13)
                          & 0xF))
             & 1) << 27)
           | ((v13 & 0x3FFFF) << 8)
           | 0x40000001;
    v17[2] = a4;
    result = a6xx_ringbuffer_addcmds(a1, v9, 0, 1, v17, 3, 0, 0);
    if ( !(_DWORD)result )
    {
      v14 = v10;
      if ( v10[2455] != v9 )
      {
        kthread_queue_work(v10[3050], v10 + 3051);
        v14 = v10;
      }
      v15 = adreno_ringbuffer_waittimestamp(v9, *((unsigned int *)v14 + 3597), 20000);
      if ( v15 != -11 && v15 )
      {
        v16 = v15;
        dev_err(*v10, "Perfcounter %s/%u/%u start via commands failed %d\n", *(const char **)(a2 + 16), a3, v12, v15);
        result = v16;
      }
      else
      {
        result = 0;
        *(_QWORD *)(v7 + 32) = 0;
      }
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
