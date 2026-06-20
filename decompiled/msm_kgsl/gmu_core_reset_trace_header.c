__int64 *__fastcall gmu_core_reset_trace_header(__int64 *result)
{
  _QWORD *v1; // x8
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x9

  if ( *((_BYTE *)result + 10) == 1 )
  {
    v1 = *(_QWORD **)(*result + 8);
    v1[4] = 0;
    v1[5] = 0;
    v1[2] = 0;
    v1[3] = 0;
    *v1 = 0;
    v1[1] = 0;
    v2 = *result;
    *((_WORD *)result + 4) = 0;
    v3 = *(_QWORD *)(v2 + 8);
    *(_DWORD *)(v3 + 40) = 5;
    *(_QWORD *)(v3 + 4) = 0x5040000001LL;
    *(_QWORD *)(v3 + 32) = *(unsigned int *)(*result + 184);
    v4 = *(_QWORD *)(*result + 40);
    *(_DWORD *)(v3 + 44) = 1;
    *(_DWORD *)(v3 + 12) = v4;
    *((_BYTE *)result + 10) = 0;
  }
  return result;
}
