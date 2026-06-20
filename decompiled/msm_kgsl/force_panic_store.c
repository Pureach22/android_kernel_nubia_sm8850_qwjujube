__int64 __fastcall force_panic_store(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0

  LODWORD(result) = kstrtobool(a2, a1 + 11300);
  if ( (_DWORD)result )
    return (int)result;
  else
    return a3;
}
