__int64 __fastcall extract_chan_stats_tlv(__int64 a1, _QWORD *a2, unsigned int a3, _DWORD *a4)
{
  _DWORD *v4; // x8

  if ( *(_DWORD *)(*a2 + 24LL) > a3 )
  {
    v4 = (_DWORD *)(a2[2]
                  + 240LL * *(unsigned int *)(*a2 + 8LL)
                  + 164LL * *(unsigned int *)(*a2 + 12LL)
                  + 20LL * *(unsigned int *)(*a2 + 16LL)
                  + 20LL * a3);
    *a4 = *v4;
    a4[1] = v4[1];
    a4[2] = v4[2];
    a4[3] = v4[3];
    a4[4] = v4[4];
  }
  return 0;
}
