__int64 __fastcall wcd939x_hph_xtalk_put(__int64 a1, __int64 a2)
{
  unsigned int v2; // w3
  __int64 v4; // x0
  __int64 v5; // x9
  __int64 v6; // x10

  v2 = *(_DWORD *)(a2 + 72);
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL);
  if ( v2 > 1 || (v5 = *(unsigned int *)(*(_QWORD *)(a1 + 120) + 20LL), (unsigned int)v5 > 1) )
  {
    dev_err(v4, "%s: Invalid xtalk value = %d\n", "wcd939x_hph_xtalk_put", v2);
    return 4294967274LL;
  }
  else
  {
    v6 = *(_QWORD *)(v4 + 152);
    *(_DWORD *)(v6 + 4 * v5 + 272) = v2;
    return 0;
  }
}
