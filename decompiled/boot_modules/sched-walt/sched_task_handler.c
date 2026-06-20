__int64 __fastcall sched_task_handler(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int16 v10; // w8
  unsigned int v11; // w20
  __int64 v12; // x0
  char *v13; // x0
  __int64 v14; // x1
  int v15; // w22
  int v16; // w23
  char *v17; // x19
  _DWORD *v18; // x24
  __int64 vpid; // x0
  char *pid_task; // x0
  int v21; // w9
  _BYTE *v22; // x8
  unsigned __int64 v23; // x0
  int v24; // w8
  char v26; // w8
  char v27; // w8
  __int64 v28; // x0
  __int64 v29; // x25
  int v35; // w8
  _QWORD v37[2]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v38; // [xsp+28h] [xbp-48h]
  __int64 v39; // [xsp+30h] [xbp-40h]
  __int64 v40; // [xsp+38h] [xbp-38h]
  __int64 v41; // [xsp+40h] [xbp-30h]
  __int64 v42; // [xsp+48h] [xbp-28h]
  _QWORD v43[2]; // [xsp+50h] [xbp-20h] BYREF
  _QWORD v44[2]; // [xsp+60h] [xbp-10h] BYREF

  v44[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43[1] = 0;
  v44[0] = -1;
  v37[0] = 0;
  v37[1] = v44;
  v38 = 8;
  v10 = *(_WORD *)(a1 + 20);
  v43[0] = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  WORD2(v38) = v10;
  mutex_lock(&sysctl_pid_mutex);
  if ( !a2 )
  {
    vpid = find_vpid((unsigned int)sysctl_task_read_pid);
    pid_task = (char *)get_pid_task(vpid, 0);
    if ( pid_task )
    {
      v21 = *(_DWORD *)(a1 + 8);
      v17 = pid_task;
      if ( pid_task == (char *)&init_task )
        v22 = &vendor_data_pad;
      else
        v22 = pid_task + 5184;
      v11 = -22;
      LODWORD(v44[0]) = sysctl_task_read_pid;
      if ( v21 > 5 )
      {
        if ( v21 <= 7 )
        {
          if ( v21 == 6 )
            LODWORD(v23) = v22[191] & 1;
          else
            LODWORD(v23) = ((unsigned __int8)v22[191] >> 2) & 1;
        }
        else
        {
          switch ( v21 )
          {
            case 8:
              LODWORD(v23) = *((_DWORD *)v22 + 84);
              break;
            case 9:
              LODWORD(v23) = *((_DWORD *)v22 + 92);
              break;
            case 10:
              LODWORD(v23) = (unsigned __int8)v22[385];
              break;
            default:
              goto LABEL_44;
          }
        }
      }
      else if ( v21 <= 2 )
      {
        if ( v21 == 1 )
        {
          LODWORD(v23) = (unsigned __int8)v22[188];
        }
        else
        {
          if ( v21 != 2 )
            goto LABEL_44;
          LODWORD(v23) = *((_DWORD *)v22 + 54);
        }
      }
      else if ( v21 == 3 )
      {
        LODWORD(v23) = sched_get_group_id(pid_task);
      }
      else if ( v21 == 4 )
      {
        LODWORD(v23) = *((_DWORD *)v22 + 46);
      }
      else
      {
        v23 = *((_QWORD *)v22 + 24) / 0xF4240uLL;
      }
      HIDWORD(v44[0]) = v23;
      v11 = proc_dointvec(v37, 0, a3, a4, a5);
      goto LABEL_44;
    }
LABEL_20:
    v11 = -2;
    goto LABEL_82;
  }
  v11 = proc_dointvec(v37, a2, a3, a4, a5);
  if ( v11 )
    goto LABEL_82;
  if ( SLODWORD(v44[0]) < 1 )
    goto LABEL_20;
  v12 = find_vpid(LODWORD(v44[0]));
  v13 = (char *)get_pid_task(v12, 0);
  if ( !v13 )
    goto LABEL_20;
  v15 = *(_DWORD *)(a1 + 8);
  v16 = HIDWORD(v44[0]);
  v17 = v13;
  if ( v13 == (char *)&init_task )
    v18 = &vendor_data_pad;
  else
    v18 = v13 + 5184;
  if ( v15 != 8 && (v44[0] & 0x8000000000000000LL) != 0 )
  {
    v11 = -22;
    goto LABEL_44;
  }
  v11 = -22;
  if ( v15 <= 4 )
  {
    if ( v15 > 2 )
    {
      if ( v15 == 3 )
      {
        v11 = sched_set_group_id((__int64)v13, SHIDWORD(v44[0]));
      }
      else
      {
        if ( HIDWORD(v44[0]) > 3 )
          goto LABEL_44;
        v11 = 0;
        v18[46] = HIDWORD(v44[0]);
        if ( !v16 )
          *((_QWORD *)v18 + 24) = 0;
      }
    }
    else if ( v15 == 1 )
    {
      v11 = 0;
      *((_BYTE *)v18 + 188) = HIDWORD(v44[0]) != 0;
    }
    else if ( v15 == 2 )
    {
      if ( HIDWORD(v44[0]) > 0x64 )
        goto LABEL_44;
      v11 = 0;
      v18[54] = HIDWORD(v44[0]);
    }
LABEL_76:
    return_address(1);
    return_address(2);
    return_address(3);
    return_address(4);
    return_address(5);
    goto LABEL_44;
  }
  v24 = HIDWORD(v44[0]);
  if ( v15 > 6 )
  {
    if ( v15 != 7 )
    {
      if ( v15 == 8 )
      {
        if ( (unsigned int)(HIDWORD(v44[0]) - 91) < 0xFFFFFF4B )
          goto LABEL_44;
        v11 = 0;
        v18[84] = HIDWORD(v44[0]);
        if ( v16 )
          *((_QWORD *)v18 + 43) = 10LL * v24
                                + (int)(((5243 * (__int16)(24 * v16)) >> 19)
                                      + ((unsigned int)(5243 * (__int16)(24 * v16)) >> 31));
        else
          *((_QWORD *)v18 + 43) = 0;
      }
      else if ( v15 == 9 )
      {
        v11 = 0;
        *((_QWORD *)v18 + 46) = SHIDWORD(v44[0]);
        sysctl_bitmap = v16;
      }
      goto LABEL_76;
    }
    v28 = task_rq_lock(v13, v43);
    if ( *((_DWORD *)v17 + 12) == 128 )
    {
LABEL_62:
      task_rq_unlock(v28, v17, v43);
      goto LABEL_44;
    }
    v29 = v28;
    if ( v16 )
    {
      v11 = ((__int64 (__fastcall *)(_DWORD *))add_pipeline)(v18);
      if ( (v11 & 0x80000000) != 0 )
      {
        v28 = v29;
        goto LABEL_62;
      }
      *((_BYTE *)v18 + 191) |= 4u;
    }
    else
    {
      *((_BYTE *)v18 + 191) &= ~4u;
      ((void (__fastcall *)(_DWORD *))remove_pipeline)(v18);
      v11 = 0;
    }
    task_rq_unlock(v29, v17, v43);
    goto LABEL_76;
  }
  if ( v15 != 5 )
  {
    v26 = *((_BYTE *)v18 + 191);
    v11 = 0;
    if ( HIDWORD(v44[0]) )
      v27 = v26 | 1;
    else
      v27 = v26 & 0xFE;
    *((_BYTE *)v18 + 191) = v27;
    goto LABEL_76;
  }
  if ( v18[46] || !HIDWORD(v44[0]) )
  {
    *((_QWORD *)v18 + 24) = 1000000LL * SHIDWORD(v44[0]);
    v11 = 0;
    *((_QWORD *)v18 + 25) = *((_QWORD *)v18 + 24) + sched_clock(v13, v14);
    goto LABEL_76;
  }
LABEL_44:
  _X0 = (unsigned int *)(v17 + 64);
  __asm { PRFM            #0x11, [X0] }
  do
    v35 = __ldxr(_X0);
  while ( __stlxr(v35 - 1, _X0) );
  if ( v35 == 1 )
  {
    __dmb(9u);
    _put_task_struct(v17);
  }
  else if ( v35 <= 0 )
  {
    refcount_warn_saturate();
  }
LABEL_82:
  mutex_unlock(&sysctl_pid_mutex);
  _ReadStatusReg(SP_EL0);
  return v11;
}
