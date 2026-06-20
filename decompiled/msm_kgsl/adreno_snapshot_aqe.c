__int64 __fastcall adreno_snapshot_aqe(_QWORD *a1, _QWORD *a2, unsigned __int64 a3)
{
  _QWORD *v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10

  if ( (*(_BYTE *)(a1[1783] + 34LL) & 4) == 0 || !a1[1791] )
    return 0;
  if ( a3 > 0x1F )
  {
    *a2 = 0x600000014LL;
    v5 = *(_QWORD **)(a1[1791] + 8LL);
    v7 = v5[1];
    v6 = v5[2];
    a2[1] = *v5;
    a2[2] = v7;
    a2[3] = v6;
    return 32;
  }
  if ( !(unsigned int)__ratelimit(&adreno_snapshot_aqe__rs, "adreno_snapshot_aqe") )
    return 0;
  dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "AQE VERSION DEBUG");
  return 0;
}
