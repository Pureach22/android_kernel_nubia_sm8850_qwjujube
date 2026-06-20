__int64 __fastcall msm_cvp_dma_buf_vmap(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0

  result = dma_buf_vmap_unlocked(a1, a2);
  a2[2] = *a2;
  return result;
}
