__int64 __fastcall usb_cser_rw_show(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( *(_QWORD *)(a1 + 128) )
    seq_printf();
  else
    printk(&unk_8F9B, "usb_cser_rw_show", a3, a4);
  return 0;
}
