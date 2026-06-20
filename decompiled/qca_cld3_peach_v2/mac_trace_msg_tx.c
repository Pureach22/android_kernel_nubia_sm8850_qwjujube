__int64 __fastcall mac_trace_msg_tx(__int64 a1, unsigned __int8 a2, int a3)
{
  unsigned int v3; // w8
  __int16 v5; // w2
  unsigned int v6; // w1

  v3 = BYTE1(a3);
  if ( BYTE1(a3) == 16 )
  {
    v5 = a2;
    v6 = 8;
  }
  else if ( BYTE1(a3) == 19 )
  {
    v5 = a2;
    if ( (unsigned __int16)((unsigned __int16)a3 >> 4) < 0x13Bu )
      v6 = 6;
    else
      v6 = 10;
  }
  else
  {
    v5 = a2;
    v6 = v3;
  }
  return qdf_trace(53, v6, v5, a3);
}
