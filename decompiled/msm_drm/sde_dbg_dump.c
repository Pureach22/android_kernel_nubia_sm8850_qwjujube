__int64 __fastcall sde_dbg_dump(
        int a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  __int64 result; // x0
  char v13; // w25
  int v14; // w26
  const char **v15; // x28
  unsigned int v16; // w8
  unsigned int v17; // w23
  const char **v18; // x20
  const char *v19; // x24
  const char **v20; // x9
  int v21; // w0
  char v22; // w20
  __int64 v23; // [xsp+0h] [xbp-60h]
  char v24; // [xsp+Ch] [xbp-54h]
  char *v25; // [xsp+38h] [xbp-28h] BYREF
  char **v26; // [xsp+40h] [xbp-20h]
  __int64 v27; // [xsp+48h] [xbp-18h]
  __int64 v28; // [xsp+50h] [xbp-10h]
  __int64 v29; // [xsp+58h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v25 = nullptr;
  v26 = nullptr;
  result = sde_evtlog_is_enabled(sde_dbg_base, 0xFFFFFFFFLL);
  if ( (result & 1) != 0 && (a1 != 1 || (qword_294358 & 1) == 0) && (word_294380 & 1) == 0 )
  {
    v13 = 0;
    v14 = 0;
    dword_2945D8 = a1;
    v15 = (const char **)&a9;
    v16 = -40;
    v23 = a2;
    v24 = 0;
    v25 = &a9;
    v26 = &v25;
    v28 = 4294967256LL;
LABEL_7:
    v17 = v16 + 8;
    LODWORD(v28) = v16 + 8;
    if ( v16 <= 0xFFFFFFF8 )
    {
      v18 = v15;
      v15 = (const char **)((char *)&v25 + (int)v16);
      goto LABEL_10;
    }
    while ( 1 )
    {
      v18 = v15 + 1;
      v25 = (char *)(v15 + 1);
LABEL_10:
      v19 = *v15;
      if ( !*v15 )
      {
        v22 = v24;
        goto LABEL_26;
      }
      if ( v14 == 15 )
        break;
      ++v14;
      if ( !strcmp(*v15, "panic") )
      {
        while ( 1 )
        {
          if ( (v17 & 0x80000000) != 0 )
          {
            LODWORD(v28) = v17 + 8;
            if ( v17 <= 0xFFFFFFF8 )
            {
              v20 = (const char **)((char *)&v25 + (int)v17);
              v15 = v18;
              v17 += 8;
              v19 = *v20;
              if ( !*v20 )
                goto LABEL_25;
              goto LABEL_20;
            }
            v17 += 8;
          }
          v15 = v18 + 1;
          v25 = (char *)(v18 + 1);
          v19 = *v18;
          if ( !*v18 )
          {
LABEL_25:
            v22 = 1;
            goto LABEL_26;
          }
LABEL_20:
          if ( v14 == 15 )
          {
            v22 = 1;
            goto LABEL_33;
          }
          ++v14;
          v18 = v15;
          if ( strcmp(v19, "panic") )
          {
            v24 = 1;
            goto LABEL_23;
          }
        }
      }
      v15 = v18;
LABEL_23:
      v21 = strcmp(v19, "secure");
      v16 = v17;
      v13 |= v21 == 0;
      if ( (v17 & 0x80000000) != 0 )
        goto LABEL_7;
    }
    v22 = v24;
LABEL_33:
    printk(&unk_25B6AB, "sde_dbg_dump");
LABEL_26:
    if ( a1 == 1 )
    {
      byte_294378 = v22 & 1;
      qword_294598 = a3;
      result = queue_work_on(32, system_wq, &qword_294358);
    }
    else
    {
      result = sde_dump_array(v22 & 1, v23, v13 & 1, a3);
      if ( (dword_29437C & 8) != 0 )
      {
        result = dev_coredumpm_timeout(
                   qword_2942C8,
                   &_this_module,
                   &sde_dbg_base,
                   0,
                   3264,
                   sde_devcoredump_read,
                   sde_devcoredump_free,
                   75000);
        LOBYTE(word_294380) = 1;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
