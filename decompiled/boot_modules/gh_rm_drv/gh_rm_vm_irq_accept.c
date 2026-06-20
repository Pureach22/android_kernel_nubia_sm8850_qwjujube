__int64 __fastcall gh_rm_vm_irq_accept(int a1, int a2)
{
  unsigned int v2; // w19
  unsigned int v3; // w0
  __int64 v5; // [xsp+0h] [xbp-20h] BYREF
  _DWORD v6[2]; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v7[2]; // [xsp+10h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 < -1 )
  {
LABEL_2:
    v2 = -22;
    goto LABEL_9;
  }
  v2 = a2;
  v6[0] = a1;
  v6[1] = a2;
  v7[0] = 0;
  v5 = 0;
  v3 = gunyah_rm_call(rm, 1442840656, v6, 8, v7, &v5);
  if ( v3 )
  {
    v2 = v3;
    printk(&unk_1382B, "gh_rm_vm_irq_accept");
    goto LABEL_9;
  }
  if ( v2 == -1 && v5 != 4 )
  {
    printk(&unk_1202B, "gh_rm_vm_irq_accept");
    if ( v5 )
      kfree(v7[0]);
    goto LABEL_2;
  }
  if ( v2 == -1 )
    v2 = *(_DWORD *)v7[0];
  kfree(v7[0]);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v2;
}
