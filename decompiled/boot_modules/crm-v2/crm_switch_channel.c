__int64 __fastcall crm_switch_channel(__int64 a1, int a2)
{
  writel_relaxed(
    1LL << a2,
    *(_QWORD *)(a1 + 24)
  + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 40) + 4LL)
                 + *(_DWORD *)(*(_QWORD *)(a1 + 40) + 12LL) * *(_DWORD *)(a1 + 32)));
  if ( (*(_BYTE *)(a1 + 181) & 1) != 0 )
    return 0;
  else
    return crm_channel_switch_complete(a1, a2);
}
