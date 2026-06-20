__int64 __fastcall modem_notifier_cb(__int64 a1, __int64 a2)
{
  __int64 v3; // x24
  __int64 *v4; // x25
  unsigned __int64 v5; // x8
  __int64 *v6; // x23
  int v7; // w8
  __int64 *v8; // x27
  char v9; // w9
  __int64 *v10; // x21
  __int64 *v11; // x28
  __int64 *v12; // x23
  int v13; // w20
  __int64 *v14; // x8
  int v15; // w9
  __int64 v16; // x10
  unsigned __int64 StatusReg; // x19
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // [xsp+8h] [xbp-28h]
  _QWORD v22[4]; // [xsp+10h] [xbp-20h] BYREF

  v22[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[2] = 7;
  v22[0] = 0;
  v22[1] = 3;
  mutex_lock(memsh_drv + 8);
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      dev_info(*(_QWORD *)memsh_drv, "memshare: QCOM_SSR_BEFORE_SHUTDOWN: bootup_request:%llu\n", ++bootup_request);
      dword_8550 = 0;
      dword_85B0 = 0;
      dword_8610 = 0;
      dword_8670 = 0;
      dword_86D0 = 0;
      dword_8730 = 0;
      dword_8790 = 0;
      dword_87F0 = 0;
      dword_8850 = 0;
      dword_88B0 = 0;
    }
    goto LABEL_32;
  }
  if ( a2 != 1 )
  {
LABEL_32:
    mutex_unlock(memsh_drv + 8);
    dev_info(*(_QWORD *)memsh_drv, "memshare: notifier_cb processed for code: %lu\n", a2);
    goto LABEL_33;
  }
  dev_info(*(_QWORD *)memsh_drv, "memshare: QCOM_SSR_AFTER_POWERUP: Modem has booted up\n");
  v3 = 0;
  v4 = &memsh_child;
  v5 = bootup_request;
  while ( 1 )
  {
    v8 = &memblock[v3];
    v9 = memblock[v3 + 11];
    if ( v9 && v5 >= 2 )
      *((_BYTE *)v8 + 88) = --v9;
    if ( v9 )
      goto LABEL_13;
    v10 = &memblock[v3];
    if ( HIDWORD(memblock[v3]) )
      goto LABEL_13;
    if ( *((_DWORD *)v10 + 4) )
      goto LABEL_13;
    v11 = &memblock[v3];
    if ( HIDWORD(memblock[v3 + 3]) )
      goto LABEL_13;
    if ( !*((_DWORD *)v11 + 5) )
      goto LABEL_13;
    v12 = &memblock[v3];
    if ( LODWORD(memblock[v3 + 3]) )
      goto LABEL_13;
    v13 = *((_DWORD *)v8 + 14);
    v21 = *v4;
    dev_info(
      *(_QWORD *)memsh_drv,
      "memshare: hypervisor unmapping for allocated memory with client id: %d\n",
      *(unsigned int *)v12);
    if ( *((_BYTE *)v12 + 89) )
      break;
LABEL_9:
    v6 = &memblock[v3];
    if ( LODWORD(memblock[v3 + 4]) )
      v7 = v13 + 4096;
    else
      v7 = v13;
    dma_free_attrs(*(_QWORD *)(v21 + 8), v7, memblock[v3 + 10], memblock[v3 + 9], 0);
    v5 = bootup_request;
    *((_DWORD *)v11 + 5) = 0;
    *((_DWORD *)v10 + 4) = 0;
    v6[9] = 0;
    v6[10] = 0;
    v6[1] = 0x1FFFFFFFFLL;
LABEL_13:
    v3 += 12;
    ++v4;
    if ( v3 == 120 )
    {
      bootup_request = v5 + 1;
      goto LABEL_32;
    }
  }
  v14 = &memblock[v3];
  v15 = HIDWORD(memblock[v3 + 4]);
  if ( !v15 )
  {
LABEL_28:
    if ( (unsigned int)qcom_scm_assign_mem(v14[9], *((unsigned int *)v8 + 14), v22) && *((_BYTE *)v12 + 89) == 1 )
      dev_err(
        *(_QWORD *)memsh_drv,
        "memshare: failed to hypervisor unmap the memory region for client id: %d\n",
        *(_DWORD *)v8);
    else
      *((_BYTE *)v12 + 89) = 0;
    goto LABEL_9;
  }
  v16 = (1LL << *((_DWORD *)v14 + 10)) | v22[0];
  if ( v15 == 1 || (v16 |= 1LL << HIDWORD(memblock[v3 + 5]), v15 == 2) )
  {
    v22[0] = v16;
    goto LABEL_28;
  }
  v22[0] = v16;
  __break(0x5512u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v19 = _traceiter_rproc_qcom_event(0, "modem", "modem_notifier", "exit");
    v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v20;
    if ( !v20 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v19);
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return 0;
}
