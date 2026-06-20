__int64 __fastcall msm_vidc_prepare_buf(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w1
  __int64 vb2q; // x0
  __int64 result; // x0
  __int64 v9; // x2
  unsigned int v10; // w19

  v4 = *(_DWORD *)(a3 + 4);
  if ( (unsigned int)(v4 - 13) >= 2 && ((unsigned int)(v4 - 9) > 1 || !*(_DWORD *)(a3 + 72)) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_834D4, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_prepare_buf");
    return 4294967274LL;
  }
  vb2q = msm_vidc_get_vb2q(a1);
  if ( !vb2q )
    return 4294967274LL;
  result = vb2_prepare_buf(vb2q, a2, a3);
  if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
  {
    v9 = a1 + 340;
    v10 = result;
    printk(&unk_8C95C, "err ", v9, "msm_vidc_prepare_buf", (unsigned int)result);
    return v10;
  }
  return result;
}
