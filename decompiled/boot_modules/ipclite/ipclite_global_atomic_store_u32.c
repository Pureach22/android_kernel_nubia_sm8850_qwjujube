__int64 __fastcall ipclite_global_atomic_store_u32(__int64 result, int a2)
{
  _DWORD *v2; // x19
  __int64 v4; // x8
  _DWORD *v5; // x9
  void *v6; // x0

  if ( !result )
  {
    __break(0x800u);
    return ipclite_global_atomic_store_i32();
  }
  v2 = (_DWORD *)result;
  if ( (feature_mask & 1) == 0 )
  {
    if ( ipclite )
    {
      result = _hwspin_lock_timeout(*(_QWORD *)(ipclite + 6456), 1000, 1, ipclite + 6464);
      if ( !(_DWORD)result )
      {
        **(_DWORD **)(ipclite + 6352) = 0;
        goto LABEL_6;
      }
      v6 = &unk_EAD6;
    }
    else
    {
      v6 = &unk_F98D;
    }
    result = printk(v6, "ipclite", "ipclite_hw_mutex_acquire");
  }
LABEL_6:
  *v2 = a2;
  if ( (feature_mask & 1) == 0 )
  {
    v4 = ipclite;
    if ( ipclite )
    {
      v5 = *(_DWORD **)(ipclite + 6352);
      if ( !*v5 )
      {
        *v5 = 255;
        return _hwspin_unlock(*(_QWORD *)(v4 + 6456), 1, v4 + 6464);
      }
    }
    else
    {
      return printk(&unk_F98D, "ipclite", "ipclite_hw_mutex_release");
    }
  }
  return result;
}
