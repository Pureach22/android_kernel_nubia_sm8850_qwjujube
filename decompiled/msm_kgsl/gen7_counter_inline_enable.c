__int64 __fastcall gen7_counter_inline_enable(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v9; // x22
  unsigned int v11; // w8
  __int64 v12; // x8
  unsigned int v13; // w0
  unsigned int v14; // w22
  _DWORD v15[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 11120) != 2 )
  {
    v5 = *(_QWORD *)a2 + 48LL * a3;
    result = gen7_perfcounter_update(a1, (int *)v5, 1, 0, *(_QWORD *)(a2 + 24));
    if ( (_DWORD)result )
      goto LABEL_16;
LABEL_15:
    *(_QWORD *)(v5 + 32) = 0;
    goto LABEL_16;
  }
  if ( *(_BYTE *)(a1 + 24024) == 1 )
  {
    result = gen7_hwsched_counter_inline_enable(a1, (__int64 *)a2, a3, a4);
    goto LABEL_16;
  }
  v5 = *(_QWORD *)a2 + 48LL * a3;
  v9 = a1 + 14352;
  gen7_perfcounter_update(a1, (int *)v5, 0, 0, *(_QWORD *)(a2 + 24));
  v15[0] = 1881571328;
  v11 = *(_DWORD *)(v5 + 24);
  v15[1] = (((0x9669u >> (((v11 >> 4)
                         ^ BYTE1(v11)
                         ^ (v11 >> 12)
                         ^ BYTE2(v11)
                         ^ (v11 >> 20)
                         ^ HIBYTE(v11)
                         ^ (v11 >> 28)
                         ^ v11)
                        & 0xF))
           & 1) << 27)
         | ((v11 & 0x3FFFF) << 8)
         | 0x40000001;
  v15[2] = a4;
  result = gen7_ringbuffer_addcmds(a1, v9, 0, 1, v15, 3, 0, 0);
  if ( (_DWORD)result )
    goto LABEL_16;
  v12 = a1;
  if ( *(_QWORD *)(a1 + 19640) != v9 )
  {
    kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
    v12 = a1;
  }
  v13 = adreno_ringbuffer_waittimestamp(v9, *(unsigned int *)(v12 + 14388), 20000);
  if ( v13 == -11 || !v13 )
  {
    result = 0;
    goto LABEL_15;
  }
  v14 = v13;
  if ( (unsigned int)__ratelimit(&gen7_swsched_counter_inline_enable__rs, "gen7_swsched_counter_inline_enable") )
    dev_err(
      *(_QWORD *)a1,
      "Perfcounter %s/%u/%u start via commands failed %d\n",
      *(const char **)(a2 + 16),
      a3,
      a4,
      v14);
  result = v14;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
