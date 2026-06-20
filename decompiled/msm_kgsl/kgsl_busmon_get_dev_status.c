__int64 __fastcall kgsl_busmon_get_dev_status(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x10

  if ( *(_BYTE *)(*(_QWORD *)(a1 + 152) + 12960LL) != 1 )
    return 4294967225LL;
  result = 0;
  *a2 = last_status_0;
  v3 = a2[3];
  v4 = last_status_2;
  a2[1] = last_status_1;
  a2[2] = v4;
  if ( v3 )
  {
    *(_QWORD *)v3 = last_xstats;
    *(_QWORD *)(v3 + 8) = qword_17D170;
    *(_DWORD *)(v3 + 16) = qword_17D178;
    *(_QWORD *)(v3 + 24) = qword_17D180;
  }
  return result;
}
