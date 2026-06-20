__int64 __fastcall ipa3_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  size_t v3; // x19
  size_t v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  unsigned __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x0
  __int64 v12; // x0
  size_t v13; // x0
  size_t v14; // x2
  size_t v15; // x0
  size_t v16; // x0
  size_t v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x9
  const char *v23; // x1
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  char string[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v30; // [xsp+10h] [xbp-20h]
  __int64 v31; // [xsp+18h] [xbp-18h]
  __int64 v32; // [xsp+20h] [xbp-10h]
  __int64 v33; // [xsp+28h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v32 = 0;
  *(_QWORD *)string = 0;
  v30 = 0;
  if ( a3 > 0x1F )
  {
LABEL_2:
    v3 = -14;
LABEL_3:
    _ReadStatusReg(SP_EL0);
    return v3;
  }
  v3 = a3;
  _check_object_size(string, a3, 0);
  v6 = inline_copy_from_user((__int64)string, a2, v3);
  if ( v6 )
  {
    printk(&unk_3B1B58, "ipa3_write");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d Unable to copy data from user\n", "ipa3_write", 8689);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(v20, "ipa %s:%d Unable to copy data from user\n", "ipa3_write", 8689);
    }
    goto LABEL_2;
  }
  if ( v3 )
    string[v3] = 0;
  v7 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d user input string %s\n", "ipa3_write", 8696, string);
      v7 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v7 + 34160);
    if ( v6 )
      v6 = ipc_log_string(v6, "ipa %s:%d user input string %s\n", "ipa3_write", 8696, string);
  }
  v9 = 0;
  if ( v3 )
  {
    while ( 1 )
    {
      if ( v9 > 0x1F )
        __break(1u);
      if ( (*((_BYTE *)&ctype + (unsigned __int8)string[v9]) & 0x20) == 0 )
        break;
      if ( (int)++v9 >= v3 )
      {
        v9 = (int)v9;
        break;
      }
    }
  }
  v10 = ipa3_ctx;
  if ( v9 == v3 )
  {
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d Empty ipa_config file\n", "ipa3_write", 8705);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d Empty ipa_config file\n", "ipa3_write", 8705);
    }
    goto LABEL_3;
  }
  if ( *(_DWORD *)(ipa3_ctx + 32256) )
  {
    if ( (ipa_is_ready(v6) & 1) != 0 )
      goto LABEL_3;
LABEL_25:
    ipa_fw_load_sm_handle_event(0);
    goto LABEL_3;
  }
  v13 = strnlen(string, 0x20u);
  v14 = v13;
  if ( v13 >= 0x21 )
    goto LABEL_67;
  if ( v13 == 32 )
    goto LABEL_68;
  if ( !strnstr(string, "vlan", v13) )
  {
    if ( v3 && string[v3 - 1] == 10 )
      string[v3 - 1] = 0;
    if ( !strcasecmp(string, "MHI") )
    {
      v21 = ipa3_ctx;
      v22 = 32260;
    }
    else
    {
      if ( *(_DWORD *)string != 5456452 )
      {
        if ( *(unsigned __int16 *)string != 49 )
        {
          printk(&unk_3C956D, "ipa3_write");
          v25 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v26 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v26 )
            {
              ipc_log_string(v26, "ipa %s:%d got invalid string %s not loading FW\n", "ipa3_write", 8757, string);
              v25 = ipa3_ctx;
            }
            v27 = *(_QWORD *)(v25 + 34160);
            if ( v27 )
              ipc_log_string(v27, "ipa %s:%d got invalid string %s not loading FW\n", "ipa3_write", 8757, string);
          }
          goto LABEL_3;
        }
        v21 = ipa3_ctx;
LABEL_54:
        if ( *(_BYTE *)(v21 + 32260) )
          v23 = (const char *)&unk_3B7A49;
        else
          v23 = "non ";
        v24 = printk(&unk_3BAA49, v23);
        if ( (ipa_is_ready(v24) & 1) != 0 )
          goto LABEL_3;
        goto LABEL_25;
      }
      v21 = ipa3_ctx;
      v22 = 50152;
    }
    *(_BYTE *)(v21 + v22) = 1;
    goto LABEL_54;
  }
  v15 = strnlen(string, 0x20u);
  v14 = v15;
  if ( v15 >= 0x21 )
    goto LABEL_67;
  if ( v15 == 32 )
    goto LABEL_68;
  if ( strnstr(string, "eth", v15) )
    *(_BYTE *)(ipa3_ctx + 44848) = 1;
  v16 = strnlen(string, 0x20u);
  v14 = v16;
  if ( v16 >= 0x21 )
    goto LABEL_67;
  if ( v16 == 32 )
    goto LABEL_68;
  if ( strnstr(string, "rndis", v16) )
    *(_BYTE *)(ipa3_ctx + 44851) = 1;
  v17 = strnlen(string, 0x20u);
  v14 = v17;
  if ( v17 >= 0x21 )
  {
LABEL_67:
    _fortify_panic(2, 32, v14 + 1);
    goto LABEL_68;
  }
  if ( v17 != 32 )
  {
    if ( strnstr(string, "ecm", v17) )
      *(_BYTE *)(ipa3_ctx + 44852) = 1;
    goto LABEL_3;
  }
LABEL_68:
  v28 = _fortify_panic(4, 32, 33);
  return ipa3_open(v28);
}
