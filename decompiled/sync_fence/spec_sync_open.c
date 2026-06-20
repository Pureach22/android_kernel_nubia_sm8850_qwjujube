__int64 __fastcall spec_sync_open(__int64 a1, __int64 a2)
{
  size_t v3; // x0
  unsigned __int64 v4; // x2
  unsigned int v6; // w20
  unsigned int v13; // w9
  char string[8]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)string = 0;
  v15 = 0;
  if ( !a1 || !a2 || !*(_QWORD *)(a1 + 656) )
  {
    printk(&unk_7B1F, "spec_sync_open");
    v6 = -22;
    goto LABEL_15;
  }
  mutex_lock(&unk_7B60);
  _get_task_comm(string, 16, _ReadStatusReg(SP_EL0));
  if ( dword_7B98 <= 1 )
  {
    if ( dword_7B98 )
      goto LABEL_20;
    qword_7BAC = 0;
    qword_7BB4 = 0;
    qword_7B9C = 0;
    qword_7BA4 = 0;
    v3 = strnlen(string, 0x10u);
    if ( v3 < 0x10 || v3 == 32 )
    {
      if ( v3 == 32 )
        v4 = 32;
      else
        v4 = v3 + 1;
      if ( v4 < 0x21 )
      {
        sized_strscpy(&qword_7B9C, string);
LABEL_20:
        _X8 = &dword_7B98;
        __asm { PRFM            #0x11, [X8] }
        do
          v13 = __ldxr((unsigned int *)&dword_7B98);
        while ( __stxr(v13 + 1, (unsigned int *)&dword_7B98) );
        v6 = 0;
        *(_QWORD *)(a2 + 32) = &sync_dev;
        goto LABEL_14;
      }
    }
    else
    {
      _fortify_panic(2);
    }
    _fortify_panic(7);
    goto LABEL_20;
  }
  printk(&unk_7708, "spec_fence_init_locked");
  printk(&unk_77CF, "spec_sync_open");
  v6 = -17;
LABEL_14:
  mutex_unlock(&unk_7B60);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v6;
}
