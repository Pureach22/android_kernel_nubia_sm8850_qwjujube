__int64 __fastcall qpace_remove(__int64 a1)
{
  _free_pages(
    ((unsigned __int64)(((__int64)(*(_QWORD *)tr_rings << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
    0);
  _free_pages(
    ((unsigned __int64)(((__int64)(*(_QWORD *)(tr_rings + 32) << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
    0);
  kfree(tr_rings);
  _free_pages(
    ((unsigned __int64)(((__int64)(*(_QWORD *)(ev_rings + 32) << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
    0);
  _free_pages(
    ((unsigned __int64)(((__int64)(*(_QWORD *)(ev_rings + 96) << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
    0);
  kfree(ev_rings);
  return qpace_power_off(a1 + 16);
}
