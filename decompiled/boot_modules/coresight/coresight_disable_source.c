__int64 __fastcall coresight_disable_source(_QWORD *a1)
{
  __int64 (*v2)(void); // x8
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 (*v6)(void); // x9

  v2 = *(__int64 (**)(void))(*(_QWORD *)(a1[3] + 16LL) + 16LL);
  if ( *((_DWORD *)v2 - 1) != 1233040329 )
    __break(0x8228u);
  result = v2();
  v4 = *a1;
  if ( *(int *)(*a1 + 4LL) >= 1 )
  {
    v5 = 0;
    do
    {
      result = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 8) + 8 * v5) + 16LL);
      if ( result )
      {
        if ( *(_DWORD *)(result + 8) == 4 )
        {
          v6 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(result + 24) + 24LL) + 8LL);
          if ( v6 )
          {
            if ( *((_DWORD *)v6 - 1) != -1331650805 )
              __break(0x8229u);
            result = v6();
            v4 = *a1;
          }
        }
      }
      ++v5;
    }
    while ( v5 < *(int *)(v4 + 4) );
  }
  return result;
}
