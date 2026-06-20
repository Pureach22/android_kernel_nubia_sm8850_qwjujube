__int64 __fastcall populate_dot11f_ssid2(__int64 a1, _BYTE *a2)
{
  qdf_mem_copy(a2 + 2, (const void *)(a1 + 37), *(unsigned __int8 *)(a1 + 36));
  a2[1] = *(_BYTE *)(a1 + 36);
  *a2 = 1;
  return 0;
}
