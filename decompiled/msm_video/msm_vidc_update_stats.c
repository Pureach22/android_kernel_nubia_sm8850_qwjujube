unsigned __int64 __fastcall msm_vidc_update_stats(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w8

  v5 = *(_DWORD *)(a1 + 308);
  if ( !(_DWORD)a3 && v5 == 2 || (_DWORD)a3 == 3 && v5 == 1 )
    *(_QWORD *)(a1 + 4296) += *(unsigned int *)(a2 + 48);
  return msm_vidc_debugfs_update(a1, a3, a3, a4, a5);
}
