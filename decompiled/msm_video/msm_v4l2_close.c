__int64 __fastcall msm_v4l2_close(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x9
  __int64 result; // x0

  if ( a1 && (v5 = *(_QWORD *)(a1 + 32)) != 0 && v5 != 1648 )
  {
    result = msm_vidc_close(v5 - 1648, a2, a3, a4, a5);
    *(_QWORD *)(a1 + 32) = 0;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_961DD, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_close");
    return 4294967274LL;
  }
  return result;
}
