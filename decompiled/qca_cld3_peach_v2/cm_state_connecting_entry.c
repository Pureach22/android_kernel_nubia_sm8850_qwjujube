__int64 __fastcall cm_state_connecting_entry(__int64 result)
{
  if ( result )
    *(_QWORD *)(result + 80) = 0x600000001LL;
  return result;
}
