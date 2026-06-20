__int64 __fastcall cm_get_state(unsigned int *a1)
{
  if ( a1 && *(_QWORD *)a1 && (*(_DWORD *)(*(_QWORD *)a1 + 16LL) & 0xFFFFFFFD) == 0 )
    return a1[20];
  else
    return 5;
}
