__int64 __fastcall tmc_etr_get_data_sg_buf(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x9
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x10
  __int64 v7; // x8
  __int64 result; // x0

  v4 = **(_QWORD **)(a1 + 56);
  v5 = (__int64)*(int *)(v4 + 64) << 12;
  v6 = v5 - a2;
  if ( v5 <= a2 )
    return -22;
  v7 = a2 & 0xFFF;
  if ( v6 >= a3 )
    v6 = a3;
  if ( v6 >= 4096 - v7 )
    result = 4096 - v7;
  else
    result = v6;
  if ( v6 )
    *a4 = (((*(_QWORD *)(*(_QWORD *)(v4 + 80) + 8LL * (int)(a2 >> 12)) << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL
         | 0xFF00000000000000LL)
        + v7;
  return result;
}
