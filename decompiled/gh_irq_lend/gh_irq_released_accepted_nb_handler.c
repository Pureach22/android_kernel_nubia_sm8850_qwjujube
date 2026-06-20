__int64 __fastcall gh_irq_released_accepted_nb_handler(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v6; // x1
  __int16 *v7; // x21
  unsigned int v8; // w19
  __int16 *v9; // x21
  _DWORD *v10; // x8
  __int64 v11; // x0
  __int64 v12; // x1

  if ( (unsigned __int64)(a2 - 1443889172) < 0xFFFFFFFFFFFFFFFELL )
    return 0;
  v6 = raw_spin_lock_irqsave(&gh_irq_lend_lock);
  if ( dword_6E58 != 4 && dword_6E58 != 1 )
    goto LABEL_10;
  if ( a2 != 1443889171 )
  {
    v7 = gh_irq_entries;
    if ( *a3 == dword_6E5C )
    {
      v8 = 0;
LABEL_46:
      *((_DWORD *)v7 + 8) = 3;
      raw_spin_unlock_irqrestore(&gh_irq_lend_lock, v6);
      v10 = *((_DWORD **)v7 + 1);
      v11 = *((_QWORD *)v7 + 3);
      v12 = 1443889170;
      goto LABEL_47;
    }
LABEL_10:
    if ( dword_6E80 == 4 || dword_6E80 == 1 )
    {
      if ( a2 == 1443889170 )
      {
        v7 = &word_6E60;
        if ( *a3 == dword_6E84 )
        {
          v8 = 1;
          goto LABEL_46;
        }
      }
      else
      {
        v9 = &word_6E60;
        if ( *a3 == dword_6E84 )
        {
          v8 = 1;
          goto LABEL_43;
        }
      }
    }
    if ( dword_6EA8 == 4 || dword_6EA8 == 1 )
    {
      if ( a2 == 1443889170 )
      {
        v7 = &word_6E88;
        if ( *a3 == dword_6EAC )
        {
          v8 = 2;
          goto LABEL_46;
        }
      }
      else
      {
        v9 = &word_6E88;
        if ( *a3 == dword_6EAC )
        {
          v8 = 2;
          goto LABEL_43;
        }
      }
    }
    if ( dword_6ED0 == 4 || dword_6ED0 == 1 )
    {
      if ( a2 == 1443889170 )
      {
        v7 = &word_6EB0;
        if ( *a3 == dword_6ED4 )
        {
          v8 = 3;
          goto LABEL_46;
        }
      }
      else
      {
        v9 = &word_6EB0;
        if ( *a3 == dword_6ED4 )
        {
          v8 = 3;
          goto LABEL_43;
        }
      }
    }
    if ( dword_6EF8 == 4 || dword_6EF8 == 1 )
    {
      if ( a2 == 1443889170 )
      {
        v7 = &word_6ED8;
        if ( *a3 == dword_6EFC )
        {
          v8 = 4;
          goto LABEL_46;
        }
      }
      else
      {
        v9 = &word_6ED8;
        if ( *a3 == dword_6EFC )
        {
          v8 = 4;
          goto LABEL_43;
        }
      }
    }
    if ( dword_6F20 == 4 || dword_6F20 == 1 )
    {
      if ( a2 == 1443889170 )
      {
        v7 = &word_6F00;
        if ( *a3 == dword_6F24 )
        {
          v8 = 5;
          goto LABEL_46;
        }
      }
      else
      {
        v9 = &word_6F00;
        if ( *a3 == dword_6F24 )
        {
          v8 = 5;
          goto LABEL_43;
        }
      }
    }
    raw_spin_unlock_irqrestore(&gh_irq_lend_lock, v6);
    return 0;
  }
  v9 = gh_irq_entries;
  if ( *a3 != dword_6E5C )
    goto LABEL_10;
  v8 = 0;
LABEL_43:
  *((_DWORD *)v9 + 8) = 4;
  raw_spin_unlock_irqrestore(&gh_irq_lend_lock, v6);
  v10 = *((_DWORD **)v9 + 1);
  v11 = *((_QWORD *)v9 + 3);
  v12 = 1443889171;
LABEL_47:
  if ( *(v10 - 1) != -1907065697 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _QWORD))v10)(v11, v12, v8);
  return 1;
}
