__int64 __fastcall nb7vpq904m_host_work(__int64 a1)
{
  unsigned int v1; // w20
  __int64 result; // x0

  v1 = *(unsigned __int8 *)(a1 - 52);
  if ( (regmap_write(*(_QWORD *)(a1 - 120), 0, (unsigned __int8)v1 & 0xFE) & 0x80000000) != 0 )
    dev_err(*(_QWORD *)(a1 - 128), "writing reg 0x%02x failure\n", 0);
  usleep_range_state(2000, 2500, 2);
  result = regmap_write(*(_QWORD *)(a1 - 120), 0, v1);
  if ( (result & 0x80000000) != 0 )
    return dev_err(*(_QWORD *)(a1 - 128), "writing reg 0x%02x failure\n", 0);
  return result;
}
