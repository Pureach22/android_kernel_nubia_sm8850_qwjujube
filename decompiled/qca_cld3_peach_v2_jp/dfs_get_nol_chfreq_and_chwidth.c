__int64 __fastcall dfs_get_nol_chfreq_and_chwidth(__int64 result, _DWORD *a2, _DWORD *a3, int a4)
{
  unsigned __int16 *v4; // x8

  if ( result )
  {
    v4 = (unsigned __int16 *)(result + 24LL * a4);
    *a2 = *v4;
    *a3 = v4[1];
  }
  return result;
}
