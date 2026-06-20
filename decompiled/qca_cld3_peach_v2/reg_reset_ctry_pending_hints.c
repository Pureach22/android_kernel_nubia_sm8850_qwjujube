__int64 __fastcall reg_reset_ctry_pending_hints(__int64 result)
{
  if ( *(_BYTE *)(result + 91095) == 1 )
  {
    *(_DWORD *)(result + 91136) = 0;
    *(_QWORD *)(result + 91128) = 0;
  }
  return result;
}
