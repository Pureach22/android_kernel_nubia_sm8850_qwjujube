__int64 __fastcall sub_1024B4(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x13

  *(_DWORD *)(v4 + 208) = 0;
  *(_DWORD *)(v4 + 212) = a4;
  return kgsl_drawobj_sync_add_syncpoints(a1, a2, a3, a4);
}
