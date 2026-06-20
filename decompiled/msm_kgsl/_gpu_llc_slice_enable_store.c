__int64 __fastcall gpu_llc_slice_enable_store(__int64 a1, char a2)
{
  unsigned __int64 v2; // x8
  unsigned int v3; // w2

  v2 = *(_QWORD *)(a1 + 20824);
  v3 = 0;
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( *(_BYTE *)(a1 + 20832) == (a2 & 1) )
      return 0;
    return (unsigned int)adreno_power_cycle_bool(a1, (_BYTE *)(a1 + 20832), a2 & 1);
  }
  return v3;
}
