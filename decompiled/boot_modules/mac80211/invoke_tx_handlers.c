__int64 __fastcall invoke_tx_handlers(__int64 a1)
{
  if ( (unsigned int)invoke_tx_handlers_early(a1) )
    return 0xFFFFFFFFLL;
  else
    return invoke_tx_handlers_late(a1);
}
