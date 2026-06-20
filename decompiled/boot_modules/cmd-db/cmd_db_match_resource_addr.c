bool __fastcall cmd_db_match_resource_addr(unsigned int a1, unsigned int a2)
{
  if ( a1 == a2 )
    return 1;
  return (a1 & 0xF0000LL) == 0x40000 && (((unsigned __int64)a1 >> 4) & 0x4FFF) == (unsigned __int16)(a2 >> 4);
}
