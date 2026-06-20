__int64 __fastcall ipclite_global_atomic_load_i32(
        unsigned int *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  void *v8; // x17
  __int64 result; // x0
  __int64 v11; // x9
  _DWORD *v12; // x8
  unsigned int v13; // w19
  void *v14; // x0

  if ( !a1 )
  {
    __break(0x800u);
    __arm_mte_set_tag((void *)(a8 + 3616), v8);
    return ipclite_global_test_and_set_bit(0, a2, a3, a4, a5, a6, a7, a8 + 3616);
  }
  if ( (feature_mask & 1) == 0 )
  {
    if ( ipclite )
    {
      if ( !(unsigned int)_hwspin_lock_timeout(*(_QWORD *)(ipclite + 6456), 1000, 1, ipclite + 6464) )
      {
        **(_DWORD **)(ipclite + 6352) = 0;
        goto LABEL_6;
      }
      v14 = &unk_EAD6;
    }
    else
    {
      v14 = &unk_F98D;
    }
    printk(v14, "ipclite", "ipclite_hw_mutex_acquire");
  }
LABEL_6:
  result = *a1;
  if ( (feature_mask & 1) != 0 )
    return result;
  v11 = ipclite;
  if ( ipclite )
  {
    v12 = *(_DWORD **)(ipclite + 6352);
    if ( *v12 )
      return result;
    v13 = *a1;
    *v12 = 255;
    _hwspin_unlock(*(_QWORD *)(v11 + 6456), 1, v11 + 6464);
  }
  else
  {
    v13 = *a1;
    printk(&unk_F98D, "ipclite", "ipclite_hw_mutex_release");
  }
  return v13;
}
