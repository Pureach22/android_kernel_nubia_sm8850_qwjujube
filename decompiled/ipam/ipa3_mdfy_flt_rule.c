__int64 __fastcall ipa3_mdfy_flt_rule(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  unsigned __int64 v6; // x20
  __int64 v7; // x19
  int v8; // w8
  int v9; // w23
  int v10; // w21
  __int64 v11; // x1
  int v12; // w25
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int (__fastcall *v17)(_QWORD); // x8
  unsigned int v18; // w19
  _DWORD v19[2]; // [xsp+8h] [xbp-188h] BYREF
  _BYTE v20[360]; // [xsp+10h] [xbp-180h] BYREF
  __int64 v21; // [xsp+178h] [xbp-18h]
  __int64 v22; // [xsp+180h] [xbp-10h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !*(_BYTE *)(a1 + 8) || *(_DWORD *)(a1 + 4) >= 2u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_mdfy_flt_rule__rs, "ipa3_mdfy_flt_rule") )
      printk(&unk_3FB3F2, "ipa3_mdfy_flt_rule");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d bad parm\n", "ipa3_mdfy_flt_rule", 1762);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d bad parm\n", "ipa3_mdfy_flt_rule", 1762);
    }
    result = 4294967274LL;
    goto LABEL_12;
  }
  mutex_lock(ipa3_ctx + 29472);
  if ( *(_BYTE *)(a1 + 8) )
  {
    v6 = 0;
    v7 = a1;
    do
    {
      if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
        *(_BYTE *)(v7 + 366) = 0;
      v9 = *(_DWORD *)(v7 + 372);
      v10 = *(_DWORD *)(v7 + 376);
      v21 = 0;
      memcpy(v20, (const void *)(v7 + 12), sizeof(v20));
      v11 = *(unsigned int *)(a1 + 4);
      v19[0] = v9;
      v19[1] = v10;
      v12 = _ipa_mdfy_flt_rule(v19, v11);
      memcpy((void *)(v7 + 12), v20, 0x168u);
      *(_DWORD *)(v7 + 372) = v9;
      *(_DWORD *)(v7 + 376) = v10;
      if ( !v12 )
      {
        v8 = 0;
        goto LABEL_16;
      }
      if ( (unsigned int)__ratelimit(&ipa3_mdfy_flt_rule__rs_66, "ipa3_mdfy_flt_rule") )
      {
        printk(&unk_3FB408, "ipa3_mdfy_flt_rule");
        v13 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_22:
          v14 = *(_QWORD *)(v13 + 34152);
          if ( v14 )
          {
            ipc_log_string(v14, "ipa %s:%d failed to mdfy flt rule %d\n", "ipa3_mdfy_flt_rule", 1780, v6);
            v13 = ipa3_ctx;
          }
          v15 = *(_QWORD *)(v13 + 34160);
          if ( v15 )
            ipc_log_string(v15, "ipa %s:%d failed to mdfy flt rule %d\n", "ipa3_mdfy_flt_rule", 1780, v6);
        }
      }
      else
      {
        v13 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_22;
      }
      v8 = -1;
LABEL_16:
      *(_DWORD *)(v7 + 376) = v8;
      ++v6;
      v7 += 368;
    }
    while ( v6 < *(unsigned __int8 *)(a1 + 8) );
  }
  if ( !*(_BYTE *)a1 )
    goto LABEL_34;
  v16 = *(unsigned int *)(a1 + 4);
  v17 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
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
