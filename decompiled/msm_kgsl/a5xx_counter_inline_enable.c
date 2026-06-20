__int64 __fastcall a5xx_counter_inline_enable(__int64 *a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 v5; // x23
  unsigned int v9; // w8
  __int64 *v10; // x22
  __int64 result; // x0
  int v12; // w0
  __int64 v13; // x8
  unsigned int v14; // w19
  _DWORD v15[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)a2 + 48LL * a3;
  if ( *((_DWORD *)a1 + 2780) != 2 )
  {
    kgsl_regmap_write(a1 + 1650, a4);
    goto LABEL_9;
  }
  v15[0] = 1881571328;
  v9 = *(_DWORD *)(v5 + 24);
  v10 = a1 + 1794;
  v15[1] = (((0x9669u >> ((BYTE1(v9)
                         ^ (v9 >> 4)
                         ^ (v9 >> 12)
                         ^ BYTE2(v9)
                         ^ (v9 >> 20)
                         ^ HIBYTE(v9)
                         ^ (v9 >> 28)
                         ^ v9)
                        & 0xF))
           & 1) << 27)
         | ((v9 & 0x3FFFF) << 8)
         | 0x40000001;
  v15[2] = a4;
  result = a5xx_ringbuffer_addcmds(a1, a1 + 1794, 0, 1, v15, 3, 0, 0);
  if ( !(_DWORD)result )
  {
    if ( (__int64 *)a1[2455] != v10 )
      kthread_queue_work(a1[3050], a1 + 3051);
    v12 = adreno_ringbuffer_waittimestamp(a1 + 1794, *((unsigned int *)a1 + 3597), 20000);
    if ( v12 != -11 && v12 )
    {
      v13 = *a1;
      v14 = v12;
      dev_err(v13, "Perfcounter %s/%u/%u start via commands failed %d\n", *(const char **)(a2 + 16), a3, a4, v12);
      result = v14;
      goto LABEL_10;
    }
LABEL_9:
    result = 0;
    *(_QWORD *)(v5 + 32) = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
