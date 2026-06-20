__int64 __fastcall i2c_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19

  if ( !display_buf )
    return 0;
  v4 = simple_read_from_buffer(a2, a3, a4, display_buf, 3000);
  memset((void *)display_buf, 0, 0xBB8u);
  return v4;
}
