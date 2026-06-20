__int64 __fastcall ipclite_global_atomic_inc(unsigned int *a1)
{
  _QWORD *v2; // x20
  _BYTE *v3; // x21
  __int64 v4; // x9
  _DWORD *v5; // x8
  unsigned int v6; // w19
  __int64 result; // x0
  void *v8; // x0

  if ( a1 )
  {
    v3 = &loc_E000;
    _X19 = a1;
    v2 = &loc_E000;
    if ( (feature_mask & 1) == 0 )
    {
      if ( ipclite )
      {
        if ( !(unsigned int)_hwspin_lock_timeout(*(_QWORD *)(ipclite + 6456), 1000, 1, ipclite + 6464) )
        {
          **(_DWORD **)(ipclite + 6352) = 0;
          goto LABEL_17;
        }
        v8 = &unk_EAD6;
      }
      else
      {
        v8 = &unk_F98D;
      }
      printk(v8, "ipclite", "ipclite_hw_mutex_acquire");
    }
  }
  else
  {
    __break(0x800u);
  }
LABEL_17:
  __asm { PRFM            #0x11, [X19] }
  do
    result = __ldxr(_X19);
  while ( __stlxr(result + 1, _X19) );
  __dmb(0xBu);
  if ( (v3[1080] & 1) == 0 )
  {
    v4 = v2[134];
    if ( v4 )
    {
      v5 = *(_DWORD **)(v4 + 6352);
      if ( *v5 )
        return result;
      v6 = result;
      *v5 = 255;
      _hwspin_unlock(*(_QWORD *)(v4 + 6456), 1, v4 + 6464);
    }
    else
    {
      v6 = result;
      printk(&unk_F98D, "ipclite", "ipclite_hw_mutex_release");
    }
    return v6;
  }
  return result;
}
