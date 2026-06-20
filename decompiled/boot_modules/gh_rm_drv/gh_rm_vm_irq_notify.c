__int64 __fastcall gh_rm_vm_irq_notify(_WORD *a1, unsigned int a2, char a3, int a4)
{
  __int64 result; // x0
  __int64 v9; // x21
  __int64 v10; // x23
  unsigned int v11; // w19
  unsigned __int64 StatusReg; // x25
  __int64 v13; // x26
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 || (a3 & 1) != 0 )
  {
    v14 = 0;
    v15[0] = 0;
    if ( (a3 & 1) != 0 )
      v9 = 4LL * a2 + 12;
    else
      v9 = 8;
    v10 = _kmalloc_noprof(v9, 3520);
    if ( !v10 )
    {
LABEL_18:
      result = 4294967284LL;
      goto LABEL_19;
    }
    while ( 1 )
    {
      *(_DWORD *)v10 = a4;
      *(_BYTE *)(v10 + 4) = a3;
      if ( (a3 & 1) == 0 )
        break;
      *(_WORD *)(v10 + 8) = a2;
      if ( !a2 )
        break;
      while ( (a3 & 1) != 0 )
      {
        *(_WORD *)(v10 + 12) = *a1;
        if ( a2 == 1 )
          goto LABEL_12;
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v13 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &gh_rm_vm_irq_notify__alloc_tag;
      v10 = _kmalloc_noprof(v9, 3520);
      *(_QWORD *)(StatusReg + 80) = v13;
      if ( !v10 )
        goto LABEL_18;
    }
LABEL_12:
    v11 = gunyah_rm_call(rm, 1442840660, v10, v9, v15, &v14);
    kfree(v10);
    if ( v11 )
    {
      printk(&unk_136D1, "gh_rm_vm_irq_notify");
      result = v11;
      goto LABEL_19;
    }
    if ( !v14 )
    {
      result = 0;
      goto LABEL_19;
    }
    printk(&unk_125D1, "gh_rm_vm_irq_notify");
    kfree(v15[0]);
  }
  result = 4294967274LL;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
