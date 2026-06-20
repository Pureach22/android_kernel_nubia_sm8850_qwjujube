__int64 sub_8038()
{
  __int64 v0; // x10

  if ( (v0 & 0x1000000000000000LL) == 0 )
    JUMPOUT(0xFDC0);
  return hdcp1_start_qseecom();
}
