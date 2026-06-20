__int64 __fastcall ipa3_mdfy_rt_rule(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  unsigned __int64 v6; // x20
  int *v7; // x28
  int v8; // w23
  int v9; // w21
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned int (__fastcall *v14)(_QWORD); // x8
  unsigned int v15; // w19
  _DWORD v16[2]; // [xsp+8h] [xbp-C8h] BYREF
  _BYTE v17[168]; // [xsp+10h] [xbp-C0h] BYREF
  __int64 v18; // [xsp+B8h] [xbp-18h]
  __int64 v19; // [xsp+C0h] [xbp-10h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !*(_BYTE *)(a1 + 8) || *(_DWORD *)(a1 + 4) >= 2u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_mdfy_rt_rule__rs, "ipa3_mdfy_rt_rule") )
      printk(&unk_3C3EF1, "ipa3_mdfy_rt_rule");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d bad param\n", "ipa3_mdfy_rt_rule", 2284);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d bad param\n", "ipa3_mdfy_rt_rule", 2284);
    }
    result = 4294967274LL;
    goto LABEL_12;
  }
  mutex_lock(ipa3_ctx + 29472);
  if ( *(_BYTE *)(a1 + 8) )
  {
    v6 = 0;
    v7 = (int *)(a1 + 184);
    do
    {
      if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
        *((_BYTE *)v7 - 7) = 0;
      v9 = *(v7 - 1);
      v8 = *v7;
      v18 = 0;
      memcpy(v17, v7 - 43, sizeof(v17));
      v16[0] = v9;
      v16[1] = v8;
      if ( !(unsigned int)_ipa_mdfy_rt_rule(v16) )
      {
        *v7 = 0;
        memcpy(v7 - 43, v17, 0xA8u);
        *(v7 - 1) = v9;
        goto LABEL_16;
      }
      if ( (unsigned int)__ratelimit(&ipa3_mdfy_rt_rule__rs_109, "ipa3_mdfy_rt_rule") )
      {
        printk(&unk_3E6CDA, "ipa3_mdfy_rt_rule");
        v10 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_22:
          v11 = *(_QWORD *)(v10 + 34152);
          if ( v11 )
          {
            ipc_log_string(v11, "ipa %s:%d failed to mdfy rt rule %i\n", "ipa3_mdfy_rt_rule", 2295, v6);
            v10 = ipa3_ctx;
          }
          v12 = *(_QWORD *)(v10 + 34160);
          if ( v12 )
            ipc_log_string(v12, "ipa %s:%d failed to mdfy rt rule %i\n", "ipa3_mdfy_rt_rule", 2295, v6);
        }
      }
      else
      {
        v10 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_22;
      }
      v8 = -1;
LABEL_16:
      *v7 = v8;
      v7 += 44;
      ++v6;
    }
    while ( v6 < *(unsigned __int8 *)(a1 + 8) );
  }
  if ( !*(_BYTE *)a1 )
    goto LABEL_34;
  v13 = *(unsigned int *)(a1 + 4);
  v14 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 120LL);
  if ( *((_DWORD *)v14 - 1) != 1856640366 )
    __break(0x8228u);
  if ( v14(v13) )
    v15 = -1;
  else
LABEL_34:
    v15 = 0;
  mutex_unlock(ipa3_ctx + 29472);
  result = v15;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
