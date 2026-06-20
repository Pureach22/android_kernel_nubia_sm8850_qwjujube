__int64 __fastcall sde_vm_populate_res(__int64 a1, __int64 a2)
{
  unsigned int resources; // w0
  unsigned __int64 v4; // x0
  unsigned int *v5; // x0
  __int64 result; // x0
  unsigned int v7; // w19
  _QWORD *v8[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v9[3]; // [xsp+18h] [xbp-18h] BYREF

  v9[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = v9;
  v9[1] = v9;
  v8[0] = v8;
  v8[1] = v8;
  resources = sde_vm_get_resources(a1, (__int64)v8);
  if ( resources )
  {
    v7 = resources;
    printk(&unk_21F879, "_sde_vm_populate_res");
    result = v7;
  }
  else
  {
    v4 = sde_vm_populate_sgl((__int64)v8);
    *(_QWORD *)(a2 + 280) = v4;
    if ( v4 && v4 < 0xFFFFFFFFFFFFF001LL )
    {
      v5 = (unsigned int *)sde_vm_populate_irq(v8);
      *(_QWORD *)(a2 + 272) = v5;
      if ( v5 && (unsigned __int64)v5 < 0xFFFFFFFFFFFFF001LL )
      {
        sort(*((_QWORD *)v5 + 1), *v5, 8, _irq_cmp, 0);
        sort(*(_QWORD *)(a2 + 280) + 6LL, **(unsigned int **)(a2 + 280), 16, _sgl_cmp, 0);
        result = 0;
      }
      else
      {
        printk(&unk_23A7EF, "_sde_vm_populate_res");
        result = *(unsigned int *)(a2 + 272);
      }
    }
    else
    {
      printk(&unk_252194, "_sde_vm_populate_res");
      result = *(unsigned int *)(a2 + 280);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
