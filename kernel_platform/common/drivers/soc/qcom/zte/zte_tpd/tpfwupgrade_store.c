__int64 __fastcall tpfwupgrade_store(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x1
  __int64 v11; // x2
  _QWORD *v12; // x8
  __int64 v13; // x9
  _DWORD *v14; // x8
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = tpd_cdev;
  v15 = 0;
  if ( (unsigned int)kstrtouint_from_user(a2, a3, 10, &v15) )
  {
    v3 = -22;
  }
  else
  {
    printk(unk_328A8, "tpfwupgrade_store", v15);
    mutex_lock(v4 + 2728);
    v6 = *(_QWORD *)(v4 + 2720);
    if ( v15 < 0xB )
    {
      if ( v6 )
      {
        v14 = *(_DWORD **)(v4 + 3168);
        if ( v14 )
        {
          if ( *(v14 - 1) != 1299599524 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, _QWORD))v14)(v4, 0, 0);
          v6 = *(_QWORD *)(v4 + 2720);
        }
        if ( *(_QWORD *)(v6 + 8) )
        {
          vfree(*(_QWORD *)(v6 + 8));
          *(_QWORD *)(*(_QWORD *)(v4 + 2720) + 8LL) = 0;
          v6 = *(_QWORD *)(v4 + 2720);
        }
        kfree(v6);
        *(_QWORD *)(v4 + 2720) = 0;
        *(_DWORD *)(v4 + 1096) = 0;
      }
    }
    else
    {
      if ( v6 )
      {
        if ( *(_QWORD *)(v6 + 8) )
        {
          vfree(*(_QWORD *)(v6 + 8));
          v6 = *(_QWORD *)(v4 + 2720);
        }
        kfree(v6);
      }
      *(_DWORD *)(v4 + 1096) = 0;
      v7 = _kmalloc_cache_noprof(remove_proc_entry, 3520, 24);
      *(_QWORD *)(v4 + 2720) = v7;
      if ( v7 )
      {
        *(_QWORD *)(*(_QWORD *)(v4 + 2720) + 8LL) = vmalloc_noprof(v15 + 24LL);
        v12 = *(_QWORD **)(v4 + 2720);
        if ( v12[1] )
        {
          v13 = v15;
          *v12 = v15;
          memset(*(void **)(*(_QWORD *)(v4 + 2720) + 8LL), 0, v13 + 24);
        }
        else
        {
          printk(unk_3B60C, v10, v11);
          kfree(*(_QWORD *)(v4 + 2720));
          v3 = -12;
        }
      }
      else
      {
        printk(unk_3224B, v8, v9);
        v3 = -12;
      }
    }
    mutex_unlock(v4 + 2728);
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
