__int64 qdf_get_bus_reg_dump()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  v0 = (__int64 (*)(void))get_bus_reg_dump;
  if ( get_bus_reg_dump )
  {
    if ( *((_DWORD *)get_bus_reg_dump - 1) != 546480799 )
      __break(0x8228u);
    return v0();
  }
  return result;
}
