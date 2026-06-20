__int64 __fastcall synx_release_n(unsigned __int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x9
  __int64 (__fastcall *v4)(_QWORD); // x9

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a1 <= 0xFFFFFFFFFFFFF000LL )
    {
      v3 = *(_QWORD *)(a1 + 16);
      if ( v3 )
      {
        v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 112);
        if ( v4 )
        {
          if ( *((_DWORD *)v4 - 1) != -2081307906 )
            __break(0x8229u);
          return v4(a1);
        }
      }
    }
  }
  return result;
}
