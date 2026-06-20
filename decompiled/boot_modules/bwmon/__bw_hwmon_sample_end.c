__int64 __fastcall _bw_hwmon_sample_end(_QWORD *a1)
{
  __int64 v1; // x22
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  int v5; // w4
  __int64 v6; // x10
  unsigned __int64 v7; // x2
  __int64 result; // x0
  __int64 v9; // x0
  __int64 (__fastcall *v10)(_QWORD); // x10
  __int64 v11; // x21
  unsigned __int64 v12; // x20
  __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x2
  unsigned __int64 v16; // x8
  __int64 v17; // x9
  int v18; // w9
  int v19; // w9

  v1 = a1[22];
  if ( a1[3] )
  {
    v3 = (__int64 (*)(void))a1[4];
    if ( *((_DWORD *)v3 - 1) != 1485313329 )
      __break(0x8228u);
    v4 = v3();
    v5 = 1;
    v6 = *(_QWORD *)(v1 + 344);
    v7 = (1000000 * v4 / (unsigned __int64)(unsigned int)(1000 * *(_DWORD *)(v1 + 112)) + 0xFFFFF) >> 20;
    *(_QWORD *)(v1 + 224) = v7;
    if ( v7 <= *(_QWORD *)(v6 + 232) )
      v5 = 2 * (v7 < *(_QWORD *)(v6 + 240));
    *(_DWORD *)(v1 + 296) = v5;
    *(_BYTE *)(v1 + 320) = 1;
    return 1;
  }
  else
  {
    v9 = ktime_get(a1);
    v10 = (__int64 (__fastcall *)(_QWORD))a1[4];
    v11 = v9;
    v12 = (unsigned int)(((int)v9 - *(_DWORD *)(v1 + 304)) / 1000);
    if ( *((_DWORD *)v10 - 1) != 1485313329 )
      __break(0x822Au);
    v13 = *(_QWORD *)(v1 + 216) + v10(a1);
    result = 1;
    v14 = 1000000 * v13 / v12 + 0xFFFFF;
    v15 = v14 >> 20;
    if ( *(_QWORD *)(v1 + 224) <= v14 >> 20 )
      v16 = v14 >> 20;
    else
      v16 = *(_QWORD *)(v1 + 224);
    v17 = *(_QWORD *)(v1 + 344);
    *(_QWORD *)(v1 + 216) = 0;
    *(_QWORD *)(v1 + 224) = v16;
    if ( v15 <= *(_QWORD *)(v17 + 232) )
    {
      if ( v15 >= *(_QWORD *)(v17 + 240) )
      {
        result = 0;
      }
      else
      {
        v18 = *(_DWORD *)(v1 + 300);
        if ( v18 )
        {
          v19 = v18 - 1;
          *(_DWORD *)(v1 + 300) = v19;
          result = 2 * (unsigned int)(v19 == 0);
        }
        else
        {
          result = 2;
        }
      }
    }
    *(_QWORD *)(v1 + 304) = v11;
    *(_DWORD *)(v1 + 296) = result;
    *(_BYTE *)(v1 + 320) = 1;
  }
  return result;
}
