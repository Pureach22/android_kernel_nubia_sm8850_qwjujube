bool __fastcall of_property_read_bool(__int64 a1, __int64 a2)
{
  return of_find_property(a1, a2, 0) != 0;
}
