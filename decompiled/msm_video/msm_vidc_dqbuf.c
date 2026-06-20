__int64 __fastcall msm_vidc_dqbuf(__int64 a1, __int64 a2)
{
  int v3; // w1
  __int64 vb2q; // x0
  __int64 result; // x0
  __int64 v7; // x2
  unsigned int v8; // w19

  v3 = *(_DWORD *)(a2 + 4);
  if ( (unsigned int)(v3 - 13) >= 2 && ((unsigned int)(v3 - 9) > 1 || !*(_DWORD *)(a2 + 72)) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_834D4, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dqbuf");
    return 4294967274LL;
  }
  vb2q = msm_vidc_get_vb2q(a1);
  if ( !vb2q )
    return 4294967274LL;
  result = vb2_dqbuf(vb2q, a2, 1);
  if ( a1 && (_DWORD)result != -11 && (_DWORD)result && (msm_vidc_debug & 4) != 0 )
  {
    v7 = a1 + 340;
    v8 = result;
    printk(&unk_8C95C, "low ", v7, "msm_vidc_dqbuf", (unsigned int)result);
    return v8;
  }
  return result;
}
