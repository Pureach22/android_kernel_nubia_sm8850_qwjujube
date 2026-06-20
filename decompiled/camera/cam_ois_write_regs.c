__int64 __fastcall cam_ois_write_regs(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned __int8 v8; // w24
  unsigned int *v9; // x23
  unsigned int v10; // w0
  unsigned int v11; // w8
  unsigned int v12; // w23

  if ( a1 && a2 && a3 )
  {
    if ( a4 )
    {
      v8 = 0;
      while ( 1 )
      {
        v9 = (unsigned int *)(a3 + 16LL * v8);
        v10 = zte_cam_cci_i2c_write(a1 + 3656, *v9, v9[1], *(unsigned int *)(a2 + 8), *(unsigned int *)(a2 + 12));
        v11 = v9[2];
        v12 = v10;
        msleep(v11);
        if ( (v12 & 0x80000000) != 0 )
          break;
        if ( a4 <= ++v8 )
          return v12;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_write_regs",
        178,
        "dw978x i2c write failed, rc=%d",
        v12);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_write_regs",
      165,
      "Invalid Args");
    return (unsigned int)-22;
  }
  return v12;
}
