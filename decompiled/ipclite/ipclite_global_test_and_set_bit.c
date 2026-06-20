__int64 __fastcall ipclite_global_test_and_set_bit(char a1, unsigned int *a2)
{
  _BYTE *v3; // x20
  _QWORD *v4; // x21
  int v5; // w22
  __int64 v6; // x9
  _DWORD *v7; // x8
  unsigned int v8; // w19
  __int64 result; // x0
  void *v10; // x0

  if ( a2 )
  {
    v3 = &loc_E000;
    _X19 = a2;
    v5 = 1 << a1;
    v4 = &loc_E000;
    if ( (feature_mask & 1) == 0 )
    {
      if ( ipclite )
      {
        if ( !(unsigned int)_hwspin_lock_timeout(*(_QWORD *)(ipclite + 6456), 1000, 1, ipclite + 6464) )
        {
          **(_DWORD **)(ipclite + 6352) = 0;
          goto LABEL_17;
        }
        v10 = &unk_EAD6;
      }
      else
      {
        v10 = &unk_F98D;
      }
      printk(v10, "ipclite", "ipclite_hw_mutex_acquire");
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
  while ( __stlxr(result | v5, _X19) );
  __dmb(0xBu);
  if ( (v3[1080] & 1) == 0 )
  {
    v6 = v4[134];
    if ( v6 )
    {
      v7 = *(_DWORD **)(v6 + 6352);
      if ( *v7 )
        return result;
      v8 = result;
      *v7 = 255;
      _hwspin_unlock(*(_QWORD *)(v6 + 6456), 1, v6 + 6464);
    }
    else
    {
      v8 = result;
      printk(&unk_F98D, "ipclite", "ipclite_hw_mutex_release");
    }
    return v8;
  }
  return result;
}
