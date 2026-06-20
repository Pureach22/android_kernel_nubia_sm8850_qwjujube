size_t __fastcall ipa3_write_ep_holb(__int64 a1, int a2, unsigned __int64 a3)
{
  size_t v3; // x19
  char *v6; // x0
  char *v7; // x0
  char *v8; // x0
  char *v9; // [xsp+0h] [xbp-30h] BYREF
  unsigned int v10; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h] BYREF
  __int64 v12; // [xsp+18h] [xbp-18h] BYREF
  __int64 v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 > 0x1000
    || (v3 = a3, v12 = 0,
                 v13 = 0,
                 v11 = 0,
                 v10 = 0,
                 _check_object_size(dbg_buff, a3, 0),
                 inline_copy_from_user_0(a2, v3)) )
  {
    v3 = -14;
  }
  else
  {
    dbg_buff[v3] = 0;
    v9 = dbg_buff;
    v6 = strsep(&v9, " ");
    if ( !v6
      || (unsigned int)kstrtouint(v6, 0, &v10)
      || (v7 = strsep(&v9, " ")) == nullptr
      || (unsigned int)kstrtouint(v7, 0, (char *)&v11 + 4)
      || (v8 = strsep(&v9, " ")) == nullptr
      || (unsigned int)kstrtouint(v8, 0, &v11) )
    {
      v3 = -22;
    }
    else
    {
      WORD2(v13) = WORD2(v11);
      LODWORD(v12) = v11;
      ipa3_cfg_ep_holb(v10, &v12);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
