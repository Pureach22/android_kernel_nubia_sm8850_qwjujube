__int64 __fastcall nb7vpq904m_shutdown(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 184);
  result = regmap_write(*(_QWORD *)(v1 + 96), 0, 251);
  if ( (result & 0x80000000) != 0 )
  {
    dev_err(*(_QWORD *)(v1 + 88), "writing reg 0x%02x failure\n", 0);
    return dev_err(a1 + 32, "%s: fail to set USB mode with 4 channel enabled.\n", "nb7vpq904m_shutdown");
  }
  return result;
}
