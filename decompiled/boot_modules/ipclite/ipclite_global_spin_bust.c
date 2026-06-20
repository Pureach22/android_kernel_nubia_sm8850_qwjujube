__int64 __fastcall ipclite_global_spin_bust(
        unsigned int a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v8; // w29
  __int64 result; // x0
  __int64 v10; // x8
  unsigned int v11; // w9

  if ( a1 > 0xFF )
    return 4294967274LL;
  v10 = *(_QWORD *)(ipclite + 6448);
  v11 = *(_DWORD *)(v10 + 4LL * a1);
  if ( (feature_mask & 8) != 0 )
  {
    if ( v11 != a2 + 1 )
      return 0;
  }
  else if ( ((v11 >> a2) & 1) == 0 )
  {
    return 0;
  }
  *(_DWORD *)(v10 + 4LL * a1) = 0;
  result = 0;
  if ( (ipclite_debug_level & 0x10) == 0 )
    return result;
  if ( (ipclite_debug_control & 1) != 0 )
  {
    printk(&unk_E9AE, "ipclite", "ipclite_global_spin_bust");
    if ( (ipclite_debug_control & 4) == 0 )
      return 0;
    goto LABEL_10;
  }
  if ( (ipclite_debug_control & 4) != 0 )
LABEL_10:
    ipclite_inmem_log("APPS:%s:Ipclite Bust for atomic lock successful", (__int64)"LOW", a3, a4, a5, a6, a7, a8, v8);
  return 0;
}
