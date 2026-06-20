__int64 __fastcall adreno_drawctxt_sched(__int64 result)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  v1 = *(_QWORD *)(result + 20896);
  if ( v1 && (v2 = *(__int64 (**)(void))(v1 + 16)) != nullptr )
  {
    if ( *((_DWORD *)v2 - 1) != -1413602428 )
      __break(0x8228u);
    return v2();
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
