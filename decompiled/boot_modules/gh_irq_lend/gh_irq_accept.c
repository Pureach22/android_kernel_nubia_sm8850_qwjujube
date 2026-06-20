__int64 __fastcall gh_irq_accept(unsigned int a1, __int64 a2)
{
  __int16 *v2; // x21
  unsigned int v3; // w20
  __int64 result; // x0
  unsigned int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 > 5 )
    goto LABEL_5;
  v2 = &gh_irq_entries[20 * a1];
  if ( *((_DWORD *)v2 + 8) != 5 )
    goto LABEL_5;
  v3 = a2;
  v5 = 0;
  if ( (_DWORD)a2 == -1 )
  {
    v5 = -1;
  }
  else
  {
    if ( (unsigned int)gh_rm_irq_to_virq((unsigned int)a2, &v5) )
    {
LABEL_5:
      result = 4294967274LL;
      goto LABEL_6;
    }
    a2 = v5;
  }
  result = gh_rm_vm_irq_accept(*((unsigned int *)v2 + 9), a2);
  v5 = result;
  if ( (result & 0x80000000) == 0 )
  {
    if ( v3 == -1 )
      v3 = gh_rm_virq_to_irq();
    result = v3;
    *((_DWORD *)v2 + 8) = 4;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
