__int64 __fastcall ipa3_del_flt_rule(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  unsigned __int64 v6; // x20
  int *v7; // x26
  int v8; // w8
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int (__fastcall *v13)(_QWORD); // x8
  unsigned int v14; // w19

  if ( !a1 || !*(_BYTE *)(a1 + 8) || *(_DWORD *)(a1 + 4) >= 2u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_del_flt_rule__rs, "ipa3_del_flt_rule") )
      printk(&unk_3C3EF1, "ipa3_del_flt_rule");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d bad param\n", "ipa3_del_flt_rule", 1721);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d bad param\n", "ipa3_del_flt_rule", 1721);
    }
    return 4294967274LL;
  }
  mutex_lock(ipa3_ctx + 29472);
  if ( *(_BYTE *)(a1 + 8) )
  {
    v6 = 0;
    v7 = (int *)(a1 + 16);
    do
    {
      if ( !(unsigned int)_ipa_del_flt_rule((unsigned int)*(v7 - 1)) )
      {
        v8 = 0;
        goto LABEL_15;
      }
      if ( (unsigned int)__ratelimit(&ipa3_del_flt_rule__rs_63, "ipa3_del_flt_rule") )
      {
        printk(&unk_3B22FC, "ipa3_del_flt_rule");
        v9 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_19:
          v10 = *(_QWORD *)(v9 + 34152);
          if ( v10 )
          {
            ipc_log_string(v10, "ipa %s:%d failed to del flt rule %i\n", "ipa3_del_flt_rule", 1728, v6);
            v9 = ipa3_ctx;
          }
          v11 = *(_QWORD *)(v9 + 34160);
          if ( v11 )
            ipc_log_string(v11, "ipa %s:%d failed to del flt rule %i\n", "ipa3_del_flt_rule", 1728, v6);
        }
      }
      else
      {
        v9 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_19;
      }
      v8 = -1;
LABEL_15:
      *v7 = v8;
      v7 += 2;
      ++v6;
    }
    while ( v6 < *(unsigned __int8 *)(a1 + 8) );
  }
  if ( !*(_BYTE *)a1 )
    goto LABEL_31;
  v12 = *(unsigned int *)(a1 + 4);
  v13 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
  if ( *((_DWORD *)v13 - 1) != 1856640366 )
    __break(0x8228u);
  if ( v13(v12) )
    v14 = -1;
  else
LABEL_31:
    v14 = 0;
  mutex_unlock(ipa3_ctx + 29472);
  return v14;
}
