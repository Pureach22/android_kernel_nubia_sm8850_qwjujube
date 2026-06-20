__int64 __fastcall pmic_glink_debug_callback(__int64 a1, _DWORD *a2, __int64 a3)
{
  unsigned int v3; // w8
  __int64 v4; // x2
  __int64 v6; // x0
  __int64 v7; // x2

  v3 = a2[2];
  if ( v3 == 56 )
  {
    if ( a3 != 16 )
    {
      dev_err(*(_QWORD *)(a1 + 8), "Invalid write response, glink packet size=%zu\n", a3);
      return 0;
    }
    v7 = (unsigned int)a2[3];
    if ( (_DWORD)v7 )
    {
      dev_err(*(_QWORD *)(a1 + 8), "glink write failed, ret=%d\n", v7);
      return 0;
    }
    v6 = a1 + 64;
  }
  else
  {
    if ( v3 != 55 )
    {
      dev_err(*(_QWORD *)(a1 + 8), "Unknown opcode %u\n", v3);
      return 0;
    }
    if ( a3 != 284 )
    {
      dev_err(*(_QWORD *)(a1 + 8), "Invalid read response, glink packet size=%zu\n", a3);
      return 0;
    }
    v4 = (unsigned int)a2[6];
    if ( (v4 & 0x80000000) != 0 )
    {
      dev_err(*(_QWORD *)(a1 + 8), "glink read failed, ret=%d\n", v4);
      return 0;
    }
    memcpy((void *)(a1 + 96), a2, 0x11Cu);
    v6 = a1 + 64;
  }
  complete(v6);
  return 0;
}
