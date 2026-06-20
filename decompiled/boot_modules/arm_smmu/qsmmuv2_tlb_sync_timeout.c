__int64 __fastcall qsmmuv2_tlb_sync_timeout(_QWORD *a1)
{
  _DWORD **v2; // x8
  _DWORD *v3; // x8
  int v4; // w0
  _DWORD **v5; // x8
  int v6; // w20
  _DWORD *v7; // x8
  int v8; // w0
  int v9; // w21
  __int64 result; // x0

  if ( (unsigned int)__ratelimit(&qsmmuv2_tlb_sync_timeout__rs, "qsmmuv2_tlb_sync_timeout") )
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
    {
LABEL_4:
      v4 = readl_relaxed_1((unsigned int *)(a1[1] + (6 << *((_DWORD *)a1 + 7)) + 80LL));
      goto LABEL_5;
    }
  }
  v3 = *v2;
  if ( !v3 )
    goto LABEL_4;
  if ( *(v3 - 1) != 616069899 )
    __break(0x8228u);
  v4 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v3)(a1, 6, 80);
LABEL_5:
  v5 = (_DWORD **)a1[6];
  v6 = v4;
  if ( v5 && (v7 = *v5) != nullptr )
  {
    if ( *(v7 - 1) != 616069899 )
      __break(0x8228u);
    v8 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v7)(a1, 6, 84);
  }
  else
  {
    v8 = readl_relaxed_1((unsigned int *)(a1[1] + (6 << *((_DWORD *)a1 + 7)) + 84LL));
  }
  v9 = v8;
  result = __ratelimit(&qsmmuv2_tlb_sync_timeout__rs_70, "qsmmuv2_tlb_sync_timeout");
  if ( (_DWORD)result )
    return dev_err(*a1, "clk on 0x%x, clk on client 0x%x status\n", v6, v9);
  return result;
}
