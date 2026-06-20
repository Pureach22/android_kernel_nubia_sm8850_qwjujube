__int64 __fastcall msm_vb2_buf_out_validate(__int64 a1)
{
  if ( a1 )
  {
    *(_DWORD *)(a1 + 580) = 1;
    return 0;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_9283B, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_buf_out_validate");
    return 4294967274LL;
  }
}
