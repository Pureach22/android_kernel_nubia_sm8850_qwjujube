__int64 __fastcall glink_adc_callback(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  __int64 v4; // x9
  __int64 v5; // x11
  __int64 v6; // x10

  v3 = *(_DWORD *)(a2 + 8);
  if ( v3 == 73 )
  {
    if ( a3 == 36 )
    {
      *(_QWORD *)(a1 + 108) = *(_QWORD *)a2;
      v5 = *(_QWORD *)(a2 + 16);
      v4 = *(_QWORD *)(a2 + 24);
      v6 = *(_QWORD *)(a2 + 8);
      *(_DWORD *)(a1 + 140) = *(_DWORD *)(a2 + 32);
      *(_QWORD *)(a1 + 132) = v4;
      *(_QWORD *)(a1 + 124) = v5;
      *(_QWORD *)(a1 + 116) = v6;
      complete(a1 + 64);
    }
    else
    {
      dev_err(*(_QWORD *)(a1 + 8), "Invalid read response, glink packet size=%zu\n", a3);
    }
  }
  else
  {
    dev_err(*(_QWORD *)(a1 + 8), "Unknown opcode %u\n", v3);
  }
  return 0;
}
