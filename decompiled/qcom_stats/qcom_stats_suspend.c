__int64 __fastcall qcom_stats_suspend(__int64 a1)
{
  __int64 v1; // x20
  __int64 *v2; // x19
  __int64 v3; // x21
  __int64 v4; // x8
  unsigned __int64 v5; // x0
  __int64 v6; // x8
  unsigned __int64 v7; // x10
  unsigned __int64 v8; // x9
  unsigned int v9; // w11
  __int64 v10; // x19
  unsigned int v11; // w22

  if ( subsystem_stats_debug_on == 1 )
  {
    v1 = *(_QWORD *)(a1 + 152);
    mutex_lock(&sleep_stats_mutex);
    v2 = &qword_168;
    v3 = -480;
    do
    {
      v5 = qcom_smem_get(*((unsigned int *)v2 - 1), *((unsigned int *)v2 - 2), 0);
      if ( v5 < 0xFFFFFFFFFFFFF001LL )
      {
        *(_BYTE *)v2 = 0;
        v4 = b_subsystem_stats + v3;
        *(_DWORD *)(v4 + 480) = *(_DWORD *)v5;
        *(_DWORD *)(v4 + 484) = *(_DWORD *)(v5 + 4);
        *(_QWORD *)(v4 + 488) = *(_QWORD *)(v5 + 8);
        *(_QWORD *)(v4 + 496) = *(_QWORD *)(v5 + 16);
        *(_QWORD *)(v4 + 504) = *(_QWORD *)(v5 + 24);
      }
      else
      {
        *(_BYTE *)v2 = 1;
      }
      v3 += 32;
      v2 += 3;
    }
    while ( v3 );
    v6 = *(_QWORD *)(v1 + 8);
    v7 = *(_QWORD *)(v6 + 24);
    if ( v7 )
    {
      v8 = 0;
      v9 = 0;
      v10 = 0;
      do
      {
        v11 = v9;
        if ( v7 > v9 )
          v10 = *(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL * v9 + 8);
        if ( v10 )
        {
          _memcpy_fromio(b_system_stats + 32 * v8, v10, 32);
          v6 = *(_QWORD *)(v1 + 8);
        }
        v9 = v11 + 1;
        v7 = *(_QWORD *)(v6 + 24);
        v8 = (int)(v11 + 1);
      }
      while ( v7 > v8 );
    }
    mutex_unlock(&sleep_stats_mutex);
  }
  return 0;
}
