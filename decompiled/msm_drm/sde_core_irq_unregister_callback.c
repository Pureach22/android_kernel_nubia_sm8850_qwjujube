__int64 __fastcall sde_core_irq_unregister_callback(_QWORD *a1, unsigned int a2, _QWORD *a3)
{
  const void *v3; // x30
  __int64 v7; // x22
  int v8; // w7
  _QWORD *v9; // x8
  __int64 v10; // x9
  _QWORD *v11; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a1 && a1[239] )
  {
    if ( a3 && a3[2] )
    {
      if ( (a2 & 0x80000000) != 0 || *(_DWORD *)(a1[237] + 328LL) <= a2 )
      {
        printk(&unk_27D8FF, "sde_core_irq_unregister_callback");
        return 4294967274LL;
      }
      else
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "[%pS] irq_idx=%d\n", v3, a2);
        v7 = raw_spin_lock_irqsave(a1 + 242);
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_core_irq_unregister_callback",
          330,
          -1,
          a2,
          (int)a3,
          -1059143953,
          v8,
          vars0);
        v9 = (_QWORD *)a3[1];
        if ( (_QWORD *)*v9 == a3 && (v10 = *a3, *(_QWORD **)(*a3 + 8LL) == a3) )
        {
          *(_QWORD *)(v10 + 8) = v9;
          *v9 = v10;
        }
        else
        {
          _list_del_entry_valid_or_report(a3);
        }
        *a3 = a3;
        a3[1] = a3;
        v11 = (_QWORD *)(a1[239] + 16LL * a2);
        if ( (_QWORD *)*v11 == v11 )
        {
          if ( *(_DWORD *)(a1[240] + 4LL * a2) )
            printk(&unk_26CAA7, "sde_core_irq_unregister_callback");
        }
        raw_spin_unlock_irqrestore(a1 + 242, v7);
        return 0;
      }
    }
    else
    {
      printk(&unk_227618, "sde_core_irq_unregister_callback");
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_223EAA, "sde_core_irq_unregister_callback");
    return 4294967274LL;
  }
}
