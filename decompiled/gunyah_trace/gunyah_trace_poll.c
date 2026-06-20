__int64 __fastcall gunyah_trace_poll(__int64 a1, void (**a2)(void))
{
  __int64 v2; // x19
  void (*v3)(void); // x8
  __int64 v4; // x21
  unsigned __int64 v5; // x22
  __int64 i; // x23
  __int64 v7; // x25
  __int64 v8; // x0
  __int64 v9; // x9
  unsigned int *v10; // x8
  unsigned int v11; // w25
  unsigned int v12; // w26

  v2 = *(_QWORD *)(a1 + 32);
  if ( a2 )
  {
    v3 = *a2;
    if ( *a2 )
    {
      if ( *((_DWORD *)v3 - 1) != -442429149 )
        __break(0x8228u);
      v3();
      __dmb(0xBu);
    }
  }
  if ( !word_7E0C )
    return 0;
  v4 = 0;
  v5 = 0;
  for ( i = 8; ; i += 32 )
  {
    v7 = qword_7E38;
    v8 = raw_spin_lock_irqsave(*(_QWORD *)(v2 + 8) + v4 + 8);
    v9 = *(_QWORD *)(v7 + i);
    v10 = (unsigned int *)(*(_QWORD *)(v2 + 8) + v4);
    if ( *(_DWORD *)(v9 + 48) > v10[1] )
      break;
    v11 = *(_DWORD *)(v9 + 40);
    v12 = *v10;
    raw_spin_unlock_irqrestore(v10 + 2, v8);
    if ( v11 > v12 )
      return 65;
    ++v5;
    v4 += 12;
    if ( v5 >= (unsigned __int16)word_7E0C )
      return 0;
  }
  raw_spin_unlock_irqrestore(v10 + 2, v8);
  return 65;
}
