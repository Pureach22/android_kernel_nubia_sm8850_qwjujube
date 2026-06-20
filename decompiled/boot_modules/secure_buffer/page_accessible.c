bool __fastcall page_accessible(__int64 a1)
{
  return *(_QWORD *)((a1 << 6) - ((__int64)memstart_addr >> 12 << 6) - 0x13FFFFFD8LL) != 4008636142LL;
}
