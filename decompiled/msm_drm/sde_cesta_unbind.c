__int64 __fastcall sde_cesta_unbind(__int64 a1, __int64 a2)
{
  if ( !a1 || !a2 )
    return printk(&unk_26DDCA, "sde_cesta_unbind");
  if ( *(_QWORD *)(a1 + 152) )
    return msm_unregister_vm_event(a2, a1);
  return printk(&unk_25C232, "sde_cesta_unbind");
}
