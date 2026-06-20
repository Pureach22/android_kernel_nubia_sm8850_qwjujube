__int64 __fastcall dp_rx_desc_cookie_2_va_be(__int64 a1, unsigned int a2)
{
  return *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 22552) + 24LL * ((a2 >> 9) & 0x7FF)) + 8LL * (a2 & 0x1FF));
}
