__int64 __fastcall arm_tbu_log_outstanding_transactions(__int64 a1)
{
  _QWORD *v1; // x21
  __int64 v3; // x20
  unsigned __int64 v4; // x20
  char v5; // w0
  __int64 v6; // x22
  __int64 v7; // x21

  v1 = *(_QWORD **)(a1 + 32);
  v3 = readq_relaxed_0(v1 + 38);
  writeq_relaxed_0(v3 | 0x80, v1 + 38);
  v4 = v3 & 0xFFFFFFFFFFFB7F3FLL;
  writeq_relaxed_0(v4 | 0x40000, v1 + 38);
  v5 = readq(v1 + 47);
  if ( (v5 & 1) == 0 )
  {
    v6 = 100001;
    while ( --v6 >= 0 )
    {
      __yield();
      v5 = readq(v1 + 47);
      if ( (v5 & 1) != 0 )
        goto LABEL_5;
    }
    if ( (readq(v1 + 47) & 1) != 0 )
      goto LABEL_9;
LABEL_6:
    if ( (unsigned int)__ratelimit(&arm_tbu_log_outstanding_transactions__rs, "arm_tbu_log_outstanding_transactions") )
      dev_err(*(_QWORD *)(a1 + 16), "Timeout on TNX snapshot poll\n");
    return writeq_relaxed_0(v4, (_QWORD *)(*(_QWORD *)(a1 + 32) + 304LL));
  }
LABEL_5:
  if ( (v5 & 1) == 0 )
    goto LABEL_6;
LABEL_9:
  v7 = readq_relaxed_0(v1 + 39);
  if ( (unsigned int)__ratelimit(&arm_tbu_log_outstanding_transactions__rs_18, "arm_tbu_log_outstanding_transactions") )
    dev_err(*(_QWORD *)(a1 + 16), "Outstanding Transaction Bitmap: 0x%llx\n", v7);
  return writeq_relaxed_0(v4, (_QWORD *)(*(_QWORD *)(a1 + 32) + 304LL));
}
