bool __fastcall simple_amp_volatile_register(__int64 a1, int a2)
{
  return (unsigned int)(a2 - 1079510051) <= 0x11 && ((1 << (a2 - 35)) & 0x20081) != 0
      || (unsigned int)get_access_mode(*(_QWORD *)(a1 + 152)) == 0;
}
