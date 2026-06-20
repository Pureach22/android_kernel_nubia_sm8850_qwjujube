__int64 __usercall ipclite_global_test_and_clear_bit@<X0>(char a1@<W0>, unsigned int *a2@<X1>, int a3@<W8>)
{
  _QWORD *v4; // x21
  _BYTE *v5; // x22
  __int64 v7; // x9
  _DWORD *v8; // x8
  unsigned int v9; // w19
  __int64 result; // x0
  void *v11; // x0
  int v12; // w8

  if ( !a2 )
  {
    __break(0x800u);
    goto LABEL_17;
  }
  v5 = &loc_E000;
  _X19 = a2;
  v4 = &loc_E000;
  if ( (feature_mask & 1) == 0 )
  {
    if ( ipclite )
    {
      if ( !(unsigned int)_hwspin_lock_timeout(*(_QWORD *)(ipclite + 6456), 1000, 1, ipclite + 6464) )
      {
        **(_DWORD **)(ipclite + 6352) = 0;
        goto LABEL_6;
      }
      v11 = &unk_EAD6;
    }
    else
    {
      v11 = &unk_F98D;
    }
    printk(v11, "ipclite", "ipclite_hw_mutex_acquire");
  }
LABEL_6:
  a3 = 1 << a1;
LABEL_17:
  v12 = ~a3;
  __asm { PRFM            #0x11, [X19] }
  do
    result = __ldxr(_X19);
  while ( __stlxr(result & v12, _X19) );
  __dmb(0xBu);
  if ( (v5[1080] & 1) == 0 )
  {
    v7 = v4[134];
    if ( v7 )
    {
      v8 = *(_DWORD **)(v7 + 6352);
      if ( *v8 )
        return result;
      v9 = result;
      *v8 = 255;
      _hwspin_unlock(*(_QWORD *)(v7 + 6456), 1, v7 + 6464);
    }
    else
    {
      v9 = result;
      printk(&unk_F98D, "ipclite", "ipclite_hw_mutex_release");
    }
    return v9;
  }
  return result;
}
