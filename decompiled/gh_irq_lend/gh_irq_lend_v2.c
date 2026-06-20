__int64 __fastcall gh_irq_lend_v2(unsigned int a1, unsigned int a2, unsigned int a3, __int64 a4, __int64 a5)
{
  unsigned __int8 v5; // w21
  bool v7; // cc
  __int64 result; // x0
  __int64 v12; // x0
  unsigned __int8 *v13; // x11
  __int16 *v14; // x21
  __int64 v15; // x20
  unsigned int vmid; // w0
  unsigned int v17; // w19
  unsigned int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v7 = a1 > 5;
  result = 4294967274LL;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( v7 || !a4 )
    goto LABEL_11;
  v18 = 0;
  if ( (unsigned int)gh_rm_irq_to_virq(a3, &v18) )
  {
    result = 4294967274LL;
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v12 = raw_spin_lock_irqsave(&gh_irq_lend_lock);
  if ( a1 <= 5 )
  {
    v14 = &gh_irq_entries[20 * a1];
    v15 = v12;
    if ( *((_DWORD *)v14 + 8) )
    {
      raw_spin_unlock_irqrestore(&gh_irq_lend_lock, v12);
      result = 4294967274LL;
    }
    else
    {
      vmid = ghd_rm_get_vmid(a2, &gh_irq_entries[20 * a1]);
      if ( vmid )
      {
        v17 = vmid;
        *((_DWORD *)v14 + 8) = 0;
        raw_spin_unlock_irqrestore(&gh_irq_lend_lock, v15);
        result = v17;
      }
      else
      {
        *((_QWORD *)v14 + 1) = a4;
        *((_QWORD *)v14 + 3) = a5;
        *((_DWORD *)v14 + 8) = 1;
        raw_spin_unlock_irqrestore(&gh_irq_lend_lock, v15);
        result = gh_rm_vm_irq_lend((unsigned __int16)*v14, v18, a1, v14 + 18);
      }
    }
    goto LABEL_11;
  }
  __break(1u);
  __stxr(v5, v13);
  return gh_irq_lend(v12);
}
