__int64 __fastcall rmnet_perf_cmd_xmit(_BYTE *a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x19
  size_t v5; // x21
  __int64 v6; // x0
  __int64 v7; // x22
  char *v8; // x8
  char v9; // w9
  char v10; // w10
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x9
  unsigned int *v14; // x9
  unsigned int v15; // w12
  __int64 v16; // x9
  unsigned int v17; // w19

  v2 = dev_get_by_name(&init_net, "rmnet_ipa0");
  if ( v2 )
  {
    v3 = *(unsigned __int16 *)a1;
    v4 = v2;
    v5 = v3 + 12;
    v6 = _alloc_skb((unsigned int)(v3 + 12), 2080, 0, 0xFFFFFFFFLL);
    if ( v6 )
    {
      v7 = v6;
      skb_put(v6, (unsigned int)v5);
      memset(*(void **)(v7 + 224), 0, v5);
      v8 = *(char **)(v7 + 224);
      v9 = *v8;
      v8[1] = 0;
      v10 = v8[5];
      *v8 = v9 | 0x80;
      *((_WORD *)v8 + 1) = bswap32(*(unsigned __int16 *)a1 + 8) >> 16;
      v8[4] = a1[2];
      v8[5] = v10 & 0xFC | a1[3] & 3;
      memcpy((void *)(*(_QWORD *)(v7 + 224) + 12LL), a1 + 4, *(unsigned __int16 *)a1);
      *(_QWORD *)(v7 + 16) = v4;
      *(_WORD *)(v7 + 180) = -1792;
      result = rmnet_qmap_send(v7, 255, 0);
    }
    else
    {
      printk(&unk_F279, "rmnet_perf_cmd_xmit");
      result = 4294967284LL;
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    v13 = *(_QWORD *)(v4 + 1320);
    v14 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v13);
    do
      v15 = __ldxr(v14);
    while ( __stxr(v15 - 1, v14) );
    v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v16;
    if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
    {
      v17 = result;
      preempt_schedule_notrace();
      return v17;
    }
  }
  else
  {
    printk(&unk_F35C, "rmnet_perf_cmd_xmit");
    return 4294967277LL;
  }
  return result;
}
