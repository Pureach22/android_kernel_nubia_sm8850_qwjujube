__int64 __fastcall sub_E7E74(int a1, int a2, int a3)
{
  __asm { PRFM            #1, 0xFFFFFFFFFFFF02A8 }
  return adreno_ringbuffer_setup(a1, a2, a3);
}
