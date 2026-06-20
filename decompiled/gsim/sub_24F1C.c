__int64 sub_24F1C()
{
  __asm { PRFM            #9, 0x32C5C }
  return _gsi_msi_write_msg();
}
