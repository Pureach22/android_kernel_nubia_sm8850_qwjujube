__int64 __fastcall dload_mode_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  char v6; // w0
  unsigned int v7; // w21
  __int64 v8; // x0
  char v9; // w20
  __int64 v10; // x1
  __int64 v11; // x1
  bool v12; // zf
  __int64 v13; // x1
  __int64 result; // x0
  int v15; // w20
  int *v16; // x8
  __int64 v17; // x1
  __int64 v18; // x21
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = sysfs_streq(a3, "full");
  if ( (v6 & 1) != 0 )
  {
    if ( enable_dump )
    {
      v7 = 16;
      v8 = 16;
      v19 = 0;
      goto LABEL_12;
    }
    v7 = 16;
  }
  else
  {
    v9 = v6;
    if ( (sysfs_streq(a3, "mini") & 1) != 0 )
    {
      v7 = 32;
    }
    else
    {
      if ( (sysfs_streq(a3, "both") & 1) == 0 )
      {
        printk(&unk_6F48, v10);
        printk(&unk_6FB7, v17);
        result = -22;
        goto LABEL_21;
      }
      v7 = 48;
    }
    if ( enable_dump )
    {
      v19 = 0;
      if ( (v9 & 1) != 0 || (msm_minidump_enabled() & 1) != 0 )
      {
        v8 = v7;
      }
      else
      {
        printk(&unk_71F8, v11);
        if ( (v7 & 0x10) == 0 )
        {
          v15 = 0;
          result = -19;
          if ( dump_mode == v7 )
            goto LABEL_16;
LABEL_25:
          v18 = result;
          printk(&unk_719E, v13);
          result = v18;
          if ( !v15 )
            goto LABEL_21;
          goto LABEL_20;
        }
        v8 = v7 & 0x10;
      }
LABEL_12:
      current_download_mode = v8;
      qcom_scm_set_download_mode(v8);
      v12 = (unsigned int)qcom_scm_get_download_mode(&v19) == 0;
      result = 0;
      v15 = 1;
      if ( v12 )
        v16 = &v19;
      else
        v16 = &dump_mode;
      dump_mode = *v16;
      if ( dump_mode == v7 )
      {
LABEL_16:
        if ( !v15 )
          goto LABEL_21;
        goto LABEL_20;
      }
      goto LABEL_25;
    }
  }
  dump_mode = v7;
LABEL_20:
  result = a4;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
