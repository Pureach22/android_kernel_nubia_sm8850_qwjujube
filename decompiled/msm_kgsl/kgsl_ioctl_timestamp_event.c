__int64 __fastcall kgsl_ioctl_timestamp_event(_QWORD *a1, __int64 a2, __int64 a3)
{
  if ( *(_DWORD *)a3 == 2 )
    return (int)kgsl_add_fence_event(
                  *a1,
                  *(unsigned int *)(a3 + 8),
                  *(unsigned int *)(a3 + 4),
                  *(_QWORD *)(a3 + 16),
                  *(unsigned int *)(a3 + 24),
                  a1);
  else
    return -22;
}
