__int64 __fastcall hal_rx_mon_hw_desc_get_mpdu_status_be(__int64 result, __int64 a2)
{
  __int64 v2; // x10
  unsigned __int64 v3; // x10
  unsigned __int64 v4; // x10

  v2 = *(_QWORD *)(a2 + 20);
  *(_BYTE *)(a2 + 52) = *(_DWORD *)(result + 48);
  v3 = v2 & 0xFFFFFFFFFFEFFFFFLL | (((*(_QWORD *)(result + 36) >> 46) & 1LL) << 20);
  *(_QWORD *)(a2 + 20) = v3;
  v4 = v3 & 0xFFFFFFFFFF9FFFFFLL | ((unsigned __int64)(dword_A2FA18[(*(_QWORD *)(result + 44) >> 44) & 3LL] & 3) << 21);
  *(_QWORD *)(a2 + 20) = v4;
  *(_QWORD *)(a2 + 20) = v4 & 0xFFFFFFFFFDFFFFFFLL
                       | ((unsigned __int64)((*(_QWORD *)(result + 44) & 0xE0000000000000LL) == 0x20000000000000LL) << 25);
  return result;
}
