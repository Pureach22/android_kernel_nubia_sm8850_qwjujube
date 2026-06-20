__int64 __fastcall sub_541F20(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w9

  if ( (v4 & 0x1000000) != 0 )
    JUMPOUT(0x53F200);
  return dp_rx_wbm_err_process(a1, a2, a3, a4);
}
