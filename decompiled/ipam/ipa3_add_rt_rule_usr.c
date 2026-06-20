__int64 __fastcall ipa3_add_rt_rule_usr(__int64 a1, char a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 result; // x0
  unsigned __int64 v8; // x21
  __int64 v9; // x28
  int v10; // w8
  __int64 v11; // x0
  __int64 v12; // x3
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int (__fastcall *v17)(_QWORD); // x8
  unsigned int v18; // w19
  _BYTE v19[168]; // [xsp+0h] [xbp-C0h] BYREF
  __int64 v20; // [xsp+A8h] [xbp-18h]
  __int64 v21; // [xsp+B0h] [xbp-10h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !*(_BYTE *)(a1 + 40) || *(_DWORD *)(a1 + 4) >= 2u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_usr__rs, "ipa3_add_rt_rule_usr") )
      printk(&unk_3C3EF1, "ipa3_add_rt_rule_usr");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d bad param\n", "ipa3_add_rt_rule_usr", 1341);
        v3 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v3 + 34160);
      if ( v5 )
        ipc_log_string(v5, "ipa %s:%d bad param\n", "ipa3_add_rt_rule_usr", 1341);
    }
    result = 4294967274LL;
    goto LABEL_12;
  }
  mutex_lock(ipa3_ctx + 29472);
  if ( *(_BYTE *)(a1 + 40) )
  {
    v8 = 0;
    v9 = a1 + 209;
    do
    {
      *(_BYTE *)(a1 + 39) = 0;
      if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
        *(_BYTE *)v9 = 0;
      memcpy(v19, (const void *)(v9 - 165), sizeof(v19));
      v11 = *(unsigned int *)(a1 + 4);
      v12 = *(unsigned __int8 *)(v9 + 3);
      v20 = 0;
      if ( !(unsigned int)((__int64 (__fastcall *)(__int64, __int64, _BYTE *, __int64, __int64, _QWORD, _QWORD))_ipa_add_rt_rule)(
                            v11,
                            a1 + 8,
                            v19,
                            v12,
                            v9 + 7,
                            0,
                            a2 & 1) )
      {
        memcpy((void *)(v9 - 165), v19, 0xA8u);
        v10 = 0;
        goto LABEL_16;
      }
      if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_usr__rs_24, "ipa3_add_rt_rule_usr") )
      {
        printk(&unk_3B00AA, "ipa3_add_rt_rule_usr");
        v13 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_22:
          v14 = *(_QWORD *)(v13 + 34152);
          if ( v14 )
          {
            ipc_log_string(v14, "ipa %s:%d failed to add rt rule %d\n", "ipa3_add_rt_rule_usr", 1358, v8);
            v13 = ipa3_ctx;
          }
          v15 = *(_QWORD *)(v13 + 34160);
          if ( v15 )
            ipc_log_string(v15, "ipa %s:%d failed to add rt rule %d\n", "ipa3_add_rt_rule_usr", 1358, v8);
        }
      }
      else
      {
        v13 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_22;
      }
      v10 = -1;
LABEL_16:
      *(_DWORD *)(v9 + 11) = v10;
      ++v8;
      v9 += 180;
    }
    while ( v8 < *(unsigned __int8 *)(a1 + 40) );
  }
  if ( !*(_BYTE *)a1 )
    goto LABEL_34;
  v16 = *(unsigned int *)(a1 + 4);
  v17 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 120LL);
  if ( *((_DWORD *)v17 - 1) != 1856640366 )
    __break(0x8228u);
  if ( v17(v16) )
    v18 = -1;
  else
LABEL_34:
    v18 = 0;
  mutex_unlock(ipa3_ctx + 29472);
  result = v18;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
