__int64 __fastcall sub_2CFB44(__int64 a1, __int64 _X1)
{
  __asm { STZ2G           X1, [X15,#-0x1E0]! }
  return cds_register_scan_flush_recovery_callback();
}
