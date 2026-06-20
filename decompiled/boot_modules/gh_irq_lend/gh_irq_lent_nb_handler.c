__int64 __fastcall gh_irq_lent_nb_handler(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  __int64 v3; // x0
  unsigned int vm_name; // w0
  unsigned int v6; // w20
  __int64 result; // x0
  __int64 v8; // x0
  unsigned __int16 *v9; // x8
  __int16 *v10; // x20
  unsigned int v11; // w19
  int v12; // w8
  _DWORD *v13; // x8
  __int64 v14; // x0
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 != 1443889169 )
    goto LABEL_37;
  v3 = *a3;
  v15 = 0;
  vm_name = gh_rm_get_vm_name(v3, &v15);
  if ( vm_name )
  {
    v6 = vm_name;
    if ( (unsigned int)__ratelimit(&gh_irq_lent_nb_handler__rs, "gh_irq_lent_nb_handler") )
      printk(&unk_6F58, "gh_irq_lent_nb_handler", *a3);
    result = v6;
    goto LABEL_38;
  }
  v8 = raw_spin_lock_irqsave(&gh_irq_lend_lock);
  v9 = a3;
  if ( dword_6E58 != 5 && dword_6E58 != 2
    || *((_DWORD *)a3 + 2)
    || (v10 = gh_irq_entries, v11 = 0, dword_6E3C != 5) && dword_6E3C != v15 )
  {
    if ( dword_6E80 != 5 && dword_6E80 != 2
      || *((_DWORD *)v9 + 2) != 1
      || (v10 = &word_6E60, v11 = 1, dword_6E64 != 5) && dword_6E64 != v15 )
    {
      if ( dword_6EA8 != 5 && dword_6EA8 != 2
        || *((_DWORD *)v9 + 2) != 2
        || (v10 = &word_6E88, v11 = 2, dword_6E8C != 5) && dword_6E8C != v15 )
      {
        if ( dword_6ED0 != 5 && dword_6ED0 != 2
          || *((_DWORD *)v9 + 2) != 3
          || (v10 = &word_6EB0, v11 = 3, dword_6EB4 != 5) && dword_6EB4 != v15 )
        {
          if ( dword_6EF8 != 5 && dword_6EF8 != 2
            || *((_DWORD *)v9 + 2) != 4
            || (v10 = &word_6ED8, v11 = 4, dword_6EDC != 5) && dword_6EDC != v15 )
          {
            if ( dword_6F20 != 5 && dword_6F20 != 2
              || *((_DWORD *)v9 + 2) != 5
              || (v10 = &word_6F00, v11 = 5, dword_6F04 != 5) && dword_6F04 != v15 )
            {
              raw_spin_unlock_irqrestore(&gh_irq_lend_lock, v8);
LABEL_37:
              result = 0;
              goto LABEL_38;
            }
          }
        }
      }
    }
  }
  *v10 = *v9;
  v12 = *((_DWORD *)v9 + 1);
  *((_DWORD *)v10 + 8) = 5;
  *((_DWORD *)v10 + 9) = v12;
  raw_spin_unlock_irqrestore(&gh_irq_lend_lock, v8);
  v13 = *((_DWORD **)v10 + 1);
  v14 = *((_QWORD *)v10 + 3);
  if ( *(v13 - 1) != -1907065697 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _QWORD))v13)(v14, 1443889169, v11);
  result = 1;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
