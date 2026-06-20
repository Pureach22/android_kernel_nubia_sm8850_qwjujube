__int64 __fastcall wcd939x_hph_xtalk_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x3
  __int64 v3; // x0
  __int64 v4; // x9

  v2 = *(unsigned int *)(*(_QWORD *)(a1 + 120) + 20LL);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL);
  if ( (unsigned int)v2 >= 2 )
  {
    dev_err(v3, "%s: Invalid xtalk value = %d\n", "wcd939x_hph_xtalk_get", v2);
    return 4294967274LL;
  }
  else
  {
    v4 = *(_QWORD *)(v3 + 152);
    *(_QWORD *)(a2 + 72) = *(int *)(v4 + 4 * v2 + 272);
    return 0;
  }
}
