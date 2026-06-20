__int64 __fastcall hfi_create_header(__int64 a1, unsigned int a2, int a3, int a4)
{
  if ( a1 && a2 > 0x1F )
  {
    *(_QWORD *)(a1 + 20) = 0;
    *(_QWORD *)(a1 + 12) = 0;
    *(_DWORD *)a1 = 32;
    *(_DWORD *)(a1 + 4) = a3;
    *(_DWORD *)(a1 + 8) = a4;
    *(_DWORD *)(a1 + 28) = 0;
    return 0;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "hfi_create_header");
    return 4294967274LL;
  }
}
