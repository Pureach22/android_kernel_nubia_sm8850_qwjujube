__int64 __fastcall nb7vpq904m_reg_set(__int64 a1, unsigned __int8 a2, unsigned __int8 a3)
{
  unsigned int v5; // w0
  int v7; // w2
  unsigned int v8; // w19

  v5 = regmap_write(*(_QWORD *)(a1 + 96), a2, a3);
  if ( (v5 & 0x80000000) == 0 )
    return 0;
  v7 = a2;
  v8 = v5;
  dev_err(*(_QWORD *)(a1 + 88), "writing reg 0x%02x failure\n", v7);
  return v8;
}
