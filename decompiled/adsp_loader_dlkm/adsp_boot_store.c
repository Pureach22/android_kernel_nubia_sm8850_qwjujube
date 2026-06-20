__int64 __fastcall adsp_boot_store(int a1, int a2, char *s, __int64 a4)
{
  _QWORD *v5; // x8
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  if ( sscanf(s, "%du", &v7) == 1 )
  {
    if ( v7 )
    {
      if ( v7 == 1 )
        queue_work_on(32, system_wq, &adsp_ldr_work);
    }
    else
    {
      v5 = *(_QWORD **)(adsp_private + 168);
      if ( v5 && *v5 )
        rproc_shutdown();
    }
  }
  else
  {
    printk(&unk_6DAF, "adsp_boot_store");
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
