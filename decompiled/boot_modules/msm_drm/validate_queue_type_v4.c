__int64 __fastcall validate_queue_type_v4(_DWORD *a1)
{
  if ( a1[9] == 1 && (a1[8] || !a1[2]) )
    return 4294967274LL;
  else
    return 0;
}
