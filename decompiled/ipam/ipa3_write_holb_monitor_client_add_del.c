size_t __fastcall ipa3_write_holb_monitor_client_add_del(__int64 a1, int a2, unsigned __int64 a3)
{
  size_t v3; // x19
  char *v6; // x0
  char *v7; // x0
  char *v8; // x0
  char *v9; // x0
  char *v10; // x0
  char *stringp; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v12[4]; // [xsp+14h] [xbp-1Ch] BYREF
  _BYTE v13[4]; // [xsp+18h] [xbp-18h] BYREF
  unsigned __int16 v14; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v15[2]; // [xsp+20h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 > 0x1000
    || (v3 = a3,
        v15[0] = 0,
        v14 = 0,
        v13[0] = 0,
        v12[0] = 0,
        _check_object_size(dbg_buff, a3, 0),
        inline_copy_from_user_0(a2, v3)) )
  {
    v3 = -14;
  }
  else
  {
    dbg_buff[v3] = 0;
    stringp = dbg_buff;
    v6 = strsep(&stringp, " ");
    if ( !v6
      || (unsigned int)kstrtou16(v6, 0, &v14)
      || (v7 = strsep(&stringp, " ")) == nullptr
      || (unsigned int)kstrtouint(v7, 0, v15)
      || (v8 = strsep(&stringp, " ")) == nullptr
      || (unsigned int)kstrtouint(v8, 0, (char *)v15 + 4)
      || (v9 = strsep(&stringp, " ")) == nullptr
      || (unsigned int)kstrtou8(v9, 0, v13)
      || (v10 = strsep(&stringp, " ")) == nullptr
      || (unsigned int)kstrtou8(v10, 0, v12) )
    {
      v3 = -22;
    }
    else if ( v12[0] )
    {
      ((void (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD))ipa3_uc_client_add_holb_monitor)(
        v14,
        LODWORD(v15[0]),
        HIDWORD(v15[0]),
        v13[0]);
    }
    else
    {
      ipa3_uc_client_del_holb_monitor(v14, v13[0]);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
