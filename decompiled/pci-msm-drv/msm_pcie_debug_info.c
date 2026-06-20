__int64 __fastcall msm_pcie_debug_info(__int64 a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v6; // w19
  __int64 v8; // x20

  if ( !a1 )
  {
    printk(&unk_21D37);
    return 4294967277LL;
  }
  v6 = a2 - 11;
  if ( (unsigned int)(a2 - 11) <= 2 )
  {
    if ( (unsigned int)(a3 - 9) <= 0xFFFFFFF7 )
    {
      printk(&unk_2DE44);
      printk(&unk_30427);
      return 4294967274LL;
    }
    base_sel = a3;
    v8 = a1;
    printk(&unk_2D3EE);
    a1 = v8;
    if ( v6 <= 1 )
    {
      wr_offset = a4;
      wr_mask = a5;
      wr_value = a6;
      printk(&unk_2F519);
      printk(&unk_23293);
      printk(&unk_2A52A);
      a1 = v8;
    }
  }
  rc_sel = 1LL << *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 232LL) + 200LL) + 1348LL);
  ((void (*)(void))msm_pcie_sel_debug_testcase)();
  return 0;
}
