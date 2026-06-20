__int64 __fastcall rmnet_perf_coal_stat(__int64 result, unsigned __int8 a2, __int64 a3, int a4)
{
  unsigned __int64 v4; // x10
  char *v5; // x8
  _QWORD *v6; // x8
  unsigned __int64 v7; // x10
  char *v8; // x8
  unsigned __int64 v9; // x10
  char *v10; // x8
  unsigned __int64 v11; // x10
  char *v12; // x8

  if ( (unsigned int)(unsigned __int8)result - 17 >= 0xFFFFFFF0 && a2 <= 0xFu )
  {
    if ( a4 > 1 )
    {
      if ( a4 == 2 )
      {
        v11 = ((unsigned __int64)a2 << 6) + 1192LL * (unsigned __int8)result + 88;
        if ( v11 >> 3 <= 0x9E0 )
        {
          v12 = (char *)&stats_store + 1192 * (unsigned __int8)result + 64 * (unsigned __int64)a2;
          ++*((_QWORD *)v12 + 15);
          if ( v11 >> 8 <= 0x4E )
          {
            v6 = v12 + 128;
            goto LABEL_20;
          }
        }
      }
      else
      {
        if ( a4 != 3 )
          return result;
        v7 = ((unsigned __int64)a2 << 6) + 1192LL * (unsigned __int8)result + 88;
        if ( v7 >> 3 <= 0x9DE )
        {
          v8 = (char *)&stats_store + 1192 * (unsigned __int8)result + 64 * (unsigned __int64)a2;
          ++*((_QWORD *)v8 + 17);
          if ( v7 >> 4 <= 0x4EE )
          {
            v6 = v8 + 144;
            goto LABEL_20;
          }
        }
      }
    }
    else if ( a4 )
    {
      if ( a4 != 1 )
        return result;
      v4 = ((unsigned __int64)a2 << 6) + 1192LL * (unsigned __int8)result + 88;
      if ( v4 >> 3 <= 0x9E2 )
      {
        v5 = (char *)&stats_store + 1192 * (unsigned __int8)result + 64 * (unsigned __int64)a2;
        ++*((_QWORD *)v5 + 13);
        if ( v4 >> 4 <= 0x4F0 )
        {
          v6 = v5 + 112;
LABEL_20:
          *v6 += a3;
          return result;
        }
      }
    }
    else
    {
      v9 = ((unsigned __int64)a2 << 6) + 1192LL * (unsigned __int8)result + 88;
      if ( v9 >> 3 <= 0x9E4 )
      {
        v10 = (char *)&stats_store + 1192 * (unsigned __int8)result + 64 * (unsigned __int64)a2;
        ++*((_QWORD *)v10 + 11);
        if ( v9 >> 5 <= 0x278 )
        {
          v6 = v10 + 96;
          goto LABEL_20;
        }
      }
    }
    __break(1u);
    JUMPOUT(0x6DC0);
  }
  return result;
}
