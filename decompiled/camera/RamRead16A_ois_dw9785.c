__int64 __fastcall RamRead16A_ois_dw9785(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v4; // w20

  result = camera_io_dev_read(*a1 + 3656LL, a2, a3, 2, 2, 0);
  if ( (result & 0x80000000) != 0 )
  {
    v4 = result;
    printk(&unk_3E416B);
    return v4;
  }
  return result;
}
