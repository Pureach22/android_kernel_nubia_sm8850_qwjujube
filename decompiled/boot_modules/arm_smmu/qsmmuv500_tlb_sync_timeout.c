__int64 __fastcall qsmmuv500_tlb_sync_timeout(_QWORD *a1)
{
  _DWORD **v2; // x8
  _DWORD *v3; // x8
  unsigned int v4; // w20
  int v5; // w23
  int v6; // w24
  bool v7; // w21
  _BOOL4 v8; // w22
  unsigned int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w21
  unsigned int v12; // w23
  __int64 result; // x0
  unsigned int v14; // w21
  unsigned int v15; // w21
  const char *v16; // x2
  int v17; // w3
  const char *v18; // x4
  unsigned __int64 v19; // x24
  const char *v20; // x2
  const char *v21; // x3
  const char *v22; // x20
  const char *v23; // x21
  _QWORD *v24; // x25
  unsigned __int64 v25; // x9
  _QWORD *v26; // x8
  int v27; // w27
  unsigned int v28; // w9
  unsigned int v29; // w10
  const char **v30; // x8
  const char *v31; // x3
  _QWORD v32[2]; // [xsp+0h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  if ( (unsigned int)__ratelimit(&qsmmuv500_tlb_sync_timeout__rs_32, "qsmmuv500_tlb_sync_timeout") )
  {
    dev_err(*a1, "TLB sync timed out -- SMMU may be deadlocked\n");
    v2 = (_DWORD **)a1[6];
    if ( !v2 )
      goto LABEL_4;
  }
  else
  {
    v2 = (_DWORD **)a1[6];
    if ( !v2 )
      goto LABEL_4;
  }
  v3 = *v2;
  if ( v3 )
  {
    if ( *(v3 - 1) != 616069899 )
      __break(0x8228u);
    v4 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v3)(a1, 7, 1500);
    if ( v4 )
      goto LABEL_5;
    goto LABEL_11;
  }
LABEL_4:
  v4 = readl_relaxed_1((unsigned int *)(a1[1] + (7 << *((_DWORD *)a1 + 7)) + 1500LL));
  if ( v4 )
  {
LABEL_5:
    v5 = (unsigned __int16)v4 >> 1;
    v6 = v4 >> 17;
    v7 = (v4 & 1) == 0;
    v8 = (v4 & 0x10000) == 0;
    goto LABEL_12;
  }
LABEL_11:
  v6 = 0;
  v5 = 0;
  v8 = 1;
  v7 = 1;
LABEL_12:
  v9 = qcom_scm_io_readl(a1[39] + 8708LL, (char *)v32 + 4);
  if ( v9 )
  {
    v14 = v9;
    if ( (unsigned int)__ratelimit(&qsmmuv500_tlb_sync_timeout__rs_34, "qsmmuv500_tlb_sync_timeout") )
      dev_err(*a1, "SCM read of TBU power status fails: %d\n", v14);
    goto LABEL_27;
  }
  v10 = qcom_scm_io_readl(a1[39] + 9840LL, v32);
  if ( v10 )
  {
    v15 = v10;
    if ( (unsigned int)__ratelimit(&qsmmuv500_tlb_sync_timeout__rs_36, "qsmmuv500_tlb_sync_timeout") )
      dev_err(*a1, "SCM read of TBU sync/inv prog fails: %d\n", v15);
LABEL_27:
    if ( v4 )
    {
      if ( v8 )
        v16 = "inv";
      else
        v16 = "sync";
      if ( v8 )
        v17 = v5;
      else
        v17 = v6;
      if ( v8 )
        v18 = "check for TBU power status";
      else
        v18 = "check pending transactions on TBU";
      dev_err(*a1, "TBU %s ack pending, got ack for TBUs %d, %s\n", v16, v17, v18);
    }
    result = dev_err(*a1, "TBU SYNC_INV_ACK reg 0x%x\n", v4);
    goto LABEL_39;
  }
  if ( !HIDWORD(v32[0]) )
  {
LABEL_17:
    v11 = 0;
    goto LABEL_20;
  }
  if ( v8 )
  {
    if ( v7 )
      goto LABEL_17;
    v11 = HIDWORD(v32[0]) & ~v5;
  }
  else
  {
    v11 = HIDWORD(v32[0]) & ~v6;
  }
LABEL_20:
  v12 = v32[0];
  result = __ratelimit(&qsmmuv500_tlb_sync_timeout__rs, "qsmmuv500_tlb_sync_timeout");
  if ( (_DWORD)result )
  {
    v19 = v11;
    dev_err(*a1, "TBU ACK 0x%x TBU PWR 0x%x TCU sync_inv 0x%x\n", v4, HIDWORD(v32[0]), LODWORD(v32[0]));
    v20 = (v12 & 0x10000) != 0 ? "pending" : "completed";
    v21 = ((v12 >> 20) & 1) != 0 ? "pending" : "completed";
    result = dev_err(*a1, "TCU invalidation %s, TCU sync %s\n", v20, v21);
    v22 = v8 ? "inv" : "sync";
    v23 = v8 ? "check for TBU power status" : "check pending transactions on TBU";
    if ( (_DWORD)v19 )
    {
      v24 = a1 + 41;
      v25 = v19;
      do
      {
        v26 = (_QWORD *)*v24;
        v27 = __clz(__rbit64(v25));
        if ( (_QWORD *)*v24 != v24 )
        {
          v28 = v27 << 10;
          while ( 1 )
          {
            v29 = *((_DWORD *)v26 + 14);
            if ( v29 <= v28 && *((_DWORD *)v26 + 15) + v29 > v28 )
              break;
            v26 = (_QWORD *)*v26;
            if ( v26 == v24 )
              goto LABEL_55;
          }
          if ( v26 )
          {
            v30 = (const char **)v26[2];
            v31 = v30[14];
            if ( !v31 )
              v31 = *v30;
            result = dev_err(*a1, "TBU %s ack pending for TBU %s, %s\n", v22, v31, v23);
          }
        }
LABEL_55:
        v25 = (-2LL << v27) & v19;
      }
      while ( v25 );
    }
  }
  if ( (v12 & 0x100000) != 0 )
    result = queue_work_on(32, system_wq, a1 + 45);
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
