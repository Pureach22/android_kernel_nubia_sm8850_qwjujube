__int64 __fastcall sde_vm_release_irq(__int64 a1)
{
  __int64 v1; // x23
  __int64 v2; // x8
  __int64 v3; // x24
  __int64 i; // x25
  __int64 v6; // x28
  unsigned int v7; // w0
  unsigned int v8; // w0
  bool v9; // cc
  unsigned int v16; // w9
  unsigned int v18; // w19
  void *v19; // x0

  v1 = *(_QWORD *)(a1 + 272);
  v2 = (unsigned int)(*(_DWORD *)(a1 + 56) - 1);
  if ( (int)v2 < 0 )
    return 0;
  v3 = 8LL * (unsigned int)(*(_DWORD *)(a1 + 56) - 1);
  for ( i = v2 + 1; ; --i )
  {
    v6 = *(_QWORD *)(v1 + 8);
    v7 = gh_irq_release(*(unsigned int *)(v6 + v3));
    if ( v7 )
    {
      v18 = v7;
      v19 = &unk_259335;
      goto LABEL_18;
    }
    _X8 = (unsigned int *)(a1 + 56);
    __asm { PRFM            #0x11, [X8] }
    do
      v16 = __ldxr(_X8);
    while ( __stxr(v16 - 1, _X8) );
    v8 = gh_irq_release_notify(*(unsigned int *)(v6 + v3));
    if ( v8 )
      break;
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_2260FA, *(unsigned int *)(v6 + v3));
    else
      printk(&unk_260D56, "_sde_vm_release_irq");
    v9 = i <= 1;
    v3 -= 8;
    if ( v9 )
      return 0;
  }
  v18 = v8;
  v19 = &unk_23DFA5;
LABEL_18:
  printk(v19, "_sde_vm_release_irq");
  return v18;
}
