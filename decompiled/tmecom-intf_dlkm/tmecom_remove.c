__int64 __fastcall tmecom_remove(__int64 a1)
{
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 168) + 64LL) )
    mbox_free_channel();
  return dev_info(a1 + 16, "tmecom remove success\n");
}
