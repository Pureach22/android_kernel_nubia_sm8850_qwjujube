__int64 __fastcall cm_state_disconnecting_entry(__int64 result)
{
  if ( result )
    *(_QWORD *)(result + 80) = 0x600000003LL;
  return result;
}
