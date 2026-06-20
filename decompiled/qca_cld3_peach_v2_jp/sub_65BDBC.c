__int64 __fastcall sub_65BDBC(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return wma_twt_process_nudge_dialog(a1, a2, a3, a4 & 0xFFFFF80001FFFFFFLL | ((a4 & 0x3FFFF) << 25));
}
