__int64 __fastcall aw882xx_dev_irq_reinit(__int64 a1)
{
  int v1; // w0

  v1 = aw_dev_reg_fw_update(a1);
  return v1 & (unsigned int)(v1 >> 31);
}
