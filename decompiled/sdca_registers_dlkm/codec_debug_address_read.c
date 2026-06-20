__int64 __fastcall codec_debug_address_read(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v6; // x8
  _QWORD v10[2]; // [xsp+0h] [xbp-20h] BYREF
  int v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  result = -22;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( a1 )
    {
      if ( a3 )
      {
        if ( a4 )
        {
          v6 = *(_QWORD *)(a1 + 32);
          if ( v6 )
          {
            v11 = 0;
            v10[0] = 0;
            v10[1] = 0;
            if ( *(_QWORD *)v6 )
            {
              if ( (*a4 & 0x8000000000000000LL) == 0 )
              {
                snprintf((char *)v10, 0x14u, "0x%x\n", *(_DWORD *)(v6 + 16));
                result = simple_read_from_buffer(a2, a3, a4, v10, 20);
              }
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
