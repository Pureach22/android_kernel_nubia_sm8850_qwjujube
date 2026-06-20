__int64 __fastcall hung_task_handler(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int16 v9; // w9
  unsigned int v10; // w19
  __int64 vpid; // x0
  char *pid_task; // x0
  _BYTE *v13; // x8
  char v14; // w9
  __int64 v15; // x0
  unsigned __int8 *v16; // x0
  unsigned __int8 *v17; // x8
  unsigned __int8 *v18; // x22
  int v25; // w9
  _QWORD v27[2]; // [xsp+8h] [xbp-48h] BYREF
  int v28; // [xsp+18h] [xbp-38h]
  __int16 v29; // [xsp+1Ch] [xbp-34h]
  __int16 v30; // [xsp+1Eh] [xbp-32h]
  __int64 v31; // [xsp+20h] [xbp-30h]
  __int64 v32; // [xsp+28h] [xbp-28h]
  __int64 v33; // [xsp+30h] [xbp-20h]
  __int64 v34; // [xsp+38h] [xbp-18h]
  _QWORD v35[2]; // [xsp+40h] [xbp-10h] BYREF

  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35[0] = -1;
  v9 = *(_WORD *)(a1 + 20);
  v27[1] = v35;
  v30 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v27[0] = 0;
  v28 = 8;
  v29 = v9;
  mutex_lock(&readpid_mutex);
  if ( a2 )
  {
    v10 = proc_dointvec(v27, a2, a3, a4, a5);
    if ( v10 )
      goto LABEL_26;
    v10 = -2;
    if ( SLODWORD(v35[0]) < 1 )
      goto LABEL_26;
    if ( HIDWORD(v35[0]) > 1 )
      goto LABEL_26;
    vpid = find_vpid(LODWORD(v35[0]));
    pid_task = (char *)get_pid_task(vpid, 0);
    if ( !pid_task )
      goto LABEL_26;
    if ( pid_task == (char *)&init_task )
      v13 = &vendor_data_pad;
    else
      v13 = pid_task + 5184;
    if ( HIDWORD(v35[0]) == 1 )
    {
      if ( dword_65C4 )
        v14 = 2;
      else
        v14 = 1;
      v10 = 0;
      v13[361] = v14;
    }
    else
    {
      v10 = 0;
      v13[361] = 0;
    }
  }
  else
  {
    v15 = find_vpid((unsigned int)hung_task_enh);
    v16 = (unsigned __int8 *)get_pid_task(v15, 0);
    if ( !v16 )
    {
      v10 = -2;
      goto LABEL_26;
    }
    v17 = v16 + 5184;
    v18 = v16;
    if ( v16 == (unsigned __int8 *)&init_task )
      v17 = (unsigned __int8 *)&vendor_data_pad;
    v35[0] = __PAIR64__(v17[361], hung_task_enh);
    v10 = proc_dointvec(v27, 0, a3, a4, a5);
    pid_task = (char *)v18;
  }
  _X8 = (unsigned int *)(pid_task + 64);
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stlxr(v25 - 1, _X8) );
  if ( v25 == 1 )
  {
    __dmb(9u);
    _put_task_struct();
  }
  else if ( v25 <= 0 )
  {
    refcount_warn_saturate(pid_task + 64, 3);
  }
LABEL_26:
  mutex_unlock(&readpid_mutex);
  _ReadStatusReg(SP_EL0);
  return v10;
}
