__int64 __fastcall crtc_cmp(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = 0;
  if ( a1 )
  {
    if ( a2 )
      return (unsigned int)(*(_DWORD *)(*(_QWORD *)a1 + 32LL) - *(_DWORD *)(*(_QWORD *)a2 + 32LL));
  }
  return result;
}
