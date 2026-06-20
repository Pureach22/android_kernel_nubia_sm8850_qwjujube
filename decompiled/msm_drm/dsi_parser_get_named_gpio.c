__int64 __fastcall dsi_parser_get_named_gpio(__int64 a1, char *a2)
{
  unsigned int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = -22;
  dsi_parser_read_u32(a1, a2, &v3);
  _ReadStatusReg(SP_EL0);
  return v3;
}
