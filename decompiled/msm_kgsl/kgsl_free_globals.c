__int64 __fastcall kgsl_free_globals(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x21
  _QWORD *v3; // x0
  _QWORD *v4; // x23
  __int64 v5; // x8
  void (*v6)(void); // x9
  void (*v7)(void); // x8
  _QWORD *v8; // x20
  _QWORD *v9; // x8
  _QWORD *v10; // x9
  _QWORD *v11; // x9

  v1 = *(_QWORD **)(result + 13112);
  v2 = result + 13112;
  if ( v1 != (_QWORD *)(result + 13112) )
  {
    do
    {
      v3 = v1 - 27;
      v4 = (_QWORD *)*v1;
      if ( v1 != qword_D8 )
      {
        if ( *(v1 - 22) )
        {
          v5 = *(v1 - 19);
          if ( v5 )
          {
            v6 = *(void (**)(void))(v5 + 40);
            if ( v6 )
            {
              if ( *((_DWORD *)v6 - 1) != 1555154090 )
                __break(0x8229u);
              v6();
              v5 = *(v1 - 19);
              v3 = v1 - 27;
            }
            v7 = *(void (**)(void))(v5 + 16);
            if ( v7 )
            {
              v8 = v3;
              if ( *((_DWORD *)v7 - 1) != 1555154090 )
                __break(0x8228u);
              v7();
              v3 = v8;
            }
          }
        }
      }
      v9 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v9 == v1 && (v10 = (_QWORD *)*v1, *(_QWORD **)(*v1 + 8LL) == v1) )
      {
        v10[1] = v9;
        *v9 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
        v3 = v11;
      }
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      result = kfree(v3);
      v1 = v4;
    }
    while ( v4 != (_QWORD *)v2 );
  }
  return result;
}
