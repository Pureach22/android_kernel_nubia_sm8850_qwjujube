__int64 __fastcall cm_state_init_entry(__int64 result)
{
  if ( result )
    *(_QWORD *)(result + 80) = 0x600000000LL;
  return result;
}
