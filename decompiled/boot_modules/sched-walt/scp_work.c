__int64 __fastcall scp_work(__int64 a1, __int64 a2)
{
  unsigned int *v2; // x19
  __int64 result; // x0
  __int64 v4; // x21
  __int64 vpid; // x0
  char *pid_task; // x0
  char *v7; // x20
  _DWORD *v8; // x27
  int v9; // w9
  int v10; // w8
  int v11; // w8
  unsigned int v12; // w8
  unsigned int *v13; // x28
  int v14; // w8
  __int64 v15; // x21
  const char *v16; // x22
  __int64 v17; // x8
  int v18; // w28
  __int64 v19; // x22
  const char *v20; // x23
  __int64 v21; // x8
  size_t v22; // x2
  size_t v23; // x26
  size_t v24; // x0
  _BOOL4 v25; // w26
  int v26; // w9
  __int64 v27; // x8
  __int64 v28; // x1
  size_t v30; // x2
  int v36; // w8
  int v37; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v38; // [xsp+18h] [xbp-8h]

  v2 = (unsigned int *)(a1 - 8);
  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  result = sched_clock(a1, a2);
  if ( v2 )
  {
    v4 = result;
    mutex_lock(&scp_data_lock);
    vpid = find_vpid(*v2);
    pid_task = (char *)get_pid_task(vpid, 0);
    if ( !pid_task )
    {
      if ( byte_6A5A8 == 1 )
        printk(&unk_64772);
      goto LABEL_105;
    }
    v7 = pid_task;
    if ( pid_task == (char *)&init_task )
      v8 = &vendor_data_pad;
    else
      v8 = pid_task + 5184;
    if ( !v8 )
      goto LABEL_93;
    if ( byte_6A5A8 == 1 )
      printk(&unk_649AF);
    v9 = scp_udata;
    if ( !scp_udata )
    {
      v12 = v8[120];
LABEL_24:
      if ( (v12 | 2) == 3 )
      {
        v13 = v8 + 120;
        v8[120] = 3;
        goto LABEL_87;
      }
LABEL_26:
      v13 = v8 + 120;
      if ( v12 > 1 )
      {
LABEL_86:
        if ( v12 == 3 )
        {
LABEL_87:
          if ( *((int *)v7 + 38) < 100 || *((int *)v7 + 39) < 100 )
            goto LABEL_93;
          if ( (unsigned int)(*((_DWORD *)v7 + 338) - 3) >= 0xFFFFFFFE )
            printk(&unk_66DF9);
          v17 = 0;
          *v13 = 0;
          goto LABEL_92;
        }
        goto LABEL_93;
      }
      if ( v12 )
      {
        if ( (byte_6A5A8 & 1) == 0 )
        {
LABEL_29:
          if ( *((_QWORD *)v7 + 197) <= (unsigned __int64)(v4 - qword_6A598)
            || *((_QWORD *)v7 + 36) <= (unsigned __int64)qword_6A598 )
          {
            if ( byte_6A5A8 == 1 )
              printk(&unk_6542C);
            v17 = qword_6A5A0;
            *v13 = 2;
LABEL_92:
            *((_QWORD *)v8 + 61) = v17;
            goto LABEL_93;
          }
          v12 = *v13;
          if ( *v13 == 1 )
          {
            if ( (unsigned int)(*((_DWORD *)v7 + 338) - 3) <= 0xFFFFFFFD )
            {
              v14 = (unsigned __int8)byte_6A5A8;
              v8[121] = *((_DWORD *)v7 + 38);
              if ( v14 == 1 )
                printk(&unk_67205);
              if ( dword_6A4A4 >= 1 )
              {
                v15 = 0;
                v16 = (const char *)&unk_6A4BC;
                while ( 1 )
                {
                  v23 = strnlen(v7 + 2320, 0x10u);
                  if ( v23 >= 0x11 )
                    break;
                  if ( v15 == 10 )
                    goto LABEL_97;
                  v24 = strnlen(v16 - 20, 0x10u);
                  if ( v24 >= 0x11 )
                    goto LABEL_96;
                  if ( v23 >= v24 )
                  {
                    v22 = strnlen(v7 + 2320, 0x10u);
                    if ( v22 >= 0x11 )
                      goto LABEL_98;
                    if ( !strnstr(v7 + 2320, v16 - 20, v22) )
                      goto LABEL_67;
                    v23 = strnlen(v7 + 2320, 0x10u);
                    if ( v23 >= 0x11 )
                      break;
                    v24 = strnlen(v16 - 20, 0x10u);
                    if ( v24 >= 0x11 )
                      goto LABEL_96;
                    if ( v23 == v24 )
                    {
                      v28 = *((unsigned int *)v16 - 1);
                      v37 = *(_DWORD *)v16;
                      if ( (unsigned int)sched_setscheduler_nocheck(v7, v28, &v37) )
                        __break(0x800u);
                      if ( (unsigned int)(*((_DWORD *)v7 + 338) - 3) <= 0xFFFFFFFD )
                      {
                        printk(&unk_617D0);
                      }
                      else if ( byte_6A5A8 == 1 )
                      {
                        printk(&unk_62DEF);
                      }
                    }
                    else
                    {
LABEL_67:
                      if ( byte_6A5A8 == 1 )
                        printk(&unk_66DB2);
                    }
                  }
                  ++v15;
                  v16 += 24;
                  if ( v15 >= dword_6A4A4 )
                    goto LABEL_85;
                }
LABEL_95:
                v30 = v23 + 1;
LABEL_99:
                _X0 = (unsigned int *)_fortify_panic(2, 16, v30);
                goto LABEL_100;
              }
            }
LABEL_85:
            v12 = *v13;
          }
          goto LABEL_86;
        }
      }
      else
      {
        if ( (byte_6A5A8 & 1) != 0 )
          printk(&unk_676DA);
        v18 = dword_6A4A4;
        if ( dword_6A4A4 >= 1 )
        {
          v19 = 0;
          v20 = (const char *)&unk_6A4A8;
          do
          {
            v23 = strnlen(v7 + 2320, 0x10u);
            if ( v23 >= 0x11 )
              goto LABEL_95;
            if ( v19 == 10 )
            {
LABEL_97:
              __break(0x5512u);
LABEL_98:
              v30 = v22 + 1;
              goto LABEL_99;
            }
            v24 = strnlen(v20, 0x10u);
            if ( v24 >= 0x11 )
              goto LABEL_96;
            if ( v23 < v24 )
            {
              v8[120] = 2;
              v21 = qword_6A5A0;
            }
            else
            {
              if ( byte_6A5A8 == 1 )
                printk(&unk_624BF);
              v22 = strnlen(v7 + 2320, 0x10u);
              if ( v22 >= 0x11 )
                goto LABEL_98;
              if ( strnstr(v7 + 2320, v20, v22) )
              {
                v23 = strnlen(v7 + 2320, 0x10u);
                if ( v23 >= 0x11 )
                  goto LABEL_95;
                v24 = strnlen(v20, 0x10u);
                if ( v24 >= 0x11 )
                {
LABEL_96:
                  v30 = v24 + 1;
                  goto LABEL_99;
                }
                v25 = v23 == v24;
              }
              else
              {
                v25 = 0;
              }
              if ( byte_6A5A8 == 1 )
              {
                printk(&unk_61CCF);
                if ( v25 )
                {
LABEL_62:
                  v13 = v8 + 120;
                  v26 = (unsigned __int8)byte_6A5A8;
                  v27 = qword_6A5A0;
                  v8[120] = 1;
                  *((_QWORD *)v8 + 61) = v27;
                  if ( v26 != 1 )
                    goto LABEL_65;
                  printk(&unk_617A2);
                  break;
                }
              }
              else if ( v25 )
              {
                goto LABEL_62;
              }
              v21 = qword_6A5A0;
              v18 = dword_6A4A4;
              v8[120] = 2;
            }
            ++v19;
            v20 += 24;
            *((_QWORD *)v8 + 61) = v21;
          }
          while ( v19 < v18 );
        }
        v13 = v8 + 120;
        if ( v8[120] == 2 )
        {
LABEL_93:
          _X0 = (unsigned int *)(v7 + 64);
LABEL_100:
          __asm { PRFM            #0x11, [X0] }
          do
            v36 = __ldxr(_X0);
          while ( __stlxr(v36 - 1, _X0) );
          if ( v36 == 1 )
          {
            __dmb(9u);
            _put_task_struct(v7);
          }
          else if ( v36 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
LABEL_105:
          mutex_unlock(&scp_data_lock);
          result = kfree(v2);
          goto LABEL_106;
        }
LABEL_65:
        if ( (byte_6A5A8 & 1) == 0 )
          goto LABEL_29;
      }
      printk(&unk_624EE);
      goto LABEL_29;
    }
    if ( scp_udata == *((_DWORD *)v7 + 451) && (!qword_6A5A0 || qword_6A5A0 != *((_QWORD *)v8 + 61)) )
    {
      v10 = v8[120];
      if ( v10 == 1 )
      {
        v11 = 3;
      }
      else
      {
        if ( v10 != 2 )
          goto LABEL_23;
        v11 = 0;
      }
      v8[120] = v11;
    }
LABEL_23:
    v12 = v8[120];
    if ( v9 == *((_DWORD *)v7 + 451) )
      goto LABEL_26;
    goto LABEL_24;
  }
  if ( byte_6A5A8 == 1 )
    result = printk(&unk_6509F);
LABEL_106:
  _ReadStatusReg(SP_EL0);
  return result;
}
