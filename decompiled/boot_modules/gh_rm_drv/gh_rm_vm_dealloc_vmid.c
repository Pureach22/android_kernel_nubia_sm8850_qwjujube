__int64 __fastcall gh_rm_vm_dealloc_vmid(__int16 a1)
{
  unsigned int v2; // w0
  __int16 *v3; // x8
  __int64 result; // x0
  unsigned int v5; // w19
  __int64 v6; // [xsp+0h] [xbp-20h] BYREF
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  _WORD v8[2]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = a1;
  v8[1] = 0;
  v6 = 0;
  v7 = 0;
  v2 = gunyah_rm_call(rm, 1442840578, v8, 4, &v6, &v7);
  if ( v2 )
  {
    v5 = v2;
    printk(&unk_12C85, "gh_rm_vm_dealloc_vmid");
    result = v5;
  }
  else if ( v7 )
  {
    printk(&unk_129F9, "gh_rm_vm_dealloc_vmid");
    kfree(v6);
    result = 4294967274LL;
  }
  else
  {
    raw_spin_lock(&gh_vm_table_lock);
    v3 = &word_13A50;
    if ( word_13A50 == a1
      || (v3 = &word_13AB8, word_13AB8 == a1)
      || (v3 = &word_13B20, word_13B20 == a1)
      || (v3 = &word_13B88, word_13B88 == a1) )
    {
      *((_DWORD *)v3 + 18) = 0;
      *v3 = -1;
      *((_QWORD *)v3 + 1) = 0;
      *((_QWORD *)v3 + 2) = 0;
      *((_QWORD *)v3 + 3) = 0;
      *((_QWORD *)v3 + 4) = 0;
      *((_DWORD *)v3 + 10) = 0;
    }
    raw_spin_unlock(&gh_vm_table_lock);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
