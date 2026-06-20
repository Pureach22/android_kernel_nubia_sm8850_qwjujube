__int64 __fastcall ipa3_generate_flt_hw_rule(int a1, __int64 a2)
{
  int v3; // w8
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  int *v8; // x8
  int v9; // w8
  unsigned int v10; // w9
  unsigned int v11; // w10
  __int64 result; // x0
  unsigned int v13; // w19
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int64 v21; // [xsp+10h] [xbp-20h]
  __int64 v22; // [xsp+18h] [xbp-18h]
  __int64 v23; // [xsp+20h] [xbp-10h]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned __int8 *)(a2 + 374);
  v21 = 0;
  v22 = 0;
  v20 = 0;
  if ( v3 )
  {
    if ( (*(_BYTE *)(a2 + 35) & 8) != 0 && !*(_BYTE *)(a2 + 372) )
    {
      if ( (unsigned int)__ratelimit(&ipa3_generate_flt_hw_rule__rs, "ipa3_generate_flt_hw_rule") )
        printk(&unk_3C0E1A, "ipa3_generate_flt_hw_rule");
      v17 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v18 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v18 )
        {
          ipc_log_string(v18, "ipa %s:%d PURE_ACK rule atrb used with hash rule\n", "ipa3_generate_flt_hw_rule", 52);
          v17 = ipa3_ctx;
        }
        v19 = *(_QWORD *)(v17 + 34160);
        if ( v19 )
          ipc_log_string(v19, "ipa %s:%d PURE_ACK rule atrb used with hash rule\n", "ipa3_generate_flt_hw_rule", 52);
      }
      goto LABEL_33;
    }
    if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x11u && *(_BYTE *)(a2 + 372) && *(_BYTE *)(a2 + 186) )
    {
      if ( (unsigned int)__ratelimit(&ipa3_generate_flt_hw_rule__rs_120, "ipa3_generate_flt_hw_rule") )
      {
        printk(&unk_3CFBB3, "ipa3_generate_flt_hw_rule");
        v4 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_9;
      }
      else
      {
        v4 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_9:
          v5 = *(_QWORD *)(v4 + 34152);
          if ( v5 )
          {
            ipc_log_string(v5, "ipa %s:%d PURE_ACK rule eq used with hash rule\n", "ipa3_generate_flt_hw_rule", 64);
            v4 = ipa3_ctx;
          }
          v6 = *(_QWORD *)(v4 + 34160);
          if ( v6 )
            ipc_log_string(v6, "ipa %s:%d PURE_ACK rule eq used with hash rule\n", "ipa3_generate_flt_hw_rule", 64);
        }
      }
LABEL_33:
      result = 0xFFFFFFFFLL;
      goto LABEL_34;
    }
  }
  v7 = *(_QWORD *)(a2 + 400);
  LODWORD(v20) = a1;
  if ( v7 && (ipa3_check_idr_if_freed(v7) & 1) == 0 )
    v8 = (int *)(*(_QWORD *)(a2 + 400) + 72LL);
  else
    v8 = (int *)(a2 + 368);
  v9 = *v8;
  v10 = *(unsigned __int16 *)(a2 + 416);
  v11 = *(unsigned __int16 *)(a2 + 418);
  v23 = a2 + 20;
  HIDWORD(v20) = v9;
  v21 = __PAIR64__(v11, v10);
  LOBYTE(v22) = *(_BYTE *)(a2 + 420);
  result = ((__int64 (__fastcall *)(__int64 *, __int64))ipahal_flt_generate_hw_rule)(&v20, a2 + 408);
  if ( (_DWORD)result )
  {
    v13 = result;
    if ( (unsigned int)__ratelimit(&ipa3_generate_flt_hw_rule__rs_123, "ipa3_generate_flt_hw_rule") )
      printk(&unk_3F803E, "ipa3_generate_flt_hw_rule");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d failed to generate flt h/w rule\n", "ipa3_generate_flt_hw_rule", 82);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
        ipc_log_string(v16, "ipa %s:%d failed to generate flt h/w rule\n", "ipa3_generate_flt_hw_rule", 82);
    }
    result = v13;
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
