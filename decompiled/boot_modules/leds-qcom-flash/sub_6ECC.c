__int64 sub_6ECC()
{
  __asm { PRFM            #0x1D, 0xCE700 }
  return qcom_flash_fault_get();
}
