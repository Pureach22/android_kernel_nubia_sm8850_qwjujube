__int64 __fastcall ipa3_add_rt_rule_ext_v2(__int64 a1, char a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v8; // x27
  unsigned __int64 v9; // x21
  int v10; // w8
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int (__fastcall *v16)(_QWORD); // x8
  unsigned int v17; // w19

  if ( !a1 || !*(_BYTE *)(a1 + 40) || *(_DWORD *)(a1 + 4) >= 2u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_ext_v2__rs, "ipa3_add_rt_rule_ext_v2") )
      printk(&unk_3C3EF1, "ipa3_add_rt_rule_ext_v2");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d bad param\n", "ipa3_add_rt_rule_ext_v2", 1510);
        v3 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v3 + 34160);
      if ( v5 )
        ipc_log_string(v5, "ipa %s:%d bad param\n", "ipa3_add_rt_rule_ext_v2", 1510);
    }
    return 4294967274LL;
  }
  mutex_lock(ipa3_ctx + 29472);
  if ( *(_BYTE *)(a1 + 40) )
  {
    v8 = 0;
    v9 = 0;
    do
    {
      if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
        *(_BYTE *)(*(_QWORD *)(a1 + 56) + v8 + 181) = 0;
      if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, __int64, _QWORD, __int64, _QWORD, _QWORD))_ipa_add_rt_rule)(
                            *(unsigned int *)(a1 + 4),
                            a1 + 8,
                            *(_QWORD *)(a1 + 56) + v8 + 16,
                            *(unsigned __int8 *)(*(_QWORD *)(a1 + 56) + v8),
                            *(_QWORD *)(a1 + 56) + v8 + 4,
                            *(unsigned __int16 *)(*(_QWORD *)(a1 + 56) + v8 + 12),
                            a2 & 1) )
      {
        v10 = 0;
        goto LABEL_15;
      }
      if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_ext_v2__rs_29, "ipa3_add_rt_rule_ext_v2") )
      {
        printk(&unk_3B00AA, "ipa3_add_rt_rule_ext_v2");
        v12 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_21:
          v13 = *(_QWORD *)(v12 + 34152);
          if ( v13 )
          {
            ipc_log_string(v13, "ipa %s:%d failed to add rt rule %d\n", "ipa3_add_rt_rule_ext_v2", 1529, v9);
            v12 = ipa3_ctx;
          }
          v14 = *(_QWORD *)(v12 + 34160);
          if ( v14 )
            ipc_log_string(v14, "ipa %s:%d failed to add rt rule %d\n", "ipa3_add_rt_rule_ext_v2", 1529, v9);
        }
      }
      else
      {
        v12 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_21;
      }
      v10 = -1;
LABEL_15:
      ++v9;
      v11 = *(_QWORD *)(a1 + 56) + v8;
      v8 += 192;
      *(_DWORD *)(v11 + 8) = v10;
    }
    while ( v9 < *(unsigned __int8 *)(a1 + 40) );
  }
  if ( !*(_BYTE *)a1 )
    goto LABEL_33;
  v15 = *(unsigned int *)(a1 + 4);
  v16 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 120LL);
  if ( *((_DWORD *)v16 - 1) != 1856640366 )
    __break(0x8228u);
  if ( v16(v15) )
    v17 = -1;
  else
LABEL_33:
    v17 = 0;
  mutex_unlock(ipa3_ctx + 29472);
  return v17;
}
