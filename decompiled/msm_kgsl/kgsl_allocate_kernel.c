__int64 __fastcall kgsl_allocate_kernel(__int64 a1, _QWORD *a2, __int64 a3, unsigned __int64 a4, int a5)
{
  __int64 result; // x0
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x8
  void (__fastcall *v9)(_QWORD); // x9
  unsigned int v10; // w20
  void (__fastcall *v11)(_QWORD); // x8
  unsigned int v12; // w20

  result = kgsl_allocate_user(a1, a2, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    v7 = *(__int64 (__fastcall **)(_QWORD))(a2[8] + 24LL);
    if ( v7 )
    {
      if ( *((_DWORD *)v7 - 1) != -441828660 )
        __break(0x8228u);
      result = v7(a2);
      if ( (_DWORD)result )
      {
        if ( a2 )
        {
          if ( a2[5] )
          {
            v8 = a2[8];
            if ( v8 )
            {
              v9 = *(void (__fastcall **)(_QWORD))(v8 + 40);
              if ( v9 )
              {
                v10 = result;
                if ( *((_DWORD *)v9 - 1) != 1555154090 )
                  __break(0x8229u);
                v9(a2);
                v8 = a2[8];
                result = v10;
              }
              v11 = *(void (__fastcall **)(_QWORD))(v8 + 16);
              if ( v11 )
              {
                v12 = result;
                if ( *((_DWORD *)v11 - 1) != 1555154090 )
                  __break(0x8228u);
                v11(a2);
                return v12;
              }
            }
          }
        }
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
