__int64 __fastcall htc_set_pkt_dbg(__int64 result, char a2)
{
  *(_BYTE *)(result + 3563) = a2;
  return result;
}
