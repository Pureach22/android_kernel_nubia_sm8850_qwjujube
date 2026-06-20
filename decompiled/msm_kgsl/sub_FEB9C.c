__int64 __fastcall sub_FEB9C(__int64 a1, __int64 a2)
{
  if ( (_DWORD)a1 )
    JUMPOUT(0xA81FC);
  return kgsl_bus_update(a1, a2);
}
