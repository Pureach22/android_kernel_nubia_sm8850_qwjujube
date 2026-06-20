__int64 __fastcall kgsl_get_pagetable(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x22
  __int64 i; // x19
  __int64 v5; // x20
  unsigned int v7; // w8
  unsigned int v8; // w23
  unsigned int v14; // w9

  v2 = raw_spin_lock_irqsave(&unk_3A838);
  v3 = qword_3A828;
  for ( i = v2; (__int64 *)v3 != &qword_3A828; v3 = *(_QWORD *)v3 )
  {
    if ( *(_DWORD *)(v3 + 16) == a1 )
    {
      _X0 = (unsigned int *)(v3 - 4);
      v7 = *(_DWORD *)(v3 - 4);
      if ( v7 )
      {
        do
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v14 = __ldxr(_X0);
          while ( v14 == v7 && __stxr(v7 + 1, _X0) );
          v8 = v7;
          if ( v14 == v7 )
            break;
          v8 = 0;
          v7 = v14;
        }
        while ( v14 );
      }
      else
      {
        v8 = 0;
      }
      if ( (((v8 + 1) | v8) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(_X0, 0);
        if ( v8 )
          goto LABEL_17;
      }
      else if ( v8 )
      {
LABEL_17:
        v5 = v3 - 8;
        goto LABEL_18;
      }
    }
  }
  v5 = 0;
LABEL_18:
  raw_spin_unlock_irqrestore(&unk_3A838, i);
  return v5;
}
