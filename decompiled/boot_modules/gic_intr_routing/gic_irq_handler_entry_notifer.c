void __fastcall gic_irq_handler_entry_notifer(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v4; // x0
  int v5; // w20
  const char **v6; // x8
  __int64 v7; // x21
  int v8; // w8
  __int64 v9; // x20
  __int64 v10; // x9
  __int64 v11; // x10
  unsigned __int64 v18; // x10

  if ( !*(_QWORD *)(a3 + 32) )
    return;
  v4 = irq_to_desc(a2);
  if ( !v4 )
    return;
  v5 = *(_DWORD *)(v4 + 56);
  if ( (unsigned int)(v5 - 1020) < 0xFFFFFC24 )
    return;
  if ( byte_7B4E != 1 )
  {
    v6 = *(const char ***)(v4 + 72);
    if ( !v6 )
      return;
LABEL_10:
    v7 = v4;
    v8 = strcmp(*v6, "GICv3");
    v4 = v7;
    if ( v8 )
      return;
    goto LABEL_11;
  }
  __dmb(9u);
  v6 = *(const char ***)(v4 + 72);
  if ( !v6 )
    return;
  if ( !gic_routing_data )
    goto LABEL_10;
  if ( v6 != (const char **)gic_routing_data )
    return;
LABEL_11:
  if ( ((*(_QWORD *)((char *)&active_gic_class0 + (((unsigned __int64)(unsigned int)(v5 - 32) >> 3) & 0x1FFFFFF8)) >> ((unsigned __int8)v5 - 32))
      & 1) != 0
    || ((*(_QWORD *)((char *)&active_gic_class1 + (((unsigned __int64)(unsigned int)(v5 - 32) >> 3) & 0x1FFFFFF8)) >> ((unsigned __int8)v5 - 32))
      & 1) != 0 )
  {
    v9 = v4;
    if ( (unsigned int)raw_spin_trylock(v4 + 172) )
    {
      v10 = *(_QWORD *)(v9 + 64);
      v11 = *(_QWORD *)(v9 + 24);
      if ( (unsigned int)v11 != *(_DWORD *)(v10 + 32) )
      {
        *(_QWORD *)(v10 + 32) = v11;
        _X9 = (unsigned __int64 *)(a3 + 64);
        __asm { PRFM            #0x11, [X9] }
        do
          v18 = __ldxr(_X9);
        while ( __stxr(v18 | 4, _X9) );
      }
      raw_spin_unlock(v9 + 172);
    }
  }
}
