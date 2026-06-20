__int64 __fastcall hif_get_max_wmi_ep(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x12
  unsigned __int64 v3; // x8
  int *v4; // x11
  int v5; // t1
  unsigned int v6; // w12
  unsigned int v7; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v7 = 0;
  hif_select_service_to_pipe_map(a1, v8, &v7);
  result = 0;
  if ( v7 >= 0xC )
  {
    result = 0;
    v2 = v8[0] + 4LL;
    v3 = v7 / 0xCuLL;
    v4 = (int *)(v8[0] + 4LL);
    do
    {
      v5 = *v4;
      v4 += 3;
      if ( v5 == 2 )
      {
        v6 = *(_DWORD *)(v2 - 4) - 256;
        if ( v6 <= 6 && ((1 << v6) & 0x61) != 0 )
          result = (unsigned int)(result + 1);
      }
      --v3;
      v2 = (__int64)v4;
    }
    while ( v3 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
