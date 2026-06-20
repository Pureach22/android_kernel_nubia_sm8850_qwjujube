__int64 __fastcall wda_svc_exit(__int64 result)
{
  if ( result == 48 )
    return printk(&unk_2CF4B, "wda_svc_exit");
  return result;
}
