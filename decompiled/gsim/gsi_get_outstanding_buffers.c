__int64 __fastcall gsi_get_outstanding_buffers(int a1)
{
  return gsihal_read_reg_nk(138, (unsigned int)(20 * a1 + 19), 0);
}
