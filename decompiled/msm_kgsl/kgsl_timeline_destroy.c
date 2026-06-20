__int64 __fastcall kgsl_timeline_destroy(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 8) != a1 + 8 )
    __break(0x800u);
  if ( *(_QWORD *)(a1 + 24) != a1 + 24 )
    __break(0x800u);
  return kfree(a1 - 32);
}
