__int64 __fastcall rmnet_perf_tether_cmd(char a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v6; // x21
  _QWORD *v7; // x8
  char *v8; // x8
  char v9; // w9
  __int64 v10; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x9
  unsigned int *v13; // x9
  unsigned int v14; // w12
  __int64 v15; // x9

  result = dev_get_by_name(&init_net, "rmnet_ipa0");
  if ( result )
  {
    v5 = result;
    if ( a1 == 1 )
    {
      result = _alloc_skb(16, 2080, 0, 0xFFFFFFFFLL);
      if ( result )
      {
        v6 = result;
        skb_put(result, 16);
        v7 = *(_QWORD **)(v6 + 224);
        *v7 = 0;
        v7[1] = 0;
        v8 = *(char **)(v6 + 224);
        v9 = *v8;
        *((_WORD *)v8 + 1) = 3072;
        *v8 = v9 | 0x80;
        *(_BYTE *)(*(_QWORD *)(v6 + 224) + 4LL) = 27;
        v10 = *(_QWORD *)(v6 + 224);
        *(_BYTE *)(v10 + 12) = 1;
        *(_BYTE *)(v10 + 14) = a2 == 0;
        *(_QWORD *)(v6 + 16) = v5;
        *(_WORD *)(v6 + 180) = -1792;
        result = rmnet_qmap_send(v6, 255, 0);
      }
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    v12 = *(_QWORD *)(v5 + 1320);
    v13 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v12);
    do
      v14 = __ldxr(v13);
    while ( __stxr(v14 - 1, v13) );
    v15 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v15;
    if ( !v15 || !*(_QWORD *)(StatusReg + 16) )
      return preempt_schedule_notrace(result);
  }
  return result;
}
