__int64 __fastcall tmc_sg_table_get_data(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x10
  __int64 v6; // x9
  __int64 result; // x0

  v4 = (__int64)*(int *)(a1 + 64) << 12;
  v5 = v4 - a2;
  if ( v4 <= a2 )
    return -22;
  v6 = a2 & 0xFFF;
  if ( v5 >= a3 )
    v5 = a3;
  if ( v5 >= 4096 - v6 )
    result = 4096 - v6;
  else
    result = v5;
  if ( v5 )
    *a4 = (((*(_QWORD *)(*(_QWORD *)(a1 + 80) + 8LL * (int)(a2 >> 12)) << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL
         | 0xFF00000000000000LL)
        + v6;
  return result;
}
