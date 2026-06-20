__int64 __fastcall dp_nud_ignore_tracking(__int64 result, char a2)
{
  if ( !*(_DWORD *)(result + 28) )
  {
    if ( *(_BYTE *)(*(_QWORD *)result + 202LL) )
      *(_BYTE *)(result + 3481) = a2 & 1;
  }
  return result;
}
