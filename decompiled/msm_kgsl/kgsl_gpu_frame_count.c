__int64 __fastcall kgsl_gpu_frame_count(int a1, _QWORD *a2)
{
  __int64 *v3; // x0

  if ( !a2 )
    return 4294967274LL;
  v3 = kgsl_process_private_find(a1);
  if ( !v3 )
    return 4294967294LL;
  *a2 = v3[48];
  kgsl_process_private_put((unsigned int *)v3);
  return 0;
}
