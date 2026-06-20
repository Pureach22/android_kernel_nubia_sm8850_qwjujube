__int64 __fastcall htc_set_nodrop_pkt(__int64 result, char a2)
{
  *(_BYTE *)(result + 3560) = a2;
  return result;
}
