__int64 __fastcall ipa3_add_rt_rule_ext(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  unsigned __int64 v6; // x20
  __int64 v7; // x27
  int v8; // w8
  __int64 v9; // x0
  __int64 v10; // x5
  __int64 v11; // x3
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int (__fastcall *v16)(_QWORD); // x8
  unsigned int v17; // w19
  _BYTE v18[168]; // [xsp+0h] [xbp-C0h] BYREF
  __int64 v19; // [xsp+A8h] [xbp-18h]
  __int64 v20; // [xsp+B0h] [xbp-10h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !*(_BYTE *)(a1 + 40) || *(_DWORD *)(a1 + 4) >= 2u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_ext__rs, "ipa3_add_rt_rule_ext") )
      printk(&unk_3C3EF1, "ipa3_add_rt_rule_ext");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d bad param\n", "ipa3_add_rt_rule_ext", 1456);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d bad param\n", "ipa3_add_rt_rule_ext", 1456);
    }
    result = 4294967274LL;
    goto LABEL_12;
  }
  mutex_lock(ipa3_ctx + 29472);
  if ( *(_BYTE *)(a1 + 40) )
  {
    v6 = 0;
    v7 = a1 + 209;
    do
    {
      if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
        *(_BYTE *)v7 = 0;
      memcpy(v18, (const void *)(v7 - 165), sizeof(v18));
      v9 = *(unsigned int *)(a1 + 4);
      v10 = *(unsigned __int16 *)(v7 + 15);
      v11 = *(unsigned __int8 *)(v7 + 3);
      v19 = 0;
      if ( !(unsigned int)((__int64 (__fastcall *)(__int64, __int64, _BYTE *, __int64, __int64, __int64, __int64))_ipa_add_rt_rule)(
                            v9,
                            a1 + 8,
                            v18,
                            v11,
                            v7 + 7,
                            v10,
                            1) )
      {
        memcpy((void *)(v7 - 165), v18, 0xA8u);
        v8 = 0;
        goto LABEL_16;
      }
      if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_ext__rs_28, "ipa3_add_rt_rule_ext") )
      {
        printk(&unk_3B00AA, "ipa3_add_rt_rule_ext");
        v12 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_22:
          v13 = *(_QWORD *)(v12 + 34152);
          if ( v13 )
          {
            ipc_log_string(v13, "ipa %s:%d failed to add rt rule %d\n", "ipa3_add_rt_rule_ext", 1472, v6);
            v12 = ipa3_ctx;
          }
          v14 = *(_QWORD *)(v12 + 34160);
          if ( v14 )
            ipc_log_string(v14, "ipa %s:%d failed to add rt rule %d\n", "ipa3_add_rt_rule_ext", 1472, v6);
        }
      }
      else
      {
        v12 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_22;
      }
      v8 = -1;
LABEL_16:
      *(_DWORD *)(v7 + 11) = v8;
      ++v6;
      v7 += 184;
    }
    while ( v6 < *(unsigned __int8 *)(a1 + 40) );
  }
  if ( !*(_BYTE *)a1 )
    goto LABEL_34;
  v15 = *(unsigned int *)(a1 + 4);
  v16 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 120LL);
  if ( *((_DWORD *)v16 - 1) != 1856640366 )
    __break(0x8228u);
  if ( v16(v15) )
    v17 = -1;
  else
LABEL_34:
    v17 = 0;
  mutex_unlock(ipa3_ctx + 29472);
  result = v17;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
