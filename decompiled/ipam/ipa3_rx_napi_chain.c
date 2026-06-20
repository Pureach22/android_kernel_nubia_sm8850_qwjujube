__int64 __fastcall ipa3_rx_napi_chain(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x26
  int v4; // w27
  __int64 v6; // x19
  _UNKNOWN **v8; // x22
  __int64 v9; // x25
  __int64 v10; // x28
  int v11; // w23
  __int64 v12; // x25
  int v13; // w23
  _UNKNOWN **v14; // x24
  void (*v15)(void); // x8
  __int64 ep_mapping; // x0
  void (*v17)(void); // x8
  __int64 (__fastcall *v18)(_QWORD); // x8
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  _DWORD *v22; // x8
  __int64 v23; // [xsp+0h] [xbp-10h]

  v6 = result;
  if ( *(_DWORD *)(*(_QWORD *)(result + 1624) + 4LL) == 95 )
  {
    v8 = &off_1F7000;
    if ( (*(_BYTE *)(ipa3_ctx + 45386) & 1) != 0 )
    {
      if ( !a3 )
        return result;
      v9 = 0;
      v10 = 0;
      v8 = nullptr;
      v11 = 0;
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        result = handle_page_completion(a2 + 24LL * v11);
        if ( result )
          break;
LABEL_39:
        if ( a3 == ++v11 )
          goto LABEL_49;
      }
      if ( v8 )
      {
        if ( v9 )
        {
          if ( !v10 )
            goto LABEL_48;
        }
        else
        {
          v9 = result;
          v10 = (__int64)v8[27] + *((unsigned int *)v8 + 53) + 8;
        }
        *(_QWORD *)v10 = result;
      }
      else
      {
        v8 = (_UNKNOWN **)result;
      }
LABEL_48:
      v10 = result;
      goto LABEL_39;
    }
    if ( !a3 )
      return result;
    v13 = 0;
    v14 = (_UNKNOWN **)&_ksymtab_ipa3_add_rt_rule_after_v2;
    v12 = 480;
    while ( 1 )
    {
      result = handle_skb_completion(a2 + 24LL * v13, 0, 0);
      if ( result )
        break;
LABEL_9:
      if ( a3 == ++v13 )
        return result;
    }
    v15 = *(void (**)(void))(v6 + 128);
    if ( *((_DWORD *)v15 - 1) != 2117430862 )
      __break(0x8228u);
    v15();
    ep_mapping = ipa_get_ep_mapping(35);
    if ( (_DWORD)ep_mapping == -1 )
    {
      result = printk(&unk_3AC96C, "ipa3_rx_napi_chain");
      v19 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v20 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v20 )
        {
          ipc_log_string(v20, "ipa %s:%d Invalid client.\n", "ipa3_rx_napi_chain", 5663);
          v19 = ipa3_ctx;
        }
        result = *(_QWORD *)(v19 + 34160);
        if ( result )
          return ipc_log_string(result, "ipa %s:%d Invalid client.\n", "ipa3_rx_napi_chain", 5663);
      }
      return result;
    }
    if ( (unsigned int)ep_mapping < 0x24 )
    {
      v17 = *(void (**)(void))(*(_QWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 640) + 360LL);
      if ( *((_DWORD *)v17 - 1) != 1136933575 )
        __break(0x8228u);
      v17();
      v18 = *(__int64 (__fastcall **)(_QWORD))(v6 + 360);
      if ( *((_DWORD *)v18 - 1) != 1136933575 )
        __break(0x8228u);
      result = v18(v6);
      goto LABEL_9;
    }
    __break(0x5512u);
    result = preempt_schedule_notrace(ep_mapping);
    v10 = v23;
    while ( 1 )
    {
      while ( 1 )
      {
        if ( a3 == ++v13 )
        {
LABEL_49:
          if ( v10 )
          {
            *(_QWORD *)(*(_QWORD *)(v10 + 216) + *(unsigned int *)(v10 + 212) + 8LL) = 0;
            v22 = *(_DWORD **)(v6 + 128);
            if ( *(v22 - 1) != 2117430862 )
              __break(0x8228u);
            return ((__int64 (__fastcall *)(_UNKNOWN **, __int64))v22)(v8, v6);
          }
          return result;
        }
LABEL_27:
        v21 = a2 + v13 * (__int64)v4;
        if ( (*((_BYTE *)v14[257] + v3) & 1) == 0 )
          break;
        result = handle_page_completion(v21);
        if ( result )
          goto LABEL_31;
      }
      result = handle_skb_completion(v21, 0, 0);
      if ( result )
      {
LABEL_31:
        if ( !v8 )
        {
          v8 = (_UNKNOWN **)result;
          goto LABEL_38;
        }
        if ( !v12 )
        {
          v12 = result;
          v10 = (__int64)v8[27] + *((unsigned int *)v8 + 53) + 8;
LABEL_37:
          *(_QWORD *)v10 = result;
          goto LABEL_38;
        }
        if ( v10 )
          goto LABEL_37;
LABEL_38:
        v10 = result;
      }
    }
  }
  if ( a3 )
  {
    v12 = 0;
    v10 = 0;
    v8 = nullptr;
    v13 = 0;
    v14 = &off_1F7000;
    v3 = 45386;
    v4 = 24;
    _ReadStatusReg(SP_EL0);
    goto LABEL_27;
  }
  return result;
}
