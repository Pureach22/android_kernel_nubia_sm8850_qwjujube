__int64 __fastcall adreno_hwsched_unregister_contexts(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8

  raw_read_lock(a1 + 11208);
  idr_for_each(a1 + 11184, unregister_context, 0);
  result = raw_read_unlock(a1 + 11208);
  v3 = *(_QWORD *)(a1 + 22944);
  if ( v3 )
  {
    *(_DWORD *)(v3 + 20) = *(_DWORD *)(v3 + 24);
    __dsb(0xFu);
  }
  *(_BYTE *)(a1 + 23144) = 0;
  return result;
}
