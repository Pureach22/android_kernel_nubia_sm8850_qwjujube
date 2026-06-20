__int64 __fastcall adreno_gpu_bus_set(__int64 a1, int a2, int a3)
{
  __int64 (*v3)(void); // x8
  __int64 v8; // x9

  v3 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 160LL) + 56LL);
  if ( v3 )
  {
    if ( *((_DWORD *)v3 - 1) != 380066992 )
      __break(0x8228u);
    return v3();
  }
  else
  {
    if ( *(_DWORD *)(a1 + 10404) != a2 || *(_DWORD *)(a1 + 10464) != a3 )
    {
      kgsl_icc_set_tag(a1 + 8832);
      v8 = *(_QWORD *)(a1 + 10392);
      *(_DWORD *)(a1 + 10404) = a2;
      *(_DWORD *)(a1 + 10464) = a3;
      icc_set_bw(*(_QWORD *)(a1 + 10456), (unsigned int)(1000 * a3), *(unsigned int *)(v8 + 4LL * a2));
    }
    return 0;
  }
}
