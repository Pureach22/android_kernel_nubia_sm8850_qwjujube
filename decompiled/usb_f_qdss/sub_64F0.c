__int64 __fastcall sub_64F0(__int64 a1, __int64 a2)
{
  void *v2; // x25

  __arm_mte_set_tag((void *)(a2 - 2336), v2);
  return usb_qdss_write(a1, a2 - 2336);
}
