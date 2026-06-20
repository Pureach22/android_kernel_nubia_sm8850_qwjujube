__int64 __fastcall ieee80211_get_regs(__int64 result, __int64 a2)
{
  *(_QWORD *)(a2 + 4) = *(unsigned int *)(**(_QWORD **)(result + 992) + 244LL);
  return result;
}
