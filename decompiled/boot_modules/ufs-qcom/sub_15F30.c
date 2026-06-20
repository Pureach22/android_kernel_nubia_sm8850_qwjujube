__int64 sub_15F30()
{
  __asm { PRFM            #9, 0x23C70 }
  return ufs_qcom_write_msi_msg();
}
