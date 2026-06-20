size_t __fastcall ipa3_write_holb_monitor_client(__int64 a1, int a2, unsigned __int64 a3)
{
  size_t v3; // x19
  char *v6; // x0
  char *v7; // x0
  char *v8; // x0
  char *v9; // [xsp+0h] [xbp-130h] BYREF
  _BYTE v10[4]; // [xsp+Ch] [xbp-124h] BYREF
  _WORD v11[2]; // [xsp+10h] [xbp-120h] BYREF
  int v12; // [xsp+14h] [xbp-11Ch] BYREF
  _WORD v13[2]; // [xsp+18h] [xbp-118h] BYREF
  int v14; // [xsp+1Ch] [xbp-114h]
  int v15; // [xsp+20h] [xbp-110h]
  char v16; // [xsp+24h] [xbp-10Ch]
  bool v17; // [xsp+25h] [xbp-10Bh]
  _BYTE v18[258]; // [xsp+26h] [xbp-10Ah] BYREF
  __int64 v19; // [xsp+128h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 > 0x1000
    || (v3 = a3, v12 = 0, v11[0] = 0, v10[0] = 0, _check_object_size(dbg_buff, a3, 0), inline_copy_from_user_0(a2, v3)) )
  {
    v3 = -14;
  }
  else
  {
    dbg_buff[v3] = 0;
    v9 = dbg_buff;
    v6 = strsep(&v9, " ");
    if ( !v6
      || (unsigned int)kstrtou16(v6, 0, v11)
      || (v7 = strsep(&v9, " ")) == nullptr
      || (unsigned int)kstrtouint(v7, 0, &v12)
      || (v8 = strsep(&v9, " ")) == nullptr
      || (unsigned int)kstrtou8(v8, 0, v10) )
    {
      v3 = -22;
    }
    else
    {
      v13[0] = v11[0];
      v13[1] = 0;
      v14 = 3;
      v15 = v12;
      v16 = 0;
      v17 = v10[0] != 0;
      memset(v18, 0, sizeof(v18));
      ipa3_set_holb_client_by_ch(v13);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
