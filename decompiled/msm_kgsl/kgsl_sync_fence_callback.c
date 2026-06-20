__int64 __fastcall kgsl_sync_fence_callback(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 (__fastcall *v3)(_QWORD); // x8

  v2 = *(_QWORD *)(a2 + 32);
  v3 = *(__int64 (__fastcall **)(_QWORD))(a2 + 40);
  if ( *((_DWORD *)v3 - 1) != -2091637267 )
    __break(0x8228u);
  return v3(v2);
}
