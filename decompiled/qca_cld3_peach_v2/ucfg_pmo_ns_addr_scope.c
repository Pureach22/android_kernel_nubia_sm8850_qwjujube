__int64 __fastcall ucfg_pmo_ns_addr_scope(__int64 result)
{
  if ( (int)result > 4 )
  {
    switch ( (_DWORD)result )
    {
      case 5:
        return 3;
      case 8:
        return 4;
      case 0xE:
        return 5;
    }
    return 0;
  }
  if ( (_DWORD)result != 1 && (_DWORD)result != 2 )
    return 0;
  return result;
}
