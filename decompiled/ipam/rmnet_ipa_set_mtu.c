__int64 __fastcall rmnet_ipa_set_mtu(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // x27
  size_t v4; // x19
  char *v7; // x0
  char *v8; // x20
  size_t v9; // x0
  unsigned __int64 v10; // x2
  char *v11; // x0
  char *v12; // x0
  __int64 v13; // x0
  char *stringp; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int16 v15[2]; // [xsp+10h] [xbp-20h] BYREF
  unsigned __int16 v16; // [xsp+14h] [xbp-1Ch] BYREF
  _QWORD v17[3]; // [xsp+18h] [xbp-18h] BYREF

  v17[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v15[0] = 0;
  if ( a3 > 0xFFF
    || (v4 = a3, _check_object_size(dbg_buff_2, a3, 0), inline_copy_from_user_2((__int64)dbg_buff_2, a2, v4)) )
  {
    v4 = -14;
LABEL_4:
    _ReadStatusReg(SP_EL0);
    return v4;
  }
  dbg_buff_2[v4] = 0;
  stringp = dbg_buff_2;
  v17[0] = 0;
  v17[1] = 0;
  v7 = strsep(&stringp, " ");
  if ( !v7 )
  {
LABEL_13:
    v4 = -22;
    goto LABEL_4;
  }
  v8 = v7;
  v9 = strnlen(v7, 0x10u);
  if ( v9 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v9 == 16 )
      v10 = 16;
    else
      v10 = v9 + 1;
    if ( v10 < 0x11 )
    {
      sized_strscpy(v17, v8);
      v11 = strsep(&stringp, " ");
      if ( v11 )
      {
        if ( !(unsigned int)kstrtou16(v11, 0, &v16) )
        {
          v12 = strsep(&stringp, " ");
          if ( v12 )
          {
            if ( !(unsigned int)kstrtou16(v12, 0, v15) )
            {
              rmnet_ipa_send_set_mtu_notification((const char *)v17, v16, v15[0], 2);
              goto LABEL_4;
            }
          }
        }
      }
      goto LABEL_13;
    }
  }
  v13 = _fortify_panic(7, 16, v10);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v3);
  return ipa3_lcl_mdm_ssr_notifier_cb(v13);
}
