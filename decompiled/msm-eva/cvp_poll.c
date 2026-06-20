__int64 __fastcall cvp_poll(__int64 a1, void (**a2)(void))
{
  __int64 v2; // x20
  void (*v3)(void); // x8
  __int64 v4; // x0
  int v5; // w8
  unsigned int v6; // w19

  v2 = *(_QWORD *)(a1 + 32);
  if ( a2 )
  {
    if ( v2 != -296 )
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
  }
  v4 = raw_spin_lock_irqsave(v2 + 288);
  v5 = *(_DWORD *)(v2 + 292);
  *(_DWORD *)(v2 + 292) = 0;
  if ( v5 == 6 )
    v6 = 1;
  else
    v6 = 2 * (v5 == 1);
  raw_spin_unlock_irqrestore(v2 + 288, v4);
  return v6;
}
