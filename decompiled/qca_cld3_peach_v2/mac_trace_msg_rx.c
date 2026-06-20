__int64 __fastcall mac_trace_msg_rx(__int64 a1, unsigned __int8 a2, int a3)
{
  __int16 v4; // w2
  unsigned int v5; // w1

  if ( BYTE1(a3) == 16 )
  {
    v4 = a2;
    v5 = 9;
  }
  else if ( BYTE1(a3) == 19 )
  {
    v4 = a2;
    if ( (unsigned __int16)((unsigned __int16)a3 >> 4) < 0x13Bu )
      v5 = 7;
    else
      v5 = 11;
  }
  else
  {
    v4 = a2;
    v5 = a3;
  }
  return qdf_trace(53, v5, v4, a3);
}
