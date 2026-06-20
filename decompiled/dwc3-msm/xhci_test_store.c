__int64 __fastcall xhci_test_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x22
  __int64 v5; // x8
  __int64 v7; // x21
  __int64 v8; // x20

  v4 = *(_QWORD *)(a1 + 152);
  v5 = *(_QWORD *)(v4 + 40);
  if ( v5 )
  {
    v7 = a4;
    if ( (*(_BYTE *)(v4 + 746) & 1) != 0 || *(_DWORD *)(v4 + 752) )
    {
      dev_err(a1, "USB is not in host mode\n");
    }
    else
    {
      v8 = *(_QWORD *)(v5 + 168);
      _pm_runtime_resume(*(_QWORD *)(v8 + 384) + 16LL, 0);
      pm_runtime_forbid(*(_QWORD *)(v8 + 384) + 16LL);
      LODWORD(v8) = readl((unsigned int *)(*(_QWORD *)(v4 + 8) + (unsigned int)(*(_DWORD *)(v4 + 2800) + 1028)));
      dev_info(a1, "USB PORTPMSC val:%x\n", v8);
      dev_info(a1, "writing %x to USB PORTPMSC\n", v8 | 0x40000000);
      writel(v8 | 0x40000000, (unsigned int *)(*(_QWORD *)(v4 + 8) + (unsigned int)(*(_DWORD *)(v4 + 2800) + 1028)));
    }
    return v7;
  }
  return a4;
}
