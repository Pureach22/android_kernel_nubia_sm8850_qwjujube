_QWORD *__fastcall check_free_list_for_invalid_flush(_QWORD *result)
{
  unsigned __int64 v1; // x8
  unsigned __int64 v2; // x9
  unsigned __int64 v3; // x10
  unsigned int v4; // w11
  __int64 v5; // x14
  unsigned __int64 v6; // t2
  __int64 v7; // x9
  unsigned __int64 *v8; // x9
  __int64 v9; // t1

  if ( *(_DWORD *)(result[5] + 132LL) )
  {
    v1 = result[2528];
    if ( v1 )
    {
      v2 = 0;
      v3 = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
      v4 = 1;
      do
      {
        v5 = result[2526];
        HIDWORD(v6) = **(_DWORD **)(v5 + 56 * v2 + 24) + 1379995772;
        LODWORD(v6) = HIDWORD(v6);
        if ( (unsigned int)(v6 >> 28) <= 3 )
        {
          v7 = v5 + 56 * v2;
          v9 = *(_QWORD *)(v7 + 48);
          v8 = (unsigned __int64 *)(v7 + 48);
          if ( !v9 )
          {
            *v8 = v3;
            v1 = result[2528];
          }
        }
        v2 = v4++;
      }
      while ( v1 > v2 );
    }
  }
  return result;
}
