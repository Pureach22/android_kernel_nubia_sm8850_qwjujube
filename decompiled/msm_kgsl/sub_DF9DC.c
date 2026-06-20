__int64 __fastcall sub_DF9DC(__int64 a1, __int64 a2)
{
  __asm { STGP            X14, X11, [X11],#-0xB8 }
  return adreno_hwsched_drawobj_replay(a1, a2);
}
