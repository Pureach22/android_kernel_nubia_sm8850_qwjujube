__int64 __fastcall hw_fence_ipcc_enable_protocol(__int64 a1, unsigned int a2)
{
  __int64 v2; // x30
  int v3; // w5
  __int64 v4; // x6
  __int64 v5; // x19

  if ( a1 && (v3 = *(_DWORD *)(a1 + 624), v4 = *(_QWORD *)(a1 + 648), v3) && v4 && *(_DWORD *)(a1 + 60) > a2 )
  {
    v5 = *(_QWORD *)(a1 + 608)
       + (unsigned int)(*(_DWORD *)(a1 + 620) * v3)
       + (int)(*(_DWORD *)(v4 + 16LL * a2 + 4) << 12);
    if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
      printk(&unk_20278, "hw_fence_ipcc_enable_protocol", 844, 1, v5 + 8);
    writel_relaxed(1u, (unsigned int *)(v5 + 8));
    return 0;
  }
  else
  {
    printk(&unk_28B7F, "hw_fence_ipcc_enable_protocol", 836, v2, a1);
    return 4294967274LL;
  }
}
