__int64 __fastcall sub_20D5C(__int64 a1, __int64 a2)
{
  __asm { SUBG            X17, X11, #0x1C0, #9 }
  return synx_util_get_fence_entry(a1, a2);
}
