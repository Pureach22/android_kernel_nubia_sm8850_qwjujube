__int64 __fastcall cnss_get_fw_lpass_shared_mem(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x10

  v5 = cnss_bus_dev_to_plat_priv(a1, (__int64)a2);
  if ( !v5 )
    return 4294967274LL;
  v6 = *(unsigned int *)(v5 + 1720);
  if ( !(_DWORD)v6 )
    return 4294967274LL;
  v7 = 0;
  v8 = 40 * v6;
  while ( v7 != 2080 )
  {
    v9 = v5 + v7;
    if ( *(_DWORD *)(v5 + v7 + 1756) == 11 )
    {
      *a2 = *(_QWORD *)(v9 + 1744);
      *a3 = *(_QWORD *)(v9 + 1728);
      return 0;
    }
    v7 += 40;
    if ( v8 == v7 )
      return 4294967274LL;
  }
  __break(0x5512u);
  return cnss_athdiag_read();
}
