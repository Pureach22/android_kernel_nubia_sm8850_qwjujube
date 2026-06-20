__int64 __fastcall sub_130DA4(__int64 a1)
{
  __asm { STGP            X26, X0, [X23,#0x5C]! }
  return kgsl_sync_timeline_create(a1);
}
