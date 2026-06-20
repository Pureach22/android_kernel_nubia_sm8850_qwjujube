__int64 __fastcall sde_vm_reclaim_irq(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x23
  __int64 v3; // x8
  __int64 v4; // x25
  __int64 v5; // x24
  __int64 v6; // x28
  unsigned int v7; // w0
  bool v8; // cc
  unsigned int v15; // w9
  unsigned int v16; // w19

  v1 = *(_QWORD *)(a1 + 6384);
  v2 = *(_QWORD *)(v1 + 272);
  if ( !v2 )
    return 0;
  v3 = (unsigned int)(*(_DWORD *)(v1 + 56) - 1);
  if ( (int)v3 < 0 )
  {
LABEL_14:
    v16 = 0;
  }
  else
  {
    v4 = 8LL * (unsigned int)(*(_DWORD *)(v1 + 56) - 1);
    v5 = v3 + 1;
    while ( 1 )
    {
      v6 = *(_QWORD *)(v2 + 8);
      v7 = gh_irq_reclaim(*(unsigned int *)(v6 + v4));
      if ( v7 )
        break;
      _X8 = (unsigned int *)(v1 + 56);
      __asm { PRFM            #0x11, [X8] }
      do
        v15 = __ldxr(_X8);
      while ( __stxr(v15 - 1, _X8) );
      if ( (_drm_debug & 4) != 0 )
        printk(&unk_26EDC1, *(unsigned int *)(v6 + v4));
      else
        printk(&unk_23DF14, "_sde_vm_reclaim_irq");
      v8 = v5-- <= 1;
      v4 -= 8;
      if ( v8 )
        goto LABEL_14;
    }
    v16 = v7;
    printk(&unk_26B2BA, "_sde_vm_reclaim_irq");
  }
  sde_vm_free_irq(*(_QWORD *)(v1 + 272));
  *(_QWORD *)(v1 + 272) = 0;
  *(_DWORD *)(v1 + 56) = 0;
  return v16;
}
