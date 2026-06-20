__int64 __fastcall sub_88E8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 _X4)
{
  __asm { LDTRB           W16, [X4,#-0x72] }
  return system_heap_deferred_free();
}
