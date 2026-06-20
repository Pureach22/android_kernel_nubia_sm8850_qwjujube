__int64 __fastcall wmi_mtrace(unsigned int a1, unsigned __int8 a2, int a3)
{
  return qdf_mtrace(49, 100, a1 & 0x7F | ((unsigned __int8)(a1 >> 12) << 7), a2, a3);
}
