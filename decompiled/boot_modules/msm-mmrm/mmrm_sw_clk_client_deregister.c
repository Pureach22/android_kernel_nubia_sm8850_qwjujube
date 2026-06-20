__int64 __fastcall mmrm_sw_clk_client_deregister(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  int v5; // w8
  int v6; // w8
  __int64 v7; // x0

  if ( a2 )
  {
    if ( *(_DWORD *)(a2 + 4) < *(_DWORD *)(a1 + 72) )
    {
      mutex_lock(a1);
      v4 = *(_QWORD *)(a1 + 64) + 720LL * *(unsigned int *)(a2 + 4);
      v5 = *(_DWORD *)(v4 + 680);
      if ( !v5 || (v6 = v5 - 1, (*(_DWORD *)(v4 + 680) = v6) == 0) )
      {
        kfree(*(_QWORD *)(v4 + 712));
        v7 = *(_QWORD *)(v4 + 656);
        *(_QWORD *)(v4 + 712) = 0;
        kfree(v7);
        *(_QWORD *)(v4 + 128) = 0;
        *(_DWORD *)(v4 + 136) = 0;
        *(_BYTE *)(v4 + 688) = 0;
        *(_QWORD *)(v4 + 144) = 0;
        *(_QWORD *)(v4 + 152) = 0;
        *(_QWORD *)(v4 + 656) = 0;
        *(_QWORD *)(v4 + 664) = 0;
        *(_DWORD *)(v4 + 672) = 0;
        *(_QWORD *)(v4 + 692) = 0;
        *(_QWORD *)(v4 + 700) = 0;
      }
      mutex_unlock(a1);
      return 0;
    }
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_C610, "err ", "mmrm_sw_clk_client_deregister");
  }
  else if ( (~msm_mmrm_debug & 0x10001) == 0 )
  {
    printk(&unk_CA9A, "err ", "mmrm_sw_clk_client_deregister");
  }
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
    printk(&unk_DA62, "err ", "mmrm_sw_clk_client_deregister");
  return 4294967274LL;
}
