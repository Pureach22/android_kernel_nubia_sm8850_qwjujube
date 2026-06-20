__int64 __fastcall dp_deliver_tx_mgmt(__int64 a1, char a2)
{
  if ( a2 )
    return 16;
  else
    return 16 * (unsigned int)(*(_QWORD *)(a1 + 72) == 0);
}
