__int64 __fastcall sde_core_irq_register_callback(__int64 a1, unsigned int a2, __int64 *a3)
{
  const void *v3; // x30
  __int64 v7; // x22
  int v8; // w7
  __int64 **v9; // x8
  __int64 v10; // x9
  __int64 v11; // x2
  __int64 *v12; // x1
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a1 && *(_QWORD *)(a1 + 1912) )
  {
    if ( a3 && a3[2] )
    {
      if ( (a2 & 0x80000000) != 0 || *(_DWORD *)(*(_QWORD *)(a1 + 1896) + 328LL) <= a2 )
      {
        printk(&unk_27D8FF, "sde_core_irq_register_callback");
        return 4294967274LL;
      }
      else
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "[%pS] irq_idx=%d\n", v3, a2);
        v7 = raw_spin_lock_irqsave(a1 + 1936);
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_core_irq_register_callback",
          295,
          -1,
          a2,
          (int)a3,
          -1059143953,
          v8,
          vars0);
        v9 = (__int64 **)a3[1];
        if ( *v9 == a3 && (v10 = *a3, *(__int64 **)(*a3 + 8) == a3) )
        {
          *(_QWORD *)(v10 + 8) = v9;
          *v9 = (__int64 *)v10;
        }
        else
        {
          _list_del_entry_valid_or_report(a3);
        }
        *a3 = (__int64)a3;
        a3[1] = (__int64)a3;
        v11 = *(_QWORD *)(a1 + 1912) + 16LL * a2;
        v12 = *(__int64 **)(v11 + 8);
        if ( (__int64 *)v11 == a3 || v12 == a3 || *v12 != v11 )
        {
          _list_add_valid_or_report(a3, v12);
        }
        else
        {
          *(_QWORD *)(v11 + 8) = a3;
          *a3 = v11;
          a3[1] = (__int64)v12;
          *v12 = (__int64)a3;
        }
        raw_spin_unlock_irqrestore(a1 + 1936, v7);
        return 0;
      }
    }
    else
    {
      printk(&unk_227618, "sde_core_irq_register_callback");
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_223EAA, "sde_core_irq_register_callback");
    return 4294967274LL;
  }
}
