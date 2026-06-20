__int64 __fastcall ddr_cdev_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 168);
  result = *(_QWORD *)(v1 + 16);
  if ( result )
  {
    icc_set_bw(result, 0, **(unsigned int **)(v1 + 32));
    result = icc_put(*(_QWORD *)(v1 + 16));
    *(_QWORD *)(v1 + 16) = 0;
  }
  return result;
}
