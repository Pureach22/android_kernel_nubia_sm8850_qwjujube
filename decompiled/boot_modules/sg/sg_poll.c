__int64 __fastcall sg_poll(__int64 a1, void (**a2)(void))
{
  __int64 v2; // x19
  __int64 v3; // x20
  void (*v4)(void); // x8
  __int64 lock_irqsave; // x1
  __int64 *v6; // x9
  unsigned int v7; // w22
  int v8; // w21
  unsigned int v10; // w8

  v2 = *(_QWORD *)(a1 + 32);
  if ( !v2 )
    return 8;
  v3 = *(_QWORD *)(v2 + 16);
  if ( !v3 )
    return 8;
  if ( a2 )
  {
    v4 = *a2;
    if ( *a2 )
    {
      if ( *((_DWORD *)v4 - 1) != -442429149 )
        __break(0x8228u);
      v4();
      __dmb(0xBu);
    }
  }
  lock_irqsave = raw_read_lock_irqsave(v2 + 48);
  v6 = *(__int64 **)(v2 + 144);
  if ( v6 == (__int64 *)(v2 + 144) )
  {
    v8 = 0;
    v7 = 0;
  }
  else
  {
    v7 = 0;
    v8 = 0;
    do
    {
      if ( !v7 )
      {
        if ( *((_BYTE *)v6 + 243) == 1 )
        {
          if ( *((_BYTE *)v6 + 242) )
            v7 = 0;
          else
            v7 = 65;
        }
        else
        {
          v7 = 0;
        }
      }
      v6 = (__int64 *)*v6;
      ++v8;
    }
    while ( v6 != (__int64 *)(v2 + 144) );
  }
  raw_read_unlock_irqrestore(v2 + 48, lock_irqsave);
  if ( *(_DWORD *)(v3 + 112) )
    return v7 | 0x10;
  v10 = v7 | 0x104;
  if ( *(_BYTE *)(v2 + 4905) )
  {
    if ( v8 >= 16 )
      return v7;
    else
      return v10;
  }
  else if ( v8 )
  {
    return v7;
  }
  else
  {
    return v10;
  }
}
