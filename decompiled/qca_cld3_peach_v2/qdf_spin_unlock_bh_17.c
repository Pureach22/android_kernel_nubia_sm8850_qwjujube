__int64 __fastcall qdf_spin_unlock_bh_17(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 8);
  if ( (v1 & 1) == 0 )
    return raw_spin_unlock(a1);
  *(_QWORD *)(a1 + 8) = v1 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1);
}
