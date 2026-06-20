__int64 __fastcall ddr_set_cur_state(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x9
  unsigned int v7; // w19

  v2 = *(_QWORD *)(a1 + 944);
  if ( *(unsigned int *)(v2 + 4) < a2 )
    return 4294967274LL;
  if ( *(_DWORD *)v2 == a2 )
    return 0;
  result = icc_set_bw(*(_QWORD *)(v2 + 16), 0, *(unsigned int *)(*(_QWORD *)(v2 + 32) + 4 * a2));
  if ( (result & 0x80000000) != 0 )
  {
    v5 = *(_QWORD *)(v2 + 24);
    v6 = *(_QWORD *)(v2 + 32);
    v7 = result;
    dev_err(v5, "Error placing DDR freq%u. err:%d\n", *(_DWORD *)(v6 + 4 * a2), result);
    return v7;
  }
  else
  {
    *(_DWORD *)v2 = a2;
  }
  return result;
}
