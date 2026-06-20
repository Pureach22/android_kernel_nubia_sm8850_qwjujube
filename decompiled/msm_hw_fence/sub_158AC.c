__int64 __fastcall sub_158AC(double a1)
{
  __int64 v1; // x24
  __int64 v2; // d27

  *(double *)(v1 - 216) = a1;
  *(_QWORD *)(v1 - 208) = v2;
  return hw_fence_get_txq_skip_wr_idx();
}
