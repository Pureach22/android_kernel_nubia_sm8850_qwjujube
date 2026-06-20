__int64 __fastcall msm_vidc_fence_destroy_fd(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x8

  v2 = *(_QWORD **)(a2 + 256);
  if ( v2 )
    fput(*v2);
  put_unused_fd(*(unsigned int *)(a2 + 152));
  *(_DWORD *)(a2 + 152) = -1;
  return 0;
}
