__int64 __fastcall sde_vm_deinit_0(__int64 result, _QWORD *a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x0

  v2 = *(_QWORD **)(result + 6384);
  if ( v2 )
  {
    a2[12] = 0;
    a2[13] = 0;
    a2[10] = 0;
    a2[11] = 0;
    a2[8] = 0;
    a2[9] = 0;
    a2[6] = 0;
    a2[7] = 0;
    a2[4] = 0;
    a2[5] = 0;
    a2[2] = 0;
    a2[3] = 0;
    *a2 = 0;
    a2[1] = 0;
    sde_vm_msgq_deinit(*(_QWORD *)(result + 6384));
    if ( v2[6] )
      gh_mem_notifier_unregister();
    kfree(v2[35]);
    v3 = v2[34];
    if ( v3 )
      sde_vm_free_irq(v3);
    return kfree(v2);
  }
  return result;
}
