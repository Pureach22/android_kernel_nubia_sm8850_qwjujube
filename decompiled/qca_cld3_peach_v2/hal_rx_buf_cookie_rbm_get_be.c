__int64 __fastcall hal_rx_buf_cookie_rbm_get_be(__int64 result, __int64 a2)
{
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(result + 4) >> 12;
  *(_BYTE *)(a2 + 12) = *(_BYTE *)(result + 5) & 0xF;
  return result;
}
