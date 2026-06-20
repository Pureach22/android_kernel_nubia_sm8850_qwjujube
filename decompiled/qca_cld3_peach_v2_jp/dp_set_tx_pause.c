__int64 __fastcall dp_set_tx_pause(__int64 result, char a2)
{
  *(_BYTE *)(result + 20092) = a2;
  return result;
}
