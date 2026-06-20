void __fastcall dp_mon_filter_set_status_cbf(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x8

  v2 = *(_QWORD *)(a2 + 4) & 0xFFFF0000FFDE2020LL;
  *(_QWORD *)(a2 + 12) &= 0xFFFF0000FFFF0000LL;
  *(_QWORD *)(a2 + 4) = v2 | 0x400000005F81LL;
}
