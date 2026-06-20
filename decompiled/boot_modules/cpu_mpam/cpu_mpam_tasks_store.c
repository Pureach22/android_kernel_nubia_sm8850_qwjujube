__int64 __fastcall cpu_mpam_tasks_store(__int64 a1, char *a2, __int64 a3)
{
  int v4; // w22
  char *v5; // x0
  _QWORD *task_by_vpid; // x0
  _BYTE *v7; // x8
  char *stringp; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v10; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 136);
  stringp = a2;
  v10 = 0;
  v5 = strsep(&stringp, " ");
  if ( v5 )
  {
    while ( (kstrtouint(v5, 10, &v10) & 0x80000000) == 0 )
    {
      task_by_vpid = (_QWORD *)find_task_by_vpid(v10);
      if ( task_by_vpid && (unsigned __int64)task_by_vpid < 0xFFFFFFFFFFFFF001LL )
      {
        v7 = task_by_vpid + 648;
        if ( task_by_vpid == init_task )
          v7 = &vendor_data_pad;
        v7[385] = v4;
      }
      else
      {
        printk(&unk_8068);
      }
      v5 = strsep(&stringp, " ");
      if ( !v5 )
        goto LABEL_12;
    }
    printk(&unk_7F06);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return a3;
}
