__int64 __fastcall crm_write_bw_pt_vote(__int64 a1, int a2, int a3, unsigned int *a4)
{
  __int64 v4; // x19
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x8
  _DWORD *v8; // x20
  __int64 result; // x0

  v4 = *(_QWORD *)(a1 + 152);
  if ( !a1 )
    goto LABEL_10;
  v5 = 72;
  if ( !a2 )
    v5 = 48;
  v6 = 64;
  v7 = *(unsigned int *)(v4 + v5);
  if ( !a2 )
    v6 = 40;
  if ( (int)v7 >= 1 )
  {
    v8 = *(_DWORD **)(v4 + v6);
    while ( v8[8] != a3 )
    {
      --v7;
      v8 += 48;
      if ( !v7 )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v8 = nullptr;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(v4 + 288) + 4LL) & 4) == 0 )
    return 0xFFFFFFFFLL;
  result = 4294967274LL;
  if ( a4 && v8 && *a4 < v8[34] && a4[1] < v8[35] && (a4[2] & 0x20000000) != 0 )
  {
    crm_cache_vcd_votes((__int64)v8, 2u, a4);
    if ( a2 == 1 )
      crm_send_cmd(v4, (__int64)v8, 2u, (int *)a4, 1);
    return 0;
  }
  return result;
}
