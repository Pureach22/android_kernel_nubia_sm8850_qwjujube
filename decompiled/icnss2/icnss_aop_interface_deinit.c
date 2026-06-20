unsigned __int64 __fastcall icnss_aop_interface_deinit(__int64 a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 5744);
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
    mbox_free_channel();
  result = *(_QWORD *)(a1 + 5752);
  if ( result )
  {
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      result = qmp_put();
      *(_BYTE *)(a1 + 5760) = 0;
    }
  }
  return result;
}
