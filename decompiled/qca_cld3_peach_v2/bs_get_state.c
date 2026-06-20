__int64 __fastcall bs_get_state(__int64 a1)
{
  if ( a1 && *(_QWORD *)a1 )
    return *(unsigned int *)(a1 + 88);
  else
    return 4;
}
