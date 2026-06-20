__int64 __fastcall skip_ib_capture_store(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0

  LODWORD(result) = kstrtobool(a2, a1 + 11301);
  if ( (_DWORD)result )
    return (int)result;
  else
    return a3;
}
