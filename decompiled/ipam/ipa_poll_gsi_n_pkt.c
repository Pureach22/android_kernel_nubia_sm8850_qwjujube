__int64 __fastcall ipa_poll_gsi_n_pkt(__int64 a1, _QWORD *a2, int a3, int *a4)
{
  unsigned int v5; // w21
  __int64 v6; // x8
  int v7; // w20
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 result; // x0
  int v12; // w8
  unsigned int v13; // w19
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v5 = 0;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 1624);
  v17 = 0;
  v7 = *(unsigned __int8 *)(v6 + 136);
  if ( v7 == 1 )
  {
    v9 = *(_QWORD *)(v6 + 120);
    v8 = *(_QWORD *)(v6 + 128);
    v5 = 1;
    v10 = *(_QWORD *)(v6 + 112);
    a2[1] = v9;
    a2[2] = v8;
    *a2 = v10;
    *(_BYTE *)(*(_QWORD *)(a1 + 1624) + 136LL) = 0;
  }
  if ( a3 == v5 )
  {
    result = 0;
    *a4 = a3;
    goto LABEL_13;
  }
  result = gsi_poll_n_channel(*(_QWORD *)(*(_QWORD *)(a1 + 1624) + 8LL), &a2[3 * v5], a3 - v5, &v17);
  if ( !(_DWORD)result )
  {
    v12 = v17 + v5;
LABEL_12:
    *a4 = v12;
    goto LABEL_13;
  }
  if ( (_DWORD)result == 9 )
  {
    if ( !v7 )
    {
      *a4 = 0;
      result = 9;
      goto LABEL_13;
    }
    goto LABEL_11;
  }
  if ( v7 )
  {
LABEL_11:
    result = 0;
    v12 = 1;
    goto LABEL_12;
  }
  *a4 = 0;
  v13 = result;
  printk(&unk_3DE36C, "ipa_poll_gsi_n_pkt");
  v14 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v15 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v15 )
    {
      ipc_log_string(v15, "ipa %s:%d Poll channel err: %d\n", "ipa_poll_gsi_n_pkt", 7196, v13);
      v14 = ipa3_ctx;
    }
    v16 = *(_QWORD *)(v14 + 34160);
    if ( v16 )
      ipc_log_string(v16, "ipa %s:%d Poll channel err: %d\n", "ipa_poll_gsi_n_pkt", 7196, v13);
  }
  result = v13;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
