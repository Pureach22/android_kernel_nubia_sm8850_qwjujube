__int64 __fastcall ipa3_force_close_coal(char a1, char a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  unsigned int v6; // w19
  __int64 v7; // x10
  __int64 v8; // x9
  unsigned int v9; // w11
  unsigned int v10; // w12
  _WORD *v11; // x11
  unsigned int v12; // w11
  unsigned int v13; // w12
  _WORD *v14; // x11
  _QWORD *v15; // x12
  _WORD *v16; // x10
  _QWORD *v17; // x11
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  _QWORD v22[40]; // [xsp+0h] [xbp-140h] BYREF

  v22[39] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)memset(v22, 0, 0x138u);
  v5 = ipa3_ctx;
  v6 = 0;
  v7 = ipa3_ctx + 48728;
  v8 = ipa3_ctx + 32240;
  if ( (a1 & 1) != 0 )
  {
    if ( *(unsigned __int8 *)(ipa3_ctx + 32244) >= 0x18uLL )
      goto LABEL_43;
    if ( ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 4940] != 1 )
      goto LABEL_13;
    v9 = *(_DWORD *)&ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 4960];
    if ( (v9 & 0x80000000) != 0 )
      goto LABEL_13;
    v10 = *(_DWORD *)v8 <= 0x14u ? 31 : 36;
    if ( v9 >= v10 )
      goto LABEL_13;
    if ( *(_DWORD *)(ipa3_ctx + 480LL * v9 + 168) == 1 )
    {
      v11 = *(_WORD **)v7;
      if ( *(_QWORD *)v7 )
      {
        v6 = 1;
        memset(v22, 0, 104);
        WORD2(v22[4]) = v11[1];
        v22[1] = v11 + 2;
        WORD1(v22[4]) = *v11;
        LODWORD(v22[0]) = 3;
        if ( (a2 & 1) == 0 )
          goto LABEL_27;
        goto LABEL_17;
      }
LABEL_13:
      v6 = 0;
      if ( (a2 & 1) == 0 )
        goto LABEL_27;
      goto LABEL_17;
    }
    v6 = 0;
  }
  if ( (a2 & 1) == 0 )
    goto LABEL_27;
LABEL_17:
  if ( *(unsigned __int8 *)(ipa3_ctx + 32244) >= 0x18uLL )
LABEL_43:
    __break(0x5512u);
  if ( ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 6604] == 1 )
  {
    v12 = *(_DWORD *)&ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 6624];
    if ( (v12 & 0x80000000) == 0 )
    {
      v13 = *(_DWORD *)v8 <= 0x14u ? 31 : 36;
      if ( v12 < v13 && *(_DWORD *)(ipa3_ctx + 480LL * v12 + 168) == 1 )
      {
        v14 = *(_WORD **)(ipa3_ctx + 48736);
        if ( v14 )
        {
          v15 = &v22[13 * v6++];
          v15[11] = 0;
          v15[12] = 0;
          v15[9] = 0;
          v15[10] = 0;
          v15[7] = 0;
          v15[8] = 0;
          v15[5] = 0;
          v15[6] = 0;
          v15[3] = 0;
          v15[4] = 0;
          v15[1] = 0;
          v15[2] = 0;
          *v15 = 0;
          *((_WORD *)v15 + 18) = v14[1];
          v15[1] = v14 + 2;
          *((_WORD *)v15 + 17) = *v14;
          *(_DWORD *)v15 = 3;
        }
      }
    }
  }
LABEL_27:
  if ( *(_BYTE *)(v7 + 2514) == 1 && (v16 = *(_WORD **)(v7 + 16)) != nullptr )
  {
    v17 = &v22[13 * v6++];
    v17[11] = 0;
    v17[12] = 0;
    v17[9] = 0;
    v17[10] = 0;
    v17[7] = 0;
    v17[8] = 0;
    v17[5] = 0;
    v17[6] = 0;
    v17[3] = 0;
    v17[4] = 0;
    v17[1] = 0;
    v17[2] = 0;
    *v17 = 0;
    *((_WORD *)v17 + 18) = v16[1];
    v17[1] = v16 + 2;
    *((_WORD *)v17 + 17) = *v16;
    *(_DWORD *)v17 = 3;
  }
  else if ( !v6 )
  {
    goto LABEL_42;
  }
  if ( v5 )
  {
    v18 = *(_QWORD *)(v8 + 1912);
    if ( v18 )
    {
      ipc_log_string(
        v18,
        "ipa %s:%d Sending %d descriptor(s) for coal force close\n",
        "ipa3_force_close_coal",
        12809,
        v6);
      v5 = ipa3_ctx;
    }
    v19 = *(_QWORD *)(v5 + 34160);
    if ( v19 )
      ipc_log_string(
        v19,
        "ipa %s:%d Sending %d descriptor(s) for coal force close\n",
        "ipa3_force_close_coal",
        12809,
        v6);
  }
  result = ipa3_send_cmd_timeout(v6, (__int64)v22, 0x1F4u);
  if ( (_DWORD)result )
  {
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d ipa3_send_cmd_timeout timedout\n", "ipa3_force_close_coal", 12814);
        v20 = ipa3_ctx;
      }
      result = *(_QWORD *)(v20 + 34160);
      if ( result )
        result = ipc_log_string(result, "ipa %s:%d ipa3_send_cmd_timeout timedout\n", "ipa3_force_close_coal", 12814);
    }
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
