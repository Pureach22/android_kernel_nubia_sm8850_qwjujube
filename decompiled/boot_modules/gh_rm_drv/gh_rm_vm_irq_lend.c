__int64 __fastcall gh_rm_vm_irq_lend(__int16 a1, int a2, int a3, _DWORD *a4)
{
  unsigned int v5; // w0
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v8; // w19
  __int64 v9; // [xsp+8h] [xbp-28h] BYREF
  _WORD v10[2]; // [xsp+14h] [xbp-1Ch] BYREF
  int v11; // [xsp+18h] [xbp-18h]
  int v12; // [xsp+1Ch] [xbp-14h]
  _QWORD v13[2]; // [xsp+20h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = a1;
  v11 = a2;
  v12 = a3;
  v13[0] = 0;
  v10[1] = 0;
  v9 = 0;
  v5 = gunyah_rm_call(rm, 1442840657, v10, 12, v13, &v9);
  if ( v5 )
  {
    v8 = v5;
    printk(&unk_127BE, "gh_rm_vm_irq_lend");
    result = v8;
  }
  else if ( v9 == 4 )
  {
    v6 = v13[0];
    if ( a4 )
      *a4 = *(_DWORD *)v13[0];
    kfree(v6);
    result = 0;
  }
  else
  {
    printk(&unk_133BD, "gh_rm_vm_irq_lend");
    if ( v9 )
      kfree(v13[0]);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
