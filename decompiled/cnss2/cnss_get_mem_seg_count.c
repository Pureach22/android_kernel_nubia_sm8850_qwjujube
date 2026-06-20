__int64 __fastcall cnss_get_mem_seg_count(int a1, _DWORD *a2)
{
  __int64 v2; // x9

  if ( !plat_env )
    return 4294967277LL;
  if ( !a1 )
  {
    v2 = 1720;
    goto LABEL_7;
  }
  if ( a1 == 1 )
  {
    v2 = 4144;
LABEL_7:
    *a2 = *(_DWORD *)(plat_env + v2);
    return 0;
  }
  return 4294967274LL;
}
