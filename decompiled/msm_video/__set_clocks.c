__int64 __fastcall _set_clocks(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8
  unsigned __int64 v3; // x19
  int v6; // w8
  __int64 result; // x0
  unsigned int v8; // w19

  v2 = *(_QWORD *)(a1 + 3904);
  v3 = *(_QWORD *)(v2 + 64);
  if ( v3 >= v3 + 72LL * *(unsigned int *)(v2 + 72) )
    return 0;
  while ( 1 )
  {
    if ( *(_BYTE *)(v3 + 20) != 1 )
      goto LABEL_3;
    v6 = *(_DWORD *)(v3 + 56) - 1;
    if ( a2 < v6 )
      v6 = a2;
    a2 = v6 & ~(v6 >> 31);
    result = _opp_set_rate(a1, *(_QWORD *)(*(_QWORD *)(v3 + 64) + 8LL * a2));
    if ( (_DWORD)result )
      break;
    result = _set_clk_rate(a1, v3, *(_QWORD *)(*(_QWORD *)(v3 + 64) + 8LL * a2));
    if ( (_DWORD)result )
      return result;
    v2 = *(_QWORD *)(a1 + 3904);
LABEL_3:
    v3 += 72LL;
    if ( v3 >= *(_QWORD *)(v2 + 64) + 72 * (unsigned __int64)*(unsigned int *)(v2 + 72) )
      return 0;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v8 = result;
    printk(&unk_96680, "err ", 0xFFFFFFFFLL, "codec", "__set_clocks");
    return v8;
  }
  return result;
}
