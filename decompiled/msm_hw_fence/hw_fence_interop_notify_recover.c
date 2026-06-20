__int64 __fastcall hw_fence_interop_notify_recover(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 (__fastcall *v5)(__int64, __int64, __int64, __int64, unsigned __int64); // x8

  if ( a1 && a1 < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = (__int64 (__fastcall *)(__int64, __int64, __int64, __int64, unsigned __int64))off_2B788;
    if ( off_2B788 )
    {
      if ( *((_DWORD *)off_2B788 - 1) != 609031242 )
        __break(0x8228u);
      return v5(5, a2, a3, a4, a1);
    }
    else
    {
      if ( (~msm_hw_fence_debug_level & 0x10004) == 0 )
        printk(&unk_28422, "hw_fence_interop_notify_recover", 447, off_2B790, a1);
      return 0;
    }
  }
  else
  {
    printk(&unk_234EF, "hw_fence_interop_notify_recover", 441, v4, a1);
    return 4294967274LL;
  }
}
