__int64 __fastcall ipa3_set_evict_policy(int *a1)
{
  int v1; // w8
  int v2; // w9
  char v3; // w10
  bool v4; // zf
  int v5; // w9
  int v6; // w10
  char v7; // w8
  int v8; // w8
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  int v13; // [xsp+Ch] [xbp-14h] BYREF
  char v14; // [xsp+10h] [xbp-10h]
  char v15; // [xsp+11h] [xbp-Fh]
  __int16 v16; // [xsp+12h] [xbp-Eh]
  int v17; // [xsp+14h] [xbp-Ch]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x11u )
    {
      v1 = *a1;
      v2 = *((unsigned __int8 *)a1 + 8);
      v3 = *((_BYTE *)a1 + 9);
      v17 = 0;
      v13 = v1;
      LOWORD(v1) = *((_WORD *)a1 + 5);
      v4 = v2 == 0;
      v5 = *((unsigned __int8 *)a1 + 12);
      v15 = v3;
      v6 = *((unsigned __int8 *)a1 + 13);
      v16 = v1;
      v7 = !v4;
      v14 = v7;
      v8 = *((unsigned __int8 *)a1 + 14);
      LOBYTE(v17) = v5 != 0;
      BYTE1(v17) = v6 != 0;
      BYTE2(v17) = v8 != 0;
      ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(128, 0, &v13);
    }
    result = 0;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_set_evict_policy__rs, "ipa3_set_evict_policy") )
      printk(&unk_3AD81A, "ipa3_set_evict_policy");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d Bad arg evict_pol(%p)\n", "ipa3_set_evict_policy", 7331, nullptr);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d Bad arg evict_pol(%p)\n", "ipa3_set_evict_policy", 7331, nullptr);
    }
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
