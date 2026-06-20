__int64 __fastcall ipa3_uc_holb_event_log(__int64 result, char a2, int a3, int a4)
{
  __int64 v5; // x9
  __int64 v6; // x12
  __int64 v7; // x8
  __int64 v8; // x13
  __int64 v9; // x9
  __int64 v10; // x12
  unsigned int v11; // w13
  __int64 v12; // x11
  int v13; // w13
  __int64 v14; // x15
  unsigned __int16 v15; // w20
  __int64 v16; // x9
  unsigned __int16 v17; // w8
  __int64 v18; // x0

  if ( *(_BYTE *)(ipa3_ctx + 34904) == 1 )
  {
    v5 = *(unsigned int *)(ipa3_ctx + 34912);
    if ( (int)v5 < 1 )
    {
LABEL_16:
      v15 = result;
      result = printk(&unk_3E4374, "ipa3_uc_holb_event_log");
      v16 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v17 = v15;
        v18 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v18 )
        {
          ipc_log_string(v18, "ipa %s:%d Invalid client with GSI chan %d\n", "ipa3_uc_holb_event_log", 231, v15);
          v16 = ipa3_ctx;
          v17 = v15;
        }
        result = *(_QWORD *)(v16 + 34160);
        if ( result )
          return ipc_log_string(
                   result,
                   "ipa %s:%d Invalid client with GSI chan %d\n",
                   "ipa3_uc_holb_event_log",
                   231,
                   v17);
      }
    }
    else
    {
      v6 = 0;
      v7 = 0;
      v8 = 272 * v5;
      v9 = ipa3_ctx + 34932;
      while ( 1 )
      {
        if ( v6 == -31 )
          goto LABEL_21;
        if ( *(unsigned __int16 *)(v9 + v7) == (unsigned __int16)result )
          break;
        v7 += 272;
        --v6;
        if ( v8 == v7 )
          goto LABEL_16;
      }
      if ( (_DWORD)v6 == 22 )
        goto LABEL_16;
      if ( (unsigned int)-(int)v6 >= 0x1F
        || (v10 = ipa3_ctx + 35192, v11 = *(_DWORD *)(ipa3_ctx + 35192 + v7), v11 > 0x13) )
      {
LABEL_21:
        __break(0x5512u);
        __asm { STGP            X14, X2, [X22],#-0x44 }
        return ipa3_uc_mhi_init();
      }
      v12 = ipa3_ctx + 12LL * v11 + v7;
      *(_DWORD *)(v12 + 34952) = a3;
      v13 = *(_DWORD *)(v10 + v7);
      *(_BYTE *)(v12 + 34960) = a2 & 1;
      if ( (a2 & 1) != 0 )
        v14 = 264;
      else
        v14 = 268;
      *(_DWORD *)(v12 + 34956) = a4;
      ++*(_DWORD *)(v9 + v14 + v7);
      *(_DWORD *)(v10 + v7) = (v13 + 1) % 0x14u;
    }
  }
  return result;
}
