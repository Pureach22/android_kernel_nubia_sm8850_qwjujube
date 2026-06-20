__int64 sub_A1A0()
{
  __int64 v0; // x10

  if ( (v0 & 0x1000000000000000LL) == 0 )
    JUMPOUT(0x11F28);
  return hdcp1_start_smcinvoke();
}
