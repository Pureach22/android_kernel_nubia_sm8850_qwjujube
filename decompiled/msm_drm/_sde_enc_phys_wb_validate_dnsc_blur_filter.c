__int64 __fastcall sde_enc_phys_wb_validate_dnsc_blur_filter(_DWORD *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // w6
  void *v5; // x0

  if ( a3 - 1 >= a2 )
  {
    printk(&unk_232BFF, "_sde_enc_phys_wb_validate_dnsc_blur_filter");
  }
  else
  {
    if ( a1[1] > a2 || a1[2] < a2 || a1[3] > a3 || a1[4] < a3 )
    {
      v5 = &unk_232C3A;
    }
    else
    {
      v3 = (a3 - 1 + a2) / a3;
      if ( v3 >= a1[5] && v3 <= a1[6] )
        return 0;
      v5 = &unk_25C108;
    }
    printk(v5, "_sde_enc_phys_wb_validate_dnsc_blur_filter");
  }
  return 4294967274LL;
}
