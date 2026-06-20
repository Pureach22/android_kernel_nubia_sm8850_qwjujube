__int64 __fastcall sde_core_irq_uninstall(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x20
  int v4; // w0
  char v5; // w6
  unsigned int v6; // w8
  int v7; // w9
  int v8; // w22
  _QWORD *v9; // x9
  __int64 v10; // x0
  __int64 v11; // x8
  void (*v12)(void); // x8
  __int64 v13; // x8
  void (*v14)(void); // x8
  __int64 v15; // x20
  unsigned int v17; // w9
  unsigned int v24; // w11
  int v25; // w20
  int v26; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return printk(&unk_224408, "sde_core_irq_uninstall");
  v1 = *(_QWORD *)(a1 + 136);
  if ( !v1 )
    return printk(&unk_224408, "sde_core_irq_uninstall");
  v3 = *(_QWORD *)(v1 + 8);
  v4 = _pm_runtime_resume(v3, 4);
  if ( v4 < 0 )
  {
    v17 = *(_DWORD *)(v3 + 480);
    do
    {
      if ( !v17 )
        break;
      _X13 = (unsigned int *)(v3 + 480);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v24 = __ldxr(_X13);
        if ( v24 != v17 )
          break;
        if ( !__stlxr(v17 - 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v24 == v17;
      v17 = v24;
    }
    while ( !_ZF );
    v25 = v4;
    printk(&unk_24C43E, "sde_core_irq_uninstall");
    return sde_evtlog_log(sde_dbg_base_evtlog, "sde_core_irq_uninstall", 501, -1, v25, 60333, -1059143953, v26, vars0);
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 1904);
    if ( v6 )
    {
      v7 = 0;
      do
      {
        v8 = v7;
        if ( *(_DWORD *)(*(_QWORD *)(a1 + 1920) + 4LL * v7)
          || (v9 = (_QWORD *)(*(_QWORD *)(a1 + 1912) + 16LL * v7), (_QWORD *)*v9 != v9) )
        {
          printk(&unk_26238A, "sde_core_irq_uninstall");
          v6 = *(_DWORD *)(a1 + 1904);
        }
        v7 = v8 + 1;
      }
      while ( v8 + 1 < v6 );
    }
    v10 = *(_QWORD *)(a1 + 1896);
    if ( !v10 )
      goto LABEL_22;
    v11 = *(unsigned int *)(v10 + 28);
    if ( (unsigned int)v11 < 3 )
    {
      v12 = *(void (**)(void))(v10 + 8 * v11 + 104);
      if ( v12 )
      {
        if ( *((_DWORD *)v12 - 1) != 1946677504 )
          __break(0x8228u);
        v12();
        v10 = *(_QWORD *)(a1 + 1896);
        if ( !v10 )
          goto LABEL_22;
      }
      v13 = *(unsigned int *)(v10 + 28);
      if ( (unsigned int)v13 < 3 )
      {
        v14 = *(void (**)(void))(v10 + 8 * v13 + 128);
        if ( v14 )
        {
          if ( *((_DWORD *)v14 - 1) != 1946677504 )
            __break(0x8228u);
          v14();
        }
LABEL_22:
        _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 8LL), 4);
        v15 = raw_spin_lock_irqsave(a1 + 1936);
        kfree(*(_QWORD *)(a1 + 1912));
        kfree(*(_QWORD *)(a1 + 1920));
        kfree(*(_QWORD *)(a1 + 1928));
        *(_DWORD *)(a1 + 1904) = 0;
        *(_QWORD *)(a1 + 1912) = 0;
        *(_QWORD *)(a1 + 1920) = 0;
        *(_QWORD *)(a1 + 1928) = 0;
        return raw_spin_unlock_irqrestore(a1 + 1936, v15);
      }
    }
    __break(0x5512u);
    if ( (v5 & 0x10) != 0 )
      JUMPOUT(0xFEE08);
    return sde_core_irq_domain_add();
  }
}
