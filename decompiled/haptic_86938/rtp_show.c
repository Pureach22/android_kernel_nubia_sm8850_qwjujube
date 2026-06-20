__int64 __fastcall rtp_show(__int64 a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "rtp_cnt = %d\n", *(_DWORD *)(*(_QWORD *)(a1 + 152) - 52LL));
}
