__int64 __fastcall mmrm_sw_clk_client_getval(__int64 a1, __int64 a2, _QWORD *a3)
{
  unsigned int v3; // w3
  __int64 v4; // x8
  __int64 v5; // x9
  void *v7; // x0

  if ( a2 )
  {
    v3 = *(_DWORD *)(a2 + 4);
    if ( v3 >= *(_DWORD *)(a1 + 72) )
    {
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
        printk(&unk_C610, "err ", "mmrm_sw_clk_client_getval");
      goto LABEL_12;
    }
    v4 = *(_QWORD *)(a1 + 64) + 720LL * v3;
    if ( *(_QWORD *)(v4 + 128) )
    {
      v5 = *(_QWORD *)(v4 + 664);
      *a3 = v5;
      a3[1] = v5;
      a3[2] = *(_QWORD *)(v4 + 664);
      return 0;
    }
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
    {
      v7 = &unk_C595;
      goto LABEL_11;
    }
  }
  else if ( (~msm_mmrm_debug & 0x10001) == 0 )
  {
    v7 = &unk_CA9A;
LABEL_11:
    printk(v7, "err ", "mmrm_sw_clk_client_getval");
  }
LABEL_12:
  if ( (~msm_mmrm_debug & 0x10001) == 0 )
    printk(&unk_DA62, "err ", "mmrm_sw_clk_client_getval");
  return 4294967274LL;
}
