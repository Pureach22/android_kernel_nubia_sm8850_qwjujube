__int64 __fastcall sde_core_irq_preinstall(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x9
  __int64 v4; // x20
  int v5; // w0
  __int64 v6; // x0
  __int64 v7; // x8
  void (*v8)(void); // x8
  __int64 v9; // x8
  void (*v10)(void); // x8
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 result; // x0
  __int64 v14; // x8
  unsigned int v15; // w8
  __int64 v16; // x9
  _QWORD *v17; // x9
  __int64 v18; // x9
  __int64 v19; // x9
  unsigned int v20; // w9
  unsigned int v27; // w11
  int v28; // w20
  int v29; // w7
  unsigned __int64 StatusReg; // x20
  __int64 v31; // x21
  char v32; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return printk(&unk_224408, "sde_core_irq_preinstall");
  v1 = *(_QWORD *)(a1 + 136);
  if ( !v1 )
    return printk(&unk_224408, "sde_core_irq_preinstall");
  v3 = *(_QWORD *)(a1 + 152);
  if ( v3 && (*(_BYTE *)(v3 + 20120) & 1) != 0 )
    goto LABEL_18;
  v4 = *(_QWORD *)(v1 + 8);
  v5 = _pm_runtime_resume(v4, 4);
  if ( (v5 & 0x80000000) == 0 )
  {
    v6 = *(_QWORD *)(a1 + 1896);
    if ( v6 )
    {
      v7 = *(unsigned int *)(v6 + 28);
      if ( (unsigned int)v7 >= 3 )
        goto LABEL_43;
      v8 = *(void (**)(void))(v6 + 8 * v7 + 104);
      if ( v8 )
      {
        if ( *((_DWORD *)v8 - 1) != 1946677504 )
          __break(0x8228u);
        v8();
        v6 = *(_QWORD *)(a1 + 1896);
        if ( !v6 )
          goto LABEL_17;
      }
      v9 = *(unsigned int *)(v6 + 28);
      if ( (unsigned int)v9 >= 3 )
      {
LABEL_43:
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v31 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &sde_core_irq_preinstall__alloc_tag;
        v12 = _kmalloc_noprof(16LL * *(unsigned int *)(a1 + 1904), 3520);
        *(_QWORD *)(StatusReg + 80) = v31;
        goto LABEL_19;
      }
      v10 = *(void (**)(void))(v6 + 8 * v9 + 128);
      if ( v10 )
      {
        if ( *((_DWORD *)v10 - 1) != 1946677504 )
          __break(0x8228u);
        v10();
      }
    }
LABEL_17:
    _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 8LL), 4);
LABEL_18:
    v11 = *(_QWORD *)(a1 + 1896);
    *(_DWORD *)(a1 + 1936) = 0;
    *(_DWORD *)(a1 + 1904) = *(_DWORD *)(v11 + 328);
    v12 = _kmalloc_noprof(16LL * *(unsigned int *)(a1 + 1904), 3520);
LABEL_19:
    *(_QWORD *)(a1 + 1912) = v12;
    *(_QWORD *)(a1 + 1920) = _kmalloc_noprof(4LL * *(unsigned int *)(a1 + 1904), 3520);
    result = _kmalloc_noprof(4LL * *(unsigned int *)(a1 + 1904), 3520);
    v14 = *(_QWORD *)(a1 + 1912);
    *(_QWORD *)(a1 + 1928) = result;
    if ( v14 && *(_QWORD *)(a1 + 1920) && result && *(_DWORD *)(a1 + 1904) )
    {
      v15 = 0;
      do
      {
        v16 = *(_QWORD *)(a1 + 1912);
        if ( v16 )
        {
          v17 = (_QWORD *)(v16 + 16LL * (int)v15);
          *v17 = v17;
          v17[1] = v17;
        }
        v18 = *(_QWORD *)(a1 + 1920);
        if ( v18 )
          *(_DWORD *)(v18 + 4LL * (int)v15) = 0;
        v19 = *(_QWORD *)(a1 + 1928);
        if ( v19 )
          *(_DWORD *)(v19 + 4LL * (int)v15) = 0;
        ++v15;
      }
      while ( v15 < *(_DWORD *)(a1 + 1904) );
    }
    return result;
  }
  v20 = *(_DWORD *)(v4 + 480);
  do
  {
    if ( !v20 )
      break;
    _X13 = (unsigned int *)(v4 + 480);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v27 = __ldxr(_X13);
      if ( v27 != v20 )
        break;
      if ( !__stlxr(v20 - 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v27 == v20;
    v20 = v27;
  }
  while ( !_ZF );
  v28 = v5;
  printk(&unk_24C43E, "sde_core_irq_preinstall");
  return sde_evtlog_log(sde_dbg_base_evtlog, "sde_core_irq_preinstall", 448, -1, v28, 60333, -1059143953, v29, v32);
}
