void __fastcall dp_mon_filter_set_cbf_cmn(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a2 + 4) = *(_QWORD *)(a2 + 4) & 0xFFFF0000FFDE2020LL | 0x40000000405FLL;
}
